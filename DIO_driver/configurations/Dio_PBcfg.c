/*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio_PBcfg.c
 * Description  : post build source file for DIO Module.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/
#include "../static_code/Dio_types.h"
#include "Dio_PBCfg.h"


Dio_configurationType Dio_configuration = {
                                           {
                                            {red_led_PORT_ID , red_led_CHANNEL_ID},
                                            {blue_led_PORT_ID , blue_led_CHANNEL_ID},
                                            {green_led_PORT_ID , green_led_CHANNEL_ID},
                                            {right_button_PORT_ID , right_button_CHANNEL_ID},
                                            {left_button_PORT_ID , left_button_CHANNEL_ID}
                                           },
                                           {
                                            {RGB_GROUP_MASK , RGB_GROUP_OFFSET , RGB_PORT_ID},
                                            {STEPPER_GROUP_MASK , STEPPER_GROUP_OFFSET , STEPPER_PORT_ID}

                                           },
};
