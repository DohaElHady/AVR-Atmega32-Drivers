#define			F_CPU		16000000UL
#define			LCD_MODE	4

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"

#include		"LCD_interface.h"
#include		"LCD_private.h"

#include		<util/delay.h>

void	LCD_voidInit8bit(void){
	/*	Pins Init 					*/
	/*	PB2 , 1 ,3 = OUTPUT 		*/
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_EN,OUTPUT);
	/*	PORTA = OUTPUT				*/
	DIO_voidSetPortDirection(LCD_DATA_PORT,OUTPUT);

	/* 		After Power ON		*/
	_delay_ms(35);
	/*		Function Set 2 lines of Display and Font Size 5*7	*/
	LCD_voidSendCMD8bit(0x38);
	_delay_ms(1);
	/*		Display ON/OFF Control Display ON, Cursor OFF		*/
	LCD_voidSendCMD8bit(0x0C);
	_delay_ms(1);
	/*		Display Clear										*/
	LCD_voidSendCMD8bit(0x01);
	_delay_ms(2);
	/*		Entry Mode Display  Cursor Increases				*/
	LCD_voidSendCMD8bit(0x06);
	/*	Set Cursor to 0,0 pos. 		*/
	LCD_voidGoToXY(0,0);
}

void	LCD_voidInit4bit(void){
	/*	Pins Init 					*/
	/*	PB2 , 1 ,3 = OUTPUT 		*/
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_EN,OUTPUT);
	/*	PORTA_HighNibble (A4,A5,A6,A7) = OUTPUT				*/
	DIO_voidSetNibbleDirection(LCD_DATA_PORT,LCD_4BIT_NIBBLECASE,OUTPUT);
	/*	LCD Init 					*/
	_delay_ms(35);
	LCD_voidSendCMD4bit(0x33);
	LCD_voidSendCMD4bit(0x32);
	LCD_voidSendCMD4bit(0x28);

	LCD_voidSendCMD4bit(0x0C);
	LCD_voidSendCMD4bit(0x01);
	LCD_voidSendCMD4bit(0x06);
	LCD_voidSendCMD4bit(0x02);
	/*	Set Cursor to 0,0 pos. 		*/
	LCD_voidGoToXY(0,0);
}



void	LCD_voidWriteString( u8 * String)
{
	int Local_u8Value_Index=0;
	while(String[Local_u8Value_Index] != '\0' )
	{

		#if LCD_MODE==4
			LCD_voidWriteChar4bit((u8) String[Local_u8Value_Index]);
		#elif LCD_MODE==8
			LCD_voidWriteChar8bit((u8) String[Local_u8Value_Index]);
		#endif

		Local_u8Value_Index++;
	}
}


void	LCD_voidWriteu8Num(u8 Num)
{
	/*		Use math to write the most significant number first on LCD		*/
	/*		The start address of numbers on LCD is 0x30						*/
	
	#if LCD_MODE==4
		LCD_voidWriteChar4bit(((Num/100)%10)+0x30);
		LCD_voidWriteChar4bit(((Num/10)%10)+0x30);
		LCD_voidWriteChar4bit((Num%10)+0x30);
	#elif LCD_MODE==8
		LCD_voidWriteChar8bit(((Num/100)%10)+0x30);
		LCD_voidWriteChar8bit(((Num/10)%10)+0x30);
		LCD_voidWriteChar8bit((Num%10)+0x30);
	#endif
}


void	LCD_voidAddCustomChar (u8* CharHexArray){

	u8 Local_u8Variable_HexArrLen=8;
	u8 Local_u8Variable_Index=0;
	/*	initializing CGRAM address								*/
	static u8 Local_u8Variable_CharAdd=CGRAM_INIT_ADDRESS_CMD;
	/*	initializing writing in CGRAM							*/
	#if LCD_MODE==4
			LCD_voidSendCMD4bit(Local_u8Variable_CharAdd);
	#elif LCD_MODE==8
		LCD_voidSendCMD8bit(Local_u8Variable_CharAdd);
	#endif
	if (Local_u8Variable_CharAdd < CGRAM_LAST_ADDRESS_CMD)
	{
		while(Local_u8Variable_Index < Local_u8Variable_HexArrLen )
		{
			#if LCD_MODE==4
				LCD_voidWriteChar4bit(CharHexArray[Local_u8Variable_Index]);
			#elif LCD_MODE==8
				LCD_voidWriteChar8bit(CharHexArray[Local_u8Variable_Index]);
			#endif

			Local_u8Variable_Index++;
		}
		/*Increasing Address 8 bits so that in the next time write in the following memory location */
		Local_u8Variable_CharAdd += 8;
	}
	/*	back to DDRAM address							*/
	#if LCD_MODE==4
		LCD_voidSendCMD4bit(DDRAM_INIT_ADDRESS_CMD);
	#elif LCD_MODE==8
		LCD_voidSendCMD8bit(DDRAM_INIT_ADDRESS_CMD);
	#endif
}
void	LCD_voidGoToXY(u8 Row, u8 Column)
{
	if (Row ==0)
	{
		#if LCD_MODE==4
			LCD_voidSendCMD4bit((CURSOR_ROW0_COL0_CMD+Column));
		#elif LCD_MODE==8
			LCD_voidSendCMD8bit((CURSOR_ROW0_COL0_CMD+Column));
		#endif

	}else if (Row ==1)
	{
		#if LCD_MODE==4
			LCD_voidSendCMD4bit((CURSOR_ROW1_COL0_CMD+Column));
		#elif LCD_MODE==8
			LCD_voidSendCMD8bit((CURSOR_ROW1_COL0_CMD+Column));
		#endif
	}
}

void	LCD_voidCursorDisplayShift(u8 OrderCmd)
{
	#if LCD_MODE==4
	LCD_voidSendCMD4bit(OrderCmd);
	#elif LCD_MODE==8
	LCD_voidSendCMD8bit(OrderCmd);
	#endif
}
void	LCD_voidLCDClear (void)
{
	#if LCD_MODE==4
		LCD_voidSendCMD4bit(LCD_CLEAR_CMD);
	#elif LCD_MODE==8
		LCD_voidSendCMD8bit(LCD_CLEAR_CMD);
	#endif
}

void	LCD_voidWriteChar4bit(u8 Data)
{
	/*	1-	RS = 1	to Send CMD								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*	2-	RW = 0	to Write CMD							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*	3-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	4-	Assign the High Nibble of Data without change in the low Nibble in PORT	*/
	DIO_voidSetNibbleValue(LCD_DATA_PORT,HIGH,Data);
	/*	5-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
	/*	6-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	7-	Assign the LOW Nibble of Data without change in the low Nibble in PORT	*/
	DIO_voidSetNibbleValue(LCD_DATA_PORT,HIGH,Data<<4);
	/*	8-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
}


void	LCD_voidSendCMD4bit(u8 CMD)
{
	/*	1-	RS = 0	to Send CMD								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*	2-	RW = 0	to Write CMD							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*	3-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	4-	Assign the High Nibble of Data without change in the low Nibble in PORT	*/
	DIO_voidSetNibbleValue(LCD_DATA_PORT,HIGH,CMD);
	/*	5-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
	/*	6-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	7-	Assign the LOW Nibble of Data without change in the low Nibble in PORT	*/
	DIO_voidSetNibbleValue(LCD_DATA_PORT,HIGH,CMD<<4);
	/*	8-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
}


void	LCD_voidWriteChar8bit(u8 Data){
	/*1-RS=1 to send Char										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*2-RW=0 to write Char										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*3-EN must be latched (EN=1)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*4-Send CMD								*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Data);
	/*3-EN must be latched (EN=0)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
}


void	LCD_voidSendCMD8bit(u8 CMD){
	/*1-RS=0 to send CMD										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*2-RW=0 to write CMD										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*3-EN must be latched (EN=1)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*4-Send CMD												*/
	DIO_voidSetPortValue(LCD_DATA_PORT,CMD);
	/*3-EN must be latched (EN=0)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);

}
