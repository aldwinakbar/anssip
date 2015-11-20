@defgroup NUC131SD2AE_Example

##Nuvoton NUC131SD2AE Example Code for CoOS Free RTOS

### Device: ###
Nuvoton NUC131SD2AE

### Evaluation Board: ###
NuTiny-EVB-NUC131-LQFP64 V1.0

### Complier: ###

CoIDE V2.0.2

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware、clock、GPIO, create all the clock flags; Creat tasks of A and B.
taskB|Operating I/O port to control led color basing on the key number,then output color on the display terminal through the UART0. 
taskA|Detecting if the key is pressed,and record key number.

### Descriptions: ###

1.This example is that set GPIO12 input mode and link external key,when button is pressed,record key number.

2.Each time you press the button,the green,red or blue is lightted, press again,the lights go off,recycling the process,then output color on the display terminal through the UART0.

###System Configuration:###
Clock Settings:

- XTAL   freq       = 12.00 MHz 
- SYSCLK freq       = 12.00 MHz 
- System Tick freq    = 300Hz (10/3ms) 

### Download File ###
[Nuvoton NUC131SD2AE Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC131_CoOS_led.zip)