
@defgroup WDT_Reset_Example Reset

## Introduction
	This example is used to demonstrate the use of the WDT Reset
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
	This example is show how to configure WDT timer into Reset mode.
	When program is running. The status of LED  will flip.If we
	don't feed the dog, then the program will restart, the times of
	LED's state flip willn't achieve 10 times.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.

### WDT Reset Example
@include WDT_Reset_Example.c


