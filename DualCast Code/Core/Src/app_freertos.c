/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : app_freertos.c
 * Description        : FreeRTOS applicative file
 ******************************************************************************
 * @attention
 *
 * Code provided by roboticworx.io
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * of the corresponding GitHub page.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#include "main.h"

#include "st7789.h"
#include "lvgl.h"

#include "sx126x.h"
#include "sx126x_hal.h"

#include "bmi323.h"
#include "bme280.h"
#include "common.h"
#include "common_bme.h"
#include "vl53lx_api.h"

#include "dualcast_lvgl.h"
#include "dualcast_functions.h"

#include "aes.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define QUEUE_LENGTH 1 // Number of items the queue can hold. 1 ensures synchronization
#define ITEM_SIZE sizeof(wifi_ap_data_t) // Size of each item in the queue

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
osMessageQueueId_t wifi_scan_queue;
osMessageQueueId_t wifi_analyze_queue;

osMessageQueueId_t pass_wifi_data_queue;
osMessageQueueId_t pass_wifi_macs_queue;
osMessageQueueId_t pass_wifi_beacon_queue;

osMessageQueueId_t bme_wifi_queue;
osMessageQueueId_t bme_lora_queue;

osMessageQueueId_t lora_hex_queue_tx;
osMessageQueueId_t lora_hex_queue_rx;
osMessageQueueId_t lora_decrypted_queue_rx;

osMessageQueueId_t lora_rssi_snr_queue;

osMessageQueueId_t rotation_queue;

osMessageQueueId_t lidar_queue;
osMessageQueueId_t lidar_queue_d;

osMessageQueueId_t adc_queue;

osSemaphoreId_t lidarEnableSemaphore;
osSemaphoreId_t bmeDisableSemaphore;
osSemaphoreId_t bmiDisableSemaphore;
osSemaphoreId_t sxDisableSemaphore;

osMutexId_t i2c4MutexId;
const osMutexAttr_t i2c4Mutex_attributes = {
		.name = "i2c4Mutex"
};

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osThreadId_t LvglTaskHandle;

extern SPI_HandleTypeDef hspi1;
extern I2C_HandleTypeDef hi2c4;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart4;

VL53LX_Dev_t vl53l4cx_dev;
VL53LX_MultiRangingData_t ranging_data;

extern volatile bool btn_1_pressed;
extern volatile bool btn_2_pressed;
extern volatile bool btn_3_pressed;
extern volatile bool btn_4_pressed;
extern volatile bool btn_5_pressed;
extern volatile bool btn_6_pressed;
extern volatile bool btn_7_pressed;
extern volatile bool btn_8_pressed;
extern volatile bool any_btn_pressed;
extern volatile bool lora_hap_btn_pressed;

static uint8_t buf1[LCD_H_RES * LCD_V_RES / 10 * BYTES_PER_PIXEL];

volatile bool start_scan = false;
bool already_scanned = false;

volatile int8_t network_selected = 1;
volatile uint8_t target_type = 0;

volatile bool on_lidar_page = false;
volatile bool on_wifi_page = false;
volatile bool on_beacon_page = false;
volatile bool on_data_page = false;
volatile bool on_lora_page = false;
volatile bool on_scanning_page = false;
volatile bool on_docs_page = false;

volatile bool show_encryption_decryption_key = false;

volatile bool network_chosen = false;


uint8_t value_to_transmit = 0;


/* USER CODE END Variables */
/* Definitions for blinkTask */
osThreadId_t blinkTaskHandle;
const osThreadAttr_t blinkTask_attributes = {
  .name = "blinkTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 64 * 4
};
/* Definitions for lvglTask */
osThreadId_t lvglTaskHandle;
const osThreadAttr_t lvglTask_attributes = {
  .name = "lvglTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 1536 * 4
};
/* Definitions for loraTask */
osThreadId_t loraTaskHandle;
const osThreadAttr_t loraTask_attributes = {
  .name = "loraTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 1024 * 4
};
/* Definitions for accelTask */
osThreadId_t accelTaskHandle;
const osThreadAttr_t accelTask_attributes = {
  .name = "accelTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for atmoTask */
osThreadId_t atmoTaskHandle;
const osThreadAttr_t atmoTask_attributes = {
  .name = "atmoTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for lidarTask */
osThreadId_t lidarTaskHandle;
const osThreadAttr_t lidarTask_attributes = {
  .name = "lidarTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for uartTask */
osThreadId_t uartTaskHandle;
const osThreadAttr_t uartTask_attributes = {
  .name = "uartTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for adcTask */
osThreadId_t adcTaskHandle;
const osThreadAttr_t adcTask_attributes = {
  .name = "adcTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for hapticTask */
osThreadId_t hapticTaskHandle;
const osThreadAttr_t hapticTask_attributes = {
  .name = "hapticTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	wifi_scan_queue = osMessageQueueNew(QUEUE_LENGTH + 19, sizeof(wifi_ap_data_t), NULL);
	if (wifi_scan_queue == NULL)
	{
		printf("Failed to create wifi_scan_queue.\n");
	}
	wifi_analyze_queue = osMessageQueueNew(QUEUE_LENGTH + 19, sizeof(wifi_analyze_data_t), NULL);
	if (wifi_analyze_queue == NULL)
	{
		printf("Failed to create wifi_analyze_queue.\n");
	}
	pass_wifi_data_queue = osMessageQueueNew(QUEUE_LENGTH, 200, NULL);
	if (pass_wifi_data_queue == NULL)
	{
		printf("Failed to create pass_wifi_data_queue.\n");
	}
	pass_wifi_macs_queue = osMessageQueueNew(QUEUE_LENGTH, sizeof(UniqueData_t), NULL);
	if (pass_wifi_macs_queue == NULL)
	{
		printf("Failed to create pass_wifi_macs_queue.\n");
	}
	pass_wifi_beacon_queue = osMessageQueueNew(QUEUE_LENGTH, 400, NULL);
	if (pass_wifi_beacon_queue == NULL)
	{
		printf("Failed to create pass_wifi_beacon_queue.\n");
	}
	bme_wifi_queue = osMessageQueueNew(QUEUE_LENGTH, 64, NULL);
	if (bme_wifi_queue == NULL)
	{
		printf("Failed to create bme_wifi_queue.\n");
	}
	bme_lora_queue = osMessageQueueNew(QUEUE_LENGTH, 64, NULL);
	if (bme_lora_queue == NULL)
	{
		printf("Failed to create bme_lora_queue.\n");
	}
	lora_hex_queue_tx = osMessageQueueNew(QUEUE_LENGTH, 80, NULL);
	if (lora_hex_queue_tx == NULL)
	{
		printf("Failed to create lora_hex_queue_tx.\n");
	}
	lora_hex_queue_rx = osMessageQueueNew(QUEUE_LENGTH, CYPHERTEXT_LENGTH + 16, NULL);
	if (lora_hex_queue_rx == NULL)
	{
		printf("Failed to create lora_hex_queue_rx.\n");
	}
	lora_decrypted_queue_rx = osMessageQueueNew(QUEUE_LENGTH, CYPHERTEXT_LENGTH, NULL);
	if (lora_decrypted_queue_rx == NULL)
	{
		printf("Failed to create lora_decrypted_queue_rx.\n");
	}
	lora_rssi_snr_queue = osMessageQueueNew(QUEUE_LENGTH, sizeof(Lora_Receipt_t), NULL);
	if (lora_rssi_snr_queue == NULL)
	{
		printf("Failed to create lora_rssi_snr_queue.\n");
	}
	rotation_queue = osMessageQueueNew(QUEUE_LENGTH, 4, NULL);
	if (rotation_queue == NULL)
	{
		printf("Failed to create rotation_queue.\n");
	}
	lidar_queue = osMessageQueueNew(QUEUE_LENGTH, sizeof(VL53LX_MultiRangingData_t), NULL);
	if (lidar_queue == NULL)
	{
		printf("Failed to create lidar_queue.\n");
	}
	lidar_queue_d = osMessageQueueNew(QUEUE_LENGTH, 2, NULL);
	if (lidar_queue_d == NULL)
	{
		printf("Failed to create lidar_queue.\n");
	}
	adc_queue = osMessageQueueNew(QUEUE_LENGTH, 4, NULL);
	if (adc_queue == NULL)
	{
		printf("Failed to create adc_queue.\n");
	}


	i2c4MutexId = osMutexNew(&i2c4Mutex_attributes);
	if (i2c4MutexId == NULL)
	{
		printf("Failed to create i2c mutex.\n");
	}

	lidarEnableSemaphore = osSemaphoreNew(1, 0, NULL); // Up to 1, starts at 0 (default off)
	bmeDisableSemaphore = osSemaphoreNew(1, 0, NULL);
	bmiDisableSemaphore = osSemaphoreNew(1, 0, NULL);
	sxDisableSemaphore = osSemaphoreNew(1, 0, NULL);

	if (lidarEnableSemaphore == NULL)
	{
		printf("Failed to create lidar semaphores\n");
	}

  /* USER CODE END RTOS_QUEUES */
  /* creation of blinkTask */
  blinkTaskHandle = osThreadNew(BlinkTask, NULL, &blinkTask_attributes);

  /* creation of lvglTask */
  lvglTaskHandle = osThreadNew(LvglTask, NULL, &lvglTask_attributes);

  /* creation of loraTask */
  loraTaskHandle = osThreadNew(LoraTask, NULL, &loraTask_attributes);

  /* creation of accelTask */
  accelTaskHandle = osThreadNew(AccelTask, NULL, &accelTask_attributes);

  /* creation of atmoTask */
  atmoTaskHandle = osThreadNew(AtmoTask, NULL, &atmoTask_attributes);

  /* creation of lidarTask */
  lidarTaskHandle = osThreadNew(LidarTask, NULL, &lidarTask_attributes);

  /* creation of uartTask */
  uartTaskHandle = osThreadNew(UartTask, NULL, &uartTask_attributes);

  /* creation of adcTask */
  adcTaskHandle = osThreadNew(AdcTask, NULL, &adcTask_attributes);

  /* creation of hapticTask */
  hapticTaskHandle = osThreadNew(HapticTask, NULL, &hapticTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */

	if (lvglTaskHandle == NULL)
	{
		printf("LvglTask creation failed\n");
	}
	if (loraTaskHandle == NULL)
	{
		printf("LoraTask creation failed\n");
	}
	if (accelTaskHandle == NULL)
	{
		printf("AccelTask creation failed\n");
	}
	if (atmoTaskHandle == NULL)
	{
		printf("AtmoTask creation failed\n");
	}
	if (lidarTaskHandle == NULL)
	{
		printf("LidarTask creation failed\n");
	}
	if (uartTaskHandle == NULL)
	{
		printf("UartTask creation failed\n");
	}
	if (adcTaskHandle == NULL)
	{
		printf("AdcTask creation failed\n");
	}
	if (hapticTaskHandle == NULL)
	{
		printf("hapticTaskHandle creation failed\n");
	}
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_BlinkTask */
/**
 * @brief Function implementing the blinkTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_BlinkTask */
void BlinkTask(void *argument)
{
  /* USER CODE BEGIN blinkTask */

	/* Infinite loop */
	for(;;)
	{
		HAL_GPIO_TogglePin(BLINK_GPIO_Port, BLINK_Pin); // Toggle the LED
		//printf("Blinking\n");
		osDelay(250);
	}
  /* USER CODE END blinkTask */
}

/* USER CODE BEGIN Header_LvglTask */
/**
 * @brief Function implementing the lvglTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_LvglTask */
void LvglTask(void *argument)
{
  /* USER CODE BEGIN lvglTask */

	static bool lidar_page_once = true;
	static bool wifi_page_once = true;
	static bool beacon_page_once = true;
	static bool data_page_once = true;
	static bool lora_page_once = true;
	static bool scanning_page_once = true;
	static bool docs_page_once = true;

	ST7789_Init();

	osDelay(10); // Give LCD time to initialize

	lv_init();
	//lv_tick_set_cb(osKernelGetTickCount);

	lv_display_t * display1 = lv_display_create(LCD_H_RES, LCD_V_RES);
	lv_display_set_rotation(display1, LV_DISPLAY_ROTATION_0);
	lv_display_set_buffers(display1, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

	lv_display_set_flush_cb(display1, my_flush_cb);

	/* Create and configure the screen */
	lv_obj_t *scr = lv_screen_active(); // Get the active screen object
	lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), 0);
	lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0); // Set the background opacity to 100% (fully opaque)

	lv_obj_t * beacon_chart;
	lv_chart_series_t * beacon_ser;
	lv_obj_t * beacon_log_label;

	lv_obj_t * data_chart;
	lv_chart_series_t * data_ser_mac1;
	lv_chart_series_t * data_ser_mac2;
	lv_chart_series_t * data_ser_mac3;
	lv_chart_series_t * data_ser_mac4;
	lv_chart_series_t * data_ser_mac5;
	lv_chart_series_t * data_ser_mac6;
	lv_chart_series_t * data_ser_mac7;
	lv_chart_series_t * data_ser_mac8;
	lv_chart_series_t * data_ser_mac9;
	lv_chart_series_t * data_ser_mac10;
	lv_chart_series_t * data_ser_mac11;
	lv_chart_series_t * data_ser_mac12;
	lv_chart_series_t * data_ser_mac13;
	lv_chart_series_t * data_ser_mac14;

	lv_obj_t * data_log_label;

	wifi_ap_data_t ap_data;

	char received_data_message[128];
	char received_beacon_message[256];
	char received_bme_data[128];
	char received_lora_hex_data[CYPHERTEXT_LENGTH + 16];
	char received_lora_decrypted[CYPHERTEXT_LENGTH];

	int extracted_beacon_rssi = 0;

	float x_rotation = 0;
	int16_t lidar_d = 0;
	uint32_t received_adc_lora = 0;
	uint32_t received_adc_wifi = 0;

	UniqueData_t uniqueData;

	Lora_Receipt_t lora_sigs;

	VL53LX_MultiRangingData_t ranging_data_extract;

	//uint8_t buffer[LORA_NUM_BYTES];
	//char buffer[LORA_NUM_BYTES];

	//char buffer_rssi[16];
	//char buffer_snr[16];
	bool rotate_on_start = true;

	uint8_t lora_val1 = 1;
	uint8_t lora_val2 = 2;
	uint8_t lora_val3 = 3;
	uint8_t lora_val4 = 4;

	load_encryption_key_from_flash();

	memset(&uniqueData, 0, sizeof(uniqueData)); // Zero out the entire structure

	for(;;)
	{
		if (rotate_on_start)
		{
			if (osMessageQueueGet(rotation_queue, &x_rotation, NULL, 1000) == osOK)
			{
				if (x_rotation < -1)
				{
					lv_display_set_rotation(display1, LV_DISPLAY_ROTATION_180);

					on_wifi_page = true;
					rotate_on_start = false;
				}
				else
				{
					lv_display_set_rotation(display1, LV_DISPLAY_ROTATION_0);

					on_lora_page = true;
					rotate_on_start = false;
				}
			}
		}

		if (on_lidar_page) // If lidar page selected
		{
			if (lidar_page_once)
			{
				osSemaphoreRelease(lidarEnableSemaphore); // Enable LiDAR

				HAL_GPIO_WritePin(LASER_EN_GPIO_Port, LASER_EN_Pin, GPIO_PIN_SET); // Enable Laser

				osSemaphoreRelease(bmeDisableSemaphore); // Disable BME280
				osSemaphoreRelease(bmiDisableSemaphore); // Disable BMI323
				osSemaphoreRelease(sxDisableSemaphore); // Disable SX1262

				lv_obj_t * clear_rect = lv_obj_create(scr); // Clear screen without deleting child objects
				lv_obj_set_size(clear_rect, 240, 320);
				lv_obj_set_pos(clear_rect, 0, 0);
				lv_obj_set_style_bg_color(clear_rect, lv_color_black(), LV_PART_MAIN);
				lv_obj_set_style_border_width(clear_rect, 0, LV_PART_MAIN);
				lv_obj_set_style_bg_opa(clear_rect, LV_OPA_COVER, LV_PART_MAIN);

				lidar_page(scr);
				lidar_page_once = false;
			}

			if (osMessageQueueGet(lidar_queue, &ranging_data_extract, NULL, 10) == osOK)
			{
				update_lidar_text(&ranging_data_extract);
			}
			if (osMessageQueueGet(lidar_queue_d, &lidar_d, NULL, 10) == osOK)
			{
				update_lidar_d_text(lidar_d); // Distance text only
			}

		}
		else if (on_wifi_page) // If wifi page selected
		{
			if (wifi_page_once)
			{
				osSemaphoreRelease(sxDisableSemaphore); // Disable SX1262

				HAL_GPIO_WritePin(C6_EN_GPIO_Port, C6_EN_Pin, GPIO_PIN_SET); // Enable ESP32

				wifi_page(scr);
				wifi_page_once = false;

				if (osMessageQueueGet(bme_wifi_queue, received_bme_data, NULL, 100) == osOK)
				{
					show_bme_wifi(received_bme_data);
				}

				if (osMessageQueueGet(adc_queue, &received_adc_wifi, NULL, 150) == osOK)
				{
					update_adc_wifi(received_adc_wifi);
				}

			}


			if ((btn_5_pressed || btn_6_pressed || btn_7_pressed || btn_8_pressed) && !already_scanned)
			{
				start_scan = true;
				already_scanned = true;
			}

		}
		else if (on_beacon_page) // If beacon page selected
		{
			if (beacon_page_once)
			{
				osSemaphoreRelease(bmeDisableSemaphore); // Disable BME280
				osSemaphoreRelease(bmiDisableSemaphore); // Disable BMI323

				lv_obj_t * clear_rect = lv_obj_create(scr); // Clear screen without deleting child objects
				lv_obj_set_size(clear_rect, 240, 320);
				lv_obj_set_pos(clear_rect, 0, 0);
				lv_obj_set_style_bg_color(clear_rect, lv_color_black(), LV_PART_MAIN);
				lv_obj_set_style_border_width(clear_rect, 0, LV_PART_MAIN);
				lv_obj_set_style_bg_opa(clear_rect, LV_OPA_COVER, LV_PART_MAIN);


				beacon_chart = lv_chart_create(scr);
				beacon_ser = lv_chart_add_series(beacon_chart, lv_color_hex(0xff0000), LV_CHART_AXIS_PRIMARY_Y);
				beacon_log_label = lv_label_create(scr);

				create_beacon_chart(beacon_chart);
				beacon_page(scr);
				create_beacon_log(beacon_log_label);

				beacon_page_once = false;
			}

			if (osMessageQueueGet(pass_wifi_beacon_queue, received_beacon_message, NULL, 10) == osOK) // Receive scanned networks from UART interrupt
			{
				beacon_log_append(beacon_log_label, received_beacon_message);


				const char *p = strstr(received_beacon_message, "RSSI:");
				if(p != NULL)
				{
					if(sscanf(p, "RSSI: %d", &extracted_beacon_rssi) == 1)
					{
						//printf("Extracted RSSI: %d\n", extracted_beacon_rssi);
						add_beacon_chart_value(beacon_chart, beacon_ser, extracted_beacon_rssi);
					}
					else
					{
						printf("Failed to extract RSSI\n");
					}
				}
			}

			if (btn_1_pressed) // Toggle
			{
				on_data_page = true;
				on_beacon_page = false;

				data_page_once = true;

				target_type = 2; // 1 = Beacon Frames, 2 = Data Frames
				btn_1_pressed = false;
			}

		}
		else if (on_data_page) // If beacon page selected
		{
			if (data_page_once)
			{
				osSemaphoreRelease(bmeDisableSemaphore); // Disable BME280
				osSemaphoreRelease(bmiDisableSemaphore); // Disable BMI323

				lv_obj_t * clear_rect = lv_obj_create(scr); // Clear screen without deleting child objects
				lv_obj_set_size(clear_rect, 240, 320);
				lv_obj_set_pos(clear_rect, 0, 0);
				lv_obj_set_style_bg_color(clear_rect, lv_color_black(), LV_PART_MAIN);
				lv_obj_set_style_border_width(clear_rect, 0, LV_PART_MAIN);
				lv_obj_set_style_bg_opa(clear_rect, LV_OPA_COVER, LV_PART_MAIN);

				data_page(scr);
				data_chart = lv_chart_create(scr);
				create_data_chart(data_chart);

				data_ser_mac1  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_BLUE),         LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac2  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_GREEN),        LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac3  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_RED),          LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac4  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_PURPLE),       LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac5  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_YELLOW),       LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac6  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_ORANGE),       LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac7  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_CYAN),         LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac8  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_TEAL),         LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac9  = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_AMBER),        LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac10 = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_BROWN),        LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac11 = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_DEEP_PURPLE),  LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac12 = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_INDIGO),       LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac13 = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_LIGHT_BLUE),   LV_CHART_AXIS_PRIMARY_Y);
				data_ser_mac14 = lv_chart_add_series(data_chart, lv_palette_main(LV_PALETTE_LIGHT_GREEN),  LV_CHART_AXIS_PRIMARY_Y);

				data_log_label = lv_label_create(scr);
				create_data_log(data_log_label);

				data_page_once = false;
			}

			if (osMessageQueueGet(pass_wifi_data_queue, received_data_message, NULL, 10) == osOK) // Receive scanned networks from UART interrupt
			{
				data_log_append(data_log_label, received_data_message);
			}

			if (osMessageQueueGet(pass_wifi_macs_queue, &uniqueData, NULL, 10) == osOK) // Receive scanned networks from UART interrupt
			{
				update_unique_macs(scr, &uniqueData);
				add_data_chart_value(data_chart, data_ser_mac1, uniqueData.uniqRssi[0]);
				add_data_chart_value(data_chart, data_ser_mac2, uniqueData.uniqRssi[1]);
				add_data_chart_value(data_chart, data_ser_mac3, uniqueData.uniqRssi[2]);
				add_data_chart_value(data_chart, data_ser_mac4, uniqueData.uniqRssi[3]);
				add_data_chart_value(data_chart, data_ser_mac5, uniqueData.uniqRssi[4]);
				add_data_chart_value(data_chart, data_ser_mac6, uniqueData.uniqRssi[5]);
				add_data_chart_value(data_chart, data_ser_mac7, uniqueData.uniqRssi[6]);
				add_data_chart_value(data_chart, data_ser_mac8, uniqueData.uniqRssi[7]);
				add_data_chart_value(data_chart, data_ser_mac9, uniqueData.uniqRssi[8]);
				add_data_chart_value(data_chart, data_ser_mac10, uniqueData.uniqRssi[9]);
				add_data_chart_value(data_chart, data_ser_mac11, uniqueData.uniqRssi[10]);
				add_data_chart_value(data_chart, data_ser_mac12, uniqueData.uniqRssi[11]);
				add_data_chart_value(data_chart, data_ser_mac13, uniqueData.uniqRssi[12]);
				add_data_chart_value(data_chart, data_ser_mac14, uniqueData.uniqRssi[13]);
			}

			if (btn_1_pressed)
			{
				on_beacon_page = true;
				on_data_page = false;

				beacon_page_once = true;

				target_type = 1; // 1 = Beacon Frames, 2 = Data Frames
				btn_1_pressed = false;
			}
		}
		else if (on_lora_page) // If lora page selected
		{
			if (lora_page_once)
			{

				HAL_GPIO_WritePin(C6_EN_GPIO_Port, C6_EN_Pin, GPIO_PIN_RESET); // Disable ESP32

				lora_page(scr);

				create_rssi_snr_bars(scr);

				if (osMessageQueueGet(bme_lora_queue, received_bme_data, NULL, 10) == osOK)
				{
					show_bme_lora(received_bme_data);
				}

				lora_page_once = false;
			}

			if (osMessageQueueGet(lora_hex_queue_tx, received_lora_hex_data, NULL, 10) == osOK)
			{
				show_sending_receive_text((uint8_t *)received_lora_hex_data, sizeof(received_lora_hex_data), true);
			}

			if (osMessageQueueGet(lora_hex_queue_rx, received_lora_hex_data, NULL, 10) == osOK)
			{
				show_sending_receive_text((uint8_t *)received_lora_hex_data, sizeof(received_lora_hex_data), false);
			}

			if (osMessageQueueGet(lora_decrypted_queue_rx, received_lora_decrypted, NULL, 10) == osOK)
			{
				show_decrypted_text((uint8_t *)received_lora_decrypted);
			}

			if (osMessageQueueGet(lora_rssi_snr_queue, &lora_sigs, NULL, 10) == osOK)
			{
				update_rssi_snr_bars(lora_sigs.lora_rssi, lora_sigs.lora_snr); // RSSI, SNR
			}

			if (osMessageQueueGet(adc_queue, &received_adc_lora, NULL, 10) == osOK)
			{
				update_adc_lora(received_adc_lora);
			}

			if (show_encryption_decryption_key)
			{
				show_key();
				show_encryption_decryption_key = false;
			}


			if ((HAL_GPIO_ReadPin(S8_BTN_GPIO_Port, S8_BTN_Pin) == GPIO_PIN_SET) && (HAL_GPIO_ReadPin(S1_BTN_GPIO_Port, S1_BTN_Pin) == GPIO_PIN_SET)) // Btn 4 and 3
			{
				on_lidar_page = true;
				on_lora_page = false;
			}
			else if ((HAL_GPIO_ReadPin(S8_BTN_GPIO_Port, S8_BTN_Pin) == GPIO_PIN_SET) && (HAL_GPIO_ReadPin(S7_BTN_GPIO_Port, S7_BTN_Pin) == GPIO_PIN_SET)) // Btn 4 and 2
			{
				on_docs_page = true;
				on_lora_page = false;
			}
			else if (btn_1_pressed)
			{
				increment_selected_nibble();
				save_encryption_key_to_flash();
				btn_1_pressed = false;
			}
			else if (btn_2_pressed)
			{
				increment_nibble_selected();
				save_encryption_key_to_flash();
				btn_2_pressed = false;
			}
			else if (btn_3_pressed)
			{
				lora_val1 -= 4;
				lora_val2 -= 4;
				lora_val3 -= 4;
				lora_val4 -= 4;

				btn_3_pressed = false;
			}
			else if (btn_4_pressed)
			{
				lora_val1 += 4;
				lora_val2 += 4;
				lora_val3 += 4;
				lora_val4 += 4;

				btn_4_pressed = false;
			}
			else if (btn_5_pressed)
			{
				value_to_transmit = lora_val1;
				btn_5_pressed = false;
			}
			else if (btn_6_pressed)
			{
				value_to_transmit = lora_val2;
				btn_6_pressed = false;
			}
			else if (btn_7_pressed)
			{
				value_to_transmit = lora_val3;
				btn_7_pressed = false;
			}
			else if (btn_8_pressed)
			{
				value_to_transmit = lora_val4;
				btn_8_pressed = false;
			}

			values_to_send(scr, lora_val1, lora_val2, lora_val3, lora_val4); // Shows send nums at bottom
		}
		else if (on_scanning_page) // If scanning page selected
		{
			if (scanning_page_once)
			{
				osSemaphoreRelease(bmeDisableSemaphore); // Disable BME280
				osSemaphoreRelease(bmiDisableSemaphore); // Disable BMI323

				scanning_page_once = false;
			}

			if (osMessageQueueGet(wifi_scan_queue, &ap_data, NULL, 10) == osOK) // Receive scanned networks from UART interrupt
			{
				// Process the received data
				/*printf("RTOS Task Received Data:\n");
				printf("AP Count: %d\n", ap_data.ap_count);
				printf("SSID: %s\n", ap_data.ssid);
				printf("BSSID: %s\n", ap_data.bssid);
				printf("RSSI: %d\n", ap_data.rssi);
				printf("Channel: %d\n", ap_data.channel);
				printf("Auth Mode: %d\n", ap_data.auth_mode);*/

				add_scan_to_page(ap_data.ssid, ap_data.bssid, ap_data.rssi, ap_data.channel, ap_data.auth_mode);
			}

			if (btn_3_pressed)
			{
				scroll_scan(SCAN_SPACING); // Scroll down
				network_selected++;
				show_network_selected_from_scan(network_selected);
				btn_3_pressed = false;
			}
			else if (btn_4_pressed)
			{
				scroll_scan(-SCAN_SPACING); // Scroll up
				network_selected--;
				show_network_selected_from_scan(network_selected);
				btn_4_pressed = false;
			}
			else if (btn_2_pressed)
			{
				network_chosen = true;
				on_data_page = true;
				on_scanning_page = false;
				btn_2_pressed = false;
			}

		}
		else if (on_docs_page) // If docs
		{
			if (docs_page_once)
			{
				osSemaphoreRelease(bmeDisableSemaphore); // Disable BME280
				osSemaphoreRelease(bmiDisableSemaphore); // Disable BMI323
				osSemaphoreRelease(sxDisableSemaphore); // Disable SX1262

				show_docs(scr);
				docs_page_once = false;
			}

		}

		/* Call the LVGL timer handler periodically */
		uint32_t time_till_next = lv_timer_handler();
		if (time_till_next > 50) { // Limit delay to keep responsiveness
			time_till_next = 50;
		}
		osDelay(time_till_next);

	}
  /* USER CODE END lvglTask */
}

/* USER CODE BEGIN Header_LoraTask */
/**
 * @brief Function implementing the loraTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_LoraTask */
void LoraTask(void *argument)
{
  /* USER CODE BEGIN loraTask */
	bool end_task = false;

	sx126x_sleep_cfgs_t sleep_cfg = SX126X_SLEEP_CFG_COLD_START; // For disabling if not in LoRa mode

	sx126x_mod_params_lora_t lora_mod_params =
	{
			.sf = SX126X_LORA_SF9, // Spreading factor (higher value sends further but takes more time)
			.bw = SX126X_LORA_BW_125, // Bandwidth
			.cr = SX126X_LORA_CR_4_5, // Error correction
			.ldro = 0, // 1 if SF > 10
	};

	sx126x_pkt_params_lora_t lora_pkt_params =
	{
			.preamble_len_in_symb = 12,
			.header_type = SX126X_LORA_PKT_EXPLICIT,
			.pld_len_in_bytes = (CYPHERTEXT_LENGTH + 16), // 64 cyphertext + 16 IV (for decryption)
			.crc_is_on = true,
			.invert_iq_is_on = false,
	};

	// Define the PA configuration parameters
	sx126x_pa_cfg_params_t pa_config =
	{
			.pa_duty_cycle = 0x04, // Duty cycle setting
			.hp_max = 0x07, // Maximum output power
			.device_sel = 0x00, // Select SX1262-specific PA configuration
			.pa_lut = 0x01 // Default LUT (Look-Up Table)
	};

	sx126x_hal_reset(NULL);

	while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

	sx126x_status_t status = sx126x_init_retention_list(NULL);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set packet type\n");
	}

	status = sx126x_set_reg_mode(NULL, SX126X_REG_MODE_LDO);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set reg mode\n");
	}

	//sx126x_set_dio2_as_rf_sw_ctrl(NULL, 1);
	//sx126x_set_dio3_as_tcxo_ctrl

	status = sx126x_cal(NULL, SX126X_CAL_ALL);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to calibrate\n");
	}

	status = sx126x_set_standby(NULL, SX126X_STANDBY_CFG_RC);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set standby\n");
	}

	status = sx126x_set_pkt_type(NULL, SX126X_PKT_TYPE_LORA);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set packet type\n");
	}

	status = sx126x_set_rf_freq(NULL, 915000000);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set frequency?\n");
	}

	status = sx126x_set_pa_cfg(NULL, &pa_config);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set pa configuration\n");
	}

	//sx126x_set_rx_tx_fallback_mode
	//sx126x_cfg_rx_boosted

	status = sx126x_set_lora_mod_params(NULL, &lora_mod_params);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set lora parameters\n");
	}

	status = sx126x_set_lora_pkt_params(NULL, &lora_pkt_params);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set lora packet parameters\n");
	}

	status = sx126x_set_dio_irq_params(
			NULL,                            // Context (use NULL if not required)
			SX126X_IRQ_RX_DONE | SX126X_IRQ_CRC_ERROR, // Enable RX_DONE and CRC_ERROR IRQs
			SX126X_IRQ_RX_DONE,              // Map RX_DONE to DIO1
			SX126X_IRQ_NONE,                 // No IRQs mapped to DIO2
			SX126X_IRQ_NONE                  // No IRQs mapped to DIO3
	);

	if (status != SX126X_STATUS_OK) {
		printf("Failed to set DIO IRQ parameters\n");
	}

	status = sx126x_set_lora_sync_word(NULL, 0x62);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to set LoRa sync word\n");
	}

	char payload[CYPHERTEXT_LENGTH] = {0}; // Hold data to send
	for (;;)
	{
		if (!end_task)
		{
			if (on_lora_page && value_to_transmit != 0)
			{
				snprintf(payload, sizeof(payload), "DualCast_Command_Value: %d", value_to_transmit); // Format command into string

				encrypt_and_transmit((uint8_t *)payload); // Encrypt and send over LoRa
				osDelay(475); // Delay to allow time to transmit
				set_lora_rx_mode(); // Listen for receipt from receiver

				value_to_transmit = 0;
			}

			if (osSemaphoreAcquire(sxDisableSemaphore, 0) == osOK)
			{
				sx126x_status_t status = sx126x_set_sleep(NULL, sleep_cfg);
				if (status != SX126X_STATUS_OK)
				{
					printf("Failed to set sleep mode: %d\n", status);
				}
				else
				{
					//printf("LoRa set to sleep mode: %d\n", status);
					end_task = true;
				}
			}
		}

		osDelay(100);
	}
  /* USER CODE END loraTask */
}

/* USER CODE BEGIN Header_AccelTask */
/**
 * @brief Function implementing the accelTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_AccelTask */
void AccelTask(void *argument)
{
  /* USER CODE BEGIN accelTask */

	uint16_t command = BMI3_SLEEP_MASK; // BMI3_SLEEP_MASK defined as 0x0001
	bool end_task = false;

	struct bmi3_dev dev = {0};
	struct bmi3_sensor_data sensor_data = {0};
	//struct bmi3_sens_config config = {0};
	int8_t rslt;
	uint16_t int_status = 0;
	float x = 0; //, y = 0, z = 0;

	// Initialize the BMI323 sensor interface
	rslt = bmi3_interface_init(&dev, BMI3_I2C_INTF);
	bmi3_error_codes_print_result("bmi3_interface_init", rslt);

	// Initialize the BMI323 sensor
	rslt = bmi323_init(&dev);
	bmi3_error_codes_print_result("bmi323_init", rslt);

	// Configure accelerometer settings
	rslt = set_accel_config(&dev);
	bmi3_error_codes_print_result("set_accel_config", rslt);

	// Set up the sensor data type to read accelerometer data
	sensor_data.type = BMI323_ACCEL;

	// Infinite loop
	for (;;)
	{
		if (!end_task)
		{
			// Check accelerometer data ready interrupt status
			rslt = bmi323_get_int1_status(&int_status, &dev);
			bmi3_error_codes_print_result("bmi323_get_int1_status", rslt);

			if ((rslt == BMI323_OK) && (int_status & BMI3_INT_STATUS_ACC_DRDY))
			{

				// Get accelerometer data for X, Y, Z axes
				rslt = bmi323_get_sensor_data(&sensor_data, 1, &dev);
				bmi3_error_codes_print_result("bmi323_get_sensor_data", rslt);

				// Convert raw LSB values to m/s²
				if (rslt == BMI323_OK)
				{
					x = lsb_to_mps2(sensor_data.sens_data.acc.x, 2, dev.resolution);
					//y = lsb_to_mps2(sensor_data.sens_data.acc.y, 2, dev.resolution);
					//z = lsb_to_mps2(sensor_data.sens_data.acc.z, 2, dev.resolution);

					// Print the scaled integer values
					//printf("Accel (m/s² x100): X=%.2f, Y=%.2f, Z=%.2f\n", x, y, z);

					osStatus_t status = osMessageQueuePut(rotation_queue, &x, 0, 100);
					if (status != osOK)
					{
						//printf("Failed to send rotation_queue\n");
					}
				}
			}

			if (osSemaphoreAcquire(bmiDisableSemaphore, 0) == osOK)
			{
				rslt = bmi323_set_command_register(command, &dev);
				if (rslt == BMI323_OK)
				{
					//printf("BMI set to sleep mode\n");
					end_task = true;
				}
			}
		}

		osDelay(50);
	}
  /* USER CODE END accelTask */
}

/* USER CODE BEGIN Header_AtmoTask */
/**
 * @brief Function implementing the atmoTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_AtmoTask */
void AtmoTask(void *argument)
{
  /* USER CODE BEGIN atmoTask */
	bool end_task = false;

	struct bme280_dev dev = {0};
	struct bme280_settings settings = {0};
	struct bme280_data comp_data = {0};
	int8_t rslt;
	uint32_t period;

	if (osMutexAcquire(i2c4MutexId, osWaitForever) == osOK)
	{
		// Initialize the BME280 interface
		rslt = bme280_interface_selection(&dev, BME280_I2C_INTF);
		if (rslt != BME280_OK)
		{
			printf("BME280 interface selection failed! Exiting task.\n");
		}

		// Initialize the BME280 sensor
		rslt = bme280_init(&dev);
		if (rslt != BME280_OK)
		{
			printf("BME280 initialization failed! Exiting task.\n");
		}

		// Set desired configurations
		settings.filter = BME280_FILTER_COEFF_2;
		settings.osr_h = BME280_OVERSAMPLING_4X;  // Humidity
		settings.osr_p = BME280_OVERSAMPLING_4X;  // Pressure
		settings.osr_t = BME280_OVERSAMPLING_4X;  // Temperature
		settings.standby_time = BME280_STANDBY_TIME_0_5_MS;

		rslt = bme280_set_sensor_settings(BME280_SEL_ALL_SETTINGS, &settings, &dev);
		if (rslt != BME280_OK)
		{
			printf("Failed to set BME280 sensor settings! Exiting task.\n");
		}

		// Set the sensor to normal power mode
		rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, &dev);
		if (rslt != BME280_OK)
		{
			printf("Failed to set BME280 sensor mode! Exiting task.\n");
		}

		// Calculate the measurement delay
		rslt = bme280_cal_meas_delay(&period, &settings);
		if (rslt != BME280_OK)
		{
			printf("Failed to calculate measurement delay! Exiting task.\n");
		}

		//printf("Measurement time: %lu us\n", (long unsigned int)period);
		osMutexRelease(i2c4MutexId);
	}

	// Periodic task loop
	uint32_t last_wake_time = osKernelGetTickCount();
	uint8_t bme_data[64] = {0};

	while (1)
	{
		if (!end_task)
		{
			// Wait for the next cycle
			uint32_t current_time = osKernelGetTickCount();
			if ((current_time - last_wake_time) < (period / 1000))
			{
				osDelay((period / 1000) - (current_time - last_wake_time));
			}
			last_wake_time = osKernelGetTickCount();

			if (osMutexAcquire(i2c4MutexId, osWaitForever) == osOK)
			{

				rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, &dev); // Get data

				if (rslt == BME280_OK)
				{
					// Print data using floating-point formatting
					//printf("Temperature: %.2f C\n", comp_data.temperature);
					//printf("Pressure: %.2f raw\n", comp_data.pressure);
					//printf("Humidity: %.2f %%RH\n", comp_data.humidity);

					float sea_level_pressure = 101325.0; // Reference pressure in Pa
					float altitude = 44330.0 * (1.0 - pow((float)comp_data.pressure / sea_level_pressure, 0.1903));
					//printf("Altitude: %.2f m\n", altitude);

					snprintf((char *)bme_data, sizeof(bme_data), "T:%.2f C / %.2f F, P:%.2f hPa\nH:%.2f %%, Alt:%.2f m",
							comp_data.temperature, (comp_data.temperature * 1.8) + 32, (comp_data.pressure / 100), comp_data.humidity, altitude);
					//printf("BME280: %s", bme_data);

					osStatus_t status = osMessageQueuePut(bme_wifi_queue, bme_data, 0, 0);
					if (status != osOK)
					{
						//printf("Failed to send bme_wifi_queue\n");
					}
					status = osMessageQueuePut(bme_lora_queue, bme_data, 0, 0);
					if (status != osOK)
					{
						//printf("Failed to send bme_lora_queue\n");
					}
				}

				if (osSemaphoreAcquire(bmeDisableSemaphore, 0) == osOK)
				{
					rslt = put_device_to_sleep(&dev);
					if (rslt == BME280_OK)
					{
						//printf("BME set to sleep mode\n");
						end_task = true;
					}
				}

				osMutexRelease(i2c4MutexId);
			}
		}

		osDelay(500);
	}
  /* USER CODE END atmoTask */
}

/* USER CODE BEGIN Header_LidarTask */
/**
 * @brief Function implementing the lidarTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_LidarTask */
void LidarTask(void *argument)
{
  /* USER CODE BEGIN lidarTask */

	// Guide:
	// https://www.st.com/resource/en/user_manual/um2923-a-guide-to-using-the-vl53l4cx-timeofflight-sensor-with-extended-distance-measurement-stmicroelectronics.pdf

	// Initialize the VL53L4CX structure
	vl53l4cx_dev.I2cDevAddr = VL53L4CX_ADDR;
	vl53l4cx_dev.I2cHandle = &hi2c4;

	// Block until the semaphore is available
	osSemaphoreAcquire(lidarEnableSemaphore, osWaitForever);

	HAL_GPIO_WritePin(XSHUT_GPIO_Port, XSHUT_Pin, GPIO_PIN_SET); // Enable LiDAR

	if (osMutexAcquire(i2c4MutexId, osWaitForever) == osOK)
	{
		// Wait for the device to boot
		if (VL53LX_WaitDeviceBooted(&vl53l4cx_dev) != VL53LX_ERROR_NONE)
		{
			printf("Failed to wait for device booted.\n");
		}

		// Initialize the sensor
		if (VL53LX_DataInit(&vl53l4cx_dev) != VL53LX_ERROR_NONE)
		{
			printf("Failed to initialize data.\n");
		}

		if (VL53LX_SetTuningParameter(&vl53l4cx_dev, VL53LX_TUNINGPARM_PHASECAL_PATCH_POWER, 2) != VL53LX_ERROR_NONE) {
			printf("Failed to set tuning parameter for phase calibration.\n");
		}

		// Set the distance mode
		// VL53LX_DISTANCEMODE_SHORT: Short-range mode with better accuracy but reduced range
		// VL53LX_DISTANCEMODE_MEDIUM: Mix
		// VL53LX_DISTANCEMODE_LONG: Long-range mode with increased range but slightly less precision.
		if (VL53LX_SetDistanceMode(&vl53l4cx_dev, VL53LX_DISTANCEMODE_LONG) != VL53LX_ERROR_NONE)
		{
			printf("Failed to set distance mode.\n");
		}

		// Set the measurement timing budget
		// Lower values increase speed but reduce accuracy.
		// Higher values (e.g., 50000 µs or 100000 µs) improve accuracy but increase latency.
		if (VL53LX_SetMeasurementTimingBudgetMicroSeconds(&vl53l4cx_dev, 100000) != VL53LX_ERROR_NONE) // Going for high accuracy
		{
			printf("Failed to set measurement timing budget.\n");
		}

		/*
			// Some other optional settings you can mess with

			// Set the ROI to an 8x8 region. Default ROI is 13deg from center in all directions (25/29deg cone)
			if (VL53LX_SetUserROI(&vl53l4cx_dev, 8, 8) != VL53LX_ERROR_NONE) {
				printf("Failed to set ROI.\n");
			}

			uint16_t signal_min = 200;    // Minimum signal threshold (arbitrary example)
			uint16_t ambient_max = 1000; // Maximum ambient noise threshold (arbitrary example)
			if (VL53LX_SetThresholds(&vl53l4cx_dev, signal_min, ambient_max) != VL53LX_ERROR_NONE) {
				printf("Failed to set thresholds.\n");
			}

			if (VL53LX_SetInterruptConfig(&vl53l4cx_dev, VL53LX_INTERRUPT_NEW_SAMPLE_READY) != VL53LX_ERROR_NONE) {
				printf("Failed to configure interrupts.\n");
			}

			if (VL53LX_SetAmbientLightCompensation(&vl53l4cx_dev, ENABLE) != VL53LX_ERROR_NONE) {
				printf("Failed to enable ambient light compensation.\n");
			}
		 */

		osMutexRelease(i2c4MutexId);
	}

	static bool is_measuring = false;

	/* Infinite loop */
	for(;;)
	{
		// If not already measuring, start measurement once.
		if (!is_measuring)
		{
			if (osMutexAcquire(i2c4MutexId, osWaitForever) == osOK)
			{
				if (VL53LX_StartMeasurement(&vl53l4cx_dev) != VL53LX_ERROR_NONE)
				{
					printf("Failed to start measurement.\n");
				}
				else
				{
					is_measuring = true;
				}
				osMutexRelease(i2c4MutexId);
			}
		}

		// Perform measurement (assuming measurement is continuous once started)
		if (is_measuring)
		{
			if (osMutexAcquire(i2c4MutexId, osWaitForever) == osOK)
			{
				if (VL53LX_WaitMeasurementDataReady(&vl53l4cx_dev) == VL53LX_ERROR_NONE)
				{
					if (VL53LX_GetMultiRangingData(&vl53l4cx_dev, &ranging_data) == VL53LX_ERROR_NONE)
					{
						for (uint8_t i = 0; i < ranging_data.NumberOfObjectsFound; i++)
						{
							//printf("Distance: %d mm, Status: %d\n",
							//		ranging_data.RangeData[i].RangeMilliMeter,
							//		ranging_data.RangeData[i].RangeStatus);

							osStatus_t status = osMessageQueuePut(lidar_queue, &ranging_data, 0, 10);
							if (status != osOK)
							{
								//printf("Failed to send lidar_queue\n");
							}

							// Separate queue for distance only for speed
							status = osMessageQueuePut(lidar_queue_d, &ranging_data.RangeData[0].RangeMilliMeter, 0, 10);
							if (status != osOK)
							{
								//printf("Failed to send lidar_queue_d\n");
							}
						}
					}
					VL53LX_ClearInterruptAndStartMeasurement(&vl53l4cx_dev);
				}
				else
				{
					printf("Measurement timeout or error.\n");
				}
				osMutexRelease(i2c4MutexId);
			}
		}

		osDelay(100);
	}
  /* USER CODE END lidarTask */
}

/* USER CODE BEGIN Header_UartTask */
/**
 * @brief Function implementing the uartTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_UartTask */
void UartTask(void *argument)
{
  /* USER CODE BEGIN uartTask */

	wifi_analyze_data_t analyze_data;

	//static bool network_chosen = false;
	static bool choice_ready = false;
	static bool type_selected = false;

	target_type = 2; // 1 = Beacon Frames, 2 = Data Frames

	uint8_t rx_data;
	HAL_UART_Receive_IT(&huart4, &rx_data, 1); // Start receiving in interrupt mode

	/* Infinite loop */
	for(;;)
	{
		if (start_scan == true) // Ask for the available networks
		{
			uint8_t msg[] = "scan_for_networks";
			HAL_UART_Transmit(&huart4, msg, sizeof(msg), HAL_MAX_DELAY); // Send scan_for_networks command
			on_wifi_page = false;
			on_scanning_page = true;
			start_scan = false;
		}

		if (osMessageQueueGet(wifi_analyze_queue, &analyze_data, NULL, 10) == osOK) // Receive the BSSID and channel of all networks scanned
		{
			/*printf("Saved BSSIDs and Channels:\n");
			for (int i = 0; i < 20; i++) // Max 20 networks (can change if needed)
			{
				if (analyze_data.bssid[i][0] != '\0') // Check if BSSID is valid (not empty)
				{
					printf("Entry %d: BSSID = %s, Channel = %d\n",
							i + 1, analyze_data.bssid[i], analyze_data.channel[i]);
				}
			}*/
			choice_ready = true;
		}

		if (choice_ready && network_chosen) // Enable choice of network after all scanning done
		{
			// Send the selected network's BSSID and channel over UART
			for (int i = 0; i < 20; i++) // Max 20 networks (can change if needed)
			{
				if (analyze_data.bssid[i][0] != '\0') // Check if BSSID is valid (not empty)
				{
					if (i + 1 == network_selected) // Adjust for 1-based indexing. This "if" matches the network selected with the corresponding BSSID
					{
						char msg[96]; // Buffer to store the message

						// Combine data into string to send
						snprintf(msg, sizeof(msg), "network_selected BSSID: %s Channel: %d", analyze_data.bssid[i], analyze_data.channel[i]);

						// Send the specific network to analyze to the ESP32 (BSSID & channel)
						HAL_UART_Transmit(&huart4, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);
						//printf("Transmitted: %s\n", msg); // Debug log
						choice_ready = false; // Prevent looping
						type_selected = true; // Enables selection of beacon frames or data frames
						network_chosen = false;
						break; // No need to check further networks
					}
				}
			}
		}

		if (type_selected == true) // Ready to analyze (Data Frames are default)
		{
			if (target_type == 1) // If 1: Request ESP32 to sniff network Beacon Frames
			{
				uint8_t msg[] = "type_beacon";
				HAL_UART_Transmit(&huart4, msg, sizeof(msg), HAL_MAX_DELAY); // Send type_beacon command
				//type_selected = false;
			}
			else if (target_type == 2) // If 2: Request ESP32 to sniff network Data Frames
			{
				uint8_t msg[] = "type_data";
				HAL_UART_Transmit(&huart4, msg, sizeof(msg), HAL_MAX_DELAY); // Send type_data command
				//type_selected = false;
			}
		}

		osDelay(100);

	}
  /* USER CODE END uartTask */
}

/* USER CODE BEGIN Header_AdcTask */
/**
 * @brief Function implementing the adcTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_AdcTask */
void AdcTask(void *argument)
{
  /* USER CODE BEGIN adcTask */
	uint64_t sum;
	uint32_t avg_adc;

	/* Infinite loop */
	for(;;)
	{
		// Average ADC samples
		sum = 0;
		for (uint8_t i = 0; i < NUM_ADC_SAMPLES; i++)
		{
			if (HAL_ADC_Start(&hadc1) == HAL_OK)
			{
				// Wait for conversion to complete (timeout in ms)
				if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
				{
					// Accumulate the ADC conversion result
					sum += HAL_ADC_GetValue(&hadc1);
				}
				HAL_ADC_Stop(&hadc1);
			}
			osDelay(1);
		}

		// Calculate the average value
		avg_adc = (uint32_t)(sum / NUM_ADC_SAMPLES);

		// Now send the averaged ADC value to your queue
		osStatus_t status = osMessageQueuePut(adc_queue, &avg_adc, 0, 0);
		if (status != osOK)
		{
			//printf("Failed to send data to adc_queue\n");
		}

		osDelay(100);
	}
  /* USER CODE END adcTask */
}

/* USER CODE BEGIN Header_HapticTask */
/**
 * @brief Function implementing the hapticTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_HapticTask */
void HapticTask(void *argument)
{
  /* USER CODE BEGIN hapticTask */
	/* Infinite loop */
	for(;;)
	{
		// Control haptic motor
		if (on_lora_page && lora_hap_btn_pressed)
		{
			HAL_GPIO_WritePin(HAPTIC_CTRL_GPIO_Port, HAPTIC_CTRL_Pin, GPIO_PIN_SET);
			osDelay(HAPTIC_ON_TIME); // Motor on time
			HAL_GPIO_WritePin(HAPTIC_CTRL_GPIO_Port, HAPTIC_CTRL_Pin, GPIO_PIN_RESET);
			osDelay(HAPTIC_ON_TIME * 10);
			lora_hap_btn_pressed = false;
		}
		else if (!on_lora_page && any_btn_pressed)
		{
			HAL_GPIO_WritePin(HAPTIC_CTRL_GPIO_Port, HAPTIC_CTRL_Pin, GPIO_PIN_SET);
			osDelay(HAPTIC_ON_TIME); // Motor on time
			HAL_GPIO_WritePin(HAPTIC_CTRL_GPIO_Port, HAPTIC_CTRL_Pin, GPIO_PIN_RESET);
			osDelay(HAPTIC_ON_TIME * 10);
			any_btn_pressed = false;
		}

		osDelay(50);
	}
  /* USER CODE END hapticTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */





/* USER CODE END Application */

