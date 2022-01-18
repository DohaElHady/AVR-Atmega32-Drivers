#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"TMR_interface.h"
#include		"TMR_private.h"
#include		"TMR_config.h"

#ifndef			NULL
#define			NULL			(void*)0
#endif

static void (*TMR0_Overflow_ISR_CallBack) 			(void)=NULL;
static void (*TMR0_CompareMatch_ISR_CallBack) 	(void)=NULL;

static void (*TMR1_InputCapture_ISR_CallBack)		(void)=NULL;
static void (*TMR1A_CompareMatch_ISR_CallBack)	(void)=NULL;
static void (*TMR1B_CompareMatch_ISR_CallBack)	(void)=NULL;
static void (*TMR1_Overflow_ISR_CallBack) 			(void)=NULL;

static void (*TMR2_Overflow_ISR_CallBack) 			(void)=NULL;
static void (*TMR2_CompareMatch_ISR_CallBack) 	(void)=NULL;

/*****************************************************************************/
/***************************   TMR0  8-Bit************************************/

void		TMR0_voidInit(void)
{
	CLR_BIT(TCCR0_REG,FOC0);
	#if 	TMR0_WAVE_GEN		==	NORMAL_WAVE_GEN
			CLR_BIT(TCCR0_REG,WGM00);
			CLR_BIT(TCCR0_REG,WGM01);
	#elif TMR0_WAVE_GEN		==	PWM_WAVE_GEN
			SET_BIT(TCCR0_REG,WGM00);
			CLR_BIT(TCCR0_REG,WGM01);
	#elif TMR0_WAVE_GEN		==	CTC_WAVE_GEN
			CLR_BIT(TCCR0_REG,WGM00);
			SET_BIT(TCCR0_REG,WGM01);
	#elif TMR0_WAVE_GEN		==	FAST_PWM_WAVE_GEN
			SET_BIT(TCCR0_REG,WGM00);
			SET_BIT(TCCR0_REG,WGM01);
	#endif

	#if 	TMR0_COMPARE_MATCH		==	NORMAL_COMPARE_MATCH
			CLR_BIT(TCCR0_REG,COM00);
			CLR_BIT(TCCR0_REG,COM01);
	#elif TMR0_COMPARE_MATCH		==	TOGGLE_OC_COMPARE_MATCH
			SET_BIT(TCCR0_REG,COM00);
			CLR_BIT(TCCR0_REG,COM01);
	#elif TMR0_COMPARE_MATCH		==	CLR_OC_COMPARE_MATCH
			CLR_BIT(TCCR0_REG,COM00);
			SET_BIT(TCCR0_REG,COM01);
	#elif TMR0_COMPARE_MATCH		==	SET_OC_COMPARE_MATCH
			SET_BIT(TCCR0_REG,COM00);
			SET_BIT(TCCR0_REG,COM01);
	#endif

	#if 	TMR0_CLK_SELECT		==	NO_CLK
			CLR_BIT(TCCR0_REG,CS00);
			CLR_BIT(TCCR0_REG,CS01);
			CLR_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	PRESCALER_0
			SET_BIT(TCCR0_REG,CS00);
			CLR_BIT(TCCR0_REG,CS01);
			CLR_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	PRESCALER_8
			CLR_BIT(TCCR0_REG,CS00);
			SET_BIT(TCCR0_REG,CS01);
			CLR_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	PRESCALER_64
			SET_BIT(TCCR0_REG,CS00);
			SET_BIT(TCCR0_REG,CS01);
			CLR_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	PRESCALER_256
			CLR_BIT(TCCR0_REG,CS00);
			CLR_BIT(TCCR0_REG,CS01);
			SET_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	PRESCALER_1024
			SET_BIT(TCCR0_REG,CS00);
			CLR_BIT(TCCR0_REG,CS01);
			SET_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	EX_CLK_FALLING_EDGE
			CLR_BIT(TCCR0_REG,CS00);
			SET_BIT(TCCR0_REG,CS01);
			SET_BIT(TCCR0_REG,CS02);
	#elif TMR0_CLK_SELECT		==	EX_CLK_RISING_EDGE
			SET_BIT(TCCR0_REG,CS00);
			SET_BIT(TCCR0_REG,CS01);
			SET_BIT(TCCR0_REG,CS02);
	#endif
	TCNT0_REG=0x00;
}

void 		TMR0_voidSetPrescaler(u8 TMR0_Prescaler)
{
	switch (TMR0_Prescaler)
	{
		case 		NO_CLK:
				CLR_BIT(TCCR0_REG,CS00);
				CLR_BIT(TCCR0_REG,CS01);
				CLR_BIT(TCCR0_REG,CS02);
				break;
		case 		PRESCALER_0:
				SET_BIT(TCCR0_REG,CS00);
				CLR_BIT(TCCR0_REG,CS01);
				CLR_BIT(TCCR0_REG,CS02);
				break;
		case 		PRESCALER_8:
				CLR_BIT(TCCR0_REG,CS00);
				SET_BIT(TCCR0_REG,CS01);
				CLR_BIT(TCCR0_REG,CS02);
				break;
		case 		PRESCALER_64:
				SET_BIT(TCCR0_REG,CS00);
				SET_BIT(TCCR0_REG,CS01);
				CLR_BIT(TCCR0_REG,CS02);
				break;
		case 		PRESCALER_256:
				CLR_BIT(TCCR0_REG,CS00);
				CLR_BIT(TCCR0_REG,CS01);
				SET_BIT(TCCR0_REG,CS02);
				break;
		case 		PRESCALER_1024:
				SET_BIT(TCCR0_REG,CS00);
				CLR_BIT(TCCR0_REG,CS01);
				SET_BIT(TCCR0_REG,CS02);
				break;
		case 		EX_CLK_FALLING_EDGE:
				CLR_BIT(TCCR0_REG,CS00);
				SET_BIT(TCCR0_REG,CS01);
				SET_BIT(TCCR0_REG,CS02);
				break;
		case 		EX_CLK_RISING_EDGE:
				SET_BIT(TCCR0_REG,CS00);
				SET_BIT(TCCR0_REG,CS01);
				SET_BIT(TCCR0_REG,CS02);
				break;
		}

}
/*					Timer Counter TCNT0 Setter & Getter				*/
u8 			TMR0_u8GetTCNT(void)
{
	return TCNT0_REG;
}

void		TMR0_voidSetTCNT(u8 TCNT0_Preload)
{
	TCNT0_REG=TCNT0_Preload;
}

/*					Compare Match Interrupt	OCR0				*/
void 		TMR0_voidOCIEnable(void)
{
	SET_BIT(TIMSK_REG,OCIE0);
}

void 		TMR0_voidOCIDisable(void)
{
	CLR_BIT(TIMSK_REG,OCIE0);
}

void		TMR0_voidSetOCR(u8 OCR0Value)
{
	OCR0_REG=OCR0Value;
}

void    TMR0_voidSetCompareMatchISRFunc(void (*PointertoFunCM0) (void))
{
	TMR0_CompareMatch_ISR_CallBack=PointertoFunCM0;
}

void		__vector_10(void)
{
	TMR0_CompareMatch_ISR_CallBack();
}

/*					Timer0 Overflow Interrupt Enable/Disable			*/
void 		TMR0_voidTOIEnable(void)
{
	SET_BIT(TIMSK_REG,TOIE0);
}
void 		TMR0_voidTOIDisable(void)
{
	CLR_BIT(TIMSK_REG,TOIE0);
}
void    TMR0_voidSetOverflowISRFunc(void (*PointertoFunOF0) (void))
{
	TMR0_Overflow_ISR_CallBack=PointertoFunOF0;
}

void		__vector_11(void)
{
	TMR0_Overflow_ISR_CallBack();

}

/*****************************************************************************/
/***************************   TMR1  16-Bit***********************************/

void		TMR1_voidInit(void)
{
	CLR_BIT(TCCR1A_REG,FOC1A);
	CLR_BIT(TCCR1A_REG,FOC1B);
	#if 		TMR1_WAVE_GEN		==	NORMAL_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_8BIT_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_9BIT_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_10BIT_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	CTC_TOP_OCR1A_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	FAST_PWM_8BIT_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	FAST_PWM_9BIT_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	FAST_PWM_10BIT_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			CLR_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_PHASE_FREQ_CORRECT_TOP_ICR1_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_PHASE_FREQ_CORRECT_TOP_OCR1A_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_PHASE_CORRECT_TOP_ICR1_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	PWM_PHASE_CORRECT_TOP_OCR1A_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			CLR_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	CTC_TOP_ICR1_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			CLR_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	FAST_PWM_TOP_ICR1_WAVE_GEN
			CLR_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#elif 	TMR1_WAVE_GEN		==	FAST_PWM_TOP_OCR1A_WAVE_GEN
			SET_BIT(TCCR1A_REG,WGM10);
			SET_BIT(TCCR1A_REG,WGM11);
			SET_BIT(TCCR1B_REG,WGM12);
			SET_BIT(TCCR1B_REG,WGM13);
	#endif

	#if 	TMR1_CLK_SELECT		==	NO_CLK
			CLR_BIT(TCCR1B_REG,CS10);
			CLR_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	PRESCALER_0
			SET_BIT(TCCR1B_REG,CS10);
			CLR_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	PRESCALER_8
			CLR_BIT(TCCR1B_REG,CS10);
			SET_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	PRESCALER_64
			SET_BIT(TCCR1B_REG,CS10);
			SET_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	PRESCALER_256
			CLR_BIT(TCCR1B_REG,CS10);
			CLR_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	PRESCALER_1024
			SET_BIT(TCCR1B_REG,CS10);
			CLR_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	EX_CLK_FALLING_EDGE
			CLR_BIT(TCCR1B_REG,CS10);
			SET_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS12);
	#elif TMR1_CLK_SELECT		==	EX_CLK_RISING_EDGE
			SET_BIT(TCCR1B_REG,CS10);
			SET_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS12);
	#endif

	#if 	TMR1A_COMPARE_MATCH		==	NORMAL_COMPARE_MATCH
			CLR_BIT(TCCR1A_REG,COM1A0);
			CLR_BIT(TCCR1A_REG,COM1A1);
	#elif TMR1A_COMPARE_MATCH		==	TOGGLE_OC_COMPARE_MATCH
			SET_BIT(TCCR1A_REG,COM1A0);
			CLR_BIT(TCCR1A_REG,COM1A1);
	#elif TMR1A_COMPARE_MATCH		==	CLR_OC_COMPARE_MATCH
			CLR_BIT(TCCR1A_REG,COM1A0);
			SET_BIT(TCCR1A_REG,COM1A1);
	#elif TMR1A_COMPARE_MATCH		==	SET_OC_COMPARE_MATCH
			SET_BIT(TCCR1A_REG,COM1A0);
			SET_BIT(TCCR1A_REG,COM1A1);
	#endif

	#if 	TMR1B_COMPARE_MATCH		==	NORMAL_COMPARE_MATCH
			CLR_BIT(TCCR1A_REG,COM1B0);
			CLR_BIT(TCCR1A_REG,COM1B1);
	#elif TMR1B_COMPARE_MATCH		==	TOGGLE_OC_COMPARE_MATCH
			SET_BIT(TCCR1A_REG,COM1B0);
			CLR_BIT(TCCR1A_REG,COM1B1);
	#elif TMR1B_COMPARE_MATCH		==	CLR_OC_COMPARE_MATCH
			CLR_BIT(TCCR1A_REG,COM1B0);
			SET_BIT(TCCR1A_REG,COM1B1);
	#elif TMR1B_COMPARE_MATCH		==	SET_OC_COMPARE_MATCH
			SET_BIT(TCCR1A_REG,COM1B0);
			SET_BIT(TCCR1A_REG,COM1B1);
	#endif

	#if 	TMR1_NOISE_CANCELER		==	HIGH
			SET_BIT(TCCR1B_REG,ICNC1);
	#elif TMR1_NOISE_CANCELER		==	LOW
			CLR_BIT(TCCR1B_REG,ICNC1);
	#endif

	#if 	TMR1_IC_EDGE_SELECT		==	RISING_EDGE
			SET_BIT(TCCR1B_REG,ICES1);
	#elif TMR1_IC_EDGE_SELECT		==	FALLING_EDGE
			CLR_BIT(TCCR1B_REG,ICES1);
	#endif

	TCNT1_REG=0x00;
}

void 		TMR1_voidSetPrescaler(u8 TMR1_Prescaler)
{
	switch (TMR1_Prescaler)
	{
		case 		NO_CLK:
				CLR_BIT(TCCR1B_REG,CS10);
				CLR_BIT(TCCR1B_REG,CS11);
				CLR_BIT(TCCR1B_REG,CS12);
				break;
		case 		PRESCALER_0:
				SET_BIT(TCCR1B_REG,CS10);
				CLR_BIT(TCCR1B_REG,CS11);
				CLR_BIT(TCCR1B_REG,CS12);
				break;
		case 		PRESCALER_8:
				CLR_BIT(TCCR1B_REG,CS10);
				SET_BIT(TCCR1B_REG,CS11);
				CLR_BIT(TCCR1B_REG,CS12);
				break;
		case 		PRESCALER_64:
				SET_BIT(TCCR1B_REG,CS10);
				SET_BIT(TCCR1B_REG,CS11);
				CLR_BIT(TCCR1B_REG,CS12);
				break;
		case 		PRESCALER_256:
				CLR_BIT(TCCR1B_REG,CS10);
				CLR_BIT(TCCR1B_REG,CS11);
				SET_BIT(TCCR1B_REG,CS12);
				break;
		case 		PRESCALER_1024:
				SET_BIT(TCCR1B_REG,CS10);
				CLR_BIT(TCCR1B_REG,CS11);
				SET_BIT(TCCR1B_REG,CS12);
				break;
		case 		EX_CLK_FALLING_EDGE:
				CLR_BIT(TCCR1B_REG,CS10);
				SET_BIT(TCCR1B_REG,CS11);
				SET_BIT(TCCR1B_REG,CS12);
				break;
		case 		EX_CLK_RISING_EDGE:
				SET_BIT(TCCR1B_REG,CS10);
				SET_BIT(TCCR1B_REG,CS11);
				SET_BIT(TCCR1B_REG,CS12);
				break;
		}

}

/*					Timer Counter TCNT1 Setter & Getter								*/
u16 		TMR1_u16GetTCNT(void)
{
	return TCNT1_REG;
}

void		TMR1_voidSetTCNT(u16 TCNT1_Preload)
{
	TCNT1_REG=TCNT1_Preload;
}

/*					Timer1 Input Capture Interrupt Enable/Disable			*/
void 		TMR1_voidTICIEnable(void)
{
	SET_BIT(TIMSK_REG,TICIE1);
}
void 		TMR1_voidTICIDisable(void)
{
	CLR_BIT(TIMSK_REG,TICIE1);
}

void		TMR1_voidSetICR(u16 ICR1Value)
{
	ICR1_REG =ICR1Value;
}
u16		TMR1_u16GetICR(void)
{
	return ICR1_REG;
}
void 		TMR1_voidInputCaptureRisingEdge(void)
{
	SET_BIT(TCCR1_REG,ICES1);
}
void 		TMR1_voidInputCaptureFallingEdge(void)
{
	CLR_BIT(TCCR1_REG,ICES1);
}
void    TMR1_voidSetInputCaptureISRFunc(void (*PointertoFunIC1) (void))
{
	TMR1_InputCapture_ISR_CallBack=PointertoFunIC1;
}
void		__vector_6(void)
{
	TMR1_InputCapture_ISR_CallBack();
}

/*					Compare Match Interrupt	OCR1A				*/
void 		TMR1A_voidOCIEnable(void)
{
	SET_BIT(TIMSK_REG,OCIE1A);
}

void 		TMR1A_voidOCIDisable(void)
{
	CLR_BIT(TIMSK_REG,OCIE1A);
}

void		TMR1A_voidSetOCR(u16 OCR1AValue)
{
	OCR1A_REG=OCR1AValue;
}

void    TMR1A_voidSetCompareMatchISRFunc(void (*PointertoFunCM1A) (void))
{
	TMR1A_CompareMatch_ISR_CallBack=PointertoFunCM1A;
}

void		__vector_7(void)
{
	TMR1A_CompareMatch_ISR_CallBack();
}

/*					Compare Match Interrupt	OCR1B				*/
void 		TMR1B_voidOCIEnable(void)
{
	SET_BIT(TIMSK_REG,OCIE1B);
}

void 		TMR1B_voidOCIDisable(void)
{
	CLR_BIT(TIMSK_REG,OCIE1B);
}

void		TMR1B_voidSetOCR(u16 OCR1BValue)
{
	OCR1B_REG=OCR1BValue;
}

void    TMR1B_voidSetCompareMatchISRFunc(void (*PointertoFunCM1B) (void))
{
	TMR1B_CompareMatch_ISR_CallBack=PointertoFunCM1B;
}

void		__vector_8(void)
{
	TMR1B_CompareMatch_ISR_CallBack();
}

/*					Timer1 Overflow Interrupt Enable/Disable			*/
void 		TMR1_voidTOIEnable(void)
{
	SET_BIT(TIMSK_REG,TOIE1);
}
void 		TMR1_voidTOIDisable(void)
{
	CLR_BIT(TIMSK_REG,TOIE1);
}
void    TMR1_voidSetOverflowISRFunc(void (*PointertoFunOF1) (void))
{
	TMR1_Overflow_ISR_CallBack=PointertoFunOF1;
}

void		__vector_9(void)
{
	TMR1_Overflow_ISR_CallBack();
}


/*****************************************************************************/
/***************************   TMR2  8-Bit************************************/


void		TMR2_voidInit(void)
{
	CLR_BIT(TCCR2_REG,FOC2);
	#if 	TMR2_WAVE_GEN		==	NORMAL_WAVE_GEN
			CLR_BIT(TCCR2_REG,WGM20);
			CLR_BIT(TCCR2_REG,WGM21);
	#elif TMR2_WAVE_GEN		==	PWM_WAVE_GEN
			SET_BIT(TCCR2_REG,WGM20);
			CLR_BIT(TCCR2_REG,WGM21);
	#elif TMR2_WAVE_GEN		==	CTC_WAVE_GEN
			CLR_BIT(TCCR2_REG,WGM20);
			SET_BIT(TCCR2_REG,WGM21);
	#elif TMR2_WAVE_GEN		==	FAST_PWM_WAVE_GEN
			SET_BIT(TCCR2_REG,WGM20);
			SET_BIT(TCCR2_REG,WGM21);
	#endif

	#if 	TMR2_COMPARE_MATCH		==	NORMAL_COMPARE_MATCH
			CLR_BIT(TCCR2_REG,COM20);
			CLR_BIT(TCCR2_REG,COM21);
	#elif TMR2_COMPARE_MATCH		==	TOGGLE_OC_COMPARE_MATCH
			SET_BIT(TCCR2_REG,COM20);
			CLR_BIT(TCCR2_REG,COM21);
	#elif TMR2_COMPARE_MATCH		==	CLR_OC_COMPARE_MATCH
			CLR_BIT(TCCR2_REG,COM20);
			SET_BIT(TCCR2_REG,COM21);
	#elif TMR2_COMPARE_MATCH		==	SET_OC_COMPARE_MATCH
			SET_BIT(TCCR2_REG,COM20);
			SET_BIT(TCCR2_REG,COM21);
	#endif

	#if 	TMR2_CLK_SELECT		==	NO_CLK
			CLR_BIT(TCCR2_REG,CS20);
			CLR_BIT(TCCR2_REG,CS21);
			CLR_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	PRESCALER_0
			SET_BIT(TCCR2_REG,CS20);
			CLR_BIT(TCCR2_REG,CS21);
			CLR_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	PRESCALER_8
			CLR_BIT(TCCR2_REG,CS20);
			SET_BIT(TCCR2_REG,CS21);
			CLR_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	PRESCALER_64
			SET_BIT(TCCR2_REG,CS20);
			SET_BIT(TCCR2_REG,CS21);
			CLR_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	PRESCALER_256
			CLR_BIT(TCCR2_REG,CS20);
			CLR_BIT(TCCR2_REG,CS21);
			SET_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	PRESCALER_1024
			SET_BIT(TCCR2_REG,CS20);
			CLR_BIT(TCCR2_REG,CS21);
			SET_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	EX_CLK_FALLING_EDGE
			CLR_BIT(TCCR2_REG,CS20);
			SET_BIT(TCCR2_REG,CS21);
			SET_BIT(TCCR2_REG,CS22);
	#elif TMR2_CLK_SELECT		==	EX_CLK_RISING_EDGE
			SET_BIT(TCCR2_REG,CS20);
			SET_BIT(TCCR2_REG,CS21);
			SET_BIT(TCCR2_REG,CS22);
	#endif
	TCNT2_REG=0x00;
}

void 		TMR2_voidSetPrescaler(u8 TMR2_Prescaler)
{
	switch (TMR2_Prescaler)
	{
		case 		NO_CLK:
				CLR_BIT(TCCR2_REG,CS20);
				CLR_BIT(TCCR2_REG,CS21);
				CLR_BIT(TCCR2_REG,CS22);
				break;
		case 		PRESCALER_0:
				SET_BIT(TCCR2_REG,CS20);
				CLR_BIT(TCCR2_REG,CS21);
				CLR_BIT(TCCR2_REG,CS22);
				break;
		case 		PRESCALER_8:
				CLR_BIT(TCCR2_REG,CS20);
				SET_BIT(TCCR2_REG,CS21);
				CLR_BIT(TCCR2_REG,CS22);
				break;
		case 		PRESCALER_64:
				SET_BIT(TCCR2_REG,CS20);
				SET_BIT(TCCR2_REG,CS21);
				CLR_BIT(TCCR2_REG,CS22);
				break;
		case 		PRESCALER_256:
				CLR_BIT(TCCR2_REG,CS20);
				CLR_BIT(TCCR2_REG,CS21);
				SET_BIT(TCCR2_REG,CS22);
				break;
		case 		PRESCALER_1024:
				SET_BIT(TCCR2_REG,CS20);
				CLR_BIT(TCCR2_REG,CS21);
				SET_BIT(TCCR2_REG,CS22);
				break;
		case 		EX_CLK_FALLING_EDGE:
				CLR_BIT(TCCR2_REG,CS20);
				SET_BIT(TCCR2_REG,CS21);
				SET_BIT(TCCR2_REG,CS22);
				break;
		case 		EX_CLK_RISING_EDGE:
				SET_BIT(TCCR2_REG,CS20);
				SET_BIT(TCCR2_REG,CS21);
				SET_BIT(TCCR2_REG,CS22);
				break;
		}

}

/*					Timer Counter TCNT2 Setter & Getter				*/
u8 			TMR2_u8GetTCNT(void)
{
	return TCNT2_REG;
}

void		TMR2_voidSetTCNT(u8 TCNT2_Preload)
{
	TCNT2_REG=TCNT2_Preload;
}

/*					Compare Match Interrupt	OCR2				*/
void 		TMR2_voidOCIEnable(void)
{
	SET_BIT(TIMSK_REG,OCIE2);
}

void 		TMR2_voidOCIDisable(void)
{
	CLR_BIT(TIMSK_REG,OCIE2);
}

void		TMR2_voidSetOCR(u8 OCR2Value)
{
	OCR2_REG=OCR2Value;
}

void    TMR2_voidSetCompareMatchISRFunc(void (*PointertoFunCM2) (void))
{
	TMR2_CompareMatch_ISR_CallBack=PointertoFunCM2;
}

void		__vector_4(void)
{
	TMR2_CompareMatch_ISR_CallBack();
}

/*					Timer2 Overflow Interrupt Enable/Disable			*/
void 		TMR2_voidTOIEnable(void)
{
	SET_BIT(TIMSK_REG,TOIE2);
}
void 		TMR2_voidTOIDisable(void)
{
	CLR_BIT(TIMSK_REG,TOIE2);
}
void    TMR2_voidSetOverflowISRFunc(void (*PointertoFunOF2) (void))
{
	TMR2_Overflow_ISR_CallBack=PointertoFunOF2;
}

void		__vector_5(void)
{
	TMR2_Overflow_ISR_CallBack();
}
