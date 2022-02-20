#ifndef		ADC_PRIVATE_H
#define		ADC_PRIVATE_H


#define			ADMUX_REG			*((volatile u8 *)0x27)
#define			ADCSRA_REG		*((volatile u8 *)0x26)
#define			ADCH_REG			*((volatile u8 *)0x25)
#define			ADCL_REG			*((volatile u8 *)0x24)
#define			ADC_REG				*((volatile u16 *)0x24)
#define			SFIOR_REG			*((volatile u8 *)0x50)

#define 		ADC_AVCC							1
#define 		ADC_INTERNAL					3
#define 		ADC_AREF							5

#define 		ADC_DIV_2							1
#define 		ADC_DIV_4							3
#define 		ADC_DIV_8							5
#define 		ADC_DIV_16						7
#define 		ADC_DIV_32						9
#define 		ADC_DIV_64						11
#define 		ADC_DIV_128						13

/* ADC CONTROL REG ADCSRA */
#define     ADPS0         0
#define     ADPS1         1
#define     ADPS2         2
#define     ADIE          3
#define     ADIF          4
#define     ADATE         5
#define     ADSC          6
#define     ADEN          7

/*        ADMUX REG      */
#define     MUX0          0
#define     MUX1          1
#define     MUX2          2
#define     MUX3          3
#define     MUX4          4
#define     ADLAR         5
#define     REF0          6
#define     REF1          7



#endif
