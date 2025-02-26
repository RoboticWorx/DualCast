#include "esp_wifi.h"
#include "esp_log.h"
#include <string.h>
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"

#include "wifi_functions.h"
#include "uart_functions.h"

#define DEFAULT_SCAN_LIST_SIZE 20
#define MAX_BUFF 1024
#define C6_POKE_GPIO GPIO_NUM_21
#define C6_PULL_GPIO GPIO_NUM_22

static const char *TAG = "DualCast_Main";
volatile unsigned int target_type = 1;

uint8_t global_target_bssid[18];
uint64_t last_uart_time;
uint64_t data_frames_count = 0;
uint64_t beacon_frames_count = 0;
char combined_macs_buffer[2048];

extern size_t unique_mac_count;

typedef struct {
	char bssid[6]; // To store the BSSID
	int channel;    // To store the channel
} wifi_target_t;

// Specify the target BSSID (network MAC address)

SemaphoreHandle_t target_ready_semaphore;

QueueHandle_t wifi_target_queue;

TaskHandle_t uartTaskHandle = NULL;
TaskHandle_t promiscuousTaskHandle = NULL;

void UartTask(void *param)
{

	init_uart();

	wifi_ap_record_t ap_info[MAX_SCAN_LIST_SIZE];
	uint16_t ap_count = 0;

	/*gpio_set_level(C6_POKE_GPIO, 1); // Notify the STM32 that the ESP32 is ready
	while (gpio_get_level(C6_PULL_GPIO) == 0) // Wait for STM32 to be ready
	{
		vTaskDelay(pdMS_TO_TICKS(10));
	}*/

	// Buffer for receiving STM32 response
	uint8_t rx_buffer[BUF_SIZE];

	while (1)
	{
		int len = uart_read_bytes(UART_NUM, rx_buffer, BUF_SIZE, pdMS_TO_TICKS(100)); // Read UART bytes

		if (len > 0) // If valid UART receive
		{
			rx_buffer[len] = '\0'; // Null-terminate for printing
			//ESP_LOGI(TAG, "UART Received: %s", (char *)rx_buffer);

			// Compare the received string
			if (strcmp((char *)rx_buffer, "scan_for_networks") == 0) // If scan_for_networks command
			{
				ESP_LOGI(TAG, "Command scan_for_networks executing");
				activate_wifi();
				scan_for_networks(ap_info, MAX_SCAN_LIST_SIZE, &ap_count);
				deactivate_wifi();
				send_ap_info_over_uart(ap_info, ap_count);
			}
			else if (strstr((char *)rx_buffer, "network_selected") == (char *)rx_buffer) // If contains "network_selected" is network_selected command
			{
				ESP_LOGI(TAG, "Command network_selected executing");

				char target_bssid_str[18]; // Store requested BSSID to analyze
				int target_channel; // Store requested channel to analyze

				// Parse the BSSID and channel from the received message
				int result = sscanf((char *)rx_buffer, "network_selected BSSID: %17s Channel: %d", target_bssid_str, &target_channel); // Separate values from string

				if (result == 2) // If successfully parsed both fields
				{
					ESP_LOGI(TAG, "Parsed Data:");
					ESP_LOGI(TAG, "BSSID: %s", target_bssid_str);
					ESP_LOGI(TAG, "Channel: %d", target_channel);

					// Convert BSSID string to uint8_t array
					wifi_target_t target_network;
					sscanf(target_bssid_str, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
							&target_network.bssid[0], &target_network.bssid[1], &target_network.bssid[2],
							&target_network.bssid[3], &target_network.bssid[4], &target_network.bssid[5]);
					target_network.channel = target_channel;

					xSemaphoreGive(target_ready_semaphore); // Enable PromiscuousTask
					if (xQueueSend(wifi_target_queue, &target_network, portMAX_DELAY) != pdPASS) // Send target BSSID and channel
					{
						ESP_LOGE(TAG, "Failed to send to queue");
					}
				}
				else
				{
					ESP_LOGW(TAG, "Failed to parse BSSID and Channel from command: %s", (char *)rx_buffer);
				}
			}
			else if (strcmp((char *)rx_buffer, "type_beacon") == 0) // If beacon frames requested
			{
				//ESP_LOGI(TAG, "Command type_beacon executing");
				target_type = 1;
			}
			else if (strcmp((char *)rx_buffer, "type_data") == 0) // If data frames requested
			{
				//ESP_LOGI(TAG, "Command type_data executing");
				target_type = 2;
			}
			else
			{
				ESP_LOGW(TAG, "Unknown command received: %s", (char *)rx_buffer);
			}
		}
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}

void PromiscuousTask(void *param)
{
	wifi_target_t target_network;

	if (xSemaphoreTake(target_ready_semaphore, portMAX_DELAY) == pdTRUE)
	{
		if (xQueueReceive(wifi_target_queue, &target_network, portMAX_DELAY) == pdPASS)
		{
			ESP_LOGI("RECEIVE_TASK", "Received Network Info:");
			ESP_LOGI("RECEIVE_TASK", "BSSID: %02x:%02x:%02x:%02x:%02x:%02x",
					target_network.bssid[0], target_network.bssid[1], target_network.bssid[2],
					target_network.bssid[3], target_network.bssid[4], target_network.bssid[5]);
			ESP_LOGI("RECEIVE_TASK", "Channel: %d", target_network.channel);

			// Store the target BSSID globally for filtering
			memcpy(global_target_bssid, target_network.bssid, 6);

			// Activate promiscuous mode which calls wifi_promiscuous_handler on each packet received
			activate_wifi_promiscuous(target_network.channel, (const uint8_t *)target_network.bssid);

			while (1)
			{
				vTaskDelay(pdMS_TO_TICKS(1000)); // Delay to avoid busy looping
			}
		}
	}
}

void wifi_promiscuous_handler(void *buf, wifi_promiscuous_pkt_type_t type)
{
	const wifi_promiscuous_pkt_t *packet = (wifi_promiscuous_pkt_t *)buf;
	const uint8_t *payload = packet->payload;

	int frame_length = packet->rx_ctrl.sig_len; // Total length of the frame
	int rssi = packet->rx_ctrl.rssi; // RSSI of the frame
	const uint8_t *bssid = &payload[16]; // BSSID starts here

	char uart_buffer[512]; // UART sending buffer

	const uint8_t *src_mac = &payload[10]; // Source MAC address starts here
	const uint8_t *dst_mac = &payload[4]; // Destination MAC address starts here

	uint16_t frame_ctrl = payload[0] | (payload[1] << 8);
	uint8_t frame_type = (frame_ctrl & 0x0C) >> 2; // Extract frame type
	uint8_t frame_subtype = (frame_ctrl & 0xF0) >> 4; // Extract frame subtype

	// Filter packets by BSSID
	if (memcmp(bssid, global_target_bssid, 6) == 0) // If requested BSSID
	{
		if (target_type == 1 && frame_type == 0 && frame_subtype == 8) // Beacon Frames
		{
			if (frame_length >= 38)
			{
				beacon_frames_count++;

				int ssid_len = payload[37];
				char rate_buffer[256]; // Buffer to hold supported rates string

				parse_supported_rates(payload, frame_length, rate_buffer, sizeof(rate_buffer)); // Get rates

				//ESP_LOGI(TAG, "Beacon Frame Detected - SSID: %.*s RSSI: %d Frame Length: %d Rates: %s",
				//ssid_len, &payload[38], rssi, frame_length, rate_buffer);

				// Format into string
				snprintf(uart_buffer, sizeof(uart_buffer),
						"(%llu) SSID: %.*s, RSSI: %d, Frame Length: %d, Rates: %s\n",
						beacon_frames_count, ssid_len, &payload[38], rssi, frame_length, rate_buffer);

				ESP_LOGI(TAG, "Transmitting: %s", uart_buffer);
				uart_write_bytes(UART_NUM, uart_buffer, strlen(uart_buffer)); // Send the beacon info to the STM32
			}
			else
			{
				ESP_LOGW(TAG, "Beacon frame too short: %d bytes", frame_length);
			}
		}
		else if (target_type == 2 && frame_type == 2) // Data Frames
		{
			if (frame_length >= 24) // 24 is total number of bytes in a complete data frame packet
			{
				data_frames_count++; // Number of Data Frames received

				if (is_mac_address_unique(src_mac))
				{
					add_mac_address(src_mac);
					ESP_LOGI(TAG, "New unique MAC detected: %02x:%02x:%02x:%02x:%02x:%02x, Count: %d",
							src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5], unique_mac_count);
				}

				format_unique_macs(combined_macs_buffer, sizeof(combined_macs_buffer)); // Combine unique MAC addresses of devices on network

				ESP_LOGI(TAG,
						"(%llu) SrcMAC: %02x:%02x:%02x:%02x:%02x:%02x, DstMAC: %02x:%02x:%02x:%02x:%02x:%02x, RSSI: %d, Frame Length: %d, UnqMacCnt: %d, UnqMacs: %.265s\n",
						data_frames_count,
						src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5],
						dst_mac[0], dst_mac[1], dst_mac[2], dst_mac[3], dst_mac[4], dst_mac[5],
						rssi, frame_length, unique_mac_count, combined_macs_buffer);


				snprintf(uart_buffer, sizeof(uart_buffer), // %.265s truncate at 265 characters (14 MACs)
						"(%llu) SrcMAC: %02x:%02x:%02x:%02x:%02x:%02x, DstMAC: %02x:%02x:%02x:%02x:%02x:%02x, RSSI: %d, Frame Length: %d, UnqMacCnt: %d, UnqMacs: %.265s\n",
						data_frames_count,
						src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5],
						dst_mac[0], dst_mac[1], dst_mac[2], dst_mac[3], dst_mac[4], dst_mac[5],
						rssi, frame_length, unique_mac_count, combined_macs_buffer);
				uart_write_bytes(UART_NUM, uart_buffer, strlen(uart_buffer));
			}
		}
		else
		{
			ESP_LOGW(TAG, "Data frame too short: %d bytes", frame_length);
		}
	}
}


void app_main(void)
{
	/*
	// Configure output GPIO
	gpio_config_t io_conf_out = {
	    .pin_bit_mask = (1ULL << C6_POKE_GPIO),
	    .mode = GPIO_MODE_OUTPUT,               // Set as output
	    .pull_up_en = GPIO_PULLUP_DISABLE,      // Disable pull-up
	    .pull_down_en = GPIO_PULLDOWN_DISABLE,  // Disable pull-down
	    .intr_type = GPIO_INTR_DISABLE          // No interrupt
	};
	gpio_config(&io_conf_out); // Apply configuration for output GPIO

	// Configure input GPIO
	gpio_config_t io_conf_in = {
	    .pin_bit_mask = (1ULL << C6_PULL_GPIO),
	    .mode = GPIO_MODE_INPUT,                // Set as input
	    .pull_up_en = GPIO_PULLUP_DISABLE,      // Disable pull-up
	    .pull_down_en = GPIO_PULLDOWN_ENABLE,   // Enable pull-down
	    .intr_type = GPIO_INTR_DISABLE          // No interrupt
	};
	gpio_config(&io_conf_in); // Apply configuration for input GPIO
	 */

	esp_err_t ret;

	// Initialize NVS for WiFi
	ESP_LOGI(TAG, "Initializing NVS...");
	ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_LOGW(TAG, "NVS needs erasing. Erasing...");
		ret = nvs_flash_erase();
		if (ret != ESP_OK)
		{
			ESP_LOGE(TAG, "Failed to erase NVS: %s", esp_err_to_name(ret));
			return;
		}
		ret = nvs_flash_init();
	}
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to initialize NVS: %s", esp_err_to_name(ret));
		return;
	}

	wifi_target_queue = xQueueCreate(10, sizeof(wifi_target_t));
	if (wifi_target_queue == NULL)
	{
		ESP_LOGE("MAIN", "Failed to create queue");
		return;
	}

	target_ready_semaphore = xSemaphoreCreateBinary();
	if (target_ready_semaphore == NULL)
	{
		ESP_LOGE("MAIN", "Failed to create semaphore");
		return;
	}

	xTaskCreate(UartTask, "UART_Task", 2048 * 4, NULL, 5, &uartTaskHandle);
	xTaskCreate(PromiscuousTask, "Promiscuous_Task", 2048 * 4, NULL, 5, &promiscuousTaskHandle);
}


/*
-30 dBm to -50 dBm	Excellent	Very strong signal; close to the router or access point (AP).
-51 dBm to -60 dBm	Good	Reliable signal; ideal for most tasks like streaming or gaming.
-61 dBm to -70 dBm	Fair	Moderate signal; sufficient for web browsing and basic tasks.
-71 dBm to -80 dBm	Weak	Unstable connection; may experience drops or slow speeds.
-81 dBm to -90 dBm	Very Weak	Unreliable connection; likely unusable for most applications.
Below -90 dBm	Dead Zone	No usable signal; connection will likely fail.
 */


