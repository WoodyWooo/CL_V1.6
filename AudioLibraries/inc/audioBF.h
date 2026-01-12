/*
 * audioBF.h
 *
 *  Created on: Oct 18, 2024
 *      Author: michaelsmart
 */

#ifndef INC_AUDIOBF_H_
#define INC_AUDIOBF_H_

#include "acoustic_bf.h"
#include "comlink_control.h"


void BF_Init(void);
void SW_IRQ_BF_Tasks_Init(void);
void SW_Task1_Callback(void);
void SW_Task1_Start(void);
void SW_Task2_Start(void);
uint8_t AUDIO_IN_PDM_To_BFPCM(uint16_t *PDMBuf, uint16_t *PCMBuf);





#endif /* AUDIOFUNC_INC_AUDIOBF_H_ */
