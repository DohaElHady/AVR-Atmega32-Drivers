#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"SSD_interface.h"
#include		"SSD_private.h"

/*
SSD_voidSSDInit(SSD1); (EN1_PIN) = OUTPUT;
*/
void		SSD_voidSSDInit(u8 SSDID )
{
	if(SSDID < 3 && SSDID > 0 )
	{
		DIO_voidSetPinDirection(DIP_PORT , DIP_PIN , OUTPUT );
		DIO_voidSetNibbleDirection(SSD_PORT, SSD_NIBBLECASE, OUTPUT);
		switch(SSDID)
		{
			case SSD1 :	DIO_voidSetPinDirection(EN1_PORT , EN1_PIN , OUTPUT );	break;
			case SSD2 :	DIO_voidSetPinDirection(EN2_PORT , EN2_PIN , OUTPUT );	break;
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
SSD_voidSetSSDValue(SSD1,8); (SSD1) = 8;
*/
void		SSD_voidSetSSDValue(u8 SSDID ,u8 Value )
{
	/*		Range Check									*/
	if(LedID < 3 )
	{
		if(SSDID < 3 && SSDID > 0 )
		{
			switch(SSDID)
			{
				case SSD1 :	DIO_voidSetPinValue(DATA_A_PORT , DATA_A_PIN , (Value&0x10>>4) );
										DIO_voidSetPinValue(DATA_B_PORT , DATA_B_PIN , (Value&0x20>>5) );
										DIO_voidSetPinValue(DATA_C_PORT , DATA_C_PIN , (Value&0x40>>6) );
										DIO_voidSetPinValue(DATA_D_PORT , DATA_D_PIN , (Value&0x80>>7) );
										break;
				case SSD2 :	DIO_voidSetPinValue(DATA_A_PORT , DATA_A_PIN , (Value&0x10>>4) );
										DIO_voidSetPinValue(DATA_B_PORT , DATA_B_PIN , (Value&0x20>>5) );
										DIO_voidSetPinValue(DATA_C_PORT , DATA_C_PIN , (Value&0x40>>6) );
										DIO_voidSetPinValue(DATA_D_PORT , DATA_D_PIN , (Value&0x80>>7) );
										break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}
