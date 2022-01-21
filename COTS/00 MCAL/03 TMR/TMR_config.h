#ifndef		TMR_CONFIG_H
#define		TMR_CONFIG_H


/*****************************************************************************/
/***************************   TMR0  *****************************************/

/****************************************************************
TMR0_CLK_SELECT Modes can be:
                        NO_CLK
                        PRESCALER_0
                        PRESCALER_8
                        PRESCALER_64
                        PRESCALER_256
                        PRESCALER_1024
                        EX_CLK_FALLING_EDGE
                        EX_CLK_RISING_EDGE
****************************************************************/
#define			TMR0_CLK_SELECT         PRESCALER_1024
/****************************************************************
TMR0_WAVE_GEN Modes can be:
                        NORMAL_WAVE_GEN
                        PWM_WAVE_GEN
                        CTC_WAVE_GEN
                        FAST_PWM_WAVE_GEN
****************************************************************/
#define			TMR0_WAVE_GEN         NORMAL_WAVE_GEN
/****************************************************************
TMR0_COMPARE_MATCH Modes can be:
                        NORMAL_COMPARE_MATCH
                        TOGGLE_OC_COMPARE_MATCH (only at non-PWM)
                        CLR_OC_COMPARE_MATCH
                        SET_OC_COMPARE_MATCH
****************************************************************/
#define			TMR0_COMPARE_MATCH     NORMAL_COMPARE_MATCH


/*****************************************************************************/
/***************************   TMR1  16-Bit***********************************/

/****************************************************************
TMR1A_COMPARE_MATCH Modes can be:
                        NORMAL_COMPARE_MATCH
                        TOGGLE_OC_COMPARE_MATCH
                        CLR_OC_COMPARE_MATCH  (Non-inverting PWM)
                        SET_OC_COMPARE_MATCH  (Inverting PWM)
****************************************************************/
#define			TMR1A_COMPARE_MATCH     CLR_OC_COMPARE_MATCH
/****************************************************************
TMR1B_COMPARE_MATCH Modes can be:
                        NORMAL_COMPARE_MATCH
                        TOGGLE_OC_COMPARE_MATCH
                        CLR_OC_COMPARE_MATCH  (Non-inverting PWM)
                        SET_OC_COMPARE_MATCH  (Inverting PWM)
****************************************************************/
#define			TMR1B_COMPARE_MATCH     NORMAL_COMPARE_MATCH
/****************************************************************
TMR1_WAVE_GEN Modes can be:
                        NORMAL_WAVE_GEN
                        PWM_8BIT_WAVE_GEN
                        PWM_9BIT_WAVE_GEN
                        PWM_10BIT_WAVE_GEN
                        CTC_TOP_OCR1A_WAVE_GEN
                        FAST_PWM_8BIT_WAVE_GEN
                        FAST_PWM_9BIT_WAVE_GEN
                        FAST_PWM_10BIT_WAVE_GEN
                        PWM_PHASE_FREQ_CORRECT_TOP_ICR1_WAVE_GEN
                        PWM_PHASE_FREQ_CORRECT_TOP_OCR1A_WAVE_GEN
                        PWM_PHASE_CORRECT_TOP_ICR1_WAVE_GEN
                        PWM_PHASE_CORRECT_TOP_OCR1A_WAVE_GEN
                        CTC_TOP_ICR1_WAVE_GEN
                        FAST_PWM_TOP_ICR1_WAVE_GEN
                        FAST_PWM_TOP_OCR1A_WAVE_GEN
****************************************************************/
#define			TMR1_WAVE_GEN         FAST_PWM_TOP_ICR1_WAVE_GEN
/****************************************************************
TMR1_CLK_SELECT Modes can be:
                        NO_CLK
                        PRESCALER_0
                        PRESCALER_8
                        PRESCALER_64
                        PRESCALER_256
                        PRESCALER_1024
                        EX_CLK_FALLING_EDGE
                        EX_CLK_RISING_EDGE
****************************************************************/
#define			TMR1_CLK_SELECT         PRESCALER_64
/***************************************************************
TMR1_NOISE_CANCELER Modes can be:
                        HIGH
                        LOW
***************************************************************/
#define     TMR1_NOISE_CANCELER      HIGH

/***************************************************************
TMR1_IC_EDGE_SELECT Modes can be:
                        FALLING_EDGE
                        RISING_EDGE
***************************************************************/
#define     TMR1_IC_EDGE_SELECT     FALLING_EDGE


/*****************************************************************************/
/***************************   TMR2  *****************************************/

/****************************************************************
TMR2_CLK_SELECT Modes can be:
                        NO_CLK
                        PRESCALER_0
                        PRESCALER_8
                        PRESCALER_64
                        PRESCALER_256
                        PRESCALER_1024
                        EX_CLK_FALLING_EDGE
                        EX_CLK_RISING_EDGE
****************************************************************/
#define			TMR2_CLK_SELECT         PRESCALER_1024
/****************************************************************
TMR2_WAVE_GEN Modes can be:
                        NORMAL_WAVE_GEN
                        PWM_WAVE_GEN
                        CTC_WAVE_GEN
                        FAST_PWM_WAVE_GEN
****************************************************************/
#define			TMR2_WAVE_GEN         NORMAL_WAVE_GEN
/****************************************************************
TMR2_COMPARE_MATCH Modes can be:
                        NORMAL_COMPARE_MATCH
                        TOGGLE_OC_COMPARE_MATCH (only at non-PWM)
                        CLR_OC_COMPARE_MATCH
                        SET_OC_COMPARE_MATCH
****************************************************************/
#define			TMR2_COMPARE_MATCH     NORMAL_COMPARE_MATCH


#endif
