/*
 * audio_in.c
 *
 *  Created on: Dec 9, 2024
 *      Author: elecinnov2
 */

#include "../../AudioIN/inc/audio_in.h"
#include "audioBF.h"
#include "comlink_control.h"

#define CHANNEL_DEMUX_MASK                    	0x55

static Audio_IN_Setting_TypeDef 	AudioIN;
static TIM_HandleTypeDef          	TimDividerHandle;
static TIM_SlaveConfigTypeDef     	sSlaveConfig;
static TIM_IC_InitTypeDef         	sICConfig;
static TIM_OC_InitTypeDef        	sOCConfig;

I2S_HandleTypeDef                 hAudioInI2s;
SPI_HandleTypeDef                 hAudioInSPI;

uint8_t Channel_Demux[128] = {
  0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x02, 0x03,
  0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x02, 0x03,
  0x04, 0x05, 0x04, 0x05, 0x06, 0x07, 0x06, 0x07,
  0x04, 0x05, 0x04, 0x05, 0x06, 0x07, 0x06, 0x07,
  0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x02, 0x03,
  0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x02, 0x03,
  0x04, 0x05, 0x04, 0x05, 0x06, 0x07, 0x06, 0x07,
  0x04, 0x05, 0x04, 0x05, 0x06, 0x07, 0x06, 0x07,
  0x08, 0x09, 0x08, 0x09, 0x0a, 0x0b, 0x0a, 0x0b,
  0x08, 0x09, 0x08, 0x09, 0x0a, 0x0b, 0x0a, 0x0b,
  0x0c, 0x0d, 0x0c, 0x0d, 0x0e, 0x0f, 0x0e, 0x0f,
  0x0c, 0x0d, 0x0c, 0x0d, 0x0e, 0x0f, 0x0e, 0x0f,
  0x08, 0x09, 0x08, 0x09, 0x0a, 0x0b, 0x0a, 0x0b,
  0x08, 0x09, 0x08, 0x09, 0x0a, 0x0b, 0x0a, 0x0b,
  0x0c, 0x0d, 0x0c, 0x0d, 0x0e, 0x0f, 0x0e, 0x0f,
  0x0c, 0x0d, 0x0c, 0x0d, 0x0e, 0x0f, 0x0e, 0x0f
};


static uint16_t I2S_InternalBuffer[640];//[PDM_INTERNAL_BUFFER_SIZE_I2S];

void Audio_IN_Init(uint32_t AudioFreq, uint32_t BitRes, uint32_t ChnlNbr)
{
	AudioIN.MicChannels = ChnlNbr;

	switch (AudioFreq)
	{

		case 16000:
			AudioIN.PDM_Clock_Freq = 1024;//PDM_FREQ_16K; /*KHz*/
			AudioIN.PCM_Sampling_Freq = 16000;
			break;

		case 48000:
			AudioIN.PDM_Clock_Freq = 3072; /*KHz*/
			AudioIN.PCM_Sampling_Freq = 48000;
			break;
		//default:

			//return 0;
	}

	AudioIN.DecimationFactor = (AudioIN.PDM_Clock_Freq * 1000) /AudioIN.PCM_Sampling_Freq;
	AudioIN.PdmBufferSize = (AudioIN.PDM_Clock_Freq / 8) * 2 * BF_N_MS_PER_INTERRUPT;

	uint16_t PDM_I2S_Clock = AudioIN.PDM_Clock_Freq;

	PDM_I2S_Clock *= 2;  /*Clock to be generated is twice the PDM clock */
	/*Timer Init*/
	Audio_IN_Timer_Init();

	Audio_IN_ClockConfig(NULL, AudioIN.PCM_Sampling_Freq, &(PDM_I2S_Clock));

	/* I2S Peripheral configuration */
	hAudioInI2s.Instance = SPI2;
	__HAL_I2S_DISABLE(&hAudioInI2s);

	if(AudioIN.MicChannels == 1)
	{
		hAudioInI2s.Init.DataFormat   = I2S_DATAFORMAT_16B;
	}
	else
	{
		hAudioInI2s.Init.DataFormat   = I2S_DATAFORMAT_32B;
	}

	hAudioInI2s.Init.AudioFreq = ((AudioIN.PDM_Clock_Freq * 1000) / 32);
	hAudioInI2s.Init.ClockSource  = I2S_CLOCK_PLL;
	hAudioInI2s.Init.CPOL         = I2S_CPOL_HIGH;
	hAudioInI2s.Init.MCLKOutput   = I2S_MCLKOUTPUT_DISABLE;
	hAudioInI2s.Init.Mode         = I2S_MODE_MASTER_RX;
	hAudioInI2s.Init.Standard     = I2S_STANDARD_MSB;
	hAudioInI2s.Init.FullDuplexMode   = I2S_FULLDUPLEXMODE_DISABLE;

	if(HAL_I2S_GetState(&hAudioInI2s) == HAL_I2S_STATE_RESET)
	{
		Audio_IN_I2S_MspInit();
	}

	if(HAL_I2S_Init(&hAudioInI2s) != HAL_OK)
	{
	//return 0;
	}

}

uint8_t Audio_IN_Timer_Init(void)
{

  GPIO_InitTypeDef   GPIO_InitStruct;

  /* Enable AUDIO_TIMER clock*/
  AUDIO_IN_TIMER_CLK_ENABLE();
  AUDIO_IN_TIMER_CHOUT_GPIO_PORT_CLK_ENABLE();
  AUDIO_IN_TIMER_CHIN_GPIO_PORT_CLK_ENABLE();

  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Alternate = AUDIO_IN_TIMER_CHIN_AF;
  GPIO_InitStruct.Pin = AUDIO_IN_TIMER_CHIN_PIN;
  HAL_GPIO_Init(AUDIO_IN_TIMER_CHIN_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Alternate = AUDIO_IN_TIMER_CHOUT_AF;
  GPIO_InitStruct.Pin = AUDIO_IN_TIMER_CHOUT_PIN;
  HAL_GPIO_Init(AUDIO_IN_TIMER_CHOUT_GPIO_PORT, &GPIO_InitStruct);

  TimDividerHandle.Instance = AUDIO_IN_TIMER;

  /* Configure the Input: channel_1 */
  sICConfig.ICPolarity  = TIM_ICPOLARITY_RISING;
  sICConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sICConfig.ICPrescaler = TIM_ICPSC_DIV1;
  sICConfig.ICFilter = 0;
  if(HAL_TIM_IC_ConfigChannel(&TimDividerHandle, &sICConfig, TIM_CHANNEL_1) != HAL_OK)
  {
    return 0;
  }

  /* Configure TIM1 in Gated Slave mode for the external trigger (Filtered Timer
  Input 1) */
  sSlaveConfig.InputTrigger = TIM_TS_TI1FP1;//TIM_TS_TI1F_ED;;
  sSlaveConfig.SlaveMode    = TIM_SLAVEMODE_EXTERNAL1;
  if( HAL_TIM_SlaveConfigSynchronization(&TimDividerHandle, &sSlaveConfig) != HAL_OK)
  {
    return 0;
  }

  /* Initialize TIM3 peripheral in PWM mode*/
  TimDividerHandle.Init.Period            = 1;
  TimDividerHandle.Init.Prescaler         = 0;
  TimDividerHandle.Init.ClockDivision     = 0;
  TimDividerHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimDividerHandle.Init.RepetitionCounter = 0;
  if(HAL_TIM_PWM_Init(&TimDividerHandle) != HAL_OK)
  {
    return 0;
  }

  /* Configure the PWM_channel_1  */
  sOCConfig.OCMode     = TIM_OCMODE_PWM1;
  sOCConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
  sOCConfig.Pulse = 1;
  if(HAL_TIM_PWM_ConfigChannel(&TimDividerHandle, &sOCConfig, TIM_CHANNEL_2) != HAL_OK)
  {
    return 0;
  }
  return 1;
}

uint8_t Audio_IN_ClockConfig(I2S_HandleTypeDef *hi2s, uint32_t AudioFreq, void *Params)
{
	/*I2S PLL Configuration*/
	RCC_PeriphCLKInitTypeDef rccclkinit;
	HAL_RCCEx_GetPeriphCLKConfig(&rccclkinit);

	rccclkinit.PLLI2S.PLLI2SQ = 2;
	rccclkinit.PLLI2SDivQ = 1;

	if ((*(uint16_t *)Params) % 1280 == 0)
	{
		rccclkinit.PLLI2S.PLLI2SM = 20;
		rccclkinit.PLLI2S.PLLI2SN = 96;
		rccclkinit.PLLI2S.PLLI2SR = 5;
	}
	else
	{
		rccclkinit.PLLI2S.PLLI2SM = 32;
		rccclkinit.PLLI2S.PLLI2SN = 258;
		rccclkinit.PLLI2S.PLLI2SR = 3;
	}
	rccclkinit.PeriphClockSelection = RCC_PERIPHCLK_I2S_APB2;

	if(HAL_RCCEx_PeriphCLKConfig(&rccclkinit) != HAL_OK)
	{
		return 0;
	}
	return 1;


}

void Audio_IN_I2S_MspInit(void)
{
  static DMA_HandleTypeDef hdma_i2sRx;
  GPIO_InitTypeDef  GPIO_InitStruct;
  I2S_HandleTypeDef *hi2s = &hAudioInI2s;

  /* Enable the I2S2 peripheral clock */
  AUDIO_IN_I2S_CLK_ENABLE();

  /* Enable I2S GPIO clocks */
  AUDIO_IN_I2S_SCK_GPIO_CLK_ENABLE();
  AUDIO_IN_I2S_MOSI_GPIO_CLK_ENABLE();

  /* I2S2 pins configuration: SCK and MOSI pins ------------------------------*/
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;


  GPIO_InitStruct.Pin       = AUDIO_IN_I2S_SCK_PIN;
  GPIO_InitStruct.Alternate = AUDIO_IN_I2S_SCK_AF;
  HAL_GPIO_Init(AUDIO_IN_I2S_SCK_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = AUDIO_IN_I2S_MOSI_PIN ;
  GPIO_InitStruct.Alternate = AUDIO_IN_I2S_MOSI_AF;
  HAL_GPIO_Init(AUDIO_IN_I2S_MOSI_GPIO_PORT, &GPIO_InitStruct);

  /* Enable the DMA clock */
  AUDIO_IN_I2S_DMAx_CLK_ENABLE();

  if(hi2s->Instance == AUDIO_IN_I2S_INSTANCE)
  {
    /* Configure the hdma_i2sRx handle parameters */
    hdma_i2sRx.Init.Channel             = AUDIO_IN_I2S_DMAx_CHANNEL;
    hdma_i2sRx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_i2sRx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_i2sRx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_i2sRx.Init.PeriphDataAlignment = AUDIO_IN_I2S_DMAx_PERIPH_DATA_SIZE;
    hdma_i2sRx.Init.MemDataAlignment    = AUDIO_IN_I2S_DMAx_MEM_DATA_SIZE;
    hdma_i2sRx.Init.Mode                = DMA_CIRCULAR;
    hdma_i2sRx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_i2sRx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_i2sRx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_i2sRx.Init.MemBurst            = DMA_MBURST_SINGLE;
    hdma_i2sRx.Init.PeriphBurst         = DMA_MBURST_SINGLE;

    hdma_i2sRx.Instance = AUDIO_IN_I2S_DMAx_STREAM;

    /* Associate the DMA handle */
    __HAL_LINKDMA(hi2s, hdmarx, hdma_i2sRx);

    /* Deinitialize the Stream for new transfer */
    HAL_DMA_DeInit(&hdma_i2sRx);

    /* Configure the DMA Stream */
    HAL_DMA_Init(&hdma_i2sRx);
  }

  /* I2S DMA IRQ Channel configuration */
  HAL_NVIC_SetPriority(AUDIO_IN_I2S_DMAx_IRQ, AUDIO_IN_IRQ_PREPRIO, AUDIO_IN_IRQ_PREPRIO);
  HAL_NVIC_EnableIRQ(AUDIO_IN_I2S_DMAx_IRQ);
}

uint8_t Audio_IN_Record(uint16_t * pbuf, uint32_t size)
{
	AudioIN.PDM_Data = pbuf;

	Audio_IN_Timer_Start();

	if(HAL_I2S_Receive_DMA(&hAudioInI2s, I2S_InternalBuffer, AudioIN.PdmBufferSize/2) != HAL_OK)
	{
		return 0;
	}

	return 1;
}

uint8_t Audio_IN_Pause(void)
{
	if(HAL_I2S_DMAPause(&hAudioInI2s) != HAL_OK)
	{
		return 0;
	}

	return 1;
}

uint8_t Audio_IN_Resume(void)
{
	if(HAL_I2S_DMAResume(&hAudioInI2s) != HAL_OK)
	{
		return 0;
	}

	return 1;
}


uint8_t Audio_IN_Timer_Start(void)
{

  if(HAL_TIM_IC_Start(&TimDividerHandle, TIM_CHANNEL_1) != HAL_OK)
  {
    return 0;
  }
  /* Start the Output Compare */
  if(HAL_TIM_OC_Start(&TimDividerHandle, TIM_CHANNEL_2) != HAL_OK)
  {
    return 0;
  }

  return 1;
}

void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s)
{

  uint32_t index = 0;

  switch(AudioIN.MicChannels)
  {
  case 1:
    {
      uint16_t * DataTempI2S = &I2S_InternalBuffer[AudioIN.PdmBufferSize/4] ;
      for(index = 0; index < AudioIN.PdmBufferSize/4; index++)
      {
        AudioIN.PDM_Data[index] = HTONS(DataTempI2S[index]);
      }
      break;
    }

  case 2:
    {
      uint16_t * DataTempI2S = &(I2S_InternalBuffer[AudioIN.PdmBufferSize/2]);
      uint8_t a,b=0;
      for(index=0; index<AudioIN.PdmBufferSize/2; index++)
      {
        a = ((uint8_t *)(DataTempI2S))[(index*2)];
        b = ((uint8_t *)(DataTempI2S))[(index*2)+1];
        ((uint8_t *)(AudioIN.PDM_Data))[(index*2)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] | Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4;;
        ((uint8_t *)(AudioIN.PDM_Data))[(index*2)+1] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] |Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4;
      }
      break;
    }

  default:
    {

      break;
    }

  }

  Audio_IN_TransferComplete_CallBack();
}

/**
* @brief Rx Transfer completed callbacks. It performs demuxing of the bit-interleaved PDM streams into
byte-interleaved data suitable for PDM to PCM conversion. 1 ms of data for each microphone is
written into the buffer that the user indicates when calling the BSP_AUDIO_IN_Start(...) function.
* @param hi2s: I2S handle
* @retval None
*/

void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
  uint32_t index = 0;
  switch(AudioIN.MicChannels)
  {
	  case 1:
	  {
		  uint16_t * DataTempI2S = I2S_InternalBuffer;
		  for(index = 0; index < AudioIN.PdmBufferSize/4; index++)
		  {
			AudioIN.PDM_Data[index] = HTONS(DataTempI2S[index]);
		  }
		  break;
	  }
	  case 2:
	  {
		  uint16_t * DataTempI2S = I2S_InternalBuffer;
		  uint8_t a,b=0;
		  for(index=0; index<AudioIN.PdmBufferSize/2; index++)
		  {
			  a = ((uint8_t *)(DataTempI2S))[(index*2)];
			  b = ((uint8_t *)(DataTempI2S))[(index*2)+1];
			  ((uint8_t *)(AudioIN.PDM_Data))[(index*2)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] |
					  Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4;;
			  ((uint8_t *)(AudioIN.PDM_Data))[(index*2)+1] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] |
					  Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4;
		  }
		  break;
	  }

  default:
    {
      break;
    }

  }

  Audio_IN_HalfTransfer_CallBack();
}

/**
* @brief  User callback when record buffer is filled.
* @param  None
* @retval None
*/
__weak void BSP_AUDIO_IN_TransferComplete_CallBack(void)
{
  /* This function should be implemented by the user application.
  It is called into this driver when the current buffer is filled
  to prepare the next buffer pointer and its size. */
}

/**
* @brief  User callback when record buffer is half filled.
* @param  None
* @retval None
*/
__weak void BSP_AUDIO_IN_HalfTransfer_CallBack(void)
{
  /* This function should be implemented by the user application.
  It is called into this driver when the current buffer is filled
  to prepare the next buffer pointer and its size. */
}

/**
* @brief  Audio IN Error callback function
* @param  None
* @retval None
*/
__weak void BSP_AUDIO_IN_Error_Callback(void)
{
  /* This function is called when an Interrupt due to transfer error on or peripheral
  error occurs. */
}

/**
* @brief I2S error callbacks
* @param hi2s: I2S handle
* @retval None
*/
void HAL_I2S_ErrorCallback(I2S_HandleTypeDef *hi2s)
{
  /* Manage the error generated on DMA FIFO: This function
  should be coded by user (its prototype is already declared in stm32f4_discovery_audio.h) */
  if(hi2s->Instance == AUDIO_IN_I2S_INSTANCE)
  {
    BSP_AUDIO_IN_Error_Callback();
  }
}

