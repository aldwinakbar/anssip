@defgroup NANO112VC2AN_Example

##Nuvoton NANO112VC2AN Example Code for CoOS Free RTOS
### Device: ###

Nuvoton M453VG6AE

### Evaluation board: ###

NuTiny-SDK-Nano112_LQFP100_V1.1

### Complier: ###

CoIDE V2.0.2

### Tasks:  ###

Task|Description
:--|:--
task0  |             Via a serial port and LCD to send message to indicate task0 is running.
task1  |             Via a serial port and LCD to send message to indicate task0 is running 

### Description: ###

1. The program is running, the first after finish the initialization will be via a serial port to print the current CPU running frequency.
2. Later, you can create two tasks , Via a serial port to print the information in the task before the task has been created and has not been run .

### The system configuration ###
Biggest user tasks: 5

Can make mutexes and software timer.

The clock Settings: 

- XTAL   freq         = 12.00 MHz 
- SYSCLK freq         = 12.00 MHz 
- System Tick freq    = 1000Hz (1ms) 

### Download File ###
[Nuvoton NANO112VC2AN Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/CoOS_NANO112VC2AN.zip)