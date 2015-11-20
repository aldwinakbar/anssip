
@defgroup SPI_SDCard_Example SDCard

## Introduction
	Show how to configure SPI bus to drive SDCard.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       SPI0 CLK                  |      PA15      |
|       SPI0 CS                   |      PA16      |
|       SPI0 MISO                 |      PA17      |
|       SPI0 MOSI                 |      PA18      |

## Describe
	When the program is SPI using Master mode. When the LED start
	flashing, it's said the SDcard is initialize succeed finished.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.
	This sample need a SD card driver is added to the project.


### SPI SDCard Example
@include SPI_SDCard_Example.c


