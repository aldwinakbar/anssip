//******************************************************************************
//
//! \file     Timer_Capture_Mode_Example.c
//!
//! \brief    Show how to configure timer into capture mode.
//!
//! \PinUsed  PC0  : PWMB channel1 output pin
//!           PB23 : Timer3 channel0 capture input pin
//!           PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!
//! \describe This example is Show how to configure timer into Capture mode.
//!           When program is running, connected to the PWM's output pins and
//!           Timer's capture pin, The LED's status will toggle when timer
//!           pin capture the edge of the PWM pulse. The frequency will be
//!           send to PC by Uart.
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
#define TIMER_BASE             xTIMER3_BASE
#define TIMER_CHANNEL          xTIMER_CHANNEL0
#define LED1                   PB18
#define TIM_PIN   	           PA23

/* Private variables *********************************************************/
static unsigned char Status = 0;
static unsigned int Timer_Pwm_Counter = 0;
static unsigned int Timer_Pwm_Counter_Start_Value = 0;
static unsigned int Timer_Pwm_Counter_Stop_Value = 0;
static unsigned int Pwm_Frequency = 0;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void PWM_Init(void);
static void LED_Init(void);
static void Timer_Init(void);
static unsigned long Timer0Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData);
void Timer_Capture_Mode_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup TIMER_Example TIMER Example
//!     	@{
//!       		\addtogroup Timer_Capture_Mode_Example Capture Mode
//!        		@{
//!
//! \brief  The Timer_Capture_Mode_Example function show you how to use the
//!         timer capture mode frequency measurement
//!
//! \return None
//
//*****************************************************************************
void Timer_Capture_Mode_Example(void)
{
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(TICK_SLOW);

    /********************** Initialize System peripheral *******************/
    LED_Init();
    #if Use_Uart_Debug
    UART_Init();
    #endif
    PWM_Init();
    Timer_Init();

    while (1)
    {
         #if Use_Uart_Debug
    	 printf(" Timer Capture Example  \r\n");
         #endif
    	 xSysCtlDelay(TICK_SLOW*20);

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
//! \brief  The Timer_Init function Used to Initialize Timer peripheral
//!
//! \return None
//
//*****************************************************************************
static void Timer_Init(void)
{
    /********************** Configure peripheral Power *********************/
    xSysCtlPeripheralEnable2(TIMER_BASE);

    /********************** Configure Peripheral'S IO **********************/
    // Configure PA23 as CAP0.0
    xSPinTypeTimer(TIMCCP0,TIM_PIN);

    /********************** Configure Timer *********************************/
    // Initialize timer , period set is 1s
    xTimerInitConfig(TIMER_BASE, TIMER_CHANNEL,xTIMER_MODE_CAPTURE,1000000);

    xTimerCaptureModeSet(TIMER_BASE, TIMER_CHANNEL,xTIMER_CAP_MODE_CAP);

    xTimerCaptureEdgeSelect(TIMER_BASE, TIMER_CHANNEL,TIMER_CAP_BOTH);

    // Configure Timer Interrupt
    xTimerIntCallbackInit(TIMER_BASE, Timer0Callback);
    xTimerIntEnable(TIMER_BASE, TIMER_CHANNEL,xTIMER_INT_CAP_EVENT);
    xIntEnable(xSysCtlPeripheralIntNumGet(TIMER_BASE));

    /********************** Enable Timer ***********************************/
    xTimerStart(TIMER_BASE, TIMER_CHANNEL);
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
	/************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2( xGPIOSPinToPort( PC0 ) );
    xSysCtlPeripheralEnable2( xPWMB_BASE );

    /******************** Configure Peripheral'S IO **********************/
    xSPinTypePWM( PWM1, PC0 );

    /********************** Configure PWM ********************************/
	xPWMInitConfigure( xPWMB_BASE, PWM_CHANNEL1, xPWM_TOGGLE_MODE|
									    xPWM_OUTPUT_INVERTER_DIS |
											  xPWM_DEAD_ZONE_DIS );
	// Set Timer frequency
	xPWMFrequencySet( xPWMB_BASE, PWM_CHANNEL1, 100 );
	// Set Timer duty
	xPWMDutySet( xPWMB_BASE, PWM_CHANNEL1, 50 );
	// Set output enable
	xPWMOutputEnable( xPWMB_BASE, PWM_CHANNEL1 );

    /********************** Enable/Start PWM *****************************/
	xPWMStart( xPWMB_BASE, PWM_CHANNEL1 );

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
//! \brief  The Timer0Callback function Used to Timer0¡®s CallBack function
//!
//*****************************************************************************
static unsigned long Timer0Callback(void *pvCBData,  unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData)
{

	// PWM inputer Counter AddSelf
	Timer_Pwm_Counter++;
	//  Clear Interrupt
	TimerIntStatusClear(TIMER_BASE, TIMER_INT_CAP_CH_0);

    if(Timer_Pwm_Counter == 1)
    {
    	Timer_Pwm_Counter_Start_Value = xTimerValueGet(TIMER_BASE, TIMER_CHANNEL);
        #if Use_Uart_Debug
    	printf(" Timer Capture PWM Timer_Pwm_Counter_Start_Value is %d  \r\n",Timer_Pwm_Counter_Start_Value);
        #endif

    }
    if(Timer_Pwm_Counter >= 2)
    {
    	Timer_Pwm_Counter = 0;
    	Timer_Pwm_Counter_Stop_Value = xTimerValueGet(TIMER_BASE, TIMER_CHANNEL);
        #if Use_Uart_Debug
    	printf(" Timer Capture PWM Timer_Pwm_Counter_Stop_Value is %d  \r\n",Timer_Pwm_Counter_Stop_Value);
        #endif
    	// Calculate the frequency
    	Pwm_Frequency = xTimerPrescaleGet(TIMER_BASE, TIMER_CHANNEL)/(Timer_Pwm_Counter_Stop_Value-Timer_Pwm_Counter_Start_Value)*100/80;
        #if Use_Uart_Debug
    	printf(" Timer Capture PWM xTimer prescale  is    %d  \r\n",xTimerPrescaleGet(TIMER_BASE, TIMER_CHANNEL));
    	printf(" Timer Capture PWM xTimer capture Time is %d  \r\n",(Timer_Pwm_Counter_Stop_Value-Timer_Pwm_Counter_Start_Value));
    	printf(" Timer Capture PWM Frequency is %d Hz \r\n",Pwm_Frequency);
        #endif

    }

    /* LED Status Toggle ...*/
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
