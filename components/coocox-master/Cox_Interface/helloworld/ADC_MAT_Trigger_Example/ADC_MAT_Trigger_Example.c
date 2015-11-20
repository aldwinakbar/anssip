//******************************************************************************
//
//! \file     ADC_MAT_Trigger_Example.c
//!
//! \brief    This example show how to use ADC module to read 1 channel analog data.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA25 : ADC0 Channel 2
//!           PC0  : PWMB Channel 1
//!           PB27 : ADC Capture Trigger Pin
//!
//! \describe This example is Show how to configure ADC into Single channel sampling
//!           mode. When program is running, The LED's status will toggle When the
//!           ADC values are read. And the value of the ADC conversion will be send
//!           to PC by Uart.
//!
//! \version  1.0
//! \date     10/27/2014
//! \author   CooCox
//! \copy
//!
//! Copyright (c) 2009-2014 CooCox.  All rights reserved.
//
//*****************************************************************************
#include "stdio.h"
#include "CoX.h"

/* Private define ************************************************************/
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1                   PB18
#define ADC_PORT               xADC0_BASE
#define ADC_CHANNEL            xADC_CTL_CH2
#define ADC_CHANNEL_PIN        PA25

/* Private variables *********************************************************/
static unsigned int Status = 0 ;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void ADC_Init(void);
static void Timer_Init(void);
static unsigned long ADCMAT01Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData );
static unsigned long MAT01Callback(void *pvCBData,  unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData );
void ADC_MAT_Trigger_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup ADC_Example ADC Example
//!     	@{
//!       		\addtogroup ADC_MAT_Trigger_Example MAT Trigger
//!        		@{
//!
//! \brief  The ADC_MAT_Trigger_Example function Used to Initialize ADC peripheral
//!
//! \return None
//
//*****************************************************************************
void ADC_MAT_Trigger_Example(void)
{
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_XTAL_12MHZ | xSYSCTL_OSC_MAIN);
    xSysCtlDelay(0x10000);

    #if Use_Uart_Debug
    /********************** Initialize Uart Peripheral ********************/
    UART_Init();
    #endif

    /********************** Initialize GPIO Peripheral ********************/
    LED_Init();

    /********************** Initialize TIMER Peripheral ********************/
    Timer_Init();

    /********************** Initialize ADC Peripheral *********************/
    ADC_Init();

    while(1)
    {

        xSysCtlDelay(xSysCtlClockGet()/40);
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
//! \brief  The ADC_Init function Used to Initialize ADC peripheral
//!
//! \return None
//
//*****************************************************************************
static void ADC_Init(void)
{
    /********************** Configure peripheral Power *********************/
	xSysCtlPeripheralEnable2(ADC_PORT);
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);

    /********************** Configure Peripheral'S IO **********************/
	xSPinTypeADC(ADC2, ADC_CHANNEL_PIN);

    /********************** Configure ADC *********************************/
	xADCConfigure(ADC_PORT, xADC_MODE_SCAN_CONTINUOUS, xADC_TRIGGER_EXT_MAT01);

	// Enable the channel
	xADCStepConfigure(ADC_PORT, 0, ADC_CHANNEL);

    xADCIntEnable(xADC0_BASE, 0);
    xADCIntCallbackInit(xADC0_BASE, ADCMAT01Callback);
    xIntEnable(xSysCtlPeripheralIntNumGet(xADC0_BASE));

    /********************** Enable ADC ************************************/
	// Start ADC Channel 0, convert now.
	xADCEnable(ADC_PORT);
	xADCProcessorTrigger(ADC_PORT);

    #if Use_Uart_Debug
	printf(" ADC Initialize Succeed ! \r\n");
    #endif

}
//*****************************************************************************
//
//! \brief  The Timer_Init function Used to Initialize Timer peripheral
//!         Only MAT0.1, MAT0.3, MAT1.0 and MAT1.1 has the function of
//!         timing trigger an ADC.
//!
//! \return None
//
//*****************************************************************************
static void Timer_Init(void)
{
    /********************** Configure peripheral Power *********************/
    xSysCtlPeripheralEnable2(xTIMER0_BASE);

    /********************** Configure Peripheral'S IO **********************/
    // Configure P27 as CAP0.1
    // It's does not require that the MAT0.1 function appear on a device pin
    xSPinTypeTimer(TIMCCP1, PB27);

    /********************** Configure Timer *********************************/
    // Initialize timer 0, prescale count time of 100uS
    xTimerInitConfig(xTIMER0_BASE, xTIMER_CHANNEL1,xTIMER_MODE_PERIODIC,100);

    // Set Match value, count value of 10000 (10000 * 100uS = 1S --> 1Hz)
    xTimerMatchSet(xTIMER0_BASE, xTIMER_CHANNEL1, 10000);

    // Configure Timer Interrupt
    // Doesn't have to use the interrupt function
    xTimerIntCallbackInit(xTIMER0_BASE, MAT01Callback);
    xTimerIntEnable(xTIMER0_BASE, TIMER_CHANNEL1, xTIMER_INT_MATCH);
    xIntEnable(xSysCtlPeripheralIntNumGet(xTIMER0_BASE));

    /********************** Enable Timer ***********************************/
    xTimerStart(xTIMER0_BASE, xTIMER_CHANNEL1);

    #if Use_Uart_Debug
	printf(" Timer Initialize Succeed ! \r\n");
	printf(" Timer Initialize frequency is %d Hz! \r\n",1);
    #endif
}

#if Use_Uart_Debug
//*****************************************************************************
//
//! \brief  The UART_Init function Used to Initialize Uart peripheral
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

    #if Use_Uart_Debug
	printf(" Uart Initialize Succeed ! \r\n");
    #endif

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

    xGPIOSPinWrite(LED1, 1);

    #if Use_Uart_Debug
	printf(" LED Initialize Succeed ! \r\n");
    #endif

}
//*****************************************************************************
//
//! \brief   The Callback function for ADC0 TIMER match trigger channel 1
//!
//! \return 0
//
//*****************************************************************************
static unsigned long ADCMAT01Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData )
{
    unsigned long adc_value;
    xADCDataGet(xADC0_BASE, &adc_value);
	#if Use_Uart_Debug
	printf("ADC conversion value = %d\n", adc_value);
	printf(" ADC0 match channel 1 Interrupt ! \r\n");
	#endif
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
    return 0;
}
//*****************************************************************************
//
//! \brief   The Callback function for TIMER match channel 1
//!
//! \return 0
//
//*****************************************************************************
static unsigned long MAT01Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData)
{
	#if Use_Uart_Debug
	printf(" TIMER0 match channel 1 Interrupt ! \r\n");
	#endif
    return 0;
}
