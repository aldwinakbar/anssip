@defgroup M0518_Example

## Nuvoton M0518SD2AE Example Code for CoOS Free RTOS

### Device: ###
Nuvoton M0518SD2AE

### Evaluation Board: ###
NUTINY-M0518-V1.1

### Complier: ###
CoIDE V2.0.2

### Tasks: ###

Task|Description
:--|:--
task_init |Initialize all hardware, create task A,B,C.
taskC     |          Echo string “Hello from taskC\r\n” via UART0 every 1 second.
taskB      |         Echo string “Hello from taskB\r\n” via UART0 every 3 seconds.
taskA      |         Blink LED（PB13）every 1 second.

### Descriptions: ###
   Demo 3 simple tasks.

1. taskA bilik a LED at 1hz.
2. taskB echo a string every 3 seconds and
3. tackC echo a string every 1 second.


### System Configuration: ###
The max user task:5

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 50.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###

[Nuvoton M0518SD2AE Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/M0518_CoOS_demo2.zip)

