#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"

#include		"HBridge_interface.h"
#include		"HBridge_private.h"

#include		<util/delay.h>

void	HB_voidInit(u8 M1Mode, u8 M2Mode)
{
	
	if(M1Mode==ON)
	{
		DIO_voidSetPinDirection(HB_EN_PORT,HB_EN1,OUTPUT);
		DIO_voidSetPinDirection(HB_DIR_PORT,HB_A1,OUTPUT);
		DIO_voidSetPinDirection(HB_DIR_PORT,HB_A2,OUTPUT);
	}
	if(M2Mode==ON)
	{
		DIO_voidSetPinDirection(HB_EN_PORT,HB_EN2,OUTPUT);
		DIO_voidSetPinDirection(HB_DIR_PORT,HB_A3,OUTPUT);
		DIO_voidSetPinDirection(HB_DIR_PORT,HB_A4,OUTPUT);
	}
}

void	HB_voidMotorDir(u8 MotorNum, u8 Direction)
{
	if (Direction==RIGHT)
	{
		switch (MotorNum)
		{
			case 1: DIO_voidSetPinValue(HB_DIR_PORT,HB_A1,HIGH);
					DIO_voidSetPinValue(HB_DIR_PORT,HB_A2,LOW);
					break;
			case 2: DIO_voidSetPinValue(HB_DIR_PORT,HB_A3,HIGH);
					DIO_voidSetPinValue(HB_DIR_PORT,HB_A4,LOW);
					break;
		}
	}else if(Direction == LEFT)
	{
		switch (MotorNum)
		{
			case 1: DIO_voidSetPinValue(HB_DIR_PORT,HB_A1,LOW);
					DIO_voidSetPinValue(HB_DIR_PORT,HB_A2,HIGH);
					break;
			case 2: DIO_voidSetPinValue(HB_DIR_PORT,HB_A3,LOW);
					DIO_voidSetPinValue(HB_DIR_PORT,HB_A4,HIGH);
					break;
		}
	}
}

void	HB_voidMotorEn(u8 MotorNum, u8 MotorMode)
{
	if (MotorMode==ON)
	{
		switch (MotorNum)
		{
			case 1: DIO_voidSetPinValue(HB_EN_PORT,HB_EN1,HIGH);	break;
			case 2: DIO_voidSetPinValue(HB_EN_PORT,HB_EN2,HIGH);	break;
		}
	}else if(MotorMode == OFF)
	{
		switch (MotorNum)
		{
			case 1: DIO_voidSetPinValue(HB_EN_PORT,HB_EN1,LOW);		break;
			case 2: DIO_voidSetPinValue(HB_EN_PORT,HB_EN2,LOW);		break;
		}
	}
}