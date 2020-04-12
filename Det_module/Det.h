 /*-------------------------------------------------------------------------------
 * Module       : DET
 * File Name    : Det.h
 * Description  : header file for DET Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/

#ifndef DET_MODULE_DET_H_
#define DET_MODULE_DET_H_

/*=======================================file version definitions================================================*/
/*-----------------------------------------------------------------
 * software version definition (first release) V1.0.0
 * used to check compatibility between module files
 * ---------------------------------------------------------------*/
#define DET_SW_MAJOR_VERSION    (1U)
#define DET_SW_MINOR_VERSION    (0U)
#define DET_SW_BATCH_VERSION    (0U)

 /*---------------------------------------------------------------
 * autosar version used for this driver is 3.2.3
 * used for compatibility checking between different autosar module
 * ---------------------------------------------------------------*/
#define DET_AR_MAJOR_VERSION    (3U)
#define DET_AR_MINOR_VERSION    (2U)
#define DET_AR_PATCH_VERSION    (3U)


#include "../AS_platform/Std_Types.h"
#if(DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION ||   \
    DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION ||   \
    DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION)
#error"AUTOSAR version mismatch between DET and Std_types"
#endif



void Det_ReportError( uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId );
#endif /* DET_MODULE_DET_H_ */
