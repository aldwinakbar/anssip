//*****************************************************************************
//
//! \file xcan.h
//! \brief Prototypes for the CAN Driver.
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

#ifndef _XCAN_H_
#define _XCAN_H_

#include "can.h"

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
//!    		\addtogroup xCAN_Enum xCAN Enum
//!     	@{
//!
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_Ints xCAN Interrupts
//! \brief Values that show xCAN interrupts
//! \n
//! \section xCAN_Ints_Section 1. Where to use this group
//! Values that can be passed to xCANIntEnable, xCANIntDisable, and xCANIntClear
//! as the ulIntFlags parameter, and returned from CANIntStatus. 
//! \n
//! \section xCAN_Ints_CoX 2. CoX Port Details 
//! \verbatim
//! +--------------------------+----------------+------------------------+
//! |xCAN Interrupts           |       CoX      |         LPC17xx        |
//! |--------------------------|----------------|------------------------|
//! |xCAN_INT_OVERRUN          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_INT_TX               |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_INT_RX               |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_INT_ERROR            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_INT_FIFOn(n=0,1...)  |  Non-Mandatory |            Y           |
//! +--------------------------+----------------+------------------------+
//! \endverbatim
//! More please refer to [xCAN Interrupts in MD file](@ref xCAN_Interrupt_md).
//! @{
//
//*****************************************************************************

//
//! Overrun Interrupt
//
#define xCAN_INT_EOT            CAN_INT_EOT
  
//
//! TX Buffer Empty Interrupt
//  
#define xCAN_INT_TX             CAN_INT_TX

//
//! RX Buffer Not Empty Interrupt
//  
#define xCAN_INT_RX             CAN_INT_RX
  
//
//! All ERROR Interrupt
// 
#define xCAN_INT_ERROR          CAN_INT_ERROR

//
//! FIFO0 Interrput
//
#define xCAN_INT_FIFO0          CAN_INT_FIFO0

//
//! FIFO1 Interrput
//
#define xCAN_INT_FIFO1          CAN_INT_FIFO1

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_Ints_Event xCAN Interrupt Event
//! \brief Values that show xCAN interrupt events.
//! \n
//! \section xCAN_Ints_Event_Section 1. Where to use this group
//! Values that can be passed to CANIntEnable, CANIntDisable, and CANIntClear
//! as the ulIntFlags parameter, and returned from CANIntStatus. 
//! \n
//! \section xCAN_Ints_Event_CoX 2. CoX Port Details 
//! \verbatim
//! +--------------------------+----------------+------------------------+
//! |xCAN Interrupts           |       CoX      |         LPC17xx        |
//! |--------------------------|----------------|------------------------|
//! |xCAN_EVENT_OVERRUN        |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_EVENT_TX             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_EVENT_RX             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_EVENT_ERROR          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_EVENT_FIFOn(n=0,1...)|  Non-Mandatory |            Y           |
//! +--------------------------+----------------+------------------------+
//! \endverbatim
//! More please refer to [xCAN Defineds in MD file](@ref xCAN_Config_Event_md).
//! @{
//
//*****************************************************************************

//
//! Overrun Interrupt
//
#define xCAN_EVENT_OVERRUN      CAN_EVENT_OVERRUN
  
//
//! TX Buffer Empty Event
//  
#define xCAN_EVENT_TX           CAN_EVENT_TX

//
//! RX Buffer Not Empty Event
//  
#define xCAN_EVENT_RX           CAN_EVENT_RX
  
//
//! All ERROR Event
// 
#define xCAN_EVENT_ERROR        CAN_EVENT_ERROR

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_Errors xCAN Errors
//! \brief Values that show xCAN Errors
//! \n
//! \section xCAN_Ints_Section 1. Where to use this group
//! Values that can be passed to xCANErrorFlagGet, and xCANErrorFlagClear.
//! as the ulErrorFlags parameter, and returned from CANErrorStatus. 
//! \n
//! \section xCAN_Errors_CoX 2. CoX Port Details 
//! \verbatim
//! +--------------------------+----------------+------------------------+
//! |xCAN Interrupts           |       CoX      |         LPC17xx        |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_STUFF          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_FORM           |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_ACK            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_BitRecessive   |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_BitDominant    |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_CRC            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_ERROR_SOFTWARE       |  Non-Mandatory |            Y           |
//! +--------------------------+----------------+------------------------+
//! \endverbatim
//! More please refer to [xCAN Errors in MD file](@ref xCAN_Errors_md).
//! @{
//
//*****************************************************************************

//
//! Stuff Error 
//
#define xCAN_ERROR_STUFF        CAN_ERROR_STUFF
  
//
//! Form Error
//  
#define xCAN_ERROR_FORM         CAN_ERROR_FORM

//
//! Acknowledgment Error
//  
#define xCAN_ERROR_ACK          xCAN_ERROR_ACK
  
//
//! Bit Recessive Error
// 
#define xCAN_ERROR_BitRecessive CAN_ERROR_BitRecessive

//
//! Bit Dominant Error
//
#define xCAN_ERROR_BitDominant  CAN_ERROR_BitDominant

//
//! CRC Error
//
#define xCAN_ERROR_CRC          CAN_ERROR_CRC

//
//! Software Set Error
//
#define xCAN_ERROR_SOFTWARE     CAN_ERROR_SOFTWARE

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_Config_Mode xCAN Mode
//! \brief Values that show xCAN Mode
//! \n
//! \section xCAN_Mode_Section 1. Where to use this group
//! Values that can be passed to xCANConfigSet.
//! as the ulMode parameter. 
//! \n
//! \section xCAN_Mode_CoX 2. CoX Port Details 
//! \verbatim
//! +--------------------------+----------------+------------------------+
//! |xCAN Interrupts           |       CoX      |         LPC17xx        |
//! |--------------------------|----------------|------------------------|
//! |xCAN_MODE_NORMAL          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_MODE_SILENT          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_MODE_LOOPBACK        |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xCAN_MODE_SILENT_LOOPBACK |    Mandatory   |            Y           |
//! +--------------------------+----------------+------------------------+
//! \endverbatim
//! More please refer to [xCAN Mode in MD file](@ref xCAN_Mode_md).
//! @{
//
//*****************************************************************************

//
//! normal mode
//
#define xCAN_MODE_NORMAL        CAN_MODE_NORMAL

//
//! silent mode
//
#define xCAN_MODE_SILENT        CAN_MODE_SILENT

//
//! loopback mode
//
#define xCAN_MODE_LOOPBACK      CAN_MODE_LOOPBACK

//
//! loopback combined with silent mode
//
#define xCAN_MODE_SILENT_LOOPBACK   CAN_MODE_SILENT_LOOPBACK

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_Msg_Format xCAN type of Frame Format
//! \brief Values that show xCAN Message Format
//! \n
//! \section xCAN_DMA_Section 1. Where to use this group
//! Values that can be passed to xCANSendMessage() and xCANReceiveMessage()
//! as the CAN_Msg parameter. 
//! \n
//! \section xCAN_DMA_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Configs            |       CoX      |         LPC17xx        |
//! |------------------------|----------------|------------------------|
//! |xCAN_ID_STD             |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCAN_ID_EXT             |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! More please refer to [xCAN ID Type in MD file](@ref xCAN_Config_ID_md).
//!
//! |------------------------|----------------|------------------------|
//! |xCAN_RTR_REMOTE         |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCAN_RTR_DATA           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! More please refer to [xCAN RTR in MD file](@ref xCAN_Config_RTR_md).
//!
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! 11-bit ID value
//
#define xCAN_ID_STD             CAN_ID_STD

//
//! 29-bit ID value
//
#define xCAN_ID_EXT             CAN_ID_EXT

//
//! Remote frame
//
#define xCAN_REMOTE_FRAME       CAN_REMOTE_FRAME

//
//! Data frame
//
#define xCAN_DATA_FRAME         CAN_DATA_FRAME

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_FilterMode xCAN Filter Mode
//! \brief Values show xCAN Filter Mode
//! \n
//! \section xCAN_Filter_Section 1. Where to use this group
//! Values that can be passed to xCANFilterConfig()
//! as the ulFilterConfig parameter. 
//! \n
//! \section xCAN_Filter_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xCAN Filter Mode        |       CoX      |         LPC17xx        |
//! |------------------------|----------------|------------------------|
//! |xCAN_FILTERMODE_MASK    |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCAN_FILTERMODE_LIST    |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! More please refer to [xCAN FilterMode in MD file](@ref xCAN_FilterMode_md).
//!
//! |------------------------|----------------|------------------------|
//! |xCAN_FILTERDATA_16Bit   |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xCAN_FILTERDATA_32Bit   |  Non-Mandatory |            Y           |
//! |------------------------|----------------|------------------------|
//! More please refer to [xCAN FilterScale in MD file](@ref xCAN_FilterScale_md).
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! Filter Mode
//
#define xCAN_FILTERMODE_MASK    CAN_FILTERMODE_MASK  
#define xCAN_FILTERMODE_LIST    CAN_FILTERMODE_LIST

//
//! Filter Scale
//
#define xCAN_FILTERSCALE_16Bit  CAN_FILTERSCALE_16Bit
#define xCAN_FILTERSCALE_32Bit  CAN_FILTERSCALE_32Bit

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xCAN_FIFONum xCAN FIFO Number
//! \brief Values that show xCAN FIFO Number
//! \n
//! \section xCAN_FIFONum_Section 1. Where to use this group
//! Values that can be passed to xCANSSSet()
//! as the ulFIFONum parameter. 
//! \n
//! \section xCAN_FIFONum_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xCAN FIFO Number        |       CoX      |         LPC17xx        |
//! |------------------------|----------------|------------------------|
//! |xCAN_FIFO0              |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCAN_FIFO1              |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! More please refer to [xCAN Defineds in MD file](@ref xCAN_FIFONum_md).
//! @{
//
//*****************************************************************************

#define xCAN_FIFO0              CAN_FIFO0   
#define xCAN_FIFO1              CAN_FIFO1

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
//! \addtogroup xCAN_Exported_APIs xCAN API
//! \brief xCAN API Reference.
//!
//! \section xCAN_Exported_APIs_Port CoX Port Details
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xCAN API                |       CoX      |         LPC17xx        |
//! |------------------------|----------------|------------------------|
//! |xCANConfigSet           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANFilterConfig        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANModeSet             |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANSendMessage         |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANReceiveMessage      |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANErrorFlagsGet       |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANErroeFlagsClear     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIntEnable           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIntCallbackInit     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIntDisable          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIntStatusGet        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIntFlagClear        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIsRxEmpty           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xCANIsTxEmpty           |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! CAN message structure definition
//
typedef struct
{
#if 0
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
                        will be transmitted. This parameter can be a value 
                        of @ref CAN_identifier_type */

  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
                        be transmitted. This parameter can be a value of 
                        @ref CAN_remote_transmission_request */
#endif
  unsigned int  Id;
  unsigned char type;
  unsigned char format;
  
  unsigned char Len;  /*!< Specifies the length of the frame that will be 
                           transmitted. This parameter can be a value between 
                           0 to 8 */

  unsigned char Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
                                to 0xFF. */
} CAN_MSG_Type;

//*****************************************************************************
//
//! \brief Configures the CAN peripheral interface.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulBitRate specifies the CAN clock rate.
//! \param ulBitRate specifies the CAN operating mode.
//!
//! This function configures the CAN peripheral interface.  It sets
//! the CAN mode of operation, bit rate, and data width and the first
//! bit.
//!
//! \return None.
//
//*****************************************************************************
extern void xCANConfigSet(unsigned long ulBase, unsigned long ulBitRate);

//*****************************************************************************
//
//! \brief Configures the CAN peripheral interface.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulBitRate specifies the CAN operating mode.
//!
//! This function configures the CAN peripheral interface.  It sets
//! the CAN mode of operation.
//!
//! \return None.
//
//*****************************************************************************
extern void xCANModeSet(unsigned long ulBase, unsigned long ulMode);

//*****************************************************************************
//
//! \brief Configures the CAN reception filter according to the specified parameters.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulFilterConfig is the required filter configuration of the CAN.
//!
//! The \e ulConfig parameter is the logical OR of several different values,
//! many of which are grouped into sets where only one can be chosen.
//! xCAN_FILTERMODE_MASK or \b xCAN_FILTERMODE_LIST.
//!
//! \return None.
//
//*****************************************************************************
extern void xCANFilterConfig(unsigned long ulBase, unsigned long ulMsgNum, 
                               unsigned long ulIDType, unsigned long ulIDMask);

//*****************************************************************************
//! \brief      Send message data
//! \param[in]	ulBase	is the base address of the SPI port.
//! \param[in]  ulMsgNum is the massage number.
//! \param[in]	CAN_Msg point to the CAN_MSG_Type Structure, it contains message
//!		information such as: ID, DLC, RTR, ID Format
//!
//! \return Status:
//!           - xtrue: send message successfully
//!           - xfalse: send message unsuccessfully
//
//*****************************************************************************
extern xtBoolean xCANSendMessage(unsigned long ulBase, unsigned long ulMsgNum, 
                                   CAN_MSG_Type *CAN_Msg);

//*****************************************************************************
//
//! \brief Check the status of the Rx buffer of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//!
//! This function Check the Rx buffer status of the specified CAN module.
//!
//! \return Returns the Rx buffer status of the specified CAN port.
//! \b xtrue The Rx buffer is empty,or \b xfalse The Rx buffer is not empty.
//
//*****************************************************************************  
extern xtBoolean xCANIsRxEmpty(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Receive message data.
//!
//! \param ulBase specifies the CAN module base address.
//! \param CAN_Msg point to the CAN_MSG_Type Struct, it will contain received
//!        message information such as: ID, DLC, RTR, ID Format 
//!
//! This function is to Receive message data.
//!
//! The \e ulBase can be one of the following values:
//! \b CAN1_BASE, \b CAN2_BASE.
//!
//! \return An Error Status enumeration value:
//! xtrue : receive message successfully
//! xfalse: receive message unsuccessfully
//
//*****************************************************************************
extern xtBoolean xCANReceiveMessage(unsigned long ulBase, unsigned long ulMsgNum,
                                       CAN_MSG_Type *CAN_Msg);

//*****************************************************************************
//
//! \brief Enable the CAN interrupt of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulIntFlags specifies the type of CAN interrupt.
//! 
//! The ulIntFlags parameter is the logical OR of several different values:
//! \b SPI_INT_RX, \b SPI_INT_TX, or \b SPI_INT_ERRE.
//!
//! This function is to enable the CAN interrupt of the specified CAN port 
//! and install the callback function.
//!
//! \return None.
//
//*****************************************************************************
extern void xCANIntEnable(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
//! \brief Disable the CAN interrupt of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulIntFlags specifies the type of CAN interrupt.
//! 
//! The ulIntFlags parameter is the logical OR of several different values:
//! \b SPI_INT_RX, \b SPI_INT_TX, or \b SPI_INT_ERRE.
//!
//! This function is to disable the CAN interrupt of the specified CAN port 
//!
//! \return None.
//
//*****************************************************************************
extern void xCANIntDisable(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
//! \brief Init interrupts callback for the specified CAN Port.
//!
//! \param ulPort is the base address of the CAN port.
//! \param xtCANCallback is callback for the specified CAN Port.
//!
//! Init interrupts callback for the specified CAN Port.
//!
//! \return None.
//
//*****************************************************************************
extern void xCANIntCallbackInit(unsigned long ulBase, xtEventCallback xtCANCallback);

//*****************************************************************************
//
//! \brief Get the CAN interrupt Status of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//!
//! This function is to get the CAN interrupt flag of the specified CAN port 
//!
//! \return the CAN interrupt flag. It can be the following values:
//! \b .
//
//*****************************************************************************
extern unsigned long xCANIntStatusGet(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Clear the CAN interrupt flag of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulIntFlags specifies the type of CAN interrupt.
//!
//! This function is to clear the CAN interrupt flag of the specified CAN port 
//!
//! \return None.
//
//*****************************************************************************
extern void xCANIntFlagClear(unsigned long ulBase, unsigned long ulIntFlags);


//*****************************************************************************
//
//! \brief Get the CAN error flag of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//!
//! This function is to get the CAN error flag of the specified CAN port 
//!
//! \return the CAN error flag. It can be the following values:
//!  \b xCAN_ERROR_STUFF
//!  \b xCAN_ERROR_FORM
//!  \b xCAN_ERROR_ACK
//!  \b xCAN_ERROR_BitRecessive
//!  \b xCAN_ERROR_BitDominant
//!  \b xCAN_ERROR_CRC
//!  \b xCAN_ERROR_SOFTWARE
//
//*****************************************************************************
extern xtBoolean xCANErrorStatusGet(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Clear the CAN error flag of the specified CAN port.
//!
//! \param ulBase specifies the CAN module base address.
//! \param ulErrorFlags specifies the type of CAN error type.
//!
//! This function is to clear the CAN error flag of the specified CAN port 
//!
//! \return None.
//
//*****************************************************************************
extern void xCANErrorFlagsClear(unsigned long ulBase, unsigned long ulErrorFlags);

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

#endif
