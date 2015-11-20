@defgroup NANO130KE3BN_Example

##Nuvoton NANO130KE3BN Example Code for CoOS Free RTOS

### Device: ###
Nuvoton NANO130KE3BN

### Evaluation Board: ###
NuTiny-SDK-Nano130

### Complier: ###
CoIDE V1.7.5

### Tasks: ###

Task|Description
:--|:--
task_init|Initalize all the hardware, RCC, GPIO, UART, RTC, create all the flag and mailbox in this application.
taskA|This function is used to deal button-record , recevie e-mail messages and print the messages on HyperTerminal by uart0.
taskB|This function is used to detect button，post e-mail messages and display the current time or date.

### Descriptions: ###
1. the current time or date is dispalyed on LCD when turn on the power of system.
2. the current time and date is dispalyed in turn according to key-button. the current time and date are printed on HyperTerminal by uart0 when the state of the button is changed.

### System Configuration: ###
The max user task:5

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Nuvoton NANO130KE3BN Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/Nano130_CoOS.zip)
