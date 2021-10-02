/*
 * xpt2046.c
 *
 *  Created on: Sep 5, 2021
 *      Author: paulo
 */

#include "xpt2046.h"


/**
 * TOUCH Select
 *
 * @param   void
 *
 * @return  void
 */
void XPT2046_Select(void)
{
	#if CS_ENABLE
	XPT2046_CS_Low();
	#endif
}

/**
 * TOUCH Deselect
 *
 * @param   void
 *
 * @return  void
 */
void XPT2046_Deselect(void)
{
	#if CS_ENABLE
	XPT2046_CS_High();
	#endif
}

uint32_t XPT2046_Irq_Read(void)
{
    return  HAL_GPIO_ReadPin(XPT2046_IRQ_GPIO_Port, XPT2046_IRQ_Pin);
}

static uint8_t SendReceive_Byte(SPI_TypeDef *SPIx, uint8_t data)
{
	uint8_t Rx_data=0;
    HAL_SPI_TransmitReceive(&XPT2046_SPI_PORT, (uint8_t*)&data, (uint8_t*)&Rx_data, 1, 1000);
    return Rx_data;
}

void XPT2046_Init(void)

{
	Touchpad.width = Disp.width ;
	Touchpad.height = Disp.height ;
	Touchpad.rotation = Disp.rotation;
	Touchpad.x_min = XPT2046_X_MIN;
	Touchpad.x_max = XPT2046_X_MAX;
	Touchpad.y_min = XPT2046_Y_MIN;
	Touchpad.y_max = XPT2046_Y_MAX;

	XPT2046_Select();
    SendReceive_Byte(SPI2, 0X80);
    SendReceive_Byte(SPI2, 0X00);
    SendReceive_Byte(SPI2, 0X00);
    HAL_Delay(1);
    XPT2046_Deselect();
}

uint16_t XPT2046_Get_Value(uint8_t address)
{
    uint16_t data = 0;
    XPT2046_Select();
    SendReceive_Byte(SPI2, address);
    data = SendReceive_Byte(SPI2, 0X00);
    data <<= 8;

    data |= SendReceive_Byte(SPI2, 0X00);
    data >>= 3;
    XPT2046_Deselect();
    return data;
}

void XPT2046_Get_Touch_XY(volatile uint16_t* x_kor, volatile uint16_t* y_kor, uint8_t count_read)
{
    uint8_t i = 0;
    uint16_t tmpx, tmpy, touch_x, touch_y = 0;

    touch_x = XPT2046_Get_Value(XPT2046_X_ADDR);
    touch_y = XPT2046_Get_Value(XPT2046_Y_ADDR);
    for (i = 0; i < count_read; i++)
    {
        tmpx = XPT2046_Get_Value(XPT2046_X_ADDR);
        tmpy = XPT2046_Get_Value(XPT2046_Y_ADDR);

        if (tmpx == 0)
        {
        	tmpy = 0;
        }
        else if (tmpy == 0)
        {
        	tmpx = 0;
        }
        else
		{
			touch_x = (touch_x + tmpx) / 2;
			touch_y = (touch_y + tmpy) / 2;
		}
	}
	*x_kor = touch_x;
	*y_kor = touch_y;
}

void XPT2046_Corr(uint16_t * x, uint16_t * y)
{
#if XPT2046_XY_SWAP 
    int16_t swap_tmp;
    swap_tmp = *x;
    *x = *y;
    *y = swap_tmp;
#endif

    if((*x) > Touchpad.x_min )
    {
    	(*x) -= Touchpad.x_min ;
    }
    else
    {
    	(*x) = 0;
    }

    if((*y) > Touchpad.y_min)
    {
    	(*y) -= Touchpad.y_min;
    }
    else
    {
    	(*y) = 0;
    }

    if(Touchpad.rotation==0||Touchpad.rotation==2)
	{
		(*x) = (uint32_t)((uint32_t)(*x) * Touchpad.width) / (Touchpad.x_max - Touchpad.x_min );
		(*y) = (uint32_t)((uint32_t)(*y) * Touchpad.height) / (Touchpad.y_max - Touchpad.y_min);
		(*x) =  Touchpad.width - (*x);
		(*y) =  Touchpad.height - (*y);
    }
    else
    {
		(*x) = (uint32_t)((uint32_t)(*x) * Touchpad.height) / (Touchpad.x_max - Touchpad.x_min );
		(*y) = (uint32_t)((uint32_t)(*y) * Touchpad.width) / (Touchpad.y_max - Touchpad.y_min);
    }



}

void XPT2046_Average(uint16_t * x, uint16_t * y)
{
    /*Shift out the oldest data*/
    uint8_t i;
    for(i = XPT2046_AVG - 1; i > 0 ; i--) {
        Touchpad.avg_buf_x[i] = Touchpad.avg_buf_x[i - 1];
        Touchpad.avg_buf_y[i] = Touchpad.avg_buf_y[i - 1];
    }

    /*Insert the new point*/
    Touchpad.avg_buf_x[0] = *x;
    Touchpad.avg_buf_y[0] = *y;
    if(Touchpad.avg_last < XPT2046_AVG) Touchpad.avg_last++;

    /*Sum the x and y coordinates*/
    int32_t x_sum = 0;
    int32_t y_sum = 0;
    for(i = 0; i < Touchpad.avg_last ; i++) {
        x_sum += Touchpad.avg_buf_x[i];
        y_sum += Touchpad.avg_buf_y[i];
    }

    /*Normalize the sums*/
    (*x) = (int32_t)x_sum / Touchpad.avg_last;
    (*y) = (int32_t)y_sum / Touchpad.avg_last;
}


