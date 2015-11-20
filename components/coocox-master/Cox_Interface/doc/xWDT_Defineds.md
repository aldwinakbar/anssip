\page xWDT_page xWDT page 

[TOC]


xWDT document  {#xWDT_document_md}
======
本篇文章主要讲解，CoX.WDT的规范，包括：
- 宏参数
    - 参数的意义？
    - 传给哪个API？
    - 参数的形式
    - 各个厂商系列的实现情况
- API函数
    - 函数原型
    - 需要实现的功能和每个参数的意义
    - 函数之间的组合应用（功能）
 

xWDT Function Type   {#xWDT_FunctionType_md}
================
- 这里定义的是WDT工作的一些模式，包括:
    - 中断 \ref xWDT_INT_FUNCTION
    - 复位 \ref xWDT_RESET_FUNCTION
    - 唤醒 \ref xWDT_WAKEUP_FUNCTION
    - 保持 \ref xWDT_HOLD_IN_ICE
- 这组宏作为 \ref xWDTFunctionEnable() 和 \ref xWDTFunctionDisable() 的ulIntType参数传入。
- 其中 xWDT_WAKEUP_FUNCTION 和 xWDT_HOLD_IN_ICE 是非强制模式。

|  xWDT Function Type   | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|-----------------------|---------|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  xWDT_INT_FUNCTION    |  **Y**  |  **Y**  | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  xWDT_RESET_FUNCTION  |  **Y**  |  **Y**  | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  xWDT_WAKEUP_FUNCTION |   *N*   |   *N*   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  xWDT_HOLD_IN_ICE     |   *N*   |   *N*   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |

xWDT Clock Configuration   {#xWDT_ClockConfiguration_md}
================
- 这里定义的是 WDT 的时钟模式，包括:
    - 内部低速时钟 \ref xWDT_S_INTSL
    - 外部低速时钟 \ref xWDT_S_EXTSL
    - 系统时钟分频 \ref xWDT_S_HCLK_DIV
- 这组宏作为 \ref xWDTInit() 的 ulConfig 参数传入。
- 其中 xWDT_S_HCLK_DIV 是非强制模式。

|  xWDT Clock      | LPC17xx |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|------------------|---------|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  xWDT_S_INTSL    |  **Y**  |  **Y**  | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  xWDT_S_EXTSL    |  **Y**  |  **Y**  | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  xWDT_S_HCLK_DIV |   *N*   |   *N*   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |

