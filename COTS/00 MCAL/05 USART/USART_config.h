#ifndef		USART_CONFIG_H
#define		USART_CONFIG_H

#ifndef     F_CPU
#define     F_CPU             16000000UL
#endif
#define			USART_BAUD              103

#define     USART_MULTI_PROCESSOR_COMM    LOW
#define     USART_DOUBLE_TRAN_SPEED       LOW

/*
USART_RX_MODE can be:
              ENABLE
              DISABLE
*/
#define     USART_RX_MODE         ENABLE
/*
USART_TX_MODE can be:
              ENABLE
              DISABLE
*/
#define     USART_TX_MODE         ENABLE
/*
USART_CHARACTER_SIZE can be:
              USART_CHARACTER_SIZE_5
              USART_CHARACTER_SIZE_6
              USART_CHARACTER_SIZE_7
              USART_CHARACTER_SIZE_8
              USART_CHARACTER_SIZE_9
*/
#define     USART_CHARACTER_SIZE    USART_CHARACTER_SIZE_8
/*
USART_PARITY can be:
              USART_PARITY_DISABLE
              USART_PARITY_EN_EVEN
              USART_PARITY_EN_ODD
*/
#define     USART_PARITY         USART_PARITY_DISABLE
/*
USART_STOPBIT can be:
              USART_STOPBIT_1
              USART_STOPBIT_2
*/
#define     USART_STOPBIT        USART_STOPBIT_1

/*
USART_MODE can be:
              ASYNCH
              SYNCH
*/
#define     USART_MODE         ASYNCH

#endif
