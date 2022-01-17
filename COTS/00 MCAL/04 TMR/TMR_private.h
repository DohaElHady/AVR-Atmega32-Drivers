#ifndef		TMR_PRIVATE_H
#define		TMR_PRIVATE_H


#define     TIMSK_REG     *((volatile u8 *)0x59)    //Interrupts Enable Reg
#define     TIFR_REG      *((volatile u8 *)0x59)    //Interrupts Flag Reg

/*****************************************************************************/
/***************************   TMR0  8-Bit************************************/
#define		  TCCR0_REG			*((volatile u8 *)0x53)
#define     TCNT0_REG     *((volatile u8 *)0x52)
#define     OCR0_REG      *((volatile u8 *)0x5C)    // Output Compare Reg


/*        TCCR0_REG Pins    */
#define       CS00          0
#define       CS01          1
#define       CS02          2
#define       WGM01         3
#define       COM00         4
#define       COM01         5
#define       WGM00         6
#define       FOC0          7
/*        TIMSK_REG Pins    */
#define       TOIE0         0
#define       OCIE0         1

/*        TIFR_REG Pins     */
#define       TOV0          0
#define       OCF0          1

/*****************************************************************************/
/***************************   TMR1  16-Bit***********************************/
#define			TCCR1A_REG		*((volatile u8 *)0x4F)
#define			TCCR1B_REG		*((volatile u8 *)0x4E)
#define			TCCR1_REG		  *((volatile u16 *)0x4E)    // ShortCut to the two TCCR1 Reg.
#define     TCNT1_REG     *((volatile u16 *)0x4C)    //u16 > 2 Reg.(high/low)
#define     OCR1A_REG     *((volatile u16 *)0x4A)
#define     OCR1B_REG     *((volatile u16 *)0x48)
#define     ICR1_REG      *((volatile u16 *)0x46)

/*        TCCR1_REG Pins    */
#define       WGM10         0
#define       WGM11         1
#define       FOC1B         2
#define       FOC1A         3
#define       COM1B0        4
#define       COM1B1        5
#define       COM1A0        6
#define       COM1A1        7
#define       CS10          8
#define       CS11          9
#define       CS12          10
#define       WGM12         11
#define       WGM13         12
#define       ICES1         14
#define       ICNC1         15

/*        TIMSK_REG Pins    */
#define       TOIE1         2
#define       OCIE1A        3
#define       OCIE1B        4
#define       TICIE1        5

/*        TIFR_REG Pins     */
#define       TOV1          2
#define       OCF1B         3
#define       OCF1A         4
#define       ICF1          5


/*****************************************************************************/
/***************************   TMR2  8-Bit************************************/
#define		  TCCR2_REG			*((volatile u8 *)0x45)
#define     TCNT2_REG     *((volatile u8 *)0x44)
#define     OCR2_REG      *((volatile u8 *)0x43)    // Output Compare Reg
#define		  ASSR_REG			*((volatile u8 *)0x42)
#define		  SFIOR_REG			*((volatile u8 *)0x50)


/*        TCCR2_REG Pins    */
#define       CS20          0
#define       CS21          1
#define       CS22          2
#define       WGM21         3
#define       COM20         4
#define       COM21         5
#define       WGM20         6
#define       FOC2          7

/*        TIMSK_REG Pins    */
#define       TOIE2         6
#define       OCIE2         7

/*        TIFR_REG Pins     */
#define       TOV2          6
#define       OCF2          7
/*****************************************************************************/
/***************************   General Configs********************************/
/*           TMR_COMPARE_MATCH Modes          */
#define      NORMAL_COMPARE_MATCH              0
#define      TOGGLE_OC_COMPARE_MATCH           1
#define      CLR_OC_COMPARE_MATCH              2
#define      SET_OC_COMPARE_MATCH              3

/*          TMR_CLK_SELECT Modes              */
#define      NO_CLK                            0
#define      PRESCALER_0                       1
#define      PRESCALER_8                       2
#define      PRESCALER_64                      3
#define      PRESCALER_256                     4
#define      PRESCALER_1024                    5
#define      EX_CLK_FALLING_EDGE               6
#define      EX_CLK_RISING_EDGE                7

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


#endif
