\page xint_page xint page 

[TOC]

xlowlayer Interrupt template              {#xlowlayerBaseInt}
========
CoX xlowlayer Int template提取了一套ARM Cortex MCU通用强制类型的中断ID，这里不仅展示了所有通用强制类型中断ID，同时也分别列出了各个系列MCU所拥有的中断及其ID编号范围。

> **NOTE:**
>
> 这里的ID编号范围是指相关外设ID编号的范围。


# GPIO Int Table               {#GPIOIntTemplate}

- 以下几个表展示了各系列GPIO中断ID模板（n从A到G）, 同时也展示了已有的各个CoX系列的GPIO Port Int分布情况。
xINT_GPIOn| LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_GPIOA|xINT_GPIOA|xINT_GPIOA|xINT_GPIOA|xINT_GPIOA
...       |xINT_GPIOC|...       |...       |...       
xINT_GPIOG|...       |xINT_GPIOG|xINT_GPIOF|xINT_GPIOF

xINT_GPIOn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_GPIOA|xINT_GPIOA|xINT_GPIOA|xINT_GPIOA <br> ... <br> xINT_GPIOD|xINT_GPIOA <br> ... <br> xINT_GPIOD
...       |...       |...       |xINT_GPIOF|xINT_GPIOF 
xINT_GPIOG|xINT_GPIOE|xINT_GPIOD|...       |...       

xINT_GPIOn| KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_GPIOA|xINT_GPIOA|xINT_GPIOA|xINT_GPIOA
...       |xINT_GPIOD|xINT_GPIOB|...       
xINT_GPIOG|...       |...       |xINT_GPIOE


# EINT Int Table               {#EINTIntTemplate}

- 以下几个表展示了各系列EINT中断ID模板（n从0到15）, 同时也展示了已有的各个CoX系列的EINT Int分布情况。
xINT_EINTn| LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_EINT0|xINT_EINT0|xINT_EINT0|xINT_EINT0|xINT_EINT0
...       |...       |...       |xINT_EINT1|xINT_EINT1
xINT_EINT15|xINT_EINT3|xINT_EINT4|...       |...       

xINT_EINTn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_EINT0|xINT_EINT0|xINT_EINT0|xINT_EINT0|xINT_EINT0
...       |xINT_EINT1|xINT_EINT1|xINT_EINT1|xINT_EINT1 
xINT_EINT15|...       |...       |...       |...       

xINT_EINTn| KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_EINT0|xINT_EINT0|xINT_EINT0|xINT_EINT0
...       |xINT_EINT3|xINT_EINT1|...       
xINT_EINT15|...       |...       |xINT_EINT15

# TIMER Int Table               {#TimerIntTemplate}

- 以下几个表展示了各系列DMA中断ID模板（n从0到2）, 同时也展示了已有的各个CoX系列的DMA Int分布情况 。

xINT_TIMERn | LPC17xx | STM32F1xx | Mini51 | M051  | NUC1xx | NUC122 | NUC123 | NUC2xx |  KLx  | HT32F125x | HT32F175x | LM3S  |        
------------|---------|-----------|------- |-------|--------|--------|--------|--------|-------|-----------|-----------|-------|
xINT_TIMER0 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER1 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER2 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER3 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER4 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER5 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER6 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |
xINT_TIMER7 |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |

# PWM Int Table               {#PWMIntTemplate}

- 以下几个表展示了各系列PWM中断ID模板（n从A到C）, 同时也展示了已有的各个CoX系列的PWM Int分布情况 。
xINT_PWMn| LPC17xx  | STM32F1xx|  Mini51  | M051     
---------|----------|----------|----------|----------
xINT_PWMA|xINT_PWMA |xINT_PWMA |xINT_PWMA |xINT_PWMA
...      |...       |xINT_PWMB |...       |xINT_PWMB
xINT_PWMC|...       |...       |...       |...      

xINT_PWMn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
---------|----------|----------|----------|----------
xINT_PWMA|xINT_PWMA |xINT_PWMA |xINT_PWMA |xINT_PWMA
...      |xINT_PWMB |...       |...       |xINT_PWMB 
xINT_PWMC|...       |...       |...       |...       

xINT_PWMn| KLX      | HT32F125x| HT32F175x
---------|----------|----------|----------
xINT_PWMA|xINT_PWMA |...       |...       
...      |xINT_PWMB |...       |...       
xINT_PWMC|xINT_PWMC |...       |...       

# DMA Int Table               {#DMAIntTemplate}

- 以下几个表展示了各系列DMA中断ID模板（n从0到2）, 同时也展示了已有的各个CoX系列的DMA Int分布情况 。
xINT_DMAn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_DMA0 |xINT_DMA0 |...       |...       |...       
xINT_DMA1 |...       |xINT_DMA1 |...       |...       
xINT_DMA2 |...       |xINT_DMA2 |...       |...       

xINT_DMAn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_DMA0 |xINT_DMA0 |...       |xINT_DMA0 |xINT_DMA0
xINT_DMA1 |...       |...       |...       |...       
xINT_DMA2 |...       |...       |...       |...       

xINT_DMAn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_DMA0 |xINT_DMA0 |...       |xINT_DMA0
xINT_DMA1 |...       |...       |...       
xINT_DMA2 |...       |...       |...       


# RTC Int Table               {#RTCIntTemplate}
- 以下几个表展示了各系列RTC中断模板, 同时也展示了已有的各个CoX系列的 RTC Int 分布情况。
xINT_RTC | LPC17xx | STM32F1xx | Mini51 | M051  | NUC1xx | NUC122 | NUC123 | NUC2xx |  KLx  | HT32F125x | HT32F175x | LM3S  |        
---------|---------|-----------|------- |-------|--------|--------|--------|--------|-------|-----------|-----------|-------|
xINT_RTC |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |

# WDT Int Table               {#WDTIntTemplate}
- 以下几个表展示了各系列WDT中断模板, 同时也展示了已有的各个CoX系列的 WDT Int 分布情况。
xINT_WDT | LPC17xx | STM32F1xx | Mini51 | M051  | NUC1xx | NUC122 | NUC123 | NUC2xx |  KLx  | HT32F125x | HT32F175x | LM3S  |        
---------|---------|-----------|------- |-------|--------|--------|--------|--------|-------|-----------|-----------|-------|
xINT_WDT |  **Y**  |   **Y**   | **Y**  | **Y** | **Y**  | **Y**  | **Y**  |  **Y** | **Y** |   **Y**   |   **Y**   | **Y** |

# ETH Int Table               {#ETHIntTemplate}
- 以下几个表展示了各系列ETH中断模板, 同时也展示了已有的各个CoX系列的 ETH Int 分布情况。
xINT_ETH | LPC17xx | STM32F1xx | Mini51 | M051  | NUC1xx | NUC122 | NUC123 | NUC2xx |  KLx  | HT32F125x | HT32F175x | LM3S  |        
---------|---------|-----------|------- |-------|--------|--------|--------|--------|-------|-----------|-----------|-------|
xINT_ETH |  **Y**  |   **N**   | **N**  | **N** | **N**  | **N**  | **N**  |  **N** | **N** |   **N**   |   **N**   | **N** |


# QEI Int Table               {#QEIIntTemplate}

- 以下几个表展示了各系列QEI中断ID模板, 同时也展示了已有的各个CoX系列的QEI Int 分布情况。
xINT_QEI| LPC17xx  | STM32F1xx|  Mini51  | M051     
---------|----------|----------|----------|----------
xINT_QEI|xINT_QEI |...       |...       |...       

xINT_QEI| NUC1xx   | NUC122   | NUC123   | NUC2xx 
---------|----------|----------|----------|----------
xINT_QEI|xINT_QEI |xINT_QEI |...      |...       
   

xINT_QEI| KLX      | HT32F125x| HT32F175x
---------|----------|----------|----------
xINT_QEI|...       |...       |...      

# UART Int Table               {#UARTIntTemplate}

 - 以下几个表展示了各系列UART中断ID模板（n从0到5）, 同时也展示了已有的各个CoX系列的UART Int分布情况。
xINT_UARTn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_UART0 |xINT_UART0 |xINT_UART1 |xINT_UART0 |xINT_UART0 
...       |...       |...       |...       |xINT_UART1   
xINT_UART5 |xINT_UART3 |xINT_UART5 |...       |...       

xINT_UARTn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_UART0 |xINT_UART0 |xINT_UART0|xINT_UART0|xINT_UART0
...       |...       |xINT_UART1 |xINT_UART1|xINT_UART1 
xINT_UART5 |xINT_UART2|...       |...       |...       

xINT_UARTn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_UART0 |xINT_UART0 |xINT_UART0|xINT_UART0
...       |...       |...       |xINT_UART1
xINT_UART5 |xINT_UART2|...       |...       


# I2C Int Table               {#I2CIntTemplate}

- 以下几个表展示了各系列I2C中断ID模板（n从0到2）, 同时也展示了已有的各个CoX系列的I2C Int分布情况。
xINT_I2Cn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_I2C0 |xINT_I2C0 |...       |xINT_I2C0 |xINT_I2C0 
xINT_I2C1 |xINT_I2C1 |xINT_I2C1 |...       |...        
xINT_I2C2 |xINT_I2C2 |xINT_I2C2 |...       |...       

xINT_I2Cn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_I2C0 |xINT_I2C0 |xINT_I2C0 |xINT_I2C0 |xINT_I2C0
xINT_I2C1 |xINT_I2C1 |...       |xINT_I2C1 |xINT_I2C1 
xINT_I2C2 |...       |...       | ...      |...       

xINT_I2Cn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_I2C0 |xINT_I2C0 |xINT_I2C0 |xINT_I2C0
xINT_I2C1 |xINT_I2C1 |...       |xINT_I2C1
xINT_I2C2 |...       |...       |...        


# SPI Int Table               {#SPIIntTemplate}

- 以下几个表展示了各系列SPI中断ID模板（n从0到3）, 同时也展示了已有的各个CoX系列的SPI Int分布情况。
xINT_SPIn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_SPI0 |xINT_SPI0 |...       |xINT_SPI0 |xINT_SPI0 
xINT_SPI1 |...       |xINT_SPI1 |...       |xINT_SPI1  
xINT_SPI2 |...       |xINT_SPI2 |...       |...       
xINT_SPI3 |...       |xINT_SPI3 |...       |...       

xINT_SPIn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_SPI0 |xINT_SPI0 |xINT_SPI0 |xINT_SPI0 |xINT_SPI0
xINT_SPI1 |xINT_SPI1 |xINT_SPI1 |xINT_SPI1 |xINT_SPI1 
xINT_SPI2 |xINT_SPI2 |...       |xINT_SPI2 |xINT_SPI2 
xINT_SPI3 |xINT_SPI3 |...       |...       |xINT_SPI3

xINT_SPIn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_SPI0 |xINT_SPI0 |xINT_SPI0 |xINT_SPI0
xINT_SPI1 |xINT_SPI1 |...       |xINT_SPI1
xINT_SPI2 |...       |...       |...       
xINT_SPI3 |...       |...       |...      

# CAN Int Table               {#CANIntTemplate}

- 以下几个表展示了各系列CAN中断ID模板（n从0到1）, 同时也展示了已有的各个CoX系列的CAN Int分布情况 。
xINT_CANn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_CAN0 |xINT_CAN0 |xINT_CAN0 |xINT_CAN0 |xINT_CAN0 
xINT_CAN1 |...       |xINT_CAN1 |...       |xINT_CAN1    

xINT_CANn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_CAN0 |xINT_CAN0 |...       |...       |...       
xINT_CAN1 |...       |...       |...       |...       

xINT_CANn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_CAN0 |...       |...       |...       
xINT_CAN1 |...       |...       |...       


# I2S Int Table               {#I2SIntTemplate}

- 以下几个表展示了各系列I2S中断ID模板（n从0到1）, 同时也展示了已有的各个CoX系列的I2S Int分布情况 。
xINT_I2Sn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_I2S0 |xINT_I2S0 |...       |...       |...       
xINT_I2S1 |...       |...       |...       |...         

xINT_I2Sn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_I2S0 |xINT_I2S0 |...       |xINT_I2S0 |...       
xINT_I2S1 |...       |...       |...       |...       

xINT_I2Sn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_I2S0 |...       |...       |...       
xINT_I2S1 |...       |...       |...       

# USB Int Table               {#USBIntTemplate}

- 以下几个表展示了各系列USB中断ID模板（分别为USB主设备和从设备）, 同时也展示了已有的各个CoX系列 的USB Int分布情况。
xINT_USBn | LPC17xx  | STM32F1xx|  Mini51  | M051     
----------|----------|----------|----------|----------
xINT_USBD |xINT_USBD |xINT_USBD |...       |...       
xINT_USBH |xINT_USBH |xINT_USBH |...       |...         

xINT_USBn | NUC1xx   | NUC122   | NUC123   | NUC2xx 
----------|----------|----------|----------|----------
xINT_USBD |...       |...       |...       |...       
xINT_USBH |...       |...       |...       |...       

xINT_USBn | KLX      | HT32F125x| HT32F175x      
----------|----------|----------|----------
xINT_USBD |...       |...       |...       
xINT_USBH |...       |...       |...       



# ADC Int Table               {#ADCIntTemplate}

- 以下几个表展示了各系列ADC0中断ID模板, 同时也展示了已有的各个CoX系列的ADC Int分布情况 。
xINT_ADCn| LPC17xx  | STM32F1xx|  Mini51  | M051     
---------|----------|----------|----------|----------
xINT_ADC0|xINT_ADC0 |xINT_ADC0 |xINT_ADC0 |xINT_ADC0 

xINT_ADCn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
---------|----------|----------|----------|----------
xINT_ADC0|xINT_ADC0 |...       |...       |xINT_ADC0 
   

xINT_ADCn| KLX      | HT32F125x| HT32F175x
---------|----------|----------|----------
xINT_ADC0|xINT_ADC0 |xINT_ADC0 |xINT_ADC0   


# DAC Int Table               {#DACIntTemplate}

- 以下几个表展示了各系列DAC0中断ID模板, 同时也展示了已有的各个CoX系列的DAC Int分布情况 。
xINT_DACn| LPC17xx  | STM32F1xx|  Mini51  | M051     
---------|----------|----------|----------|----------
xINT_DAC0|...       |...       |...       |...       

xINT_DACn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
---------|----------|----------|----------|----------
xINT_DAC0|...       |...       |...       |...       
   

xINT_DACn| KLX      | HT32F125x| HT32F175x
---------|----------|----------|----------
xINT_DAC0|...       |...       |...       
 
# ACMP Int Table               {#ACMPIntTemplate}

- 以下几个表展示了各系列ACMP0中断ID模板, 同时也展示了已有的各个CoX系列的ACMP Int分布情况 。
xINT_ACMPn| LPC17xx  | STM32F1xx|  Mini51  | M051     
---------|----------|----------|----------|----------
xINT_ACMP0|...       |...       |xINT_ACMP0 |xINT_ACMP0 

xINT_ACMPn| NUC1xx   | NUC122   | NUC123   | NUC2xx 
---------|----------|----------|----------|----------
xINT_ACMP0|xINT_ACMP0 |...       |...       |xINT_ACMP0 
   

xINT_ACMPn| KLX      | HT32F125x| HT32F175x
---------|----------|----------|----------
xINT_ACMP0|xINT_ACMP0 |xINT_ACMP0 |xINT_ACMP0
