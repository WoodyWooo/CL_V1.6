/*
 * opus_init.h
 *
 *  Created on: Jan 16, 2025
 *      Author: elecinnov2
 */

#ifndef INC_OPUS_INIT_H_
#define INC_OPUS_INIT_H_

#include <stdint.h>
#include "opus.h"
#include "string.h"
#include "opus_private.h"


/**
 * @brief Opus encoder configuration parameters.
 */
typedef struct
{
  float ms_frame;                                       /*!< audio frame size [ms] (2.5, 5, 10, 20, 40, 60).*/

  uint32_t sample_freq;                                 /*!< Audio sampling frequency [Hz] (8000, 12000, 16000, 24000, 48000).*/

  uint8_t channels;                                     /*!< Number of audio input channels. */

  uint16_t application;                                 /*!< Specifies the application type (OPUS_APPLICATION_VOIP, OPUS_APPLICATION_AUDIO, OPUS_APPLICATION_RESTRICTED_LOWDELAY) see opus_define.h. */

  uint32_t bitrate;                                     /*!< Specifies the choosen encoding bitrate [bps] (from 6000 to 510000). */

  uint8_t complexity;                                   /*!< Specifies the choosen encoding complexity (from 0 to 10). */

  uint8_t *pInternalMemory;                             /*!< Pointer to the internal memory used for the BlueVoiceOPUS encoding. */

} BV_OPUS_ENC_ConfigTypeDef;

/**
  * @}
  */

/** @defgroup BV_OPUS_DecoderParameters BV_OPUS_DecoderParameters
  * @{
  */

/**
 * @brief Opus decoder configuration parameters.
 */
typedef struct
{
  float ms_frame;                                       /*!< audio frame size [ms] (2.5, 5, 10, 20, 40, 60). */

  uint32_t sample_freq;                                 /*!< Audio sampling frequency [Hz] (8000, 12000, 16000, 24000, 48000). */

  uint8_t channels;                                     /*!< Number of audio input channels */

  uint32_t bitrate;                                     /*!< Specifies the choosen encoding bitrate [bps] (from 6000 to 510000). */

  uint8_t *pInternalMemory;                             /*!< Pointer to the internal memory used for the BlueVoice decoding. */

} BV_OPUS_DEC_ConfigTypeDef;

/**
  * @}
  */

typedef enum
{
  BV_OPUS_SUCCESS = 0x00,                        /*!< Success.*/
  BV_OPUS_ERROR = 0x01,                          /*!< Error.*/
  BV_OPUS_INVALID_PARAM = 0x12,                  /*!< Invalid Opus parameters.*/
  BV_OPUS_DISCONNECTED = 0x13,                   /*!< BLE Disconnected Error.*/
  BV_OPUS_TX_HANDLE_NOT_AVAILABLE = 0x20,        /*!< TX BlueVoiceOPUS characteristics handle not set.*/
  BV_OPUS_NOTIF_DISABLE = 0x21,                  /*!< The notifications are disabled.*/
  BV_OPUS_ENC_NOT_CONFIG = 0x30,                 /*!< BlueVoiceOPUS encoder not configured.*/
  BV_OPUS_DEC_NOT_CONFIG = 0x31,                 /*!< BlueVoiceOPUS decoder not configured.*/
  BV_OPUS_PKT_NOT_COMPLETE = 0x40,               /*!< Received Opus packet not completed.*/
  BV_OPUS_TIMEOUT = 0x50,                        /*!< A BLE timeout occurred.*/
  BV_OPUS_START_STREAMING = 0x60,                /*!< Audio Streaming ready to start.*/
  BV_OPUS_STOP_STREAMING = 0x61                  /*!< Auiod Streaming must be stopped.*/
} BV_OPUS_Status;

uint8_t Opus_Profile_Init(void);
uint32_t BluevoiceOPUS_ENC_getMemorySize(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus);
uint32_t BluevoiceOPUS_DEC_getMemorySize(BV_OPUS_DEC_ConfigTypeDef *DEC_configOpus);
uint8_t BluevoiceOPUS_ENC_Init(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int *opus_err);
uint8_t BluevoiceOPUS_DEC_Init(BV_OPUS_DEC_ConfigTypeDef *DEC_configOpus, int *opus_err);
void BluevoiceOPUS_ENC_Deinit(void);
void BluevoiceOPUS_DEC_Deinit(void);
uint8_t BluevoiceOPUS_ENC_IsConfigured(void);
uint8_t BluevoiceOPUS_DEC_IsConfigured(void);
uint8_t BluevoiceOPUS_ENC_Set_Bitrate(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int bitrate, int *opus_err);
uint8_t BluevoiceOPUS_ENC_Set_CBR(void);
uint8_t BluevoiceOPUS_ENC_Set_VBR(void);
uint8_t BluevoiceOPUS_ENC_Set_Complexity(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int complexity, int *opus_err);
int BluevoiceOPUS_ENC_Encode(uint8_t * buf_in, uint8_t * buf_out);
int BluevoiceOPUS_DEC_Decode(uint8_t * buf_in, uint32_t len, uint8_t * buf_out);



#endif /* INC_OPUS_INIT_H_ */
