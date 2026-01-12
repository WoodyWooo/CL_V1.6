/*
 * opus_init.c
 *
 *  Created on: Jan 16, 2025
 *      Author: elecinnov2
 */

#include "opus.h"
#include "opus_init.h"
#include "opus_defines.h"
#include "comlink_control.h"
#include "main.h"
#include <stdlib.h>


typedef struct
{
  uint16_t ENC_frame_size;                              /*!< Specifies the encoder frame size. */

  uint16_t DEC_frame_size;                              /*!< Specifies the decoder frame size. */

  uint16_t max_enc_frame_size;                          /*!< Specifies the maximum size of the encoder frame. */

  OpusEncoder *Encoder;                                 /*!< Opus encoder. */

  uint8_t ENC_configured;                               /*!< Specifies if the Encoder is configured. */

  OpusDecoder *Decoder;                                 /*!< Opus decoder. */

  uint8_t DEC_configured;                               /*!< Specifies if the Decoder is configured. */

} BV_OPUS_Codec_HandleTypeDef;

static BV_OPUS_Codec_HandleTypeDef hOpus;

BV_OPUS_ENC_ConfigTypeDef EncConfigOpus;                                        /*!< BlueVoice opus encode configuration.*/
BV_OPUS_DEC_ConfigTypeDef DecConfigOpus;                                        /*!< BlueVoice opus decode configuration.*/

/**
 * @brief BV_OPUS_Opus_HandleTypeDef structure definition
 */

/*
**
  * @brief  This function returns if the the Opus Decoder is configured.
  * @param  None.
  * @retval uint8_t: 1 if the Decoder is configured 0 otherwise.
  */

 uint8_t Opus_Profile_Init(void)
 {
	 BV_OPUS_Status status;

     EncConfigOpus.application = OPUS_APPLICATION_VOIP;
     EncConfigOpus.bitrate = 16000;
     EncConfigOpus.channels = AUDIO_CHANNELS_IN;
     EncConfigOpus.complexity = 0;
     EncConfigOpus.ms_frame = AUDIO_IN_MS;
     EncConfigOpus.sample_freq = AUDIO_SAMPLING_FREQUENCY;

     DecConfigOpus.bitrate = 16000;
     DecConfigOpus.channels = AUDIO_CHANNELS_OUT;
     DecConfigOpus.ms_frame = AUDIO_OUT_MS;
     DecConfigOpus.sample_freq = AUDIO_SAMPLING_FREQUENCY;

     uint32_t enc_size = BluevoiceOPUS_ENC_getMemorySize(&EncConfigOpus);

     EncConfigOpus.pInternalMemory = (uint8_t *)malloc(enc_size);

     uint32_t dec_size = BluevoiceOPUS_DEC_getMemorySize(&DecConfigOpus);

     DecConfigOpus.pInternalMemory = (uint8_t *)malloc(dec_size);

     int opus_err;
     status = BluevoiceOPUS_ENC_Init(&EncConfigOpus, &opus_err);

     if( status != BV_OPUS_SUCCESS)
     {
         Error_Handler();
     }

     status = BluevoiceOPUS_DEC_Init(&DecConfigOpus, &opus_err);

     if( status != BV_OPUS_SUCCESS)
     {
         Error_Handler();
     }

     /* SW task for opus compression and data sent */
     SW_IRQ_OpusTasks_Init();

     return 1;
 }

 /**
  * @brief  This functions returns the amount of memory required for the current bluevoice encoder setup.
  * @param  Opus encoder configuration.
  * @retval Number of byte.
  */
 uint32_t BluevoiceOPUS_ENC_getMemorySize(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus)
 {
   if((ENC_configOpus->bitrate<6000) || (ENC_configOpus->bitrate>510000))
     return BV_OPUS_INVALID_PARAM;
   if((ENC_configOpus->ms_frame!=2.5f) &&
        (ENC_configOpus->ms_frame!=5.0f) &&
          (ENC_configOpus->ms_frame!=10.0f) &&
            (ENC_configOpus->ms_frame!=20.0f) &&
              (ENC_configOpus->ms_frame!=40.0f) &&
                (ENC_configOpus->ms_frame!=60.0f))
   {
     return BV_OPUS_INVALID_PARAM;
   }

   uint32_t tot_enc_size;

   /* size x2 (worst case encode VBR) x2 (temp buffer used for BVTP) */
   hOpus.max_enc_frame_size = (ENC_configOpus->bitrate/8/((uint16_t)(1000.0f/ENC_configOpus->ms_frame)))*4;
   tot_enc_size = hOpus.max_enc_frame_size + (hOpus.max_enc_frame_size/19)+1;

   return tot_enc_size;
 }


 /**
  * @brief  This function returns the amount of memory required for the current bluevoice decoder setup.
  * @param  Opus decoder configuration.
  * @retval Number of byte.
  */
 uint32_t BluevoiceOPUS_DEC_getMemorySize(BV_OPUS_DEC_ConfigTypeDef *DEC_configOpus)
 {
   if((DEC_configOpus->bitrate<6000) || (DEC_configOpus->bitrate>510000))
     return BV_OPUS_INVALID_PARAM;
   if((DEC_configOpus->ms_frame!=2.5f) &&
        (DEC_configOpus->ms_frame!=5.0f) &&
          (DEC_configOpus->ms_frame!=10.0f) &&
            (DEC_configOpus->ms_frame!=20.0f) &&
              (DEC_configOpus->ms_frame!=40.0f) &&
                (DEC_configOpus->ms_frame!=60.0f))
   {
     return BV_OPUS_INVALID_PARAM;
   }

   uint32_t tot_dec_size = (DEC_configOpus->bitrate/8/((uint16_t)(1000.0f/DEC_configOpus->ms_frame)))*2;

   return tot_dec_size;
 }


uint8_t BluevoiceOPUS_ENC_Init(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int *opus_err)
 {
   if((ENC_configOpus->application!=OPUS_APPLICATION_VOIP) &&
        (ENC_configOpus->application!=OPUS_APPLICATION_AUDIO) &&
          (ENC_configOpus->application!=OPUS_APPLICATION_RESTRICTED_LOWDELAY))
   {
     return BV_OPUS_INVALID_PARAM;
   }
   if((ENC_configOpus->bitrate<6000) || (ENC_configOpus->bitrate>510000))
     return BV_OPUS_INVALID_PARAM;
   if(ENC_configOpus->complexity>10)
     return BV_OPUS_INVALID_PARAM;
   if(ENC_configOpus->channels==0)
     return BV_OPUS_INVALID_PARAM;
   if((ENC_configOpus->ms_frame!=2.5f) &&
        (ENC_configOpus->ms_frame!=5.0f) &&
          (ENC_configOpus->ms_frame!=10.0f) &&
            (ENC_configOpus->ms_frame!=20.0f) &&
              (ENC_configOpus->ms_frame!=40.0f) &&
                (ENC_configOpus->ms_frame!=60.0f))
   {
     return BV_OPUS_INVALID_PARAM;
   }
   if((ENC_configOpus->sample_freq!=8000) &&
        (ENC_configOpus->sample_freq!=12000) &&
          (ENC_configOpus->sample_freq!=16000) &&
            (ENC_configOpus->sample_freq!=24000) &&
              (ENC_configOpus->sample_freq!=48000))
   {
     return BV_OPUS_INVALID_PARAM;
   }

   hOpus.ENC_frame_size = (uint16_t)(((float)(ENC_configOpus->sample_freq/1000))*ENC_configOpus->ms_frame);

   *opus_err = 0;
   BV_OPUS_Status status;

   hOpus.Encoder = opus_encoder_create(ENC_configOpus->sample_freq, ENC_configOpus->channels, ENC_configOpus->application, opus_err);

   if (*opus_err != OPUS_OK)
   {
     return BV_OPUS_ERROR;
   }

   status = BluevoiceOPUS_ENC_Set_Bitrate(ENC_configOpus, ENC_configOpus->bitrate, opus_err);
   if (status != BV_OPUS_SUCCESS)
   {
     return BV_OPUS_ERROR;
   }

   status = BluevoiceOPUS_ENC_Set_Complexity(ENC_configOpus, ENC_configOpus->complexity, opus_err);
   if (status != BV_OPUS_SUCCESS)
   {
     return BV_OPUS_ERROR;
   }

   hOpus.ENC_configured = 1;

   return BV_OPUS_SUCCESS;
 }

 /**
  * @brief  Encoder deinit function.
  * @param  None.
  * @retval None.
  */
 void BluevoiceOPUS_ENC_Deinit(void)
 {
   opus_encoder_destroy(hOpus.Encoder);
   hOpus.ENC_configured = 0;
   hOpus.ENC_frame_size = 0;
   hOpus.max_enc_frame_size = 0;
 }

 /**
   * @brief  This function returns if the the Opus Encoder is configured.
   * @param  None.
   * @retval uint8_t: 1 if the Encoder is configured 0 otherwise.
   */
 uint8_t BluevoiceOPUS_ENC_IsConfigured(void)
 {
  return hOpus.ENC_configured;
 }

 /**
  * @brief  Decoder initialization.
  * @param  Opus decoder configuration.
  * @param  opus_err: @ref opus_errorcodes
  * @retval BV_OPUS_Status: Value indicating success or error (in case of error check opus_err).
  */
 uint8_t BluevoiceOPUS_DEC_Init(BV_OPUS_DEC_ConfigTypeDef *DEC_configOpus, int *opus_err)
 {
   if((DEC_configOpus->bitrate<6000) || (DEC_configOpus->bitrate>510000))
     return BV_OPUS_INVALID_PARAM;
   if(DEC_configOpus->channels==0)
     return BV_OPUS_INVALID_PARAM;
   if((DEC_configOpus->ms_frame!=2.5f) &&
        (DEC_configOpus->ms_frame!=5.0f) &&
          (DEC_configOpus->ms_frame!=10.0f) &&
            (DEC_configOpus->ms_frame!=20.0f) &&
              (DEC_configOpus->ms_frame!=40.0f) &&
                (DEC_configOpus->ms_frame!=60.0f))
   {
     return BV_OPUS_INVALID_PARAM;
   }
   if((DEC_configOpus->sample_freq!=8000) &&
        (DEC_configOpus->sample_freq!=12000) &&
          (DEC_configOpus->sample_freq!=16000) &&
            (DEC_configOpus->sample_freq!=24000) &&
              (DEC_configOpus->sample_freq!=48000))
   {
     return BV_OPUS_INVALID_PARAM;
   }

   hOpus.DEC_frame_size = (uint16_t)(((float)(DEC_configOpus->sample_freq/1000))*DEC_configOpus->ms_frame);

   /*Decoder Init*/
   hOpus.Decoder = opus_decoder_create(DEC_configOpus->sample_freq, DEC_configOpus->channels, opus_err);

   if (*opus_err != OPUS_OK)
   {
     return BV_OPUS_ERROR;
   }

   hOpus.DEC_configured = 1;

   return BV_OPUS_SUCCESS;
 }

 /**
  * @brief  Decoder deinit function.
  * @param  None.
  * @retval None.
  */
 void BluevoiceOPUS_DEC_Deinit(void)
 {
   opus_decoder_destroy(hOpus.Decoder);
   hOpus.DEC_configured = 0;
   hOpus.DEC_frame_size = 0;
 }

uint8_t BluevoiceOPUS_DEC_IsConfigured(void)
{
 return hOpus.DEC_configured;
}

/**
 * @brief  Set bitrate to be used for encoding
 * @param  bitrate: Indicate the bitrate in bit per second.
 * @param  opus_err: @ref opus_errorcodes.
 * @retval BV_OPUS_Status: Value indicating success or error (in case of error check opus_err).
 */
uint8_t BluevoiceOPUS_ENC_Set_Bitrate(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int bitrate, int *opus_err)
{
  if((bitrate<6000) || (bitrate>510000))
    return BV_OPUS_INVALID_PARAM;

  ENC_configOpus->bitrate = bitrate;
  *opus_err =  opus_encoder_ctl(hOpus.Encoder, OPUS_SET_BITRATE(bitrate));
  if (*opus_err != OPUS_OK)
  {
    return BV_OPUS_ERROR;
  }

  return BV_OPUS_SUCCESS;
}

/**
 * @brief  Set constant bitrate option for the encoder.
 * @param  None.
 * @retval BV_OPUS_Status: Value indicating success or error.
 */
uint8_t BluevoiceOPUS_ENC_Set_CBR(void)
{
  int err =  opus_encoder_ctl(hOpus.Encoder, OPUS_SET_VBR(0));
  if (err != OPUS_OK)
  {
    return BV_OPUS_ERROR;
  }

  return BV_OPUS_SUCCESS;
}

/**
 * @brief  Set variable bitrate option for the encoder.
 * @param  None.
 * @retval BV_OPUS_Status: Value indicating success or error.
 */
uint8_t BluevoiceOPUS_ENC_Set_VBR(void)
{
  int err =  opus_encoder_ctl(hOpus.Encoder, OPUS_SET_VBR(1));
  if (err != OPUS_OK)
  {
    return BV_OPUS_ERROR;
  }

  return BV_OPUS_SUCCESS;
}


/**
 * @brief  Set complexity to be used for encoding
 * @param  complexity: value from o to 10.
 * @param  opus_err: @ref opus_errorcodes.
 * @retval BV_OPUS_Status: Value indicating success or error (in case of error check opus_err).
 */
uint8_t BluevoiceOPUS_ENC_Set_Complexity(BV_OPUS_ENC_ConfigTypeDef *ENC_configOpus, int complexity, int *opus_err)
{
  if(complexity>10)
    return BV_OPUS_INVALID_PARAM;

  ENC_configOpus->complexity = complexity;
  *opus_err = opus_encoder_ctl(hOpus.Encoder, OPUS_SET_COMPLEXITY(complexity));

  if (*opus_err != OPUS_OK)
  {
    return BV_OPUS_ERROR;
  }

  return BV_OPUS_SUCCESS;
}

/**
 * @brief  Encoding functions.
 * @param  buf_in: pointer to the PCM buffer to be encoded.
 * @param  buf_out: pointer to the Encoded buffer.
 * @retval Number of bytes in case of success, 0 viceversa.
 */
int BluevoiceOPUS_ENC_Encode(uint8_t * buf_in, uint8_t * buf_out)
{
  return opus_encode(hOpus.Encoder, (opus_int16 *) buf_in, hOpus.ENC_frame_size, (unsigned char *) buf_out, (opus_int32) hOpus.max_enc_frame_size);
}

/**
 * @brief  Decoding functions.
 * @param  buf_in: pointer to the Encoded buffer to be decoded.
 * @param  len: length of the buffer in.
 * @param  buf_out: pointer to the Decoded buffer.
 * @retval Number of decoded samples or @ref opus_errorcodes.
 */
int BluevoiceOPUS_DEC_Decode(uint8_t * buf_in, uint32_t len, uint8_t * buf_out)
{
  return opus_decode(hOpus.Decoder, (unsigned char *) buf_in, (opus_int32) len, (opus_int16 *) buf_out, hOpus.DEC_frame_size, 0);
}


