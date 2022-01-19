#ifndef		SERVO_INTERFACE_H
#define		SERVO_INTERFACE_H
/*****************************************************************************/
/***************************  TMR_PWM ****************************************/

void	Servo_voidInit_TMR1PWM(void);
void	Servo_voidSetAngle_TMR1PWM(u8 Angle);
/*****************************************************************************/
/***************************  SW_PWM *****************************************/

void	Servo_voidInit_SWPWM(void);
void	Servo_voidSetAngle_SWPWM(u8 Angle);

#endif
