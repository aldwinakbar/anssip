//******************************************************************************
//
//! \file     GPIO_LED_Example.c
//!
//! \brief    This example show how to configure GPIO to OutPut mode.
//!
//! \PinUsed  PB18 : LED pin
//!
//! \describe When the program runs the LED will be flashing.
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
#define DEBUG
#define TICK_SLOW       ((unsigned long)0xFFFFF)
#define LED1            PB18

/* Private function prototypes **********************************************/
void GPIO_LED_Example(void);
static void LED_Init(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup GPIO_Example GPIO Example
//!     	@{
//!       		\addtogroup GPIO_LED_Example LED
//!        		@{
//!
//! \brief  The GPIO_LED_Example function illustrates the GPIO to light LED
//!
//! \return None
//
//*****************************************************************************
void GPIO_LED_Example(void)
{

    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);

    /********************** Initialize GPIO peripheral *******************/
    LED_Init();

    while(1)
    {
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
