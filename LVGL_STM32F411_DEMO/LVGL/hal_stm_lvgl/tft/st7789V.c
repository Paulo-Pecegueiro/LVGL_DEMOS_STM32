/*
 * st7789V.c
 *
 *  Created on: Mar 14, 2021
 *      Author: paulo
 */
#include "st7789V.h"

/**
 * LCD DC Set
 *
 * @param   void
 *
 * @return  void
 */
static void ST7789_DC_Set(void)
{
	ST7789_DC_High();
}

/**
 * LCD DC Reset
 *
 * @param   void
 *
 * @return  void
 */
static void ST7789_DC_Reset(void)
{
	ST7789_DC_Low();
}

/**
 * @brief   Calls SPI to transfer data buffer
 *
 * @param   data    buffer to be  sent
 * @param   size    size of data buffer
 *
 * @return  void
 */
static void ST7789_SPI_Send(uint8_t *data, uint16_t size)
{
#if CS_ENABLE
    ST7789_Select();
    HAL_SPI_Transmit(&ST7789_SPI_PORT,data,size,1000);
    ST7789_UnSelect();
#else
    HAL_SPI_Transmit(&ST7789_SPI_PORT,data,size,1000);
#endif

}


/**
 * Waits for DMA be ready
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_SPI_WAIT_DMA(void){
	 while(ST7789_SPI_PORT.hdmatx->State != HAL_DMA_STATE_READY); //waits until SPI TX DMA channel complete transmission
}


/**
 * @brief   Calls DMA to transfer SPI data buffer
 *
 * @param   data    buffer to be  sent
 * @param   size    size of data buffer
 *
 * @return  void
 */
static void ST7789_SPI_Send_DMA(uint8_t *data, uint16_t size)
{
#if Using_LVGL
#if CS_ENABLE
    ST7789_Select();
    HAL_SPI_Transmit(&ST7789_SPI_PORT, data, size, 1000);
    ST7789_UnSelect();
#else
    HAL_SPI_Transmit(&ST7789_SPI_PORT, data, size, 1000); //Library functions will not use DMA if LVGL is being used
#endif
#else
#if CS_ENABLE
    ST7789_Select();
    HAL_SPI_Transmit_DMA(&ST7789_SPI_PORT, data, size);
    ST7789_SPI_WAIT_DMA();
    ST7789_UnSelect();
#else
    HAL_SPI_Transmit_DMA(&ST7789_SPI_PORT, data, size);
    ST7789_SPI_WAIT_DMA();
#endif
#endif
}


/**
 * @brief   Writes one command to ST7789
 *
 * @param   cmd     command
 *
 * @return  void
 */
static void ST7789_Write_Cmd(uint8_t cmd)
{

    ST7789_DC_Reset();
    ST7789_SPI_Send(&cmd, 1);
    ST7789_DC_Set();
}


/**
 * @brief   Writes one data byte
 *
 * @param   data        data byte to be sent
 *
 * @return  void
 */
static void ST7789_Write_Data(uint8_t* data, uint16_t size)
{
	ST7789_SPI_Send_DMA(data, size);
}

/**
 *  Sets area address and size area for data transfer
 *
 * @param   x1,y1   start addresses
 * @param   x2,y2   end addresses
 *
 * @return  void
 */
static void ST7789_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{

    uint8_t bufx[4]={(x1+Disp.xstart) >> 8, (x1+Disp.xstart) & 0xFF, (x2+Disp.xstart) >> 8, (x2+Disp.xstart) & 0xFF};
    ST7789_Write_Cmd(0x2a);
    ST7789_Write_Data(bufx, 4);

    uint8_t bufy[4] = {(y1+Disp.ystart) >> 8, (y1+Disp.ystart) & 0xFF, (y2+Disp.ystart) >> 8, (y2+Disp.ystart) & 0xFF};
    ST7789_Write_Cmd(0x2b);
    ST7789_Write_Data(bufy, 4);

    ST7789_Write_Cmd(0x2C);
}

/**
 * @brief   Initializes ST7789 LCD driver
 *
 * @param   void
 * @return  void
 */


void ST7789_Init(uint8_t rotation)
{
	uint8_t madctl=0;
	uint8_t data[14];

		UNUSED(madctl);
		UNUSED(Disp);
		ST7789_Select();

		ST7789_DisplayOff();

	    ST7789_Reset();

	    HAL_Delay(120);
	    /* Sleep Out */
	    ST7789_Write_Cmd(0x11);
	    /* wait for power stability */
	    HAL_Delay(120);

	    Disp.rotation = rotation;
	    /* Memory Data Access Control */
	    switch (Disp.rotation) {

	    case DISP_ROT_Portrait: 					// Portrait
	    	  Disp.width = ST7789_Width;
	          Disp.height = ST7789_Height;
	          if (Disp.height == 320 || Disp.width == 240) {
	              Disp.xstart = 0;
	              Disp.ystart = 0;
	          }
	          else if (Disp.width == 135) {
	                  Disp.xstart = 52;
	                  Disp.ystart = 40;
	          }
	    	  madctl = ST7789_MADCTL_RGB;
	    	  break;

	      case DISP_ROT_Landscape:						 // Landscape
	    	  Disp.width = ST7789_Height;
	    	  Disp.height = ST7789_Width;
	          if (Disp.height == 320 || Disp.width == 240) {
	        	  Disp.xstart = 0;
	        	  Disp.ystart = 0;
	          } else if (Disp.width == 135) {
	          	  Disp.xstart = 40;
	          	  Disp.ystart = 53;
	          }
	    	  madctl = ST7789_MADCTL_MX | ST7789_MADCTL_MV | ST7789_MADCTL_RGB;
	    	  break;

	      case DISP_ROT_Inv_Portrait:					// Inverted Portrait
	    	  Disp.width = ST7789_Width;
	    	  Disp.height = ST7789_Height;
	    	  if (Disp.height == 320) {
	    		  Disp.xstart = 0;
	    		  Disp.ystart = 0;
	    	  } else if (Disp.width == 135) {
	    		  Disp.xstart = 53;
	    		  Disp.ystart = 40;
	    	  }
	    	  else if (Disp.width == 240) {
	    		  Disp.xstart = 0;
	    		  Disp.ystart = 80;
	    	  }
	    	  madctl = ST7789_MADCTL_MX | ST7789_MADCTL_MY | ST7789_MADCTL_RGB;
	    	  break;

	      case DISP_ROT_Inv_Landscape:					// Inverted Landscape
	    	  Disp.width = ST7789_Height;
	    	  Disp.height = ST7789_Width;
	    	  if (Disp.height == 320) {
	    		  Disp.xstart = 0;
	    		  Disp.ystart = 0;
	    	  } else if (Disp.width == 135) {
	    		  Disp.xstart = 40;
	    		  Disp.ystart = 52;
	    	  }
	    	  else if (Disp.width == 240) {
	    		  Disp.xstart = 80;
	    		  Disp.ystart = 0;
	    	  }
	    	  madctl = ST7789_MADCTL_MV | ST7789_MADCTL_MY | ST7789_MADCTL_RGB;
	    	  break;
	      }

	    ST7789_Write_Cmd(0x36);
	    data[0]=madctl;
	    ST7789_Write_Data(data, 1);

	    /* RGB 5-6-5-bit  */
	    ST7789_Write_Cmd(0x3A);
	    data[0]=0x65;
	    ST7789_Write_Data(data, 1);

	    /* Porch Setting */
	    ST7789_Write_Cmd(0xB2);
	    data[0] = 0x0C;
	    data[1] = 0x0C;
	    data[2] = 0x00;
	    data[3] = 0x33;
	    data[4] = 0x33;
	    ST7789_Write_Data(data, 5);

	    /*  Gate Control */
	    ST7789_Write_Cmd(0xB7);
	    data[0]=0x72;
	    ST7789_Write_Data(data, 1);


	    /* VCOM Setting */
	    ST7789_Write_Cmd(0xBB);
	    data[0]=0x3D;
	    ST7789_Write_Data(data, 1);  //Vcom=1.625V

	    /* LCM Control */
	    ST7789_Write_Cmd(0xC0);
	    data[0]=0x2C;
	    ST7789_Write_Data(data, 1);

	    /* VDV and VRH Command Enable */
	    ST7789_Write_Cmd(0xC2);
	    data[0]=0x01;
	    ST7789_Write_Data(data, 1);

	    /* VRH Set */
	    ST7789_Write_Cmd(0xC3);
	    data[0]=0x19;
	    ST7789_Write_Data(data, 1);

	    /* VDV Set */
	    ST7789_Write_Cmd(0xC4);
	    data[0]=0x20;
	    ST7789_Write_Data(data, 1);

	    /* Frame Rate Control in Normal Mode */
	    ST7789_Write_Cmd(0xC6);
	    data[0]=0xFF;				//39HZ
	    //data[0]=0x0F; 			//60HZ
	    //data[0]=0x01;				//111HZ



	    ST7789_Write_Data(data, 1);

		#if  TE_ENABLE
	    /* Tearing Effect Line On */
	    ST7789_Write_Cmd(0x35);
	    data[0]=0x00;	// TEM=0,  this library supports V-Blanking information only
	    ST7789_Write_Data(data, 1);
	    #else
	    /*Tearing Effect Line OFF*/
	    ST7789_Write_Cmd(0x34);
		#endif

	    /* Power Control 1 */
	    ST7789_Write_Cmd(0xD0);
	    data[0]=0xA4;
	    data[1]=0xA1;
	    ST7789_Write_Data(data, 2);

	    /* Positive Voltage Gamma Control */
	    ST7789_Write_Cmd(0xE0);
	    data[0]=(0xD0);
	    data[1]=(0x04);
	    data[2]=(0x0D);
	    data[3]=(0x11);
	    data[4]=(0x13);
	    data[5]=(0x2B);
	    data[6]=(0x3F);
	    data[7]=(0x54);
	    data[8]=(0x4C);
	    data[9]=(0x18);
	    data[10]=(0x0D);
	    data[11]=(0x0B);
	    data[12]=(0x1F);
	    data[13]=(0x23);
	    ST7789_Write_Data(data, 14);

	    /* Negative Voltage Gamma Control */
	    ST7789_Write_Cmd(0xE1);
	    data[0]=(0xD0);
	    data[1]=(0x04);
	    data[2]=(0x0C);
	    data[3]=(0x11);
	    data[4]=(0x13);
	    data[5]=(0x2C);
	    data[6]=(0x3F);
	    data[7]=(0x44);
	    data[8]=(0x51);
	    data[9]=(0x2F);
	    data[10]=(0x1F);
	    data[11]=(0x1F);
	    data[12]=(0x20);
	    data[13]=(0x23);
	    ST7789_Write_Data(data, 14);

	    /* Display Inversion On */
	    ST7789_Write_Cmd(0x21);

	    ST7789_Write_Cmd(0x29);

	    //ST7789_Fill_Color(0x0000);
	    ST7789_DisplayOn();
}


/**
 * LCD Reset
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_Reset(void)
{
#if RST_ENABLE
	ST7789_RST_Low();
    HAL_Delay(120);
    ST7789_RST_High();
#else
    ST7789_Write_Cmd(0x01); // Soft Reset
#endif

}

/**
 * LCD Select
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_Select(void)
{
	#if CS_ENABLE
	ST7789_CS_Low();
	#endif
}


/**
 * LCD Deselect
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_Deselect(void)
{
	#if CS_ENABLE
	ST7789_CS_High();
	#endif
}


/**
 * Waits for TE goes high to start writing
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_Wait_TE(void)
{
	#if TE_ENABLE
	while(ST7789_TE_Read()==1);
	HAL_Delay(1);
	#endif
}


/**
 * LCD Back light on state
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_DisplayOn(void)
{
	#if BLK_ENABLE
	ST7789_BLK_High();
	#endif
}

/**
 * LCD Back light off state
 *
 * @param   void
 *
 * @return  void
 */
void ST7789_DisplayOff(void)
{
	#if BLK_ENABLE
	ST7789_BLK_Low();
	#endif
}


/**
 *  Fills LCD screen with a color
 *
 * @param   color
 *
 * @return  void
 */
/*
void ST7789_Fill_Color(uint16_t color)
{
	uint32_t total_bytes, sent_bytes=0;
	uint16_t i, remain_bytes;
	uint8_t Buffer[65534]; 				//max DMA transfer size is 65535 bytes, but 65535 is not divided by 2 and a uint16_t has 2 bytes.
	uint8_t data[2] = {0};

	total_bytes = (uint32_t) ST7789_Size*2;

	ST7789_Address_Set(0, 0, ST7789_Width - 1, ST7789_Height - 1);

    data[0] = color >> 8;
    data[1] = color;

	for(i = 0; i < 32762; i++)
	{
		Buffer[(i*2)] =  data[0];
		Buffer[(i*2)+1] =  data[1];
	}

    for(i=0; i < total_bytes/65534; i++){
    	ST7789_SPI_Send_DMA(Buffer, 65534);
    	sent_bytes+=65534;
    }

    remain_bytes = (uint32_t)total_bytes - sent_bytes;
    ST7789_SPI_Send_DMA(Buffer, remain_bytes);
}
*/

/**
 *  Fills LCD area with a color
 *
 * @param   x_start,y_start
 * @param   x_end,y_end
 * @param   color
 *
 * @return  void
 */
/*
void ST7789_Fill_Area_Color(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color)
{
	uint32_t total_bytes, sent_bytes=0;
	uint16_t i, remain_bytes;
	uint8_t Buffer[65534]; 				//max DMA transfer size is 65535 bytes, but 65535 is not divided by 2 and a uint16_t has 2 bytes.


    total_bytes = (x_end - x_start + 1) * (y_end - y_start + 1) * 2;

    ST7789_Address_Set(x_start, y_start, x_end, y_end);

    if(total_bytes>65534){
        for(i = 0; i < 65534 / 2; i++)
        {
        	Buffer[2 * i] = color >> 8;
        	Buffer[2 * i + 1] = color;
        }


        for(i=0; i < total_bytes/65534; i++){
        	ST7789_SPI_Send_DMA(Buffer, 65534);
        	sent_bytes+=65534;
        }

        remain_bytes = (uint32_t)total_bytes - sent_bytes;
        ST7789_SPI_Send_DMA(Buffer, remain_bytes);
    }else{

    	for(i = 0; i < total_bytes / 2; i++)
        {
        	Buffer[2 * i] = color >> 8;
        	Buffer[2 * i + 1] = color;
        }
        ST7789_SPI_Send_DMA(Buffer, total_bytes);
    }


}
*/

/**
 *  Sends data buffer to LCD GRAM, used with LVGL
 *
 * @param   x_start,y_start
 * @param   x_end,y_end
 * @param   *p              buffer data
 *
 * @return  void
 */

void ST7789_Send_Data_DMA(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint8_t *p)
{
    ST7789_Address_Set(x_start, y_start, x_end, y_end);
#if CS_ENABLE
    ST7789_Select();
    HAL_SPI_Transmit_DMA(&ST7789_SPI_PORT, (uint8_t *)p, (x_end - x_start + 1) * (y_end - y_start + 1) * 2);
    ST7789_UnSelect();
#else
    HAL_SPI_Transmit_DMA(&ST7789_SPI_PORT, (uint8_t *)p, (x_end - x_start + 1) * (y_end - y_start + 1) * 2);
#endif

}


/**
 *  Test LCD screen colors and connections
 *
 * @param   void
 *
 * @return  void
 */
/*
void ST7789_Test(void){
	  ST7789_Fill_Area_Color(0,0, 240, 80, RED);
	  ST7789_Fill_Area_Color(0,80, 240, 160, GREEN);
	  ST7789_Fill_Area_Color(0,160, 240, 240, BLUE);
	  HAL_Delay(333);

	  ST7789_Fill_Area_Color(0,0, 240, 80, GREEN);
	  ST7789_Fill_Area_Color(0,80, 240, 160, BLUE);
	  ST7789_Fill_Area_Color(0,160, 240, 240, RED);
	  HAL_Delay(333);

	  ST7789_Fill_Area_Color(0,0, 240, 80, BLUE);
	  ST7789_Fill_Area_Color(0,80, 240, 160, RED);
	  ST7789_Fill_Area_Color(0,160, 240, 240, GREEN);
	  HAL_Delay(333);

	  ST7789_Fill_Area_Color(0,0, 240, 240, RED);
	  HAL_Delay(666);
	  ST7789_Fill_Area_Color(0,0, 240, 240, GREEN);
	  HAL_Delay(666);
	  ST7789_Fill_Area_Color(0,0, 240, 240, BLUE);
	  HAL_Delay(666);
}
*/
