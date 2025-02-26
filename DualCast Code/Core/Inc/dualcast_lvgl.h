#ifndef DUALCAST_LVGL_H
#define DUALCAST_LVGL_H

#include "lvgl.h"
#include "vl53lx_api.h"

#define LCD_H_RES       240
#define LCD_V_RES       320

#define BYTES_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565))

#define LIDAR_FRAME_DELAY 200
#define WIFI_FRAME_DELAY 400
#define LIDAR_Y_COORD 45
#define LIDAR_X_COORD 5
#define WIFI_CHART_SIZE 100
#define MIN_RSSI -100
#define MAX_RSSI -40 // -26 technically max
#define MIN_SNR -20
#define MAX_SNR 10

#define LORA_BASE_VAL_OFFSET 28
#define LORA_SEND_VAL_OFFSET 55

#define MAX_LOG_LINES     6
#define MAX_LINE_LENGTH   400
#define MAX_BUFFER_SIZE   (MAX_LOG_LINES * MAX_LINE_LENGTH)

#define USER_DATA_FLASH_START  (0x081FE000UL) // Beginning of memory address allocated for user data
#define USER_DATA_FLASH_BANK   FLASH_BANK_2 // User data memory address in flash bank 2
#define USER_DATA_SECTOR_INDEX 127 // Since user memory in last page of bank 2 (of 128)
#define KEY_MAGIC  0xBEEFBEEF // Known value to compare

#define SCAN_SPACING -96

#define MAX_MACS 14
#define MAC_STR_SIZE 18

typedef struct {
    int uniqCount;
    char uniqMacs[MAX_MACS][MAC_STR_SIZE];
    int uniqRssi[MAX_MACS];
} UniqueData_t;


void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map);

void show_docs(lv_obj_t *scr);

void start_wifi_animation(lv_obj_t *img);
void wifi_page(lv_obj_t *scr);
void show_bme_wifi(char bme_data[]);
void update_adc_wifi(uint32_t adc_val);

void start_lidar_animation(lv_obj_t *img);
void lidar_page(lv_obj_t *scr);
void update_lidar_text(VL53LX_MultiRangingData_t *ranging_data_extract);
void update_lidar_d_text(int16_t dist_mm);

void beacon_page(lv_obj_t *scr);
void create_beacon_chart(lv_obj_t * chart);
void add_beacon_chart_value(lv_obj_t * chart, lv_chart_series_t * ser, int bar_value);
void beacon_log_append(lv_obj_t * log_label, const char * new_line);
void create_beacon_log(lv_obj_t * log_label);

void data_page(lv_obj_t *scr);
void update_unique_macs(lv_obj_t *scr, const UniqueData_t *data);
void create_data_chart(lv_obj_t * chart);
void add_data_chart_value(lv_obj_t * chart, lv_chart_series_t * ser, int32_t bar_value);
void create_data_log(lv_obj_t * log_label);
void data_log_append(lv_obj_t * log_label, const char * new_line);

void lora_page(lv_obj_t *scr);
void update_adc_lora(uint32_t adc_val);
void show_key(void);
void show_bme_lora(char bme_data[]);
void increment_selected_nibble(void);
void decrement_selected_nibble(void);
void increment_nibble_selected(void);
void values_to_send(lv_obj_t *scr, uint8_t val1, uint8_t val2, uint8_t val3, uint8_t val4);
void show_sending_receive_text(uint8_t payload[], size_t len, bool type);
void show_decrypted_text(uint8_t payload[]);
void create_rssi_snr_bars(lv_obj_t *scr);
void update_rssi_snr_bars(int rssi, int snr);

bool save_encryption_key_to_flash(void);
bool load_encryption_key_from_flash(void);

void scroll_scan(int dy);
void add_scan_to_page(char ssid[], char bssid[], int rssi, int channel, int auth_mode);
void show_network_selected_from_scan(uint8_t network_selected);

#endif
