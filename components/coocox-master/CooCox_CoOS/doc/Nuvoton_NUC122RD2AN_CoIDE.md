@defgroup NUC122RD2AN_Example

##Nuvoton NUC122RD2AN Example Code for CoOS Free RTOS

###Device:
Nuvoton NUC122RD2AN

###Evaluation Board:
NuTiny-EVB-122

###Complier:
CoIDE V1.4.2

###Tasks:

Task|Description
:--|:--
task_init|Initialize all the hardware, create all the flag and mutex in this application.
Task_TimeBlink|This task use to blink the the hour, minute or second that is being set up and show it on LCD1602 when setting time.
Task_Monitor|This task use to display the current time,the format likes xx:xx:xx.
Task_TimeSet|This task use to set time.
led_blink|This task use to blink the 7 leds.

###Descriptions:
1. This example simulates a real-time clock on LCD1602 which users can set time freely:  
Set key1(PD0) to low to choose the hour,minute or second that you want to set, when you continuous press seven times, the system will exits setup time. Set key2(PD1) to low to increase the hour, minute or second which was choosen to set by 1.
2. 7 LEDs will blink. 

###System Configuration:
Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 60.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File

[Nuvoton NUC122RD2AN Example Code for CoOS Free RTOS (using CoIDE V1.4.2)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC122RD2AN_CoOS.zip)
