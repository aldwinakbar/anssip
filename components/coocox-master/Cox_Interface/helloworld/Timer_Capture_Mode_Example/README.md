
@defgroup Timer_Capture_Mode_Example Capture Mode

## Introduction
	Show how to configure timer into capture mode.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       Timer3 channel0           |      PB23      |


## Describe
	This example is Show how to configure timer into Capture mode.
	When program is running, connected to the PWM's output pins and
	Timer's capture pin, The LED's status will toggle when timer
	pin capture the edge of the PWM pulse. The frequency will be
	send to PC by Uart.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### Timer Capture Mode Example
@include Timer_Capture_Mode_Example.c


