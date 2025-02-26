/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32h5xx_it.c
 * @brief   Interrupt Service Routines.
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
#include "stm32h5xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <ctype.h>
#include "cmsis_os2.h"
#include <stdio.h>
#include <stdint.h>
#include "sx126x.h"
#include "sx126x_hal.h"
#include "app_freertos.h"
#include <string.h>
#include "lvgl.h"
#include "dualcast_functions.h"
#include "dualcast_lvgl.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define UART_NUM_BYTES 1024

#define BTN_DEBOUNCE_TIME 250
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern UART_HandleTypeDef huart4;

extern osMessageQueueId_t wifi_scan_queue;
extern osMessageQueueId_t wifi_analyze_queue;
extern osMessageQueueId_t pass_wifi_data_queue;
extern osMessageQueueId_t pass_wifi_macs_queue;
extern osMessageQueueId_t pass_wifi_beacon_queue;
extern osMessageQueueId_t lora_rssi_snr_queue;

//extern int8_t pe6_pressed;

//bool first_packet = true;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void parse_uart_scan_message(const char *message);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef handle_GPDMA1_Channel7;
extern SPI_HandleTypeDef hspi1;
extern UART_HandleTypeDef huart4;
extern TIM_HandleTypeDef htim17;

/* USER CODE BEGIN EV */
volatile bool btn_1_pressed = false;
volatile bool btn_2_pressed = false;
volatile bool btn_3_pressed = false;
volatile bool btn_4_pressed = false;
volatile bool btn_5_pressed = false;
volatile bool btn_6_pressed = false;
volatile bool btn_7_pressed = false;
volatile bool btn_8_pressed = false;
volatile bool any_btn_pressed = false;
volatile bool lora_hap_btn_pressed = false;

extern volatile bool on_lidar_page;
extern volatile bool on_wifi_page;
extern volatile bool on_beacon_page;
extern volatile bool on_data_page;
extern volatile bool on_lora_page;
extern volatile bool on_scanning_page;
extern volatile bool on_docs_page;

volatile uint32_t last_btn1_press = 0;
volatile uint32_t last_btn2_press = 0;
volatile uint32_t last_btn3_press = 0;
volatile uint32_t last_btn4_press = 0;
volatile uint32_t last_btn5_press = 0;
volatile uint32_t last_btn6_press = 0;
volatile uint32_t last_btn7_press = 0;
volatile uint32_t last_btn8_press = 0;

Lora_Receipt_t lora_sigs;
UniqueData_t uniqueData;

uint8_t rx_buffer[CYPHERTEXT_LENGTH + 16]; // 64 cyphertext + 16 IV

static int find_mac(UniqueData_t *uniqueData, const char *mac)
{
	for (int i = 0; i < uniqueData->uniqCount; i++)
	{
		if (strcmp(uniqueData->uniqMacs[i], mac) == 0) {
			return i;
		}
	}
	return -1;
}

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
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32H5xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32h5xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI Line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn3_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_3_pressed = true;
		last_btn3_press = HAL_GetTick();
	}
  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S1_BTN_Pin);
  /* USER CODE BEGIN EXTI4_IRQn 1 */

  /* USER CODE END EXTI4_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line5 interrupt.
  */
void EXTI5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI5_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn5_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_5_pressed = true;
		last_btn5_press = HAL_GetTick();
	}
  /* USER CODE END EXTI5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S2_BTN_Pin);
  /* USER CODE BEGIN EXTI5_IRQn 1 */

  /* USER CODE END EXTI5_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line6 interrupt.
  */
void EXTI6_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI6_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn6_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_6_pressed = true;
		last_btn6_press = HAL_GetTick();
	}
  /* USER CODE END EXTI6_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S3_BTN_Pin);
  /* USER CODE BEGIN EXTI6_IRQn 1 */

  /* USER CODE END EXTI6_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line8 interrupt.
  */
void EXTI8_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI8_IRQn 0 */
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

		lora_sigs.lora_rssi = pkt_status.rssi_pkt_in_dbm;
		lora_sigs.lora_snr = pkt_status.snr_pkt_in_db;

		osStatus_t status = osMessageQueuePut(lora_rssi_snr_queue, &lora_sigs, 0, 0);
		if (status != osOK)
		{
			printf("Failed to send lora_rssi_snr_queue\n");
		}

		// Clear RX
		memset(rx_buffer, 0, sizeof(rx_buffer)); // Clear buffer
		sx126x_clear_irq_status(NULL, SX126X_IRQ_RX_DONE); // Clear IRQ
	}



  /* USER CODE END EXTI8_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(DIO1_Pin);
  /* USER CODE BEGIN EXTI8_IRQn 1 */

  /* USER CODE END EXTI8_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line9 interrupt.
  */
void EXTI9_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn2_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;

		btn_2_pressed = true;
		last_btn2_press = HAL_GetTick();
	}
  /* USER CODE END EXTI9_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S7_BTN_Pin);
  /* USER CODE BEGIN EXTI9_IRQn 1 */

  /* USER CODE END EXTI9_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line10 interrupt.
  */
void EXTI10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI10_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn1_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;

		btn_1_pressed = true;
		last_btn1_press = HAL_GetTick();
	}
  /* USER CODE END EXTI10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S6_BTN_Pin);
  /* USER CODE BEGIN EXTI10_IRQn 1 */

  /* USER CODE END EXTI10_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line11 interrupt.
  */
void EXTI11_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI11_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn8_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_8_pressed = true;
		last_btn8_press = HAL_GetTick();
	}
  /* USER CODE END EXTI11_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S5_BTN_Pin);
  /* USER CODE BEGIN EXTI11_IRQn 1 */

  /* USER CODE END EXTI11_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line13 interrupt.
  */
void EXTI13_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI13_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn7_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_7_pressed = true;
		last_btn7_press = HAL_GetTick();
	}
  /* USER CODE END EXTI13_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S4_BTN_Pin);
  /* USER CODE BEGIN EXTI13_IRQn 1 */

  /* USER CODE END EXTI13_IRQn 1 */
}

/**
  * @brief This function handles EXTI Line15 interrupt.
  */
void EXTI15_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_IRQn 0 */

	// Ensure click only registers once every BTN_DEBOUNCE_TIME
	if(HAL_GetTick() - last_btn4_press > BTN_DEBOUNCE_TIME)
	{
		any_btn_pressed = true;
		lora_hap_btn_pressed = true;

		btn_4_pressed = true;
		last_btn4_press = HAL_GetTick();
	}
  /* USER CODE END EXTI15_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(S8_BTN_Pin);
  /* USER CODE BEGIN EXTI15_IRQn 1 */

  /* USER CODE END EXTI15_IRQn 1 */
}

/**
  * @brief This function handles GPDMA1 Channel 7 global interrupt.
  */
void GPDMA1_Channel7_IRQHandler(void)
{
  /* USER CODE BEGIN GPDMA1_Channel7_IRQn 0 */

  /* USER CODE END GPDMA1_Channel7_IRQn 0 */
  HAL_DMA_IRQHandler(&handle_GPDMA1_Channel7);
  /* USER CODE BEGIN GPDMA1_Channel7_IRQn 1 */

  /* USER CODE END GPDMA1_Channel7_IRQn 1 */
}

/**
  * @brief This function handles SPI1 global interrupt.
  */
void SPI1_IRQHandler(void)
{
  /* USER CODE BEGIN SPI1_IRQn 0 */

  /* USER CODE END SPI1_IRQn 0 */
  HAL_SPI_IRQHandler(&hspi1);
  /* USER CODE BEGIN SPI1_IRQn 1 */

  /* USER CODE END SPI1_IRQn 1 */
}

/**
  * @brief This function handles UART4 global interrupt.
  */
void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */

	static uint8_t uart_rx_buff[(UART_NUM_BYTES) + 1]; // Buffer to store received bytes
	static volatile int uart_index = 0;

	if (__HAL_UART_GET_FLAG(&huart4, UART_FLAG_RXNE))
	{
		// Read the received byte
		uint8_t received_byte = (uint8_t)(huart4.Instance->RDR & 0xFF);

		if (received_byte == '\n') // End of message
		{
			uart_rx_buff[uart_index] = '\0'; // Null-terminate the string
			//printf("%s \n", uart_rx_buff); // Print the full string

			// Call the parsing function
			parse_uart_scan_message((char *)uart_rx_buff);

			uart_index = 0; // Reset uart_index for the next message
		}
		else if (uart_index < UART_NUM_BYTES)
		{
			uart_rx_buff[uart_index++] = received_byte; // Store the byte
		}
		else
		{
			// Buffer overflow, reset uart_index
			printf("UART buffer overflow\n");
			uart_index = 0;
		}
	}
	//printf("byte 12: %u", uart_rx_buff[12]);
  /* USER CODE END UART4_IRQn 0 */
  HAL_UART_IRQHandler(&huart4);
  /* USER CODE BEGIN UART4_IRQn 1 */

  /* USER CODE END UART4_IRQn 1 */
}

/**
  * @brief This function handles TIM17 global interrupt.
  */
void TIM17_IRQHandler(void)
{
  /* USER CODE BEGIN TIM17_IRQn 0 */
	lv_tick_inc(1);
  /* USER CODE END TIM17_IRQn 0 */
  HAL_TIM_IRQHandler(&htim17);
  /* USER CODE BEGIN TIM17_IRQn 1 */

  /* USER CODE END TIM17_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void parse_uart_scan_message(const char *message)
{
	if (on_data_page)
	{
		char extracted[200] = {0};

		// This will read everything until the first 'U'
		int n = sscanf(message, "%127[^U]", extracted);
		if (n == 1)
		{
			// Send everything for log
			osStatus_t status = osMessageQueuePut(pass_wifi_data_queue, extracted, 0, 0);
			if (status != osOK)
			{
				printf("Failed to send data to pass_wifi_data_queue\n");
			}
		}

		int uniqCount;
		int currentRssi; // The RSSI value from the current transmission
		char uniqMacsStr[512] = {0}; // This string holds the comma-separated MAC addresses
		const char *p = strstr(message, "RSSI:");
		if (p != NULL)
		{
			if (sscanf(p, "RSSI: %d, %*[^U]UnqMacCnt: %d, UnqMacs: %264[^\n]",
					&currentRssi, &uniqCount, uniqMacsStr) == 3)
			{
				uniqueData.uniqCount = uniqCount; // Update count

				if (uniqueData.uniqCount <= MAX_MACS) // Stop appending after MAX_MACS
				{
					char macListCopy[512];
					strncpy(macListCopy, uniqMacsStr, sizeof(uniqMacsStr) - 1);

					// Seperate into seperate MACs
					char *token = strtok(macListCopy, ",");
					while (token != NULL)
					{
						// Remove any leading whitespace from the token.
						while (*token && isspace((unsigned char)*token))
						{
							token++;
						}

						// Check if this MAC is already stored
						int index = find_mac(&uniqueData, token);
						if (index == -1)
						{
							// Not found: add the new MAC and its current RSSI at the next available index.
							strncpy(uniqueData.uniqMacs[uniqueData.uniqCount - 1], token, MAC_STR_SIZE - 1);
							uniqueData.uniqMacs[uniqueData.uniqCount - 1][MAC_STR_SIZE - 1] = '\0';
							uniqueData.uniqRssi[uniqueData.uniqCount - 1] = currentRssi;
						}

						// Get the next token
						token = strtok(NULL, ",");
					}
				}

				// Update MAC RSSI
				char srcMac[MAC_STR_SIZE] = {0};
				const char *srcPos = strstr(message, "SrcMAC:");
				if (srcPos != NULL)
				{
					if (sscanf(srcPos, "SrcMAC: %17[^,]", srcMac) == 1)
					{
						int rssi_ind = find_mac(&uniqueData, srcMac);
						if (rssi_ind != -1)
						{
							uniqueData.uniqRssi[rssi_ind] = currentRssi;
						}
						else
						{
							printf("SrcMAC not found in uniqueData\n");
						}
					}
				}


				// Print the entire array
				/*printf("Unique MAC addresses (%d):\n", uniqueData.uniqCount);
				for (int i = 0; i < uniqueData.uniqCount; i++) {
					printf("Index %d: %s, RSSI: %d\n", i, uniqueData.uniqMacs[i], uniqueData.uniqRssi[i]);
				}*/

				// Send data to LVGL task
				osStatus_t status = osMessageQueuePut(pass_wifi_macs_queue, &uniqueData, 0, 0);
				if (status != osOK)
				{
					//printf("Failed to send pass_wifi_macs_queue\n");
				}
			}
			else
			{
				printf("Failed to parse UnqMacCnt and UnqMacs from the message.\n");
			}
		}
	}
	else if (on_beacon_page)
	{
		// Increase the buffer size if needed:
		char beacon_info[400] = {0}; // Larger buffer to hold the entire message

		// Copy the entire message into beacon_info
		size_t len = strlen(message);
		if (len >= sizeof(beacon_info))
			len = sizeof(beacon_info) - 1;
		strncpy(beacon_info, message, len);
		beacon_info[len] = '\0';  // ensure null termination

		// Send the full message
		osStatus_t status = osMessageQueuePut(pass_wifi_beacon_queue, beacon_info, 0, 0);
		if (status != osOK) {
			printf("Failed to send pass_wifi_beacon_queue\n");
		}
	}
	else
	{
		int ap_count, rssi, channel, auth_mode;
		char ssid[64];
		char bssid[18];

		// Persistent analyze data
		static wifi_analyze_data_t analyze_data = {0};
		static int analyze_index = 0;

		// Attempt to parse the received message
		int result = sscanf(message,
				"ap_count: %d, SSID: %63[^,], BSSID: %17s, RSSI: %d, Channel: %d, Auth Mode: %d",
				&ap_count, ssid, bssid, &rssi, &channel, &auth_mode);

		if (result == 6) // Successfully parsed all fields
		{
			wifi_ap_data_t ap_data;

			// Populate the `ap_data` structure
			ap_data.ap_count = ap_count;
			strncpy(ap_data.ssid, ssid, sizeof(ap_data.ssid) - 1);
			ap_data.ssid[sizeof(ap_data.ssid) - 1] = '\0'; // Ensure null termination
			strncpy(ap_data.bssid, bssid, sizeof(ap_data.bssid) - 1);
			ap_data.bssid[sizeof(ap_data.bssid) - 1] = '\0'; // Ensure null termination
			ap_data.rssi = rssi;
			ap_data.channel = channel;
			ap_data.auth_mode = auth_mode;

			// Send full data to the scan queue
			osStatus_t status = osMessageQueuePut(wifi_scan_queue, &ap_data, 0, 0);
			if (status != osOK)
			{
				printf("Failed to send data to wifi_scan_queue\n");
			}

			// Store only BSSID and channel for analysis
			if (analyze_index < 20) // Ensure we don't exceed the array limit
			{
				strncpy(analyze_data.bssid[analyze_index], ap_data.bssid, sizeof(analyze_data.bssid[analyze_index]) - 1);
				analyze_data.bssid[analyze_index][sizeof(analyze_data.bssid[analyze_index]) - 1] = '\0'; // Null-terminate
				analyze_data.channel[analyze_index] = ap_data.channel;
				analyze_index++;
			}
			else
			{
				printf("Analyze data storage full, cannot add more networks.\n");
			}

			// Send analyze data to the analyze queue after all networks are parsed
			if (analyze_index >= ap_count)
			{
				osStatus_t status = osMessageQueuePut(wifi_analyze_queue, &analyze_data, 0, 0);
				if (status != osOK)
				{
					printf("Failed to send data to wifi_analyze_queue\n");
				}

				// Reset index for next batch
				analyze_index = 0;
				memset(&analyze_data, 0, sizeof(analyze_data)); // Clear the structure
			}
		}
		else
		{
			// Parsing failed
			//printf("Failed to parse message: %s\n", message);
		}
	}
}

/* USER CODE END 1 */
