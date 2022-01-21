#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"TMR_interface.h"
#include		"PWM_interface.h"

#ifndef				F_CPU
#define				F_CPU				16000000UL
#endif


volatile 	u16 		Global_PWM_TopICR1_u16ICRValue=0;

void	    PWM_voidSetDutyCycle(u8 PwmDutyCycle,u8 PWM_TMRSelect)
{
	u8	Local_u8OCRValue=0;
	u16	Local_u16OCRValue=0;
	switch (PWM_TMRSelect)
	{
		case TMR0_PWM:
			Local_u8OCRValue = (256*PwmDutyCycle/100);
			TMR0_voidSetOCR(Local_u8OCRValue);
			break;
		case TMR1A_PWM:
			Local_u16OCRValue = (65535UL*PwmDutyCycle/100);
			TMR1A_voidSetOCR(Local_u16OCRValue);
			break;
		case TMR1B_PWM:
			Local_u16OCRValue = (65535UL*PwmDutyCycle/100);
			TMR1B_voidSetOCR(Local_u16OCRValue);
			break;
		case TMR2_PWM:
			Local_u8OCRValue = (256*PwmDutyCycle/100);
			TMR2_voidSetOCR(Local_u8OCRValue);
			break;
	}
}

void	    PWM_TopICR1_voidSetFreq(u8 PwmFreq)
{
	Global_PWM_TopICR1_u16ICRValue=(F_CPU/(PwmFreq*PWM_TOPICR1_PRESCALER));
	TMR1_voidSetICR(Global_PWM_TopICR1_u16ICRValue);
}
void 		PWM_TopICR1_voidSetDutyCycle(u8 PwmDutyCycle)
{
	u16	Local_u16OCRValue_TopICR1=(Global_PWM_TopICR1_u16ICRValue*PwmDutyCycle/100UL);
	TMR1A_voidSetOCR(Local_u16OCRValue_TopICR1);
}
