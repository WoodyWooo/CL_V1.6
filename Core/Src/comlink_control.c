/*
 * comlink_control.c
 *
 *  Created on: Dec 11, 2024
 *      Author: elecinnov2
 */

#include "comlink_control.h"
#include <stddef.h>
#include "audio_in.h"
#include "pdm2pcm_glo.h"
#include "audioBF.h"
#include "PCM1774_CODEC_driver.h"
#include "Audio_out_control.h"
#include "SDR.h"
#include "opus_init.h"
#include "opus_func.h"
#include "gpio.h"
#include "string.h"
#include "stm32f4xx_hal_spi.h"
#include "ESP_link.h"
#include "gp_timer.h"
#include "rtc.h"
#include "battery_mgmt.h"


#define PAYLOAD_SIZE 	80
#define OFF_DELAY    	5
#define CONTROL_REG  	76
#define BATT_VOLT_REG	77


SPI_State state = Idle;
ESP_BT_State ESPbluetooth = Disconnected;

extern BV_OPUS_ENC_ConfigTypeDef EncConfigOpus;
extern BV_OPUS_DEC_ConfigTypeDef DecConfigOpus;
extern SPI_HandleTypeDef SpiHandle;

void *PCM1774_X_0_handle = NULL;

uint16_t PDM_Buffer[AUDIO_CHANNELS_IN * PCM_IN_SAMPLES_PER_MS * 64 / 8];
uint16_t PCM_Buffer[AUDIO_CHANNELS_IN * PCM_AUDIO_IN_SAMPLES];             		/*!< PCM data is stored here.*/
static uint16_t PCM_Buffer_OUT[PCM_BUFFER_OUT_LEN];                             /*!< PCM data to be streamed via Audio OUT are stored here.*/
static uint16_t PCM_Buffer_Temp[PCM_BUFFER_IN_LEN];
uint8_t audio_data_ready = 0;
uint8_t AudioOutActive = 0;
uint8_t audioDetected = 0;
uint32_t elapsedMillis = 0;
uint8_t newDataAvailable = 0;
uint8_t ESP_Ready = 0;
uint8_t OpusEncBuf[PAYLOAD_SIZE];
uint8_t espSleep =100;
uint8_t readBattVolt = 1;
uint8_t batV = 0;

void Start_Audio_In(void)
{
	Audio_IN_Init(AUDIO_SAMPLING_FREQUENCY, 16, BF_CHANNELS_IN);
	Audio_IN_Record(PDM_Buffer, 0);
}

void ESP_Process(void)
{
	uint32_t currentMillis = HAL_GetTick();

	if (newDataAvailable)
	{
		if (HAL_GPIO_ReadPin(ESP_F446_IRQ_GPIO_Port, ESP_F446_IRQ_Pin))
			elapsedMillis = currentMillis;
		else
			newDataAvailable = 0;
	}

	if (((currentMillis - elapsedMillis) >= OFF_DELAY) && AudioOutActive)
	{
		AudioOutActive = 0;
		//BSP_AUDIO_OUT_Stop(PCM1774_X_0_handle, 0);
	    BSP_AUDIO_OUT_SetVolume(PCM1774_X_0_handle, 0);
	}

	if(audio_data_ready)
	{
		SW_OpusTask_Start();
		audio_data_ready = 0;
		if (!newDataAvailable && !audioDetected)
			{
			    Power_Save(120);
			}
	}

	if (readBattVolt)
	{
		batV = Get_Battery_Volt();
	}
}

/**
 * @brief  Initializes Opus SW interrupt
 * @param  None
 * @retval None
 */
void SW_IRQ_OpusTasks_Init(void)
{
    HAL_NVIC_SetPriority((IRQn_Type)EXTI1_IRQn, 7, 0);
    HAL_NVIC_EnableIRQ((IRQn_Type)EXTI1_IRQn);
}

/**
 * @brief  Throws Opus SW interrupt
 * @param  None
 * @retval None
 */
void SW_OpusTask_Start(void)
{
    HAL_NVIC_SetPendingIRQ(EXTI1_IRQn);
}

void SW_OpusTask_Callback(void)
{
    int opus_err;
    //SPI_State state = Idle;
    //uint8_t EspHasData = 0;

    if (newDataAvailable && !audioDetected && !readBattVolt)
    {
    	state = Rx;

    }
    if (newDataAvailable && audioDetected && !readBattVolt)
    {
    	state = TxRx;

    }
    if (!newDataAvailable && audioDetected && !readBattVolt)
    {
    	state = Tx;
    }
    if (!newDataAvailable && audioDetected && readBattVolt)
    {
    	state = TxBtData;
    }
    if (newDataAvailable && !audioDetected && readBattVolt)
    {
    	state = RxBtData;
    }
    if (!newDataAvailable && !audioDetected && readBattVolt)
    {
    	state = BtData;
    }

    if (!newDataAvailable && !audioDetected && !readBattVolt)
    {
    	state = Idle;

    	return;
    }

    SpiDataTransfer((uint8_t*) PCM_Buffer, &EncConfigOpus, &opus_err, state, batV);

}

void Audio_IN_HalfTransfer_CallBack(void)
{
   Audio_Process();
}


void Audio_IN_TransferComplete_CallBack(void)
{
   Audio_Process();
}

void Audio_Process(void)
{
	uint8_t bufFull = 0;

	bufFull = AUDIO_IN_PDM_To_BFPCM((uint16_t *) PDM_Buffer, (uint16_t *) PCM_Buffer);
	if (bufFull ==1)
	{
		/////Put PCM_Buffer through Sound Detection Module/////
		if (SDR_Process(PCM_Buffer, PCM_BUFFER_IN_LEN) == SDR_DETECTED_AUDIO)
		{
			audioDetected=1;
			//Play_Audio(PCM_BUFFER_IN_LEN, &PCM_Buffer);
		}
		else
		{
			audioDetected=0;
			//BSP_AUDIO_OUT_Stop(PCM1774_X_0_handle, 0);

		}

		audio_data_ready=1;

	}

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == ESP_F446_IRQ_Pin)
	{
		newDataAvailable = 1;

		//Clear_SPI_EXTI_Flag();
	}

	if(GPIO_Pin == PB_1_INPUT_Pin)
	{
		On_Off_Sequence_Detect();
	}

}

uint16_t TX=0;
uint8_t SpiDataTransfer(uint8_t *data_in, BV_OPUS_ENC_ConfigTypeDef *enc_config, int *opus_err, uint8_t SPIstate, uint8_t volt)
{
	if(!BluevoiceOPUS_ENC_IsConfigured())
	{
		//BV_APP_CEN_Error_Handler();
		return BV_OPUS_ENC_NOT_CONFIG;
	}

	int32_t OpusEncBufLen = 0;
	uint8_t *pEncBuf;

	SPI_State state = SPIstate;

	memset(OpusEncBuf, 0, PAYLOAD_SIZE);

	if ((state == Tx) || (state == TxRx) || (state == TxRxBtData))
	{
		TX++;
		*opus_err = 0;

		OpusEncBufLen = BluevoiceOPUS_ENC_Encode((uint8_t *) data_in, enc_config->pInternalMemory);  ///from PCM sample to encoded OPUS here

		if(OpusEncBufLen<=0)
		{
			*opus_err = OpusEncBufLen;
			return BV_OPUS_ERROR;
		}

		memcpy(&OpusEncBuf[1], enc_config->pInternalMemory, OpusEncBufLen); ////write data buffer length into first element of array, followed by the actual data

		OpusEncBuf[0] = OpusEncBufLen;
		OpusEncBuf[BATT_VOLT_REG] = volt;

		while (OpusEncBufLen >= PAYLOAD_SIZE)
		{
			//dataTooLong++;
			Error_Handler();
		}
	}
	if ((state == BtData) || (state == RxBtData))
	{
		OpusEncBuf[BATT_VOLT_REG] = volt;
	}

	pEncBuf = OpusEncBuf;

	struct timer t;

	Timer_Set(&t, CLOCK_SECOND/10);

	while(1)
	{
		if(ESP_SPI_Ready())
		{
			Write_to_ESP(pEncBuf, PAYLOAD_SIZE, state);
			break;
		}

		if(Timer_Expired(&t))
		{
			break;
		}

	}
	//++;
	return BV_OPUS_SUCCESS;
}
uint16_t RX=0;
uint8_t	outData[PAYLOAD_SIZE];
uint8_t	Datatx[PAYLOAD_SIZE];
void Write_to_ESP(uint8_t *data, uint8_t len, uint8_t SPIstate)
{
	uint8_t	tempData[PAYLOAD_SIZE] = {0};
	//HAL_NVIC_DisableIRQ( EXTI0_IRQn);
	memcpy(Datatx, data, len);
	SPI_State state = SPIstate;

	HAL_GPIO_WritePin(ESP_SPI_CS_PORT, ESP_SPI_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t *)data, (uint8_t *)&tempData, PAYLOAD_SIZE, 100);
	HAL_GPIO_WritePin(ESP_SPI_CS_PORT, ESP_SPI_CS_PIN, GPIO_PIN_SET);

	if ((state == Rx) || (state == TxRx))
	{
		RX++;
		memset(outData, 0, PAYLOAD_SIZE);
		memcpy(outData, &tempData[1], tempData[0]);

		uint8_t l = tempData[0];
		if (l > 0)
			Play_Audio(l, outData);

		ESPbluetooth = tempData[CONTROL_REG];
		if (ESPbluetooth == Connected)
		{
			readBattVolt = 1;
		}
	}

	//Enable_SPI_IRQ();
	//HAL_NVIC_EnableIRQ( EXTI0_IRQn);

}
int p =0;
void Start_Audio_Out(void)
{
	BSP_AUDIO_OUT_Init(&PCM1774_X_0_handle, NULL, 30, AUDIO_SAMPLING_FREQUENCY);

}

void Stop_Audio_Out(void)
{
	BSP_AUDIO_OUT_Stop(PCM1774_X_0_handle, 0);
}

void Play_Audio(uint8_t data_len, uint8_t *dataBuf)   //////<-------uint16_t *dataBuf change back to uint8_t
{
		uint8_t status = 0;
		int opur_error;
		static uint32_t IndexOut = 0;
		static uint32_t IndexIn = 0;

		uint16_t PCMSamples = 0;

		status = BluevoiceOPUS_ParseData(dataBuf, data_len, (uint8_t *) PCM_Buffer_Temp, &PCMSamples, &DecConfigOpus, &opur_error);
		//Biquad_Filter_Process();
		p++;
		if (PCMSamples > 0)
		{
			for(IndexIn=0;IndexIn<PCMSamples;IndexIn++)
			{
				PCM_Buffer_OUT[IndexOut++] = PCM_Buffer_Temp[IndexIn];
				PCM_Buffer_OUT[IndexOut++] = PCM_Buffer_Temp[IndexIn];

			}

			if (!AudioOutActive && IndexOut==PCM_BUFFER_OUT_LEN/2)
			{
				//BSP_AUDIO_OUT_Init(&PCM1774_X_0_handle, NULL, 30, AUDIO_SAMPLING_FREQUENCY);
				HAL_NVIC_DisableIRQ(DMA2_Stream5_IRQn);// interrupt not needed
				BSP_AUDIO_OUT_SetVolume(PCM1774_X_0_handle, 50);
				///// start audio streaming
				BSP_AUDIO_OUT_Play(PCM1774_X_0_handle,(uint16_t*)PCM_Buffer_OUT, PCM_BUFFER_OUT_LEN);
				AudioOutActive=1;
			}

			if(IndexOut==PCM_BUFFER_OUT_LEN)
			{
				IndexOut = 0;
			}

		if(status != BV_OPUS_SUCCESS)
		{
			Error_Handler();
		}

	}
}

/* To configure the HAL_RTCEx_SetWakeUpTimer_IT wakeup:
 * RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 =16
 * Wake up time base = 16/(32kHz) = 0.0005 seconds   32kHz is the LSI
 * so for 100ms wake up time:
 * 0.100/0.0005 = 200   or for 1ms = 2 * Wake up time base
 */

void Power_Save(uint16_t sleepMillis)
{
	uint8_t	data[PAYLOAD_SIZE]= {0};
	data[78] = espSleep;
	uint8_t	tempData[PAYLOAD_SIZE];
	uint16_t wakeupCounter =  sleepMillis*2;

	if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, wakeupCounter, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
	  {
	    Error_Handler();
	  }
	Audio_IN_Pause();

	HAL_GPIO_WritePin(ESP_SPI_CS_PORT, ESP_SPI_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t *)data, (uint8_t *)&tempData, PAYLOAD_SIZE, 100);
	HAL_GPIO_WritePin(ESP_SPI_CS_PORT, ESP_SPI_CS_PIN, GPIO_PIN_SET);

	HAL_GPIO_WritePin(ESP_SLEEP_CTRL_GPIO_Port, ESP_SLEEP_CTRL_Pin, GPIO_PIN_SET);
	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	HAL_ResumeTick();
	//SystemClock_Config();
	//PeriphCommonClock_Config();
	HAL_GPIO_WritePin(ESP_SLEEP_CTRL_GPIO_Port, ESP_SLEEP_CTRL_Pin, GPIO_PIN_RESET);
	Audio_IN_Resume();
	HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);


}
