@defgroup NUC140VE3AN_CAN_Master_Example

##Nuvoton NUC140VE3CN CAN Master Example Code for CoOS Free RTOS

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
get_datab|According to the ID data which received from the sub-machine to obtain the ID's database information.
update_db|According to the consumption which received from the sub-machine to update the database information.
uart_print|Print the the information in this application.

###Descriptions:

This example simulates a punch card consumption sub-machine system. In the test, needs to dock with a punch card sub-machine system.

1. Obtain the ID's database information according to the ID data which received from the sub-machine.
2. Update the database information according to the consumption which received from the sub-machine.
3. 
###System Configuration:
Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 12.00 MHz
- System Tick freq = 100Hz (10ms)

###Download File
[Nuvoton NUC140VE3CN CAN Example Code for CoOS Free RTOS (using CoIDE V1.1.0)](http://www.coocox.org/download/downloadfile/CoOS/Demo/NUC140_CAN_Master_CoOS.zip)