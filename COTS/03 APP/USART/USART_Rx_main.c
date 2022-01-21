
#define F_CPU			16000000UL
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "USART_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	USART_voidInit();
    while (1) 
    {
		if(USART_u8RecieveData()=='H')
		{
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		}
		else if (USART_u8RecieveData()=='L')
		{
			DIO_voidSetPinValue(PORTA,PIN0,LOW);
		}
    }
}

