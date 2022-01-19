#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"TMR_interface.h"
#include		"ICU_interface.h"
#include		"DIO_interface.h"
#ifndef				F_CPU
#define				F_CPU				16000000UL
#endif
#ifndef				TMR1_PRESCALER
#define				TMR1_PRESCALER				1024UL
#endif

volatile 		u8 		ICUGlobal_u8Flag=0;
volatile 		u16 	ICUGlobal_u16PeriodTemp1=0;
volatile 		u16 	ICUGlobal_u16PeriodTemp2=0;
volatile 		u16 	ICUGlobal_u16PeriodTemp3=0;
volatile 		u16 	ICUGlobal_u16TotalPeriod=0;

void	    ICU_TMR1_IC_ISR(void)
{
	if (ICUGlobal_u8Flag==0)
	{
		/* 	1st Rising Edge	Detected*/
		ICUGlobal_u16PeriodTemp1=TMR1_u16GetICR();
		ICUGlobal_u8Flag=1;
		DIO_voidSetPinValue(PORTD,PIN7,HIGH);
	}
	else if (ICUGlobal_u8Flag==1)
	{
		/*	2nd Rising Edge Detected*/
		/*	Temp2 - Temp1 = Tperiod */
		/*	Convert to Falling Edge to Get the TPeriod_on*/
		TMR1_voidInputCaptureFallingEdge();
		ICUGlobal_u16PeriodTemp2=TMR1_u16GetICR();
		ICUGlobal_u8Flag=2;
		DIO_voidSetPinValue(PORTD,PIN7,LOW);
	}
	else if (ICUGlobal_u8Flag==2)
	{
		/*	2nd Falling Edge Detected*/
		/*	Temp3 - Temp2= TPeriod_on*/
		ICUGlobal_u16PeriodTemp3=TMR1_u16GetICR();
		ICUGlobal_u8Flag=3;
		DIO_voidSetPinValue(PORTD,PIN7,HIGH);
	}
}
u16       ICU_u16GetFreq(void)
{
	TMR1_voidInputCaptureRisingEdge();
	ICUGlobal_u8Flag=0;
	while (ICUGlobal_u8Flag!=3);
	ICUGlobal_u16TotalPeriod=ICUGlobal_u16PeriodTemp2-ICUGlobal_u16PeriodTemp1;
	u16 Local_u16Freq= (F_CPU/(TMR1_PRESCALER*ICUGlobal_u16TotalPeriod));
	return Local_u16Freq;
}
u16       ICU_u16GetDutyCycle(void)
{
	u16 Local_u16PeriodOn=ICUGlobal_u16PeriodTemp3-ICUGlobal_u16PeriodTemp2;
	u16 Local_u16DutyCycle=((Local_u16PeriodOn*100)/ICUGlobal_u16TotalPeriod);
	return Local_u16DutyCycle;
}
