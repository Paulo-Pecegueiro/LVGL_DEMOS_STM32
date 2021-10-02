/*
 * ili9341.c
 *
 *  Created on: Mar 14, 2021
 *      Author: paulo
 */
#include "ili9341.h"

/**
 * LCD DC Set
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_DC_Set(void)
{
	ILI9341_DC_High();
}

/**
 * LCD DC Reset
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_DC_Reset(void)
{
	ILI9341_DC_Low();
}

/**
 * LCD Select
 *
 * @param   void
 *
 * @return  void
 */
void ILI9341_Select(void)
{
	#if CS_ENABLE
	ILI9341_CS_Low();
	#endif
}


/**
 * LCD Deselect
 *
 * @param   void
 *
 * @return  void
 */
void ILI9341_Deselect(void)
{
	#if CS_ENABLE
	ILI9341_CS_High();
	#endif
}


/**
 * LCD Back light on state
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_DisplayOn(void)
{
	#if BLK_ENABLE
	ILI9341_BLK_High();
	#endif
}

/**
 * LCD Back light off state
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_DisplayOff(void)
{
	#if BLK_ENABLE
	ILI9341_BLK_Low();
	#endif
}



/**
 * Waits for TE goes high to start writing
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_Wait_TE(void)
{
	#if TE_ENABLE
	while(ILI9341_TE_Read()==1);
	HAL_Delay(1);
	#endif
}


/**
 * @brief   Calls SPI to transfer data buffer
 *
 * @param   data    buffer to be  sent
 * @param   size    size of data buffer
 *
 * @return  void
 */
static void ILI9341_SPI_Send(uint8_t *data, uint16_t size)
{
#if CS_ENABLE
    ILI9341_Select();
    HAL_SPI_Transmit(&ILI9341_SPI_PORT,data,size,1000);
    ILI9341_Deselect();
#else
    HAL_SPI_Transmit(&ILI9341_SPI_PORT,data,size,1000);
#endif

}

/**
 * Waits for DMA be ready
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_SPI_WAIT_DMA(void){
	 while(ILI9341_SPI_PORT.hdmatx->State != HAL_DMA_STATE_READY); //waits until SPI TX DMA channel complete transmission
}


/**
 * @brief   Calls DMA to transfer SPI data buffer
 *
 * @param   data    buffer to be  sent
 * @param   size    size of data buffer
 *
 * @return  void
 */
static void ILI9341_SPI_Send_DMA(uint8_t *data, uint16_t size)
{
#if Using_LVGL
	#if CS_ENABLE
    ILI9341_Select();
    HAL_SPI_Transmit(&ILI9341_SPI_PORT, data, size, 1000);
    ILI9341_Deselect();
	#else
    HAL_SPI_Transmit(&ILI9341_SPI_PORT, data, size, 1000); //Library functions will not use DMA if LVGL is being used
#endif
#else
#if CS_ENABLE
    ILI9341_Select();
    HAL_SPI_Transmit_DMA(&ILI9341_SPI_PORT, data, size);
    ILI9341_SPI_WAIT_DMA();
    ILI9341_Deselect();
#else
    HAL_SPI_Transmit_DMA(&ILI9341_SPI_PORT, data, size);
    ILI9341_SPI_WAIT_DMA();
#endif
#endif
}

/**
 * @brief   Writes one command to ILI9341
 *
 * @param   cmd     command
 *
 * @return  void
 */
static void ILI9341_Write_Cmd(uint8_t cmd)
{

    ILI9341_DC_Reset();
    ILI9341_SPI_Send(&cmd, 1);
    ILI9341_DC_Set();
}

/**
 * @brief   Writes one data byte
 *
 * @param   data        data byte to be sent
 *
 * @return  void
 */
static void ILI9341_Write_Data(uint8_t* data, uint16_t size)
{
	ILI9341_SPI_Send_DMA(data, size);
}

/**
 * LCD Reset
 *
 * @param   void
 *
 * @return  void
 */
static void ILI9341_Reset(void)
{
#if RST_ENABLE
	ILI9341_RST_Low();
    HAL_Delay(1);
    ILI9341_RST_High();
    HAL_Delay(1);
#else
    ILI9341_Write_Cmd(0x01); // Soft Reset
#endif

}




/**
 *  Sets area address and size area for data transfer
 *
 * @param   x1,y1   start addresses
 * @param   x2,y2   end addresses
 *
 * @return  void
 */
static void ILI9341_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    uint8_t bufx[4]={(x1+Disp.xstart) >> 8, (x1+Disp.xstart) & 0xFF, (x2+Disp.xstart) >> 8, (x2+Disp.xstart) & 0xFF};
	ILI9341_Write_Cmd(ILI9341_COLUMN_ADDR);
    ILI9341_Write_Data(bufx, 4);

    uint8_t bufy[4] = {(y1+Disp.ystart) >> 8, (y1+Disp.ystart) & 0xFF, (y2+Disp.ystart) >> 8, (y2+Disp.ystart) & 0xFF};
    ILI9341_Write_Cmd(ILI9341_PAGE_ADDR);
    ILI9341_Write_Data(bufy, 4);

    ILI9341_Write_Cmd(ILI9341_GRAM);
}


/*
static const uint8_t init_commands[] = {
    4, 0xEF, 0x03, 0x80, 0x02,
    4, 0xCF, 0x00, 0xC1, 0x30,
    5, 0xED, 0x64, 0x03, 0x12, 0x81,
    4, 0xE8, 0x85, 0x00, 0x78,
    6, 0xCB, 0x39, 0x2C, 0x00, 0x34, 0x02,
    2, 0xF7, 0x20,
    3, 0xEA, 0x00, 0x00,
    2, ILI9341_POWER1, 0x23, // Power control VRH[5:0]
    2, ILI9341_POWER2, 0x10, // Power control SAP[2:0];BT[3:0]
    3, ILI9341_VCOM1, 0x3e, 0x28, // VCM control
    2, ILI9341_VCOM2, 0x86, // VCM control2
    2, ILI9341_MAC, 0x48, // Memory Access Control
    2, 0x37, 0x00, // Vertical scroll zero
    2, ILI9341_PIXEL_FORMAT, 0x55,
    3, 0xB1, 0x00, 0x18,
    4, 0xB6, 0x08, 0x82, 0x27, // Display Function Control
    2, 0xF2, 0x00, // 3Gamma Function Disable
    2, 0x26, 0x01, // Gamma curve selected
    16, 0xE0, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, // Set Gamma
    0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
    16, 0xE1, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, // Set Gamma
    0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
    2, 0x11, 0x80, // Exit Sleep
    2, 0x29, 0x80, // Display on
	  0
};
*/
/**
 * @brief   Initializes ILI9341 LCD driver
 *
 * @param   void
 * @return  void
 */

void ILI9341_Init(uint8_t rotation) {

	uint8_t madctl=0;
	uint8_t data[15];

	UNUSED(madctl);
	UNUSED(Disp);

	ILI9341_DisplayOff();
    ILI9341_Reset();

    //TURN OFF DISPLAY
	ILI9341_Write_Cmd(0x28);

	Disp.rotation = rotation;
	switch(Disp.rotation)
	{
		case DISP_ROT_Portrait:
			Disp.width = ILI9341_Width;
			Disp.height = ILI9341_Height;
			Disp.xstart = 0;
			Disp.ystart = 0;
			madctl = 0x40|0x08;
			break;
		case DISP_ROT_Landscape:
			Disp.width = ILI9341_Height;
			Disp.height = ILI9341_Width;
			Disp.xstart = 0;
			Disp.ystart = 0;
			madctl = 0x20|0x08;
			break;
		case DISP_ROT_Inv_Portrait:
			Disp.width = ILI9341_Width;
			Disp.height = ILI9341_Height;
			Disp.xstart = 0;
			Disp.ystart = 0;
			madctl = 0x80|0x08;
			break;
		case DISP_ROT_Inv_Landscape:
			Disp.width = ILI9341_Height;
			Disp.height = ILI9341_Width;
			Disp.xstart = 0;
			Disp.ystart = 0;
			madctl = 0x40|0x80|0x20|0x08;

			break;
		default:
			//EXIT IF SCREEN ROTATION NOT VALID!
			madctl = 0x48;
			break;
	}

	//POWER CONTROL A
	ILI9341_Write_Cmd(0xCB);
    data[0] = 0x39;
    data[1] = 0x2C;
    data[2] = 0x00;
    data[3] = 0x34;
    data[4] = 0x02;
	ILI9341_Write_Data(data,5);

	//POWER CONTROL B
	ILI9341_Write_Cmd(0xCF);
    data[0] = 0x00;
    data[1] = 0xC1;
    data[2] = 0x30;
	ILI9341_Write_Data(data,3);

	//DRIVER TIMING CONTROL A
	ILI9341_Write_Cmd(0xE8);
    data[0] = 0x85;
    data[1] = 0x00;
    data[2] = 0x78;
	ILI9341_Write_Data(data,3);


	//DRIVER TIMING CONTROL B
	ILI9341_Write_Cmd(0xEA);
    data[0] = 0x00;
    data[1] = 0x00;
	ILI9341_Write_Data(data,2);

	//POWER ON SEQUENCE CONTROL
	ILI9341_Write_Cmd(0xED);
    data[0] = 0x64;
    data[1] = 0x03;
    data[2] = 0x12;
    data[3] = 0x81;
	ILI9341_Write_Data(data,4);


	//PUMP RATIO CONTROL
	ILI9341_Write_Cmd(0xF7);
	data[0] = 0x20;
	ILI9341_Write_Data(data,1);

	//POWER CONTROL,VRH[5:0]
	ILI9341_Write_Cmd(0xC0);
	data[0] = 0x23;
	ILI9341_Write_Data(data,1);

	//POWER CONTROL,SAP[2:0];BT[3:0]
	ILI9341_Write_Cmd(0xC1);
	data[0] = 0x10;
	ILI9341_Write_Data(data,1);

	//VCM CONTROL
	ILI9341_Write_Cmd(0xC5);
    data[0] = 0x3E;
    data[1] = 0x28;
	ILI9341_Write_Data(data,2);

	//VCM CONTROL 2
	ILI9341_Write_Cmd(0xC7);
	data[0] = 0x86;
	ILI9341_Write_Data(data,1);

	//MEMORY ACCESS CONTROL
	ILI9341_Write_Cmd(0x36);
	data[0] = madctl;
	ILI9341_Write_Data(data,1);

	//PIXEL FORMAT
	ILI9341_Write_Cmd(0x3A);
	data[0] = 0x55;
	ILI9341_Write_Data(data,1);

	//FRAME RATIO CONTROL, STANDARD RGB COLOR
	ILI9341_Write_Cmd(0xB1);
    data[0] = 0x00;
    data[1] = 0x18;
	ILI9341_Write_Data(data,2);

	//DISPLAY FUNCTION CONTROL
	ILI9341_Write_Cmd(0xB6);
    data[0] = 0x08;
    data[1] = 0x82;
    data[2] = 0x27;
	ILI9341_Write_Data(data,3);

	//3GAMMA FUNCTION DISABLE
	ILI9341_Write_Cmd(0xF2);
	data[0] = 0x00;
	ILI9341_Write_Data(data,1);

	//GAMMA CURVE SELECTED
	ILI9341_Write_Cmd(0x26);
	data[0] = 0x01;
	ILI9341_Write_Data(data,1);

	//POSITIVE GAMMA CORRECTION
	ILI9341_Write_Cmd(0xE0);
	data[0] = 0x0F;
	data[1] = 0x31;
	data[2] = 0x2B;
	data[3] = 0x0C;
	data[4] = 0x0E;
	data[5] = 0x08;
	data[6] = 0x4E;
	data[7] = 0xF1;
	data[8] = 0x37;
	data[9] = 0x07;
	data[10] = 0x10;
	data[11] = 0x03;
	data[12] = 0x0E;
	data[13] = 0x09;
	data[14] = 0x00;
	ILI9341_Write_Data(data,15);

	//NEGATIVE GAMMA CORRECTION
	ILI9341_Write_Cmd(0xE1);
	data[0] = 0x00;
	data[1] = 0x0E;
	data[2] = 0x14;
	data[3] = 0x03;
	data[4] = 0x11;
	data[5] = 0x07;
	data[6] = 0x31;
	data[7] = 0xC1;
	data[8] = 0x48;
	data[9] = 0x08;
	data[10] = 0x0F;
	data[11] = 0x0C;
	data[12] = 0x31;
	data[13] = 0x36;
	data[14] = 0x0F;
	ILI9341_Write_Data(data,15);

	//EXIT SLEEP
	ILI9341_Write_Cmd(0x11);
	HAL_Delay(120);

	//TURN ON DISPLAY
	ILI9341_Write_Cmd(0x29);
	//ILI9341_Fill_Color(color);
	//ILI9341_DisplayOn();

	//STARTING ROTATION

}

/*
 *  Sends data buffer to LCD GRAM, used with LVGL
 *
 * @param   x_start,y_start
 * @param   x_end,y_end
 * @param   *p              buffer data
 *
 * @return  void
 */

void ILI9341_Send_Data_DMA(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint8_t *p)
{
    ILI9341_Address_Set(x_start, y_start, x_end, y_end);
#if CS_ENABLE
    ILI9341_Select();
    ILI9341_SPI_WAIT_DMA();
    HAL_SPI_Transmit_DMA(&ILI9341_SPI_PORT, (uint8_t *)p, (x_end - x_start + 1) * (y_end - y_start + 1) * 2);
    //ILI9341_SPI_WAIT_DMA();

#else
    HAL_SPI_Transmit_DMA(&ILI9341_SPI_PORT, (uint8_t *)p, (x_end - x_start + 1) * (y_end - y_start + 1) * 2);
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
void ILI9341_Fill_Color(uint16_t color)
{
	uint32_t total_bytes, sent_bytes=0;
	uint16_t i, remain_bytes;
	uint8_t Buffer[65534]; 				//max DMA transfer size is 65535 bytes, but 65535 is not divided by 2 and a uint16_t has 2 bytes.
	uint8_t data[2] = {0};

	total_bytes = (uint32_t) ILI9341_Size*2;

	ILI9341_Address_Set(0, 0, Disp.width - 1, Disp.height - 1);

    data[0] = color >> 8;
    data[1] = color;

	for(i = 0; i < 32762; i++)
	{
		Buffer[(i*2)] =  data[0];
		Buffer[(i*2)+1] =  data[1];
	}

    for(i=0; i < total_bytes/65534; i++){
    	ILI9341_SPI_Send_DMA(Buffer, 65534);
    	sent_bytes+=65534;
    }

    remain_bytes = (uint32_t)total_bytes - sent_bytes;
    ILI9341_SPI_Send_DMA(Buffer, remain_bytes);
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
void ILI9341_Fill_Area_Color(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color)
{
	uint32_t total_bytes, sent_bytes=0;
	uint16_t i, remain_bytes;
	uint8_t Buffer[65534]; 				//max DMA transfer size is 65535 bytes, but 65535 is not divided by 2 and a uint16_t has 2 bytes.


    total_bytes = (x_end - x_start + 1) * (y_end - y_start + 1) * 2;

    ILI9341_Address_Set(x_start, y_start, x_end, y_end);

    if(total_bytes>65534){
        for(i = 0; i < 65534 / 2; i++)
        {
        	Buffer[2 * i] = color >> 8;
        	Buffer[2 * i + 1] = color;
        }

        for(i=0; i < total_bytes/65534; i++){
        	ILI9341_SPI_Send_DMA(Buffer, 65534);
        	sent_bytes+=65534;
        }

        remain_bytes = (uint32_t)total_bytes - sent_bytes;
        ILI9341_SPI_Send_DMA(Buffer, remain_bytes);
    }else{

    	for(i = 0; i < total_bytes / 2; i++)
        {
        	Buffer[2 * i] = color >> 8;
        	Buffer[2 * i + 1] = color;
        }
        ILI9341_SPI_Send_DMA(Buffer, total_bytes);
    }

}
*/

/**
 *  Test LCD screen colors and connections
 *
 * @param   void
 *
 * @return  void
 */
/*
void ILI9341_Test(void){
	  ILI9341_Fill_Area_Color(0,0, 240, 106, RED);
	  ILI9341_Fill_Area_Color(0,106, 240, 212, GREEN);
	  ILI9341_Fill_Area_Color(0,212, 240, 320, BLUE);
	  HAL_Delay(333);

	  ILI9341_Fill_Area_Color(0,0, 240, 106, GREEN);
	  ILI9341_Fill_Area_Color(0,106, 240, 212, BLUE);
	  ILI9341_Fill_Area_Color(0,212, 240, 320, RED);
	  HAL_Delay(333);

	  ILI9341_Fill_Area_Color(0,0, 240, 106, BLUE);
	  ILI9341_Fill_Area_Color(0,106, 240, 212, RED);
	  ILI9341_Fill_Area_Color(0,212, 240, 320, GREEN);
	  HAL_Delay(333);

	  ILI9341_Fill_Area_Color(0,0, 240, 320, RED);
	  HAL_Delay(666);
	  ILI9341_Fill_Area_Color(0,0, 240, 320, GREEN);
	  HAL_Delay(666);
	  ILI9341_Fill_Area_Color(0,0, 240, 320, BLUE);
	  HAL_Delay(666);



	  ILI9341_Fill_Color(RED);
	  ILI9341_Fill_Color(GREEN);
	  ILI9341_Fill_Color(BLUE);

}
*/







