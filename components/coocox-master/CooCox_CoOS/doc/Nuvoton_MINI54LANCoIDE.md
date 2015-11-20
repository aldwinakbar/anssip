@defgroup MINI54LAN_Example

##Nuvoton MINI54LAN Example Code for CoOS Free RTOS

###Device:
Nuvoton MINI54LAN

###Evaluation Board:
Nu-LB-Mini V001

###Complier:
CoIDE V1.4.2

###Tasks:

Task|Description
:--|:--
task_init|Initialize all the hardware, create the two tasks. 
Task_Monitor|This task use to display the welcom message,the sampling value of AD and the operation time of system.
Task_AD|This task use to get the AD value .

###Descriptions:
1. System samples the value of AD . You can adjust the input voltage of AD by the regulation resistance on board, and you could see the change on the LCD12864. The format likes "AD Val: ****mV".When the value of AD is constant and continuous over 5 seconds, It will display the welcome message again.
2. The available machine time is always displayed in the lower right corner of LCD12864. The format likes **:**:**.

###System Configuration:
Clock Settings:

- XTAL   freq       = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File

[Nuvoton MINI54LAN Example Code for CoOS Free RTOS (using CoIDE V1.4.2)](http://www.coocox.org/download/downloadfile/CoOS/Demo/mini51_CoOS.zip)
