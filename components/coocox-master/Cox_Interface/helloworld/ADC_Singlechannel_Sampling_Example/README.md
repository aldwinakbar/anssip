
@defgroup ADC_Singlechannel_Sampling_Example Singlechannel Sampling


## Introduction

This example show how to use ADC module to read 1 channel analog data.

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       ADC0 Channel 0            |      PA23      |


## Describe
	This example is Show how to configure ADC into Single channel sampling
	mode. When program is running, The LED's status will toggle When the
	ADC values are read. And the value of the ADC conversion will be send
	to PC by Uart.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### ADC Single channel Sampling Example
@include ADC_Singlechannel_Sampling_Example.c


