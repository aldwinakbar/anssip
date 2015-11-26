#include "i2c_dma.h"
#include "hd44780_i2c.h"
#include "utils.h"
#include <stdio.h>

void NVIC_Configuration(void);

int main(void)
{	
	// changed by aldwin@hermanudin.com
	// timer declaration moved from hd44780_i2c.c to hd44780_i2c.h
	// added hd44780_clear in hd44780_i2c.c
	
	NVIC_Configuration();
	LED_Init1();
	I2C_LowLevel_Init(I2C1);

	hd44780_init(TIM2);
	hd44780_go_to(1,1);
    hd44780_backlight(true);
    hd44780_print("Aldwin Akbar");
    delay_ms(timer, 2000);
    hd44780_clear();
    hd44780_print("Aldwin Akbar H");

}

void NVIC_Configuration(void)
{

    /* 1 bit for pre-emption priority, 3 bits for subpriority */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    NVIC_SetPriority(I2C1_EV_IRQn, 0x00);
    NVIC_EnableIRQ(I2C1_EV_IRQn);

    NVIC_SetPriority(I2C1_ER_IRQn, 0x01);
    NVIC_EnableIRQ(I2C1_ER_IRQn);


    NVIC_SetPriority(I2C2_EV_IRQn, 0x00);
    NVIC_EnableIRQ(I2C2_EV_IRQn);

    NVIC_SetPriority(I2C2_ER_IRQn, 0x01);
    NVIC_EnableIRQ(I2C2_ER_IRQn);

}
