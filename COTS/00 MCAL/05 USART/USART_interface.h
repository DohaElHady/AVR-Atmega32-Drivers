#ifndef		USART_INTERFACE_H
#define		USART_INTERFACE_H

void		USART_voidInit(void);

/*****************************************************************************/
/***************************	   Rx	Interrupt	********************************/
void		USART_voidRXIEnable(void);
void		USART_voidRXIDisable(void);
void    USART_voidRxCompleteISRFunc(void (*PointertoFunRxC) (void));
void		__vector_13(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************  	Tx	Interrupt	********************************/
void		USART_voidTXIEnable(void);
void		USART_voidTXIDisable(void);
void    USART_voidTxCompleteISRFunc(void (*PointertoFunTxC) (void));
void		__vector_15(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************   UDR	Interrupt	********************************/
void		USART_voidUDREnable(void);
void		USART_voidUDRDisable(void);
void    USART_voidDataEmptyISRFunc(void (*PointertoFunUDR) (void));
void		__vector_14(void)     __attribute__((signal,used));

/*****************************************************************************/
/******************************  Tx/Rx	**************************************/

u8 			USART_u8RecieveData(void);
void 		USART_voidSendu8Data(u8 Data);

u8 			USART_u8Recieve9thBit(void);
void 		USART_voidSend9thBit(u8 Data9thBit);


#endif
