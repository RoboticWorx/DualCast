#include "dualcast_functions.h"
#include "dualcast_lvgl.h"
#include "app_freertos.h"

#include <stdlib.h>

#include "sx126x.h"
#include "sx126x_hal.h"

#include "bmi323.h"
#include "bme280.h"
#include "common.h"
#include "common_bme.h"

#include "aes.h"

extern uint8_t encryption_key[];
extern osMessageQueueId_t lora_hex_queue_tx;
extern osMessageQueueId_t lora_hex_queue_rx;
extern osMessageQueueId_t lora_decrypted_queue_rx;

static bool in_tx_mode = false;
static bool in_rx_mode = false;

static void generate_random_iv(uint8_t *iv, size_t length)
{
	for (size_t i = 0; i < length; i++)
{
		iv[i] = (uint8_t) (rand() % (255 + 1)); // Generate number 0 - 255
	}
}

void set_lora_rx_mode(void) // Call once to set RX mode and receive on EXTI8
{
	if (!in_rx_mode) // If not already in rx mode
	{
		while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET) osDelay(1);

		HAL_GPIO_WritePin(DIO2_GPIO_Port, DIO2_Pin, GPIO_PIN_RESET); // 1 = TX, 0 = RX

		sx126x_cfg_rx_boosted(NULL, true); // increase sensitivity at higher power cost

		// Enter continuous RX mode
		sx126x_status_t status = sx126x_set_rx(NULL, SX126X_RX_SINGLE_MODE); // sx126x_set_rx_with_timeout_in_rtc_step(NULL, SX126X_RX_SINGLE_MODE);
		if (status != SX126X_STATUS_OK)
		{
			printf("Failed to enter continuous RX mode\n");
			return;
		}
	}
	in_rx_mode = true;
	in_tx_mode = false;
}

void set_lora_tx_mode(void) // Call once to set TX mode
{
	if (!in_tx_mode) // If not already in tx mode
	{
		while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET) osDelay(1);

		HAL_GPIO_WritePin(DIO2_GPIO_Port, DIO2_Pin, GPIO_PIN_SET); // 1 = TX, 0 = RX

		sx126x_status_t status = sx126x_set_tx_params(NULL, 22, SX126X_RAMP_200_US);
		if (status != SX126X_STATUS_OK)
		{
			printf("Failed to TX parameters\n");
		}
	}
	in_tx_mode = true;
	in_rx_mode = false;
}

void lora_tx(uint8_t tx_data[], uint8_t data_len)
{

	while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET) osDelay(1);

	sx126x_status_t status = sx126x_write_buffer(NULL, 0, tx_data, data_len);
	if (status != SX126X_STATUS_OK) {
		printf("Failed to write to buffer\n");
	}

	// Start transmission
	status = sx126x_set_tx(NULL, SX126X_MAX_TIMEOUT_IN_MS);

	if (status != SX126X_STATUS_OK)
	{
		printf("Failed to start transmission\n");
	}

}

void process_received_message(uint8_t *message, size_t message_len)
{
	// Verify that the message length is at least 16 bytes (for IV) + 16 bytes (minimum ciphertext)
	if (message_len < 32)
	{
		printf("Received message too short!\n");
		return;
	}

	// The expected message length is 80 bytes (16 IV + 64 cyphertext)
	if (message_len != CYPHERTEXT_LENGTH + 16)
	{
		printf("Unexpected message length: %u bytes\n", (unsigned)message_len);
		return;
	}

	uint8_t iv[16]; // To hold IV
	memcpy(iv, message, 16); // Extract the IV (first 16 bytes)

	uint8_t ciphertext[CYPHERTEXT_LENGTH]; // To hold cyphertext
	memcpy(ciphertext, message + 16, CYPHERTEXT_LENGTH); // Extract the ciphertext (remaining 64 bytes)

	// Print the received IV
	/*printf("Received IV: ");
	for (int i = 0; i < 16; i++) {
		printf("%02X ", iv[i]);
	}
	printf("\n");*/

	osStatus_t status = osMessageQueuePut(lora_hex_queue_rx, message, 0, 0);
	if (status != osOK)
	{
		printf("Failed to send lora_hex_queue_rx\n");
	}

	// Initialize the AES context with the key and received IV.
	struct AES_ctx ctx;
	AES_init_ctx_iv(&ctx, encryption_key, iv);

	// Decrypt "ciphertext"
	AES_CBC_decrypt_buffer(&ctx, ciphertext, sizeof(ciphertext));

	ciphertext[sizeof(ciphertext) - 1] = '\0'; // Ensure null termination

	status = osMessageQueuePut(lora_decrypted_queue_rx, ciphertext, 0, 0);
	if (status != osOK)
	{
		printf("Failed to send lora_decrypted_queue_rx\n");
	}

	// "cyphertext" is now decrypted - print
	//printf("Decrypted text: %s\n", ciphertext);
}

void encrypt_and_transmit(uint8_t plaintext[])
{
	set_lora_tx_mode(); // Call once to set TX parameters

	uint8_t buffer[CYPHERTEXT_LENGTH]; // Padded to 64 bytes (must be multiple of 16)
	memcpy(buffer, plaintext, sizeof(buffer)); // Copy the 64 bytes into buffer

	uint8_t iv[16]; // To hold IV
	generate_random_iv(iv, sizeof(iv)); // Generate random IV into iv[16]

	/*printf("Generated IV: ");
	for (int i = 0; i < 16; i++) {
		printf("%02X ", iv[i]);
	}
	printf("\n");*/

	struct AES_ctx ctx;
	AES_init_ctx_iv(&ctx, encryption_key, iv); // Initialize AES context with key and IV

	AES_CBC_encrypt_buffer(&ctx, buffer, sizeof(buffer)); // Encrypt buffer

	uint8_t message[16 + CYPHERTEXT_LENGTH]; // New buffer to send
	memcpy(message, iv, 16); // First 16 bytes are IV
	memcpy(message + 16, buffer, CYPHERTEXT_LENGTH); // Next 64 are the cyphertext

	/*printf("Message to send (hex): ");
	for (int i = 0; i < (int)sizeof(message); i++)
	{
		printf("%02X ", message[i]);
	}
	printf("\n");*/

	osStatus_t status = osMessageQueuePut(lora_hex_queue_tx, message, 0, 0);
	if (status != osOK)
	{
		printf("Failed to send data to lora_hex_queue_tx\n");
	}

	lora_tx(message, sizeof(message)); // Send the data
}

int8_t set_accel_config(struct bmi3_dev *dev)
{
	int8_t rslt;
	struct bmi3_sens_config config;
	struct bmi3_map_int map_int = {0};

	// Configure accelerometer
	config.type = BMI323_ACCEL;
	rslt = bmi323_get_sensor_config(&config, 1, dev);
	if (rslt != BMI323_OK) return rslt;

	// Map accelerometer data-ready interrupt to INT1
	map_int.acc_drdy_int = BMI3_INT1;
	rslt = bmi323_map_interrupt(map_int, dev);
	if (rslt != BMI323_OK) return rslt;

	// Set accelerometer configurations
	config.cfg.acc.odr = BMI3_ACC_ODR_100HZ;
	config.cfg.acc.range = BMI3_ACC_RANGE_2G;
	config.cfg.acc.bwp = BMI3_ACC_BW_ODR_QUARTER;
	config.cfg.acc.avg_num = BMI3_ACC_AVG64;
	config.cfg.acc.acc_mode = BMI3_ACC_MODE_NORMAL;

	return bmi323_set_sensor_config(&config, 1, dev);
}

float lsb_to_mps2(int16_t val, int8_t g_range, uint8_t bit_width)
{
	float half_scale = pow(2, bit_width) / 2.0f;
	return (GRAVITY_EARTH * val * g_range) / half_scale;
}

int int_map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


