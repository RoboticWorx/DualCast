/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sx126x.h"
#include "sx126x_hal.h"

#include "aes.h"
#include "dualcast_rx_functions.h"

#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

uint8_t encryption_decryption_key[16] = // CHANGE TO YOUR OWN UNIQUE VALUES
{
		0x60, 0x3d, 0xeb, 0x10,
		0x15, 0xca, 0x71, 0xbe,
		0x2b, 0x73, 0xae, 0xf0,
		0x85, 0x7d, 0x77, 0x81
};

uint8_t command_received;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_ADC1_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*int _write(int file, char *ptr, int len)
{
    // Using HAL_UART_Transmit to send data over USART3
    HAL_UART_Transmit(&huart3, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}*/
/*int __io_putchar(int ch)
{
// Support printf over UART
(void) HAL_UART_Transmit(&huart3, (uint8_t *) &ch, 1, 0xFFFFU);
 return ch;
}/*

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

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */


	// Init LoRa
	sx126x_mod_params_lora_t lora_mod_params = {
			.sf = SX126X_LORA_SF9,
			.bw = SX126X_LORA_BW_125,
			.cr = SX126X_LORA_CR_4_5,
			.ldro = 0,
	};

	// Preamble length updated to 12 symbols
	sx126x_pkt_params_lora_t lora_pkt_params = {
			.preamble_len_in_symb = 12,
			.header_type = SX126X_LORA_PKT_EXPLICIT,
			.pld_len_in_bytes = (CYPHERTEXT_LENGTH + 16), // 64 cyphertext + 16 IV (for decryption)
			.crc_is_on = true,
			.invert_iq_is_on = false,
	};

	// Define the PA configuration parameters
	sx126x_pa_cfg_params_t pa_config = {
			.pa_duty_cycle = 0x04,       // Duty cycle setting
			.hp_max = 0x07,             // Maximum output power
			.device_sel = 0x00, // Select SX1262-specific PA configuration
			.pa_lut = 0x01              // Default LUT (Look-Up Table)
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
	// End of init LoRa



	// Init BME280 atmospheric sensor
	struct bme280_dev dev = {0};
	struct bme280_settings settings = {0};
	struct bme280_data comp_data = {0};
	int8_t rslt;
	uint32_t period;

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

	printf("Measurement time: %lu us\n", (long unsigned int)period);

	uint32_t last_wake_time = HAL_GetTick();
	// End of init BME280 atmospheric sensor

	uint32_t time_since_received = HAL_GetTick();
	static bool gpios_reset = true;

	set_lora_rx_mode(); // Call once to begin receiving LoRa messages on EXTI8


	char sensor_data[CYPHERTEXT_LENGTH - 9] = {0};
	char command_str[9]; // "Cmd: " + 4 (int)
	char receipt[CYPHERTEXT_LENGTH] = {0};
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while(1)
	{

		HAL_GPIO_TogglePin(BLINK_GPIO_Port, BLINK_Pin); // Toggle LED

		// On valid LoRa receive
		if (command_received != 0)
		{
			output_to_binary(command_received); // Set the GPIOs to match the binary number

			// Format all the data into one receipt
			snprintf(command_str, sizeof(command_str), "Cmd: %d", command_received);
			snprintf(receipt, sizeof(receipt), "%s, %s", command_str, sensor_data);

			HAL_Delay(475); // Wait for transmitter to be ready to receive

			encrypt_and_transmit((uint8_t *)receipt);
			HAL_Delay(475); // Delay to allow time to transmit receipt
			set_lora_rx_mode();

			time_since_received = HAL_GetTick(); // Record time
			gpios_reset = false; // To only reset GPIOs once per receiving something

			command_received = 0;
		}
		// End of on LoRa receive

		// Binary output GPIOs will stay HIGH for 100ms then go back LOW
		if ((HAL_GetTick() - time_since_received) > 100 && !gpios_reset)
		{
			reset_gpios(); // Set them all back to LOW
			gpios_reset = true;
		}

		// Take BME280 reading
		uint32_t current_time = HAL_GetTick();
		if ((current_time - last_wake_time) < (period / 1000)) // Wait for BME280 sensor data to be ready
		{
			HAL_Delay((period / 1000) - (current_time - last_wake_time));
		}
		last_wake_time = HAL_GetTick();

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

			snprintf((char *)sensor_data, sizeof(sensor_data), "T:%.2fC / %.2fF, P:%.2fhPa, H:%.2f%%, Alt:%.2fm",
					comp_data.temperature, ((comp_data.temperature * 1.8) + 32), (comp_data.pressure / 100), comp_data.humidity, altitude);
		}
		// End of take BME280 reading

		HAL_Delay(250);
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 14;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.LowPowerAutoPowerOff = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_160CYCLES_5;
  hadc1.Init.SamplingTimeCommon2 = ADC_SAMPLETIME_1CYCLE_5;
  hadc1.Init.OversamplingMode = DISABLE;
  hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10606DA4;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, IO1_Pin|IO2_Pin|IO3_Pin|IO4_Pin
                          |IO5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, BLINK_Pin|BME_ADR_Pin|SX_CS_Pin|SX_NRST_Pin
                          |DIO2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(XSHUT_GPIO_Port, XSHUT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ANT_SW_GPIO_Port, ANT_SW_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : DIO3_Pin */
  GPIO_InitStruct.Pin = DIO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DIO3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : IO1_Pin IO2_Pin IO4_Pin IO5_Pin */
  GPIO_InitStruct.Pin = IO1_Pin|IO2_Pin|IO4_Pin|IO5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : IO3_Pin ANT_SW_Pin */
  GPIO_InitStruct.Pin = IO3_Pin|ANT_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BTN_Pin */
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(BTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BLINK_Pin */
  GPIO_InitStruct.Pin = BLINK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(BLINK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : XSHUT_Pin BME_ADR_Pin */
  GPIO_InitStruct.Pin = XSHUT_Pin|BME_ADR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : VL_INT_Pin */
  GPIO_InitStruct.Pin = VL_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(VL_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SX_BUSY_Pin */
  GPIO_InitStruct.Pin = SX_BUSY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SX_BUSY_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SX_CS_Pin SX_NRST_Pin DIO2_Pin */
  GPIO_InitStruct.Pin = SX_CS_Pin|SX_NRST_Pin|DIO2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : DIO1_Pin */
  GPIO_InitStruct.Pin = DIO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DIO1_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
