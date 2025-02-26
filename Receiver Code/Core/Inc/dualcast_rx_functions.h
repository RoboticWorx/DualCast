#ifndef DUALCAST_RX_FUNCTIONS_H
#define DUALCAST_RX_FUNCTIONS_H

#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bme280.h"
#include "common_bme.h"

#define GRAVITY_EARTH  (9.80665f)

#define CYPHERTEXT_LENGTH 64

void encrypt_and_transmit(uint8_t plaintext[]);
void process_received_message(uint8_t *message, size_t message_len);

void set_lora_rx_mode(void);
void set_lora_tx_mode(void);
void lora_tx(uint8_t tx_data[], uint8_t data_len);

void output_to_binary(uint8_t command_received);
void reset_gpios(void);

float lsb_to_mps2(int16_t val, int8_t g_range, uint8_t bit_width);

#endif
