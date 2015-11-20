@defgroup M0516LDN_Example

## Nuvoton M0516LDN Example Code for CoOS Free RTOS

### Device: ###
Nuvoton M0516LDN

### Evaluation Board: ###
NuTing-EVB-M051 V3.0

### Complier: ###
CoIDE V1.7.6

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware, create output flag in this application, create taskA and taskB.
taskA|This function is used to change the status of LED.
taskB|This function is change the number by button.

### Descriptions: ###
After power on the system, four led will turn off. A LED will turn on when you press the button. Four times is a cycle.

### System Configuration: ###
The max user task:3

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###

[Nuvoton M0516LDN Example Code for CoOS Free RTOS (using CoIDE V1.7.6)](http://www.coocox.org/download/downloadfile/CoOS/Demo/M0516DN_CoOS.zip)

