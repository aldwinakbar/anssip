
@defgroup SPI_Master_Slave_Example Master and Slave

## Introduction
	Show how to configure SPI master mode and Slave mode, how to
	transmit data via SPI Bus.

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
	When the program is SPI using Master or Slave mode. The LED
	every twinkle said a group of data test is  finished.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### SPI Master and Slave Example
@include SPI_Master_Slave_Example.c


