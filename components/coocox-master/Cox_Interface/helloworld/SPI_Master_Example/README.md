
@defgroup SPI_Master_Example Master

## Introduction
	An example of SPI using polling mode with loop-back (MISO <-> MOSI)
	connection to test SPI driver

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
	When the program is SPI using polling mode with loop-back
	(MISO <-> MOSI)connection to test SPI driver. LED every twinkle said
	a loopback test is  finished.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### SPI Master Example
@include SPI_Master_Example.c


