@defgroup NUC505Y013Y_Example

##Nuvoton NUC505Y013Y Example Code for CoOS Free RTOS

### Device: ###

Nuvoton NUC505Y013Y

### Evaluation Board: ###

NuTiny-EVB-NUC505_QFN88 V1.4

### Complier: ###

CoIDE V2.0.2

### Tasks:  ###

Task|Description
:--|:--
task_init     |      Initialize all the hardware, create all the flag and mutex in this application. 
taskB       |        USART printer information, and LED lights flashing.
taskA      |         USART printer information


### Descriptions: ###

1. In the configuration and enter the OS is going to be printing a message indicating that where the program is running.

2. When taskA running, the USART prints "This is task A." to prompts the user the system in operation.

3. When taskB running, the USART prints "This is task B.", and LED lights flashing at certain time intervals.

### System Configuration: ###
Max number of tasks that can be running:	5

Clock Settings: 

- XTAL   freq         = 12.00 MHz 
- SYSCLK freq         = 96.00 MHz 
- System Tick freq    = 100Hz (10ms) 


[Nuvoton NUC505Y013Y Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC505_CoOS.zip)