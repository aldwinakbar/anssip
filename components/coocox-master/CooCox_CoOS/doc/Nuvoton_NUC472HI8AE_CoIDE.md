@defgroup NUC472HI8AE_Example

##Nuvoton NUC472HI8AE Example Code for CoOS Free RTOS ##

### Device: ###
Nuvoton NUC472HI8AE

### Evaluation Board: ###
NuTiny-SDK-NUC472_LQFP176 V2.1

### Complier: ###
CoIDE V1.7.7

### Descriptions: ###
Step 1.In the main function, initialize the system clock as 36 Mhz, enable the uart0 print function, and set the Timer0 as periodic mode and enable it’s interrupt.

Step 2.Creat 2 tasks.Task1 mainly do the floating point arithmetic, and compare whether the result is equal to the expected result, is yes then print ok, otherwise print No. Task2 just do the FPU register any assignment. Task1 will be interrupted by the Timer0 interrupt, and the interrupt service function will pending a signal which Task2 wait for to let the task2 running. 

### System Configuration: ###
SYSCLK freq       = 36.00 MHz
System Tick freq = 100Hz (10ms)

### Download File ###
[Nuvoton NUC472HI8AE Example Code for CoOS Free RTOS](http://www.coocox.org/download/downloadfile/CoOS/Demo/CoOS_M4_NUC472HI8AE.zip)
