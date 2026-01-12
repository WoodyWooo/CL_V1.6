/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "pdm2pcm.h"
#include "rtc.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../AudioIn/inc/audio_in.h"
#include "opus_init.h"
#include "audioBF.h"
#include "SDR.h"
#include "ESP_link.h"
#include "comlink_control.h"
#include "PCM1774_CODEC_Driver.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// Require PB_1_INPUT to be high for this long to wake fully (ms)
#define PB1_WAKE_LONG_PRESS_MS   2000U

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t IRQ = 0;
extern volatile PowerState_t gPowerState;   // from gpio.c

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */
static void Enter_Stop_Mode(void);
static uint8_t PB1_Wakeup_LongPress_Detected(uint32_t requiredHighMs);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */
  //HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_PDM2PCM_Init();
  MX_TIM2_Init();
  MX_RTC_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  /*__HAL_RCC_PWR_CLK_ENABLE();

  if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
  {
	  for(int i=0; i<10; i++)
	  {
		  HAL_GPIO_TogglePin(STATUS_LED_GPIO_Port, STATUS_LED_Pin);
		  HAL_Delay(200);
	  }
  }*/

  //HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);

  TIM2->SR = 0;   // Set tim2 Status Register to 0 to avoid immediate IRQ

  ESP_SPI_Init();
  ESP_RST();

  /* initialise AcousticBF SW interrupts */
  SW_IRQ_BF_Tasks_Init();
  /* initialise AcousticBF */
  BF_Init();

  SDR_Init(PCM_BUFFER_IN_LEN);

  /* initialise Opus profile */
  Opus_Profile_Init();

  Start_Audio_In();
  Start_Audio_Out();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  ESP_Process();

	  if (goToStop)
	  {
		  Enter_Stop_Mode();
		  goToStop=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLRCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO2SOURCE_PLLI2SCLK, RCC_MCODIV_2);
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_PLLI2S;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 258;
  PeriphClkInitStruct.PLLI2S.PLLI2SP = RCC_PLLI2SP_DIV2;
  PeriphClkInitStruct.PLLI2S.PLLI2SM = 16;
  PeriphClkInitStruct.PLLI2S.PLLI2SR = 6;
  PeriphClkInitStruct.PLLI2S.PLLI2SQ = 2;
  PeriphClkInitStruct.PLLI2SDivQ = 1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
static void Enter_Stop_Mode(void)
{
	/*__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_GPIO_WritePin(ESP_RESET_PORT, ESP_RESET_PIN, GPIO_PIN_RESET);
	HAL_SuspendTick();
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	HAL_ResumeTick();
	SystemClock_Config();
	PeriphCommonClock_Config();
	TIM2->SR = 0;
	ESP_RST();*/

	gPowerState = POWER_STATE_OFF;

	    while (1)
	    {
	        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	        HAL_GPIO_WritePin(ESP_RESET_PORT, ESP_RESET_PIN, GPIO_PIN_RESET);
	        pcm1774_PowerDown(PCM1774_X_0_handle);

	        HAL_SuspendTick();
	        HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	        HAL_ResumeTick();

	        // We woke up here because of an EXTI (likely PB1)
	        SystemClock_Config();
	        PeriphCommonClock_Config();
	        TIM2->SR = 0;


	        // Check if PB1 stayed high long enough to consider this a "turn ON"
	        if (PB1_Wakeup_LongPress_Detected(PB1_WAKE_LONG_PRESS_MS))
	        {
	            gPowerState = POWER_STATE_ON;
	            ESP_RST();
	            Start_Audio_In();
	            break;   // Exit STOP loop, return to main()
	        }

	        // Short or accidental wake – loop back and re-enter STOP
	    }

}

static uint8_t PB1_Wakeup_LongPress_Detected(uint32_t requiredHighMs)
{
	uint32_t tStart;

	// If button isn't high when we wake, treat as short/accidental
	if (HAL_GPIO_ReadPin(PB_1_INPUT_GPIO_Port, PB_1_INPUT_Pin) == GPIO_PIN_RESET)
	{
		return 0;
	}

	tStart = HAL_GetTick();

	// Stay here while button is held high and watch the time
	while (HAL_GPIO_ReadPin(PB_1_INPUT_GPIO_Port, PB_1_INPUT_Pin) == GPIO_PIN_SET)
	{
		if ((HAL_GetTick() - tStart) >= requiredHighMs)
		{
			// Held high long enough – valid wake
			return 1;
		}
	}

	// Released before requiredHighMs – treat as short press
	return 0;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  Toggle_LED();
	  HAL_Delay(500);
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
