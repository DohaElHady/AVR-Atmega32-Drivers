#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"TMR_interface.h"
#include		"EXTI_interface.h"
#include		"IC_EXTI_interface.h"

#ifndef				F_CPU
#define				F_CPU				16000000UL
#endif
#ifndef				TMR2_PRESCALER
#define				TMR2_PRESCALER				1024UL
#endif

volatile 		u8 		IC_EXTI_Global_u8Flag=0;
volatile 		u16 	IC_EXTI_Global_u8Overflow=0;
volatile 		u16 	IC_EXTI_Global_u16PeriodOn=0;
volatile 		u16 	IC_EXTI_Global_u16TotalPeriod=0;

void	    IC_EXTI_TMROVFISR(void)
{
	IC_EXTI_Global_u8Overflow++;
}
void	    IC_EXTI_ISR(void)
{
	if (IC_EXTI_Global_u8Flag==0)
	{
		/* 	Start Calculating Time*/
		TMR2_voidSetTCNT(0);
		IC_EXTI_Global_u8Overflow=0
		IC_EXTI_Global_u8Flag=1;
	}
	else if (IC_EXTI_Global_u8Flag==1)
	{
		/*	2nd Rising Edge Detected*/
		/*	Temp1 = Tperiod */
		IC_EXTI_Global_u16TotalPeriod=(TMR2_u8GetTCNT()+(IC_EXTI_Global_u8Overflow*256));
		TMR2_voidSetTCNT(0);
		IC_EXTI_Global_u8Overflow=0;
		/*	Convert to Falling Edge to Get the TPeriod_on*/
		EXTI0_voidSenseFallingEdge();
		IC_EXTI_Global_u8Flag=2;
	}
	else if (IC_EXTI_Global_u8Flag==2)
	{
		/*	2nd Falling Edge Detected*/
		/*	Temp2= TPeriod_on*/
		IC_EXTI_Global_u16PeriodOn=(TMR2_u8GetTCNT()+(IC_EXTI_Global_u8Overflow*256));
		IC_EXTI_Global_u8Flag=3;
	}
}

u16       IC_EXTI_u16GetFreq(void)
{
	EXTI0_voidSenseRisingEdge();
	IC_EXTI_Global_u8Flag=0;
	while (IC_EXTI_Global_u8Flag!=3);
	u16 Local_u16Freq= (F_CPU/(TMR2_PRESCALER*IC_EXTI_Global_u16TotalPeriod));
	return Local_u16Freq;
}
u16       IC_EXTI_u16GetDutyCycle(void)
{
	u16 Local_u16DutyCycle=((IC_EXTI_Global_u16PeriodOn*100)/IC_EXTI_Global_u16TotalPeriod);
	return Local_u16DutyCycle;
}
