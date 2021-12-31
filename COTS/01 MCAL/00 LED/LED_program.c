#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"LED_interface.h"
#include		"LED_private.h"

/*
LED_voidLedInit(LED0); (LED0_PIN) = OUTPUT;
*/
void		LED_voidLedInit(u8 LedID )
{
	if(LedID < 3 )
	{
		switch(LedID)
		{
			case LED0 :	DIO_voidSetPinDirection(LED0_PORT , LED0_PIN , OUTPUT );	break;
			case LED1 :	DIO_voidSetPinDirection(LED1_PORT , LED1_PIN , OUTPUT );	break;
			case LED2 :	DIO_voidSetPinDirection(LED2_PORT , LED2_PIN , OUTPUT );	break;
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
LED_voidSetLedValue(LED0,HIGH); (LED0) = High;
*/
void		LED_voidSetLedValue(u8 LedID ,u8 Value )
{
	/*		Range Check									*/
	if(LedID < 3 )
	{
		if(Value == HIGH)
		{
			switch(LedID)
			{
				case LED0 :	DIO_voidSetPinValue(LED0_PORT , LED0_PIN , HIGH );	break;
				case LED1 :	DIO_voidSetPinValue(LED1_PORT , LED1_PIN , HIGH );	break;
				case LED2 :	DIO_voidSetPinValue(LED2_PORT , LED2_PIN , HIGH );	break;
			}
		}else if(Value == LOW)
		{
			switch(LedID)
			{
				case LED0 :	DIO_voidSetPinValue(LED0_PORT , LED0_PIN , LOW );	break;
				case LED1 :	DIO_voidSetPinValue(LED1_PORT , LED1_PIN , LOW );	break;
				case LED2 :	DIO_voidSetPinValue(LED2_PORT , LED2_PIN , LOW );	break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}
