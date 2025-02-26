/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32u0xx_it.c
 * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32u0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "sx126x.h"
#include "sx126x_hal.h"
#include <string.h>

#include "dualcast_rx_functions.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t rx_buffer[CYPHERTEXT_LENGTH + 16]; // 64 cyphertext + 16 IV

extern uint8_t command_received;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
void NMI_Handler(void)
{
	/* USER CODE BEGIN NonMaskableInt_IRQn 0 */

	/* USER CODE END NonMaskableInt_IRQn 0 */
	/* USER CODE BEGIN NonMaskableInt_IRQn 1 */
	while (1)
	{
	}
	/* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
 * @brief This function handles Hard fault interrupt.
 */
void HardFault_Handler(void)
{
	/* USER CODE BEGIN HardFault_IRQn 0 */

	/* USER CODE END HardFault_IRQn 0 */
	while (1)
	{
		/* USER CODE BEGIN W1_HardFault_IRQn 0 */
		/* USER CODE END W1_HardFault_IRQn 0 */
	}
}

/**
 * @brief This function handles System service call via SVC instruction.
 */
void SVC_Handler(void)
{
	/* USER CODE BEGIN SVCall_IRQn 0 */

	/* USER CODE END SVCall_IRQn 0 */
	/* USER CODE BEGIN SVCall_IRQn 1 */

	/* USER CODE END SVCall_IRQn 1 */
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void)
{
	/* USER CODE BEGIN PendSV_IRQn 0 */

	/* USER CODE END PendSV_IRQn 0 */
	/* USER CODE BEGIN PendSV_IRQn 1 */

	/* USER CODE END PendSV_IRQn 1 */
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
	/* USER CODE BEGIN SysTick_IRQn 0 */

	/* USER CODE END SysTick_IRQn 0 */
	HAL_IncTick();
	/* USER CODE BEGIN SysTick_IRQn 1 */

	/* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32U0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32u0xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles EXTI line 4 to 15 interrupts.
 */
void EXTI4_15_IRQHandler(void)
{
	/* USER CODE BEGIN EXTI4_15_IRQn 0 */
	sx126x_rx_buffer_status_t rx_status;
	sx126x_pkt_status_lora_t pkt_status;

	// Get RX buffer status
	if (sx126x_get_rx_buffer_status(NULL, &rx_status) != SX126X_STATUS_OK)
	{
		printf("Failed to get RX buffer status\n");

		// Re-init RX to try again
		memset(rx_buffer, 0, sizeof(rx_buffer)); // Clear buffer
		sx126x_clear_irq_status(NULL, SX126X_IRQ_RX_DONE); // Clear IRQ
		sx126x_cfg_rx_boosted(NULL, true); // Increase sensitivity
		sx126x_set_rx(NULL, SX126X_RX_SINGLE_MODE);
	}
	else if (rx_status.pld_len_in_bytes != CYPHERTEXT_LENGTH + 16)
	{
		printf("Payload size exceeds buffer size\n");

		// Re-init RX to try again
		memset(rx_buffer, 0, sizeof(rx_buffer)); // Clear buffer
		sx126x_clear_irq_status(NULL, SX126X_IRQ_RX_DONE); // Clear IRQ
		sx126x_cfg_rx_boosted(NULL, true); // Increase sensitivity
		sx126x_set_rx(NULL, SX126X_RX_SINGLE_MODE);
	}
	else if (sx126x_read_buffer(NULL, rx_status.buffer_start_pointer, rx_buffer, rx_status.pld_len_in_bytes) != SX126X_STATUS_OK)
	{
		printf("Failed to read RX buffer\n");

		// Re-init RX to try again
		memset(rx_buffer, 0, sizeof(rx_buffer)); // Clear buffer
		sx126x_clear_irq_status(NULL, SX126X_IRQ_RX_DONE); // Clear IRQ
		sx126x_cfg_rx_boosted(NULL, true); // Increase sensitivity
		sx126x_set_rx(NULL, SX126X_RX_SINGLE_MODE);
	}
	else
	{
		// Process received data
		process_received_message(rx_buffer, rx_status.pld_len_in_bytes); // Decrypt and extract the text

		if (sx126x_get_lora_pkt_status(NULL, &pkt_status) == SX126X_STATUS_OK)
		{
			//printf("RSSI: %i dBm, SNR: %i dB\n", pkt_status.rssi_pkt_in_dbm, pkt_status.snr_pkt_in_db);
		}

		memset(rx_buffer, 0, sizeof(rx_buffer)); // Clear buffer
		sx126x_clear_irq_status(NULL, SX126X_IRQ_RX_DONE); // Clear IRQ

		if (command_received == 0) // Invalid / wrong key
		{
			// Re-init RX to try again
			sx126x_cfg_rx_boosted(NULL, true); // Increase sensitivity
			sx126x_set_rx(NULL, SX126X_RX_SINGLE_MODE);
		}

	}

	/* USER CODE END EXTI4_15_IRQn 0 */
	HAL_GPIO_EXTI_IRQHandler(DIO1_Pin);
	/* USER CODE BEGIN EXTI4_15_IRQn 1 */

	/* USER CODE END EXTI4_15_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
