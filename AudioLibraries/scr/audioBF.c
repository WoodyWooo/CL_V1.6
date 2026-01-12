/*
 * audioBF.c
 *
 *  Created on: Oct 18, 2024
 *      Author: michaelsmart
 */

#include "audioBF.h"
#include "stdlib.h"
#include "stm32f446xx.h"
#include "string.h"
#include "crc.h"
#include "acoustic_bf.h"
#include "stm32f4xx_hal_cortex.h"


/*Handler and Config structure for BeamForming*/
AcousticBF_Handler_t libBeamforming_Handler_Instance;
AcousticBF_Config_t lib_Beamforming_Config_Instance;

void BF_Init(void)
{
  volatile uint32_t error_value = 0;
  /* Enable CRC peripheral to unlock the library */
  __CRC_CLK_ENABLE();
  /*Setup Beamforming static parameters*/
  error_value = 0;
  libBeamforming_Handler_Instance.algorithm_type_init= ACOUSTIC_BF_TYPE_ASR_READY;//ACOUSTIC_BF_TYPE_CARDIOID_BASIC;//ACOUSTIC_BF_TYPE_ASR_READY;//
  libBeamforming_Handler_Instance.ref_mic_enable= ACOUSTIC_BF_REF_DISABLE;
  libBeamforming_Handler_Instance.ptr_out_channels= 1;
  libBeamforming_Handler_Instance.data_format= ACOUSTIC_BF_DATA_FORMAT_PDM;
  libBeamforming_Handler_Instance.sampling_frequency= PDM_FREQ_16K;
  libBeamforming_Handler_Instance.ptr_M1_channels= 2;
  libBeamforming_Handler_Instance.ptr_M2_channels= 2;
  libBeamforming_Handler_Instance.delay_enable = 1;
  (void)AcousticBF_getMemorySize(&libBeamforming_Handler_Instance);
  libBeamforming_Handler_Instance.pInternalMemory =(uint32_t *)malloc(libBeamforming_Handler_Instance.internal_memory_size);
  error_value = AcousticBF_Init(&libBeamforming_Handler_Instance);

  /*Error Management*/
  if(error_value != 0U)
  {
   Error_Handler();
  }

  /*Malloc Failure*/
  if(libBeamforming_Handler_Instance.pInternalMemory == NULL)
  {
    Error_Handler();
  }

  /*Setup Beamforming dynamic parameters*/
  lib_Beamforming_Config_Instance.algorithm_type = ACOUSTIC_BF_TYPE_ASR_READY;//ACOUSTIC_BF_TYPE_CARDIOID_BASIC;//ACOUSTIC_BF_TYPE_STRONG;//
  lib_Beamforming_Config_Instance.M2_gain= 0.0f;
  lib_Beamforming_Config_Instance.mic_distance=40;
  lib_Beamforming_Config_Instance.volume = 5;
  error_value = AcousticBF_setConfig(&libBeamforming_Handler_Instance, &lib_Beamforming_Config_Instance);

  /*Error Management*/
  if(error_value != 0U)
  {
    Error_Handler();
  }
}


uint16_t PCM_tempBuf[320];
static uint32_t PDMindex = 0;
uint8_t AUDIO_IN_PDM_To_BFPCM(uint16_t *PDMBuf, uint16_t *PCMBuf)
{

	uint32_t index_ms = 0;
	uint16_t PDM_Offset =  PDM_IN_BUFFSIZE;//(X_NUCLEO_CCA02M1_Handler.PdmBufferSize / (2 * N_MS_PER_INTERRUPT)) * X_NUCLEO_CCA02M1_Handler.MicChannels;
	uint16_t PCM_Offset = PCM_IN_SAMPLES_PER_MS;//(X_NUCLEO_CCA02M1_Handler.MicChannels * (X_NUCLEO_CCA02M1_Handler.PCM_Sampling_Freq / 1000));


	for (index_ms = 0; index_ms < BF_N_MS_PER_INTERRUPT; index_ms++)
	{

		if(AcousticBF_FirstStep(&((uint8_t *)(PDMBuf))[index_ms * PDM_Offset],&((uint8_t *)(PDMBuf))[(index_ms * PDM_Offset)+1], (int16_t *)&(PCM_tempBuf[PDMindex + index_ms * PCM_Offset]), &libBeamforming_Handler_Instance) == 1U)
		{

			SW_Task1_Start();

		}

	}


	PDMindex+=PCM_IN_SAMPLES_PER_MS;       /////change depending on PDM Buffer size   //////////////index + index_ms * PCM_Offset
	if (PDMindex == PCM_BUFFER_IN_LEN)
	{
		memcpy(PCMBuf, PCM_tempBuf, (PCM_BUFFER_IN_LEN*2));
		PDMindex = 0;
		return 1;
	}
	else

		return 0;

}

void SW_IRQ_BF_Tasks_Init(void)
{
  HAL_NVIC_SetPriority((IRQn_Type)EXTI2_IRQn, 0x0D, 0);
  HAL_NVIC_EnableIRQ((IRQn_Type)EXTI2_IRQn);

  HAL_NVIC_SetPriority((IRQn_Type)EXTI3_IRQn, 0x0E, 0);
  HAL_NVIC_EnableIRQ((IRQn_Type)EXTI3_IRQn);
}


void SW_Task1_Callback(void)
{
  (void)AcousticBF_SecondStep(&libBeamforming_Handler_Instance);
}

/**
* @brief Throws Highest priority interrupt
* @param  None
* @retval None
*/
void SW_Task1_Start(void)
{
  HAL_NVIC_SetPendingIRQ(EXTI2_IRQn);
}

void EXTI2_IRQHandler(void)
{
	SW_Task1_Callback();
}
/**
* @brief Throws Lower priority interrupt
* @param  None
* @retval None
*/
void SW_Task2_Start(void)
{
  HAL_NVIC_SetPendingIRQ(EXTI3_IRQn);
}


