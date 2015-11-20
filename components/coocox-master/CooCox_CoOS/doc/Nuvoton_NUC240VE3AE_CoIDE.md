@defgroup NUC240VE3AE_Example

##Nuvoton NUC240VE3AE Example Code for CoOS Free RTOS

### Device: ###
Nuvoton NUC240VE3AE

### Evaluation Board: ###
NuTiny-EVB-NUC240-LQFP100 V1.0

### Complier: ###

CoIDE V2.0.2

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware, create all the flag and mutex in this application. 
taskB |USART printer information, and LED lights flashing.
taskA|USART printer information

### Descriptions: ###

1. In the configuration and enter the OS is going to be printing a message indicating that where the program is running.

2. When taskA running, the USART prints "This is task A." to prompts the user the system in operation.

3. When taskB running, the USART prints "This is task B.", and LED lights flashing at certain time intervals.

### System Configuration: ###
The max user task:5

Clock Settings:

- XTAL   freq         = 12.00 MHz 
- SYSCLK freq         = 72.00 MHz 
- System Tick freq    = 100Hz (10ms) 

### Download File ###
[Nuvoton NUC240VE3AE Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/CoOS_NUC240VE3AE.zip)