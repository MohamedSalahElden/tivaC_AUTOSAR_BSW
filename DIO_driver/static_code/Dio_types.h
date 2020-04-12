/*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio_Types.h
 * Description  : autosar types file for DIO Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/



#ifndef DIO_TYPES_DRIVER_STATIC_CODE_H_
#define DIO_TYPES_DRIVER_STATIC_CODE_H_

/*=======================================file version definitions================================================*/
#define DIO_TYPES_AR_MAJOR_VERSION    (3U)
#define DIO_TYPES_AR_MINOR_VERSION    (2U)
#define DIO_TYPES_AR_PATCH_VERSION    (3U)

#define DIO_TYPES_SW_MAJOR_VERSION    (1U)
#define DIO_TYPES_SW_MINOR_VERSION    (0U)
#define DIO_TYPES_SW_BATCH_VERSION    (0U)

/*=======================================Std_types version definitions================================================*/
#include "../../AS_platform/Std_Types.h"
#if(DIO_TYPES_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION || \
        DIO_TYPES_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION || \
        DIO_TYPES_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION)
#error"AUTOSAR version mismatch between Dio_Types and Std_types"
#endif

#include "../configurations/Dio_Cfg.h"


/*=========================autosar type definitions================================================*/

/*----------------------------------------------------------------------
    Name        : Dio_ChannelType
    Type        : Unsigned Integer
    Range       : This is implementation specific
                  but not all values may be valid within the type.
                - Shall cover all available DIO channels
                  TM4C123G has 43 DIO channel
    Description : Numeric ID of a DIO channel.
                  user shall use the symbolic names provided
                  by the configuration
-----------------------------------------------------------------------*/
typedef uint8   Dio_ChannelType;

/*----------------------------------------------------------------------
    Name        : Dio_PortType
    Type        : Unsigned Integer
    Range       : 0..<number of ports>
                -- Shall cover all available DIO Ports.
    Description : Numeric ID of a DIO port.
                  TM4C123G has 6 PORTS A,B,C,D,E,F
-----------------------------------------------------------------------*/
typedef uint8   Dio_PortType;

/*----------------------------------------------------------------------
    Name        : Dio_ChannelGroupType
    Type        : Structure
    Element     :   uint8/16/32 mask
                            This element mask which defines the
                            positions of the channel group.
                    uint8 offset
                            This element shall be the position of the
                            Channel Group on the port, counted from the LSB.
                    Dio_PortType port
                             This shall be the port on which the
                             Channel group is defined.
    Description : Type for the definition of a channel group,
                  which consists of several adjoining channels within a port.
-----------------------------------------------------------------------*/
typedef struct {
    uint8 mask;
    uint8 offset;
    Dio_PortType portID;
}Dio_ChannelGroupType;

/*----------------------------------------------------------------------
    Name        : Dio_LevelType
    Type        : Unsigned Integer
    Range       :   STD_LOW -- --
                    STD_HIGH -- --
    Description : These are the possible levels a DIO channel can have
                  (input or output)
-----------------------------------------------------------------------*/
typedef uint8 Dio_LevelType;

/*----------------------------------------------------------------------
    Name        : Dio_PortLevelType
    Type        : Unsigned Integer
    Range       : 0...xxx
                    -- If the µC owns ports of different port widths
                    (e.g. 4,8,16...Bit) Dio_PortLevelType
                    inherits the size of the largest port
    Description : If the µC owns ports of different port widths
                    (e.g. 4, 8,16...Bit) Dio_PortLevelType
                    inherits the size of the largest port.
-----------------------------------------------------------------------*/
typedef uint8 Dio_PortLevelType;



/*=========================autosar configutartions type definitions================================================*/
typedef struct {
    Dio_PortType port;
    Dio_ChannelType channel;
}Dio_channelConfig;




#endif /* DIO_TYPES_DRIVER_STATIC_CODE_H_ */
