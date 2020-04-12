 /*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio_PBcfg.h
 * Description  : post build header file for DIO Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/




#ifndef DIO_PBCFG_H_
#define DIO_PBCFG_H_

/*=======================================file version definitions================================================*/
#include "../static_code/Dio_types.h"
#define DIO_PBCFG_AR_MAJOR_VERSION    3U
#define DIO_PBCFG_AR_MINOR_VERSION    2U
#define DIO_PBCFG_AR_PATCH_VERSION    3U

#define DIO_PBCFG_SW_MAJOR_VERSION    1U
#define DIO_PBCFG_SW_MINOR_VERSION    0U
#define DIO_PBCFG_SW_BATCH_VERSION    0U

typedef struct {
    Dio_channelConfig       channel[NUM_OF_CHANNELS];
    Dio_ChannelGroupType    group[NUM_OF_GROUPS] ;
}Dio_configurationType;

extern Dio_configurationType Dio_configuration;

#endif /* DIO_PBCFG_H_ */
