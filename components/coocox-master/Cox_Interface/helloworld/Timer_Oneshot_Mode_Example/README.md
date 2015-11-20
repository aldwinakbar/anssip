
@defgroup Timer_Oneshot_Mode_Example Oneshot Mode

## Introduction
	Show how to configure timer into Oneshot mode.

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
	This example is Show how to configure timer into Oneshot mode.
	When program is running. The status of LED  will toggle.
	Timer will only run one more time in this mode the.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### Timer Oneshot Mode Example
@include Timer_Oneshot_Mode_Example.c


