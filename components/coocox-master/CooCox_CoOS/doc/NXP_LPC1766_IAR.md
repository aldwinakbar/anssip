@defgroup LPC1766_IAR_Example

## NXP LPC1766 Example Code for CoOS Free RTOS   ##

### Device: ###
NXP LPC1766

### Evaluation Board: ###
Keil MCB1700

### Complier: ###
IAR Systems ICCARM (IAR5.30 or higher)

### Tasks: ###

Task|Description
:--|:--
init_task|initialize task,use to create flags, mutexes and other tasks
taskA|control the LED_0(P1.28) and the switch of the simulator LED0 on LCD, at the same time call signal_func ( ) to coordinate task running
taskB|control the LED_1(P1.29) and the switch of the simulator LED1 on LCD, at the same time call signal_func ( ) to coordinate task running
taskC|control the LED_2(P1.31) and the switch of the simulator LED2 on LCD, at the same time call signal_func ( ) to coordinate task running
taskD|control the LED_3(P2.2) and the switch of the simulator LED3 on LCD, at the same time call signal_func ( ) to coordinate task running
clock|control LED_7(P2.6 ) and the switch of the simulator LED7 on LCD, it flickers every 50 ticks(0.5s)
lcd|display the words and change the colour of the words every time when all the LEDs has flickered.(it changes colour every 4s)

### Descriptions: ###
This example uses 5 tasks to control the switch of 5 leds, at the same time simulate the flickering state of the 5 leds on LCD, actually to simulate the driver of Step-motor, 4 LEDs flickering simulates the 4 states of output.

The lighting state of LED is:

LED7 lights every 0.5s, other 4 LEDs' states of lighting are as follows:  
LED0-->LED0,LED1-->LED1-->LED1,LED2-->LED2-->LED2,LED3-->LED3-->LED3,LED0-->LED0-->LED0,LED1-->...

The LED flickering state simulated on LCD is the same as the above. The colour of the words on LCD will change everytime when LED0...LED4 has been through a cycle.

### System Configuration: ###
Clock Settings:

- XTAL   freq         = 12.00 MHz
- SYSCLK freq       = 72.00 MHz
- System Tick freq = 100Hz (10ms)

### Download File ###
	
[NXP LPC1766 source code for CoOS Free RTOS Using ICCARM complier](http://www.coocox.org/download/downloadfile/CoOS/Demo/LPC1766_IAR5.30.zip)