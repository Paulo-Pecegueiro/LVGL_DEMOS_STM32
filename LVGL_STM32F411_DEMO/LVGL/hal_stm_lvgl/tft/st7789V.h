/*
 * st7789V.h
 *
 *  Created on: Mar 14, 2021
 *      Author: paulo
 */

#ifndef INC_ST7789V_H_
#define INC_ST7789V_H_
#include "main.h"
#include "stdint.h"

//Set Using LVGL
#define Using_LVGL 1  // Do not forget to enable this define if you are going to use LVGL, otherwise there will be a conflict with library and it won't work!

//Set LCD Hardware Control and Frame lines
#define RST_ENABLE 1	// If you are using RTS PIN
#define CS_ENABLE  0	// If you are using CS PIN
#define TE_ENABLE  0  	//TE_ENABLE do not supported yet, do not use!
#define BLK_ENABLE 1 	// If you are using BLK PIN


// Inform the SPI port you are using.
#define ST7789_SPI_PORT   hspi1
extern  SPI_HandleTypeDef ST7789_SPI_PORT;

//Set your LCD size
#define ST7789_Width 	 240
#define ST7789_Height 	 240
#define ST7789_Size 	 ST7789_Width*ST7789_Height

//LCD Rotation
//The rotation values are relative to how you would rotate the physical display in the clockwise direction
#define DISP_ROT_Portrait        0 //0
#define DISP_ROT_Landscape		 1 //90
#define DISP_ROT_Inv_Portrait	 2 //180
#define DISP_ROT_Inv_Landscape   3 //270

//Mask values for MADCTL
#define ST7789_MADCTL_MY  0x80
#define ST7789_MADCTL_MX  0x40
#define ST7789_MADCTL_MV  0x20
#define ST7789_MADCTL_ML  0x10
#define ST7789_MADCTL_RGB 0X00

//COLORS
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40
#define BRRED 			 0XFC07
#define GRAY  			 0X8430

#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458

#define LIGHTGREEN     	 0X841F
#define LGRAY 			 0XC618

#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12



/* Pin connection*/
#if RST_ENABLE
#define ST7789_RST_PORT   LCD_RST_GPIO_Port
#define ST7789_RST_PIN    LCD_RST_Pin
#endif

#if  CS_ENABLE
#define ST7789_CS_PORT    ST7789_CS_GPIO_Port
#define ST7789_CS_PIN     ST7789_CS_Pin
#endif

#if  TE_ENABLE
#define ST7789_TE_PORT    ST7789_TE_GPIO_Port
#define ST7789_TE_PIN     ST7789_TE_Pin
#endif

#if  BLK_ENABLE
#define ST7789_BLK_PORT   LCD_BLK_GPIO_Port
#define ST7789_BLK_PIN    LCD_BLK_Pin
#endif

#define ST7789_DC_PORT    LCD_DC_GPIO_Port
#define ST7789_DC_PIN     LCD_DC_Pin


/* Basic operations */
#if  RST_ENABLE
#define ST7789_RST_Low()   ST7789_RST_PORT->ODR &= ~ST7789_RST_PIN
#define ST7789_RST_High()  ST7789_RST_PORT->ODR |= ST7789_RST_PIN
#endif

#if  CS_ENABLE
#define ST7789_CS_Low()   ST7789_CS_PORT->ODR &= ~ST7789_CS_PIN
#define ST7789_CS_High()  ST7789_CS_PORT->ODR |= ST7789_CS_PIN
#endif

#if  TE_ENABLE
#define ST7789_TE_Read()  ST7789_TE_GPIO_Port->IDR & ST7789_TE_Pin
#endif

#if  BLK_ENABLE
#define ST7789_BLK_Low()   ST7789_BLK_PORT->ODR &= ~ST7789_BLK_PIN
#define ST7789_BLK_High()  ST7789_BLK_PORT->ODR |= ST7789_BLK_PIN
#endif

#define ST7789_DC_Low()    ST7789_DC_PORT->ODR &= ~ST7789_DC_PIN
#define ST7789_DC_High()   ST7789_DC_PORT->ODR |= ST7789_DC_PIN


/*Variables*/

struct Disp{
	uint16_t xstart;
	uint16_t ystart;
	uint16_t width;
	uint16_t height;
	uint16_t rotation;

}Disp;


/* Functions*/
void ST7789_Init(uint8_t rotation);
void ST7789_Reset(void);
void ST7789_Select(void);
void ST7789_Deselect(void);
void ST7789_DisplayOn(void);
void ST7789_DisplayOff(void);
void ST7789_Fill_Color(uint16_t color);
void ST7789_Fill_Area_Color(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color);
void ST7789_Send_Data_DMA(uint16_t x, uint16_t y, uint16_t x_end, uint16_t y_end, uint8_t *p);
void ST7789_Test(void);

#endif /* INC_ST7789V_H_ */
