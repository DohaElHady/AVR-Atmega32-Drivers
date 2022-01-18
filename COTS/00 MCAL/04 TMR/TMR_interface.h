#ifndef		TMR_INTERFACE_H
#define		TMR_INTERFACE_H

/*****************************************************************************/
/***************************   TMR0  8-Bit************************************/
void		TMR0_voidInit(void);
void 		TMR0_voidSetPrescaler(u8 TMR0_Prescaler);

u8 			TMR0_u8GetTCNT(void);
void		TMR0_voidSetTCNT(u8 TCNT0_Preload);

void 		TMR0_voidOCIEnable(void);
void 		TMR0_voidOCIDisable(void);
void		TMR0_voidSetOCR(u8 OCR0Value);
void    TMR0_voidSetCompareMatchISRFunc(void (*PointertoFunCM0) (void));
void		__vector_10(void)     __attribute__((signal,used));

void 		TMR0_voidTOIEnable(void);
void 		TMR0_voidTOIDisable(void);
void    TMR0_voidSetOverflowISRFunc(void (*PointertoFunOF0) (void));
void		__vector_11(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************   TMR1  16-Bit***********************************/

void		TMR1_voidInit(void);
void 		TMR1_voidSetPrescaler(u8 TMR1_Prescaler);

u16 		TMR1_u16GetTCNT(void);
void		TMR1_voidSetTCNT(u16 TCNT1_Preload);

void 		TMR1_voidTICIEnable(void);
void 		TMR1_voidTICIDisable(void);
void		TMR1_voidSetICR(u16 ICR1Value);
u16     TMR1_u16GetICR(void);
void 		TMR1_voidInputCaptureRisingEdge(void);
void 		TMR1_voidInputCaptureFallingEdge(void);
void    TMR1_voidSetInputCaptureISRFunc(void (*PointertoFunIC1) (void));
void		__vector_6(void)     __attribute__((signal,used));

void 		TMR1A_voidOCIEnable(void);
void 		TMR1A_voidOCIDisable(void);
void		TMR1A_voidSetOCR(u16 OCR1AValue);
void    TMR1A_voidSetCompareMatchISRFunc(void (*PointertoFunCM1A) (void));
void		__vector_7(void)     __attribute__((signal,used));

void 		TMR1B_voidOCIEnable(void);
void 		TMR1B_voidOCIDisable(void);
void		TMR1B_voidSetOCR(u16 OCR1BValue);
void    TMR1B_voidSetCompareMatchISRFunc(void (*PointertoFunCM1B) (void));
void		__vector_8(void)     __attribute__((signal,used));

void 		TMR1_voidTOIEnable(void);
void 		TMR1_voidTOIDisable(void);
void    TMR1_voidSetOverflowISRFunc(void (*PointertoFunOF1) (void));
void		__vector_9(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************   TMR0  8-Bit************************************/
void		TMR2_voidInit(void);
void 		TMR2_voidSetPrescaler(u8 TMR2_Prescaler);

u8      TMR2_u8GetTCNT(void);
void		TMR2_voidSetTCNT(u8 TCNT2_Preload);

void 		TMR2_voidOCIEnable(void);
void 		TMR2_voidOCIDisable(void);
void		TMR2_voidSetOCR(u8 OCR2Value);
void    TMR2_voidSetCompareMatchISRFunc(void (*PointertoFunCM2) (void));
void		__vector_4(void)     __attribute__((signal,used));

void 		TMR2_voidTOIEnable(void);
void 		TMR2_voidTOIDisable(void);
void    TMR2_voidSetOverflowISRFunc(void (*PointertoFunOF2) (void));
void		__vector_5(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************   General Configs********************************/
/*           TMR_COMPARE_MATCH Modes          */
#define      NORMAL_COMPARE_MATCH              0
#define      TOGGLE_OC_COMPARE_MATCH           1
#define      CLR_OC_COMPARE_MATCH              2
#define      SET_OC_COMPARE_MATCH              3

/*          TMR_WAVE_GEN Modes                */
#define      NORMAL_WAVE_GEN                   0
#define      PWM_WAVE_GEN                      1
#define      CTC_WAVE_GEN                      2
#define      FAST_PWM_WAVE_GEN                 3
/*          Special TMR1_WAVE_GEN Modes        */
#define      PWM_8BIT_WAVE_GEN                 4
#define      PWM_9BIT_WAVE_GEN                 5
#define      PWM_10BIT_WAVE_GEN                6
#define      FAST_PWM_8BIT_WAVE_GEN            7
#define      FAST_PWM_9BIT_WAVE_GEN            8
#define      FAST_PWM_10BIT_WAVE_GEN           9
#define      CTC_TOP_OCR1A_WAVE_GEN            10
#define      CTC_TOP_ICR1_WAVE_GEN             11
#define      FAST_PWM_TOP_ICR1_WAVE_GEN        12
#define      FAST_PWM_TOP_OCR1A_WAVE_GEN       13
#define      PWM_PHASE_FREQ_CORRECT_TOP_ICR1_WAVE_GEN           14
#define      PWM_PHASE_FREQ_CORRECT_TOP_OCR1A_WAVE_GEN          15
#define      PWM_PHASE_CORRECT_TOP_ICR1_WAVE_GEN                16
#define      PWM_PHASE_CORRECT_TOP_OCR1A_WAVE_GEN               17

/*          TMR_CLK_SELECT Modes              */
#define      NO_CLK                            0
#define      PRESCALER_0                       1
#define      PRESCALER_8                       2
#define      PRESCALER_64                      3
#define      PRESCALER_256                     4
#define      PRESCALER_1024                    5
#define      EX_CLK_FALLING_EDGE               6
#define      EX_CLK_RISING_EDGE                7

#define      FALLING_EDGE       0
#define      RISING_EDGE        1

#endif
