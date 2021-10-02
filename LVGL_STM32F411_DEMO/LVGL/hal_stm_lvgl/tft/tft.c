/**
 * @file lv_port_disp_templ.c
 *
 */

 /*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "tft.h"
#include "ili9341.h"
#include "main.h"
/*********************
 *      DEFINES
 *********************/
 #define SPI_DMA 1
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
#if SPI_DMA
//static lv_disp_drv_t * disp_p;
#endif
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void tft_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/
    /* Example for 1) */
		
	#define buffer_size LV_VER_RES_MAX/20*LV_HOR_RES_MAX
    /* Example for 2) */
    static lv_disp_buf_t disp_buf_1;
    static lv_color_t buf1_1[buffer_size];                        /*A buffer for 10 rows*/
    static lv_color_t buf1_2[buffer_size];                        /*An other buffer for 10 rows*/
    lv_disp_buf_init(&disp_buf_1, buf1_1, buf1_2, buffer_size);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/
	disp_drv.sw_rotate = 0;

	disp_drv.rotated = Disp.rotation;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf_1;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Initialize your display and the required peripherals. */
static void disp_init(void)
{
    /*You code here*/
	ILI9341_Init(DISP_ROT_Landscape);

}

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{

#if SPI_DMA
    /*SPI transmit data with DMA*/
	ILI9341_Send_Data_DMA(area->x1, area->y1, area->x2, area->y2, (uint8_t *)color_p);
#else
    /*SPI transmit data without DMA*/
    ILI9341_Send_Data(area->x1, area->y1, area->x2, area->y2, (uint8_t *)color_p);
    lv_disp_flush_ready(disp_drv);
#endif
}

#if SPI_DMA
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	lv_disp_flush_ready(&disp_drv);
    ILI9341_Deselect();
    GPIOA->ODR |= GPIO_PIN_4;
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
}
#endif

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
