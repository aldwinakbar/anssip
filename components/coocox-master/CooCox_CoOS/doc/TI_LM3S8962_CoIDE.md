@defgroup LM3S862_Example

## TI LM3S8962 Example Code for CoOS Free RTOS   ##

### Device: ###
TI LM3S8962

### Evaluation Board: ###
Keil EK-LM3S8962

### Complier: ###
CoIDE V1.0.0

### Tasks: ###

Task|Description
:--|:--
init_task|initialize the target board's resources, and create other tasks, and then delete itself and exit the scheduling
taskA|display current systems' run time with this hour:minutes:second: microsecond format.
taskB|blinks the Status LED every second.
taskC|it display 2 pictures about CooCox on OLED display.

### Descriptions: ###
This example use CoOS to control 3 tasks:

taskA display the systems' run time in hour,minutes,second,and microsecond.

taskB control the blinks of the Status LED.

taskC control the display of 2 different BackColor picture about CooCox LOGO.

Both taskA and taskC will use the OLED to display, so we use a Mutex to control the use of OLED.

### System Configuration: ###
Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 50.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Keil EK-LM3S8962 source code for CoOS Free RTOS (using CoIDE V1.0.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/LM3S8962_CoOS.zip)