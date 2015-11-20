\page xCAN_page xCAN page 

[TOC]


xCAN document  {#xCAN_document_md}
======
本篇文章主要讲解，CoX.CAN 的规范，包括：
- 宏参数
    - 参数的意义？
    - 传给哪个API？
    - 参数的形式
    - 各个厂商系列的实现情况
- API函数
    - 函数原型
    - 需要实现的功能和每个参数的意义
    - 函数之间的组合应用（功能）
 

xCAN Interrupt   {#xCAN_Interrupt_md}
================
- 这里定义的是 CAN 支持的一些中断类型，包括:
    - 溢出中断 \ref xCAN_INT_OVERRUN
    - 发送中断 \ref xCAN_INT_TX
    - 接收中断 \ref xCAN_INT_RX
    - 错误中断 \ref xCAN_INT_ERROR
    - FIFO中断 \ref xCAN_INT_FIFOn
- 这组宏作为 \ref xCANIntEnable(), \ref xCANIntDisable(), \ref xCANIntClear() 的 ulIntTNpe 参数传入。
- 其中 xCAN_INT_FIFOn 为非强制中断类型。

|  xCAN Int TNpe    | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|-------------------|:-------:|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  xCAN_INT_OVERRUN |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_INT_TX      |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_INT_RX      |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_INT_ERROR   |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_INT_FIFOn   |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |

xCAN Interrupt Event   {#xCAN_Event_md}
================
- 这里定义的是 CAN 支持的一些事件类型，包括:
    - 溢出事件 \ref xCAN_EVENT_OVERRUN
    - 发送事件 \ref xCAN_EVENT_TX
    - 接收事件 \ref xCAN_EVENT_RX
    - 错误事件 \ref xCAN_EVENT_ERROR
    - FIFO事件 \ref xCAN_EVENT_FIFOn
- 这组宏作为 \ref xCANIntEnable(), \ref xCANIntDisable(), \ref xCANIntClear() 的 ulIntTNpe 参数传入。
- 其中 xCAN_EVENT_FIFOn 为非强制事件类型。

|  xCAN EVENT Type    | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|---------------------|:-------:|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  xCAN_EVENT_OVERRUN |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_EVENT_TX      |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_EVENT_RX      |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_EVENT_ERROR   |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_EVENT_FIFOn   |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |

xCAN Errors Type   {#xCAN_Errors_md}
================
- 这里定义的是 CAN 支持的一些中断类型，包括:
    - STUFF错误 \ref xCAN_ERROR_STUFF
    - FORM错误 \ref xCAN_ERROR_FORM
    - 应答错误 \ref xCAN_ERROR_ACK
    - BitRecessive错误 \ref xCAN_ERROR_BitRecessive
    - BitDominant错误 \ref xCAN_ERROR_BitDominant
	- CRC校验错误 \ref xCAN_ERROR_CRC
	- 软错误  \ref xCAN_ERROR_SOFTWARE
- 这组宏作为 \ref xCANErrorFlagGet(), \ref xCANErrorFlagClear() 的 ulErrorFlags 参数传入。
- 其中 xCAN_ERROR_SOFTWARE 为非强制中断类型。

|  xCAN EVENT Type       | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|------------------------|:-------:|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
| xCAN_ERROR_STUFF       |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_FORM        |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_ACK         |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_BitRecessive|  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_BitDominant |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_CRC         |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
| xCAN_ERROR_SOFTWARE    |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |

xCAN Mode   {#xCAN_Mode_md}
================
- 这里定义的是 CAN 支持的一些事件类型，包括:
    - 正常模式 \ref xCAN_MODE_NORMAL
    - 静默模式 \ref xCAN_MODE_SILENT
    - 回环模式 \ref xCAN_MODE_LOOPBACK
    - 静默回环模式 \ref xCAN_MODE_SILENT_LOOPBACK
- 这组宏作为 \ref xCANConfigSet() 的 ulMode 参数传入。

|  xCAN Mode Type           | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|---------------------------|:-------:|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  xCAN_MODE_NORMAL         |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_MODE_SILENT         |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_MODE_LOOPBACK       |  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |
|  xCAN_MODE_SILENT_LOOPBACK|  **Y**  |  **Y**  | **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**|  **N**  |  **N**   |  **N**   |

xCAN ID Type                 {#xCAN_Config_ID_md}
================


xCAN RTR Type                {#xCAN_Config_RTR_md}
================


xCAN Filter Mode             {#xCAN_FilterMode_md}
================


xCAN Filter Scale            {#xCAN_FilterScale_md}
================


xCAN FIFO Number             {#xCAN_FIFONum_md}
================

