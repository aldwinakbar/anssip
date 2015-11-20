
@defgroup WDT_Interrupt_Example Interrupt

## Introduction
	This example is used to demonstrate the use of the WDT interrupt
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

### WDT Interrupt Example
@include WDT_Interrupt_Example.c


