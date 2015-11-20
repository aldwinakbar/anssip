@defgroup M058SSAN_Example

##Nuvoton M058SSAN Example Code for CoOS Free RTOS ##

### Device: ###
Nuvoton M058SSAN

### Evaluation Board: ###
NuTiny-SDK-M058S

### Complier: ###
CoIDE V1.7.5

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware, PWM create all the flags in this application, create taskA and taskB.
taskA|This function is used to change CMR register of PWM, The value of CMR increases from 0 to 1000.
taskB|This function is used to change CMR register of PWM, The value of CMR decreases from 1000 to 0.

### Descriptions: ###
Connect port28 (PWM1) to port 16, you can see:

The Brightness of led change from light to dark, then from dark to light. The state of led is repeated.

### System Configuration: ###
The max user task:3

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 50.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Nuvoton M058SSAN Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/M058S_CoOS.zip)