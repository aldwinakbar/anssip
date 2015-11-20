
@if (DOXYGEN_PROJECT)
@defgroup CooCox_CoOS
@endif

# CooCox CoOS  {#CooCox_CoOS_English}
CooCox CoOS is an embedded real-time multi-task OS specially for ARM Cortex M series.
[中文版点击进入](@ref CooCox_CoOS_Chinese)

## CoOS Features:
- Free and open real-time Operating System
- Specially designed for Cortex-M series
- Scalable, minimum system kernel is only 974Bytes
- Adaptive Task Scheduling Algorithm.
- Supports preemptive priority and round-robin
- Interrupt latency is next to 0
- Stack overflow detection option
- Semaphore, Mutex, Flag, Mailbox and Queue for communication & synchronisation
- Supports the platforms of ICCARM, ARMCC, GCC

## Technical Data:
### Time Specifications:

N Function	                        |Time ( No Robin/Robin )
----------------------------------- | -------------
Create defined task, no task switch	| 5.3us / 5.8us
Create defined task, switch task	| 7.5us / 8.6us
Delete task (ExitTask)	            | 4.8us / 5.2us
Task switch (SwitchContext)	        | 1.5us / 1.5 us
Task switch (upon set flag)	        | 7.5us / 8.1us
Task switch (upon sent semaphore)	| 6.3us / 7.0us
Task switch (upon sent mail)	    | 6.1us / 7.1us
Task switch (upon sent queue)	    | 7.0us / 7.6us
Set Flag (no task switch)	        | 1.3us / 1.3us
Send semaphore (no task switch)	    | 1.6us / 1.6us
Send mail (no task switch)	        | 1.5us / 1.5us
Send queue (no task switch)	        | 1.8us / 1.8us
Maximum interrupt lockout for IRQ ISR's | 0 / 0

### Space Specifications:

Description	                | Space
--------------------------- | -------------
RAM Space for Kernel	    | 168 Bytes
Code Space for Kernel	    | 974 Bytes
RAM Space for a Task	    | TaskStackSize + 24 Bytes(MIN) TaskStackSize + 48 Bytes(MAX)
RAM Space for a Mailbox	    | 16 Bytes
RAM Space for a Semaphore	| 16 Bytes
RAM Space for a Queue	    | 32 Bytes
RAM Space for a Mutex	    | 8   Bytes
RAM Space for a User Timer	| 24 Bytes

> The data for CoOS kernel is measured for STM32F103RB CPU with the system clock setting to 72 MHz, code execution from internal flash, with Flash Latency 2 wait states and the Prefetch Buffer enabled.

## User's Guide:
We have supplied user's guide to help you to use CooCox CoOS more easily and confidently, which includes:

- [Chapter 1 CooCox CoOS Overview](@ref CooCox_CoOS_gettingstart_en)
- [Chapter 2 Task Management](@ref CooCox_CoOS_Task_Management_en)
- [Chapter 3 Time Management](@ref CooCox_CoOS_Time_Management_en)
- [Chapter 4 Memory Management](@ref CooCox_CoOS_Memory_Management_en)
- [Chapter 5 Intertask Synchronization & Communication](@ref CooCox_CoOS_Intertask_syn_en)
- [Chapter 6 API Reference](@ref CooCox_CoOS_API_Reference_en)

To get the details, please download  [CooCox CoOS User's Guide](assets/pdf/CooCox_CoOS_User_Guide.pdf).

## Examples:
CoOS also provides some examples to help you to develop embedded applications based on CoOS more easily, as follows:

### Using ARMCC compiler:
- [Atmel ATSAM3U4E Example](@ref SAM3U4E_MDK_Example)
- [NXP LPC1114 Example](@ref LPC1114_MDK_Example)
- [NXP LPC1766 Example](@ref LPC1766_MDK_Example)
- [NXP LPC1766 LwIP Example](@ref LPC1766_LWIP_MDK_Example)
- [ST STM32F103RB Example](@ref STM32F103RB_MDK_Example)
- [TI LM3S8962 Example](@ref LM3S862_MDK_Example)

### Using ICCARM compiler:
- [NXP LPC1114 Example](@ref LPC1114_IAR_Example)
- [NXP LPC1766 Example](@ref LPC1766_IAR_Example)
- [ST STM32F103RB Example](@ref STM32F103RB_IAR_Example)

### Using GCC compiler:
- [Atmel SAM3U4E Example](@ref SAM3U4E_Example)
- [Freescale KL25Z Example](@ref KL25Z_Example)
- [Holtek HT32F1253 Example](@ref HT32F1253_Example)
- [Holtek HT32F1755 Example](@ref HT32F1755_Example)
- [Nuvoton AU9110 example ](@ref AU9110_Example)
- [Nuvoton Mini54LAN Example](@ref MINI54LAN_Example) 
- [Nuvoton M058SSAN Example](@ref M058SSAN_Example)
- [Nuvoton M0516 Example](@ref M0516LAN_Example)
- [Nuvoton M0516LDN example ](@ref M0516LDN_Example)
- [Nuvoton M0518 example ](@ref M0518_Example)
- [Nuvoton M453VG6AE example](@ref M453VG6AE_Example)
- [Nuvoton NANO112VC2AN example](@ref NANO112VC2AN_Example)
- [Nuvoton NANO130KE3BN Example](@ref NANO130KE3BN_Example)
- [Nuvoton NUC029LAN Example](@ref NUC029LAN_Example)
- [Nuvoton NUC100LE3AN Example](@ref NUC100LE3AN_Example)
- [Nuvoton NUC122RD2AN Example](@ref NUC122RD2AN_Example)
- [Nuvoton NUC123SD4AN0 Example](@ref NUC123SD4AN0_Example)
- [Nuvoton NUC123SD4AN0 UART Example](@ref NUC123SD4AN0_UART_Example)
- [Nuvoton NUC131SD2AE Example](@ref NUC131SD2AE_Example)
- [Nuvoton NUC140 Example](@ref NUC140VE3AN_Example)
- [Nuvoton NUC140 CAN Example](@ref NUC140VE3AN_CAN_Example)
- [Nuvoton NUC140 CAN Master Example](@ref NUC140VE3AN_CAN_Master_Example)
- [Nuvoton NUC220VE3AN Example](@ref NUC220VE3AN_Example)
- [Nuvoton NUC240VE3AE Example](@ref NUC240VE3AE_Example)
- [Nuvoton NUC472HI8AE example](@ref NUC472HI8AE_Example)
- [Nuvoton NUC505Y013Y example](@ref NUC505Y013Y_Example) 
- [NXP LPC1766 Example](@ref LPC1766_Example)
- [NXP LPC1766 LwIP Example](@ref LPC1766_LWIP_Example)
- [NXP LPC1114 Example](@ref LPC1114_Example)
- [ST STM32F103RB Example](@ref STM32F103RB_Example)
- [TI LM3S8962 Example](@ref LM3S862_Example)

## Supported Devices:
CoOS supports all ARM Cortex M4, M3 and M0 based devices, here only lists some of the most common used:

- Atmel ATSAM3U Series
- Energy Micro EFM32 Series
- Luminary LM3S Series
- Nuvoton Numicro Series
- NXP LPC17xx LPC13xx LPC12xx LPC11xx Series
- ST STM32 Series
- Toshiba TMPM330 Series
- Holtek HT32 Series