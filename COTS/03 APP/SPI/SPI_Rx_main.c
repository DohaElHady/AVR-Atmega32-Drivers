
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

int main(void)
{

	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	SPI_voidInit();
	SPI_voidEnable();

	while (1)
	{

		if(SPI_u8RecieveData()=='H')
		{
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		}
		else if (SPI_u8RecieveData()=='L')
		{
			DIO_voidSetPinValue(PORTA,PIN0,LOW);
		}
	}
}
