//*****************************************************************************
//
//! \file xadc.h
//! \brief Defines and Macros for ADC API.
//! \version V2.3
//! \date 07/01/2014
//! \author CooCox
//! \copy
//!
//! Copyright (c)  2011, CooCox 
//! All rights reserved.
//! 
//! Redistribution and use in source and binary forms, with or without 
//! modification, are permitted provided that the following conditions 
//! are met: 
//! 
//!     * Redistributions of source code must retain the above copyright 
//! notice, this list of conditions and the following disclaimer. 
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution. 
//!     * Neither the name of the <ORGANIZATION> nor the names of its 
//! contributors may be used to endorse or promote products derived 
//! from this software without specific prior written permission. 
//! 
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#ifndef __xADC_H__
#define __xADC_H__

#include "adc.h"

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//! \addtogroup Cox_Interface Cox Interface 3.0
//! @{
//! 	\addtogroup Cox_Enum Enumeration
//!  	@{
//!    		\addtogroup xADC_Enum xADC Enum
//!     	@{
//!
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup xADC_Data_Resolution xADC Data Resolution
//! \brief Values that show the ADC Data Resolution
//! More please refer to [xADC Data Resolution in MD file](@ref xADC_Resolution_md).
//! @{
//
//*****************************************************************************

//
//! Channel n Data Bit Length
//
#define xADC_DATA_BIT_SIZE      ADC_DATA_BIT_SIZE

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Ints xADC Interrupt Source
//! \brief Values that show the ADC Interrupt source.
//!
//! \section xADC_Ints_Flag 1. Where to use this group
//! They can be passed to xADCIntEnable(), xADCIntDisable() as the ulIntFlags 
//! parameter to enable/disable the corresponding interrupt.
//!
//! \section xADC_Ints_CoX 2. CoX Port Details
//! \verbatim
//! +------------------------+----------------+
//! |xADC Interrupt Source   |       CoX      |
//! |------------------------|----------------|
//! |xADC_INT_COMP           |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADC_INT_END_CONVERSION |    Mandatory   |
//! |------------------------|----------------|
//! \endverbatim
//! More please refer to [xADC Interrupt Source in MD file](@ref xADC_Ints_md).
//! @{
//
//*****************************************************************************

//
//! The comparator0 match Interrupt
//
#define xADC_INT_COMP0          ADC_INT_COMP0

//
//! The comparator1 match Interrupt
//
#define xADC_INT_COMP1          ADC_INT_COMP1

//
//! Interrupt after single cycle conversion
//
#define xADC_INT_END_CONVERSION ADC_INT_END_CONVERSION

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Events xADC Interrupt Event
//! \brief Values that show the interrupt event ID. 
//!
//! Users use the event ID in the interrupt callback function(xtEventCallback)
//! as \b ulEvent parameter to determine what interrupt event occurs. 
//!
//! \section xADC_Events_Comp 1. Where to use this group
//! In CoX ADC standard, the macro like \b xADC_EVENT_$COMPx$ show the comparator
//! x interrupt event, x is 0, 1 and so on.
//! Users use the \ref xADC_INT_COMP with xADCIntEnable() to enable all the 
//! comparators interrupt. Then use \b xADC_EVENT_$COMPx$ in the interrupt
//! callback function to determine what comparator match.
//!
//! \section xADC_Events_END_CONVERSION 2. Where to use this group
//! Users use the \ref xADC_INT_END_CONVERSION with xADCIntEnable() to enable 
//! single cycle conversion. Then use \b xADC_EVENT_END_CONVERSION in the 
//! interrupt callback function to determine if the end conversion is happen.
//!
//! \section xADC_Events_Port 3. CoX Port Details
//! \verbatim
//! +-------------------------+----------------+
//! |xADC Event               |       CoX      |
//! |-------------------------|----------------|
//! |xADC_EVENT_$COMPx$       |  Non-Mandatory |
//! |-------------------------|----------------|
//! |xADC_EVENT_END_CONVERSION|    Mandatory   |
//! |-------------------------|----------------|
//! \endverbatim
//! More please refer to [xADC Interrupt Event in MD file](@ref xADC_Events_md).
//! @{
//
//*****************************************************************************

//
//! The comparator0 match event
//
#define xADC_EVENT_COMP0        ADC_EVENT_COMP0

//
//! The comparator1 match event
//
#define xADC_EVENT_COMP1        ADC_EVENT_COMP1

//
//! The cycle conversion end event
//
#define xADC_EVENT_END_CONVERSION                                             \
                                ADC_EVENT_END_CONVERSION

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Mode xADC Operation Mode
//! \brief Values that show the ADC Operation Mode.
//!
//! \section xADC_Mode_Sec 1. Where to use this group
//! They can be passed to xADCConfigure() as the ulMode parameter to configure
//! the ADC.
//!
//! \section xADC_Mode_Port 2. CoX Port Details
//! \verbatim
//! +---------------------------+----------------+
//! |xADC Mode                  |       CoX      |
//! |---------------------------|----------------|
//! |xADC_MODE_SCAN_SINGLE_CYCLE|    Mandatory   |
//! |---------------------------|----------------|
//! |xADC_MODE_SCAN_CONTINUOUS  |  Non-Mandatory |
//! |---------------------------|----------------|
//! \endverbatim
//! More please refer to [xADC Operation Mode in MD file](@ref xADC_Mode_md).
//! @{
//
//*****************************************************************************
//
//! \brief Single cycle scan mode.
//!
//! A/D conversion will sample and convert the specified steps once in the
//! sequence, from the first step to the end. Then the A/D converter enters idle
//! state.
//
#define xADC_MODE_SCAN_SINGLE_CYCLE                                           \
                                ADC_MODE_SCAN_SINGLE_CYCLE

//
//! \brief Continuous scan mode.
//!
//! A/D conversion will sample and convert the specified steps in the sequence,
//! form the frist step to the end. and then The A/D converter repeat sample 
//! and convert from the first step, continuous.
//!
//! when the mode is set as continuous scan mode, the ADC will begin sample 
//! after enable the ADC.
//
#define xADC_MODE_SCAN_CONTINUOUS                                             \
                                ADC_MODE_SCAN_CONTINUOUS
//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Trigger_Source xADC Trigger Source
//! \brief values that show the ADC trigger source.
//!
//! Can be passed to 
//! xADCConfigure() as the ulTrigger parameter to configure the ADC.
//!
//! \section xADC_Trigger_Source_Ext 1. External Pin Event In CoX Standard
//! CoX defines macros like \b xADC_TRIGGER_EXT_$ShortPin$, show a trigger   
//! source on an external pin. \b $ShortPin$ is the GPIO short pin Name like 
//! \b EINT0, \b CAP01, etc.
//!
//! \section xADC_Trigger_Source_Port 2. CoX Port Details
//! \verbatim
//! +---------------------------+----------------+
//! |xADC Trigger Source        |       CoX      |
//! |---------------------------|----------------|
//! |xADC_TRIGGER_PROCESSOR     |    Mandatory   |
//! |---------------------------|----------------|
//! |xADC_TRIGGER_EXT_$ShortPin$|  Non-Mandatory |
//! |                           |                |
//! |                           |                |
//! |                           |                |
//! |                           |                |
//! |                           |                |
//! |---------------------------|----------------|
//! \endverbatim
//! More please refer to [xADC Trigger Source in MD file](@ref xADC_Trigger_Src_md).
//! @{
//
//*****************************************************************************

//
//! Processor trigger (Software)
//
#define xADC_TRIGGER_PROCESSOR         ADC_START_MODE_NOW

//
//! External int0 pin trigger.
//
#define xADC_TRIGGER_EXT_EINT0         ADC_START_MODE_EINT0

//
//! External cap01 pin trigger.
//
#define xADC_TRIGGER_EXT_CAP01         ADC_START_MODE_CAP01

//
//! External mat01 pin trigger.
//
#define xADC_TRIGGER_EXT_MAT01         ADC_START_MODE_MAT01

//
//! External mat03 pin trigger.
//
#define xADC_TRIGGER_EXT_MAT03         ADC_START_MODE_MAT03

//
//! External mat10 pin trigger.
//
#define xADC_TRIGGER_EXT_MAT10         ADC_START_MODE_MAT10

//
//! External mat11 pin trigger.
//
#define xADC_TRIGGER_EXT_MAT11         ADC_START_MODE_MAT11

//
// Others add after these moudles finish
//

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_EXT_Trigger_Mode xADC External Tigger Source Mode
//! \brief Values that show the ADC external trigger source mode.
//!
//! Can be passed 
//! to the xADCConfigure() as the ulTrigger parameter, when the trigger source
//! set as xADC_TRIGGER_EXT_$ShortPin$. The ulTrigger parameter is an OR vaule 
//! with the \ref xADC_Trigger_Source. such as  
//! \ref xADC_TRIGGER_EXT_PB8 | \ref xADC_TRIGGER_EXT_RISING_EDGE.
//!
//! \section xADC_EXT_Trigger_Mode_Port CoX Port Details
//!
//! \verbatim
//! +-----------------------------+----------------+
//! |xADC Ext Trigger Mode        |       CoX      |
//! |-----------------------------|----------------|
//! |xADC_TRIGGER_EXT_LOW_LEVEL   |  Non-Mandatory |
//! |-----------------------------|----------------|
//! |xADC_TRIGGER_EXT_HIGH_LEVEL  |  Non-Mandatory |
//! |-----------------------------|----------------|
//! |xADC_TRIGGER_EXT_RISING_EDGE |  Non-Mandatory |
//! |-----------------------------|----------------|
//! |xADC_TRIGGER_EXT_FALLING_EDGE|  Non-Mandatory |
//! |-----------------------------|----------------|
//! |xADC_TRIGGER_EXT_BOTH_EDGE   |  Non-Mandatory |
//! |-----------------------------|----------------|
//! \endverbatim
//! More please refer to [xADC External Tigger Source in MD file](@ref xADC_ExtTrigger_Mode_md).
//! @{
//
//*****************************************************************************

//
//! EXT Tigger is low level.
//
#define xADC_TRIGGER_EXT_LOW_LEVEL                                       \
                                ADC_TRIGGER_EXT_LOW_LEVEL

//
//! EXT Tigger is high level.
//
#define xADC_TRIGGER_EXT_HIGH_LEVEL                                      \
                                ADC_TRIGGER_EXT_HIGH_LEVEL

//
//! EXT Tigger is rising edge.
//
#define xADC_TRIGGER_EXT_RISING_EDGE                                     \
                                ADC_TRIGGER_EXT_RISING_EDGE

//
//! EXT Tigger is falling edge.
//
#define xADC_TRIGGER_EXT_FALLING_EDGE                                    \
                                ADC_TRIGGER_EXT_FALLING_EDGE

//
//! EXT Tigger is both rising and falling edge.
//
#define xADC_TRIGGER_EXT_BOTH_EDGE                                       \
                                ADC_TRIGGER_EXT_BOTH_EDG

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Step_Config xADC Step Config
//! \brief ADC step config values, such as single-end / diffrence, channel source.
//!
//! They are can be passed to the xADCStepConfigure() as the ulConfig parameter.
//! 
//! \section xADC_Step_Config_Divide xADC Step Config Divide
//! The Step Config value is an logic OR type of the following config:
//! - Channel source select, like \b xADC_CTL_$CHx$, such as \ref xADC_CTL_CH0.
//! Or \ref xADC_CTL_TS to select the temperature sensor.
//! - Comparator select to monitor the convertion value, like 
//! \b xADC_CTL_$CMPx$, such as \ref xADC_CTL_CMP0. If don't use the monitor 
//! function, just ingor this macro.
//! - single-end / diffrence input mode. xADC_CTL_D shows diffrence input mode,
//! and if it's single-end mode, just ingore this macro.
//! - \ref xADC_CTL_END shows this is the end step. If the configured step isn't
//! the end step, just ingor this macro.
//! .
//! \section xADC_Step_Config_Sec_Port CoX Port Details
//! \verbatim
//! +----------------+----------------+
//! |xADC Step Config|       CoX      |
//! |----------------|----------------|
//! |xADC_CTL_CH$x$  |  NonMandatory  |
//! |                |                |
//! |                |                |
//! |                |                |
//! |                |                |
//! |                |                |
//! |                |                |
//! |                |                |
//! |----------------|----------------|
//! |xADC_CTL_TS     |  Non-Mandatory |
//! |----------------|----------------|
//! |xADC_CTL_CMP$x$ |  Non-Mandatory |
//! |----------------|----------------|
//! |xADC_CTL_D      |  Non-Mandatory |
//! |----------------|----------------|
//! |xADC_CTL_END    |  Non-Mandatory |
//! |----------------|----------------|
//! \endverbatim
//! More please refer to [xADC Step Config in MD file](@ref xADC_StepConfig_md).
//! @{
//
//*****************************************************************************

//
//! Temperature sensor select
//
#define xADC_CTL_TS             ADC_CTL_TS

//
//! Sequence end select 
//
#define xADC_CTL_END            ADC_CTL_END  

//
//! Differential select
//
#define xADC_CTL_D              ADC_CTL_D  

//
//! Input channel 0
//
#define xADC_CTL_CH0            ADC_CTL_CH0  

//
//! Input channel 1
//
#define xADC_CTL_CH1            ADC_CTL_CH1  

//
//! Input channel 2
//
#define xADC_CTL_CH2            ADC_CTL_CH2 

//
//! Input channel 3
//
#define xADC_CTL_CH3            ADC_CTL_CH3

//
//! Input channel 4
//
#define xADC_CTL_CH4            ADC_CTL_CH4

//
//! Input channel 5
//
#define xADC_CTL_CH5            ADC_CTL_CH5

//
//! Input channel 6
//
#define xADC_CTL_CH6            ADC_CTL_CH6

//
//! Input channel 7
//
#define xADC_CTL_CH7            ADC_CTL_CH7

//
//! Input channel 8
//
#define xADC_CTL_CH8            ADC_CTL_CH8

//
//! Input channel 9
//
#define xADC_CTL_CH9            ADC_CTL_CH9

//
//! Input channel 10
//
#define xADC_CTL_CH10           ADC_CTL_CH10

//
//! Input channel 11
//
#define xADC_CTL_CH11           ADC_CTL_CH11

//
//! Input channel 12
//
#define xADC_CTL_CH12           ADC_CTL_CH12

//
//! Input channel 13
//
#define xADC_CTL_CH13           ADC_CTL_CH13

//
//! Input channel 14
//
#define xADC_CTL_CH14           ADC_CTL_CH14

//
//! Input channel 15
//
#define xADC_CTL_CH15           ADC_CTL_CH15

//
//! Select Comparator 0
//
#define xADC_CTL_CMP0           ADC_CTL_CMP0  

//
//! Select Comparator 1
//
#define xADC_CTL_CMP1           ADC_CTL_CMP1

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Comparator_IDs xADC Comparator ID
//! \brief IDs/index of the ADC digital comparator.
//!
//! They can be passed to the flowing function as ulComp parameter:
//! - xADCCompConditionConfig(), xADCCompRegionSet() to configure the comparator.
//! - xADCCompEnable(), xADCCompDisable() to enable/disable the comparator.
//! .
//! \section xADC_Comparator_IDs_Port CoX Port Details
//! \verbatim
//! +----------------+----------------+
//! |xADC Comp ID    |       CoX      |
//! |----------------|----------------|
//! |xADC_COMP_$x$   |  Non-Mandatory |
//! |----------------|----------------|
//! \endverbatim
//! More please refer to [xADC Comparator ID in MD file](@ref xADC_ComparatorID_md).
//! @{
//
//*****************************************************************************

//
// Comparator 0
//
#define xADC_COMP_0             ADC_COMP_0

//
// Comparator 1
//
#define xADC_COMP_1             ADC_COMP_1

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xADC_Comparator_Int_Condition xADC Comp Interrupt Condition
//! \brief Conditions when the digital comparator generate and interrupt.
//!
//! They can be passed to xADCCompConditionConfig() as the ulConfig parameter to
//! configure the comparator interrupt condition.
//!
//! \section xADC_Comparator_Int_Condition_Port CoX Port Details
//! \verbatim
//! +-------------------------+----------------+
//! |xADC Comp Int Condition  |       CoX      |
//! |-------------------------|----------------|
//! |xADC_COMP_INT_LOW        |  Non-Mandatory |
//! |-------------------------|----------------|
//! |xADC_COMP_INT_MID        |  Non-Mandatory |
//! |-------------------------|----------------|
//! |xADC_COMP_INT_HIGH       |  Non-Mandatory |
//! +-------------------------+----------------+
//! \endverbatim
//! More please refer to [xADC Comp Interrupt Condition in MD file](@ref xADC_CompIntCondition_md).
//! @{
//
//*****************************************************************************

//
//! Always generate ADC interrupt when ADC output is in the low-band.
//
#define xADC_COMP_INT_LOW       ADC_COMP_INT_LOW

//
//! Always generate ADC interrupt when ADC output is in the mid-band.
//
#define xADC_COMP_INT_MID       ADC_COMP_INT_MID

//
//! Always generate ADC interrupt when ADC output is in the high-band.
//
#define xADC_COMP_INT_HIGH      ADC_COMP_INT_HIGH

//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//!     @}
//!   @}
//
//*****************************************************************************

//*****************************************************************************
//! 	\addtogroup LPC17xx_Cox_API API Reference
//!  	@{
//!
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup xADC_Exported_APIs xADC API
//! \brief xADC API Reference
//!
//! \section xADC_Exported_APIs_Port CoX Port Details
//! \verbatim
//! +------------------------+----------------+
//! |xADC API                |       CoX      |
//! |------------------------|----------------|
//! |xADCConfigure           |    Mandatory   |
//! |------------------------|----------------|
//! |xADCStepConfigure       |    Mandatory   |
//! |------------------------|----------------|
//! |xADCIntCallbackInit     |    Mandatory   |
//! |------------------------|----------------|
//! |xADCIntEnable           |    Mandatory   |
//! |------------------------|----------------|
//! |xADCIntDisable          |    Mandatory   |
//! |------------------------|----------------|
//! |xADCDMAEnable           |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADCDMADisable          |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADCEnable              |    Mandatory   |
//! |------------------------|----------------|
//! |xADCDisable             |    Mandatory   |
//! |------------------------|----------------|
//! |xADCProcessorTrigger    |    Mandatory   |
//! |------------------------|----------------|
//! |xADCDataGet             |    Mandatory   |
//! |------------------------|----------------|
//! |xADCOverflow            |    Mandatory   |
//! |------------------------|----------------|
//! |xADCOverflowClear       |    Mandatory   |
//! |------------------------|----------------|
//! |xADCCompConditionConfig |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADCCompRegionSet       |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADCCompEnable          |  Non-Mandatory |
//! |------------------------|----------------|
//! |xADCCompDisable         |  Non-Mandatory |
//! |------------------------|----------------|
//! \endverbatim
//! more please refer to [xADC API in MD file](@ref xADC_Exported_APIs_md).
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Configures the mode and trigger source of a sample sequence.
//!
//! \param ulBase is the base address of the ADC module. 
//!        \ref xLowLayer_Peripheral_Memmap
//! \param ulMode is the sequence operation mode. Refrence \ref xADC_Mode.
//! \param ulTrigger is the trigger source that initiates the sample sequence;
//! must be one of the \b xADC_TRIGGER_* values. Refrence 
//! \ref xADC_Trigger_Source.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCConfigure(unsigned long ulBase, unsigned long ulMode, 
                          unsigned long ulTrigger);

//*****************************************************************************
//
//! \brief Configure a step of the sample sequencer.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulStep is the step to be configured.
//! \param ulConfig is the configuration of this step; must be a logical OR of
//! \b xADC_CTL_TS,  \b xADC_CTL_END, \b xADC_CTL_D, and one of the input 
//! channel selects (\b xADC_CTL_CH0 through \b xADC_CTL_CH7).  For parts
//! with the digital comparator feature, the follow values may also be OR'd
//! into the \e ulConfig value to enable the digital comparater feature:
//! one of the comparater selects (\b xADC_CTL_CMP0 through xADC_CTL_CMP1). 
//! Refrence \ref xADC_Step_Config.
//!
//! This function will set the configuration of the ADC for one step of a
//! sample sequence.  The ADC can be configured for single-ended or
//! differential operation (the \b xADC_CTL_D bit selects differential
//! operation when set), the channel to be sampled can be chosen (the
//! \b xADC_CTL_CH0 through \b xADC_CTL_CH7 values), and the internal
//! temperature sensor can be selected (the \b xADC_CTL_TS bit).  Additionally,
//! this step can be defined as the last in the sequence (the \b xADC_CTL_END
//! bit) .  If the digital comparators are present
//! on the device, this step may also be configured send the ADC sample to
//! the selected comparator (the \b xADC_CTL_CMP0 through \b xADC_CTL_CMP1
//! values).  The configuration is used by the
//! ADC at the appropriate time when the trigger for this sequence occurs.
//!
//! \note It is the responsibility of the caller to ensure that a valid 
//! configuration is specified; this function does not check the validity of 
//! the specified configuration.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCStepConfigure(unsigned long ulBase, unsigned long ulStep,
                              unsigned long ulConfig);  

//*****************************************************************************
//
//! \brief Init the ADC  Interrupt Callback function.
//!
//! \param ulBase is the base address of the ADC.
//! \param pfnCallback is the callback function.
//!
//! When there is any ADC intrrupt occrus, Interrupt Handler will 
//! call the callback function. 
//! 
//! param of pfnCallback
//! - pvCBData not used, always 0.
//! - ulEvent is the interrupt event..
//! - ulMsgParam not used, always 0.
//! - pvMsgData not used, always 0.
//! .
//!
//! \return None.
//
//*****************************************************************************
extern void xADCIntCallbackInit(unsigned long ulBase, 
                                xtEventCallback pfnCallback);

//*****************************************************************************
//
//! \brief Enable individual ADC interrupt sources.
//!
//! \param ulBase is the base address of the ADC.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! Enables the indicated ADC interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b xADC_INT_END_CONVERSION - AD conversion interrupt
//! - \b xADC_INT_COMP - Comp0 and Comp1 interrupt
//! .
//!
//! \return None.
//
//*****************************************************************************
extern void xADCIntEnable(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
//! \brief Disable ADC sample sequence interrupts.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulIntFlags is the interrupt flags.
//!
//! This function disables the requested ADC interrupts.  
//! interrupt.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCIntDisable(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
//! \brief Enable ADC DMA operation.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! The specified ADC DMA features are enabled.  The ADC can be
//! configured to use DMA for transmit AD conversion data.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCDMAEnable(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Disable ADC DMA operation.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This function is used to disable ADC DMA features that were enabled
//! by xADCDMAEnable().  The specified SSI DMA features are disabled. 
//!
//! \return None.
//
//*****************************************************************************
extern void xADCDMADisable(unsigned long ulBase);
        
//*****************************************************************************
//
//! \brief Enable ADC sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! Allows the specified sample sequence to be captured when its trigger is
//! detected.  A sample sequence must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCEnable(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Disable the ADC sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! Prevents the sample sequence from being captured when its trigger
//! is detected. 
//! \note The sample sequence should be disabled before it is configured.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCDisable(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Cause a processor trigger for a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This function triggers a processor-initiated sample sequence if the sample
//! sequence trigger is configured to \b xADC_TRIGGER_PROCESSOR. 
//!
//! \return None.
//
//*****************************************************************************
extern void xADCProcessorTrigger(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Get the captured data for a sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//! \param pulBuffer is the address where the data is stored.
//!
//! This function copies data from the specified sample sequence FIFO to
//! a memory resident buffer. The number of samples available in the 
//! FIFO are copied into the buffer, which is assumed to be large enough to
//! hold that many samples. This will only return the samples that are
//! presently available, which may not be the entire sample sequence if it is
//! in the process of being executed.
//!
//! \return Returns the number of samples copied to the buffer.
//
//*****************************************************************************
extern unsigned long xADCDataGet(unsigned long ulBase, 
                                 unsigned long *pulBuffer);

//*****************************************************************************
//
//! \brief Determine if the ADC sample sequence overflow occurred.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This determines if the ADC sample sequence overflow has occurred.  This will
//! happen if the captured samples are not read from the FIFO before the next
//! trigger occurs.
//!
//! \return Returns xfalse if there was not an overflow, and xtrue if there
//! was.
//
//*****************************************************************************
extern xtBoolean xADCOverflow(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Clear the overflow condition on the ADC sample sequence.
//!
//! \param ulBase is the base address of the ADC module.
//!
//! This will clear an overflow condition on one of the sample sequences.  The
//! overflow condition must be cleared in order to detect a subsequent overflow
//! condition (it otherwise causes no harm).
//!
//! \return None.
//
//*****************************************************************************
extern void xADCOverflowClear(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Configure an ADC digital comparator.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulCompID is the ID of the comparator to configure.
//! \param ulConfig is the configuration of the comparator.
//!
//! This function will configure a comparator.  The \e ulConfig parameter is
//! the result of xADC_COMP_INT_xxx value. Refrence 
//! \ref xADC_Comparator_Int_Condition.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCCompConditionConfig(unsigned long ulBase, 
                                    unsigned long ulCompID, 
                                    unsigned long ulConfig);

//*****************************************************************************
//
//! \brief Define the ADC digital comparator regions.
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulCompID is the ID of the comparator to configure.
//! \param ulLowRef is the reference point for the low/mid band threshold.
//! \param ulHighRef is the reference point for the mid/high band threshold.
//!
//! The ADC digital comparator operation is based on three ADC value regions:
//! - \b low-band is defined as any ADC value less than or equal to the
//! \e ulLowRef value.
//! - \b mid-band is defined as any ADC value greater than the \e ulLowRef
//! value but less than or equal to the \e ulHighRef value.
//! - \b high-band is defined as any ADC value greater than the \e ulHighRef
//! value.
//!.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCCompRegionSet(unsigned long ulBase, unsigned long ulCompID, 
                              unsigned long ulLowRef, unsigned long ulHighRef);
        

//*****************************************************************************
//
//! \brief Enable the ADC digital comparator .
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulCompID is the comparator ID.
//!
//! Enables the comparator to monitor the along input.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCCompEnable(unsigned long ulBase, unsigned long ulCompID);

//*****************************************************************************
//
//! \brief Disable the ADC digital comparator .
//!
//! \param ulBase is the base address of the ADC module.
//! \param ulCompID is the comparator ID.
//!
//! Disables the comparator to monitor the along input.
//!
//! \note In the Stellaris Implement, The comparators do note need to enable.
//! Users can switch to use other comparators or not use comparator function.
//!
//! \return None.
//
//*****************************************************************************
extern void xADCCompDisable(unsigned long ulBase, unsigned long ulCompID);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//!   @}
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __xADC_H__

