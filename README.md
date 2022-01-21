# AVR-Atmega32-Drivers
**This repository includes C drivers for AVR Atmega32 microcontroller peripherals and modules arranged in a layered Architecture.**


## Components on the Shelf (COTS)

#### 1- Microcontroller Abstraction Layer (MCAL)
```
1. Digital Input Output           (DIO)
2. Global Interrupt Enable        (GIE)
3. External Interrupt             (EXTI)
4. Timers                         (TMR)
5. Universal Synch/Asynch Tx/Rx   (USART)
6. Serial Peripheral Interface    (SPI)
```

#### 2- Hardware Abstraction Layer (HAL)
```
1. Light Emitting Diode     (LED)
2. Switch                   (SW)
3. 7 Segments Display       (SSD)
4. Liquid Crystal Display   (LCD)
5. Dual DC Motor H-Bridge   (HBridge)
6. Servomotor Driver        (Servo)
```

#### 3- Services Layer         (SERVICES)
```
1. Delay using 8-Bit Timers       (TMR_DELAY)
2. PWM Generation using Timers    (TMR_PWM)
3. Input Capture using Timers     (TMR_ICU)
4. Input Capture using EXTIs      (IC_EXTI)
```

#### 4- Application Layer  (APP)
```
1. DIO_main.c
2. EXTI_main.c
3. ICU_TMR1_main.c
4. IC_EXTI_main.c
5. LED_main.c
6. Servo_main.c
7. USART
    7.1. USART_Tx_main.c
    7.2. USART_Rx_main.c
8. SPI
    8.1. SPI_Tx_main.c
    8.2. SPI_Rx_main.c
```

#### 5- Libraries  (LIB)
1. `Bit_Math.h`   : includes macro definitions for bit manipulation.
2. `Std_Types.h`  : includes macro definitions for standard data types.
