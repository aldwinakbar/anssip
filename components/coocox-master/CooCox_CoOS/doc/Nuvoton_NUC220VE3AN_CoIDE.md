@defgroup NUC220VE3AN_Example

##Nuvoton NUC220VE3AN Example Code for CoOS Free RTOS

### Device: ###
Nuvoton NUC220VE3AN

### Evaluation Board: ###
NuTiny-EVB-NUC200-LQFP V1.0

### Complier: ###
CoIDE V1.7.5

### Tasks: ###

Task|Description
:--|:--
task_init|Initialize all the hardware, RCC, GPIO, ADC, UART, create all the flag in this application and taskA, taskB.
taskA|This function is used to detect button and set print flag.
taskB|This function is used to get ten times current temperature and compute average temperature value, then print it to hyperterminal.

### Descriptions: ###
1. System prompt user to press the button to get current temperature. The mode of GPIOE's PIN14 is selected as digital input. TaskA will set print_flag of taskB, when external button pressed.
2. System print temperature to hyperterminal by uart1.

### System Configuration: ###
The max user task:5

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 50.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Nuvoton NUC220VE3AN Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC220_CoOS.zip)