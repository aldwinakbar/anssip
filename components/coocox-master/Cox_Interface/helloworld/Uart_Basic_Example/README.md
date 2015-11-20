
@defgroup Uart_Basic_Example Basic

## Introduction
	This example is used to demonstrate the use of the PWM interrupt
	function.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |

## Describe
	This example is Show how to configure WDT timer into interrupt
	mode. When program is running. If we don't feed the dog, then
	The status of LED  will flip.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.

### Uart Basic Example
@include Uart_Basic_Example.c


