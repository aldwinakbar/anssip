//******************************************************************************
//
//! \file     ADC_Multichannel_Sampling_Example.c
//!
//! \brief    This example show how to use ADC module to read 8 channels analog data.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA23 : ADC0 Channel 0
//!           PA24 : ADC0 Channel 1
//!           PA25 : ADC0 Channel 2
//!           PA26 : ADC0 Channel 3
//!           PA30 : ADC0 Channel 4
//!           PA31 : ADC0 Channel 5
//!       #if defined(LPC_175x) || defined (LPC_176x)
//!           PA3  : ADC0 Channel 6
//!           PA2  : ADC0 Channel 7
//!       #elif defined(LPC_177x) || defined (LPC_178x)
//!           PA12 : ADC0 Channel 6
//!           PA13 : ADC0 Channel 7
//!       #endif
//!
//! \describe This example is Show how to configure ADC into Multichannel sampling
//!           mode. When program is running, The LED's status will toggle When the
//!           ADC values are read. And the value of the ADC conversion will be send
//!           to PC by Uart.
//
//******************************************************************************
#include "stdio.h"
#include "CoX.h"

/* Private define ************************************************************/
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1                   PB18
#define ADC_PORT               xADC0_BASE
#define ADC_CHANNEL            xADC_CTL_CH5

/* Private variables *********************************************************/
unsigned long ADCDataBuf[8] = {0};
unsigned int Status = 0 ;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void ADC_Init(void);
void ADC_Multichannel_Sampling_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup ADC_Example ADC Example
//!     	@{
//!       		\addtogroup ADC_Multichannel_Sampling_Example Multichannel Sampling
//!        		@{
//!
//! \brief  The ADC_Multichannel_Sampling_Example function Used to Initialize ADC peripheral
//!
//! \return None
//
//*****************************************************************************
void ADC_Multichannel_Sampling_Example(void)
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
        xADCDataGet(ADC_PORT, ADCDataBuf);
        #if Use_Uart_Debug
        printf("value = %d, %d, %d\n", ADCDataBuf[0], ADCDataBuf[1], ADCDataBuf[5]);
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
//! \return None
//
//*****************************************************************************
static void ADC_Init(void)
{
    /********************** Configure peripheral Power *********************/
	xSysCtlPeripheralEnable2(ADC_PORT);
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOB);

    /********************** Configure Peripheral'S IO **********************/
	// Map ADC Channel 5
	// P1.31 ---> Ch_5
	//xHWREG(0x4002C044) = 0x55555000;
	//xHWREG(0x4002C04C) = 0x5 << 28;
	xSPinTypeADC(ADC0, PA23);
	xSPinTypeADC(ADC1, PA24);
	xSPinTypeADC(ADC2, PA25);
	xSPinTypeADC(ADC3, PA26);
	xSPinTypeADC(ADC4, PB30);
	xSPinTypeADC(ADC5, PB31);
    #if defined(LPC_175x) || defined (LPC_176x)
	xSPinTypeADC(ADC6, PA3);
	xSPinTypeADC(ADC7, PA2);
    #elif defined(LPC_177x) || defined (LPC_178x)
	xSPinTypeADC(ADC6, PA12);
	xSPinTypeADC(ADC7, PA13);
    #endif

    /********************** Configure ADC *********************************/
	xADCConfigure(ADC_PORT, xADC_MODE_SCAN_CONTINUOUS, xADC_TRIGGER_PROCESSOR);

	// Enable the channel
	xADCStepConfigure(ADC_PORT, 0, xADC_CTL_CH0);
	xADCStepConfigure(ADC_PORT, 1, xADC_CTL_CH1);
	xADCStepConfigure(ADC_PORT, 2, xADC_CTL_CH2);
	xADCStepConfigure(ADC_PORT, 3, xADC_CTL_CH3);
	xADCStepConfigure(ADC_PORT, 4, xADC_CTL_CH4);
	xADCStepConfigure(ADC_PORT, 5, ADC_CHANNEL);

    /********************** Enable ADC ************************************/
	// Start ADC Channel 5, convert now.
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
