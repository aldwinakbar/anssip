\page xmenmap_page xmenmap page 

[TOC]






CoX xlowlayer memory map template              {#xlowlayerBaseTemplate}
========
CoX xlowlayer memory map template��ARM Cortex MCU�洢�ֲ���ͨ��ǿ�ƽӿڵ�ģ�壬ÿ���洢�ӿ�ȡ��������ϵ��MCUӵ�е�������Դ�Ĳ����������������еĴ洢�ӿڡ�ͬʱҲ�ֱ��г��˸���ϵ��MCU��ӵ�еĴ洢�ӿڵķ�Χ��

> **NOTE:**
>
> ����Ĵ洢�ӿڵķ�Χ��ָ��������Base��ŵķ�Χ��


# GPIO base Table               {#GPIOBaseTemplate}

���¼�����չʾ��GPIO����洢�ӿڷ�Χ��ģ�壨n��A��H��, ͬʱҲչʾ�����еĸ���CoXϵ�е�GPIO Port Base�ֲ������
xGPIO_PORTn_BASE| LPC17xx        | STM32F1xx      |  Mini51        | M051           
----------------|----------------|----------------|----------------|----------------
xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE
...             |...             |...             |...             |...             
xGPIO_PORTH_BASE|xGPIO_PORTH_BASE|xGPIO_PORTE_BASE|xGPIO_PORTG_BASE|xGPIO_PORTF_BASE

xGPIO_PORTn_BASE| NUC1xx         | NUC122         | NUC123         | NUC2xx 
----------------|----------------|----------------|----------------|----------------
xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE
...             |...             |...             |...             |...             
xGPIO_PORTH_BASE|xGPIO_PORTE_BASE|xGPIO_PORTD_BASE|xGPIO_PORTF_BASE|xGPIO_PORTF_BASE

xGPIO_PORTn_BASE| KLX            | HT32F125x      | HT32F175x      
----------------|----------------|----------------|----------------
xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE|xGPIO_PORTA_BASE
...             |...             |...             |...             
xGPIO_PORTH_BASE|xGPIO_PORTE_BASE|xGPIO_PORTB_BASE|xGPIO_PORTE_BASE

# TIMER base Table               {#TIMERBaseTemplate}

���¼�����չʾ��TIMER����洢�ӿڷ�Χ��ģ�壨n��0��14��, ͬʱҲչʾ�����еĸ���CoXϵ�е�TIMER Base�ֲ������
xTIMERn_BASE | LPC17xx     | STM32F1xx   |  Mini51     | M051           
-------------|-------------|-------------|-------------|-------------
xTIMER0_BASE |xTIMER0_BASE |xTIMER1_BASE |xTIMER0_BASE |xTIMER0_BASE
...          |...          |...          |xTIMER1_BASE |...             
xTIMER14_BASE|xTIMER3_BASE |xTIMER14_BASE|...          |xTIMER3_BASE

xTIMERn_BASE | NUC1xx      | NUC122      | NUC123      | NUC2xx 
-------------|-------------|-------------|-------------|-------------
xTIMER0_BASE |xTIMER0_BASE |xTIMER0_BASE |xTIMER0_BASE |xTIMER0_BASE
...          |...          |...          |...          |...             
xTIMER14_BASE|xTIMER3_BASE |xTIMER3_BASE |xTIMER3_BASE |xTIMER3_BASE

xTIMERn_BASE | KLX         | HT32F125x   | HT32F175x      
-------------|-------------|-------------|-------------
xTIMER0_BASE |xTIMER0_BASE |xTIMER0_BASE |xTIMER0_BASE 
...          |xTIMER1_BASE |xTIMER1_BASE |xTIMER1_BASE  
xTIMER14_BASE|xTIMER2_BASE |...          |...


# PWM base Table               {#PWMBaseTemplate}

���¼�����չʾ��PWM����洢�ӿڷ�Χ��ģ�壨n��A��L��, ͬʱҲչʾ�����еĸ���CoXϵ�е�PWM Base�ֲ������
xPWMn_BASE| LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xPWMA_BASE|...       |xPWMA_BASE|xPWMA_BASE|xPWMA_BASE
...       |xPWMB_BASE|...       |...       |xPWMB_BASE
xPWML_BASE|...       |xPWML_BASE|...       |...

xPWMn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xPWMA_BASE|xPWMA_BASE|xPWMA_BASE|xPWMA_BASE|xPWMA_BASE
...       |xPWMB_BASE|...       |xPWMB_BASE|...       
xPWML_BASE|...       |...       |...       |...       

xPWMn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xPWMA_BASE|xPWMA_BASE|xPWMA_BASE|xPWMA_BASE
...       |xPWMB_BASE|xPWMB_BASE|xPWMB_BASE
xPWML_BASE|xPWMC_BASE|...       |...       

# DMA base Table               {#DMABaseTemplate}

���¼�����չʾ��DMA����洢�ӿڷ�Χ��ģ�壨n��0��8��, ͬʱҲչʾ�����еĸ���CoXϵ�е�DMA Base�ֲ������
xDMAn_BASE| LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xDMA0_BASE|xDMA0_BASE|xDMA0_BASE|...       |...       
...       |...       |xDMA1_BASE|...       |...       
xDMA8_BASE|...       |...       |...       |...       

xDMAn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xDMA0_BASE|...       |...       |xDMA0_BASE|xDMA0_BASE
...       |...       |...       |...       |...       
xDMA8_BASE|...       |...       |...       |...       

xDMAn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xDMA0_BASE|xDMA0_BASE|...       |...       
...       |...       |...       |...       
xDMA8_BASE|...       |...       |...     

# RTC base Table               {#RTCBaseTemplate}

���¼�����չʾ��RTC����洢�ӿڷ�Χ��ģ��, ͬʱҲչʾ�����еĸ���CoXϵ�е�RTC Base�ֲ������
xRTC_BASE| LPC17xx | STM32F1xx|  Mini51 | M051 
---------|---------|----------|---------|------
xRTC_BASE|xRTC_BASE|xRTC_BASE |...      |...   
  

xRTC_BASE| NUC1xx  | NUC122   | NUC123  | NUC2xx 
---------|---------|----------|---------|----------
xRTC_BASE|xRTC_BASE|...       |xRTC_BASE|xRTC_BASE 

xRTC_BASE| KLX     | HT32F125x| HT32F175x
---------|---------|----------|----------
xRTC_BASE|xRTC_BASE|xRTC_BASE |xRTC_BASE 


# WDT base Table               {#WDTBaseTemplate}

���¼�����չʾ��WDT����洢�ӿڷ�Χ��ģ��, ͬʱҲչʾ�����еĸ���CoXϵ�е�WDT Base�ֲ������
xWDT_BASE| LPC17xx | STM32F1xx|  Mini51 | M051 
---------|---------|----------|---------|----------
xWDT_BASE|xWDT_BASE|xWDT_BASE |xWDT_BASE|xWDT_BASE
  

xWDT_BASE| NUC1xx  | NUC122   | NUC123  | NUC2xx 
---------|---------|----------|---------|----------
xWDT_BASE|xWDT_BASE|xWDT_BASE |xWDT_BASE|xWDT_BASE 

xWDT_BASE| KLX     | HT32F125x| HT32F175x
---------|---------|----------|----------
xWDT_BASE|xWDT_BASE|xWDT_BASE |xWDT_BASE  


# UART base Table               {#UARTBaseTemplate}

���¼�����չʾ��UART����洢�ӿڷ�Χ��ģ�壨n��0��5��, ͬʱҲչʾ�����еĸ���CoXϵ�е�UART Base�ֲ������
xUARTn_BASE| LPC17xx   | STM32F1xx |  Mini51   | M051     
-----------|-----------|-----------|-----------|----------
xUART0_BASE|xUART0_BASE|xUART1_BASE|xUART0_BASE|xUART0_BASE
...        |xUART1_BASE|...        |...        |xUART1_BASE
xUART5_BASE|...        |xUART5_BASE|...        |...

xUARTn_BASE| NUC1xx    | NUC122    | NUC123    | NUC2xx 
-----------|-----------|-----------|-----------|----------
xUART0_BASE|xUART0_BASE|xUART0_BASE|xUART0_BASE|xUART0_BASE
...        |xUART1_BASE|xUART1_BASE|xUART1_BASE|xUART1_BASE
xUART5_BASE|xUART2_BASE|...        |...        |xUART2_BASE

xUARTn_BASE| KLX       | HT32F125x | HT32F175x
-----------|-----------|-----------|----------
xUART0_BASE|xUART0_BASE|xUART0_BASE|xUART0_BASE
...        |xUART1_BASE|...        |xUART1_BASE
xUART5_BASE|xUART2_BASE|...        |...        


# I2C base Table               {#I2CBaseTemplate}

���¼�����չʾ��I2C����洢�ӿڷ�Χ��ģ�壨n��0��2��, ͬʱҲչʾ�����еĸ���CoXϵ�е�I2C Base �ֲ������
xI2Cn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xI2C0_BASE|xI2C0_BASE|xI2C0_BASE|xI2C0_BASE|xI2C0_BASE
xI2C1_BASE|xI2C1_BASE|xI2C1_BASE|...       |...       
xI2C2_BASE|xI2C2_BASE|xI2C2_BASE|...       |...       

xI2Cn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xI2C0_BASE|xI2C0_BASE|xI2C0_BASE|xI2C0_BASE|xI2C0_BASE
xI2C1_BASE|xI2C1_BASE|...       |xI2C1_BASE|xI2C1_BASE
xI2C2_BASE|...       |...       |...       |...

xI2Cn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xI2C0_BASE|xI2C0_BASE|xI2C0_BASE|xI2C0_BASE
xI2C1_BASE|xI2C1_BASE|...       |xI2C1_BASE
xI2C2_BASE|...       |...       |...       


# SPI base Table               {#SPIBaseTemplate}

���¼�����չʾ��SPI����洢�ӿڷ�Χ��ģ�壨n��0��3��, ͬʱҲչʾ�����еĸ���CoXϵ�е�SPI Base �ֲ������
xSPIn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xSPI0_BASE|xSPI0_BASE|...       |xSPI0_BASE|xSPI0_BASE
xSPI1_BASE|...       |xSPI1_BASE|...       |xSPI1_BASE    
xSPI2_BASE|...       |xSPI2_BASE|...       |...       
xSPI3_BASE|...       |xSPI2_BASE|...       |...     

xSPIn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xSPI0_BASE|xSPI0_BASE|xSPI0_BASE|xSPI0_BASE|xSPI0_BASE
xSPI1_BASE|xSPI1_BASE|xSPI1_BASE|xSPI1_BASE|xSPI1_BASE
xSPI2_BASE|xSPI2_BASE|...       |xSPI2_BASE|xSPI2_BASE
xSPI3_BASE|xSPI3_BASE|...       |...       |xSPI3_BASE

xSPIn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xSPI0_BASE|xSPI0_BASE|xSPI0_BASE|xSPI0_BASE
xSPI1_BASE|xSPI1_BASE|...       |xSPI1_BASE
xSPI2_BASE|...       |...       |...       
xSPI3_BASE|...       |...       |...        

# I2S base Table               {#I2SBaseTemplate}

���¼�����չʾ��I2S����洢�ӿڷ�Χ��ģ�壨n = 0��, ͬʱҲչʾ�����еĸ���CoXϵ�е�I2S Base �ֲ������
xI2Sn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xI2S0_BASE|xI2S0_BASE|...       |...       |...             
   

xI2Sn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xI2S0_BASE|xI2S0_BASE|...       |xI2S0_BASE|xI2S0_BASE    


xI2Sn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xI2S0_BASE|...       |...       |xI2S0_BASE


# CAN base Table               {#CANBaseTemplate}

���¼�����չʾ��CAN����洢�ӿڷ�Χ��ģ�壨n Ϊ0~2��, ͬʱҲչʾ�����еĸ���CoXϵ�е�CAN Base �ֲ������
xCANn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xCAN0_BASE|...       |...       |...       |...       
xCAN1_BASE|xCAN1_BASE|...       |...       |...       
xCAN2_BASE|xCAN2_BASE|...       |...       |...       
   

xCANn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xCAN0_BASE|xCAN0_BASE|...       |...       |...       
xCAN1_BASE|xCAN0_BASE|...       |...       |...       
xCAN2_BASE|...       |...       |...       |...       


xCANn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xCAN0_BASE|...       |...       |...       
xCAN1_BASE|...       |...       |...       
xCAN2_BASE|...       |...       |...       

# ETH base Table               {#ETHBaseTemplate}

���¼�����չʾ��ETH����洢�ӿڷ�Χ��ģ�壨n Ϊ0��, ͬʱҲչʾ�����еĸ���CoXϵ�е�ETH Base�� �������
xETHn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xETH0_BASE|xETH0_BASE|xETH0_BASE|...       |...       

xETHn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xETH0_BASE|...       |...       |...       |...       


xETHn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xETH0_BASE|...       |...       |...       

# USB base Table               {#USBBaseTemplate}

���¼�����չʾ��USB����洢�ӿڷ�Χ��ģ��, ͬʱҲչʾ�����еĸ���CoXϵ�е�USB Base �ֲ������
xUSB_BASE | LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xUSBD_BASE|xUSBD_BASE|xUSBD_BASE|...       |...       
xUSBH_BASE|xUSBH_BASE|xUSBH_BASE|...       |...       

xUSB_BASE | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xUSBD_BASE|...       |xUSBD_BASE|xUSBD_BASE|xUSBD_BASE
xUSBH_BASE|...       |...       |...       |...       

xUSB_BASE | KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xUSBD_BASE|...       |...       |xUSBD_BASE
xUSBH_B1SE|...       |...       |xUSBH_BASE

# ADC base Table               {#ADCBaseTemplate}

���¼�����չʾ��ADC����洢�ӿڷ�Χ��ģ�壨n Ϊ0~1��, ͬʱҲչʾ�����еĸ���CoXϵ�е�ADC Base  �ֲ������
xADCn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xADC0_BASE|xADC0_BASE|...       |xADC0_BASE|xADC0_BASE
xADC1_BASE|...       |xADC1_BASE|...       |...        
xADC2_BASE|...       |xADC2_BASE|...       |...      
   

xADCn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xADC0_BASE|xADC0_BASE|...       |xADC0_BASE|xADC0_BASE 
xADC1_BASE|...       |...       |...       |...       
xADC2_BASE|...       |xADC2_BASE|...       |...      

xADCn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xADC0_BASE|xADC0_BASE|xADC0_BASE|xADC0_BASE
xADC1_BASE|...       |...       |...       
xADC2_BASE|...       |...       |...       

# DAC base Table               {#DACBaseTemplate}

���¼�����չʾ��DAC����洢�ӿڷ�Χ��ģ�壨n Ϊ0��, ͬʱҲչʾ�����еĸ���CoXϵ�е�DAC Base �� �������
xDACn_BASE| LPC17xx  |STM32F1xx |  Mini51  | M051     
----------|----------|----------|----------|----------
xDAC0_BASE|xDAC0_BASE|xDAC0_BASE|...       |...         

xDACn_BASE| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xDAC0_BASE|...       |...       |...       |...             

xDACn_BASE| KLX      | HT32F125x| HT32F175x
----------|----------|----------|----------
xDAC0_BASE|xDAC0_BASE|...       |...       

# ACMP base Table               {#ACMPBaseTemplate}

���¼�����չʾ��ACMP����洢�ӿڷ�Χ��ģ�壨n Ϊ0��, ͬʱҲչʾ�����еĸ���CoXϵ�е�ACMP Base  �ֲ������
xACMPn_BASE| LPC17xx  |STM32F1xx |  Mini51   | M051     
-----------|----------|----------|-----------|-----------
xACMP0_BASE|...       |...       |xACMP0_BASE|xACMP0_BASE    

xACMPn_BASE| NUC1xx    | NUC122   | NUC123   | NUC2xx 
-----------|-----------|----------|----------|----------
xACMP0_BASE|xACMP0_BASE|...       |...       |xACMP0_BASE       

xACMPn_BASE| KLX       | HT32F125x  | HT32F175x
-----------|-----------|------------|----------
xACMP0_BASE|xACMP0_BASE|xACMP0_BASE |xACMP0_BASE   


