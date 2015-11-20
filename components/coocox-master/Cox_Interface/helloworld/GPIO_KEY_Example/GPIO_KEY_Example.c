//******************************************************************************
//
//! \file     GPIO_KEY_Example.c
//!
//! \brief    This example showhow how to configure GPIO to OutPut mode and 
//!           input mode.
//!
//! \PinUsed  PB18 : LED pin
//!           PC13 : KEY pin
//!
//! \describe When the key is pressed, then the LED will be lighted.
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
#define TICK_SLOW       ((unsigned long)0xFFFFF)
#define LED1            PB18
#define KEY1            PC13

/* Private function prototypes **********************************************/
void GPIO_KEY_Example(void);
static void LED_Init(void);
static void KEY_Init(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!			\addtogroup GPIO_Example GPIO Example
//!     	@{
//!       		\addtogroup GPIO_KEY_Example KEY
//!        		@{
//!
//! \brief  The PWM_Signal_Edge_Example function illustrates the
//!         PWM signal on 6 Channels in single edge mode
//!
//! \return None
//
//*****************************************************************************
void GPIO_KEY_Example(void)
{

    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);

    /********************** Initialize GPIO peripheral *******************/
    LED_Init();
    KEY_Init();

    while(1)
    {
    	if(xGPIOPinRead(GPIOC_BASE, GPIO_PIN_13))
        	xGPIOSPinWrite(LED1, 1);
    	else
        	xGPIOSPinWrite(LED1, 0);
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

}
//*****************************************************************************
//
//! \brief  The LED_Init function Used to Initialize LED light
//!
//! \return None
//
//*****************************************************************************
static void KEY_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
	xSysCtlPeripheralEnable2( xGPIOSPinToPort( KEY1 ) );

    /******************** Configure Peripheral'S IO **********************/
	xGPIOSPinTypeGPIOInput(KEY1);

}
