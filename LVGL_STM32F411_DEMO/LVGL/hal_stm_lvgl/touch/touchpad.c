/*
 * touchpad.c
 *
 *  Created on: Sep 5, 2021
 *      Author: paulo
 */

/**
 * @file indev.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "hal_stm_lvgl/tft/tft.h"
#include "lvgl/lvgl.h"

#include "main.h"

#include "xpt2046.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static _Bool touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize your input devices here
 */
void touchpad_init(void)
{
	XPT2046_Init();
	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.read_cb = touchpad_read;
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	lv_indev_drv_register(&indev_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Read an input device
 * @param indev_id id of the input device to read
 * @param x put the x coordinate here
 * @param y put the y coordinate here
 * @return true: the device is pressed, false: released
 */
static _Bool touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t *data)
{
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    uint16_t x = 0;
    uint16_t y = 0;
    uint8_t irq = XPT2046_Irq_Read();

    if (irq == 0) {
        XPT2046_Get_Touch_XY(&x, &y, 1);
        XPT2046_Corr(&x, &y);
        data->point.x = x;
        data->point.y = y;
		last_x = data->point.x;
		last_y = data->point.y;
        data->state = LV_INDEV_STATE_PR;
    }
    else
    {
		data->point.x = last_x;
		data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }
    return false;
}

