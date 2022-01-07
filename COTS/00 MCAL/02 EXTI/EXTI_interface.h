#ifndef		EXTI_INTERFACE_H
#define	  EXTI_INTERFACE_H

/******************************************************************************/
/***************************   EXTI0  *****************************************/
void    EXTI0_voidInit(void);
void	EXTI0_voidEnable(void);
void	EXTI0_voidDisable(void);
void    EXTI0_voidSetISRFunc(void (*PointertoFunc) (void));
void    __vector_1(void)    __attribute__((signal,used));

/******************************************************************************/
/***************************   EXTI1  *****************************************/

void    EXTI1_voidInit(void);
void	EXTI1_voidEnable(void);
void	EXTI1_voidDisable(void);
void    EXTI1_voidSetISRFunc(void (*PointertoFunc) (void));
void    __vector_2(void)    __attribute__((signal,used));
/******************************************************************************/
/***************************   EXTI2  *****************************************/

void    EXTI2_voidInit(void);
void	EXTI2_voidEnable(void);
void	EXTI2_voidDisable(void);
void    EXTI2_voidSetISRFunc(void (*PointertoFunc) (void));
void    __vector_3(void)    __attribute__((signal,used));

#endif
