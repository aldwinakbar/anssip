//******************************************************************************
//
//! \file     ADC_Capture_Trigger_Example.c
//!
//! \brief    This example show how to use ADC module to read 1 channel analog data.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA23 : ADC0 Channel 0
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

#define TIMER_BASE             xTIMER0_BASE
#define TIMER_CHANNEL          xTIMER_CHANNEL1
#define ADC_Trigger_PIN        PB27

#define PWM_Base               xPWMB_BASE
#define PWM_CH1_PIN            PC0

/* Private variables *********************************************************/
static unsigned int Status = 0 ;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void ADC_Init(void);
static void PWM_Init(void);
static void Timer_Init(void);
static unsigned long CAP01Callback(void *pvCBData,  unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData );
static unsigned long ADCCAP01Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData );
void ADC_Capture_Trigger_Example(void);
//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup ADC_Example ADC Example
//!     	@{
//!       		\addtogroup ADC_Capture_Trigger_Example Capture Trigger
//!        		@{
//! \brief  The ADC_Capture_Trigger_Example function Used to Initialize ADC peripheral
//!
//! \return None
//
//*****************************************************************************
void ADC_Capture_Trigger_Example(void)
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

    /********************** Initialize ADC Peripheral *********************/
    ADC_Init();

    /********************** Initialize TIMER Peripheral ********************/
    Timer_Init();

    /********************** Initialize PWM Peripheral *********************/
    PWM_Init();

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
	xADCConfigure(ADC_PORT, xADC_MODE_SCAN_CONTINUOUS, xADC_TRIGGER_EXT_CAP01);

	// Enable the channel
	xADCStepConfigure(ADC_PORT, 0, ADC_CHANNEL);


    xADCIntEnable(xADC0_BASE, 0);
    xADCIntCallbackInit(xADC0_BASE, ADCCAP01Callback);
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
//!         only P1.27 and P2.10 have the ability to capture trigger an ADC
//!
//! \return None
//
//*****************************************************************************
static void Timer_Init(void)
{
    /********************** Configure peripheral Power *********************/
    xSysCtlPeripheralEnable2(TIMER_BASE);
    xSysCtlPeripheralEnable2(xGPIOSPinToPort(ADC_Trigger_PIN));

    /********************** Configure Peripheral'S IO **********************/
    // Configure PB27 as CAP0.1
    xSPinTypeTimer(TIMCCP1,ADC_Trigger_PIN);

    /********************** Configure Timer *********************************/
    // Initialize timer , period set is 1s
    xTimerInitConfig(TIMER_BASE, TIMER_CHANNEL,TIMER_MODE_CAPTURE,1000000);

    xTimerCaptureModeSet(TIMER_BASE, TIMER_CHANNEL,TIMER_CAP_MODE_CAP);

    xTimerCaptureEdgeSelect(TIMER_BASE, TIMER_CHANNEL,TIMER_CAP_BOTH);

    // Configure Timer Interrupt
    xTimerIntCallbackInit(TIMER_BASE, CAP01Callback);
    xTimerIntEnable(TIMER_BASE, TIMER_CHANNEL, xTIMER_INT_CAP_EVENT);
    xIntEnable(xSysCtlPeripheralIntNumGet(TIMER_BASE));

    /********************** Enable Timer ***********************************/
    xTimerStart(TIMER_BASE, TIMER_CHANNEL);

	#if Use_Uart_Debug
	printf(" Timer Initialize Succeed ! \r\n");
	printf(" Timer Initialize frequency is %d Hz! \r\n",1);
	#endif
}

//*****************************************************************************
//
//! \brief  The PWM_Init function Used to Initialize PWM peripheral
//!
//! \return None
//
//*****************************************************************************
static void PWM_Init(void)
{
    unsigned int i;
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
    /********************** Enable/Start PWM *****************************/
	xPWMStart( PWM_Base, PWM_CHANNEL1 );

    #if Use_Uart_Debug
	printf(" PWM Initialize Succeed ! \r\n");
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
//! \brief   The Callback function for TIMER0 CAPTURE CHANNEL 1
//!
//! \return 0
//
//*****************************************************************************
static unsigned long CAP01Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData)
{
	#if Use_Uart_Debug
	printf(" TIMER0 CAPTURE CHANNEL 1 Interrupt ! \r\n");
	#endif
    return 0;
}

//*****************************************************************************
//
//! \brief   The Callback function for ADC0 CAPTURE CHANNEL 1
//!
//! \return 0
//
//*****************************************************************************
static unsigned long ADCCAP01Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData )
{
    unsigned long adc_value;
    xADCDataGet(xADC0_BASE, &adc_value);
    #if Use_Uart_Debug
    printf("ADC conversion value = %d\n", adc_value);
	printf(" ADC0 CAPTURE CHANNEL 1 Interrupt ! \r\n");
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
