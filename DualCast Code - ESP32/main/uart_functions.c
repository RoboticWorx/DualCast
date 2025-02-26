#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include <string.h>
#include "wifi_functions.h"
#include "uart_functions.h"

static const char *TAG = "UART_Functions";


mac_address_t unique_macs[MAX_UNIQUE_MACS];
size_t unique_mac_count = 0;

void init_uart(void)
{
	// Init UART
    const uart_config_t uart_config = {
        .baud_rate = 460800,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM, UART_TX_PIN, UART_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
}

void send_ap_info_over_uart(const wifi_ap_record_t *ap_info, uint16_t ap_count)
{
    char tx_buffer[512]; // Buffer to hold formatted string
    for (uint16_t i = 0; i < ap_count; i++)
    {
        // Format the AP information into a string
        snprintf(tx_buffer, sizeof(tx_buffer),
                 "ap_count: %u, SSID: %s, BSSID: %02x:%02x:%02x:%02x:%02x:%02x, RSSI: %d, Channel: %d, Auth Mode: %d\n",
				 ap_count,
                 ap_info[i].ssid,
                 ap_info[i].bssid[0], ap_info[i].bssid[1], ap_info[i].bssid[2],
                 ap_info[i].bssid[3], ap_info[i].bssid[4], ap_info[i].bssid[5],
                 ap_info[i].rssi,
                 ap_info[i].primary,
                 ap_info[i].authmode);

        // Send the formatted string over UART
        uart_write_bytes(UART_NUM, "dummy\n", strlen("dummy\n")); // Buffer message to ensure communication stable
        uart_write_bytes(UART_NUM, tx_buffer, strlen(tx_buffer));
        vTaskDelay(pdMS_TO_TICKS(50)); // Prevent overwhelming STM32
    }
}

bool is_mac_address_unique(const uint8_t *mac)
{
    for (size_t i = 0; i < unique_mac_count; i++)
    {
        if (memcmp(unique_macs[i].mac, mac, 6) == 0)
        {
            return false; // MAC address already exists
        }
    }
    return true;
}

void add_mac_address(const uint8_t *mac)
{
	// Always count a new unique MAC detected

    if (unique_mac_count <= MAX_UNIQUE_MACS)
    {
        memcpy(unique_macs[unique_mac_count].mac, mac, 6);
        unique_mac_count++;
    }
    else
    {
        ESP_LOGW(TAG, "MAC address storage full, cannot track more unique addresses.");
    }
}

void format_unique_macs(char *buffer, size_t buffer_size)
{
    size_t offset = 0;

    // Only print the stored MACs (at most MAX_UNIQUE_MACS)
    size_t count_to_print = unique_mac_count;
    if (count_to_print > MAX_UNIQUE_MACS) {
        count_to_print = MAX_UNIQUE_MACS;
    }

    // Iterate over all unique MAC addresses
    for (int i = 0; i < count_to_print; i++)
    {
        int written = snprintf(buffer + offset, buffer_size - offset,
                               "%02x:%02x:%02x:%02x:%02x:%02x, ",
                               unique_macs[i].mac[0], unique_macs[i].mac[1], unique_macs[i].mac[2],
                               unique_macs[i].mac[3], unique_macs[i].mac[4], unique_macs[i].mac[5]);
        if (written < 0 || written >= buffer_size - offset)
        {
            ESP_LOGW(TAG, "Buffer size exceeded while formatting unique MACs");
            break;
        }
        offset += written;
    }

    // Remove the trailing comma and space
    if (offset >= 2)
    {
        buffer[offset - 2] = '\0'; // Null-terminate the string
    }
    else
    {
        buffer[0] = '\0'; // Handle case where no MACs are present
    }
}

