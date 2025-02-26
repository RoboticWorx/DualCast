#ifndef UART_FUNCTIONS_H
#define UART_FUNCTIONS_H

#include <stdint.h>

#define UART_NUM UART_NUM_1
#define UART_TX_PIN (GPIO_NUM_19) // Replace with your TX pin
#define UART_RX_PIN (GPIO_NUM_20) // Replace with your RX pin
#define BUF_SIZE 128
#define MAX_UNIQUE_MACS 100 // Maximum number of unique MAC addresses to track

typedef struct {
    uint8_t mac[6];
} mac_address_t;


// Function prototypes
void format_unique_macs(char *buffer, size_t buffer_size);
bool is_mac_address_unique(const uint8_t *mac);
void add_mac_address(const uint8_t *mac);
void init_uart(void);
void send_ap_info_over_uart(const wifi_ap_record_t *ap_info, uint16_t ap_count);

#endif // UART_FUNCTIONS_H
