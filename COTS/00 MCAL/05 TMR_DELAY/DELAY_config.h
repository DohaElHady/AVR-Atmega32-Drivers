#ifndef		DELAY_CONFIG_H
#define		DELAY_CONFIG_H

#ifndef				F_CPU
#define				F_CPU				16000000UL
#endif

/*******************************************************************
DELAY_TMR_SELECT Modes can be:
                  TMR0_DELAY
                  TMR2_DELAY
******************************************************************/
#define     DELAY_TMR_SELECT    TMR2_DELAY
/*
Based on TMR_Select, Edit the TMR_config.h file as follow:
              if          DELAY_TMR_SELECT == TMR0_DELAY:
                  #define			TMR0_CLK_SELECT         PRESCALER_1024
                  #define			TMR0_WAVE_GEN           NORMAL_WAVE_GEN
                  #define			TMR0_COMPARE_MATCH      NORMAL_COMPARE_MATCH
              else if     DELAY_TMR_SELECT == TMR2_DELAY:
                  #define			TMR2_CLK_SELECT         PRESCALER_1024
                  #define			TMR2_WAVE_GEN           NORMAL_WAVE_GEN
                  #define			TMR2_COMPARE_MATCH      NORMAL_COMPARE_MATCH

*/



#endif
