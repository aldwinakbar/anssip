
@defgroup ADC_Multichannel_Sampling_Example Multichannel Sampling


## Introduction

This example show how to use ADC module to read 8 channels

[TOC]

@tableofcontent
##PinUsed  
If the MCU is LPC175x or LPC176x, The corresponding pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       ADC0 Channel 0            |      PA23      |
|       ADC0 Channel 1            |      PA24      |
|       ADC0 Channel 2            |      PA25      |
|       ADC0 Channel 3            |      PA26      |
|       ADC0 Channel 4            |      PA30      |
|       ADC0 Channel 5            |      PA31      |
|       ADC0 Channel 6            |      PA3       |
|       ADC0 Channel 7            |      PA2       |

If the MCU is LPC177x or LPC178x, The corresponding pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       ADC0 Channel 0            |      PA23      |
|       ADC0 Channel 1            |      PA24      |
|       ADC0 Channel 2            |      PA25      |
|       ADC0 Channel 3            |      PA26      |
|       ADC0 Channel 4            |      PA30      |
|       ADC0 Channel 5            |      PA31      |
|       ADC0 Channel 6            |      PA12      |
|       ADC0 Channel 7            |      PA13      |

## Describe
	This example is Show how to configure ADC into Single channel sampling
	mode. When program is running, The LED's status will toggle When the
	ADC values are read. And the value of the ADC conversion will be send
	to PC by Uart.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.


### ADC Multichannel Sampling Example
@include ADC_Multichannel_Sampling_Example.c


