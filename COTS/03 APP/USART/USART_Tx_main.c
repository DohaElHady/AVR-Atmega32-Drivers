
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "USART_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	USART_voidInit();
    while (1) 
    {
		if(DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			USART_voidSendu8Data('H');
		}
		else if(DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			USART_voidSendu8Data('L');
		}
    }
}

