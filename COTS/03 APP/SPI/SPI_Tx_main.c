

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

#define			SLAVESELECT1_PORT		PORTA
#define			SLAVESELECT1_PIN		PIN2

int main(void)
{
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	DIO_voidSetPinDirection(SLAVESELECT1_PORT,SLAVESELECT1_PIN,OUTPUT);
	DIO_voidSetPinValue(SLAVESELECT1_PORT,SLAVESELECT1_PIN,HIGH);

	DIO_voidSetPinDirection(PORTA,PIN3,OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN3,LOW);

	SPI_voidInit();
	SPI_voidEnable();
	while (1)
	{
		if(DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			DIO_voidSetPinValue(SLAVESELECT1_PORT,SLAVESELECT1_PIN,LOW);
			SPI_voidSendu8Data('H');
			DIO_voidSetPinValue(SLAVESELECT1_PORT,SLAVESELECT1_PIN,HIGH);
		}
		else if(DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			DIO_voidSetPinValue(SLAVESELECT1_PORT,SLAVESELECT1_PIN,LOW);
			SPI_voidSendu8Data('L');
			DIO_voidSetPinValue(SLAVESELECT1_PORT,SLAVESELECT1_PIN,HIGH);
		}
	}
}
