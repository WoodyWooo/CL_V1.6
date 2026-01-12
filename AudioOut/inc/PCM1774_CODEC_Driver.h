/*
 * PCM1774_CODEC_Driver.h
 *
 *  Created on: Jul 21, 2024
 *      Author: C-Tech
 */

#ifndef INC_PCM1774_CODEC_DRIVER_H_
#define INC_PCM1774_CODEC_DRIVER_H_



/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f4xx_hal.h"
//#include "audio.h"
#include "PCM1774_CODEC_Driver.h"


#define DMA_MAX(_X_)                (((_X_) <= DMA_MAX_SZE)? (_X_):DMA_MAX_SZE)

typedef struct
{

  /* Identity */
  uint8_t who_am_i;

  /* Configuration */
  uint8_t ifType;        /* 0 means I2C, 1 means SPI, etc. */
  uint8_t address;       /* Sensor I2C address (NOTE: Not a unique sensor ID). */
  uint8_t spiDevice;     /* Sensor Chip Select for SPI Bus */
  uint8_t instance;      /* Sensor instance (NOTE: Sensor ID unique only within its class). */
  uint8_t isInitialized; /* Sensor setup done. */
  uint8_t isEnabled;     /* Sensor ON. */
  uint8_t isCombo;       /* Combo sensor (component consists of more sensors). */

  /* Pointer to the Data */
  void *pData;

  /* Pointer to the Virtual Table */
  void *pVTable;
  /* Pointer to the Extended Virtual Table */
  void *pExtVTable;
} DrvContextTypeDef;

/**
 * @brief  Component's Status enumerator definition.
 */
typedef enum
{
  COMPONENT_OK = 0,
  COMPONENT_ERROR,
  COMPONENT_TIMEOUT,
  COMPONENT_NOT_IMPLEMENTED
} DrvStatusTypeDef;

typedef struct
{
  uint32_t  (*Init)(DrvContextTypeDef*, uint8_t, uint32_t);
  void      (*DeInit)(DrvContextTypeDef*);
  uint32_t  (*ReadID)(DrvContextTypeDef*);
  uint32_t  (*Play)(DrvContextTypeDef*, uint16_t*, uint16_t);
  uint32_t  (*Pause)(DrvContextTypeDef*);
  uint32_t  (*Resume)(DrvContextTypeDef*);
  uint32_t  (*Stop)(DrvContextTypeDef*, uint32_t);
  uint32_t  (*SetFrequency)(DrvContextTypeDef*, uint32_t);
  uint32_t  (*SetVolume)(DrvContextTypeDef*, uint8_t);
  uint32_t  (*SetMute)(DrvContextTypeDef*, uint32_t);
  uint32_t  (*SetOutputMode)(DrvContextTypeDef*, uint8_t);
  uint32_t  (*Reset)(DrvContextTypeDef*);
}AUDIO_DrvTypeDef;

/** @addtogroup COMPONENTS
* @{
*/

/** @addtogroup PCM1774
* @{
*/

/** @defgroup PCM1774_Exported_Types PCM1774 Exported Types
* @{
*/

typedef enum
{
  PCM1774_OK = (uint8_t)0,
  PCM1774_ERROR = 1 ,
  PCM1774_NOT_IMPLEMENTED = 2
}
PCM1774_Error_et;

typedef enum {
  PCM1774_CODEC_MUTE_ENABLE 		        = 0x40,
  PCM1774_CODEC_MUTE_DISABLE 		        = 0
}
PCM1774_CODEC_MUTE_t;

/**
* @}
*/


/** @defgroup PCM1774_Exported_Constants PCM1774 Exported Constants
* @{
*/
/************** I2C Address *****************/

#define PCM1774_CODEC_I2C_ADDRESS_LOW   0x8C
#define PCM1774_CODEC_I2C_ADDRESS_HIGH  0x8E

/* Private Function Prototype -------------------------------------------------------*/

/************** Device Register  *******************/

#define PCM1774_CODEC_VOL_HPA_L                 0x40
#define PCM1774_CODEC_VOL_HPA_R                	0x41
#define PCM1774_CODEC_DAC_DIG_ATT_SM_L          0x44
#define PCM1774_CODEC_DAC_DIG_ATT_SM_R          0x45
#define PCM1774_CODEC_DAC_OS_DE_AI_DGC          0x46
#define PCM1774_CODEC_ANALOG_MIXER_PU_PD        0x48
#define PCM1774_CODEC_DAC_HPA_PU_PD             0x49
#define PCM1774_CODEC_ANALOG_OUT_CONFIG_SEL     0x4A
#define PCM1774_CODEC_HPA_INS_DETECTION_SP      0x4B
#define PCM1774_CODEC_SD_STATUS_READ_BACK       0x4D
#define PCM1774_CODEC_PG_1_2_5_6_PU_PD 	        0x52
#define PCM1774_CODEC_MASTER_MODE     	        0x54
#define PCM1774_CODEC_SYSRESET_FSC_DATASWAP     0x55
#define PCM1774_CODEC_BCK_CONF_FSC_ZC 	        0x56
#define PCM1774_CODEC_ANALOG_IN_SELECT          0x57
#define PCM1774_CODEC_ANALOG_MIX_SWITCH         0x58
#define PCM1774_CODEC_A_TO_A_PATH            	0x59
#define PCM1774_CODEC_MIC_BOOST          	    0x5A
#define PCM1774_CODEC_BASS_BOOST_GAIN           0x5C
#define PCM1774_CODEC_MIDDLE_BOOST_GAIN         0x5D
#define PCM1774_CODEC_TREBLE_BOOST_GAIN         0x5E
#define PCM1774_CODEC_SOUND_EFFECT_SOURCE_3D    0x5F
#define PCM1774_CODEC_DIGITAL_MONO_MIX          0x60
#define PCM1774_CODEC_PG1_PG2_ADD_GAIN          0x7C
#define PCM1774_CODEC_PU_PD_TIME_CONTROL        0x7D
#define PCM1774_CODEC_MUTE_MASK  				0x40

/**
* @}
*/

/** @defgroup PCM1774_Exported_Function_Prototypes PCM1774 Exported Function Prototypes
* @{
*/
uint32_t pcm1774_Init(DrvContextTypeDef *handle, uint8_t Volume, uint32_t AudioFreq);
void pcm1774_DeInit(DrvContextTypeDef *handle);
uint32_t pcm1774_ReadID(DrvContextTypeDef *handle);
uint32_t pcm1774_Play(DrvContextTypeDef *handle, uint16_t* pBuffer, uint16_t Size);
uint32_t pcm1774_Pause(DrvContextTypeDef *handle);
uint32_t pcm1774_Resume(DrvContextTypeDef *handle);
uint32_t pcm1774_Stop(DrvContextTypeDef *handle, uint32_t Cmd);
uint32_t pcm1774_SetVolume(DrvContextTypeDef *handle, uint8_t Volume);
uint32_t pcm1774_SetMute(DrvContextTypeDef *handle, uint32_t Cmd);
uint32_t pcm1774_PowerDown(DrvContextTypeDef *handle);
uint32_t pcm1774_SetOutputMode(DrvContextTypeDef *handle, uint8_t Output);
uint32_t pcm1774_SetFrequency(DrvContextTypeDef *handle, uint32_t AudioFreq);
uint32_t pcm1774_Reset(DrvContextTypeDef *handle);
/**
* @}
*/

/**
* @}
*/

/**
* @}
*/


#endif /* INC_PCM1774_CODEC_DRIVER_H_ */
