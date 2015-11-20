//******************************************************************************
//! \file     UART_Interrupt_Example.c
//!
//! \brief    This example shows the use of UART port interrupt
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA2  : UART0 TX
//!           PA3  : UART0 RX
//!           PA10 : UART2 TX
//!           PA11 : UART2 RX
//!           PA25 : UART3 TX
//!           PA26 : UART3 RX
//!           PC0  : UART1 TX
//!           PC1  : UART1 RX
//!
//!\describe  When the system initialization finished, print the system information
//!           and prompt information. The system will make a different reaction
//!           depending on the input.
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
#define Use_Uart_PA01_Pin      1
#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define UART_COM               xUART3_BASE
#define LED1   		           PB18

/* Private variables *********************************************************/
static unsigned char menu1[] =
"\n\r********************************************************************************\n\r"
" UART Polling example \n\r"
"\t - MCU: LPC176x_7x_8x \n\r"
"\t - Core: ARM CORTEX-M3 \n\r"
"\t - UART Communication: 115200 bps \n\r"
" This example used to test UART component.\n\r"
" Receiving by keep polling the RBR register for character stored\n\r"
"  + Please press any key to be echoed\n\r"
"  + Press 'r' to re-show the welcome string\n\r"
"  + Press ESC to terminate\n\r"
"********************************************************************************\n\r";
static unsigned char menu2[] = "LPC17xx.UART Example of CoX3.0 \n\r";
static volatile unsigned long status = 1;

/* Private function prototypes **********************************************/
static void LED_Init(void);
static void UART_Init(void);
static void UART_Printf_Info(void);
static unsigned long UserUARTHandler(void *pvCBData, unsigned long ulEvent,
                              unsigned long ulMsgParam, void *pvMsgData);
void UART_Interrupt_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup UART_Example UART Example
//!     	@{
//!       		\addtogroup UART_Interrupt_Example Interrupt
//!        		@{
//!
//! \brief  The UART_Interrupt_Example function shows us the use of UART port
//!         interrupt function.
//!
//! \return None
//
//*****************************************************************************
void UART_Interrupt_Example(void)
{
    unsigned int i;

    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(0x10000);

    /********************** Initialize System peripheral *******************/
    LED_Init();
    UART_Init();

    /********************** Printing system information *******************/
    UART_Printf_Info();

    while (1)
	{
    	if(status == 1) // re-show
		{
			for(i = 0; i < sizeof(menu1); i++)
			{
				xUARTCharPut(UART_COM, menu1[i]);
			}
			xGPIOSPinWrite(LED1, 1);
			xSysCtlDelay(TICK_SLOW);
			xGPIOSPinWrite(LED1, 0);
			xSysCtlDelay(TICK_SLOW);
			status = 0;
		}
		if(status == 2) // Exit
		{
			for(i = 0; i < sizeof(menu2); i++)
			{
				xUARTCharPut(UART_COM, menu2[i]);
			}
			xGPIOSPinWrite(LED1, 1);
			xSysCtlDelay(TICK_SLOW);
			xGPIOSPinWrite(LED1, 0);
			xSysCtlDelay(TICK_SLOW);
			status = 0;
			xUARTIntDisable(UART_COM, xUART_INT_ERROR | xUART_INT_RX);
		}
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
//! \brief  The UART_Init function Used to Initialize Uart peripheral
//!
//! \return None
//
//*****************************************************************************
static void UART_Init(void)
{
    /********************** Configure peripheral Power *********************/
#if(UART_COM == xUART1_BASE)
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOC);
#else
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);
#endif
    xSysCtlPeripheralEnable2(UART_COM);

    /********************** Configure Peripheral'S IO **********************/
#if(UART_COM == xUART0_BASE)
    xSPinTypeUART(UART0TX, PA2);
    xSPinTypeUART(UART0RX, PA3);
#endif

#if(UART_COM == xUART1_BASE)
    xSPinTypeUART(UART1TX, PC0);
    xSPinTypeUART(UART1RX, PC1);
#endif

#if(UART_COM == xUART2_BASE)
    xSPinTypeUART(UART2TX, PA10);
    xSPinTypeUART(UART2RX, PA11);
#endif

#if(UART_COM == xUART3_BASE)
	#if Use_Uart_PA01_Pin
    xSPinTypeUART(UART3TX, PA0);
    xSPinTypeUART(UART3RX, PA1);
	#else
    xSPinTypeUART(UART3TX, PA25);
    xSPinTypeUART(UART3RX, PA26);
	#endif
#endif

    /********************** Configure UART *********************************/
    xUARTConfigSet(UART_COM, 115200, (   xUART_CONFIG_WLEN_8 |
                                         xUART_CONFIG_STOP_1 |
                                         xUART_CONFIG_PAR_NONE));

    xUARTIntEnable(UART_COM, xUART_INT_ERROR | xUART_INT_RX);
    // Register user callback function
    xUARTIntCallbackInit(UART_COM, UserUARTHandler);
    // Start Uart
    xIntEnable(xSysCtlPeripheralIntNumGet(UART_COM));

    /********************** Enable UART ************************************/
    xUARTEnable(UART_COM, (xUART_BLOCK_UART | xUART_BLOCK_TX | xUART_BLOCK_RX));
}
//*****************************************************************************
//
//! \brief  The UART_Init function Used to Initialize Uart peripheral
//!
//! \return None
//
//*****************************************************************************
static void UART_Printf_Info(void)
{
	unsigned int i;
	for(i = 0; i < sizeof(menu1); i++)
	{
		xUARTCharPut(UART_COM, menu1[i]);
	}
}

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
//! \brief  The UserUARTHandler function Used to Uart's CallBack function
//!
//! \return 0
//
//*****************************************************************************
unsigned long UserUARTHandler(void *pvCBData, unsigned long ulEvent,
                               unsigned long ulMsgParam, void *pvMsgData)
{
    unsigned char ch = xUARTCharGet(UART_COM);
    if((ch != 'r') && (ch != 27))
    {
        xUARTCharPut(UART_COM, ch);
    }
    if(ch == 'r') status = 1;  // re-show
    if(ch == 27)  status = 2;  // Exit
    return (0);
}

