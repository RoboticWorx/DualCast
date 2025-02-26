#include "sx126x_hal.h"
#include "stm32u0xx_hal.h"
#include "main.h"  // Pin definitions

extern SPI_HandleTypeDef hspi1;

sx126x_hal_status_t sx126x_hal_reset(const void* context)
{
	HAL_GPIO_WritePin(SX_NRST_GPIO_Port, SX_NRST_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);

	HAL_GPIO_WritePin(SX_NRST_GPIO_Port, SX_NRST_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	return SX126X_HAL_STATUS_OK;
}

sx126x_hal_status_t sx126x_hal_wakeup(const void* context)
{
	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_RESET); // CS low to begin transmit

    // Send a dummy byte
    uint8_t dummy_byte = SX126X_NOP;
    if (HAL_SPI_Transmit(&hspi1, &dummy_byte, 1, HAL_MAX_DELAY) != HAL_OK) {
    	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when done
        return SX126X_HAL_STATUS_ERROR;
    }

    HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when done

    // Wait for SX1262 to be ready
    while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

    return SX126X_HAL_STATUS_OK;
}

sx126x_hal_status_t sx126x_hal_write(const void* context, const uint8_t* command, const uint16_t command_length, const uint8_t* data, const uint16_t data_length)
{
	// Wait for the SX1262 to be ready
	while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_RESET); // CS low to begin transmit

	// Transmit command
	if (HAL_SPI_Transmit(&hspi1, (uint8_t*)command, command_length, HAL_MAX_DELAY) != HAL_OK) {
		HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when fail
		return SX126X_HAL_STATUS_ERROR;
	}

	// Transmit data
	if (data != NULL && data_length > 0) {
		if (HAL_SPI_Transmit(&hspi1, (uint8_t*)data, data_length, HAL_MAX_DELAY) != HAL_OK) {
			HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when fail
			return SX126X_HAL_STATUS_ERROR;
		}
	}

	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when done

	return SX126X_HAL_STATUS_OK;
}

sx126x_hal_status_t sx126x_hal_read(const void* context, const uint8_t* command, const uint16_t command_length, uint8_t* data, const uint16_t data_length)
{
	// Wait for the SX1262 to be ready
	while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_RESET); // CS low to begin transmit

	// Transmit command
	if (HAL_SPI_Transmit(&hspi1, (uint8_t*)command, command_length, HAL_MAX_DELAY) != HAL_OK) {
		HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when fail
		return SX126X_HAL_STATUS_ERROR;
	}

	// Receive data
	if (data != NULL && data_length > 0) {
		uint8_t dummy_byte = SX126X_NOP;
		if (HAL_SPI_TransmitReceive(&hspi1, &dummy_byte, data, data_length, HAL_MAX_DELAY) != HAL_OK) {
			HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when fail
			return SX126X_HAL_STATUS_ERROR;
		}
	}

	HAL_GPIO_WritePin(SX_CS_GPIO_Port, SX_CS_Pin, GPIO_PIN_SET); // CS high when done

	return SX126X_HAL_STATUS_OK;
}

