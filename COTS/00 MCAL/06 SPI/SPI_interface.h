#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H

void		SPI_voidInit(void);

/*****************************************************************************/
/***************************	   SPI Control	********************************/
void		SPI_voidEnable(void);
void		SPI_voidDisable(void);

/*****************************************************************************/
/***************************  	SPI	Interrupt	********************************/
void		SPI_voidInterruptEnable(void);
void		SPI_voidInterruptDisable(void);
void    SPI_voidISRFunc(void (*PointertoFunSPI) (void));
void		__vector_12(void)     __attribute__((signal,used));

/*****************************************************************************/
/***************************   DATA	  ****************************************/
void 		SPI_voidSendu8Data(u8 SPI_Data);
u8 			SPI_u8RecieveData(void);



#endif
