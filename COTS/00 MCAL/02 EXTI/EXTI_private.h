#ifndef		EXTI_PRIVATE_H
#define		EXTI_PRIVATE_H

#define			MCUCR_REG		   	*((volatile u8 *)0x55)
#define			MCUCSR_REG			*((volatile u8 *)0x54)
#define			GICR_REG			  *((volatile u8 *)0x5B)
#define			GIFR_REG			  *((volatile u8 *)0x5A)


/*      EXTI modes      */
#define		EXTI_LOW_LEVEL               0
#define		EXTI_FALLING_RISING          1
#define		EXTI_FALLING_EDGE            2
#define		EXTI_RISING_EDGE             3



/******************************************************************************/
/***************************   EXTI0  *****************************************/
#define     EXTI0_GICR_BIT             6
#define     EXTI0_GIFR_BIT             6

#define     EXTI0_MCUCR_BIT0           0
#define     EXTI0_MCUCR_BIT1           1

/******************************************************************************/
/***************************   EXTI1  *****************************************/
#define     EXTI1_GICR_BIT             7
#define     EXTI1_GIFR_BIT             7

#define     EXTI1_MCUCR_BIT0           2
#define     EXTI1_MCUCR_BIT1           3

/******************************************************************************/
/***************************   EXTI2  *****************************************/

#define     EXTI2_GICR_BIT             5
#define     EXTI2_GIFR_BIT             5
#define     EXTI2_MCUCSR_BIT		   6

#endif
