//******************************************************************************
//
//! \file     PWM_Match_Interrupt_Example.c
//!
//! \brief    This example is used to demonstrate the use of the PWM interrupt
//!           function.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PC0  : PWMB Channel 1
//!
//! \describe This example is Show how to configure PWM to toggle mode. When
//!           the LED is flashing says it has completed all initialization
//!           section. Each into the interrupt modify the PWM duty cycle, and
//!           read it out to print by UART.
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
#define PWM_Base               xPWMB_BASE
#define PWM_CH1_PIN            PC0

/* Private variables *********************************************************/
static unsigned long ultemp   = 0;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void PWM_Init(void);
static unsigned long user_Callback( void *pvCBData, unsigned long ulEvent,
                                    unsigned long ulMsgParam, void *pvMsgData );
void PWM_Match_Interrupt_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup PWM_Example PWM Example
//!     	@{
//!       		\addtogroup PWM_Match_Interrupt_Example Match Interrupt
//!        		@{
//!
//! \brief  The PWM_Match_Interrupt_Example function illustrates the
//!         PWM signal on 6 Channels in single edge mode
//!
//! \return None
//
//*****************************************************************************
void PWM_Match_Interrupt_Example(void)
{

	unsigned char long_duty = 10;
	/********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);

    /********************** Initialize System peripheral *******************/
    LED_Init();
    #if Use_Uart_Debug
    UART_Init();
    #endif
    PWM_Init();

	xGPIOSPinWrite(LED1, 1);
	xSysCtlDelay(TICK_SLOW);
	xGPIOSPinWrite(LED1, 0);
	xSysCtlDelay(TICK_SLOW);

    while(1)
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
//! \brief  The LED_Init function Used to Initialize PWM peripheral
//!
//! \return None
//
//*****************************************************************************
static void PWM_Init(void)
{
	/************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2( xGPIOSPinToPort( PWM_CH1_PIN ) );
    xSysCtlPeripheralEnable2( PWM_Base );

    /******************** Configure Peripheral'S IO **********************/
    xSPinTypePWM( PWM1, PWM_CH1_PIN );

    /********************** Configure PWM ********************************/
	xPWMInitConfigure( PWM_Base, PWM_CHANNEL1, xPWM_TOGGLE_MODE|
									 xPWM_OUTPUT_INVERTER_DIS |
										   xPWM_DEAD_ZONE_DIS );
	// Set freq
	xPWMFrequencySet( PWM_Base, PWM_CHANNEL1, 100 );
	// Set duty
	xPWMDutySet( PWM_Base, PWM_CHANNEL1, 50 );
	// Set output enable
	xPWMOutputEnable( PWM_Base, PWM_CHANNEL1 );

    // Set interrupt call back
    xPWMIntCallbackInit( PWM_Base, user_Callback );

    // PWM output interrupt enable
    xPWMIntEnable( PWM_Base, PWM_CHANNEL1, xPWM_INT_PWM );

    // NVIC interrupt enable
    xIntEnable(xSysCtlPeripheralIntNumGet(PWM_Base));
    /********************** Enable/Start PWM *****************************/
    xPWMStart( PWM_Base, PWM_CHANNEL1 );

    #if Use_Uart_Debug
    printf(" PWM finished initialize! \r\n");
    #endif
}

//*****************************************************************************
//
//! \breif PWM interrupt handler.
//!
//! \return 0
//
//*****************************************************************************
static unsigned long user_Callback( void *pvCBData, unsigned long ulEvent,
                                    unsigned long ulMsgParam, void *pvMsgData )
{
    // Change the PWM's duty
    ultemp += 5;
    if ( ultemp > 100 )
	{
		 ultemp = 0;
         #if Use_Uart_Debug
		 printf(" PWM Reset \r\n");
         #endif
		// xPWMStop( PWM_Base, PWM_CHANNEL1 );
		// xPWMIntDisable(PWM_Base, PWM_CHANNEL1, xPWM_INT_PWM);
	}
	xPWMDutySet( PWM_Base, PWM_CHANNEL1, ultemp );
    #if Use_Uart_Debug
    printf(" PWM Duty Get Value :%d %% \r\n",xPWMDutyGet( PWM_Base, PWM_CHANNEL1 ));
    #endif
    return 0;
}
