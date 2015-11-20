@defgroup SAM3U4E_MDK_Example

## Atmel SAM3U4E Example Code for CoOS Free RTOS  ##

### Device: ###
Atmel SAM3U4E

### Evaluation Board: ###
Atmel SAM3U-EK

### Complier: ###
ARM ARMCC (MDK3.80 or higher)

### Tasks: ###

Task|Description
:--|:--
lightTask|process all the lights every second
lightLedTask|control the three LEDs' states when the state of the trunk road traffic light changing
lcdBlinkyTask|a progress bar to display red, yellow and green alternately on LCD
uartprintfTask|print the current traffic states and the state of Blinky every second by serial port

Descriptions:

This example implements a simple traffic light controller at the crossroads.

1. The trunk road and the branch road own a set of red, yellow and green lights to control traffic. They display as follows on LCD:
	
	|||||||
:--|:--
Trunk road|Green(30s -- 5s)|Yellow(4s -- 0)|Red(20s -- 0)||Green(30s -- 5s)|...
Branch road|Red(30s -- 0)||Green(20s -- 5s)|Yellow(4s -- 0)|Red(30s -- 0)|...

2. Three LEDs on board will show the state of the trunk road traffic light ,their corresponding relations are as follows: 
	- LED0->Red 
	- LED1->Green 
	- LED2->Yellow
3. The serial port prints the current traffic states and the state of Blinky every second.

### System Configuration: ###

- system clock: 48MHz
- system ticks: 1KHz(1ms)

### Download File ###
[Atmel SAM3U4E source code for CoOS Free RTOS Using ARMCC compiler](http://www.coocox.org/download/downloadfile/CoOS/Demo/AT91SAM3U4E-MDK3.8.zip)
