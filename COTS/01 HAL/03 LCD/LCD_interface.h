#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H


void	LCD_voidInit8bit(void);

void	LCD_voidInit4bit(void);


void	LCD_voidWriteString( u8* String);
void	LCD_voidWriteu8Num(u8 Num);
void	LCD_voidAddCustomChar(u8* CharHexArray);
void	LCD_voidGoToXY(u8 Row, u8 Column);
void	LCD_voidCursorDisplayShift(u8 OrderCmd);
void	LCD_voidLCDClear (void);

 

void	LCD_voidWriteChar4bit(u8 Data);
void	LCD_voidSendCMD4bit(u8 CMD);

void	LCD_voidWriteChar8bit(u8 Data);
void	LCD_voidSendCMD8bit(u8 CMD);

/*		LCD Cursor & Display Shift CMD Data Line Values					*/
#define CURSOR_SH_LEFT_CMD		0x10
#define CURSOR_SH_RIGHT_CMD		0x14
#define DISPLAY_SH_LEFT_CMD		0x18
#define DISPLAY_SH_RIGHT_CMD	0x1C

/*		LCD Cursor Start Position CMD Data Line Values					*/
#define CURSOR_ROW0_COL0_CMD		0x80
#define CURSOR_ROW1_COL0_CMD		0xC0

#define LCD_CLEAR_CMD				0x01

/*		Addresses To start writing in DDRAM or CGRAM Data Line Values	*/
#define DDRAM_INIT_ADDRESS_CMD		0x80
#define CGRAM_INIT_ADDRESS_CMD		0x40

#define CGRAM_LAST_ADDRESS_CMD		(DDRAM_INIT_ADDRESS_CMD-1)

#endif
