/*
 * ESP_link.c
 *
 *  Created on: Sep 17, 2024
 *      Author: michaelsmart
 */

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "ESP_link.h"
#include "main.h"


SPI_HandleTypeDef SpiHandle;

void ESP_SPI_Init(void)
{
	__SPI3_CLK_ENABLE();
	SpiHandle.Instance = SPI3;
	SpiHandle.Init.Mode = SPI_MODE_MASTER;
	SpiHandle.Init.Direction = SPI_DIRECTION_2LINES;
	SpiHandle.Init.DataSize = SPI_DATASIZE_8BIT;
	SpiHandle.Init.CLKPolarity = SPI_POLARITY_LOW;
	SpiHandle.Init.CLKPhase = SPI_PHASE_1EDGE;
	SpiHandle.Init.NSS = SPI_NSS_SOFT;
	SpiHandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
	SpiHandle.Init.TIMode = SPI_TIMODE_DISABLED;
	SpiHandle.Init.CRCPolynomial = 7;
	SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	SpiHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;

	HAL_SPI_Init(&SpiHandle);

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct;

    /* Enable peripherals clock */

    /* Enable GPIO Ports Clock */
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();


    /* Enable SPI clock */
	__SPI3_CLK_ENABLE();

    /* Reset */
    GPIO_InitStruct.Pin = ESP_RESET_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(ESP_RESET_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(ESP_RESET_PORT, ESP_RESET_PIN, GPIO_PIN_RESET);

    /* SCLK */
    GPIO_InitStruct.Pin = ESP_SPI_SCLK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(ESP_SPI_SCLK_PORT, &GPIO_InitStruct);

    /* MISO */
    GPIO_InitStruct.Pin = ESP_SPI_MISO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull =  GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(ESP_SPI_MISO_PORT, &GPIO_InitStruct);

    /* MOSI */
    GPIO_InitStruct.Pin = ESP_SPI_MOSI_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(ESP_SPI_MOSI_PORT, &GPIO_InitStruct);

    /* NSS/CSN/CS */
    GPIO_InitStruct.Pin = ESP_SPI_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(ESP_SPI_CS_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(ESP_SPI_CS_PORT, ESP_SPI_CS_PIN, GPIO_PIN_SET);

    /* IRQ -- INPUT */
   /* GPIO_InitStruct.Pin = ESP_to_F446_IRQ_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(ESP_to_F446_IRQ_PIN, &GPIO_InitStruct);*/

    /* ESP_STATUS_Pin -- INPUT*/
    GPIO_InitStruct.Pin = ESP_SPI_READY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(ESP_SPI_READY_PORT, &GPIO_InitStruct);

    /* Configure the NVIC for SPI */
   // HAL_NVIC_SetPriority(ESP_to_F446_IRQn, 3, 0);
   // HAL_NVIC_EnableIRQ(ESP_to_F446_IRQn);

}


/**
 * @brief  Resets the BlueNRG.
 * @param  None
 * @retval None
 */

uint16_t ESP_RST(void)
{
  HAL_GPIO_WritePin(ESP_RESET_PORT, ESP_RESET_PIN, GPIO_PIN_RESET);
  HAL_Delay(5);
  HAL_GPIO_WritePin(ESP_RESET_PORT, ESP_RESET_PIN, GPIO_PIN_SET);
  HAL_Delay(700);

  if (HAL_GPIO_ReadPin(ESP_F446_IRQ_GPIO_Port, ESP_F446_IRQ_Pin) == GPIO_PIN_RESET)
  {
	  return 1;
  }
  else
  {
	  return 0;
  }
}

/**
 * @brief  Reports if the BlueNRG has data for the host micro.
 * @param  None
 * @retval 1 if data are present, 0 otherwise
 */
// FIXME: find a better way to handle this return value (bool type? TRUE and FALSE)
int ESPloaded=0;
uint8_t ESP_SPI_Ready(void)
{
  if (HAL_GPIO_ReadPin(ESP_SPI_READY_PORT, ESP_SPI_READY_PIN) == GPIO_PIN_SET)
  {
	  ESPloaded++;
	  return 1;
  }
  else
      return 0;
}


