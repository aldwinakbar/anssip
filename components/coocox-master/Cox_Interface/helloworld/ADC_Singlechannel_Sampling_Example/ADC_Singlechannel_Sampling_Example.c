//******************************************************************************
//
//! \file     ADC_Singlechannel_Sampling_Example.c
//!
//! \brief    This example show how to use ADC module to read 1 channel analog data.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA23 : ADC0 Channel 0
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
//******************************************************************************
#include "stdio.h"
#include "CoX.h"

/* Private define ************************************************************/
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1                   PB18
#define ADC_PORT               xADC0_BASE
#define ADC_CHANNEL            xADC_CTL_CH0

/* Private variables *********************************************************/
static unsigned long ADCDataBuf = 0;
static unsigned int Status = 0 ;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void ADC_Init(void);
void ADC_Singlechannel_Sampling_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup ADC_Example ADC Example
//!     	@{
//!       		\addtogroup ADC_Singlechannel_Sampling_Example Singlechannel Sampling
//!        		@{
//!
//! \brief  The ADC_Singlechannel_Sampling_Example function Used to Initialize ADC peripheral
//!
//
//*****************************************************************************
void ADC_Singlechannel_Sampling_Example(void)
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

    /********************** Initialize WDT Peripheral *********************/
    ADC_Init();

    while(1)
    {
        // Get Data
        xADCDataGet(ADC_PORT, &ADCDataBuf);
    	//ADCDataBuf = ADCDataRead(ADC_PORT, ADC_CHANNEL);
        #if Use_Uart_Debug
        printf("ADC conversion value = %d \r\n",  ADCDataBuf);
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
//
//*****************************************************************************
static void ADC_Init(void)
{
    /********************** Configure peripheral Power *********************/
	xSysCtlPeripheralEnable2(ADC_PORT);
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);

    /********************** Configure Peripheral'S IO **********************/
	xSPinTypeADC(ADC0, PA23);

    /********************** Configure ADC *********************************/
	xADCConfigure(ADC_PORT, xADC_MODE_SCAN_CONTINUOUS, xADC_TRIGGER_PROCESSOR);

	// Enable the channel
	xADCStepConfigure(ADC_PORT, 0, ADC_CHANNEL);

    /********************** Enable ADC ************************************/
	// Start ADC Channel 0, convert now.
	xADCEnable(ADC_PORT);

	xADCProcessorTrigger(ADC_PORT);

    #if Use_Uart_Debug
	printf(" ADC Initialize Succeed ! \r\n");
    #endif

}

#if Use_Uart_Debug
//*****************************************************************************
//
//! \brief  The UART_Init function Used to Initialize Uart peripheral
//!
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
