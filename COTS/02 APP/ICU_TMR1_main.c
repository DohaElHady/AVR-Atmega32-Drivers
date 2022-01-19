#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"GIE_interface.h"
#include 		"TMR_interface.h"
#include 		"ICU_interface.h"
#include		"LCD_interface.h"
/*
TMR1 Configs:
				TMR1_CLK_SELECT					PRESCALER_1024
				TMR1_WAVE_GEN						NORMAL_WAVE_GEN
				TMR1_NOISE_CANCELER			LOW
				TMR1_IC_EDGE_SELECT     RISING_EDGE
				TMR1A_COMPARE_MATCH			NORMAL_COMPARE_MATCH
				TMR1B_COMPARE_MATCH     NORMAL_COMPARE_MATCH

*/

int main(void)
{
	DIO_voidSetPinDirection(PORTD,PIN6,INPUT);
	TMR1_voidSetInputCaptureISRFunc(ICU_TMR1_IC_ISR);
	TMR1_voidInit();
	TMR1_voidTICIEnable();
	TMR1_voidInputCaptureRisingEdge();
	GIE_voidEnable();
	LCD_voidInit4bit();
	u16 Freq=0;
	u16 DutyCycle=0;
    while (1)
    {

			Freq=ICU_u16GetFreq();
			DutyCycle=ICU_u16GetDutyCycle();
			LCD_voidGoToXY(0,0);
			LCD_voidWriteu8Num((u8)Freq);
			LCD_voidGoToXY(1,0);
			LCD_voidWriteu8Num((u8)DutyCycle);

    }
}
