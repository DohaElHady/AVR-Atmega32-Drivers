#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"USART_interface.h"
#include		"USART_private.h"
#include		"USART_config.h"

#ifndef			NULL
#define			NULL			(void*)0
#endif

static void (*USART_DataEmpty_ISR_CallBack) 			(void)=NULL;
static void (*USART_TxComplete_ISR_CallBack) 			(void)=NULL;
static void (*USART_RxComplete_ISR_CallBack) 			(void)=NULL;


void		USART_voidInit(void)
{
	/*		Write in UBRRH Active */
	CLR_BIT(UCSRC_REG,URSEL);

	UBRRH_REG=(u8)	(USART_BAUD>>8);
	UBRRL_REG=(u8) 	(USART_BAUD);

	#if 		USART_DOUBLE_TRAN_SPEED		==	LOW
		CLR_BIT(UCSRA_REG,U2X);
	#elif 	USART_DOUBLE_TRAN_SPEED		==	HIGH
		SET_BIT(UCSRA_REG,U2X);
	#endif

	#if 		USART_MULTI_PROCESSOR_COMM		==	LOW
		CLR_BIT(UCSRA_REG,MPCM);
	#elif 	USART_MULTI_PROCESSOR_COMM		==	HIGH
		SET_BIT(UCSRA_REG,MPCM);
	#endif

	#if 		USART_RX_MODE		== ENABLE
		SET_BIT(UCSRB_REG,RXEN);
	#elif		USART_RX_MODE		== DISABLE
		CLR_BIT(UCSRB_REG,RXEN);
	#endif

	#if 		USART_TX_MODE		== ENABLE
		SET_BIT(UCSRB_REG,TXEN);
	#elif		USART_TX_MODE		== DISABLE
		CLR_BIT(UCSRB_REG,TXEN);
	#endif

	/*		Write in UCSRC Active */
	SET_BIT(UCSRC_REG,URSEL);

	#if 		USART_CHARACTER_SIZE == USART_CHARACTER_SIZE_5
		CLR_BIT(UCSRC_REG,UCSZ0);
		CLR_BIT(UCSRC_REG,UCSZ1);
		CLR_BIT(UCSRB_REG,UCSZ2);
	#elif 	USART_CHARACTER_SIZE == USART_CHARACTER_SIZE_6
		SET_BIT(UCSRC_REG,UCSZ0);
		CLR_BIT(UCSRC_REG,UCSZ1);
		CLR_BIT(UCSRB_REG,UCSZ2);
	#elif 	USART_CHARACTER_SIZE == USART_CHARACTER_SIZE_7
		CLR_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
		CLR_BIT(UCSRB_REG,UCSZ2);
	#elif 	USART_CHARACTER_SIZE == USART_CHARACTER_SIZE_8
		SET_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
		CLR_BIT(UCSRB_REG,UCSZ2);
	#elif 	USART_CHARACTER_SIZE == USART_CHARACTER_SIZE_9
		SET_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
		SET_BIT(UCSRB_REG,UCSZ2);
	#endif

	#if 		USART_PARITY  == USART_PARITY_DISABLE
		CLR_BIT(UCSRC_REG,UPM0);
		CLR_BIT(UCSRC_REG,UPM1);
	#elif 	USART_PARITY  == USART_PARITY_EN_EVEN
		CLR_BIT(UCSRC_REG,UPM0);
		SET_BIT(UCSRC_REG,UPM1);
	#elif 	USART_PARITY  == USART_PARITY_EN_ODD
		SET_BIT(UCSRC_REG,UPM0);
		SET_BIT(UCSRC_REG,UPM1);
	#endif

	#if 		USART_STOPBIT  == USART_STOPBIT_1
		CLR_BIT(UCSRC_REG,USBS);
	#elif 	USART_STOPBIT  == USART_STOPBIT_2
		SET_BIT(UCSRC_REG,USBS);
	#endif

	#if 		USART_MODE 		== ASYNCH
		CLR_BIT(UCSRC_REG,UMSEL);
	#elif		USART_MODE 		== SYNCH
		SET_BIT(UCSRC_REG,UMSEL);
	#endif

}

/*****************************************************************************/
/***************************	   Rx	Interrupt	********************************/
void		USART_voidRXIEnable(void)
{
		SET_BIT(UCSRB_REG,RXCIE);
}
void		USART_voidRXIDisable(void)
{
		CLR_BIT(UCSRB_REG,RXCIE);
}
void    USART_voidRxCompleteISRFunc(void (*PointertoFunRxC) (void))
{
	USART_RxComplete_ISR_CallBack=PointertoFunRxC;
}
void		__vector_13(void)
{
	USART_RxComplete_ISR_CallBack();
}
/*****************************************************************************/
/***************************  	Tx	Interrupt	********************************/

void		USART_voidTXIEnable(void)
{
		SET_BIT(UCSRB_REG,TXCIE);
}
void		USART_voidTXIDisable(void)
{
		CLR_BIT(UCSRB_REG,TXCIE);
}
void    USART_voidTxCompleteISRFunc(void (*PointertoFunTxC) (void))
{
	USART_TxComplete_ISR_CallBack=PointertoFunTxC;
}

void		__vector_15(void)
{
	USART_TxComplete_ISR_CallBack();
}
/*****************************************************************************/
/***************************   UDR	Interrupt	********************************/

void		USART_voidUDREnable(void)
{
		SET_BIT(UCSRB_REG,UDRIE);
}
void		USART_voidUDRDisable(void)
{
		CLR_BIT(UCSRB_REG,UDRIE);
}
void    USART_voidDataEmptyISRFunc(void (*PointertoFunUDR) (void))
{
	USART_DataEmpty_ISR_CallBack=PointertoFunUDR;
}
void		__vector_14(void)
{
	USART_DataEmpty_ISR_CallBack();
}
/*****************************************************************************/
/******************************  Tx/Rx	**************************************/

u8 			USART_u8RecieveData(void)
{
	while(!(UCSRA_REG&(1<<RXC)));
	return UDR_REG;
}

void 		USART_voidSendu8Data(u8 Data)
{
	while(! (UCSRA_REG&(1<<UDRE)) );
	UDR_REG=Data;
}

u8 			USART_u8Recieve9thBit(void)
{
	while(!(UCSRA_REG&(1<<RXC)));
	return 0x00 & GET_BIT(UCSRB_REG,RXB8);
}

void 		USART_voidSend9thBit(u8 Data9thBit)
{
	if (Data9thBit==1)
	{
		SET_BIT(UCSRB_REG,TXB8);
	}
	else
	{
		CLR_BIT(UCSRB_REG,TXB8);
	}
}
