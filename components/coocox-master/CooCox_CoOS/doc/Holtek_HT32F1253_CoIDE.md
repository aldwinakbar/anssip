@defgroup HT32F1253_Example

## Holtek HT32F1253 Example Code for CoOS Free RTOS   ##

### Device: ###
Holtek HT32F1253

### Evaluation Board: ###
HT32F125x Development Board REV1.0

### Complier: ###
CoIDE V1.4.0

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware ,Create all the flag and mutex in this application.
taskA|Show RTC time by UART output.
taskB|This function use to blink LED.
taskD|This function use to blink UART output,when time is in setting.
taskE|This task use to set time.

### Descriptions: ###

1. Blink a LED.
2. This example simulates a real-time clock and alarm on UART output which users can set time and set alarm freely:  
key 1 and key 2 will set time.  
Set key 1 to low to choose the year,month,day,hour, minute or second that you want to set, at the same time as set of exit(when press it the 7th time);  
Set key 2 to low to increase the year,month,day,hour, minute or second which was choosen to set by key 1
3. A other lED will blink in two second periods.

### System Configuration: ###
Max task: 5

Clock Settings:

- XTAL   freq         = 8.00 MHz
- SYSCLK freq       = 8.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Holtek HT32F1253 source code for CoOS Free RTOS(Using CoIDE 1.4.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/HT32F1253_CoOS.zip)
