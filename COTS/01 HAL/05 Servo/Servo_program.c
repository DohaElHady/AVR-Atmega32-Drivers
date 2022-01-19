#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"TMR_interface.h"
#include		"DELAY_interface.h"
#include		"PWM_interface.h"
#include		"Servo_interface.h"
#include		"Servo_private.h"
/*****************************************************************************/
/***************************  TMR_PWM ****************************************/

void	Servo_voidInit_TMR1PWM(void)
{
	DIO_voidSetPinDirection(SERVO_TMRPWM_PORT,SERVO_TMRPWM_PIN,OUTPUT);
	PWM_TopICR1_voidSetFreq(50);
}
void	Servo_voidSetAngle_TMR1PWM(u8 Angle)
{
	u8 DutyCycle = Angle*11/180;
	PWM_TopICR1_voidSetDutyCycle(DutyCycle);
}

/*****************************************************************************/
/***************************  SW_PWM *****************************************/


void	Servo_voidInit_SWPWM(void)
{
	DIO_voidSetPinDirection(SERVO_SWPWM_PORT,SERVO_SWPWM_PIN,OUTPUT);
}

void	Servo_voidSetAngle_SWPWM(u8 Angle)
{
	u8 Local_u8ServoFreq=50;
	/********	 	Run the PWM Pulses for 1 Second		*******/
	for ( u8 PWMPulses=0; PWMPulses<Local_u8ServoFreq; PWMPulses++ )
	{
		/***************     HIGH    *********************/
		u8 USdelayTimes=((Angle/30)+1);
		DIO_voidSetPinValue(SERVO_SWPWM_PORT,SERVO_SWPWM_PIN,HIGH);
		for(int SV_loop2=0;SV_loop2<(USdelayTimes/4);SV_loop2++)
		{
			DELAY_voidDelayMS(1);
		}
		for(int SV_loop1=0;SV_loop1<(USdelayTimes-4);SV_loop1++)
		{
			DELAY_voidDelayUS(250);
		}
		/***************     LOW    *********************/
		u8 USdelayTimes2=(8-USdelayTimes);

		DIO_voidSetPinValue(SERVO_SWPWM_PORT,SERVO_SWPWM_PIN,LOW);
		for(int SV_loop1=0;SV_loop1<USdelayTimes2;SV_loop1++)
		{
			DELAY_voidDelayUS(250);
		}
		for(int SV_loop2=0;SV_loop2<18;SV_loop2++)
		{
			DELAY_voidDelayMS(1);
		}
	}
}
