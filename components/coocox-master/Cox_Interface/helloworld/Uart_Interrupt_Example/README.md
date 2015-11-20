
@defgroup UART_Interrupt_Example Interrupt

## Introduction
	This example shows the use of UART port interrupt

[TOC]

@tableofcontent
##PinUsed  
	The MCU pin usage in the following table:
|       Peripheral IO             |    GPIO PIN    |
|---------------------------------|----------------|
|       LED PIN                   |      PB18      |
|       UART0 TX                  |      PA2       |
|       UART0 RX                  |      PA3       |
|       UART1 TX                  |      PC0       |
|       UART1 RX                  |      PC1       |
|       UART2 TX                  |      PA10      |
|       UART2 RX                  |      PA11      |
|       UART3 TX                  |      PA0       |
|       UART3 RX                  |      PA1       |
|       UART3 TX                  |      PA25      |
|       UART3 RX                  |      PA26      |

## Describe
	When the system initialization finished, print the system information
    and prompt information. The system will make a different reaction
    depending on the input.
	
## Usage
	The user only  modified macro definition and the corresponding parameters.

### Uart Interrupt Example
@include Uart_Interrupt_Example.c


