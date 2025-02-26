#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H

#include "esp_wifi.h"
#include <stdint.h>

#define MAX_SCAN_LIST_SIZE 20

// Function prototypes
void activate_wifi_promiscuous(uint8_t wifi_channel, const uint8_t *target_bssid);
void activate_wifi(void);
void deactivate_wifi(void);
void parse_supported_rates(const uint8_t *payload, int payload_len, char *rate_buffer, size_t buffer_size);
void scan_for_networks(wifi_ap_record_t *ap_info, uint16_t max_scan_list_size, uint16_t *ap_count);

#endif // WIFI_FUNCTIONS_H
