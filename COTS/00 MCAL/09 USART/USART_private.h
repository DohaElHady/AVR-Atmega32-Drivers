#ifndef		USART_PRIVATE_H
#define		USART_PRIVATE_H

#define     ENABLE        1
#define     DISABLE       0

#define     ASYNCH        0
#define     SYNCH         1

#define     USART_CHARACTER_SIZE_5      5
#define     USART_CHARACTER_SIZE_6      6
#define     USART_CHARACTER_SIZE_7      7
#define     USART_CHARACTER_SIZE_8      8
#define     USART_CHARACTER_SIZE_9      9

#define     USART_PARITY_DISABLE        0
#define     USART_PARITY_EN_EVEN        2
#define     USART_PARITY_EN_ODD         3

#define     USART_STOPBIT_1             1
#define     USART_STOPBIT_2             2

#define     UDR_REG       *((volatile u8 *)0x2C)    //Data I/O Reg
#define     UCSRA_REG     *((volatile u8 *)0x2B)    //Control Reg
#define     UCSRB_REG     *((volatile u8 *)0x2A)
#define     UCSRC_REG     *((volatile u8 *)0x40)
#define     UBRRL_REG     *((volatile u8 *)0x29)
#define     UBRRH_REG     *((volatile u8 *)0x40)



/*        UCSRA_REG Pins    */
#define       MPCM          0
#define       U2X           1 //0 for Normal Baud & 1 for double speed
#define       PE            2
#define       DOR           3
#define       FE            4
#define       UDRE          5
#define       TXC           6 //Flag for sending data complete
#define       RXC           7 //Flag for recieving data complete

/*        UCSRB_REG Pins    */
#define       TXB8          0
#define       RXB8          1
#define       UCSZ2         2
#define       TXEN          3 // Transmitter Enable
#define       RXEN          4 // Reciever Enable
#define       UDRIE         5
#define       TXCIE         6
#define       RXCIE         7

/*        UCSRC_REG Pins    */
#define       UCPOL         0
#define       UCSZ0         1
#define       UCSZ1         2
#define       USBS          3 // StopBit Select
#define       UPM0          4
#define       UPM1          5
#define       UMSEL         6 // Mode Select 0>Async / 1>Sync
#define       URSEL         7
#endif
