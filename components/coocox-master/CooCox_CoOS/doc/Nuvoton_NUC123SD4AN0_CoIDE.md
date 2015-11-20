@defgroup NUC123SD4AN0_Example

##Nuvoton NUC123SD4AN0 Example Code for CoOS Free RTOS

### Device: ###
Nuvoton NUC123SD4AN0

### Evaluation Board: ###
NuTiny-SDK-NUC123

### Complier: ###
CoIDE V1.7.5

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware, RCC, GPIO, create all the flag in this application.
taskA|This function is used to detect button and record the number of press button.
taskB|This function is used to control I/O port out-put to change the color of led.

### Descriptions: ###

1. The mode of GPIOB's PIN12 is selected as digital input. The number of record is modified by each press.
2. According to the record number, the color of led is changed.

### System Configuration: ###
The max user task:5

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)
 
### Download File ###
[Nuvoton NUC123SD4AN0 Example Code for CoOS Free RTOS](ttp://www.coocox.org/download/downloadfile/CoOS/Demo/NUC123_CoOS1.zip)
