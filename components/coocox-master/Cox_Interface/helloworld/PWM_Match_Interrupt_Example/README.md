
@defgroup PWM_Match_Interrupt_Example Match Interrupt

## Introduction

This example is used to demonstrate the use of the PWM interrupt function.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       PWMB Channel 1            |      PC0       |

## Describe
	This example is Show how to configure PWM to toggle mode. When
	the LED is flashing says it has completed all initialization
	section. Each into the interrupt modify the PWM duty cycle, and
	read it out to print by UART.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### PWM Match Interrupt Example
@include PWM_Match_Interrupt_Example.c


