//******************************************************************************
//
//! \file     RTC_Tick_Int_Example.c
//!
//! \brief    This example is show how to use RTC's Tick Function .
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!
//! \describe When the program is running the state of the indicator lights
//!           turn every 1 second
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

/* Private variables *********************************************************/
static xtTime tTime;
static unsigned char status = 0;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void RTC_Init(void);
static unsigned long xRTCTickCallback(void *pvCBData, unsigned long ulEvent,
                           unsigned long ulMsgParam, void *pvMsgData);
void RTC_Tick_Int_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup RTC_Example RTC Example
//!     	@{
//!       		\addtogroup RTC_Tick_Int_Example Tick Int
//!       		@{
//!
//! \brief  The example function for the Tick function
//!
//! \return None
//
//*****************************************************************************
void RTC_Tick_Int_Example(void)
{   
    /********************** Configure System clock *************************/
	xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);
    
    LED_Init();

    #if Use_Uart_Debug
    Uart_Init();
    #endif

    RTC_Init();

    while(1);
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
//! \brief  The RTC_Init function Used to Initialize RTC
//!
//! \return None
//
//*****************************************************************************
static void RTC_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2(xRTC_BASE);

    /******************** Configure RTC Peripheral *************************/
    xRTCTimeInit();

    tTime.ulSecond = 0;
    tTime.ulMinute = 10;
    tTime.ulHour = 11;
    tTime.ulMDay = 12;
    tTime.ulMonth = 10; 
    tTime.ulYear = 2014; 
    tTime.ulWDay = 6;
    xRTCTimeWrite(&tTime, xRTC_TIME_CURRENT);

    /********************Enables Tick interrupt****************************/
    xRTCIntEnable(xRTC_INT_SECOND);
    xRTCIntCallbackInit(xRTCTickCallback);  
    xIntEnable(xINT_RTC);

    /**************************Start RTC************************************/
    xRTCStart();
}
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
    /********************** Configure GPIO Port ****************************/
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
//! \brief  The callback function for the Tick function
//!
//! \return 0
//
//*****************************************************************************
static unsigned long xRTCTickCallback(void *pvCBData, unsigned long ulEvent,
                           unsigned long ulMsgParam, void *pvMsgData)
{
    if(0 == status)
    {
        xGPIOSPinWrite(LED1, 0);
        status = 1;
    }
    else
    {
        xGPIOSPinWrite(LED1, 1);
        status = 0;
    }
#if Use_Uart_Debug
    xRTCTimeRead(&tTime, xRTC_TIME_CURRENT);
    printf("Time:%d:%d:%d\n\r",tTime.ulHour,tTime.ulMinute,tTime.ulSecond);
    printf("Date:%d-%d-%d\n\r",tTime.ulYear,tTime.ulMonth,tTime.ulMonth);
#endif
    return 0;
}
