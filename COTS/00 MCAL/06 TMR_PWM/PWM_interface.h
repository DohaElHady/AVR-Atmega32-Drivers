#ifndef		PWM_INTERFACE_H
#define		PWM_INTERFACE_H
void	    PWM_voidSetDutyCycle(u8 PwmDutyCycle,u8 PWM_TMRSelect);
void	    PWM_TopICR1_voidSetFreq(u8 PwmFreq);
void	    PWM_TopICR1_voidSetDutyCycle(u8 PwmDutyCycle); // 0>100

#define       TMR0_PWM                  0x00
#define       TMR1A_PWM                 0x1A
#define       TMR1B_PWM                 0x1B
#define       TMR2_PWM                  0x02
#define		  PWM_TOPICR1_PRESCALER			64
#endif
