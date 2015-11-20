@defgroup NUC140VE3AN_CAN_Example

##Nuvoton NUC140VE3CN CAN Example Code for CoOS Free RTOS

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
send_id|This task use to send the card ID.
send_val|This task use to send the Consumption.
make_action|This task use to make a action to indicate the statue.
uart_print|Print the the information in this application.

###Descriptions:

This example simulates a punch card consumption sub-machine system. The test the hardware needs to dock with a punch card host system.

1. Using serial input to simulate the insert card movement, using AD input analog the amount of consumption's input action.
2. If communication with host is successful, system will show the card's balance, consumer status and post-consumer balance.
###System Configuration:
Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File
[Nuvoton NUC140VE3CN CAN Example Code for CoOS Free RTOS (using CoIDE V1.1.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC140_CAN_CoOS.zip)