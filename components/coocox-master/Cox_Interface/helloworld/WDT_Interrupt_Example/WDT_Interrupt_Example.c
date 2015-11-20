//******************************************************************************
//
//! \file     WDT_Interrupt_Example.c
//!
//! \brief    This example is used to demonstrate the use of the WDT interrupt
//!           function.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//! 
//! \describe This example is Show how to configure WDT timer into interrupt
//!           mode. When program is running. If we don't feed the dog, then
//!           The status of LED  will flip.
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
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1                   PB18
#define WDT_TIMEOUT 	       5000000

/* Private variables *********************************************************/
static unsigned char Status = 0;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void WDT_Init(void);
static void LED_Init(void);
static unsigned long user_Callback( void *pvCBData, unsigned long ulEvent,
                                    unsigned long ulMsgParam, void *pvMsgData );

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup WDT_Example WDT Example
//!     	@{
//!       		\addtogroup WDT_Interrupt_Example Interrupt
//!        		@{
//!
//! \brief  WDT_Interrupt_Example used to show how to use WDT in Interrupt Mode.
//!
//! \return None
//
//*****************************************************************************
void WDT_Interrupt_Example(void)
{
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_XTAL_12MHZ | xSYSCTL_OSC_MAIN);
    xSysCtlDelay(TICK_SLOW);

    #if Use_Uart_Debug
    /********************** Initialize Uart Peripheral ********************/
    UART_Init();
    #endif

    /********************** Initialize GPIO Peripheral ********************/
    LED_Init();

    /********************** Initialize WDT Peripheral *********************/
    WDT_Init();


    while(1)
    {
        xSysCtlDelay(10*TICK_SLOW);

        // Feed dog
    	xWDTEnable( xWDT_BASE );
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

#if Use_Uart_Debug
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
    xSPinTypeUART(UART3TX, PA0);
    xSPinTypeUART(UART3RX, PA1);

    /********************** Configure UART *********************************/
    xUARTConfigSet(xUART3_BASE, 115200, (xUART_CONFIG_WLEN_8 |
                                         xUART_CONFIG_STOP_1 |
                                         xUART_CONFIG_PAR_NONE));

    /********************** Enable UART ************************************/
    xUARTEnable(xUART3_BASE, (xUART_BLOCK_UART | xUART_BLOCK_TX | xUART_BLOCK_RX));
}
#endif

static void WDT_Init(void)
{

    // Set WDT clock and interval time.
    xWDTInit(xWDT_BASE, xWDT_S_INTSL, WDT_TIMEOUT);

    // Set WDT interrupt and initionalize callback.
    xWDTIntCallbackInit(xWDT_BASE, user_Callback);

    // Enable WDT wake up function.
    xWDTFunctionEnable(xWDT_BASE, xWDT_INT_FUNCTION );

    xIntEnable( xINT_WDT );

    // Start WDT timer.
    xWDTEnable( xWDT_BASE );

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

    #if Use_Uart_Debug
	printf(" LED Initialize Succeed ! \r\n");
    #endif

}

//*****************************************************************************
//! \breif Wdt interrupt handler.
//!
//! \return None
//
//*****************************************************************************
static unsigned long user_Callback( void *pvCBData, unsigned long ulEvent,
                                     unsigned long ulMsgParam, void *pvMsgData )
{
    /* Code...*/
    if(0 == Status)
    {
        xGPIOSPinWrite(LED1, 0);
        Status = 1;
    }
    else
    {
        xGPIOSPinWrite(LED1, 1);
        Status = 0;
    }

    #if Use_Uart_Debug
	printf(" WDT Interrupt! \r\n");
    #endif
    return 0;
}
