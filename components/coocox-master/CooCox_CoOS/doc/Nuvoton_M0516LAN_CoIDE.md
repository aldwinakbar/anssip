@defgroup M0516LAN_Example

##Nuvoton M0516LAN Example Code for CoOS Free RTOS

###Device:
Nuvoton M0516LAN

###Evaluation Board:
Nu-LB_002 Rev2.0

###Complier:
CoIDE V1.1.3

###Tasks:

Task|Description
:--|:--
task_init|Initialize all the hardware, create all the flag and mutex in this application.
show_3led|This task use to show 3 color led.
show_lcd|This task use to show SPI lcd.
led_blink|This task use to blink the 8 leds.

###Descriptions:
1. System samples the value of AD at regular intervals and show it by LCD. You can adjust the input voltage of AD by the regulation resistance on board, and you could see the change on the LCD.
2. 8 LEDs will blink and 3 color led will blink too.
3. Buzzer will ring according to the AD value.

###System Configuration:
The max user task:10

Enable Mutexes(CFG_MUTEX_EN) and software timer (CFG_TMR_EN).

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 48.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File
[Nuvoton M0516LAN Example Code for CoOS Free RTOS (using CoIDE V1.1.3)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC_M0516_CoOS.zip)