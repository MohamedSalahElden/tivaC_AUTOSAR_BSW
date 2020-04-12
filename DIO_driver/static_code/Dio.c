/*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio.c
 * Description  : source file for DIO Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/

#include "Dio.h"
#include "Dio_Registers.h"
#include "Common_Macros.h"
/*======================================Det module inclusion =====================*/
#include "../../Det_module/Det.h"   /*autosar version checking*/
#if((DIO_AR_MAJOR_VERSION != DET_AR_MAJOR_VERSION)    ||   \
        (DIO_AR_MINOR_VERSION != DET_AR_MINOR_VERSION)    ||   \
        (DIO_AR_PATCH_VERSION != DET_AR_PATCH_VERSION))
#error"AUTOSAR version mismatch between DIO module and DET.h"
#endif

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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(ChannelId >= NUM_OF_CHANNELS){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_READ_CHANNEL_API_ID,
                         DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
#endif
    Dio_LevelType   result;
    Dio_PortType    p   = Dio_configuration.channel[ChannelId].port;
    Dio_ChannelType ch  = Dio_configuration.channel[ChannelId].channel;

    if(p <= PORT_D_ID){
        result = GPIO_AD.port[p].DATA.all & (1<<ch);
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID;
        result = GPIO_EF.port[p].DATA.all & (1<<ch);
    }
    else{
        /*DET error*/
    }
    return result;
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(ChannelId >= NUM_OF_CHANNELS){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_WRITE_CHANNEL_API_ID,
                         DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
#endif
    Dio_PortType    p   = Dio_configuration.channel[ChannelId].port;
    Dio_ChannelType ch  = Dio_configuration.channel[ChannelId].channel;

    if(p <= PORT_D_ID){
        WRITE_BIT(GPIO_AD.port[p].DATA.all , ch , Level);
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID;
        WRITE_BIT(GPIO_EF.port[p].DATA.all , ch , Level);
    }
    else{
        /*DET error*/
    }
}

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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(PortId >= NUM_OF_PORTS){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_READ_PORT_API_ID,
                         DIO_E_PARAM_INVALID_PORT_ID);
    }
#endif
    Dio_PortLevelType  result;
    Dio_PortType    p   = PortId;   /*p 1~5*/

    if(p <= PORT_D_ID){
        result = GPIO_AD.port[p].DATA.all;
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID; /*mapping the port ID to the registers array index */
        result = GPIO_EF.port[p].DATA.all;
    }
    else{
        /*DET error*/
    }
    return result;
}


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
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(PortId >= NUM_OF_PORTS){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_WRITE_PORT_API_ID,
                         DIO_E_PARAM_INVALID_PORT_ID);
    }
#endif
    Dio_PortType    p   = PortId;   /*p 1~5*/

    if(p <= PORT_D_ID){
        GPIO_AD.port[p].DATA.all = Level;
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID; /*mapping the port ID to the registers array index */
        GPIO_EF.port[p].DATA.all = Level;
    }
    else{
        /*DET error*/
    }
}


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
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(ChannelGroupIdPtr->portID > PORT_F_ID){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_READ_CHANNEL_GROUP_API_ID,
                         DIO_E_PARAM_INVALID_PORT_ID);
    }
#endif
    Dio_PortLevelType   result;
    Dio_PortType    p       = ChannelGroupIdPtr->portID;
    uint8           msk     = ChannelGroupIdPtr->mask;
    uint8           ofst    = ChannelGroupIdPtr->offset;

    if(p <= PORT_D_ID){
        result = GPIO_AD.port[p].MASK[msk].all >> ofst;
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID;
        result = GPIO_EF.port[p].MASK[msk].all >> ofst;
    }
    else{
        /*DET error*/
    }
    return result;
}

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
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(ChannelGroupIdPtr->portID > PORT_F_ID){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_WRITE_CHANNEL_GROUP_API_ID,
                         DIO_E_PARAM_INVALID_PORT_ID);
    }
#endif
    Dio_PortType    p       = ChannelGroupIdPtr->portID;
    uint8           msk     = ChannelGroupIdPtr->mask;
    uint8           ofst    = ChannelGroupIdPtr->offset;

    if(p <= PORT_D_ID){
        GPIO_AD.port[p].MASK[msk].all  = (Level << ofst);
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID;
        GPIO_EF.port[p].MASK[msk].all = (Level << ofst);
    }
    else{
        /*DET error*/
    }
}


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
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo){
    VersionInfo->moduleID = MODULE_ID;
    VersionInfo->vendorID = VENDOR_ID;
    VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = DIO_SW_BATCH_VERSION;
}
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
void Dio_MaskedWritePort(Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask){
#if(DIO_DEV_ERROR_DETECT == TRUE)
    if(PortId > PORT_F_ID){
        Det_ReportError( MODULE_ID,
                         INSTANCE_ID,
                         DIO_MASKED_WRITE_PORT_API_ID,
                         DIO_E_PARAM_INVALID_PORT_ID);
    }
#endif
    Dio_PortType    p       = PortId;


    if(p <= PORT_D_ID){
        GPIO_AD.port[p].MASK[Mask].all  = Level;
    }
    else if((p >= PORT_E_ID) && (p <= PORT_F_ID)){
        p -= PORT_E_ID;
        GPIO_EF.port[p].MASK[Mask].all = Level;
    }
    else{
        /*DET error*/
    }
}
#endif
