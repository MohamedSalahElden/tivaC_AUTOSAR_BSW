# DIO 3.2.3 AUTOSAR driver implementation

- DIO is Digital Input Output
- this driver responsible for read from and write to Digital channels
- the operations in DIO driver can be done on 
  1. channel (single DIO pin TM4C123G has 43 individual GPIO pin)
  2. port (PORT in TM4C123G are A,B,C,D,E,F)
  3. group  (a group is a group of adjacent pins in the same PORT)
- the pin is configured by the PORT driver (setting it's direction , pull up/down resistors , alternative functionality of the channel) and the  only job of DIO driver is to read and write digital values to that pre configured pin 
- the DIO driver allows to just write to the configured pins only , any attempt to read or wite other channels will produce error (development error to DET module)

## DIO file structure and inclusion hirhalichy
- DIO driver can divide into two basic sections (folders) 
  - **static code** 
    > this includes the source and header files that kept un changeable by the user

  - **configuration code** 
    > this includes the source and header files used to configure the DIO module according to the application , these files are auto-generated 
<div align = "center">

```me rmaid
graph TD;
    Det.h-->Dio.c;
    Dio_cfg.h-->Dio.h;
    Dio.h-->Dio.c;
    Std_Types.h-->Dio.h;
    compiler.h-->Std_Types.h;
    Platform_Types.h-->Std_Types.h;
    Dio_PBCfg.h-->Dio.h;
    Dio_types.h-->Dio_PBCfg.c;
    Dio_types.h-->Dio.h;
    Std_Types.h-->Dio_types.h;
```
</div>

## Configuration specification


## DIO AUTOSAR define new words to use within code
- Dio (module)
  - DioGeneral --> (container)(1)
    - DIO_DEV_ERROR_DETECT(PC , bool)
    - DIO_MASKED_WRITE_PORT_API(PC , bool)
    - DIO_VERSION_INFO_API(PC , bool)
  - DioPort ------> (container)(1..*)
    - **DIO_PORT_ID(int , symbolic , PC/LT)**
    - **DioChannel(container)(0..*)**
      - DIO_CHANNEL_ID(int , symbolic , PC/LT)
    - **DioChannelGroup(container)(0..*)**
      - DIO_CHANNEL_GROUP_IDENTIFIKATION(PC , symbolic)
      - DioPortMask(int , PC/LT)
      - DioPortOffset(int , PC/LT)



