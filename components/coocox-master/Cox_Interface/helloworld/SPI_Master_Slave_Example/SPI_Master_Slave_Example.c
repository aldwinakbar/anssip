//******************************************************************************
//
//! \file     SPI_Master_Slave_Example.c
//!
//! \brief    Show how to configure SPI master mode and Slave mode, how to
//!           transmit data via SPI Bus.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA15 : SPI0 CLK
//!           PA16 : SPI0 CS
//!           PA17 : SPI0 MISO
//!           PA18 : SPI0 MOSI
//!
//! \describe When the program is SPI using Master or Slave mode. The LED
//!           every twinkle said a group of data test is  finished.
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
#define Master_or_Slave        1

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
void SPI_Master_Slave_Example(void);



//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup SPI_Example SPI Example
//!     	@{
//!       		\addtogroup SPI_Master_Slave_Example Master and Slave
//!        		@{
//!
//! \brief  The SPI_Master_Slave_Example function Used to Test SPI peripheral
//!
//! \return None
//
//*****************************************************************************
void SPI_Master_Slave_Example(void)
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
        if(Master_or_Slave) // Master
        {

        	xSPIDataWrite(xSPI0_BASE, SPITran, BUF_SIZE);
            #if Use_Uart_Debug
        	for(i = 0; i < BUF_SIZE; i++)
			{
				printf("SPI Master Send Value = %d \r\n",SPITran[i]);
			}
            #endif
			xSysCtlDelay(TICK_SLOW);

        }
        else //Slave
        {
        	xSPIDataRead(xSPI0_BASE, SPIRecv, BUF_SIZE);
        	xSPIDataWrite(xSPI0_BASE, SPIRecv, BUF_SIZE);
            #if Use_Uart_Debug
			for(i = 0; i < BUF_SIZE; i++)
			{
				printf("SPI Slave Receive Value = %d \r\n",SPIRecv[i]);
			}
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

}
//*****************************************************************************
//
//! \brief  The SPI_Init function Used to Init SPI peripheral
//!
//! \return None
//
//*****************************************************************************
static void SPI_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2(xSPI0_BASE);
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);
    xSysCtlPeripheralEnable(xGPIOSPinToPeripheralId(LED1));

    /******************** Configure Peripheral'S IO ************************/
    xSPinTypeSPI(SPI0CLK , PA15);
    xSPinTypeSPI(SPI0CS  , PA16);
    xSPinTypeSPI(SPI0MISO, PA17);
    xSPinTypeSPI(SPI0MOSI, PA18);
    xGPIOSPinTypeGPIOOutput(LED1);

    /******************** Configure SPI Peripheral *************************/
    if(Master_or_Slave)
        xSPIConfigSet(xSPI0_BASE, 2000000, xSPI_DATA_WIDTH8 | xSPI_MOTO_FORMAT_MODE_0 |
    								       xSPI_MODE_MASTER | xSPI_LSB_FIRST);
    else
    	xSPIConfigSet(xSPI0_BASE, 2000000, xSPI_DATA_WIDTH8 | xSPI_MOTO_FORMAT_MODE_0 |
    										xSPI_MODE_SLAVE | xSPI_LSB_FIRST);
    /**************************Start SPI************************************/
    xSPIEnable(xSPI0_BASE);
    if(Master_or_Slave)
        printf("SPIMode : Master \r\n");
    else
    	printf("SPIMode : Slave \r\n");

}
