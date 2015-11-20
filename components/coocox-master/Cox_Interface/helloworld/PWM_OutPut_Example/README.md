
@defgroup PWM_OutPut_Example OutPut

## Introduction

This example is Show how to configure PWM to toggle mode.

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
|       PWMB Channel 2            |      PC1       |
|       PWMB Channel 3            |      PC2       |
|       PWMB Channel 4            |      PC3       |
|       PWMB Channel 5            |      PC4       |
|       PWMB Channel 6            |      PC5       |

## Describe
	This example is Show how to configure PWM to toggle mode. When
	the LED is flashing says it has completed all initialization
	section. The duty cycle of each channel will be sent via Uart
	on the computer.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### PWM OutPut Example
@include PWM_OutPut_Example.c


