 /*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio_cfg.h
 * Description  : pre compile time header file configurations for DIO Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/


#ifndef DIO_DRIVER_CONFIGURATION_CFG_H_
#define DIO_DRIVER_CONFIGURATION_CFG_H_

/*=======================================file version definitions================================================*/
#define DIO_CFG_AR_MAJOR_VERSION    3U      /*autosar version definitions*/
#define DIO_CFG_AR_MINOR_VERSION    2U
#define DIO_CFG_AR_PATCH_VERSION    3U

#define DIO_CFG_SW_MAJOR_VERSION    1U      /*software version definitions*/
#define DIO_CFG_SW_MINOR_VERSION    0U
#define DIO_CFG_SW_BATCH_VERSION    0U

/*-----------------------------------------pre compile configurations---------------------------------------------*/
#define     DIO_DEV_ERROR_DETECT            FALSE
#define     DIO_MASKED_WRITE_PORT_API       FALSE
#define     DIO_VERSION_INFO_API            FALSE


/*-----------------------------------------link time symbolic names configurations---------------------------------------------*/
#define NUM_OF_PORTS        (2U)
#define NUM_OF_CHANNELS     (5U)
#define NUM_OF_GROUPS       (2U)


/*LCD_port*/
#define LCD_PORT         (0U)    /*user defined name*/

/*joystick port*/
#define joystick_PORT            (1U)    /*port ID*/

/*led channel */
#define red_led                 (0U)    /*PORTF*/
#define red_led_PORT_ID         (5U)
#define red_led_CHANNEL_ID      (1U)

/*led channel */
#define blue_led                 (1U)    /*PORTF*/
#define blue_led_PORT_ID         (5U)
#define blue_led_CHANNEL_ID      (2U)


/*led channel */
#define green_led                 (2U)    /*PORTF*/
#define green_led_PORT_ID         (5U)
#define green_led_CHANNEL_ID      (3U)


/*button channel*/
#define right_button                 (3U) /*channel id*/
#define right_button_PORT_ID         (5U)
#define right_button_CHANNEL_ID      (0U)


/*button channel*/
#define left_button                 (4U) /*channel id*/
#define left_button_PORT_ID         (5U)
#define left_button_CHANNEL_ID      (4U)

/*rgb group*/
#define rgb                   (&(Dio_configuration.group[0]))  /*group id*/
#define RGB_PORT_ID           (5U)
#define RGB_GROUP_MASK        (0x0E)
#define RGB_GROUP_OFFSET      (1U)

/*stepper group*/
#define stepper                   (&(Dio_configuration.group[1]))   /*group id*/
#define STEPPER_PORT_ID           (3U)
#define STEPPER_GROUP_MASK        (4U)
#define STEPPER_GROUP_OFFSET      (0U)














#endif /* DIO_DRIVER_CONFIGURATION_CFG_H_ */
