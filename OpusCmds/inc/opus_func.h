/*
 * opus_func.h
 *
 *  Created on: Jan 16, 2025
 *      Author: elecinnov2
 */

#ifndef INC_OPUS_FUNC_H_
#define INC_OPUS_FUNC_H_

#include <stdint.h>


uint8_t BluevoiceOPUS_ParseData(uint8_t *buf_in, uint8_t len_in, uint8_t *buf_out, uint16_t *pcm_samples, BV_OPUS_DEC_ConfigTypeDef *dec_config, int *opus_err);

#endif /* INC_OPUS_FUNC_H_ */
