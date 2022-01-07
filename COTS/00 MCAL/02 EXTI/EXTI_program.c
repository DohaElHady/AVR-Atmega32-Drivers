#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"EXTI_interface.h"
#include		"EXTI_private.h"
#include 		"EXTI_config.h"

#ifndef			NULL
#define			NULL			(void*)0
#endif

static void (*EXTI0_ISR_CallBack) (void)=NULL;
static void (*EXTI1_ISR_CallBack) (void)=NULL;
static void (*EXTI2_ISR_CallBack) (void)=NULL;

/******************************************************************************/
/***************************   EXTI0  *****************************************/

void    EXTI0_voidInit(void)
{
	/*		1-	Set Interrupt Sense Mode */
	#if 			EXTI0_SENSE_MODE == EXTI_LOW_LEVEL
		CLR_BIT(MCUCR_REG,EXTI0_MCUCR_BIT0);
		CLR_BIT(MCUCR_REG,EXTI0_MCUCR_BIT1);
	#elif			EXTI0_SENSE_MODE == EXTI_FALLING_RISING
		SET_BIT(MCUCR_REG,EXTI0_MCUCR_BIT0);
		CLR_BIT(MCUCR_REG,EXTI0_MCUCR_BIT1);
	#elif			EXTI0_SENSE_MODE == EXTI_FALLING_EDGE
		CLR_BIT(MCUCR_REG,EXTI0_MCUCR_BIT0);
		SET_BIT(MCUCR_REG,EXTI0_MCUCR_BIT1);
	#elif			EXTI0_SENSE_MODE == EXTI_RISING_EDGE
		SET_BIT(MCUCR_REG,EXTI0_MCUCR_BIT0);
		SET_BIT(MCUCR_REG,EXTI0_MCUCR_BIT1);
	#endif

	/*		2-	Disable Any Interrupt		 */
	CLR_BIT(GICR_REG,EXTI0_GICR_BIT);
	/*		3-	Clear Interrupt Flag		 */
	CLR_BIT(GIFR_REG,EXTI0_GIFR_BIT);
}


void		EXTI0_voidEnable(void)
{
	SET_BIT(GICR_REG,EXTI0_GICR_BIT);
}


void		EXTI0_voidDisable(void)
{
	CLR_BIT(GICR_REG,EXTI0_GICR_BIT);
}


void    EXTI0_voidSetISRFunc(void (*PointertoFunc) (void))
{
	EXTI0_ISR_CallBack=PointertoFunc;
}


void    __vector_1(void)
{
	EXTI0_ISR_CallBack();
}


/******************************************************************************/
/***************************   EXTI1  *****************************************/

void    EXTI1_voidInit(void)
{
	/*		1-	Set Interrupt Sense Mode */
	#if 			EXTI1_SENSE_MODE == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_REG,EXTI1_MCUCR_BIT0);
	CLR_BIT(MCUCR_REG,EXTI1_MCUCR_BIT1);
	#elif			EXTI1_SENSE_MODE == EXTI_FALLING_RISING
	SET_BIT(MCUCR_REG,EXTI1_MCUCR_BIT0);
	CLR_BIT(MCUCR_REG,EXTI1_MCUCR_BIT1);
	#elif			EXTI1_SENSE_MODE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR_REG,EXTI1_MCUCR_BIT0);
	SET_BIT(MCUCR_REG,EXTI1_MCUCR_BIT1);
	#elif			EXTI1_SENSE_MODE == EXTI_RISING_EDGE
	SET_BIT(MCUCR_REG,EXTI1_MCUCR_BIT0);
	SET_BIT(MCUCR_REG,EXTI1_MCUCR_BIT1);
	#endif

	/*		2-	Disable Any Interrupt		 */
	CLR_BIT(GICR_REG,EXTI1_GICR_BIT);
	/*		3-	Clear Interrupt Flag		 */
	CLR_BIT(GIFR_REG,EXTI1_GIFR_BIT);
}


void		EXTI1_voidEnable(void)
{
	SET_BIT(GICR_REG,EXTI1_GICR_BIT);
}


void		EXTI1_voidDisable(void)
{
	CLR_BIT(GICR_REG,EXTI1_GICR_BIT);
}


void    EXTI1_voidSetISRFunc(void (*PointertoFunc) (void))
{
	EXTI1_ISR_CallBack=PointertoFunc;
}


void    __vector_2(void)
{
	EXTI1_ISR_CallBack();
}


/******************************************************************************/
/***************************   EXTI2  *****************************************/

void    EXTI2_voidInit(void)
{
	/*		1-	Set Interrupt Sense Mode */
	#if 			EXTI2_SENSE_MODE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR_REG,EXTI2_MCUCSR_BIT);
	#elif			EXTI1_SENSE_MODE == EXTI_RISING_EDGE
	SET_BIT(MCUCSR_REG,EXTI2_MCUCSR_BIT);
	#endif

	/*		2-	Disable Any Interrupt		 */
	CLR_BIT(GICR_REG,EXTI2_GICR_BIT);
	/*		3-	Clear Interrupt Flag		 */
	CLR_BIT(GIFR_REG,EXTI2_GIFR_BIT);
}


void		EXTI2_voidEnable(void)
{

	SET_BIT(GICR_REG,EXTI2_GICR_BIT);
}


void		EXTI2_voidDisable(void)
{
	CLR_BIT(GICR_REG,EXTI2_GICR_BIT);
}


void    EXTI2_voidSetISRFunc(void (*PointertoFunc) (void))
{
	EXTI2_ISR_CallBack=PointertoFunc;
}


void    __vector_3(void)
{
	EXTI2_ISR_CallBack();
}

