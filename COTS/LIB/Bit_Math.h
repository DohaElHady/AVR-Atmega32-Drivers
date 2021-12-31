#ifndef BIT_MATH_H
#define BIT_MATH_H

#define  SET_BIT(REG,BIT_NUM)             REG |=   (1<<BIT_NUM)
#define  CLR_BIT(REG,BIT_NUM)             REG &= ~ (1<<BIT_NUM)
#define  TOG_BIT(REG,BIT_NUM)             REG ^=   (1<<BIT_NUM)
#define  GET_BIT(REG,BIT_NUM)             ((REG>>BIT_NUM) &1)
#define  CIR_SHIFT_L_BIT(REG)             REG  =   (GET_BIT(REG,7) | (REG<<1))
#define  CIR_SHIFT_R_BIT(REG)             REG  =   ((GET_BIT(REG,0) << 7) | (REG>>1))
#define  SET_NIBBLE(REG,CASE)             REG |=   (0x0F<<(4*CASE))
#define  CLR_NIBBLE(REG,CASE)             REG &=   (0xF0>>(4*CASE))
#define  ASG_NIBBLE(REG,CASE,VALUE)		REG  =	 (CASE==0?((REG&0xF0)|(VALUE&0x0F)):((REG&0x0F)|(VALUE&0xF0)))
#define  SET_PORT(REG)                    REG  =   (0xFF)
#define  CLR_PORT(REG)                    REG  =   (0x00)
#define  ASG_PORT(REG,VALUE)				REG	 =	 (VALUE)


#endif
