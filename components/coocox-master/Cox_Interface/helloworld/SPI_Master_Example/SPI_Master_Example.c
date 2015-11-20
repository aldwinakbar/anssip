//******************************************************************************
//
//! \file     SPI_Example_Master.c
//!
//! \brief    An example of SPI using polling mode with loop-back (MISO <-> MOSI)
//!           connection to test SPI driver
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA15 : SPI0 CLK
//!           PA16 : SPI0 CS
//!           PA17 : SPI0 MISO
//!           PA18 : SPI0 MOSI
//!
//! \describe When the program is SPI using polling mode with loop-back
//! 	      (MISO <-> MOSI)connection to test SPI driver. LED every twinkle said
//!           a loopback test is  finished.
//!
//! \version  3.0
//! \date     10/27/2014
//! \author   CooCox
//! \copy
//!
//! Copyright (c) 2009-2014 CooCox.  All rights reserved.
//
//******************************************************************************
#include "cox.h"

/* Private define ************************************************************/
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1   				   PB18
#define BUF_SIZE               20

/* Private variables *********************************************************/
// SPI Transmit Data buffer
static unsigned long SPIRecv[BUF_SIZE];
// SPI Receive Data buffer
static unsigned long SPITran[BUF_SIZE];

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
static void SPI_Init(void);
void SPI_Master_Example(void);

//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup SPI_Example SPI Example
//!     	@{
//!       		\addtogroup SPI_Master_Example Master
//!        		@{
//!
//! \brief  The SPI_Master_Example function used to test SPI peripheral by
//!		    LoopMode
//!
//! \return None
//
//*****************************************************************************
void SPI_Master_Example(void)
{
    /**********************Define and Initialize variables *****************/
    unsigned long i = 0;
    for(i = 0; i < BUF_SIZE; i++)
    {
        SPIRecv[i] = 0;
        SPITran[i] = i;
    }
    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(TICK_SLOW);

	#if Use_Uart_Debug
    /********************** Initialize Uart Peripheral ********************/
	UART_Init();
	#endif

    /********************** Initialize GPIO Peripheral ********************/
	LED_Init();

    /********************** Initialize SPI Peripheral ********************/
	SPI_Init();

    while (1)
    {
    	for(i = 0; i < BUF_SIZE; i++)
		{
            #if Use_Uart_Debug
			printf("SPITran[%d] Write Value = %d \r\n",i,SPITran[i]);
			printf("SPITran[%d] Read  Value = %d \r\n",i,xSPISingleDataReadWrite(xSPI0_BASE, SPITran[i]));
            #else
			xSPISingleDataReadWrite(xSPI0_BASE, SPITran[i]);
            #endif
		}
        xGPIOSPinWrite(LED1, 0);
        xSysCtlDelay(TICK_SLOW);
        xGPIOSPinWrite(LED1, 1);
        xSysCtlDelay(TICK_SLOW);
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
    /********************** Configure GPIO Port ****************************/
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
//! \brief  The SPI_Init function Used to Initialize SPI peripheral
//!
//! \return None
//
//*****************************************************************************
static void SPI_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2(xSPI0_BASE);
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);

    /******************** Configure Peripheral'S IO ************************/
    xSPinTypeSPI(SPI0CLK , PA15);
    xSPinTypeSPI(SPI0CS  , PA16);
    xSPinTypeSPI(SPI0MISO, PA17);
    xSPinTypeSPI(SPI0MOSI, PA18);

    /******************** Configure SPI Peripheral *************************/
    xSPIConfigSet(xSPI0_BASE, 2000000, xSPI_DATA_WIDTH8 | xSPI_MOTO_FORMAT_MODE_0 |
    								   xSPI_MODE_MASTER | xSPI_LSB_FIRST);

    /**************************Start SPI************************************/
    xSPIEnable(xSPI0_BASE);
}
//*****************************************************************************
//
//! \brief  The LED_Init function Used to Initialize LED light
//!
//*****************************************************************************
static void LED_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
	xSysCtlPeripheralEnable2( xGPIOSPinToPort( LED1 ) );

    /******************** Configure Peripheral'S IO **********************/
    xGPIOSPinTypeGPIOOutput(LED1);

}
