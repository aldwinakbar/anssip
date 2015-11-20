\page xTimer_page xTimer page 

[TOC]

xTimer document              {#xGPIO_document_md}
======
��ƪ������Ҫ���⣬CoX.Timer �Ĺ淶��������
- �����
    - ���������壿
    - �����ĸ�API��
    - ��������ʽ
    - ��������ϵ�е�ʵ�����
- API����
    - ����ԭ��
    - ��Ҫʵ�ֵĹ��ܺ�ÿ������������
    - ����֮������Ӧ�ã����ܣ�

CoX Timer Output Mode Tab   {#xTimer_Config_Mode_md}
====================
- ���ﶨ�����PWM������һЩģʽ������:
    - ���μ�ʱ \ref xTIMER_MODE_ONESHOT
    - ���ڼ�ʱ \ref xTIMER_MODE_PERIODIC
    - ������ʱ \ref xTIMER_MODE_TOGGLE
    - ������ʱ(��ǿ��) \ref xTIMER_MODE_CONTINUOUS
    - �����ʱ(��ǿ��) \ref xTIMER_MODE_CAPTURE
    - PWMģʽ(��ǿ��)  \ref xTIMER_MODE_PWM
- �������Ϊ xTimerInitConfig() �� ulConfig �������롣

 Timer Mode\Series      | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
----------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|   
xTIMER_MODE_ONESHOT     |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_MODE_PERIODIC    |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_MODE_TOGGLE      |  **N**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**N**|   **Y**   |   **Y**   |
xTIMER_MODE_CONTINUOUS  |  **Y**  |   **N**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**N**|   **Y**   |   **Y**   |
xTIMER_MODE_CAPTURE     |  **Y**  |   **Y**   |  **N** | **Y**|  **N** |  **N** |  **N** |  **N** |**N**|   **Y**   |   **Y**   |
xTIMER_MODE_PWM         |  **N**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**N**|   **Y**   |   **Y**   |

xTimer Interrupt Tab             {#xTimer_Interrupt_md}
==============
- ���ﶨ�����PWM֧�ֵ�һЩ�ж����ͣ�����:
    - \ref xTIMER_INT_MATCH
	- \ref xTIMER_INT_CAP_EVENT
	- \ref xTIMER_INT_CAP_MATCH
	- \ref xTIMER_INT_OVERFLOW
	- \ref xTIMER_INT_PWM
- ���� xTIMER_INT_CAP_MATCH��xTIMER_INT_OVERFLOW��xTIMER_INT_PWM �Ƿ�ǿ�ơ�
- ʹ����������API
    -  \ref xTimerIntEnable <br>
    -  \ref xTimerIntDisable <br>
	-  \ref xTimerIntStatus <br>
	-  \ref xTimerIntClear  <br>
	
Interrupts\Series    | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
-------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_INT_MATCH     |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_INT_CAP_EVENT |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   | 
xTIMER_INT_CAP_MATCH |  **N**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xTIMER_INT_OVERFLOW  |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xTIMER_INT_PWM       |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |

xTimer Interrupt Event Tab         {#xTimer_Interrupt_Event_md}
==============
- ���ﶨ�����SPI֧�ֵ�һЩʱ�����ͣ�����:
    - \ref xTIMER_EVENT_MATCH
    - \ref xTIMER_EVENT_CAP_EVENT
	- \ref xTIMER_EVENT_CAP_MATCH
	- \ref xTIMER_EVENT_OVERFLOW
	- \ref xTIMER_EVENT_PWM
- ���� xTIMER_EVENT_CAP_MATCH��xTIMER_EVENT_OVERFLOW��xPWM_EVENT_CAP �Ƿ�ǿ�����ͣ�
- ʹ����������API
    -  \ref xTimerIntEnable <br>
    -  \ref xTimerIntDisable <br>
	-  \ref xTimerIntStatus  <br>
	-  \ref xTimerIntClear  <br>
	
Interrupt Event\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
---------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_EVENT_MATCH     |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_EVENT_CAP_EVENT |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**N**|   **Y**   |   **Y**   |
xTIMER_EVENT_CAP_MATCH |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xTIMER_EVENT_OVERFLOW  |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |
xTIMER_EVENT_PWM       |  **N**  |   **N**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**Y**|   **N**   |   **N**   |


xTimer Channel Tab         {#xTimer_Config_Channel_md}
==============
- ����궨���Ƕ��� PWM ���ͨ����
- ������ʽ �� xTIMER_CHANNELn������CHANNELn��ʾ �����ͨ����оƬ��ͬ ����֧�ֵ�n�ķ�ΧҲ�᲻ͬ��
- �ò�������Ϊ���� Timer��APIs�� ulChannel �������룬������Բ��� APIs List��

  Channel\Series  |       LPC17xx    |    STM32F1xx    |       Mini51    |    M051/NUC1xx  | NUC2xx/NUC122/NUC123 |        KLx       | HT32F125x/HT32F175x |   
------------------| -----------------| ----------------| ----------------|-----------------| ---------------------| -----------------| --------------------|  
xTIMER_CHANNELn   | xTIMER_CHANNEL0  | xTIMER_CHANNEL0 | xTIMER_CHANNEL0 | xTIMER_CHANNEL0 |   xTIMER_CHANNEL0    | xTIMER_CHANNEL0  |  xTIMER_CHANNEL0    |
                | |                  |       ...       |                 |                 |                      |      ...         |        ...          |
                | | xTIMER_CHANNEL1  | xTIMER_CHANNEL3 |                 |                 |                      | xTIMER_CHANNEL3  |  xTIMER_CHANNEL3    |

				
xTimer Counter Type Tab         {#xTimer_Counter_Type_md}
==============
- ������Ƕ��� Timer ���ⲿ�ܽż���ģʽ�����������ػ��½���
    - \ref xTIMER_COUNTER_RISING
    - \ref xTIMER_COUNTER_FALLING	
- �ò�������Ϊ xTimerCounterDetectPhaseSelect() �� ulPhase �������롣

  Counter Type\Series  | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
---------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_COUNTER_RISING  |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_COUNTER_FALLING |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**N**|   **Y**   |   **Y**   |


xTimer Counter Direction Tab         {#xTimer_Counter_Direction_md}
==============
- ������Ƕ��� Timer �����������ϼ����������¼���
    - \ref xTIMER_COUNT_UP
    - \ref xTIMER_COUNT_DOWN
- ���� xTIMER_COUNT_DOWN �Ƿ�ǿ������
- �ò�������Ϊ xTimerInitConfig() �� ulConfig �������롣

Counter Direction\Series | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
------------------------ | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_COUNT_UP          |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **Y** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_COUNT_DOWN        |  **N**  |   **Y**   |  **N** | **N**|  **N** |  **N** |  **N** |  **N** |**N**|   **N**   |   **N**   |



xTimer Capture Type Tab         {#xTimer_Capture_Type_md}
==============
- ������Ƕ��� Timer ������صĹ���
    - \ref xTIMER_CAP_RISING
    - \ref xTIMER_CAP_FALLING	
	- \ref xTIMER_CAP_BOTH
- ���� xTIMER_CAP_BOTH �Ƿ�ǿ������
- �ò�������Ϊ xTimerCaptureEdgeSelect() �� ulPhase �������롣

  Capture Type\Series  | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
---------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_CAP_RISING      |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_CAP_FALLING     |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**Y**|   **Y**   |   **N**   |
xTIMER_CAP_BOTH        |  **Y**  |   **N**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**N**|   **N**   |   **N**   |


xTimer Capture Mode Tab         {#xTimer_Capture_Mode_md}
==============
- ������Ƕ��� Timer ����ģʽ��
    - \ref xTIMER_CAP_MODE_CAP
    - \ref xTIMER_CAP_MODE_RST
- ���� xTIMER_CAP_MODE_RST �Ƿ�ǿ������
- �ò�������Ϊ xTimerCaptureEdgeSelect() �� ulPhase �������롣

  Capture Mode\Series  | LPC17xx | STM32F1xx | Mini51 | M051 | NUC1xx | NUC122 | NUC123 | NUC2xx | KLx | HT32F125x | HT32F175x |   
---------------------- | --------| ----------| -------| -----| -------| -------| -------| -------| ----| ----------| ----------|
xTIMER_CAP_MODE_CAP    |  **Y**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**Y**|   **Y**   |   **Y**   |
xTIMER_CAP_MODE_RST    |  **N**  |   **Y**   |  **Y** | **Y**|  **Y** |  **N** |  **Y** |  **Y** |**N**|   **N**   |   **N**   |
