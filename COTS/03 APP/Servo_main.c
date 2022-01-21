#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"GIE_interface.h"
#include 		"TMR_interface.h"
#include 		"PWM_interface.h"
#include		"DELAY_interface.h"
#include		"Servo_interface.h"

/*
TMR1 Configs:
				TMR1_CLK_SELECT					PRESCALER_64
				TMR1_WAVE_GEN						FAST_PWM_TOP_ICR1_WAVE_GEN
				TMR1_NOISE_CANCELER			HIGH
				TMR1_IC_EDGE_SELECT     FALLING_EDGE
				TMR1A_COMPARE_MATCH			CLR_OC_COMPARE_MATCH
				TMR1B_COMPARE_MATCH     NORMAL_COMPARE_MATCH

*/
/*
TMR2 Configs:
				TMR2_CLK_SELECT					PRESCALER_1024
				TMR2_WAVE_GEN         	NORMAL_WAVE_GEN
				TMR2_COMPARE_MATCH     	NORMAL_COMPARE_MATCH
*/

int main(void)
{
	/*			DELAY Initialization 		*/
	TMR2_voidSetOverflowISRFunc(DELAY_TMR_OVF_ISR);
	TMR2_voidTOIEnable();
	GIE_voidEnable();
	/*			Serve TMR_PWM Initialization 		*/
	TMR1_voidInit();
	Servo_voidInit_TMR1PWM();
	/*			Serve SW_PWM Initialization 		*/
	Servo_voidInit_SWPWM();
  while (1)
  {
		Servo_voidSetAngle_TMR1PWM(180);
		Servo_voidSetAngle_SWPWM(180);

		for(u8 i=0; i<20;i++)
		{ // Delay 4 Sec.
			DELAY_voidDelayMS(255);
		}

		Servo_voidSetAngle_TMR1PWM(10);
		Servo_voidSetAngle_SWPWM(10);

		for(u8 i=0; i<20;i++)
		{	// Delay 4 Sec.
			DELAY_voidDelayMS(255);
		}

  }
}
