@defgroup NUC100LE3AN_Example

##Nuvoton NUC100LE3AN Example Code for CoOS Free RTOS

###Device: 
Nuvoton NUC100LE3AN
###Evaluation Board:
Nu_Tiny_EVB_001V1.1 (There are no LCD \button\Serial ports on the board, they should be built by yourself.)

###Complier: 
CoIDE V1.0.0

###Tasks:

Task|Description
:--|:--
task_init|initialize the target board's resources, and create the majority of tasks, and then delete itself and exit the scheduling
lcd_display_adc|display the current value of ADC on LCD1602
uart_print|print the current AD value of ADC by serial port
led_blink|A LED used to indicate status
time_display|display time, the format likes xx:xx:xx
time_set|set time
lcd_blink|blink the hour, minute or second that is being set up and show it on LCD1602 when setting time

###Descriptions:

1. This example simulates a real-time clock on LCD1602 which users can set time freely:  
Set PC0 to low to choose the hour, minute or second that you want to set, at the same time as set of exit(when press it the fourth time);  
Set PC1 to low to increase the hour, minute or second which was choosen to set by 1.
2. System samples the value of AD at regular intervals and show it by histogram on LCD1602, at the same time the serial port prints the value of AD.   
You can adjust the input voltage of AD by the regulation resistance on board, and you could see the change on LCD1602 or through the serial print.
3. A LED used to indicate status. On indicates displaying time，off indicates setting time.

###System Configuration:

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 48.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File

[Nuvoton NUC100LE3AN Example Code for CoOS Free RTOS (using CoIDE V1.0.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC100LE3AN_CoOS.zip)
