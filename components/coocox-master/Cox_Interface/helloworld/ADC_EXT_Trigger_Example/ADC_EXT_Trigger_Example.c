//******************************************************************************
//
//! \file     ADC_EXT_Trigger_Example.c
//!
//! \brief    This example show how to use ADC module to read 1 channel analog data.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA25 : ADC0 Channel 2
//!           PC0  : PWMB Channel 1
//!           PC10 : EXINT0 ADC Trigger input
//!
//! \describe This example is Show how to configure ADC into Single channel sampling
//!           mode. When program is running,We can use the PWM wave output as an
//!           external interrupt trigger pulse. The LED's status will toggle When the
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
//******************************************************************************
#include <stdio.h>
#include "CoX.h"

/* Private define ************************************************************/

#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)

#define LED1                   PB18

#define ADC_PORT               xADC0_BASE
#define ADC_CHANNEL            2
#define ADC_CHANNEL_PIN        PA25
#define ADC_Trigger_PIN        PC10

#define PWM_Base               xPWMB_BASE
#define PWM_CH1_PIN            PC0

/* Register define ************************************************************/
#define IOCON_P2_10           (*(volatile unsigned long*)0x4002C128)

#define EXTINT                (*(volatile unsigned long*)0x400FC140)
#define EXTMODE               (*(volatile unsigned long*)0x400FC148)
#define EXTPOLAR              (*(volatile unsigned long*)0x400FC14C)

#define ISER0                 (*(volatile unsigned long*)0xE000E100)
#define PCONP                 (*(volatile unsigned long*)0x400FC0C4)

/* Private variables *********************************************************/
static unsigned int Status = 0 ;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void ADC_Init(void);
static void PWM_Init(void);
static void EXINT_Init(void);
static void EINT0IntHandler(void);
static unsigned long ADCEINT0Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData );
void ADC_EXT_Trigger_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//! 		\addtogroup ADC_Example ADC Example
//!     	@{
//!     		\addtogroup ADC_EXT_Trigger_Example EXT Trigger
//!         	@{
//!
//! \brief  The ADC_EXT_Trigger_Example function Used to Initialize ADC peripheral
//!
//! \return None
//
//*****************************************************************************
void ADC_EXT_Trigger_Example(void)
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

    /********************** Initialize EXINT Peripheral *******************/
    EXINT_Init();

    /********************** Initialize PWM Peripheral *********************/
    PWM_Init();

    while(1)
    {

        xSysCtlDelay(xSysCtlClockGet()/40);
    }
}
//*****************************************************************************
//
//!		  	@}
//!		  @}
//!    @}
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
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOC);

    /********************** Configure Peripheral'S IO **********************/

	xSPinTypeADC(ADC2, ADC_CHANNEL_PIN);

    /********************** Configure ADC *********************************/
	xADCConfigure(ADC_PORT, xADC_TRIGGER_EXT_EINT0, xADC_TRIGGER_EXT_EINT0);

	// Enable the channel
	xADCStepConfigure(ADC_PORT, 0, ADC_CHANNEL);

    xADCIntEnable(xADC0_BASE, 0);
    xADCIntCallbackInit(xADC0_BASE, ADCEINT0Callback);
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
//! \brief  The EXINT_Init function Used to Initialize EXINT peripheral
//!
//! \return None
//
//*****************************************************************************
static void EXINT_Init(void)
{
	// Configure Exint0
	EXTMODE |= 0x1<<0;
    EXTPOLAR &= ~(0x1<<0);
    ISER0 |= (0x1<<18);
    // Configure Exint0 peripheral'IO
	IOCON_P2_10 = (IOCON_P2_10&(~0x7))|(0x1<<0);
	#if Use_Uart_Debug
	printf(" Exint0 Initialize Succeed ! \r\n");
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
//! \brief   The Callback function for EINT0Int
//!
//! \return None
//
//*****************************************************************************
static void EINT0IntHandler(void)
{
    // Clear the interrupt flag bit
	EXTINT |= (0x1<<0);
    #if Use_Uart_Debug
    printf(" Exint0 interrupt !\r\n");
    #endif
}

//*****************************************************************************
//
//! \brief   The Callback function for ADCEINT0Int
//!
//! \return None
//
//*****************************************************************************
static unsigned long ADCEINT0Callback( void *pvCBData, unsigned long ulEvent,
                                unsigned long ulMsgParam, void *pvMsgData )
{
    unsigned long adc_value = ((xHWREG(xADC0_BASE + ADC_DR2) >> 4) & 0xFFF);
    //xADCDataGet(xADC0_BASE, &adc_value);
    #if Use_Uart_Debug
    printf("ADC conversion value = %d\n",adc_value);
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
