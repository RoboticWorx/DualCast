#include "aes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sx126x.h"
#include "sx126x_hal.h"
#include "main.h"

#include <math.h>

#include "bme280.h"
#include "bme280_defs.h"
#include "common_bme.h"

#include "dualcast_rx_functions.h"

extern uint8_t encryption_decryption_key[];
extern uint8_t command_received;

static bool in_tx_mode = false;
static bool in_rx_mode = false;

static void generate_random_iv(uint8_t *iv, size_t length)
{
	for (size_t i = 0; i < length; i++) {
		iv[i] = (uint8_t) (rand() % (255 + 1)); // Generate number 0 - 255
	}
	// or int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;
}

void set_lora_rx_mode(void) // Call once to set RX mode and receive on EXTI8
{
	if (!in_rx_mode) // If not already in rx mode
	{
		while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

		HAL_GPIO_WritePin(DIO2_GPIO_Port, DIO2_Pin, GPIO_PIN_RESET); // 1 = TX, 0 = RX

		sx126x_cfg_rx_boosted(NULL, true); // Increase sensitivity at higher power cost

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
		while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

		HAL_GPIO_WritePin(DIO2_GPIO_Port, DIO2_Pin, GPIO_PIN_SET); // 1 = TX, 0 = RX

		sx126x_status_t status = sx126x_set_tx_params(NULL, 22, SX126X_RAMP_200_US);
		if (status != SX126X_STATUS_OK) {
			printf("Failed to TX parameters\n");
		}
	}
	in_tx_mode = true;
	in_rx_mode = false;
}

void lora_tx(uint8_t tx_data[], uint8_t data_len)
{

	while (HAL_GPIO_ReadPin(SX_BUSY_GPIO_Port, SX_BUSY_Pin) == GPIO_PIN_SET);

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

	// Initialize the AES context with the key and received IV.
	struct AES_ctx ctx;
	AES_init_ctx_iv(&ctx, encryption_decryption_key, iv);

	// Decrypt "ciphertext"
	AES_CBC_decrypt_buffer(&ctx, ciphertext, sizeof(ciphertext));

	// "cyphertext" is now decrypted - print
	//printf("Decrypted text: %s\n", ciphertext);

	ciphertext[sizeof(ciphertext) - 1] = '\0'; // Ensure null termination

    // Extract the number received using sscanf.
    static int extracted_number;
    if (sscanf((char *)ciphertext, "DualCast_Command_Value: %d", &extracted_number) == 1)
    {
        command_received = extracted_number;
    }
    else
    {
    	command_received = 0;
    }
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
	AES_init_ctx_iv(&ctx, encryption_decryption_key, iv); // Initialize AES context with key and IV

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

	lora_tx(message, sizeof(message));
}

void output_to_binary(uint8_t command_received)
{
	if (command_received > 31)
		return;

    // IO1 corresponds to Bit 0
    HAL_GPIO_WritePin(IO1_GPIO_Port, IO1_Pin,
        (command_received & (1 << 0)) ? GPIO_PIN_SET : GPIO_PIN_RESET); // 0b00000001 & command_received = 0 or not 0

    // IO2 corresponds to Bit 1
    HAL_GPIO_WritePin(IO2_GPIO_Port, IO2_Pin,
        (command_received & (1 << 1)) ? GPIO_PIN_SET : GPIO_PIN_RESET); // 0b00000010 & command_received = 0 or not 0

    // IO3 corresponds to Bit 2
    HAL_GPIO_WritePin(IO3_GPIO_Port, IO3_Pin,
        (command_received & (1 << 2)) ? GPIO_PIN_SET : GPIO_PIN_RESET); // 0b00000100 & command_received = 0 or not 0

    // IO4 corresponds to Bit 3
    HAL_GPIO_WritePin(IO4_GPIO_Port, IO4_Pin,
        (command_received & (1 << 3)) ? GPIO_PIN_SET : GPIO_PIN_RESET); // 0b00001000 & command_received = 0 or not 0

    // IO5 corresponds to Bit 4
    HAL_GPIO_WritePin(IO5_GPIO_Port, IO5_Pin,
        (command_received & (1 << 4)) ? GPIO_PIN_SET : GPIO_PIN_RESET); // 0b00010000 & command_received = 0 or not 0
}

void reset_gpios(void)
{
	HAL_GPIO_WritePin(IO1_GPIO_Port, IO1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IO2_GPIO_Port, IO2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IO3_GPIO_Port, IO3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IO4_GPIO_Port, IO4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IO5_GPIO_Port, IO5_Pin, GPIO_PIN_RESET);
}

float lsb_to_mps2(int16_t val, int8_t g_range, uint8_t bit_width)
{
	float half_scale = pow(2, bit_width) / 2.0f;
	return (GRAVITY_EARTH * val * g_range) / half_scale;
}
