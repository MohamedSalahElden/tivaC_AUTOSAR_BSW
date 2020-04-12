/*************************************************************************************
 * project discription :    this project blink the on board led mounted in PORTF
 * mohamed salah
 * ***********************************************************************************/

#include "tm4c123gh6pm.h"
#include "DIO_driver/static_code/Dio_Registers.h"
#include "DIO_driver/static_code/Dio.h"
void LED_init(void)
{

    SYSCTL_RCGCGPIO_R   |= (1<<5);      /* enable clock for port f */

    GPIOF.DIR.pins.pin1 = 1;
    GPIOF.DIR.pins.pin2 = 1;
    GPIOF.DIR.pins.pin3 = 1;

    GPIOF.DEN.pins.pin1 = 1;
    GPIOF.DEN.pins.pin2 = 1;
    GPIOF.DEN.pins.pin3 = 1;

}

void SW1_init(void)
{

    SYSCTL_RCGCGPIO_R   |= (1<<5);      /* enable clock for port f */
    //    GPIO_PORTF_DIR_R    &= ~(1<<4);      /* set SW2 pin direction to output */
    //    GPIO_PORTF_DEN_R    |= (1<<4);      /* set pin mode to digital pin */
    //    GPIO_PORTF_PUR_R    |= (1<<4);

    GPIOF.DIR.all    &= ~(1<<4);      /* set SW2 pin direction to output */
    GPIOF.DEN.all    |= (1<<4);      /* set pin mode to digital pin */
    GPIOF.PUR.all    |= (1<<4);


}

void SW2_init(void)
{

    SYSCTL_RCGCGPIO_R   |= (1<<5);      /* enable clock for port f */
    //    GPIO_PORTF_DIR_R    &= ~(1<<4);      /* set SW2 pin direction to output */
    //    GPIO_PORTF_DEN_R    |= (1<<4);      /* set pin mode to digital pin */
    //    GPIO_PORTF_PUR_R    |= (1<<4);

    GPIOF.DIR.all    &= ~(1<<0);      /* set SW2 pin direction to output */
    GPIOF.DEN.all    |= (1<<0);      /* set pin mode to digital pin */
    GPIOF.PUR.all    |= (1<<0);


}


void delay_ms(volatile double time)
{
    time = time * 81;
    while(time > 0)
    {
        time--;
    }
}



void main(void)
{
    LED_init();
    SW1_init();
    SW2_init();
    Dio_PortLevelType value ;
    while(1)
    {
//        value = Dio_ReadChannelGroup(rgb);
//        value ++ ;
//        Dio_WriteChannelGroup(rgb, value);
//        delay_ms(1000);

        //        Dio_WriteChannel(red_led, STD_HIGH);
        if(Dio_ReadChannel(left_button)){
            Dio_WriteChannel(green_led, STD_HIGH);
        }
        else{
            Dio_WriteChannel(green_led, STD_LOW);
        }
        if(Dio_ReadChannel(right_button)){
            Dio_WriteChannel(blue_led, STD_HIGH);
        }
        else{
            Dio_WriteChannel(blue_led, STD_LOW);
        }
    }
}
