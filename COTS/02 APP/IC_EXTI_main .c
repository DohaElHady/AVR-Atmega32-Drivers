#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"GIE_interface.h"
#include 		"TMR_interface.h"
#include		"EXTI_interface.h"
#include 		"IC_EXTI_interface.h"
#include		"LCD_interface.h"
/*
TMR2 Configs:
				TMR2_CLK_SELECT					PRESCALER_1024
				TMR2_WAVE_GEN						NORMAL_WAVE_GEN
				TMR2_COMPARE_MATCH			NORMAL_COMPARE_MATCH

*/

int main(void)
{
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	TMR2_voidSetOverflowISRFunc(IC_EXTI_TMROVFISR);
	EXTI0_voidSetISRFunc(IC_EXTI_ISR);
	EXTI0_voidInit();
	TMR2_voidInit();
	EXTI0_voidEnable();
	TMR2_voidTOIEnable();
	GIE_voidEnable();
	LCD_voidInit4bit();
	u16 Freq=0;
	u16 DutyCycle=0;
    while (1)
    {

			Freq=IC_EXTI_u16GetFreq();
			DutyCycle=IC_EXTI_u16GetDutyCycle();
			LCD_voidGoToXY(0,0);
			LCD_voidWriteu8Num((u8)Freq);
			LCD_voidGoToXY(1,0);
			LCD_voidWriteu8Num((u8)DutyCycle);

    }
}
