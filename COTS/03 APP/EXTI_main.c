#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"GIE_interface.h"
#include		"EXTI_interface.h"

#include		<util/delay.h>

void EXTI0_ISR(void)
{
	GIE_voidEnable();
	DIO_voidSetPinValue(PORTC,PIN0,HIGH);
	_delay_ms(200);
	DIO_voidSetPinValue(PORTC,PIN0,LOW);
}

void EXTI1_ISR(void)
{
	GIE_voidEnable();
	DIO_voidSetPinValue(PORTC,PIN1,HIGH);
	_delay_ms(200);
	DIO_voidSetPinValue(PORTC,PIN1,LOW);
}

void EXTI2_ISR(void)
{
	GIE_voidEnable();
	DIO_voidSetPinValue(PORTC,PIN2,HIGH);
	_delay_ms(200);
	DIO_voidSetPinValue(PORTC,PIN2,LOW);
}

int main (void)
{
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	EXTI0_voidSetISRFunc(EXTI0_ISR);
	EXTI1_voidSetISRFunc(EXTI1_ISR);
	EXTI2_voidSetISRFunc(EXTI2_ISR);
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	DIO_voidSetPinDirection(PORTD,PIN3,INPUT);
	DIO_voidSetPinValue(PORTD,PIN3,HIGH);
	DIO_voidSetPinDirection(PORTB,PIN2,INPUT);
	DIO_voidSetPinValue(PORTB,PIN2,HIGH);
	EXTI0_voidInit();
	EXTI1_voidInit();
	EXTI2_voidInit();
	GIE_voidEnable();
	EXTI0_voidEnable();
	EXTI1_voidEnable();
	EXTI2_voidEnable();
	while(1)
	{
	}
	return 0;
}
