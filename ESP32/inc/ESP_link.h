/*
 * ESP_link.h
 *
 *  Created on: Sep 17, 2024
 *      Author: michaelsmart
 */
#include "stm32f4xx_hal.h"

#ifndef ESP32_INC_ESP_LINK_H_
#define ESP32_INC_ESP_LINK_H_

// SPI Reset Pin: PC.7
#define ESP_SPI_READY_PIN         	GPIO_PIN_7
#define ESP_SPI_READY_PORT       	GPIOC

// ESP Reset Pin: PA.8
#define ESP_RESET_PIN          GPIO_PIN_8
#define ESP_RESET_PORT         GPIOA

// SCLK: PC.10
#define ESP_SPI_SCLK_PIN           GPIO_PIN_10
#define ESP_SPI_SCLK_PORT          GPIOC

// MISO (Master Input Slave Output): PC.11
#define ESP_SPI_MISO_PIN           GPIO_PIN_11
#define ESP_SPI_MISO_PORT          GPIOC

// MOSI (Master Output Slave Input): PC.12
#define ESP_SPI_MOSI_PIN           GPIO_PIN_12
#define ESP_SPI_MOSI_PORT          GPIOC

// NSS/CSN/CS: PA.11
#define ESP_SPI_CS_PIN             GPIO_PIN_4
#define ESP_SPI_CS_PORT            GPIOB

// IRQ: PA.0
//#define ESP_to_F446_IRQ_PIN            GPIO_PIN_0
//#define ESP_to_F446_IRQ_PORT           GPIOA


// EXTI External Interrupt for SPI
// NOTE: if you change the IRQ pin remember to implement a corresponding handler
// function like EXTI0_IRQHandler() in the user project
//#define ESP_to_F446_IRQn          EXTI0_IRQn
//#define ESP_to_F446_IRQHandler    EXTI0_IRQHandler

#define RTC_WAKEUP_IRQHandler       RTC_WKUP_IRQHandler

void ESP_SPI_Init(void);
uint8_t ESP_SPI_Ready(void);
uint16_t ESP_RST(void);



#endif /* ESP32_INC_ESP_LINK_H_ */
