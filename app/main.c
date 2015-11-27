#include <stm32f10x.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>
#include <misc.h>
#include <stdio.h>
#include "usart.h"
#include "i2c_dma.h"
#include "hd44780_i2c.h"

// Warning!
// TIM2 and TIM3 are in use!

//void NVIC_Configuration(void);

int main(void){

	// ####### Variable Declaration #######
	int i = 0,d=0,x=0;
	char uid_data[8];

	// ####### Variable Declaration #######

	// ####### Hardware Initialization #######
	DWT_Init();
	USART2_Init(9600);
	USART1_Init(9600);
	// ####### Hardware Initialization #######

	NVIC_Configuration();
	LED_Init1();
	I2C_LowLevel_Init(I2C1);

	hd44780_init(TIM2);
	hd44780_backlight(true);
	hd44780_clear();
	hd44780_print(" Silahkan untuk ");
	hd44780_go_to(1,0);
	hd44780_print("tap kartu disana");
	DWT_Delay(1000000);

	while (1) {

		if(USART1->SR & USART_FLAG_RXNE){
			d = (int)(USART1->DR & 0x1FF);
			uid_data[x] = d;
			x++;
			if(x == 8){
				hd44780_clear();
				hd44780_print(" Selamat datang ");
				hd44780_go_to(1,3);
				hd44780_char(uid_data[0]);
				hd44780_char(uid_data[1]);
				hd44780_char(uid_data[2]);
				hd44780_char(uid_data[3]);
				hd44780_char(uid_data[4]);
				hd44780_char(uid_data[5]);
				hd44780_char(uid_data[6]);
				hd44780_char(uid_data[7]);
				usart2_print("AT+CIPSTART=\"TCP\",\"192.168.43.53\",50005\r\n");
				DWT_Delay(3000000);
				usart2_print("AT+CIPSEND=8\r\n");
				DWT_Delay(3000000);
				SendCharUart2(uid_data[0]);
				SendCharUart2(uid_data[1]);
				SendCharUart2(uid_data[2]);
				SendCharUart2(uid_data[3]);
				SendCharUart2(uid_data[4]);
				SendCharUart2(uid_data[5]);
				SendCharUart2(uid_data[6]);
				SendCharUart2(uid_data[7]);
				usart2_print("\r\n");
				DWT_Delay(3000000);
				usart2_print("AT+CIPCLOSE\r\n");
				DWT_Delay(3000000);
				hd44780_clear();
				hd44780_print(" Silahkan untuk ");
				hd44780_go_to(1,0);
				hd44780_print("tap kartu disana");
				x=0;
			}
		}
	}
}
void atWait(){


	while (!(USART2->SR & USART_FLAG_RXNE));
	while ((USART2->SR & USART_FLAG_RXNE)){
		SendCharUart1((int)(USART2->DR & 0x1FF));
	}
}

int GetKeyUart1 (void)
{
  while (!(USART1->SR & USART_FLAG_RXNE));
  return ((int)(USART1->DR & 0x1FF));
}

int SendCharUart1 (int ch)
{
  while (!(USART1->SR & USART_FLAG_TXE));
  USART1->DR = (ch & 0x1FF);
  return (ch);
}

int GetKeyUart2 (void)
{
  while (!(USART2->SR & USART_FLAG_RXNE));
  return ((int)(USART2->DR & 0x1FF));
}

int SendCharUart2 (int ch)
{
  while (!(USART2->SR & USART_FLAG_TXE));
  USART2->DR = (ch & 0x1FF);
  return (ch);
}


void LED_Init1(void) {
    //Smaller board

    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Use PC8 and PC9 // Discovery LEDs
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
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
