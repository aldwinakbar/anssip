@defgroup AU9110_Example

##Nuvoton AU9110 Example Code for CoOS Free RTOS

###Device: 
Nuvoton AU9110

###Evaluation Board: 
NuTing-EVB- AU9110 V2.0

###Complier: 
CoIDE V1.7.6

###Tasks:

Task|Description
:--|:--
task_init|Initialize  all the hardware, RTC,UART c
taskA|This function is used to set time and get function command.
taskB|This function is used to set the way of RTC interrupt. The interrupt function is set to print current time 5 times.
taskC|Set the alarm time, waiting for the alarm generated.

###Descriptions:

1. System tell user to set initial  time and get function command when power on system.
2. Hyperterm will display current  time 5 times every one second, when user input command 1.
3. System  tell user to set alarm time, waiting for alarm generated.

###System Configuration:

The max user task:4

Clock Settings:

* XTAL freq = 32.00 KHz
* SYSCLK freq= = 48.00 MHz
* System Tick freq = 100Hz (10ms)

###Download File

[Nuvoton AU9110 Example Code for CoOS Free RTOS (using CoIDE V1.7.6)](http://www.coocox.org/download/downloadfile/CoOS/Demo/AU9110_CoOS.zip)