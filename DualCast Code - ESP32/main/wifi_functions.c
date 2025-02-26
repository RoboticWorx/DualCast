#include "wifi_functions.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include <string.h>

static const char *TAG = "Wifi_Functions";

extern void wifi_promiscuous_handler(void *buf, wifi_promiscuous_pkt_type_t type);

void activate_wifi_promiscuous(uint8_t wifi_channel, const uint8_t *target_bssid)
{
	esp_err_t ret;

	ESP_LOGI(TAG, "Starting Wi-Fi in promiscuous mode...");

	// Initialize TCP/IP stack
	ESP_LOGI(TAG, "Initializing TCP/IP stack...");
	ret = esp_netif_init();
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to initialize TCP/IP stack: %s", esp_err_to_name(ret));
		return;
	}

	// Initialize Wi-Fi
	ESP_LOGI(TAG, "Initializing Wi-Fi...");
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ret = esp_wifi_init(&cfg);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to initialize Wi-Fi: %s", esp_err_to_name(ret));
		return;
	}

	// Set Wi-Fi mode
	ESP_LOGI(TAG, "Setting Wi-Fi mode to NULL...");
	ret = esp_wifi_set_mode(WIFI_MODE_NULL);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to set Wi-Fi mode: %s", esp_err_to_name(ret));
		return;
	}

	// Start Wi-Fi
	ESP_LOGI(TAG, "Starting Wi-Fi...");
	ret = esp_wifi_start();
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to start Wi-Fi: %s", esp_err_to_name(ret));
		return;
	}

	wifi_promiscuous_filter_t filter_config = {
	    .filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT | WIFI_PROMIS_FILTER_MASK_DATA // Look for both management (beacon) and data frames
	};
	ret = esp_wifi_set_promiscuous_filter(&filter_config);
	if (ret != ESP_OK)
	{
	    ESP_LOGE(TAG, "Failed to set promiscuous filter: %s", esp_err_to_name(ret));
	}

	// Enable promiscuous mode
	ESP_LOGI(TAG, "Enabling promiscuous mode...");
	ret = esp_wifi_set_promiscuous(true);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to enable promiscuous mode: %s", esp_err_to_name(ret));
		return;
	}

	ret = esp_wifi_set_channel(wifi_channel, WIFI_SECOND_CHAN_NONE); // Set the Wi-Fi channel
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to set WiFi channel: %s", esp_err_to_name(ret));
		return;
	}

	// Set callback upon receive
	ESP_LOGI(TAG, "Setting promiscuous RX callback...");
	ret = esp_wifi_set_promiscuous_rx_cb(wifi_promiscuous_handler);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to set promiscuous RX callback: %s", esp_err_to_name(ret));
		return;
	}

	ESP_LOGI(TAG, "Wi-Fi initialized in promiscuous mode successfully.");
}

void activate_wifi(void)
{
	esp_err_t ret;

	// Initialize TCP/IP stack
	ESP_LOGI(TAG, "Initializing TCP/IP stack...");
	ret = esp_netif_init();
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to initialize TCP/IP stack: %s", esp_err_to_name(ret));
		return;
	}

	// Initialize event loop
	ESP_LOGI(TAG, "Creating default event loop...");
	ret = esp_event_loop_create_default();
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to create default event loop: %s", esp_err_to_name(ret));
		return;
	}

	// Initialize Wi-Fi
	ESP_LOGI(TAG, "Initializing Wi-Fi...");
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ret = esp_wifi_init(&cfg);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to initialize Wi-Fi: %s", esp_err_to_name(ret));
		return;
	}

	// Set Wi-Fi to station mode
	ESP_LOGI(TAG, "Setting Wi-Fi mode to STA...");
	ret = esp_wifi_set_mode(WIFI_MODE_STA);
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to set Wi-Fi mode: %s", esp_err_to_name(ret));
		return;
	}

	// Start Wi-Fi
	ESP_LOGI(TAG, "Starting Wi-Fi...");
	ret = esp_wifi_start();
	if (ret != ESP_OK)
	{
		ESP_LOGE(TAG, "Failed to start Wi-Fi: %s", esp_err_to_name(ret));
		return;
	}

	ESP_LOGI(TAG, "Wi-Fi initialized in station mode successfully.");
}

void deactivate_wifi(void)
{
	esp_err_t ret;

	ESP_LOGI(TAG, "Deactivating Wi-Fi...");

	// Disable promiscuous mode
	ESP_LOGI(TAG, "Disabling promiscuous mode...");
	ret = esp_wifi_set_promiscuous(false);
	if (ret == ESP_OK)
	{
		ESP_LOGI(TAG, "Promiscuous mode disabled.");
	}
	else if (ret == ESP_ERR_WIFI_NOT_INIT)
	{
		ESP_LOGW(TAG, "Wi-Fi not initialized; skipping promiscuous mode deactivation.");
	}
	else
	{
		ESP_LOGE(TAG, "Failed to disable promiscuous mode: %s", esp_err_to_name(ret));
	}

	ret = esp_event_loop_delete_default();
	if (ret == ESP_OK)
	{
	    ESP_LOGI(TAG, "Default event loop deinitialized successfully.");
	}
	else if (ret == ESP_ERR_INVALID_STATE)
	{
	    ESP_LOGW(TAG, "Default event loop not created or already deinitialized.");
	}
	else
	{
	    ESP_LOGE(TAG, "Failed to deinitialize default event loop: %s", esp_err_to_name(ret));
	}

	// Stop Wi-Fi
	ESP_LOGI(TAG, "Stopping Wi-Fi...");
	ret = esp_wifi_stop();
	if (ret == ESP_OK)
	{
		ESP_LOGI(TAG, "Wi-Fi stopped.");
	}
	else
	{
		ESP_LOGE(TAG, "Failed to stop Wi-Fi: %s", esp_err_to_name(ret));
	}

	// Deinitialize Wi-Fi
	ESP_LOGI(TAG, "Deinitializing Wi-Fi...");
	ret = esp_wifi_deinit();
	if (ret == ESP_OK)
	{
		ESP_LOGI(TAG, "Wi-Fi deinitialized.");
	}
	else
	{
		ESP_LOGE(TAG, "Failed to deinitialize Wi-Fi: %s", esp_err_to_name(ret));
	}

	ESP_LOGI(TAG, "Wi-Fi deactivated successfully.");
}

// Function to parse supported rates from beacon response frame
void parse_supported_rates(const uint8_t *payload, int payload_len, char *rate_buffer, size_t buffer_size)
{
    const uint8_t *ie_ptr = payload + 36; // Start of Information Elements (after beacon frame header)
    int ie_len = payload_len - 36;       // Remaining length for Information Elements
    size_t offset = 0;

    while (ie_len > 2) // Each IE must have at least 2 bytes (ID + Length)
    {
        uint8_t ie_id = ie_ptr[0];        // Element ID
        uint8_t ie_len_field = ie_ptr[1]; // Length of the element
        const uint8_t *ie_data = ie_ptr + 2; // Pointer to the data of the element

        if (ie_id == 1) // Element ID 1 = Supported Rates
        {
            for (int i = 0; i < ie_len_field; i++)
            {
                uint8_t rate = ie_data[i] & 0x7F; // Mask out the top bit (basic rate flag)
                int written = snprintf(rate_buffer + offset, buffer_size - offset, "%d Mbps, ", rate / 2); // Rates are encoded as 2x actual Mbps
                if (written < 0 || written >= buffer_size - offset)
                {
                    ESP_LOGW(TAG, "Buffer size exceeded while formatting supported rates");
                    break; // Prevent buffer overflow
                }
                offset += written;
            }
            break; // Supported rates IE found, no need to continue
        }

        // Move to the next IE
        ie_ptr += 2 + ie_len_field; // Advance pointer (ID + Length + Data)
        ie_len -= (2 + ie_len_field);
    }

    // Remove the trailing comma and space
    if (offset >= 2)
    {
        rate_buffer[offset - 2] = '\0'; // Null-terminate the string
    }
    else
   {
        rate_buffer[0] = '\0'; // Handle case where no rates are found
    }
}


void scan_for_networks(wifi_ap_record_t *ap_info, uint16_t max_scan_list_size, uint16_t *ap_count)
{
    memset(ap_info, 0, sizeof(wifi_ap_record_t) * max_scan_list_size);

    ESP_ERROR_CHECK(esp_wifi_scan_start(NULL, true));

    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&max_scan_list_size, ap_info));

    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(ap_count));

    ESP_LOGI(TAG, "Total APs scanned = %u", *ap_count);

    for (int i = 0; (i < max_scan_list_size) && (i < *ap_count); i++)
    {
        ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
        ESP_LOGI(TAG, "BSSID \t\t%02x:%02x:%02x:%02x:%02x:%02x", ap_info[i].bssid[0], ap_info[i].bssid[1], ap_info[i].bssid[2], ap_info[i].bssid[3], ap_info[i].bssid[4], ap_info[i].bssid[5]);
        ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi); // In dBm
        ESP_LOGI(TAG, "Channel \t%d", ap_info[i].primary);
        ESP_LOGI(TAG, "Auth Mode \t%d", ap_info[i].authmode);
    }
}
