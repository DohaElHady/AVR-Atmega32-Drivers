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

#endif
