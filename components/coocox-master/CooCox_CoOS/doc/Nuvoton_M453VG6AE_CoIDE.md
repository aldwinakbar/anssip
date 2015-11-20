@defgroup M453VG6AE_Example

##Nuvoton M453VG6AE Example Code for CoOS Free RTOS
### Device: ###

Nuvoton M453VG6AE

### Evaluation board: ###

NuTiny-SDK-M451_V1.3

### Complier: ###

CoIDE V2.0.2

### Tasks:  ###

Task|Description
:--|:--
task0  |             Via a serial port to send message to indicate task0 is running.
task1  |             Via a serial port LCD to send message to indicate task0 is running 

### Description: ###

1. The program is running, the first after finish the initialization will be via a serial port to print the current CPU running frequency.
2. Later, you can create two tasks , Via a serial port to print the information in the task before the task has been created and has not been run .

### The system configuration ###
Biggest user tasks: 5

software timer.

The clock Settings: 

- XTAL   freq         = 72.00 MHz 
- SYSCLK freq         = 72.00 MHz 
- System Tick freq    = 100Hz (10ms) 

### Download File ###
[Nuvoton M453VG6AE Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/CoOS_M453VG6AE.zip)