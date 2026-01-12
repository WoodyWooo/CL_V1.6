/*
 * SDR.h
 *
 *  Created on: Oct 19, 2024
 *      Author: michaelsmart
 */

#ifndef AUDIOFUNC_INC_SDR_H_
#define AUDIOFUNC_INC_SDR_H_

#include "stdint.h"
#include "stm32f4xx.h"
#include "sdr_glo.h"

#define SDR_THR1DB_MAX  40
#define SDR_THR1DB_MIN  SDR_THR2DB_MIN+2

#define SDR_THR2DB_MAX  SDR_THR1DB_MAX-2
#define SDR_THR2DB_MIN  1

#define SDR_NOISEPWRMINDB_MAX  0
#define SDR_NOISEPWRMINDB_MIN  -87

#define SDR_HANGOVERNBFR_MAX  20
#define SDR_HANGOVERNBFR_MIN  2

#define SDR_DEC_HIST_MAX  1000

typedef enum {

  SDR_OK = 0,
  SDR_ERROR_IO,
  SDR_ERROR_EOF,
  SDR_ERROR_INVALID_VALUE,
  SDR_ERROR,
  SDR_DETECTED_AUDIO,
  SDR_NO_AUDIO_DETECTED,

}SDR_StateTypeDef;

SDR_StateTypeDef SDR_Init(uint16_t buffLen);
SDR_StateTypeDef SDR_Process(uint16_t *buffer, uint16_t buffLen);



#endif /* AUDIOFUNC_INC_SDR_H_ */
