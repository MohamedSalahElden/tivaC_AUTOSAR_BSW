 /*------------------------------------------------------------
 * Module		: DIO
 * File Name	: Dio.h
 * Description	: header file for DIO Module.
 * Author		: Mohamed salah-el-den hussien
 * AR version	: V3.2.3
 * SW version	: V1.0.0
 * ------------------------------------------------------------*/
#ifndef DIO_DRIVER_STATIC_CODE_H_
#define DIO_DRIVER_STATIC_CODE_H_
/*=======================================file version definitions================================================*/
/*-----------------------------------------------------------------
 * software version definition (first release) V1.0.0
 * used to check compatibility between module files
 * ---------------------------------------------------------------*/
#define MODULE_ID   (120U)
#define VENDOR_ID   (1000U)
#define INSTANCE_ID (0U)


#define DIO_SW_MAJOR_VERSION    1U
#define DIO_SW_MINOR_VERSION    0U
#define DIO_SW_BATCH_VERSION    0U

 /*---------------------------------------------------------------
 * autosar version used for this driver is 3.2.3
 * used for compatibility checking between different autosar module
 * ---------------------------------------------------------------*/
#define DIO_AR_MAJOR_VERSION    (3U)
#define DIO_AR_MINOR_VERSION    (2U)
#define DIO_AR_PATCH_VERSION    (3U)

/*=======================================AS_platform inclusion===================================================*/
#include "../../AS_platform/Std_Types.h"
#if(DIO_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION ||   \
    DIO_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION ||   \
    DIO_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION)
#error"AUTOSAR version mismatch between DIO and Std_types"
#endif


/*================================DIO configuration file inclusion================================================*/
#include "../configurations/Dio_Cfg.h"
#if(DIO_AR_MAJOR_VERSION != DIO_CFG_AR_MAJOR_VERSION ||   \
    DIO_AR_MINOR_VERSION != DIO_CFG_AR_MINOR_VERSION ||   \
    DIO_AR_PATCH_VERSION != DIO_CFG_AR_PATCH_VERSION)
#error"AUTOSAR version mismatch between DIO module and Dio_cfg.h"
#endif

#if(DIO_SW_MAJOR_VERSION != DIO_CFG_SW_MAJOR_VERSION ||   \
    DIO_SW_MINOR_VERSION != DIO_CFG_SW_MINOR_VERSION ||   \
    DIO_SW_BATCH_VERSION != DIO_CFG_SW_BATCH_VERSION)
#error"software version mismatch between DIO module and Dio_cfg.h"
#endif


/*=========================DIO post build configuration file inclusion================================================*/
#include "../configurations/Dio_PBCfg.h"
#if(DIO_AR_MAJOR_VERSION != DIO_PBCFG_AR_MAJOR_VERSION ||   \
    DIO_AR_MINOR_VERSION != DIO_PBCFG_AR_MINOR_VERSION ||   \
    DIO_AR_PATCH_VERSION != DIO_PBCFG_AR_PATCH_VERSION)
#error"AUTOSAR version mismatch between DIO module and Dio_PBCfg.h"
#endif

#if(DIO_SW_MAJOR_VERSION != DIO_PBCFG_SW_MAJOR_VERSION ||   \
    DIO_SW_MINOR_VERSION != DIO_PBCFG_SW_MINOR_VERSION ||   \
    DIO_SW_BATCH_VERSION != DIO_PBCFG_SW_BATCH_VERSION)
#error"software version mismatch between DIO module and Dio_PBCfg.h"
#endif


/*=========================DIO post build configuration file inclusion================================================*/
#include "Dio_types.h"
#if(DIO_AR_MAJOR_VERSION != DIO_TYPES_AR_MAJOR_VERSION ||   \
    DIO_AR_MINOR_VERSION != DIO_TYPES_AR_MINOR_VERSION ||   \
    DIO_AR_PATCH_VERSION != DIO_TYPES_AR_PATCH_VERSION)
#error"AUTOSAR version mismatch between Dio.h file and Dio_types.h"
#endif

#if(DIO_SW_MAJOR_VERSION != DIO_TYPES_SW_MAJOR_VERSION ||   \
    DIO_SW_MINOR_VERSION != DIO_TYPES_SW_MINOR_VERSION ||   \
    DIO_SW_BATCH_VERSION != DIO_TYPES_SW_BATCH_VERSION)
#error"software version mismatch between Dio.h file and Dio_types.h"
#endif
/*=========================API ID DEFINITIONS================================================*/
#define DIO_READ_CHANNEL_API_ID             (uint8)0x00
#define DIO_WRITE_CHANNEL_API_ID            (uint8)0x01
#define DIO_READ_PORT_API_ID                (uint8)0x02
#define DIO_WRITE_PORT_API_ID               (uint8)0x03
#define DIO_READ_CHANNEL_GROUP_API_ID       (uint8)0x04
#define DIO_WRITE_CHANNEL_GROUP_API_ID      (uint8)0x05
#define DIO_GET_VERSION_INFO_API_ID         (uint8)0x12
#define DIO_MASKED_WRITE_PORT_API_ID        (uint8)0x13


/*=========================DET ERROR ID DEFINITIONS================================================*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID      (uint8)10      /*  Invalid channel name requested  */
#define DIO_E_PARAM_INVALID_PORT_ID         (uint8)20      /*  Invalid port name requested     */
#define DIO_E_PARAM_INVALID_GROUP_ID        (uint8)31      /*  Invalid ChannelGroup id passed  */


/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_ReadChannel
    Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
    Service ID[hex] : 0x00
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters          (in)    :    ChannelId   ID of DIO channel
                        (inout) :   None
                        (out)   :   None
    Return value    : Dio_LevelType
                        STD_HIGH The physical level of the corresponding Pin is STD_HIGH
                        STD_LOW The physical level of the corresponding Pin is STD_LOW"
    Description     : Returns the value of the specified DIO channel.

------------------------------------------------------------------------------------------------------------------------*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_WriteChannel
    Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
    Service ID[hex] : 0x01
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    : ChannelId ID of DIO channel Level Level
                    (inout) : None
                    (out)   : None
    Return value    : None
    Description     : Service to set a level of a channel.
------------------------------------------------------------------------------------------------------------------------*/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_ReadPort
    Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
    Service ID[hex] : 0x02
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    : PortId ID of DIO Port
                    (inout) :None
                    (out)   : None
    Return value    : Dio_PortLevelType Level of all channels of that port
    Description     : Returns the level of all channels of that port.
------------------------------------------------------------------------------------------------------------------------*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_WritePort
    Syntax          : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
    Service ID[hex] : 0x03
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    : PortId ID of DIO Port Level Value to be written
                    (inout) :None
                    (out)   : None
    Return value    : None
    Description     : Service to set a value of the port.
------------------------------------------------------------------------------------------------------------------------*/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);


/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_ReadChannelGroup
    Syntax          : Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
    Service ID[hex] : 0x04
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    : ChannelGroupIdPtr Pointer to ChannelGroup
                    (inout) :None
                    (out)   : None
    Return value    : Dio_PortLevelType Dio_PortLevelType
    Description     : This Service reads a subset of the adjoining bits of a port.
------------------------------------------------------------------------------------------------------------------------*/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_WriteChannelGroup
    Syntax          : void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
    Service ID[hex] : 0x05
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    : ChannelGroupIdPtr Pointer to ChannelGroup Level Value to be written
                    (inout) :None
                    (out)   : None
    Return value    : None
    Description     : Service to set a subset of the adjoining bits of a port to a specified level.
------------------------------------------------------------------------------------------------------------------------*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

#if (DIO_VERSION_INFO_API == TRUE)
/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_GetVersionInfo
    Syntax          : void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
    Service ID[hex] : 0x12
    Sync/Async      : Synchronous
    Reentrancy      : Non Reentrant
    Parameters      (in)    : None
                    (inout) :None
                    (out)   : VersionInfo Pointer to where to store the version information of this module.
    Return value    : None
    Description     : Service to get the version information of this module.
-----------------------------------------------------------------------*/
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif


#if (DIO_MASKED_WRITE_PORT_API == TRUE)
/*----------------------------------------------------------------------------------------------------------------------
    Service name    : Dio_MaskedWritePort
    Syntax          : void Dio_MaskedWritePort(Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask);
    Service ID[hex] : 0x13
    Sync/Async      : Synchronous
    Reentrancy      : Reentrant
    Parameters      (in)    :PortId ID of DIO Port Level Value to be written Mask Channels to be masked in the port
                    (inout) :None
                    (out)   : None
    Return value    : None
    Description     : Service to set the value of a given port with required mask.
------------------------------------------------------------------------------------------------------------------------*/
void Dio_MaskedWritePort(Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask);
#endif

#endif /* DIO_DRIVER_STATIC_CODE_H_ */
