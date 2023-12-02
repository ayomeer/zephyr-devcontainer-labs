/*******************************************************************************
 *  _____       ______   ____
 * |_   _|     |  ____|/ ____|  Institute of Embedded Systems
 *   | |  _ __ | |__  | (___    Zurich University of Applied Sciences
 *   | | | '_ \|  __|  \___ \   8401 Winterthur, Switzerland
 *  _| |_| | | | |____ ____) |
 * |_____|_| |_|______|_____/
 *
 *******************************************************************************
 *
 * Display handler for Zephyr OS demo application.
 * Does setup of display and widgets on display. Provides various functions
 * to interact with the display with minimal effort:
 *  - Pass data to chart and refresh
 *  - Pass data to "values" and display text
 *  - Pass information about switch state to display
 *
 ******************************************************************************/

#include <lvgl.h>
#include <math.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/zephyr.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(display);

#include "display.h"

K_MUTEX_DEFINE(lvgl_mutex);

#define PI 3.141592

#define REFRESH_THREAD_PRIO 0
#define REFRESH_THREAD_STACKSIZE 2048

struct coordinates {
	uint16_t x;
	uint16_t y;
};

static lv_obj_t *title_label;
static lv_obj_t *phil_labels[CONFIG_NUM_PHIL];
static lv_obj_t *phil_eat_count_labels[CONFIG_NUM_PHIL];
static lv_obj_t *table;
static lv_obj_t *phils[CONFIG_NUM_PHIL];
static lv_obj_t *thinking_indicator[CONFIG_NUM_PHIL];

static lv_color_t gray = (lv_color_t)LV_COLOR_MAKE(150, 124, 38);
struct coordinates table_pos = {.x = 180, .y = 140};
static uint16_t radius = 60;
static uint16_t phil_size = 40;
static uint16_t chopstick_size = 20;

static lv_color_t phil_colors[] = {
    (lv_color_t)LV_COLOR_MAKE(255, 240, 0),   /* orange */
    (lv_color_t)LV_COLOR_MAKE(255, 0, 230),   /* red */
    (lv_color_t)LV_COLOR_MAKE(0, 255, 0),     /* green */
    (lv_color_t)LV_COLOR_MAKE(255, 255, 0),   /* yellow */
    (lv_color_t)LV_COLOR_MAKE(0, 240, 255),   /* blue */
    (lv_color_t)LV_COLOR_MAKE(240, 127, 127), /* dark red */
    (lv_color_t)LV_COLOR_MAKE(0, 240, 0),     /* dark green */
    (lv_color_t)LV_COLOR_MAKE(0, 0, 240),     /* dark blue */
    (lv_color_t)LV_COLOR_MAKE(255, 240, 0),   /* orange */
    (lv_color_t)LV_COLOR_MAKE(255, 0, 230),   /* red */
    (lv_color_t)LV_COLOR_MAKE(0, 255, 0),     /* green */
    (lv_color_t)LV_COLOR_MAKE(255, 255, 0),   /* yellow */
    (lv_color_t)LV_COLOR_MAKE(0, 240, 255),   /* blue */
    (lv_color_t)LV_COLOR_MAKE(240, 127, 127), /* dark red */
    (lv_color_t)LV_COLOR_MAKE(0, 240, 0),     /* dark green */
    (lv_color_t)LV_COLOR_MAKE(0, 0, 240),     /* dark blue */
};

BUILD_ASSERT(ARRAY_SIZE(phil_colors) >= CONFIG_NUM_PHIL,
             "Not enough philosopher colors");

static lv_obj_t *chopsticks[CONFIG_NUM_PHIL];
static lv_color_t chopstick_color = (lv_color_t)LV_COLOR_MAKE(255, 255, 255);

const struct device *display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

void display_init()
{
	if (!device_is_ready(display_dev)) {
		LOG_ERR("display device not ready");
		return;
	}

	k_mutex_lock(&lvgl_mutex, K_FOREVER);

	/*
	 * Create title
	 * Label for Thread Number is static
	 */

	/* Create title style (bigger and underlined)*/
	static lv_style_t title_style;
	lv_style_init(&title_style);
	lv_style_set_text_font(&title_style, &lv_font_montserrat_18);
	lv_style_set_text_decor(&title_style, LV_TEXT_DECOR_UNDERLINE);

	/* Title label */
	title_label = lv_label_create(lv_scr_act());
	lv_obj_add_style(title_label, &title_style, 0);

	/* Position and Text of title label */
	lv_obj_set_pos(title_label, 60, 20);
	lv_label_set_text(title_label, "Dining Philosophers:");

	/* Table */
	table = lv_obj_create(lv_scr_act());
	lv_obj_set_scrollbar_mode(table, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_size(table, 60, 60);
	lv_obj_set_pos(table, table_pos.x - 60 / 2, table_pos.y - 60 / 2);
	lv_obj_set_style_bg_color(table, gray, 0);
	lv_obj_set_style_radius(table, LV_RADIUS_CIRCLE, 0);

	for (uint8_t n = 0; n < CONFIG_NUM_PHIL; ++n) {
		float angle;

		/* Static labels for philosophers */
		phil_labels[n] = lv_label_create(lv_scr_act());

		/* Position and text of static thread labels */
		lv_obj_set_pos(phil_labels[n], 5,
		               45 + 200 / CONFIG_NUM_PHIL * n);
		char lable_text[4];
		snprintk(lable_text, ARRAY_SIZE(lable_text), "P%d:", n);
		lv_label_set_text(phil_labels[n], lable_text);

		/* Create and position labels for philosopher eat count */
		phil_eat_count_labels[n] = lv_label_create(lv_scr_act());
		lv_obj_set_pos(phil_eat_count_labels[n], 35,
		               45 + 200 / CONFIG_NUM_PHIL * n);

		/* Set default eat count value */
		lv_label_set_text_fmt(phil_eat_count_labels[n], "%d", 0);

		/* Philosopher */
		angle = (float)n * 2 * PI / CONFIG_NUM_PHIL;
		struct coordinates phil_pos = {
		    .x = table_pos.x + cos(angle) * radius,
		    .y = table_pos.y + sin(angle) * radius};
		phils[n] = lv_obj_create(lv_scr_act());
		lv_obj_move_background(phils[n]);
		lv_obj_set_scrollbar_mode(phils[n], LV_SCROLLBAR_MODE_OFF);
		lv_obj_set_size(phils[n], phil_size, phil_size);
		lv_obj_set_pos(phils[n], phil_pos.x - (phil_size / 2),
		               phil_pos.y - (phil_size / 2));
		lv_obj_set_style_bg_color(phils[n], phil_colors[n], 0);
		lv_obj_set_style_radius(phils[n], LV_RADIUS_CIRCLE, 0);

		/* Chopstick */
		angle += PI / CONFIG_NUM_PHIL;
		struct coordinates chopstick_pos = {
		    .x = table_pos.x + cos(angle) * radius * .8,
		    .y = table_pos.y + sin(angle) * radius * .8};
		chopsticks[n] = lv_obj_create(lv_scr_act());
		lv_obj_set_scrollbar_mode(chopsticks[n], LV_SCROLLBAR_MODE_OFF);
		lv_obj_set_size(chopsticks[n], chopstick_size, chopstick_size);
		lv_obj_set_pos(chopsticks[n],
		               chopstick_pos.x - (chopstick_size / 2),
		               chopstick_pos.y - (chopstick_size / 2));
		lv_obj_set_style_bg_color(chopsticks[n], chopstick_color, 0);
		lv_obj_set_style_radius(chopsticks[n], LV_RADIUS_CIRCLE, 0);

		/* Thinking indicator */
		thinking_indicator[n] = lv_obj_create(lv_scr_act());
		lv_obj_remove_style_all(thinking_indicator[n]);
		lv_obj_set_pos(thinking_indicator[n],
		               phil_pos.x - (phil_size / 2),
		               phil_pos.y - (phil_size / 2));
		lv_obj_set_size(thinking_indicator[n], phil_size, phil_size);
		lv_obj_add_flag(thinking_indicator[n], LV_OBJ_FLAG_HIDDEN);
		lv_obj_t *dot;
		dot = lv_obj_create(thinking_indicator[n]);
		lv_obj_set_size(dot, 3, 3);
		lv_obj_set_pos(dot, phil_size / 2 - 6 - 1, phil_size / 2 - 1);
		lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, 0);
		lv_obj_set_style_border_width(dot, 0, 0);
		lv_obj_set_style_bg_color(dot, gray, 0);
		dot = lv_obj_create(thinking_indicator[n]);
		lv_obj_set_size(dot, 3, 3);
		lv_obj_set_pos(dot, phil_size / 2 - 1, phil_size / 2 - 1);
		lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, 0);
		lv_obj_set_style_border_width(dot, 0, 0);
		lv_obj_set_style_bg_color(dot, gray, 0);
		dot = lv_obj_create(thinking_indicator[n]);
		lv_obj_set_size(dot, 3, 3);
		lv_obj_set_pos(dot, phil_size / 2 + 6 - 1, phil_size / 2 - 1);
		lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, 0);
		lv_obj_set_style_border_width(dot, 0, 0);
		lv_obj_set_style_bg_color(dot, gray, 0);
	}

	display_blanking_off(display_dev);

	k_mutex_unlock(&lvgl_mutex);

	return;
}

int display_eat_count(uint8_t n, uint16_t count)
{
	if (n >= CONFIG_NUM_PHIL) {
		LOG_ERR("ERROR, invalid philosopher");
		return -1;
	}

	k_mutex_lock(&lvgl_mutex, K_FOREVER);
	lv_label_set_text_fmt(phil_eat_count_labels[n], "%d", count);
	k_mutex_unlock(&lvgl_mutex);

	return 0;
}

int display_thinking(uint8_t n, bool is_thinking)
{
	if (n >= CONFIG_NUM_PHIL) {
		LOG_ERR("ERROR, invalid philosopher");
		return -1;
	}

	k_mutex_lock(&lvgl_mutex, K_FOREVER);
	if (is_thinking) {
		lv_obj_clear_flag(thinking_indicator[n], LV_OBJ_FLAG_HIDDEN);
	} else {
		lv_obj_add_flag(thinking_indicator[n], LV_OBJ_FLAG_HIDDEN);
	}
	k_mutex_unlock(&lvgl_mutex);

	return 0;
}

int display_claim_chopstick(uint8_t n, uint8_t chopstick_id)
{
	if (chopstick_id >= CONFIG_NUM_PHIL || n >= CONFIG_NUM_PHIL) {
		LOG_ERR("ERROR, invalid chopstick or philosopher");
		return -1;
	}

	k_mutex_lock(&lvgl_mutex, K_FOREVER);
	lv_obj_set_style_bg_color(chopsticks[chopstick_id], phil_colors[n], 0);
	k_mutex_unlock(&lvgl_mutex);

	return 0;
}

int display_release_chopstick(uint8_t n, uint8_t chopstick_id)
{
	if (chopstick_id >= CONFIG_NUM_PHIL || n >= CONFIG_NUM_PHIL) {
		LOG_ERR("ERROR, invalid chopstick or philosopher");
		return -1;
	}

	k_mutex_lock(&lvgl_mutex, K_FOREVER);
	lv_obj_set_style_bg_color(chopsticks[chopstick_id], chopstick_color, 0);
	k_mutex_unlock(&lvgl_mutex);

	return 0;
}

static void refresh(void *p1, void *p2, void *p3)
{
	uint32_t time_till_next;
	while (true) {
		k_mutex_lock(&lvgl_mutex, K_FOREVER);
		time_till_next = lv_task_handler();
		k_mutex_unlock(&lvgl_mutex);
		k_msleep(100);
	}
}
K_THREAD_DEFINE(display_refresh, REFRESH_THREAD_STACKSIZE, refresh, NULL, NULL,
                NULL, REFRESH_THREAD_PRIO, 0, 0);
