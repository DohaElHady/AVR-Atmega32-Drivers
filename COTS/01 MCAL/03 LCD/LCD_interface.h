#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H


void	LCD_voidInit8bit(void);

void	LCD_voidInit4bit(void);


void	LCD_voidWriteString( u8* String);
void	LCD_voidWriteu8Num(u8 Num);
void	LCD_voidAddCustomChar(u8* CharHexArray);
void	LCD_voidGoToXY(u8 Row, u8 Column);
void	LCD_voidLCDClear (void);
 

void	LCD_voidWriteChar4bit(u8 Data);
void	LCD_voidSendCMD4bit(u8 CMD);

void	LCD_voidWriteChar8bit(u8 Data);
void	LCD_voidSendCMD8bit(u8 CMD);
#endif