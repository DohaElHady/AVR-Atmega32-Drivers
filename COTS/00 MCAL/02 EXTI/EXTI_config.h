#ifndef		EXTI_CONFIG_H
#define		EXTI_CONFIG_H

/*
EXTI0 Interrupt Sense Mode can be:
                1-  EXTI_LOW_LEVEL
                2-  EXTI_FALLING_RISING
                3-  EXTI_FALLING_EDGE
                4-  EXTI_RISING_EDGE
*/

#define    EXTI0_SENSE_MODE       EXTI_FALLING_EDGE

/*
EXTI1 Interrupt Sense Mode can be:
                1-  EXTI_LOW_LEVEL
                2-  EXTI_FALLING_RISING
                3-  EXTI_FALLING_EDGE
                4-  EXTI_RISING_EDGE
*/

#define    EXTI1_SENSE_MODE       EXTI_FALLING_EDGE

/*
EXTI1 Interrupt Sense Mode can be:
                1-  EXTI_FALLING_EDGE
                2-  EXTI_RISING_EDGE
*/

#define    EXTI2_SENSE_MODE       EXTI_FALLING_EDGE

#endif
