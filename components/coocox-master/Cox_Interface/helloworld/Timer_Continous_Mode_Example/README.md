
@defgroup Timer_Continuous_Mode_Example Continuous Mode

## Introduction
	Show how to configure timer into Continuous mode.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       Timer0 channel1 match     |      PB29      |


## Describe
	This example is Show how to configure timer into Continuous mode.
	When program is running. The status of LED and timer output pin
	will toggle.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### Timer Continuous Mode Example
@include Timer_Continuous_Mode_Example.c


