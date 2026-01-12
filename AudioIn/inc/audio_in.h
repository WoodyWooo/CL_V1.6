/*
 * audio_in.h
 *
 *  Created on: Dec 9, 2024
 *      Author: elecinnov2
 */

#ifndef INC_AUDIO_IN_H_
#define INC_AUDIO_IN_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "comlink_control.h"

///#include "../../ExtraDrivers/inc/stm32f4xx_hal_i2s.h"
#include "../../ExtraDrivers/inc/stm32f4xx_hal_spi.h"


  /* AUDIO TIMER definitions */
#define AUDIO_IN_TIMER                                     TIM3
#define AUDIO_IN_TIMER_CLK_ENABLE()                        __TIM3_CLK_ENABLE()
#define AUDIO_IN_TIMER_CHOUT_AF                            GPIO_AF2_TIM3
#define AUDIO_IN_TIMER_CHOUT_PIN                           GPIO_PIN_5
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT                     GPIOB
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT_CLK_ENABLE()        __GPIOB_CLK_ENABLE()
#define AUDIO_IN_TIMER_CHIN_AF                             GPIO_AF2_TIM3
#define AUDIO_IN_TIMER_CHIN_PIN                            GPIO_PIN_6//GPIO_PIN_4//
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT                      GPIOC//GPIOB//
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT_CLK_ENABLE()         __GPIOC_CLK_ENABLE()//__GPIOB_CLK_ENABLE()//

  /* I2S Configuration defines */
#define AUDIO_IN_I2S_INSTANCE                                    SPI2
#define AUDIO_IN_I2S_CLK_ENABLE()                                __SPI2_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_PIN                                     GPIO_PIN_13
#define AUDIO_IN_I2S_SCK_GPIO_PORT                               GPIOB
#define AUDIO_IN_I2S_SCK_GPIO_CLK_ENABLE()                       __GPIOB_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_AF                                      GPIO_AF5_SPI2
#define AUDIO_IN_I2S_MOSI_PIN                                    GPIO_PIN_1//GPIO_PIN_15//
#define AUDIO_IN_I2S_MOSI_GPIO_PORT                              GPIOC//GPIOB//
#define AUDIO_IN_I2S_MOSI_GPIO_CLK_ENABLE()                      __GPIOC_CLK_ENABLE()//__GPIOB_CLK_ENABLE()//
#define AUDIO_IN_I2S_MOSI_AF                                     GPIO_AF7_SPI2//GPIO_AF5_SPI2

  /* I2S DMA definitions */
#define AUDIO_IN_I2S_DMAx_CLK_ENABLE()                          __DMA1_CLK_ENABLE()
#define AUDIO_IN_I2S_DMAx_STREAM                                DMA1_Stream3
#define AUDIO_IN_I2S_DMAx_CHANNEL                               DMA_CHANNEL_0
#define AUDIO_IN_I2S_DMAx_IRQ                                   DMA1_Stream3_IRQn
#define AUDIO_IN_I2S_DMAx_PERIPH_DATA_SIZE                      DMA_PDATAALIGN_HALFWORD
#define AUDIO_IN_I2S_DMAx_MEM_DATA_SIZE                         DMA_MDATAALIGN_HALFWORD
#define AUDIO_IN_I2S_IRQHandler                                 DMA1_Stream3_IRQHandler

  /* Select the interrupt preemption priority  */
#define AUDIO_IN_IRQ_PREPRIO          6

#define DMA_MAX(_X_)                (((_X_) <= DMA_MAX_SZE)? (_X_):DMA_MAX_SZE)

#define HTONS(A)  ((((uint16_t)(A) & 0xff00) >> 8) | \
                   (((uint16_t)(A) & 0x00ff) << 8))


typedef struct
{
  uint32_t MicChannels;       /*!< Specifies the number of channels */

  uint32_t PdmBufferSize;     /*!< Specifies the size of the PDM double buffer for 1 microphone and 1 ms in bytes*/

  uint32_t PCM_Sampling_Freq;     /*!< Specifies the desired sampling frequency */

  uint32_t PDM_Clock_Freq;     /*!< Specifies the desired sampling frequency */

  uint32_t DecimationFactor;  /*!< Specifies the PDM to PCM decimation factor */

  uint16_t * PDM_Data;      /*!< Takes track of the external PDM data buffer as passed by the user in the start function*/

}
Audio_IN_Setting_TypeDef;

void Audio_IN_Init(uint32_t AudioFreq, uint32_t BitRes, uint32_t ChnlNbr);
uint8_t Audio_IN_Timer_Init(void);
uint8_t Audio_IN_ClockConfig(I2S_HandleTypeDef *hi2s, uint32_t AudioFreq, void *Params);
void Audio_IN_I2S_MspInit(void);
uint8_t Audio_IN_Record(uint16_t * pbuf, uint32_t size);
uint8_t Audio_IN_Pause(void);
uint8_t Audio_IN_Resume(void);
uint8_t Audio_IN_Timer_Start(void);
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s);
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s);


#endif /* INC_AUDIO_IN_H_ */
