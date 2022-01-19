# AVR-Atmega32-Drivers
**This repository includes C drivers for AVR Atmega32 microcontroller peripherals and modules arranged in a layered Architecture.**


## Components on the Shelf (COTS)

#### 1- Microcontroller Abstraction Layer (MCAL)
```
1. Digital Input Output           (DIO)
2. Global Interrupt Enable        (GIE)
3. External Interrupt             (EXTI)
4. Timers                         (TMR)
5. Delay using 8-Bit Timers       (TMR_DELAY)
6. PWM Generation using Timers    (TMR_PWM)
7. Input Capture using Timers     (TMR_ICU)
8. Input Capture using EXTIs      (IC_EXTI)
9. Universal Synch/Asynch Tx/Rx   (USART)
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

#### 3- Application Layer  (APP)

#### 4- Libraries  (LIB)
1. `Bit_Math.h`   : includes macro definitions for bit manipulation.
2. `Std_Types.h`  : includes macro definitions for standard data types.
