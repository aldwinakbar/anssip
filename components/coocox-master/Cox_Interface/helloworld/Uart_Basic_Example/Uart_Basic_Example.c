//******************************************************************************
//
//! \file     Uart_Basic_Example.c
//!
//! \brief    This example is used to demonstrate the use of the PWM interrupt
//!           function.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!
//!\describe This example is Show how to configure WDT timer into interrupt
//!          mode. When program is running. If we don't feed the dog, then
//!          The status of LED  will flip.
//!
//! \version  3.0
//! \date     10/27/2014
//! \author   CooCox
//! \copy
//!
//! Copyright (c) 2009-2014 CooCox.  All rights reserved.
//
//******************************************************************************
#include "CoX.h"

/* Private define ************************************************************/
#define TICK_SLOW           ((unsigned long)0xFFFFF)
#define LED1                PB18

/* Private function prototypes **********************************************/
static void UART_Init(void);
static void LED_Init(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup UART_Example UART Example
//!     	@{
//!       		\addtogroup Uart_Basic_Example Basic
//!        		@{
//!
//! \brief  The Uart_Basic_Example function illustrates the UART to message to
//!         PC.
//!
//*****************************************************************************
void Uart_Basic_Example(void)
{
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_XTAL_12MHZ | xSYSCTL_OSC_MAIN);
    xSysCtlDelay(TICK_SLOW);

    /********************** Initialize Uart Peripheral ********************/
    UART_Init();

    /********************** Initialize GPIO Peripheral ********************/
    LED_Init();

    while(1)
    {
    	printf("LPC17xx Cox3.0 Uart basic function test!");
    	xGPIOSPinWrite(LED1, 1);
    	xSysCtlDelay(TICK_SLOW);
    	xGPIOSPinWrite(LED1, 0);
    	xSysCtlDelay(TICK_SLOW);
    }

}
//*****************************************************************************
//
//!       @}
//!     @}
//!   @}
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \brief  The UART_Init function Used to Init Uart peripheral
//!
//! \return None
//
//*****************************************************************************
static void UART_Init(void)
{
    /********************** Configure peripheral Power *********************/
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);
    xSysCtlPeripheralEnable2(xUART3_BASE);
    /********************** Configure Peripheral'S IO **********************/
    //xSPinTypeUART(UART3TX, PA0);
    //xSPinTypeUART(UART3RX, PA1);
    xSPinTypeUART(UART3TX, PA25);
    xSPinTypeUART(UART3RX, PA26);

    /********************** Configure UART *********************************/
    xUARTConfigSet(xUART3_BASE, 115200, (xUART_CONFIG_WLEN_8 |
                                         xUART_CONFIG_STOP_1 |
                                         xUART_CONFIG_PAR_NONE));

    /********************** Enable UART ************************************/
    xUARTEnable(xUART3_BASE, (xUART_BLOCK_UART | xUART_BLOCK_TX | xUART_BLOCK_RX));

}

//*****************************************************************************
//
//! \brief  The LED_Init function Used to Initialize LED light
//!
//! \return None
//
//*****************************************************************************
static void LED_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
	xSysCtlPeripheralEnable2( xGPIOSPinToPort( LED1 ) );

    /******************** Configure Peripheral'S IO **********************/
    xGPIOSPinTypeGPIOOutput(LED1);

    xGPIOSPinWrite(LED1, 1);

}

