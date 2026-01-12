/*
 * SDR.c
 *
 *  Created on: Oct 18, 2024
 *      Author: michaelsmart
 */

#include <stdlib.h>
#include "SDR.h"


//Sound Detection Module VAriables
static uint16_t PCMToSdrTmpBuffer[320];

typedef enum {
  BUFFER_OFFSET_NONE = 0,
  BUFFER_OFFSET_HALF,
  BUFFER_OFFSET_FULL,
}BUFFER_StateTypeDef;

/* Audio buffer control struct */
typedef struct {

  BUFFER_StateTypeDef state;
  uint32_t fptr;
}AUDIO_OUT_BufferTypeDef;

//SDR MOD VARIABLES
static AUDIO_OUT_BufferTypeDef  audioOutBuff;
;

/* store SDR output decisions*/
static int16_t SDREn = 1;
static int16_t SDRThr1dB = 9;
static int16_t SDRThr2dB = 7;
int SDRenabled=0;
/* store SDR output decisions*/
static  uint8_t str_dec[30];

void *pSdrPersistentMem = NULL;
void *pSdrScratchMem = NULL;
static  sdr_static_param_t sdr_static_param;
static  sdr_dynamic_param_t sdr_dynamic_param;

static  buffer_t BufferHandler;
static  buffer_t *pBufferHandler = &BufferHandler;

SDR_StateTypeDef SDR_Init(uint16_t buffLen)
{
	//SDR MOD
  /* Allocat mem for SDR */
  pSdrPersistentMem = malloc(sdr_persistent_mem_size); /* sdr_persistent_mem_size  0x070 */
  pSdrScratchMem = malloc(sdr_scratch_mem_size);       /* sdr_scratch_mem_size  0x04 */
  int32_t error = SDR_ERROR_NONE;
  /* Effect Initialization and configuration */
 /*-----------------------------------------*/
 /* Enables and resets CRC-32 from STM32 HW */
  __HAL_RCC_CRC_CLK_ENABLE();
  CRC->CR = CRC_CR_RESET;

  /* SDR effect reset */
  error = sdr_reset(pSdrPersistentMem, pSdrScratchMem);
  if (error != SDR_ERROR_NONE)
  {
	 return (SDR_ERROR);
	}

  /* SDR effect static parameters setting */
  sdr_static_param.sampling_rate = 16000;   /* only sampling rate supported */
  sdr_static_param.buffer_size = buffLen;//16000/100; /* Input buffer size in samples */
  sdr_static_param.learning_frame_nb = 4;   /* Number of frames to initialize noise estimator */

  error = sdr_setParam(&sdr_static_param, pSdrPersistentMem);
  if (error != SDR_ERROR_NONE)
  {
	  return (SDR_ERROR);
	}

  /* SDR dynamic parameters that can be updated here every frame if required */
  sdr_dynamic_param.enable = 1;                   /* Enables the effect */
  sdr_dynamic_param.ratio_thr1_dB = 10;//30;            /* Threshold (in dB) above which SDR state goes from INACTIVE to ACTIVE */
  sdr_dynamic_param.ratio_thr2_dB = 8;//28;            /* Threshold (in dB) above which SDR state goes from ACTIVE to INACTIVE */
  sdr_dynamic_param.noise_pwr_min_dB = -60;       /* Minimum noise power (in dBFS) for noise estimate */
  sdr_dynamic_param.hangover_nb_frame = 10;        /* Number of frames of hangover for state going from ACTIVE to INACTIVE */

  error = sdr_setConfig(&sdr_dynamic_param, pSdrPersistentMem);
  if (error != SDR_ERROR_NONE)
  {
	  return (SDR_ERROR);
  }

  /* I/O buffers settings */
  BufferHandler.nb_bytes_per_Sample = 2; /* 8 bits in 0ne byte */
  BufferHandler.nb_channels = 1;     /*Only one channel processed*/
  BufferHandler.buffer_size = buffLen;//16000/100; /* just half buffer is process (size per channel) */
  BufferHandler.mode = NOT_INTERLEAVED;

}

int32_t thr1=0;
int32_t noisePower=0;
SDR_StateTypeDef SDR_Process(uint16_t *buffer, uint16_t buffLen)
{
	int32_t error = SDR_ERROR_NONE;
	int32_t i = 0;
    noisePower = sdr_dynamic_param.output_noise_pwr;
	 for (i=0;i<(buffLen);i+=1)
	   {
	     PCMToSdrTmpBuffer[i]= buffer[i];

	    }

	  BufferHandler.data_ptr = &PCMToSdrTmpBuffer[0];

	  error = sdr_process(pBufferHandler, pBufferHandler, pSdrPersistentMem);

	  if (error != SDR_ERROR_NONE)
	   {
	     return (SDR_ERROR);
	    }

	     // output signal decision sent to terminal IO
	  error = sdr_getConfig(&sdr_dynamic_param, pSdrPersistentMem);
	  if (error != SDR_ERROR_NONE)
	   {
	      return SDR_ERROR;
	     }

	  if (SDREn > 0)
	  { SDRenabled=1;

		   if (sdr_dynamic_param.output_state == SDR_STATE_ACTIVE)
		   {
			   //audioDetected=1;
			   return SDR_DETECTED_AUDIO;

		   }
		   else
		   {
			   //audioDetected=0;
			   return SDR_NO_AUDIO_DETECTED;

		   }
		   /*if(HAL_GPIO_ReadPin(ESP_to_F446_IRQ_PORT, ESP_to_F446_IRQ_PIN) == GPIO_PIN_SET)
		   {
			   firstIRQ = 1;
		   }*/

	   }

	return  SDR_ERROR_NONE;
}
