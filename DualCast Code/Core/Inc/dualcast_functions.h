#ifndef DUALCAST_FUNCTIONS_H
#define DUALCAST_FUNCTIONS_H

#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "bme280.h"
#include "common.h"
#include "common_bme.h"

#define CYPHERTEXT_LENGTH 64

#define GRAVITY_EARTH  (9.80665f)
#define VL53L4CX_ADDR 0x52 // Default I2C address of VL53L4CX

#define HAPTIC_ON_TIME 15
#define NUM_ADC_SAMPLES 100

typedef struct {
    int lora_rssi;
    int lora_snr;
} Lora_Receipt_t;


void encrypt_and_transmit(uint8_t plaintext[]);
void process_received_message(uint8_t *message, size_t message_len);

void set_lora_rx_mode(void);
void set_lora_tx_mode(void);
void lora_tx(uint8_t tx_data[], uint8_t data_len);

int8_t set_accel_config(struct bmi3_dev *dev);

float lsb_to_mps2(int16_t val, int8_t g_range, uint8_t bit_width);
int int_map(int x, int in_min, int in_max, int out_min, int out_max);


#endif
