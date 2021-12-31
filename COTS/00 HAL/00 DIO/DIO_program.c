#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"DIO_private.h"

/*
DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT); (DDRA,0) = 1;
*/
void		DIO_voidSetPinDirection(u8 PortID ,u8 PinID ,u8 Direction )
{
	/*		Range Check									*/
	if(PortID < 4 && PinID < 8)
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTA :	SET_BIT(DDRA_REG,PinID);	break;
				case PORTB :	SET_BIT(DDRB_REG,PinID);	break;
				case PORTC :	SET_BIT(DDRC_REG,PinID);	break;
				case PORTD :	SET_BIT(DDRD_REG,PinID);	break;
			}
		}else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTA :	CLR_BIT(DDRA_REG,PinID);	break;
				case PORTB :	CLR_BIT(DDRB_REG,PinID);	break;
				case PORTC :	CLR_BIT(DDRC_REG,PinID);	break;
				case PORTD :	CLR_BIT(DDRD_REG,PinID);	break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
DIO_voidSetPinValue(PORTA,PIN0,HIGH); (PORTA,0) = 1;
*/
void		DIO_voidSetPinValue(u8 PortID ,u8 PinID ,u8 Value )
{
	/*		Range Check									*/
	if(PortID < 4 && PinID < 8)
	{
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case PORTA :	SET_BIT(PORTA_REG,PinID);	break;
				case PORTB :	SET_BIT(PORTB_REG,PinID);	break;
				case PORTC :	SET_BIT(PORTC_REG,PinID);	break;
				case PORTD :	SET_BIT(PORTD_REG,PinID);	break;
			}
		}else if(Value == LOW)
		{
			switch(PortID)
			{
				case PORTA :	CLR_BIT(PORTA_REG,PinID);	break;
				case PORTB :	CLR_BIT(PORTB_REG,PinID);	break;
				case PORTC :	CLR_BIT(PORTC_REG,PinID);	break;
				case PORTD :	CLR_BIT(PORTD_REG,PinID);	break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
u8 x = DIO_voidGetPinValue(PORTA,PIN0); GET(PINA,0)
*/

u8			DIO_u8GetPinValue(u8 PortID ,u8 PinID )
{
	u8 Local_u8Value = 0xFF ;
	/*		Range Check									*/
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
		{
			case PORTA :	Local_u8Value	=	GET_BIT(PINA_REG,PinID);	break;
			case PORTB :	Local_u8Value	=	GET_BIT(PINB_REG,PinID);	break;
			case PORTC :	Local_u8Value	=	GET_BIT(PINC_REG,PinID);	break;
			case PORTD :	Local_u8Value	=	GET_BIT(PIND_REG,PinID);	break;
		}
	}
	else
	{
		/*	Return Error 								*/
	}
	return Local_u8Value ;
}

/*
DIO_voidSetPortDirection(PORTA,OUTPUT); (DDRA) = 0xFF;
*/
void		DIO_voidSetPortDirection(u8 PortID ,u8 Direction )
{
	/*		Range Check									*/
	if(PortID < 4 )
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTA :	SET_PORT(DDRA_REG);	break;
				case PORTB :	SET_PORT(DDRB_REG);	break;
				case PORTC :	SET_PORT(DDRC_REG);	break;
				case PORTD :	SET_PORT(DDRD_REG);	break;
			}
		}else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTA :	CLR_PORT(DDRA_REG);	break;
				case PORTB :	CLR_PORT(DDRB_REG);	break;
				case PORTC :	CLR_PORT(DDRC_REG);	break;
				case PORTD :	CLR_PORT(DDRD_REG);	break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}
/*
DIO_voidSetPortValue(PORTA,0x58); (PORTA) = ox58;
*/
void		DIO_voidSetPortValue(u8 PortID ,u8 Value )
{
	if(PortID < 4 )
	{
		
		switch(PortID)
		{
			case PORTA :	ASG_PORT(PORTA_REG,Value);	break;
			case PORTB :	ASG_PORT(PORTB_REG,Value);	break;
			case PORTC :	ASG_PORT(PORTC_REG,Value);	break;
			case PORTD :	ASG_PORT(PORTD_REG,Value);	break;
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}
/*
DIO_voidSetNibbleDirection (PORTA,HIGH,HIGH); (DDRA_REG) = 0xF0;
*/
void		DIO_voidSetNibbleDirection(u8 PortID ,u8 NibbleCase , u8 Direction )
{
	if(PortID < 4 && NibbleCase < 2 )
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTA :	SET_NIBBLE(DDRA_REG,NibbleCase);	break;
				case PORTB :	SET_NIBBLE(DDRB_REG,NibbleCase);	break;
				case PORTC :	SET_NIBBLE(DDRC_REG,NibbleCase);	break;
				case PORTD :	SET_NIBBLE(DDRD_REG,NibbleCase);	break;
			}
			}else if (Direction == INPUT){
			switch(PortID)
			{
				case PORTA :	CLR_NIBBLE(DDRA_REG,NibbleCase);	break;
				case PORTB :	CLR_NIBBLE(DDRB_REG,NibbleCase);	break;
				case PORTC :	CLR_NIBBLE(DDRC_REG,NibbleCase);	break;
				case PORTD :	CLR_NIBBLE(DDRD_REG,NibbleCase);	break;
			}
		}
	}
	else
	{
		/*	Return Error 								*/
	}
}

/*
DIO_voidSetNibbleValue (PORTA,HIGH,0x70); (PORTA_REG) = 0111 xxxx;
*/
void		DIO_voidSetNibbleValue(u8 PortID ,u8 NibbleCase , u8 Value )
{
	if(PortID < 4 && NibbleCase < 2 )
	{
		switch(PortID)
		{
			case PORTA :	ASG_NIBBLE(PORTA_REG,NibbleCase,Value);	break;
			case PORTB :	ASG_NIBBLE(PORTB_REG,NibbleCase,Value);	break;
			case PORTC :	ASG_NIBBLE(PORTC_REG,NibbleCase,Value);	break;
			case PORTD :	ASG_NIBBLE(PORTD_REG,NibbleCase,Value);	break;
		}
		
	}
	else
	{
		/*	Return Error 								*/
	}
}