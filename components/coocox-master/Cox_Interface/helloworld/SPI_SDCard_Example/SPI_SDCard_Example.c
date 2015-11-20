//******************************************************************************
//
//! \file     SPI_SDCard_Example.c
//!
//! \brief    Show how to configure SPI bus to drive SDCard.
//!
//! \PinUsed  PB18 : LED pin
//!           PA0  : UART3 TX
//!           PA1  : UART3 RX
//!           PA15 : SPI0 CLK
//!           PA16 : SPI0 CS
//!           PA17 : SPI0 MISO
//!           PA18 : SPI0 MOSI
//!
//! \describe When the program is SPI using Master mode. When the LED start
//!           flashing, it's said the SDcard is initialize succeed finished.
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
#include "hw_sdcard.h"
#include "sdcard.h"

/* Private define ************************************************************/
#define Use_Uart_Debug         0

#define TICK_SLOW              ((unsigned long)0xFFFFF)
#define LED1   				   PB18
#define BUF_SIZE               64

/* Private variables *********************************************************/
// SDCard Read Block Data buffer
static unsigned char SDCardReadBlock[BUF_SIZE];
// SDCard Write Block Data buffer
static unsigned char SDCardWriteBlock[BUF_SIZE];
// SDCard Info variable
extern tSDCardDeviceInfo g_sSDCardInfo;

/* Private function prototypes **********************************************/
#if Use_Uart_Debug
static void UART_Init(void);
#endif
static void LED_Init(void);
void SPI_Init(void);
void SPI_SDCard_Example(void);


//*****************************************************************************
//
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_HelloWorld Hello World
//!  	@{
//!    		\addtogroup SPI_Example SPI Example
//!     	@{
//!       		\addtogroup SPI_SDCard_Example SDCard
//!        		@{
//!
//! \brief  The SPI_SDCard_Example function Used to drive SDCard
//!
//! \return None
//
//*****************************************************************************
void SPI_SDCard_Example(void)
{
	int i;
	char SD_Init_Resualt = 0;

    /********************** Configure System clock *************************/
    xSysCtlClockSet(100000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_12MHZ);
    xSysCtlDelay(TICK_SLOW);

    #if Use_Uart_Debug
    /********************** Initialize Uart Peripheral ********************/
    UART_Init();
    #endif

    /********************** Initialize GPIO Peripheral ********************/
    LED_Init();

    /********************** Initialize SDCard driver **********************/
	SD_Init_Resualt = SDInit();

    #if Use_Uart_Debug
	if(SD_Init_Resualt)
	{
		printf("SDCard Initialize Succeed. \r\n");
		if(g_sSDCardInfo.ulCardType == SD_TYPE_SDSC_V2)
			printf("Standard Capacity SD Memory Card. \r\n");
		else
			printf("High Capacity or Extended Capacity SD Memory Card. \r\n");
	}
	else
	{
		printf("SDCard Initialize fail. \r\n");
		while(1);
	}
    #endif

	for(i=0;i<BUF_SIZE;i++)
		SDCardWriteBlock[i] = i;

	SDBlockWrite(SDCardWriteBlock,10);

	SDBlockRead(SDCardReadBlock,10);

	for(i=0;i<BUF_SIZE;i++)
	{
		printf("SDCardWriteBlock[%d] = %d \r\n",i,SDCardWriteBlock[i]);
		printf("SDCardReadBlock[%d]  = %d \r\n",i,SDCardReadBlock[i]);
	}
	while(1)
	{
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
    /***************** Configure peripheral Power and Clock ****************/
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

    #if Use_Uart_Debug
	printf(" LED Initialize Succeed ! \r\n");
    #endif

}
//*****************************************************************************
//
//! \brief  The Function is Used to initialize SPI Peripheral
//!
//! \return None
//
//*****************************************************************************
void SPI_Init(void)
{
    /************* Configure Peripherals Power and Clock *******************/
    xSysCtlPeripheralEnable2(xSPI0_BASE);
    xSysCtlPeripheralEnable(xSYSCTL_PERIPH_GPIOA);
    xSysCtlPeripheralEnable(xGPIOSPinToPeripheralId(LED1));

    /******************** Configure Peripheral'S IO ************************/
    xSPinTypeSPI(SPI0CLK , PA15);
    xSPinTypeSPI(SPI0MISO, PA17);
    xSPinTypeSPI(SPI0MOSI, PA18);
    xGPIOSPinTypeGPIOOutput(LED1);
    //attention : In order to use the COX SDCard components Do not use
    //            the hardware CS
    xGPIOSPinTypeGPIOOutput(PA16);
    //attention : The Pin is used to Select SPI Mode or HD SDCard Mode
    xGPIOSPinTypeGPIOOutput(PA28);

    /******************** Configure SPI Peripheral *************************/
    xSPIConfigSet(xSPI0_BASE, 1000000, xSPI_DATA_WIDTH8 | xSPI_MOTO_FORMAT_MODE_0 |
    								   xSPI_MODE_MASTER | xSPI_LSB_FIRST);

    /**************************Start SPI************************************/
    xSPIEnable(xSPI0_BASE);
    xGPIOSPinWrite(PA28, 0);
    #if Use_Uart_Debug
	printf("SPI Peripheral Initialize Finished. \r\n");
    #endif

}
