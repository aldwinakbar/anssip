@defgroup NUC140VE3AN_Example

##Nuvoton NUC140VE3CN Example Code for CoOS Free RTOS

###Device:
Nuvoton NUC140VE3CN

###Evaluation Board:
Nu-LB_002 Rev2.0

###Complier:
CoIDE V1.1.0

###Tasks:

Task|Description
:--|:--
task_init|Initialize all the hardware, create all the flag and mutex in this application.
taskC|This function use to ring the alarm clock.
taskE|This task use to set the time or the alarm.
taskF|This function use to blink lcd,when time or alarm is in setting.
taskB|This task use to Complete time and alarm display.
taskA|Complete keyboard scan, digital control of dynamic display

###Descriptions:

1. In general, press the key 1(The first key in Matrix keyboard) will Switch display time and alarm. If now LCD is display the alarm without pressing the key 1 any more, then LCD will display time after 10 seconds.
2. This example simulates a real-time clock and alarm on a 128*64 LCD with which users can set time and alarm freely: key 2 and key 3 could configure the time or alarm which is currently displayed.  
Press key 2(The second key in Matrix keyboard) to choose the month, day, hour, minute or second that you want to modify, the selected bit will blink at the same time. When press it 7 times, you will exit the configuration mode.  
Press key 3(The third key in Matrix keyboard) to increase the month, day, hour, minute or second which was choosen to modify by key 2.
3. System samples the value of AD at regular intervals and show it by the 7-segment LED. You can adjust the input voltage of AD converter by the regulation resistance on board, and you could see the change on the last three 7-segment LED.
4. The first 7-segment LED will show the key vaule.
5. When the alarm is ringing, press any key will stop it ringing. If you press Key 7, it will end Ring-again mode; if you press the other key, it will ring again after one minute.

###System Configuration:
The max user task:10

Enable Mutexes(CFG_MUTEX_EN) and software timer (CFG_TMR_EN).

Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 300Hz (3.3ms)

###Download File
[Nuvoton NUC140VE3CN Example Code for CoOS Free RTOS (using CoIDE V1.1.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC140_CoOS.zip)