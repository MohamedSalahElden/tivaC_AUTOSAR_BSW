/*-------------------------------------------------------------------------------
 * Module       : DIO
 * File Name    : Dio_registers.h
 * Description  : registers definitions file for DIO Module in TM4C123G target MCU.
 * Author       : Mohamed salah-el-den hussien
 * AR version   : V3.2.3
 * SW version   : V1.0.0
 -------------------------------------------------------------------------------*/



#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#include "..\..\AS_platform\Std_Types.h"

#define _RW
#define _R const     /*definition of read only register*/
typedef struct{
    uint32 pin0 : 4;
    uint32 pin1 : 4;
    uint32 pin2 : 4;
    uint32 pin3 : 4;
    uint32 pin4 : 4;
    uint32 pin5 : 4;
    uint32 pin6 : 4;
    uint32 pin7 : 4;
}GPIOPCTL_type;

typedef union{
    uint32 all;
    struct{
        uint32 pin0 : 1 ;
        uint32 pin1 : 1 ;
        uint32 pin2 : 1 ;
        uint32 pin3 : 1 ;
        uint32 pin4 : 1 ;
        uint32 pin5 : 1 ;
        uint32 pin6 : 1 ;
        uint32 pin7 : 1 ;
    }pins;
}_8pins_type;

typedef struct{
    _RW     _8pins_type     MASK[256]        ;
//  _RW     _8pins_type     DATA              ;             /* Data                                 page    662         */
    _RW     _8pins_type     DIR               ;             /*GPIO Direction                        page    663         */
    _RW     _8pins_type     IS                ;             /*GPIO Interrupt Sense                  page    664         */
    _RW     _8pins_type     IBE               ;             /*GPIO Interrupt Both Edges             page    665         */
    _RW     _8pins_type     IEV               ;             /*GPIO Interrupt Event                  page    666         */
    _RW     _8pins_type     IM                ;             /*GPIO Interrupt Mask                   page    667         */
    _R      _8pins_type     RIS               ;             /*GPIO Raw Interrupt Status             page    668         */
    _R      _8pins_type     MIS               ;             /*GPIO Masked Interrupt Status          page    669         */
    _RW     _8pins_type     ICR               ;             /*GPIO Interrupt Clear                  page    670         */
    _RW     _8pins_type     AFSEL             ;             /*GPIO Alternate Function Select        page    671         */
    _R      _8pins_type     blankarea1[55]    ;
    _RW     _8pins_type     DR2R              ;             /*GPIO 2-mA Drive Select                page    673         */
    _RW     _8pins_type     DR4R              ;             /*GPIO 4-mA Drive Select                page    674         */
    _RW     _8pins_type     DR8R              ;             /*GPIO 8-mA Drive Select                page    675         */
    _RW     _8pins_type     ODR               ;             /*GPIO Open Drain Select                page    676         */
    _RW     _8pins_type     PUR               ;             /*GPIO Pull-Up Select                   page    677         */
    _RW     _8pins_type     PDR               ;             /*GPIO Pull-Down Select                 page    679         */
    _RW     _8pins_type     SLR               ;             /*GPIO Slew Rate Control Select         page    681         */
    _RW     _8pins_type     DEN               ;             /*GPIO Digital Enable                   page    682         */
    _RW     _8pins_type     LOCK              ;             /*GPIO Lock                             page    684         */
    _RW     _8pins_type     CR                ;             /*GPIO Commit                           page    685         */
    _RW     _8pins_type     AMSEL             ;             /*GPIO Analog Mode Select               page    687         */
    _RW      GPIOPCTL_type  PCTL              ;             /*GPIO Port Control                     page    688         */
    _RW     _8pins_type     ADCCTL            ;             /*GPIO ADC Control                      page    690         */
    _RW     _8pins_type     DMACTL            ;             /*GPIO DMA Control                      page    691         */
    _R       uint32         blankarea2[678]   ;
    _R      _8pins_type     PeriphID4         ;             /*GPIO Peripheral Identification 4      page   692          */
    _R      _8pins_type     PeriphID5         ;             /*GPIO Peripheral Identification 5      page   693          */
    _R      _8pins_type     PeriphID6         ;             /*GPIO Peripheral Identification 6      page   694          */
    _R      _8pins_type     PeriphID7         ;             /*GPIO Peripheral Identification 7      page   695          */
    _R      _8pins_type     PeriphID0         ;             /*GPIO Peripheral Identification 0      page   696          */
    _R      _8pins_type     PeriphID1         ;             /*GPIO Peripheral Identification 1      page   697          */
    _R      _8pins_type     PeriphID2         ;             /*GPIO Peripheral Identification 2      page   698          */
    _R      _8pins_type     PeriphID3         ;             /*GPIO Peripheral Identification 3      page   699          */
    _R      _8pins_type     PCellID0          ;             /*GPIO PrimeCell Identification 0       page   700          */
    _R      _8pins_type     PCellID1          ;             /*GPIO PrimeCell Identification 1       page   701          */
    _R      _8pins_type     PCellID2          ;             /*GPIO PrimeCell Identification 2       page   702          */
    _R      _8pins_type     PCellID3          ;             /*GPIO PrimeCell Identification 3       page   703          */
}GPIOPort_Type                                ;

typedef struct{
    GPIOPort_Type port[4];  /*ports A,B,C,D*/
}GPIO_1_type;

typedef struct{
    GPIOPort_Type port[2];  /*E,F*/
}GPIO_2_type;

#define GPIO_AD     (*((GPIO_1_type *)0x40004000))
#define GPIO_EF     (*((GPIO_2_type *)0x40024000))

#define DATA        MASK[255]

#define PORT_A_ID           (0U)
#define PORT_B_ID           (1U)
#define PORT_C_ID           (2U)
#define PORT_D_ID           (3U)
#define PORT_E_ID           (4U)
#define PORT_F_ID           (5U)


#define GPIOA       GPIO_AD.port[0]
#define GPIOB       GPIO_AD.port[1]
#define GPIOC       GPIO_AD.port[2]
#define GPIOD       GPIO_AD.port[3]
#define GPIOE       GPIO_EF.port[0]
#define GPIOF       GPIO_EF.port[1]

#endif /* DIO_REGISTERS_H_ */
