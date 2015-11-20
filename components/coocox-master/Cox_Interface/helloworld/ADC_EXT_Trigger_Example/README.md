
@defgroup ADC_EXT_Trigger_Example EXT Trigger


## Introduction

This example show how to use ADC module to read 1 channel analog data.

[TOC]

@tableofcontent
##PinUsed  
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       ADC0 Channel 2            |      PA25      |
|       PWMB Channel 1            |      PC0       |
|       EXINT0 ADC Trigger input  |      PC10      |

## Describe
	This example is Show how to configure ADC into Single channel sampling
	mode. When program is running,We can use the PWM wave output as an
	external interrupt trigger pulse. The LED's status will toggle When the
	ADC values are read. And the value of the ADC conversion will be send
	to PC by Uart.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### ADC EXT Trigger Example
@include ADC_EXT_Trigger_Example.c


