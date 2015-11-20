@defgroup HT32F1755_Example

## Holtek HT32F1755 Example Code for CoOS Free RTOS   ##

### Device: ###
Holtek HT32F1755

### Evaluation Board: ###
HT32F175x_275x Development Board

### Complier: ###
CoIDE 1.4.2

### Tasks: ###

Task|Description
:--|:--
init_task|Initialize all the hardware ,Create all the flag and mutex in this application.
taskA|Toggle LED2 and LED3.
taskB|Show ADC conversion value through usart.
taskC|Use RTC to show time through usart.

### Descriptions: ###
When OS starts,LED2 and LED3 blink, time will show on the HyperTerminal, Meanwhile, LED1 will be led on every 1 second. In addition, every 5 seconds ADC conversion value will capture three times and send them to HyperTerminal.

### System Configuration: ###

Max task: 4
    
Clock Settings:

- XTAL   freq         = 8.00 MHz
- SYSCLK freq       = 8.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
[Holtek HT32F1755 source code for CoOS Free RTOS (Using CoIDE 1.4.2)](http://www.coocox.org/download/downloadfile/CoOS/Demo/HT32F1755_CoOS.zip)