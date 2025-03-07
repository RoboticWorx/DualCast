#include "lvgl.h"
#include "lv_timer.h"

#include "stm32h5xx_hal.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "dualcast_functions.h"
#include "dualcast_lvgl.h"
#include "app_freertos.h"
#include "st7789.h"

#include "vl53lx_api.h"

#include "lidar1.h"
#include "lidar2.h"
#include "lidar3.h"
#include "lidar4.h"
#include "lidar5.h"
#include "lidar6.h"
#include "lidar7.h"
#include "lidar8.h"
#include "lidar9.h"

#include "wifi1.h"
#include "wifi2.h"
#include "wifi3.h"
#include "wifi4.h"

#include "read_the_docs.h"

extern void ST7789_WriteData(uint8_t *buff, size_t buff_size);
extern void ST7789_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

extern int8_t network_selected;

lv_color_t beacon_bar_colors[WIFI_CHART_SIZE];

static lv_obj_t * lora_rssi_snr_chart = NULL;
static lv_chart_series_t * series_rssi = NULL;
static lv_chart_series_t * series_snr  = NULL;

static lv_obj_t *num_unique_macs_text;
static lv_obj_t *unique_macs_text;

static lv_obj_t * scanning_list;
static int network_scan_count = 1;
static bool key_hidden_text_hidden = false;

lv_obj_t * lora_snr_text_label;
lv_obj_t * lora_rssi_text_label;
lv_obj_t * selected_network_label;

static lv_obj_t * wifi_bme_text;
static lv_obj_t * lora_bme_text;

static lv_obj_t *val1_text;
static lv_obj_t *val2_text;
static lv_obj_t *val3_text;
static lv_obj_t *val4_text;

static lv_obj_t *default_key_text_top;
static lv_obj_t *default_key_text_bottom;

static lv_obj_t *rssi_active_text;
static lv_obj_t * lora_sending_label;
static lv_obj_t * decrypted_label;

static lv_obj_t *lidar_text;
static lv_obj_t *lidar_sigma_mil_text;
static lv_obj_t *lidar_ambient_rate_text;
static lv_obj_t *lidar_max_range_text;
static lv_obj_t *lidar_min_range_text;

static lv_obj_t *lora_adc_text;
static lv_obj_t *wifi_adc_text;

static const lv_img_dsc_t *lidar_frames[] =
{
    &lidar1, &lidar2, &lidar3, &lidar4,
    &lidar5, &lidar6, &lidar7, &lidar8, &lidar9
};

static const lv_img_dsc_t *wifi_frames[] =
{
    &wifi1, &wifi2, &wifi3, &wifi4
};

typedef struct {
    uint32_t magic;
    uint8_t  key[16];
    uint8_t  reserved[12];  // unused, just to align to 32 bytes
} key_data_t;

static lv_color_t core_colors[6];

static int frame_index = 0;
static int frame_index2 = 0;

static char beacon_log_lines[MAX_LOG_LINES][MAX_LINE_LENGTH];
static char data_log_lines[(MAX_LOG_LINES / 2)][MAX_LINE_LENGTH];

static uint8_t line_count = 0;  // Current number of valid lines
static uint8_t line_count2 = 0;
static uint8_t next_line = 0;   // Index where the next line will be stored
static uint8_t next_line2 = 0;

uint8_t encryption_key[16] = {0};
static int selected_index = 0;
static lv_obj_t * hex_labels[32];

static uint32_t scan_color_idx = 0;


void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map)
{
    lv_display_rotation_t rotation = lv_display_get_rotation(display);
    lv_area_t rotated_area = *area;

    if (rotation != LV_DISPLAY_ROTATION_0) {
        lv_color_format_t cf = lv_display_get_color_format(display);

        /* Rotate the area */
        lv_display_rotate_area(display, &rotated_area);

        /* Buffer for rotated pixels */
        static uint8_t rotated_buf[240 * 320 * 2];  // Adjust size based on resolution and color format

        /* Get stride */
        uint32_t src_stride = lv_draw_buf_width_to_stride(lv_area_get_width(area), cf);
        uint32_t dest_stride = lv_draw_buf_width_to_stride(lv_area_get_width(&rotated_area), cf);

        /* Rotate the buffer */
        lv_draw_sw_rotate(px_map, rotated_buf, lv_area_get_width(area), lv_area_get_height(area),
                          src_stride, dest_stride, rotation, cf);

        /* Use rotated area and buffer */
        area = &rotated_area;
        px_map = rotated_buf;
    }

    /* Calculate the width and height of the area to be updated */
    int32_t width = area->x2 - area->x1 + 1;
    int32_t height = area->y2 - area->y1 + 1;

    /* Set the address window to the area to be flushed */
    ST7789_SetAddressWindow(area->x1, area->y1, area->x2, area->y2);

    /* Send the pixel map directly to the display */
    ST7789_Select();
    ST7789_WriteData(px_map, width * height * 2);  // Send the rotated RGB565 buffer
    ST7789_UnSelect();

    /* Inform LVGL that flushing is complete */
    lv_display_flush_ready(display);
}

static float convert_adc_to_voltage(uint32_t adc_sum)
{
    // Convert averaged ADC value to voltage at the ADC input.
    float V_adc = (adc_sum / 4095.0f) * 3.3f;

    // Given a voltage divider with R_top = 2k and R_bottom = 5k,
    // the ADC sees: V_adc = V_in * (5k/(2k+5k)) = V_in * (5/7)
    float V_in = V_adc * (7.0f / 5.0f);

    return V_in;
}

void show_docs(lv_obj_t *scr) // Show "read the docs" QRs
{
    lv_obj_t *docs_img = lv_img_create(scr);
    lv_image_set_src(docs_img, &read_the_docs);
    lv_obj_align(docs_img, LV_ALIGN_CENTER, 0, 0);
}

static void lidar_animation_cb(lv_timer_t *timer)
{
    lv_obj_t *img = (lv_obj_t *)lv_timer_get_user_data(timer);

    /* Ensure a valid frame exists before updating */
    if (frame_index < sizeof(lidar_frames) / sizeof(lidar_frames[0]))
    {
        /* Clear the previous frame */
        lv_img_set_src(img, NULL);
        lv_obj_invalidate(img); // Ensures LVGL redraws the cleared area

        /* Set the new frame */
        lv_img_set_src(img, lidar_frames[frame_index]);
        lv_obj_invalidate(img); // Ensures LVGL redraws the new frame
    }

    frame_index++;
    if (frame_index >= sizeof(lidar_frames) / sizeof(lidar_frames[0]))
    {
        frame_index = 0;  // Loop back to the first frame
    }
}

void start_lidar_animation(lv_obj_t *img)
{
    frame_index = 0;
    lv_timer_t *timer = lv_timer_create(lidar_animation_cb, LIDAR_FRAME_DELAY, NULL);
    lv_timer_set_user_data(timer, img);
}

void lidar_page(lv_obj_t *scr)
{
	lidar_text = lv_label_create(scr); // Attach the label to the screen
	lv_label_set_text(lidar_text, " ");
	lv_obj_align(lidar_text, LV_ALIGN_TOP_MID, 0, 8); // Center the label
	lv_obj_set_style_text_color(lidar_text, lv_color_hex(0xFFFFFF), 0); // Fs are white
	lv_obj_set_style_text_font(lidar_text, &lv_font_montserrat_24, 0); // Font size
	lv_obj_set_style_text_opa(lidar_text, LV_OPA_COVER, 0); // Fully opaque text
	lv_obj_set_style_text_align(lidar_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_width(lidar_text, LCD_H_RES);

    lv_obj_t *lidar_anim = lv_img_create(scr);
    lv_obj_align(lidar_anim, LV_ALIGN_CENTER, 0, 60);
    start_lidar_animation(lidar_anim);

	lidar_ambient_rate_text = lv_label_create(scr);
	lv_label_set_text(lidar_ambient_rate_text, " ");
	lv_obj_align(lidar_ambient_rate_text, LV_ALIGN_TOP_LEFT, LIDAR_X_COORD, LIDAR_Y_COORD);
	lv_obj_set_style_text_color(lidar_ambient_rate_text, lv_color_hex(0xADD8E6), 0);
	lv_obj_set_style_text_font(lidar_ambient_rate_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(lidar_ambient_rate_text, LV_OPA_COVER, 0);
	lv_label_set_recolor(lidar_ambient_rate_text, true);
	lv_obj_set_width(lidar_ambient_rate_text, 220);

	lidar_sigma_mil_text = lv_label_create(scr);
	lv_label_set_text(lidar_sigma_mil_text, " ");
	lv_obj_align(lidar_sigma_mil_text, LV_ALIGN_TOP_LEFT, LIDAR_X_COORD, LIDAR_Y_COORD + 20);
	lv_obj_set_style_text_color(lidar_sigma_mil_text, lv_color_hex(0xADD8E6), 0);
	lv_obj_set_style_text_font(lidar_sigma_mil_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(lidar_sigma_mil_text, LV_OPA_COVER, 0);
	lv_label_set_recolor(lidar_sigma_mil_text, true);
	lv_obj_set_width(lidar_sigma_mil_text, 220);

	lidar_min_range_text = lv_label_create(scr);
	lv_label_set_text(lidar_min_range_text, " ");
	lv_obj_align(lidar_min_range_text, LV_ALIGN_TOP_LEFT, LIDAR_X_COORD, LIDAR_Y_COORD + 40);
	lv_obj_set_style_text_color(lidar_min_range_text, lv_color_hex(0xADD8E6), 0);
	lv_obj_set_style_text_font(lidar_min_range_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(lidar_min_range_text, LV_OPA_COVER, 0);
	lv_label_set_recolor(lidar_min_range_text, true);
	lv_obj_set_width(lidar_min_range_text, 220);

	lidar_max_range_text = lv_label_create(scr);
	lv_label_set_text(lidar_max_range_text, " ");
	lv_obj_align(lidar_max_range_text, LV_ALIGN_TOP_LEFT, LIDAR_X_COORD, LIDAR_Y_COORD + 60);
	lv_obj_set_style_text_color(lidar_max_range_text, lv_color_hex(0xADD8E6), 0);
	lv_obj_set_style_text_font(lidar_max_range_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(lidar_max_range_text, LV_OPA_COVER, 0);
	lv_label_set_recolor(lidar_max_range_text, true);
	lv_obj_set_width(lidar_max_range_text, 220);
}

void update_lidar_text(VL53LX_MultiRangingData_t *ranging_data_extract)
{
    char buf[36];

    // Amount of ambient light in mega counts per sec (MCPS). Measured as number of millions of photon detection events per sec
    float ambient_rate = (float)ranging_data_extract->RangeData[0].AmbientRateRtnMegaCps / 65536.0f; // Convert from 16.16 to float
    snprintf(buf, sizeof(buf), "AMBIENT_RATE: #228B22 %.4f mcps#", ambient_rate);
    lv_label_set_text(lidar_ambient_rate_text, buf);

    // Standard deviation in mm (tolerance)
    float sigma_mm = (float)ranging_data_extract->RangeData[0].SigmaMilliMeter / 65536.0f; // Convert from 16.16 to float
    snprintf(buf, sizeof(buf), "RANGING_TOL: #228B22 +/-%.2f mm#", sigma_mm);
    lv_label_set_text(lidar_sigma_mil_text, buf);

    snprintf(buf, sizeof(buf), "MIN_DIS_IN_ROI: #228B22 %hd cm#", (ranging_data_extract->RangeData[0].RangeMinMilliMeter) / 10);
    lv_label_set_text(lidar_min_range_text, buf);

    snprintf(buf, sizeof(buf), "MAX_DIS_IN_ROI: #228B22 %hd cm#", (ranging_data_extract->RangeData[0].RangeMaxMilliMeter) / 10);
    lv_label_set_text(lidar_max_range_text, buf);
}

void update_lidar_d_text(int16_t dist_mm)
{
    float dist_ft = ((float)dist_mm / 10.0f) * 0.032808399f; // Convert mm to ft

    char buf[32];
    snprintf(buf, sizeof(buf), "%.1f cm / %.2f ft", ((float)dist_mm / 10.0f), dist_ft);
    lv_label_set_text(lidar_text, buf);
}


static void wifi_animation_cb(lv_timer_t *timer)
{
    lv_obj_t *img = (lv_obj_t *)lv_timer_get_user_data(timer);

    /* Ensure a valid frame exists before updating */
    if (frame_index2 < sizeof(wifi_frames) / sizeof(wifi_frames[0]))
    {
        /* Clear the previous frame */
        lv_img_set_src(img, NULL);
        lv_obj_invalidate(img); // Ensures LVGL redraws the cleared area

        /* Set the new frame */
        lv_img_set_src(img, wifi_frames[frame_index2]);
        lv_obj_invalidate(img); // Ensures LVGL redraws the new frame
    }

    frame_index2++;
    if (frame_index2 >= sizeof(wifi_frames) / sizeof(wifi_frames[0]))
    {
        frame_index2 = 0;  // Loop back to the first frame
    }
}

void start_wifi_animation(lv_obj_t *img)
{
    frame_index2 = 0;
    lv_timer_t *timer = lv_timer_create(wifi_animation_cb, WIFI_FRAME_DELAY, NULL);
    lv_timer_set_user_data(timer, img);
}

void wifi_page(lv_obj_t *scr)
{
	lv_obj_t *wifi_text = lv_label_create(scr); // Attach the label to the screen
	lv_label_set_text(wifi_text, "WIFI_MODE"); // Set the label text
	lv_obj_align(wifi_text, LV_ALIGN_TOP_MID, 0, 8); // Center the label
	lv_obj_set_style_text_color(wifi_text, lv_color_hex(0xFFFFFF), 0); // Fs are white
	lv_obj_set_style_text_font(wifi_text, &lv_font_montserrat_24, 0); // Font size
	lv_obj_set_style_text_opa(wifi_text, LV_OPA_COVER, 0); // Fully opaque text

	lv_obj_t *any_button_text = lv_label_create(scr);
	lv_label_set_text(any_button_text, "Click any button above to begin.");
	lv_obj_align(any_button_text, LV_ALIGN_TOP_MID, 0, 40);
	lv_obj_set_style_text_color(any_button_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(any_button_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(any_button_text, LV_OPA_COVER, 0);

	wifi_adc_text = lv_label_create(scr);
	lv_obj_align(wifi_adc_text, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_color(wifi_adc_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(wifi_adc_text, &lv_font_montserrat_10, 0);
	lv_obj_set_style_text_align(wifi_adc_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_style_text_opa(wifi_text, LV_OPA_COVER, 0);
	lv_label_set_text(wifi_adc_text, " ");

	wifi_bme_text = lv_label_create(scr);
	lv_obj_align(wifi_bme_text, LV_ALIGN_CENTER, 0, -85);
	lv_obj_set_style_text_align(wifi_bme_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_style_text_color(wifi_bme_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(wifi_bme_text, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_opa(wifi_bme_text, LV_OPA_COVER, 0);

    lv_obj_t *wifi_anim = lv_img_create(scr);
    lv_obj_align(wifi_anim, LV_ALIGN_CENTER, 0, 40);
    start_wifi_animation(wifi_anim);
}

void update_adc_wifi(uint32_t adc_val)
{
	float voltage = convert_adc_to_voltage(adc_val);
	float percentage;

	// Clamp voltage to the valid range
	if (voltage <= 3.0f)
	    percentage = 0.0f;
	else if (voltage >= 4.2f)
	    percentage = 100.0f;
	else
	    percentage = ((voltage - 3.0f) * 100.0f) / (4.2f - 3.0f);


	if (percentage >= 70)
		lv_obj_set_style_text_color(wifi_adc_text, lv_color_hex(0x50C878), 0); // Green
	else if (percentage >= 30 && percentage < 70)
		lv_obj_set_style_text_color(wifi_adc_text, lv_color_hex(0xFDDA0D), 0); // Yellow
	else
		lv_obj_set_style_text_color(wifi_adc_text, lv_color_hex(0xD22B2B), 0); // Red

	char buf[32];
	snprintf(buf, sizeof(buf), "%.1f%%\n%.2fV", percentage, voltage);
	lv_label_set_text(wifi_adc_text, buf);
}

void show_bme_wifi(char bme_data[])
{
	lv_label_set_text(wifi_bme_text, bme_data);
}

static void draw_event_cb(lv_event_t * e)
{
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task);
    if(base_dsc->part != LV_PART_ITEMS) return;

    lv_draw_fill_dsc_t * fill_dsc = lv_draw_task_get_fill_dsc(draw_task);
    if(fill_dsc)
    {
        uint32_t index = base_dsc->id2;
        if(index < WIFI_CHART_SIZE) {
            fill_dsc->color = beacon_bar_colors[index];
        }
    }
}


void beacon_page(lv_obj_t *scr)
{
	lv_obj_t *beacon_frames_text = lv_label_create(scr);
	lv_label_set_text(beacon_frames_text, "BEACON_FRAMES");
	lv_obj_align(beacon_frames_text, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_color(beacon_frames_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(beacon_frames_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(beacon_frames_text, LV_OPA_COVER, 0);

	lv_obj_t *rssi_top_text = lv_label_create(scr);
	lv_label_set_text(rssi_top_text, "RSSI: -40");
	lv_obj_align(rssi_top_text, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_obj_set_style_text_color(rssi_top_text, lv_color_hex(0x50C878), 0);
	lv_obj_set_style_text_font(rssi_top_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(rssi_top_text, LV_OPA_COVER, 0);

	lv_obj_t *rssi_bottom_text = lv_label_create(scr);
	lv_label_set_text(rssi_bottom_text, "RSSI: -100");
	lv_obj_align(rssi_bottom_text, LV_ALIGN_TOP_LEFT, 0, 150);
	lv_obj_set_style_text_color(rssi_bottom_text, lv_color_hex(0xD22B2B), 0);
	lv_obj_set_style_text_font(rssi_bottom_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(rssi_bottom_text, LV_OPA_COVER, 0);

	rssi_active_text = lv_label_create(scr);
	lv_label_set_text(rssi_active_text, " ");
	lv_obj_align(rssi_active_text, LV_ALIGN_TOP_LEFT, 110, 150);
	lv_obj_set_style_text_color(rssi_active_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(rssi_active_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(rssi_active_text, LV_OPA_COVER, 0);

	lv_obj_t *live_beacon_frames_text = lv_label_create(scr);
	lv_label_set_text(live_beacon_frames_text, "LIVE_BEACON_FRAMES:");
	lv_obj_align(live_beacon_frames_text, LV_ALIGN_TOP_LEFT, 0, 170);
	lv_obj_set_style_text_color(live_beacon_frames_text, lv_color_hex(0x228B22), 0);
	lv_obj_set_style_text_font(live_beacon_frames_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(live_beacon_frames_text, LV_OPA_COVER, 0);
}

static void shift_beacon_bar_colors(void)
{
    for(uint32_t i = 0; i < WIFI_CHART_SIZE - 1; i++)
        beacon_bar_colors[i] = beacon_bar_colors[i + 1];
}

void add_beacon_chart_value(lv_obj_t * chart, lv_chart_series_t * ser, int bar_value)
{
	char rssi_val_active[32];
	snprintf(rssi_val_active, sizeof(rssi_val_active), "ACTIVE RSSI: %d", bar_value);
	lv_label_set_text(rssi_active_text, rssi_val_active);

	shift_beacon_bar_colors(); // Shift existing colors

	if (bar_value < MIN_RSSI)
		bar_value = MIN_RSSI;
	else if (bar_value > MAX_RSSI)
		bar_value = MAX_RSSI;

	// Calculate the gradient color for this value
	uint32_t ratio = (bar_value - MIN_RSSI) * 255 / (MAX_RSSI - MIN_RSSI);
	beacon_bar_colors[WIFI_CHART_SIZE - 1] = lv_color_mix(lv_palette_main(LV_PALETTE_GREEN),
	                                                lv_palette_main(LV_PALETTE_RED),
	                                                ratio);

	lv_chart_set_next_value(chart, ser, bar_value);
	lv_chart_refresh(chart);
}

void create_beacon_chart(lv_obj_t * chart)
{
    // Set chart type (Bar chart)
    lv_chart_set_type(chart, LV_CHART_TYPE_BAR);

    // Set chart size
    lv_obj_set_size(chart, LCD_H_RES, 125); // Chart width and height
    lv_obj_align(chart, LV_ALIGN_TOP_MID, 0, 20);

    lv_obj_set_style_bg_color(chart, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(chart, LV_SCROLLBAR_MODE_OFF);

    // Set number of points
    lv_chart_set_point_count(chart, WIFI_CHART_SIZE);

    // Set padding between bars
    lv_obj_set_style_pad_column(chart, 2, 0);

    // Set range (Y-axis min/max)
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, MIN_RSSI, MAX_RSSI);

    lv_obj_add_event_cb(chart, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(chart, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
}

void beacon_log_append(lv_obj_t * log_label, const char * new_line)
{
    // Copy the new line into the ring buffer at position 'next_line'
    strncpy(beacon_log_lines[next_line], new_line, MAX_LINE_LENGTH - 1);
    beacon_log_lines[next_line][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null termination

    // Update indices: move to the next slot and update the line count if needed.
    next_line = (next_line + 1) % MAX_LOG_LINES;
    if (line_count < MAX_LOG_LINES) {
        line_count++;
    }

    // Reassemble the log text in the correct order.
    // The oldest entry is at the current 'next_line' index.
    char log_text[MAX_BUFFER_SIZE] = "";
    uint8_t index = next_line; // This is the oldest log entry.
    for (uint8_t i = 0; i < line_count; i++)
    {
        strcat(log_text, beacon_log_lines[index]);
        strcat(log_text, "\n"); // Add a newline after each entry.
        index = (index + 1) % MAX_LOG_LINES;
    }

    // Update the label with the new log text.
    lv_label_set_text(log_label, log_text);
}

void create_beacon_log(lv_obj_t * log_label)
{
    // Create a new label as a child of the parent (which can be a screen or container)
    lv_label_set_text(log_label, "");  // Start with an empty log

    // Set a fixed size for the label. Adjust these values as needed.
    lv_obj_set_size(log_label, 240, 133);

    lv_obj_align(log_label, LV_ALIGN_TOP_LEFT, 0, 185);
	lv_obj_set_style_text_color(log_label, lv_color_hex(0x228B22), 0);
	lv_obj_set_style_text_font(log_label, &lv_font_montserrat_10, 0);
	lv_obj_set_style_text_opa(log_label, LV_OPA_COVER, 0);

    // Set long mode so text wraps within the label.
    lv_label_set_long_mode(log_label, LV_LABEL_LONG_WRAP);

    lv_obj_set_scrollbar_mode(log_label, LV_SCROLLBAR_MODE_OFF);
}


void data_page(lv_obj_t *scr)
{
	lv_obj_t *beacon_frames_text = lv_label_create(scr);
	lv_label_set_text(beacon_frames_text, "DATA_FRAMES");
	lv_obj_align(beacon_frames_text, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_color(beacon_frames_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(beacon_frames_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(beacon_frames_text, LV_OPA_COVER, 0);

	lv_obj_t *rssi_top_text = lv_label_create(scr);
	lv_label_set_text(rssi_top_text, "RSSI: -40");
	lv_obj_align(rssi_top_text, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_obj_set_style_text_color(rssi_top_text, lv_color_hex(0x50C878), 0);
	lv_obj_set_style_text_font(rssi_top_text, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_opa(rssi_top_text, LV_OPA_COVER, 0);

	lv_obj_t *rssi_bottom_text = lv_label_create(scr);
	lv_label_set_text(rssi_bottom_text, "RSSI: -100");
	lv_obj_align(rssi_bottom_text, LV_ALIGN_TOP_LEFT, 0, 150);
	lv_obj_set_style_text_color(rssi_bottom_text, lv_color_hex(0xD22B2B), 0);
	lv_obj_set_style_text_font(rssi_bottom_text, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_opa(rssi_bottom_text, LV_OPA_COVER, 0);

	num_unique_macs_text = lv_label_create(scr);
	lv_label_set_text(num_unique_macs_text, "> x <\nUNIQUE\nMAC(S):");
	lv_obj_align(num_unique_macs_text, LV_ALIGN_TOP_LEFT, 0, 175);
	lv_obj_set_style_text_align(num_unique_macs_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_style_text_color(num_unique_macs_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(num_unique_macs_text, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_opa(num_unique_macs_text, LV_OPA_COVER, 0);

	unique_macs_text = lv_label_create(scr);
	lv_label_set_text(unique_macs_text, " ");
	lv_obj_align(unique_macs_text, LV_ALIGN_TOP_RIGHT, 0, 150);
	lv_obj_set_style_text_color(unique_macs_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(unique_macs_text, &lv_font_montserrat_10, 0);
	lv_obj_set_style_text_opa(unique_macs_text, LV_OPA_COVER, 0);
	lv_obj_set_size(unique_macs_text, 181, 80);
	lv_obj_set_width(unique_macs_text, 181);
	//lv_label_set_long_mode(unique_macs_text, LV_LABEL_LONG_WRAP);
	lv_label_set_recolor(unique_macs_text, true);

	lv_obj_t *live_data_frames_text = lv_label_create(scr);
	lv_label_set_text(live_data_frames_text, "LIVE_DATA_FRAMES:");
	lv_obj_align(live_data_frames_text, LV_ALIGN_TOP_LEFT, 0, 236);
	lv_obj_set_style_text_color(live_data_frames_text, lv_color_hex(0x228B22), 0);
	lv_obj_set_style_text_font(live_data_frames_text, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(live_data_frames_text, LV_OPA_COVER, 0);
}

void update_unique_macs(lv_obj_t *scr, const UniqueData_t *data)
{
    char top_buf[32];
    snprintf(top_buf, sizeof(top_buf), "> %d <\nUNIQUE\nMAC(S):", data->uniqCount);
    lv_label_set_text(num_unique_macs_text, top_buf);

    // Define an array of 14 color codes (without the '#' prefix)
    const char *colors[] = {
        "2196F3", // LV_PALETTE_BLUE
        "4CAF50", // LV_PALETTE_GREEN
        "F44336", // LV_PALETTE_RED
        "9C27B0", // LV_PALETTE_PURPLE
        "FFEB3B", // LV_PALETTE_YELLOW
        "FF9800", // LV_PALETTE_ORANGE
        "00BCD4", // LV_PALETTE_CYAN
        "009688", // LV_PALETTE_TEAL
        "FFC107", // LV_PALETTE_AMBER
        "795548", // LV_PALETTE_BROWN
        "673AB7", // LV_PALETTE_DEEP_PURPLE
        "3F51B5", // LV_PALETTE_INDIGO
        "03A9F4", // LV_PALETTE_LIGHT_BLUE
        "8BC34A"  // LV_PALETTE_LIGHT_GREEN
    };
    const int color_count = sizeof(colors) / sizeof(colors[0]);

    char buf[512] = "";
    if (data->uniqCount < 15)
    {
		for (int i = 0; i < data->uniqCount; i++)
		{
			char mac_line[85];
			// Use the preset color if available; otherwise default to white.
			const char *col = (i < color_count) ? colors[i] : "FFFFFF";

			// Using the short LVGL markup syntax: "#<color> <text>#"
			snprintf(mac_line, sizeof(mac_line), "#%s %s#", col, data->uniqMacs[i]);
			strcat(buf, mac_line);
			if (i < data->uniqCount - 1)
			{
				// Insert a newline after every two MAC addresses.
				if ((i % 2) == 1)
				{
					strcat(buf, ",\n");
				}
				else
				{
					strcat(buf, ", ");
				}
			}
		}
		lv_label_set_text(unique_macs_text, buf);
    }
}

void create_data_chart(lv_obj_t * chart)
{
    // Set chart type (Bar chart)
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);

    // Set chart size
    lv_obj_set_size(chart, LCD_H_RES, 125); // Chart width and height
    lv_obj_align(chart, LV_ALIGN_TOP_MID, 0, 20);

    lv_obj_set_style_bg_color(chart, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(chart, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_line_width(chart, 2, LV_PART_ITEMS);
    //lv_obj_set_style_radius(chart, 0, LV_PART_INDICATOR);
    //lv_obj_set_style_bg_opa(chart, LV_OPA_TRANSP, LV_PART_INDICATOR);

    // Set number of points
    lv_chart_set_point_count(chart, WIFI_CHART_SIZE / 5);

    // Set padding between points
    lv_obj_set_style_pad_column(chart, 2, 0);

    // Set range (Y-axis min/max)
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, MIN_RSSI, MAX_RSSI);

    lv_obj_add_event_cb(chart, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(chart, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
}

void add_data_chart_value(lv_obj_t * chart, lv_chart_series_t * ser, int32_t line_value)
{

	lv_chart_set_next_value(chart, ser, line_value);
	lv_chart_refresh(chart);
}

void create_data_log(lv_obj_t * log_label)
{
    // Create a new label as a child of the parent (which can be a screen or container)
    lv_label_set_text(log_label, "");  // Start with an empty log

    // Set a fixed size for the label. Adjust these values as needed.
    lv_obj_set_size(log_label, 240, 66);

    lv_obj_align(log_label, LV_ALIGN_TOP_LEFT, 0, 251);
	lv_obj_set_style_text_color(log_label, lv_color_hex(0x228B22), 0);
	lv_obj_set_style_text_font(log_label, &lv_font_montserrat_10, 0);
	lv_obj_set_style_text_opa(log_label, LV_OPA_COVER, 0);

    // Set long mode so text wraps within the label.
    lv_label_set_long_mode(log_label, LV_LABEL_LONG_WRAP);

    lv_obj_set_scrollbar_mode(log_label, LV_SCROLLBAR_MODE_OFF);
}

void data_log_append(lv_obj_t * log_label, const char * new_line)
{
    // Copy the new line into the ring buffer at position 'next_line'
    strncpy(data_log_lines[next_line2], new_line, MAX_LINE_LENGTH - 1);
    data_log_lines[next_line2][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null termination

    // Update indices: move to the next slot and update the line count if needed.
    next_line2 = (next_line2 + 1) % (MAX_LOG_LINES / 2);
    if (line_count2 < (MAX_LOG_LINES / 2)) {
        line_count2++;
    }

    // Reassemble the log text in the correct order.
    // The oldest entry is at the current 'next_line' index.
    char log_text[MAX_BUFFER_SIZE] = "";
    uint8_t index = next_line2; // This is the oldest log entry.
    for (uint8_t i = 0; i < line_count2; i++)
    {
        strcat(log_text, data_log_lines[index]);
        strcat(log_text, "\n"); // Add a newline after each entry.
        index = (index + 1) % (MAX_LOG_LINES / 2);
    }

    // Update the label with the new log text.
    lv_label_set_text(log_label, log_text);
}


bool save_encryption_key_to_flash(void)
{
	// STEPS: Unlock > Erase > Write > Lock

    if (HAL_FLASH_Unlock() != HAL_OK) // Unlock flash
    {
        printf("Flash unlock failed!\n");
        return false;
    }

    FLASH_EraseInitTypeDef eraseInit = {0};
    eraseInit.TypeErase = FLASH_TYPEERASE_SECTORS; // Erasing
    eraseInit.Banks     = USER_DATA_FLASH_BANK;  // = FLASH_BANK_2
    eraseInit.Sector    = USER_DATA_SECTOR_INDEX; // = 127
    eraseInit.NbSectors = 1; // Only messing with one page (8KB)

    uint32_t sectorError = 0;
    HAL_StatusTypeDef status = HAL_FLASHEx_Erase(&eraseInit, &sectorError); // Perform erase
    if (status != HAL_OK) // If error
    {
        uint32_t errcode = HAL_FLASH_GetError();
        printf("Flash erase failed! status=%d, errcode=0x%lX\n", status, errcode);
        HAL_FLASH_Lock();
        return false;
    }

    // Prepare data in a 32-byte struct
    key_data_t temp;
    temp.magic = KEY_MAGIC;
    memcpy(temp.key, encryption_key, 16); // Copy key
    memset(temp.reserved, 0x00, 12);
    // MAGIC (4B) + Key (16B) + Padding (12B) = 32 bytes total

    // Write first 16 bytes to flash
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_QUADWORD, USER_DATA_FLASH_START, (uint32_t)&temp);

    if (status != HAL_OK)
    {
        printf("Flash program (1) failed! status=%d, err=0x%lX\n", status, HAL_FLASH_GetError());
        HAL_FLASH_Lock();
        return false;
    }

    // Write second 16 bytes to flash
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_QUADWORD, USER_DATA_FLASH_START + 16, (uint32_t)((uint8_t*)&temp + 16));

    if (status != HAL_OK)
    {
        printf("Flash program (2) failed! status=%d, err=0x%lX\n", status, HAL_FLASH_GetError());
        HAL_FLASH_Lock();
        return false;
    }

    HAL_FLASH_Lock(); // Lock flash back up when done
    return true;
}

bool load_encryption_key_from_flash(void)
{
    const key_data_t * pFlashData = (const key_data_t *) USER_DATA_FLASH_START; // Cast USER_FLASH address to pointer

    if (pFlashData->magic == KEY_MAGIC) // Check if sync word field matches
    {
        memcpy(encryption_key, pFlashData->key, 16); // Copy into encryption key global variable
        return true;
    }
    else
    {
        printf("Key load failed (magic mismatch)\n");
        return false;
    }
}


static void update_key_labels(void)
{
    for(int i = 0; i < 32; i++) // For all nibbles
    {
        uint8_t byte_idx = i / 2; // 16 bytes
        uint8_t which_half = i % 2; // Which half of byte
        uint8_t val = encryption_key[byte_idx];
        uint8_t nibble = (which_half == 0) ? (val >> 4) : (val & 0x0F); // Either top or bottom half

        char buf[2]; // Buffer to store
        snprintf(buf, sizeof(buf), "%1X", nibble); // Single hex digit
        lv_label_set_text(hex_labels[i], buf);

        if (i == selected_index)
        {
            lv_obj_set_style_text_color(hex_labels[i], lv_color_hex(0xD22B2B), 0);
        }
        else
        {
            lv_obj_set_style_text_color(hex_labels[i], lv_color_hex(0x4169E1), 0);
        }
    }
}

void increment_nibble_selected(void)
{
    if (selected_index < 31)
    {
        selected_index++;
        show_key();
    }
    else
    {
    	selected_index = 0;
    	show_key();
    }
}

void increment_selected_nibble(void)
{
    uint8_t byte_idx = selected_index / 2; // Which byte in encryption_key
    uint8_t which_half = selected_index % 2; // 0=high nibble, 1=low nibble

    uint8_t val = encryption_key[byte_idx];
    uint8_t hi = (val >> 4) & 0x0F; // High nibble
    uint8_t lo = (val & 0x0F); // Low nibble

    if (which_half == 0) // High nibble
    {
        hi = (hi + 1) & 0x0F; // Wrap from 0xF to 0x0
    }
    else // Low nibble
    {
        lo = (lo + 1) & 0x0F;
    }

    encryption_key[byte_idx] = (hi << 4) | lo;

    printf("Encryption key: ");
    for(int i = 0; i < 16; i++)
    {
        // Print each byte in two-digit hex format, e.g. "3F"
        printf("%02X", encryption_key[i]);
    }
    printf("\r\n");
    show_key();
}

void decrement_selected_nibble(void)
{
    uint8_t byte_idx = selected_index / 2;
    uint8_t which_half = selected_index % 2;

    uint8_t val = encryption_key[byte_idx];
    uint8_t hi = (val >> 4) & 0x0F; // High nibble
    uint8_t lo = (val & 0x0F); // Low nibble

    if (which_half == 0) // High nibble
    {
        hi = (hi == 0x00) ? 0x0F : (hi - 1);
    }
    else // Low nibble
    {
        lo = (lo == 0x00) ? 0x0F : (lo - 1);
    }

    encryption_key[byte_idx] = (hi << 4) | lo;
    show_key();
}

void lora_page(lv_obj_t *scr)
{
	lv_obj_t *lora_text = lv_label_create(scr); // Attach the label to the screen
	lv_label_set_text(lora_text, "LORA_MODE"); // Set the label text
	lv_obj_align(lora_text, LV_ALIGN_TOP_MID, 0, 0); // Center the label
	lv_obj_set_style_text_color(lora_text, lv_color_hex(0xFFFFFF), 0); // Fs are white
	lv_obj_set_style_text_font(lora_text, &lv_font_montserrat_24, 0); // Font size
	lv_obj_set_style_text_opa(lora_text, LV_OPA_COVER, 0); // Fully opaque text

	lora_bme_text = lv_label_create(lv_scr_act());
	lv_obj_align(lora_bme_text, LV_ALIGN_TOP_MID, 0, 27);
	lv_obj_set_style_text_align(lora_bme_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_style_text_color(lora_bme_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(lora_bme_text, &lv_font_montserrat_12, 0);
	lv_obj_set_style_text_opa(lora_bme_text, LV_OPA_COVER, 0);

	val1_text = lv_label_create(scr);
	lv_obj_align(val1_text, LV_ALIGN_BOTTOM_LEFT, LORA_BASE_VAL_OFFSET, -10);
	lv_obj_set_style_text_color(val1_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(val1_text, &lv_font_montserrat_24, 0);
	lv_obj_set_style_text_opa(val1_text, LV_OPA_COVER, 0);

	val2_text = lv_label_create(scr);
	lv_obj_align(val2_text, LV_ALIGN_BOTTOM_LEFT, LORA_BASE_VAL_OFFSET + LORA_SEND_VAL_OFFSET, -10);
	lv_obj_set_style_text_color(val2_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(val2_text, &lv_font_montserrat_24, 0);
	lv_obj_set_style_text_opa(val2_text, LV_OPA_COVER, 0);

	val3_text = lv_label_create(scr);
	lv_obj_align(val3_text, LV_ALIGN_BOTTOM_LEFT, LORA_BASE_VAL_OFFSET + (LORA_SEND_VAL_OFFSET * 2), -10);
	lv_obj_set_style_text_color(val3_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(val3_text, &lv_font_montserrat_24, 0);
	lv_obj_set_style_text_opa(val3_text, LV_OPA_COVER, 0);

	val4_text = lv_label_create(scr);
	lv_obj_align(val4_text, LV_ALIGN_BOTTOM_LEFT, LORA_BASE_VAL_OFFSET + (LORA_SEND_VAL_OFFSET * 3), -10);
	lv_obj_set_style_text_color(val4_text, lv_color_hex(0x6495ED), 0);
	lv_obj_set_style_text_font(val4_text, &lv_font_montserrat_24, 0);
	lv_obj_set_style_text_opa(val4_text, LV_OPA_COVER, 0);

    lora_sending_label = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(lora_sending_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(lora_sending_label, LV_ALIGN_LEFT_MID, 0, 75);
	lv_obj_set_style_text_font(lora_sending_label, &lv_font_montserrat_10, 0);
	lv_obj_set_width(lora_sending_label, 175);
	lv_label_set_text(lora_sending_label, " ");

	decrypted_label = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(decrypted_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(decrypted_label, LV_ALIGN_LEFT_MID, 0, 3);
	lv_obj_set_style_text_color(decrypted_label, lv_color_hex(0x58d68d), 0);
	lv_obj_set_style_text_font(decrypted_label, &lv_font_montserrat_12, 0);
	lv_obj_set_width(decrypted_label, 240);
	lv_label_set_text(decrypted_label, " ");

	lora_rssi_text_label = lv_label_create(lv_scr_act());
	lv_obj_align(lora_rssi_text_label, LV_ALIGN_BOTTOM_RIGHT, -39, -115);
	lv_obj_set_style_text_color(lora_rssi_text_label, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(lora_rssi_text_label, &lv_font_montserrat_10, 0);
	lv_label_set_text(lora_rssi_text_label, " ");

	lora_snr_text_label = lv_label_create(lv_scr_act());
	lv_obj_align(lora_snr_text_label, LV_ALIGN_BOTTOM_RIGHT, -17, -115);
	lv_obj_set_style_text_color(lora_snr_text_label, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(lora_snr_text_label, &lv_font_montserrat_10, 0);
	lv_label_set_text(lora_snr_text_label, " ");

	lora_adc_text = lv_label_create(lv_scr_act());
	lv_obj_align(lora_adc_text, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_color(lora_adc_text, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(lora_adc_text, &lv_font_montserrat_10, 0);
	lv_obj_set_style_text_align(lora_adc_text, LV_TEXT_ALIGN_CENTER, 0);
	lv_label_set_text(lora_adc_text, " ");

    lv_obj_t *container = lv_obj_create(scr);
    lv_obj_set_size(container, 240, 80);
    lv_obj_align(container, LV_ALIGN_CENTER, 0, -57);

    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_bg_color(container, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_pad_column(container, 1, 0);

    for(int i = 0; i < 32; i++)
    {
        hex_labels[i] = lv_label_create(container);
        lv_obj_set_width(hex_labels[i], 12);
        lv_label_set_text(hex_labels[i], "F");
        lv_obj_set_style_text_font(hex_labels[i], &lv_font_montserrat_18, 0);
    }

	// Default text over hidden key.
    key_hidden_text_hidden = false;
	default_key_text_top = lv_label_create(scr);
	lv_obj_align(default_key_text_top, LV_ALIGN_CENTER, 0, -68);
	lv_obj_set_style_text_color(default_key_text_top, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(default_key_text_top, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(default_key_text_top, LV_OPA_COVER, 0);
	lv_label_set_text(default_key_text_top, "Encryption key hidden.");
	default_key_text_bottom = lv_label_create(scr);
	lv_obj_align(default_key_text_bottom, LV_ALIGN_CENTER, 0, -48);
	lv_obj_set_style_text_color(default_key_text_bottom, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(default_key_text_bottom, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_opa(default_key_text_bottom, LV_OPA_COVER, 0);
	lv_label_set_text(default_key_text_bottom, "Click to view/edit.");
}

void update_adc_lora(uint32_t adc_val)
{
	float voltage = convert_adc_to_voltage(adc_val);
	float percentage;

	// Clamp voltage to the valid range
	if (voltage <= 3.0f)
	    percentage = 0.0f;
	else if (voltage >= 4.2f)
	    percentage = 100.0f;
	else
	    percentage = ((voltage - 3.0f) * 100.0f) / (4.2f - 3.0f);


	if (percentage >= 70)
		lv_obj_set_style_text_color(lora_adc_text, lv_color_hex(0x50C878), 0); // Green
	else if (percentage >= 30 && percentage < 70)
		lv_obj_set_style_text_color(lora_adc_text, lv_color_hex(0xFDDA0D), 0); // Yellow
	else
		lv_obj_set_style_text_color(lora_adc_text, lv_color_hex(0xD22B2B), 0); // Red

	char buf[32];
	snprintf(buf, sizeof(buf), "%.1f%%\n%.2fV", percentage, voltage);
	lv_label_set_text(lora_adc_text, buf);
}

void show_key(void)
{
	if (!key_hidden_text_hidden) // Only hide "key hidden" text if it's not already hidden
	{
		lv_label_set_text(default_key_text_top, "");
		lv_label_set_text(default_key_text_bottom, "");
		key_hidden_text_hidden = true;
	}

	update_key_labels();
}

void show_bme_lora(char bme_data[])
{

	lv_label_set_text(lora_bme_text, bme_data);
}

void values_to_send(lv_obj_t *scr, uint8_t val1, uint8_t val2, uint8_t val3, uint8_t val4)
{
    char val1_buf[8];
    snprintf(val1_buf, sizeof(val1_buf), "%u", val1);
    char val2_buf[8];
    snprintf(val2_buf, sizeof(val2_buf), "%u", val2);
    char val3_buf[8];
    snprintf(val3_buf, sizeof(val3_buf), "%u", val3);
    char val4_buf[8];
    snprintf(val4_buf, sizeof(val4_buf), "%u", val4);

	lv_label_set_text(val1_text, val1_buf);

	lv_label_set_text(val2_text, val2_buf);

	lv_label_set_text(val3_text, val3_buf);

	lv_label_set_text(val4_text, val4_buf);
}

void show_sending_receive_text(uint8_t payload[], size_t len, bool type)
{
    const char * prefix;
    if (type)
    	prefix = "Sending: ";
    else
    	prefix = "Received: ";

    size_t buf_size = strlen(prefix) + (len * 3) + 1; // 2 bytes hex + 1 space
    char hex_buf[buf_size];

    int pos = snprintf(hex_buf, buf_size, "%s", prefix); // Copy prefix

    for (size_t i = 0; i < len; i++) // Append each in hex
    {
        pos += snprintf(&hex_buf[pos], buf_size - pos, "%02X ", payload[i]);
    }

	if (type) // If sending
		lv_obj_set_style_text_color(lora_sending_label, lv_color_hex(0x0F52BA), 0);
	else
		lv_obj_set_style_text_color(lora_sending_label, lv_color_hex(0x228B22), 0);


	lv_label_set_text(lora_sending_label, hex_buf);

	//lv_obj_del(lora_sending_label);
}

void show_decrypted_text(uint8_t payload[])
{
	char decrypt_buf[CYPHERTEXT_LENGTH + 11]; // + "Decrypted: "
	snprintf(decrypt_buf, sizeof(decrypt_buf), "Decrypted: %s", payload);

	lv_label_set_text(decrypted_label, decrypt_buf);
}

static void lora_draw_event_cb(lv_event_t * e)
{
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task);

    if(base_dsc->part != LV_PART_ITEMS) // Only applies to bars
    {
        return;
    }

    lv_draw_fill_dsc_t * fill_dsc = lv_draw_task_get_fill_dsc(draw_task);

    if(fill_dsc)
    {
        lv_obj_t * chart = lv_event_get_target(e); // Get chart object

        uint32_t series_id = base_dsc->id1; // If id1 == 1, it's the SNR series, if id1 == 0, it's the RSSI series
        lv_chart_series_t * series = NULL;
        if(series_id == 0)
        {
            series = series_rssi; // Global pointer for RSSI series
        }
        else if(series_id == 1)
        {
            series = series_snr;  // Global pointer for SNR series
        }
        else
        {
            series = lv_chart_get_series_next(chart, NULL); // Default to first if other
        }

        int32_t * y_array = lv_chart_get_y_array(chart, series); // Get the y value
        int32_t v = y_array[base_dsc->id2];

        uint32_t ratio = (uint32_t)((v - MIN_RSSI) * 255 / (MAX_RSSI - MIN_RSSI)); // Map to 0-255

        // Apply color mixing
        if(series_id == 0) // RSSI
        {
            fill_dsc->color = lv_color_mix(lv_palette_main(LV_PALETTE_GREEN),
                                           lv_palette_main(LV_PALETTE_RED),
                                           ratio);
        }
        else if(series_id == 1) // SNR
        {
            fill_dsc->color = lv_color_mix(lv_palette_main(LV_PALETTE_GREEN),
                                           lv_palette_main(LV_PALETTE_PURPLE),
                                           ratio);
        }
    }
}

void create_rssi_snr_bars(lv_obj_t * scr)
{
	// Create chart and settings
    lora_rssi_snr_chart = lv_chart_create(scr);
    lv_chart_set_type(lora_rssi_snr_chart, LV_CHART_TYPE_BAR);
    lv_obj_set_size(lora_rssi_snr_chart, 50, 70);
    lv_obj_align(lora_rssi_snr_chart, LV_ALIGN_BOTTOM_RIGHT, -10, -45);
    lv_obj_set_style_bg_color(lora_rssi_snr_chart, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(lora_rssi_snr_chart, LV_SCROLLBAR_MODE_OFF);

    lv_chart_set_point_count(lora_rssi_snr_chart, 1); // 1 bar per series

    lv_obj_set_style_pad_column(lora_rssi_snr_chart, 10, 0); // 10px padding

    lv_chart_set_range(lora_rssi_snr_chart, LV_CHART_AXIS_PRIMARY_Y, MIN_RSSI, MAX_RSSI); // Min and max on y-axis

    lv_obj_add_event_cb(lora_rssi_snr_chart, lora_draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL); // Color the bars
    lv_obj_add_flag(lora_rssi_snr_chart, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    series_rssi = lv_chart_add_series(lora_rssi_snr_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    series_snr  = lv_chart_add_series(lora_rssi_snr_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);

    lv_chart_set_next_value(lora_rssi_snr_chart, series_rssi, MIN_RSSI); // Default values
    lv_chart_set_next_value(lora_rssi_snr_chart, series_snr, MIN_RSSI);

    lv_chart_refresh(lora_rssi_snr_chart);

    // RSSI text
	lv_obj_t * rssi_label = lv_label_create(scr);
	lv_obj_align(rssi_label, LV_ALIGN_BOTTOM_RIGHT, -39, -124);
	lv_obj_set_style_text_color(rssi_label, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(rssi_label, &lv_font_montserrat_10, 0);
	lv_label_set_text(rssi_label, "RSSI");

    // SNR text
	lv_obj_t * snr_label = lv_label_create(scr);
	lv_obj_align(snr_label, LV_ALIGN_BOTTOM_RIGHT, -10, -124);
	lv_obj_set_style_text_color(snr_label, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(snr_label, &lv_font_montserrat_10, 0);
	lv_label_set_text(snr_label, "SNR");
}

void update_rssi_snr_bars(int rssi, int snr)
{
	int bar_snr = int_map(snr, MIN_SNR, MAX_SNR, MIN_RSSI, MAX_RSSI); // Map to RSSI range for chart equivalence

    if (lora_rssi_snr_chart != NULL && series_rssi != NULL && series_snr != NULL)
    {
        lv_chart_set_next_value(lora_rssi_snr_chart, series_rssi, rssi);
        lv_chart_set_next_value(lora_rssi_snr_chart, series_snr, bar_snr);

        static char rssi_buf[5];
        static char snr_buf[5];
        snprintf(rssi_buf, sizeof(rssi_buf), "%d", rssi);
        snprintf(snr_buf, sizeof(snr_buf), "%d", snr);

        // RSSI text
    	lv_label_set_text(lora_rssi_text_label, rssi_buf);

        // SNR text
    	lv_label_set_text(lora_snr_text_label, snr_buf);
    }
}



static void create_scanning_list(lv_obj_t * parent)
{
	// Assign colors to choose from for networks
    core_colors[0] = lv_palette_main(LV_PALETTE_RED);
    core_colors[1] = lv_palette_main(LV_PALETTE_BLUE);
    core_colors[2] = lv_palette_main(LV_PALETTE_GREEN);
    core_colors[3] = lv_palette_main(LV_PALETTE_ORANGE);
    core_colors[4] = lv_palette_main(LV_PALETTE_PURPLE);
    core_colors[5] = lv_palette_main(LV_PALETTE_YELLOW);

    selected_network_label = lv_label_create(lv_scr_act()); // Initialize for show_network_selected_from_scan
    lv_obj_add_flag(selected_network_label, LV_OBJ_FLAG_HIDDEN);

    if(scanning_list == NULL) // If not already created
    {
        scanning_list = lv_list_create(parent); // Create list

        // Set settings
        lv_obj_set_style_bg_color(scanning_list, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_scrollbar_mode(scanning_list, LV_SCROLLBAR_MODE_AUTO);
        lv_obj_align(scanning_list, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_size(scanning_list, 240, 320);
        //lv_obj_set_style_border_color(scanning_list, lv_color_hex(0x0F52BA), LV_PART_MAIN);
        lv_obj_set_style_border_width(scanning_list, 0, 0);
        lv_obj_set_style_pad_top(scanning_list, 7, LV_PART_MAIN); // 7px top padding

        lv_obj_t * scrl = lv_obj_get_child(scanning_list, 0); // Get child item
        if(scrl != NULL)
        {
            lv_obj_set_style_bg_color(scrl, lv_color_black(), LV_PART_MAIN); // Format child
        }
    }
}

void scroll_scan(int dy)
{
	lv_obj_scroll_by(scanning_list, 0, dy, LV_ANIM_ON); // Scroll by distance y
}

void add_scan_to_page(char ssid[], char bssid[], int rssi, int channel, int auth_mode) // Append scan
{
    // Create the scanning list if it doesn't exist
    create_scanning_list(lv_scr_act());

    // Create a buffer that holds all the network information in one line
    char info_buf[128];
    snprintf(info_buf, sizeof(info_buf), "Network No. %d\nSSID: %s\nBSSID: %s\nRSSI: %d\nCh: %d\nAuth: %d",
    		network_scan_count, ssid, bssid, rssi, channel, auth_mode);

    // Add the text item and capture the returned object
    lv_obj_t * text_item = lv_list_add_text(scanning_list, info_buf);

    // Format the text item
    lv_obj_set_style_bg_color(text_item, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_text_color(text_item, core_colors[scan_color_idx], LV_PART_MAIN);
    lv_obj_set_style_text_font(text_item, &lv_font_montserrat_14, 0);

    if (scan_color_idx >= 5) // Loop around
    	scan_color_idx = 0;
    else
    	scan_color_idx++;

    network_scan_count++;
}

void show_network_selected_from_scan(uint8_t network_selected)
{
	lv_obj_clear_flag(selected_network_label, LV_OBJ_FLAG_HIDDEN);

	static char selected_buf[4];
	snprintf(selected_buf, sizeof(selected_buf), "%d", network_selected);

	lv_obj_align(selected_network_label, LV_ALIGN_TOP_RIGHT, -12, 10);
	lv_obj_set_style_text_color(selected_network_label, lv_color_hex(0xFFFFFF), 0);
	lv_obj_set_style_text_font(selected_network_label, &lv_font_montserrat_24, 0);
	lv_label_set_text(selected_network_label, selected_buf);
}
