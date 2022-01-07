#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"SWITCH_interface.h"
#include		"SWITCH_private.h"

/*
SWITCH_voidLedInit(SW0); (SW0_PIN) = INPUT;
*/
void		SWITCH_voidSwitchInit(u8 SwitchID )
{
	if(SwitchID < 3 )
	{
		switch(SwitchID)
		{
			case SW0 :	DIO_voidSetPinDirection(SW0_PORT , SW0_PIN , INPUT );	break;
			case SW1 :	DIO_voidSetPinDirection(SW1_PORT , SW1_PIN , INPUT );	break;
			case SW2 :	DIO_voidSetPinDirection(SW2_PORT , SW2_PIN , INPUT );	break;
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
SWITCH_u8GetSwitchValue(SW0); GET(SW0_PIN);
*/
u8		SWITCH_u8GetSwitchValue(u8 SwitchID )
{
	/*		Range Check									*/
	u8 Local_u8Value = 0xFF ;
	if(SwitchID < 3 )
	{
			switch(SwitchID)
			{
				case SW0 :	Local_u8Value	=	DIO_u8GetPinValue(SW0_PORT,SW0_PIN);	break;
				case SW1 :	Local_u8Value	=	DIO_u8GetPinValue(SW1_PORT,SW1_PIN);	break;
				case SW2 :	Local_u8Value	=	DIO_u8GetPinValue(SW2_PORT,SW2_PIN);	break;
			}

	}
	else
	{
		/*	Return Error 								*/
	}
	return Local_u8Value ;
}
