/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
#include "tim.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include "ESP_link.h"

#define OFF_LONG_PRESS_TICKS   10U

extern TIM_HandleTypeDef htim2;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

extern volatile PowerState_t gPowerState;   // from gpio.c
volatile PowerState_t gPowerState = POWER_STATE_ON;
uint8_t status=0;
volatile uint8_t goToStop = 0;
volatile uint8_t goToStart = 1;
/* USER CODE END 1 */

/** Configure pins
     PC9   ------> RCC_MCO_2
     PB6   ------> I2C1_SCL
     PB7   ------> I2C1_SDA
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ESP_SLEEP_CTRL_GPIO_Port, ESP_SLEEP_CTRL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB_1_INPUT_Pin */
  GPIO_InitStruct.Pin = PB_1_INPUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(PB_1_INPUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ESP_F446_IRQ_Pin */
  GPIO_InitStruct.Pin = ESP_F446_IRQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ESP_F446_IRQ_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB_2_INPUT_Pin */
  GPIO_InitStruct.Pin = PB_2_INPUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PB_2_INPUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : STATUS_LED_Pin */
  GPIO_InitStruct.Pin = STATUS_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(STATUS_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ESP_SLEEP_CTRL_Pin */
  GPIO_InitStruct.Pin = ESP_SLEEP_CTRL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(ESP_SLEEP_CTRL_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

//Blink LED and then open circuit to battery
uint8_t onOffDelay = 0;
uint8_t On_Off_Sequence(uint8_t NumberOfBlinks)
{
	//Disable and DeInit ESP_F446_IRQ_Pin to use PA0 as Wakeup1. Only PA0 can wake from Standby
	/*HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	__HAL_GPIO_EXTI_CLEAR_IT(ESP_F446_IRQ_Pin);
	HAL_GPIO_DeInit(ESP_F446_IRQ_GPIO_Port, ESP_F446_IRQ_Pin);*/

	/*if (onOffDelay == 0)
	{
		__HAL_TIM_SET_AUTORELOAD(&htim2, 10000);
		HAL_TIM_Base_Start_IT(&htim2);
	}

	Toggle_LED();
	onOffDelay++;

	if(onOffDelay == NumberOfBlinks)
	{

		goToStop = 1;
		onOffDelay = 0;
	}

	return onOffDelay;*/


	// One blink step every TIM2 period
	Toggle_LED();
	onOffDelay++;

	if (onOffDelay >= NumberOfBlinks)
	{
		// Done blinking – request STOP and reset state
		HAL_TIM_Base_Stop_IT(&htim2);
		onOffDelay   = 0;
		goToStop     = 1;
		gPowerState  = POWER_STATE_OFF;
	}


}

void Toggle_LED(void)
{
	if (HAL_GPIO_ReadPin(STATUS_LED_GPIO_Port, STATUS_LED_Pin) == GPIO_PIN_SET)
	{
		HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_RESET);
	}

	else if (HAL_GPIO_ReadPin(STATUS_LED_GPIO_Port, STATUS_LED_Pin) == GPIO_PIN_RESET)
	{
		HAL_GPIO_WritePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_SET);
	}

}

void On_Off_Sequence_Detect(void)
{

	/*if((HAL_GPIO_ReadPin(PB_1_INPUT_GPIO_Port, PB_1_INPUT_Pin)) == GPIO_PIN_SET)
	{
		TIM2->CNT = 0;
		HAL_TIM_Base_Start_IT(&htim2);
		//break;
	}
	if((HAL_GPIO_ReadPin(PB_1_INPUT_GPIO_Port, PB_1_INPUT_Pin)) == GPIO_PIN_RESET)
	{
		if (onOffDelay == 0)
			HAL_TIM_Base_Stop(&htim2);
	}*/

	GPIO_PinState pin = HAL_GPIO_ReadPin(PB_1_INPUT_GPIO_Port, PB_1_INPUT_Pin);

	if (pin == GPIO_PIN_SET)
	{
		// Button pressed
		if (gPowerState == POWER_STATE_ON && onOffDelay == 0)
		{
			// Start measuring long press to turn OFF
			TIM2->CNT = 0;
			__HAL_TIM_SET_AUTORELOAD(&htim2, 10000);      // Your existing period
			HAL_TIM_Base_Start_IT(&htim2);
		}
	}
	else // pin == GPIO_PIN_RESET
	{
		// Button released
		if (gPowerState == POWER_STATE_ON)
		{
			// If timer has not yet ticked, cancel (short tap)
			if (onOffDelay == 0)
			{
				HAL_TIM_Base_Stop_IT(&htim2);
			}
			// If onOffDelay > 0, we let the sequence finish in the timer callback.
		}
	}


}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		On_Off_Sequence(10);
	}
}

/* USER CODE END 2 */
