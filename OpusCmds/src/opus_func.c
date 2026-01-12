/*
 * opus_func.c
 *
 *  Created on: Jan 16, 2025
 *      Author: m.smart
 */

#include "opus.h"
#include "opus_init.h"
#include "opus_func.h"



/**
 * @brief  This function is called to decode audio data using opus.
 * @param  buf_in: pointer to the encoded buffer.
 * @param  len_in: buffer in length.
 * @param  buf_out: pointer to the decoded buffer.
 * @param  pcm_samples: number of PCM samples decoded.
 * @param  dec_config: decoder configuration.
 * @param  opus_err: @ref opus_errorcodes.
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
uint8_t BluevoiceOPUS_ParseData(uint8_t *buf_in, uint8_t len_in, uint8_t *buf_out, uint16_t *pcm_samples, BV_OPUS_DEC_ConfigTypeDef *dec_config, int *opus_err)
{
  if(!BluevoiceOPUS_DEC_IsConfigured())
  {
    return BV_OPUS_DEC_NOT_CONFIG;
  }

  uint32_t OpusDecBufLen = len_in;

  if (OpusDecBufLen > 0)
  {
    //*opus_err = BluevoiceOPUS_DEC_Decode(dec_config->pInternalMemory, OpusDecBufLen, buf_out);
	  *opus_err = BluevoiceOPUS_DEC_Decode(buf_in, OpusDecBufLen, buf_out);

    if(*opus_err<=0)
    {
      *pcm_samples = 0;
      return BV_OPUS_ERROR;
    }
    else
    {
      *pcm_samples = *opus_err;
      return BV_OPUS_SUCCESS;
    }
  }
  else
  {
    return BV_OPUS_PKT_NOT_COMPLETE;
  }
}





