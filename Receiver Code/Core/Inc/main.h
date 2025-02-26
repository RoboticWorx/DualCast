/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DIO3_Pin GPIO_PIN_13
#define DIO3_GPIO_Port GPIOC
#define IO1_Pin GPIO_PIN_3
#define IO1_GPIO_Port GPIOA
#define IO2_Pin GPIO_PIN_4
#define IO2_GPIO_Port GPIOA
#define IO3_Pin GPIO_PIN_5
#define IO3_GPIO_Port GPIOA
#define IO4_Pin GPIO_PIN_6
#define IO4_GPIO_Port GPIOA
#define IO5_Pin GPIO_PIN_7
#define IO5_GPIO_Port GPIOA
#define BTN_Pin GPIO_PIN_2
#define BTN_GPIO_Port GPIOB
#define BLINK_Pin GPIO_PIN_12
#define BLINK_GPIO_Port GPIOB
#define XSHUT_Pin GPIO_PIN_13
#define XSHUT_GPIO_Port GPIOB
#define VL_INT_Pin GPIO_PIN_14
#define VL_INT_GPIO_Port GPIOB
#define BME_ADR_Pin GPIO_PIN_15
#define BME_ADR_GPIO_Port GPIOB
#define ANT_SW_Pin GPIO_PIN_8
#define ANT_SW_GPIO_Port GPIOA
#define SX_BUSY_Pin GPIO_PIN_15
#define SX_BUSY_GPIO_Port GPIOA
#define SX_CS_Pin GPIO_PIN_6
#define SX_CS_GPIO_Port GPIOB
#define SX_NRST_Pin GPIO_PIN_7
#define SX_NRST_GPIO_Port GPIOB
#define DIO1_Pin GPIO_PIN_8
#define DIO1_GPIO_Port GPIOB
#define DIO1_EXTI_IRQn EXTI4_15_IRQn
#define DIO2_Pin GPIO_PIN_9
#define DIO2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
