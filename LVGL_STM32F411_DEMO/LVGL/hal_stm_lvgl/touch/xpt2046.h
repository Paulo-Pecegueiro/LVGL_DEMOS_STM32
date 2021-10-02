/*
 * xpt2046.h
 *
 *  Created on: Sep 5, 2021
 *      Author: paulo
 */

#ifndef INC_XPT2046_H_
#define INC_XPT2046_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <main.h>
#include "hal_stm_lvgl/tft/ili9341.h"
/* Private defines -----------------------------------------------------------*/

//Set TOUCH Hardware Control and Frame lines
#define CS_ENABLE  1	// If you are using CS PIN

// Inform the SPI port you are using.
#define XPT2046_SPI_PORT	hspi2
extern  SPI_HandleTypeDef 	XPT2046_SPI_PORT;

#define XPT2046_XY_SWAP  		0
#define XPT2046_X_INV   		0
#define XPT2046_Y_INV   		0

#define XPT2046_Y_ADDR 			0x90
#define XPT2046_X_ADDR 			0xD0

#define XPT2046_HOR_RES     	240
#define XPT2046_VER_RES     	320
#define XPT2046_X_MIN       	113
#define XPT2046_X_MAX       	3982
#define XPT2046_Y_MIN			316
#define XPT2046_Y_MAX       	4025

#define XPT2046_AVG         	4

/* Pin connection*/
#define XPT2046_CS_GPIO_Port 	TOUCH_CS_GPIO_Port
#define XPT2046_CS_Pin 			TOUCH_CS_Pin
#define XPT2046_IRQ_GPIO_Port 	TOUCH_IRQ_GPIO_Port
#define XPT2046_IRQ_Pin 		TOUCH_IRQ_Pin

/* Basic operations */
#if  CS_ENABLE
#define XPT2046_CS_Low()   		XPT2046_CS_GPIO_Port->ODR &= ~XPT2046_CS_Pin
#define XPT2046_CS_High()  		XPT2046_CS_GPIO_Port->ODR |= XPT2046_CS_Pin
#endif

/*Variables*/
struct Touchpad{
	uint16_t width;
	uint16_t height;
	uint16_t x_min;
	uint16_t x_max;
	uint16_t y_min;
	uint16_t y_max;
	uint8_t rotation;
	int16_t avg_buf_x[XPT2046_AVG];
	int16_t avg_buf_y[XPT2046_AVG];
	uint8_t avg_last;
}Touchpad;


/* Functions*/
uint32_t XPT2046_Irq_Read(void);
void XPT2046_Init(void);
void XPT2046_Get_Touch_XY(volatile uint16_t* x_kor, volatile uint16_t* y_kor, uint8_t count_read);
void XPT2046_Corr(uint16_t * x, uint16_t * y);

#endif //INC_XPT2046_H_
