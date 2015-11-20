@defgroup NUC029LAN_Example

##Nuvoton NUC029LAN Example Code for CoOS Free RTOS
### Device: ###

Nuvoton M453VG6AE

### Evaluation board: ###

NUTINY - SDK - NUC029LAN_V1

### Complier: ###

CoIDE V2.0.2

### Tasks:  ###

Task|Description
:--|:--
task0  | Via a serial port to send message to indicate task0 is running,  and the LED flashing every 600 ms
task1  | Via a serial port to send message to indicate task1 is running,  and the LED flashing every 300 ms 

### Description: ###

1. The program is running, the first after finish the initialization will be via a serial port to print the current CPU running frequency.
2. Later, you can create two tasks , Via a serial port to print the information in the task before the task has been created and has not been run .


### The system configuration ###
Biggest user tasks: 5

Can make mutexes and software timer.

The clock Settings: 

- XTAL freq = 50.00 MHz
- SYSCLK freq = 50.00 MHz
- The System Tick freq = 100 hz (10 ms)

### Download File ###
[Nuvoton NUC029LAN Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/CoOS_NuTiny_EVB_NUC029LAN.zip)