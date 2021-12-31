#ifndef		HBRIDGE_INTERFACE_H
#define		HBRIDGE_INTERFACE_H

void	HB_voidInit(u8 M1Mode, u8 M2Mode);
void	HB_voidMotorDir(u8 MotorNum, u8 Direction);
void	HB_voidMotorEn(u8 MotorNum, u8 MotorMode);

#define		ON		1
#define		OFF		0
#define		RIGHT	1
#define		LEFT	0

#endif