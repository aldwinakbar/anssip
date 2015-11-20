//******************************************************************************
//
//! \file    Timer_Toggle_Mode_Example.c
//!
//! \brief    Show how to configure timer into Toggle mode.
//!
//! \PinUsed  PB29 : Timer0 channel1 match output pin
//!           PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!
//! \describe This example is Show how to configure timer into Continuous mode.
//!           When program is running. The status of LED and timer output pin
//!           will toggle.
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
#define TIM_PIN   	           PB29


/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void Timer_Init(void);
static unsigned long Timer0Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData);
void Timer_Toggle_Mode_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup TIMER_Example TIMER Example
//!     	@{
//!       		\addtogroup Timer_Toggle_Mode_Example Toggle Mode
//!        		@{
//!
//! \brief  The Timer_Toggle_Mode_Example function illustrates the
//!         timer in single toggle mode
//!
//*****************************************************************************
void Timer_Toggle_Mode_Example(void)
{
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(TICK_SLOW);

    /********************** Initialize System peripheral *******************/
    #if Use_Uart_Debug
    UART_Init();
    #endif
    Timer_Init();

    while (1)
    {

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
//*****************************************************************************
static void Timer_Init(void)
{
    /********************** Configure peripheral Power *********************/
    xSysCtlPeripheralEnable2(xTIMER0_BASE);

    /********************** Configure Peripheral'S IO **********************/
    // Conifg PB29 as MAT0.1
    xSPinTypeTimer(TIMCCP1,TIM_PIN);

    /********************** Configure Timer *********************************/
    // Initialize timer 0, prescale count time of 100uS
    xTimerInitConfig(xTIMER0_BASE, xTIMER_CHANNEL1,xTIMER_MODE_TOGGLE,100);

    // Set Match value, count value of 10000 (10000 * 100uS = 1S --> 1Hz)
    xTimerMatchSet(xTIMER0_BASE, TIMER_CHANNEL1, 10000);

    xTimerIntCallbackInit(xTIMER0_BASE, Timer0Callback);

    xTimerIntEnable(xTIMER0_BASE, xTIMER_CHANNEL1,xTIMER_INT_MATCH);

    xIntEnable(xSysCtlPeripheralIntNumGet(xTIMER0_BASE));

    /********************** Enable Timer ***********************************/
    xTimerStart(xTIMER0_BASE, xTIMER_CHANNEL1);

}

#if Use_Uart_Debug
//*****************************************************************************
//
//! \brief  The UART_Init function Used to Init Uart peripheral
//!
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


//*****************************************************************************
//
//! \brief  The Timer0Callback function Used to Timer0¡®s CallBack function
//!
//*****************************************************************************
static unsigned long Timer0Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData)
{
    /*  Clear Interrupt */
	TimerIntStatusClear(xTIMER0_BASE, xTIMER_INT_MATCH);

    #if Use_Uart_Debug
	printf(" Timer MAT Interrupt! \r\n");
	printf(" Timer counter Value is %d  \r\n",xTimerValueGet(xTIMER0_BASE, xTIMER_CHANNEL1));
    #endif
    return 0;
}
