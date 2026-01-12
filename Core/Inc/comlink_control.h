/*
 * comlink_control.h
 *
 *  Created on: Dec 11, 2024
 *      Author: michael smart
 */

#ifndef INC_COMLINK_CONTROL_H_
#define INC_COMLINK_CONTROL_H_

#include "stdint.h"
#include "opus_init.h"


#define BF_CHANNELS_IN                      (uint16_t)(2)//(uint16_t) (IN_CHANNELS_2)
#define AUDIO_CHANNELS_IN                   (uint16_t)(1)//(uint16_t) (IN_CHANNELS_1)
#define AUDIO_CHANNELS_OUT                  (uint16_t)(1)// (uint16_t) (OUT_CHANNELS_1)

#define AUDIO_SAMPLING_FREQUENCY			(uint16_t)(16000)
#define PCM_IN_SAMPLES_PER_MS              	(AUDIO_SAMPLING_FREQUENCY/1000)            /*!< Number of PCM samples for each ms of audio acquired.*/
#define PCM_OUT_SAMPLES_PER_MS             	(AUDIO_SAMPLING_FREQUENCY/1000)            /*!< Number of PCM samples for each ms of audio given as output.*/
#define AUDIO_IN_MS                        	(N_MS_PER_INTERRUPT)                         /*!< Number of ms of Audio given as input to the BlueVoice library.*/
#define PCM_AUDIO_IN_SAMPLES               	(PCM_IN_SAMPLES_PER_MS * AUDIO_IN_MS)        /*!< Number of PCM samples input total.*/
#define AUDIO_OUT_MS                       	(20)                          /*!< Number of ms of Audio buffered in Rx before USB.*/
#define PCM_BUFFER_IN_LEN                  	(PCM_IN_SAMPLES_PER_MS * AUDIO_OUT_MS)
#define PCM_BUFFER_OUT_LEN                 	(PCM_OUT_SAMPLES_PER_MS * AUDIO_OUT_MS * 20) /*!< Number of PCM samples output total.*/

/*Number of millisecond of audio at each DMA interrupt*/
#define N_MS_PER_INTERRUPT          20
#define BF_N_MS_PER_INTERRUPT       1
#define PDM_FREQ_16K                1024//2048
#define MAX_DECIMATION_FACTOR       128
#define PDM_IN_BUFFSIZE				((((AUDIO_CHANNELS_IN * AUDIO_SAMPLING_FREQUENCY)/1000) * MAX_DECIMATION_FACTOR) / 16)  * N_MS_PER_INTERRUPT
//#define PCM_BUFFER_IN_LEN			((AUDIO_IN_CHANNELS * AUDIO_SAMPLING_FREQUENCY)/1000) * N_MS_PER_INTERRUPT
#define PCM_IN_SAMPLES_PER_MS   	(AUDIO_SAMPLING_FREQUENCY/1000)

typedef enum {
  Idle= 0,
  Rx,
  TxRx,
  Tx,
  BtData,
  RxBtData,
  TxRxBtData,
  TxBtData,
}SPI_State;

typedef enum {
  Disconnected= 0,
  Connected,
}ESP_BT_State;

extern void *PCM1774_X_0_handle;

void ESP_Process(void);
void Start_Audio_Out(void);
void Stop_Audio_Out(void);
void Play_Audio(uint8_t data_len, uint8_t *dataBuf);
void Audio_IN_HalfTransfer_CallBack(void);
void Audio_IN_TransferComplete_CallBack(void);
void Audio_Process(void);
void Start_Audio_In(void);
void SW_IRQ_OpusTasks_Init(void);
void SW_OpusTask_Start(void);
void SW_OpusTask_Callback(void);
void Write_to_ESP(uint8_t *data, uint8_t len, uint8_t SPIstate);
uint8_t SpiDataTransfer(uint8_t *data_in, BV_OPUS_ENC_ConfigTypeDef *enc_config, int *opus_err, uint8_t SPIstate, uint8_t volt);
void Power_Save(uint16_t sleepMillis);

#endif /* INC_COMLINK_CONTROL_H_ */
