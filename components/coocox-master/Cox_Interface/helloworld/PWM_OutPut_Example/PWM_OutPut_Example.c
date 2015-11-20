//******************************************************************************
//
//! \file     PWM_OutPut_Example.c
//!
//! \brief    This example is Show how to configure PWM to toggle mode.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PC0  : PWMB Channel 1
//!           PC1  : PWMB Channel 2
//!           PC2  : PWMB Channel 3
//!           PC3  : PWMB Channel 4
//!           PC4  : PWMB Channel 5
//!           PC5  : PWMB Channel 6
//!
//! \describe This example is Show how to configure PWM to toggle mode. When
//!           the LED is flashing says it has completed all initialization
//!           section. The duty cycle of each channel will be sent via Uart
//!           on the computer.
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
#define PWM_CH2_PIN            PC1
#define PWM_CH3_PIN            PC2
#define PWM_CH4_PIN            PC3
#define PWM_CH5_PIN            PC4
#define PWM_CH6_PIN            PC5

/* Private variables *********************************************************/
static unsigned long ultemp   = 0;
static unsigned long PWM_CH[] = {PWM_CHANNEL1,PWM_CHANNEL2,PWM_CHANNEL3,
		                         PWM_CHANNEL4,PWM_CHANNEL5,PWM_CHANNEL6,};

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void PWM_Init(void);
void PWM_OutPut_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup PWM_Example PWM Example
//!     	@{
//!       		\addtogroup PWM_OutPut_Example OutPut
//!        		@{
//!
//! \brief  The PWM_Signal_Edge_Example function illustrates the
//!         PWM signal on 6 Channels in single edge mode
//!
//! \return 0
//
//*****************************************************************************
void PWM_OutPut_Example(void)
{

    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);

    /********************** Initialize System peripheral *******************/
    LED_Init();
    #if Use_Uart_Debug
    Uart_Init();
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
//! \return 0
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
//! \return 0
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
//! \brief  The PWM_Init function Used to Initialize PWM peripheral
//!
//! \return 0
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
    xSPinTypePWM( PWM2, PWM_CH2_PIN );
    xSPinTypePWM( PWM3, PWM_CH3_PIN );
    xSPinTypePWM( PWM4, PWM_CH4_PIN );
    xSPinTypePWM( PWM5, PWM_CH5_PIN );
    xSPinTypePWM( PWM6, PWM_CH6_PIN );
    for(i=0;i<6;i++)
    {
    /********************** Configure PWM ********************************/
        xPWMInitConfigure( PWM_Base, PWM_CH[i], xPWM_TOGGLE_MODE|
    	                                 xPWM_OUTPUT_INVERTER_DIS |
                                               xPWM_DEAD_ZONE_DIS );
        // Set freq
        xPWMFrequencySet( PWM_Base, PWM_CH[i], 10 );
        // Set duty
        xPWMDutySet( PWM_Base, PWM_CH[i], 10*(i + 1) );
        // Set output enable
        xPWMOutputEnable( PWM_Base, PWM_CH[i] );
    /********************** Enable/Start PWM *****************************/
        xPWMStart( PWM_Base, PWM_CH[i] );
		#if Use_Uart_Debug
	    printf(" PWM Duty Get Value :%d %% \r\n",xPWMDutyGet( PWM_Base, PWM_CH[i] ));
		#endif
    }
}
