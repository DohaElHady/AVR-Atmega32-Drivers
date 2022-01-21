#ifndef		IC_EXTI_INTERFACE_H
#define		IC_EXTI_INTERFACE_H

void	    IC_EXTI_TMROVFISR(void);
void	    IC_EXTI_ISR(void);
u16       IC_EXTI_u16GetFreq(void);
u16       IC_EXTI_u16GetDutyCycle(void);

#endif
