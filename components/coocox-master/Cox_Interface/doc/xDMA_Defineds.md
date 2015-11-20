\page xDMA_page xDMA page 

[TOC]

xDMA document      {#xDMA_document_md}
======
��ƪ������Ҫ���⣬CoX.DMA�Ĺ淶��������
- �����
    - ���������壿
    - �����ĸ�API��
    - ��������ʽ
    - ��������ϵ�е�ʵ�����
- API����
    - ����ԭ��
    - ��Ҫʵ�ֵĹ��ܺ�ÿ������������
    - ����֮������Ӧ�ã����ܣ�

xDMA Interrupt Tab             {#xDMA_Interrupt_md}
==============
- ���ﶨ�����GPIO֧�ֵ�һЩ�ж����ͣ�����:
    - \ref xDMA_INT_TC
    - \ref xDMA_INT_ERROR
- ʹ����������API
    -  \ref xDMAChannelIntEnable  <br>
    -  \ref xDMAChannelIntDisable <br>
	-  \ref xDMAChannelIntFlagGet <br>
	-  \ref xDMAChannelIntFlagClear <br>
	
Interrupts\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
----------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xDMA_INT_TC       |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_INT_ERROR    |  **Y**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |

xDMA Interrupt Event Tab         {#xDMA_Event_md}
==============
- ���ﶨ����� DMA ֧�ֵ�һЩ�¼����ͣ�����:
    - \ref xDMA_EVENT_TC
    - \ref xDMA_EVENT_ERROR
- ʹ����������API
    -  \ref xDMAChannelIntEnable  <br>
    -  \ref xDMAChannelIntDisable <br>
	-  \ref xDMAChannelIntFlagGet <br>
	-  \ref xDMAChannelIntFlagClear <br>
	
Ints_Event\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
----------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xDMA_EVENT_TC     |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_EVENT_ERROR  |  **Y**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |

xDMA Request Connections Mode      {#xDMA_Connect_md}
=====================
- ����궨���� DMA ������ͨ��ģʽ��

Request Connect\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
---------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|   
xDMA_REQUEST_NOT_EXIST |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_REQUEST_MEM       |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_REQUEST_UARTn_RX  |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_REQUEST_UARTn_TX  |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_REQUEST_SPIn_RX   |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_REQUEST_SPIn_TX   |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   | 
xDMA_REQUEST_IISn_RX   |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**N**|   **N**   |   **N**   |
xDMA_REQUEST_IISn_TX   |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**N**|   **N**   |   **N**   |
xDMA_REQUEST_ADC_RX    |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |


xDMA Channel Tab         {#xDMA_Channel_md}
==============
- ����궨���Ƕ��� DMA ��֧�ֵ�ͨ����
- ������ʽ �� xDMA_CHANNEL_n, ���� CHANNEL_n ��ʾ �����ͨ����оƬ��ͬ ����֧�ֵ�n�ķ�Χ Ҳ�᲻ͬ��

  Channel\Series  |       LPC17xx    |      STM32F1xx   | Mini51/M051 | NUC1xx/NUC122/NUC123/NUC2xx |        KLx       | HT32F125x/HT32F175x |   
------------------| -----------------| -----------------| ------------------------------------------| -----------------| --------------------|  
xDMA_CHANNEL_n    |        **N**     |  xDMA_CHANNEL_0  |     **N**   |     xDMA_CHANNEL_0          |  xDMA_CHANNEL_0  |        **N**        |
                | |                  |        ...       |             |          ...                |      ...         |                     |
                | |                  |  xDMA_CHANNEL_31 |             |     xDMA_CHANNEL_31         |  xDMA_CHANNEL_63 |                     |

				  
xDMA Attribution Mode               {#xDMA_Attribution_md}
==============
- ����궨���Ƕ��� DMA �� Attribution ģʽ������:
    - \ref xDMA_ATTR_PRIORITY_NORMAL
    - \ref xDMA_ATTR_PRIORITY_HIGH
	
Attribution Mode\Series   | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |
------------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xDMA_ATTR_PRIORITY_NORMAL |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xDMA_ATTR_PRIORITY_HIGH   |  **N**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xDMA_ATTR_PRIORITY_MASK   |  **N**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |

xDMA Config Mode             {#xDMA_Config_md}
==============
- ����궨���Ƕ��� DMA ͨ������ģʽ������:
    - \ref xDMA_DST_INC_n
    - \ref xDMA_SRC_INC_n
	- \ref xDMA_SRC_SIZE_n
	- \ref xDMA_DST_SIZE_n
	- \ref xDMA_ARB_n
	- \ref xDMA_MODE_BASIC
	- \ref xDMA_MODE_AUTO
	
- �������Ϊ DMAChannelControlSet() �� ulControl �������롣

SlaveSelMode\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |  
------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xDMA_DST_INC_8      |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_DST_INC_16     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_DST_INC_32     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_INC_8      |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_INC_16     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_INC_32     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_SIZE_8     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_SIZE_16    |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_SRC_SIZE_32    |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_DST_SIZE_8     |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_DST_SIZE_16    |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_DST_SIZE_32    |  **N**  |   **Y**   |  **N** | **N**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **N**   |   **N**   |
xDMA_MODE_BASIC     |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**N**|   **N**   |   **N**   |
xDMA_MODE_AUTO      |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**N**|   **N**   |   **N**   |


xDMA API              {#xDMA_Exported_APIs_md}
==========


|       xDMA  API                 |LPC17xx  |STM32F1xx| M051 |Mini51 |NUC1xx |NUC122 |NUC123 |NUC2xx |KLx    |HT32F125x| HT32F175x| LM3S     |
|:--------------------------------|:-------:|:-------:|: ---:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-------:|:--------:|:--------:|
|  \ref xDMAEnable                | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMADisable               | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelDynamicAssign  | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelAssignmentGet  | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelDeAssign       | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelAttributeSet   | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelAttributeGet   | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelControlSet     | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelTransferSet    | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelIntCallbackInit| **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelIntCallbackGet | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelIntEnable      | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAChannelIntDisable     | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAIntEnable             | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
|  \ref xDMAIntDisable            | **Y**   | **Y**   | **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**|  **Y**  |  **Y**   |  **Y**   |
