#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"TMR_interface.h"
#include		"DELAY_interface.h"
#include		"DELAY_private.h"
#include		"DELAY_config.h"



#define				MS_PRESCALER			1024UL
#define				US_PRESCALER			8

volatile 		u16 		DelayGlobal_u16OverflowCounts=0;

void	DELAY_TMROVFISR(void)
{
	DelayGlobal_u16OverflowCounts++;
}

void      DELAY_voidDelayMS(u8 DelayMS)
{
	#if 			DELAY_TMR_SELECT	== TMR0_DELAY
		TMR0_voidSetPrescaler(PRESCALER_1024);
		/*		Math to calulate Ovf & Preload */
		u16	Local_u16NumTicks=((DelayMS*F_CPU)/(MS_PRESCALER*1000UL));
		u16	Local_u16NumOverflowReq= ((Local_u16NumTicks/256)+1);
		u16	Local_u16Preload=(Local_u16NumTicks%256);
		/*		Preload the Timer	0						*/
		TMR0_voidSetTCNT((u8)Local_u16Preload);
		/*		Pulling till the delay is over*/
		while(DelayGlobal_u16OverflowCounts!=(Local_u16NumOverflowReq));
		DelayGlobal_u16OverflowCounts=0;

	#elif 		DELAY_TMR_SELECT	== TMR2_DELAY
		TMR2_voidSetPrescaler(PRESCALER_1024);
		/*		Math to calulate Ovf & Preload */
		u16	Local_u16NumTicks=((DelayMS*F_CPU)/(MS_PRESCALER*1000UL));
		u16	Local_u16NumOverflowReq= ((Local_u16NumTicks/256)+1);
		u16	Local_u16Preload=(Local_u16NumTicks%256);
		/*		Preload the Timer	2						*/
		TMR2_voidSetTCNT((u8)Local_u16Preload);
		/*		Pulling till the delay is over*/
		while(DelayGlobal_u16OverflowCounts!=(Local_u16NumOverflowReq));
		DelayGlobal_u16OverflowCounts=0;
	#endif
}

void      DELAY_voidDelayUS(u8 DelayUS)
{
	#if 			DELAY_TMR_SELECT	== TMR0_DELAY
		TMR0_voidSetPrescaler(PRESCALER_8);
		/*		Math to calulate Ovf & Preload */
		u16	Local_u16NumTicks=((DelayUS*F_CPU)/(US_PRESCALER*1000000UL));
		u16	Local_u16NumOverflowReq= ((Local_u16NumTicks/256)+1);
		u16	Local_u16Preload=(Local_u16NumTicks%256);
		/*		Preload the Timer	0						*/
		TMR0_voidSetTCNT((u8)Local_u16Preload);
		/*		Pulling till the delay is over*/
		while(DelayGlobal_u16OverflowCounts!=Local_u16NumOverflowReq);
		DelayGlobal_u16OverflowCounts=0;

	#elif 		DELAY_TMR_SELECT	== TMR2_DELAY
		TMR2_voidSetPrescaler(PRESCALER_8);
		/*		Math to calulate Ovf & Preload */
		u16	Local_u16NumTicks=((DelayUS*F_CPU)/(US_PRESCALER*1000000UL));
		u16	Local_u16NumOverflowReq= ((Local_u16NumTicks/256)+1);
		u16	Local_u16Preload=(Local_u16NumTicks%256);
		/*		Preload the Timer	2						*/
		TMR2_voidSetTCNT((u8)Local_u16Preload);
		/*		Pulling till the delay is over*/
		while(DelayGlobal_u16OverflowCounts!=Local_u16NumOverflowReq);
		DelayGlobal_u16OverflowCounts=0;
	#endif
}
