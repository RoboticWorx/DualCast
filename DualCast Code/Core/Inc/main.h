/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct {
    int ap_count;
    char ssid[64];
    char bssid[18];
    int rssi;
    int channel;
    int auth_mode;
} wifi_ap_data_t;

typedef struct {
    char bssid[20][18]; // Array to store BSSIDs
    int channel[20];    // Array to store channels
} wifi_analyze_data_t;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WL_STOP_WAKE_Pin GPIO_PIN_2
#define WL_STOP_WAKE_GPIO_Port GPIOE
#define WL_DEEP_WAKE_Pin GPIO_PIN_3
#define WL_DEEP_WAKE_GPIO_Port GPIOE
#define S1_BTN_Pin GPIO_PIN_4
#define S1_BTN_GPIO_Port GPIOE
#define S1_BTN_EXTI_IRQn EXTI4_IRQn
#define S2_BTN_Pin GPIO_PIN_5
#define S2_BTN_GPIO_Port GPIOE
#define S2_BTN_EXTI_IRQn EXTI5_IRQn
#define S3_BTN_Pin GPIO_PIN_6
#define S3_BTN_GPIO_Port GPIOE
#define S3_BTN_EXTI_IRQn EXTI6_IRQn
#define S4_BTN_Pin GPIO_PIN_13
#define S4_BTN_GPIO_Port GPIOC
#define S4_BTN_EXTI_IRQn EXTI13_IRQn
#define STOP_WAKE_Pin GPIO_PIN_1
#define STOP_WAKE_GPIO_Port GPIOA
#define DEEP_WAKE_Pin GPIO_PIN_2
#define DEEP_WAKE_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_4
#define LCD_DC_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_5
#define LCD_RST_GPIO_Port GPIOC
#define SX_NRST_Pin GPIO_PIN_1
#define SX_NRST_GPIO_Port GPIOB
#define SX_BUSY_Pin GPIO_PIN_2
#define SX_BUSY_GPIO_Port GPIOB
#define ANT_SW_Pin GPIO_PIN_7
#define ANT_SW_GPIO_Port GPIOE
#define DIO1_Pin GPIO_PIN_8
#define DIO1_GPIO_Port GPIOE
#define DIO1_EXTI_IRQn EXTI8_IRQn
#define DIO2_Pin GPIO_PIN_9
#define DIO2_GPIO_Port GPIOE
#define DIO3_Pin GPIO_PIN_10
#define DIO3_GPIO_Port GPIOE
#define HAPTIC_CTRL_Pin GPIO_PIN_11
#define HAPTIC_CTRL_GPIO_Port GPIOE
#define IO1_Pin GPIO_PIN_13
#define IO1_GPIO_Port GPIOE
#define IO2_Pin GPIO_PIN_14
#define IO2_GPIO_Port GPIOE
#define IO3_Pin GPIO_PIN_15
#define IO3_GPIO_Port GPIOE
#define IO4_Pin GPIO_PIN_10
#define IO4_GPIO_Port GPIOB
#define IO5_Pin GPIO_PIN_12
#define IO5_GPIO_Port GPIOB
#define S8_BTN_Pin GPIO_PIN_15
#define S8_BTN_GPIO_Port GPIOB
#define S8_BTN_EXTI_IRQn EXTI15_IRQn
#define S7_BTN_Pin GPIO_PIN_9
#define S7_BTN_GPIO_Port GPIOD
#define S7_BTN_EXTI_IRQn EXTI9_IRQn
#define S6_BTN_Pin GPIO_PIN_10
#define S6_BTN_GPIO_Port GPIOD
#define S6_BTN_EXTI_IRQn EXTI10_IRQn
#define S5_BTN_Pin GPIO_PIN_11
#define S5_BTN_GPIO_Port GPIOD
#define S5_BTN_EXTI_IRQn EXTI11_IRQn
#define BMI_INT2_Pin GPIO_PIN_15
#define BMI_INT2_GPIO_Port GPIOD
#define BMI_INT1_Pin GPIO_PIN_6
#define BMI_INT1_GPIO_Port GPIOC
#define BMI_ADR_Pin GPIO_PIN_7
#define BMI_ADR_GPIO_Port GPIOC
#define BME_ADR_Pin GPIO_PIN_8
#define BME_ADR_GPIO_Port GPIOC
#define CHG_Pin GPIO_PIN_10
#define CHG_GPIO_Port GPIOA
#define SX_CS_Pin GPIO_PIN_15
#define SX_CS_GPIO_Port GPIOA
#define C6_POKE_Pin GPIO_PIN_2
#define C6_POKE_GPIO_Port GPIOD
#define C6_PULL_Pin GPIO_PIN_3
#define C6_PULL_GPIO_Port GPIOD
#define BLINK_Pin GPIO_PIN_4
#define BLINK_GPIO_Port GPIOD
#define XSHUT_Pin GPIO_PIN_5
#define XSHUT_GPIO_Port GPIOD
#define VL_INT_Pin GPIO_PIN_6
#define VL_INT_GPIO_Port GPIOD
#define LASER_EN_Pin GPIO_PIN_7
#define LASER_EN_GPIO_Port GPIOD
#define C6_EN_Pin GPIO_PIN_5
#define C6_EN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
