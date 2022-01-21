#include		"Std_Types.h"
#include		"Bit_Math.h"
#include 		"DIO_interface.h"
#include		"SPI_interface.h"
#include		"SPI_private.h"
#include		"SPI_config.h"

#ifndef			NULL
#define			NULL			(void*)0
#endif

static void (*SPI_ISR_CallBack) 			(void)=NULL;


void		SPI_voidInit(void)
{

	#if 		SPI_DORD_MODE		==	SPI_DORD_MSB
		CLR_BIT(SPCR_REG, DORD);
	#elif 	SPI_DORD_MODE		==	SPI_DORD_LSB
		SET_BIT(SPCR_REG, DORD);
	#endif

	#if 		SPI_MSTR_MODE		==	SPI_SLAVE
		CLR_BIT(SPCR_REG, MSTR);
		DIO_voidSetPinDirection(SPI_PORT,SPI_SS,INPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_SCK,INPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_MOSI,INPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_MISO,OUTPUT);
	#elif 	SPI_MSTR_MODE		==	SPI_MASTER
		SET_BIT(SPCR_REG, MSTR);
		DIO_voidSetPinDirection(SPI_PORT,SPI_SS,OUTPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_SCK,OUTPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_MOSI,OUTPUT);
		DIO_voidSetPinDirection(SPI_PORT,SPI_MISO,INPUT);
	#endif

	#if 		SPI_CLK_POLARITY		==	SPI_CLK_POLARITY_RISING_LEAD
		CLR_BIT(SPCR_REG, CPOL);
	#elif 	SPI_CLK_POLARITY		==	SPI_CLK_POLARITY_FALLING_LEAD
		SET_BIT(SPCR_REG, CPOL);
	#endif

	#if 		SPI_CLK_PHASE		==	SPI_CLK_PHASE_SAMPLE_LEAD
		CLR_BIT(SPCR_REG, CPHA);
	#elif 	SPI_CLK_PHASE		==	SPI_CLK_PHASE_SETUP_LEAD
		SET_BIT(SPCR_REG, CPHA);
	#endif

	#if 		SPI_SCK_MODE == SPI_SCK_FOSC_DIV_4
		CLR_BIT(SPCR_REG,SPR0);
		CLR_BIT(SPCR_REG,SPR1);
		CLR_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_16
		SET_BIT(SPCR_REG,SPR0);
		CLR_BIT(SPCR_REG,SPR1);
		CLR_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_64
		CLR_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,UCSZ1);
		CLR_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_128
		SET_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,SPR1);
		CLR_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_2_SP2X
		SET_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,SPR1);
		SET_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_8_SP2X
		SET_BIT(SPCR_REG,SPR0);
		CLR_BIT(SPCR_REG,SPR1);
		SET_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_32_SP2X
		CLR_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,UCSZ1);
		SET_BIT(SPSR_REG,SPI2X);
	#elif 	SPI_SCK_MODE == SPI_SCK_FOSC_DIV_64_SP2X
		SET_BIT(SPCR_REG,SPR0);
		SET_BIT(SPCR_REG,SPR1);
		SET_BIT(SPSR_REG,SPI2X);
	#endif

}

/*****************************************************************************/
/***************************	   SPI Control	********************************/

void		SPI_voidEnable(void)
{
		SET_BIT(SPCR_REG,SPE);
}
void		SPI_voidDisable(void)
{
		CLR_BIT(SPCR_REG,SPE);
}

/*****************************************************************************/
/***************************  	SPI	Interrupt	********************************/

void		SPI_voidInterruptEnable(void)
{
		SET_BIT(SPCR_REG,SPIE);
}
void		SPI_voidInterruptDisable(void)
{
		CLR_BIT(SPCR_REG,SPIE);
}
void 		SPI_voidISRFunc(void (*PointertoFunSPI) (void))
{
	SPI_ISR_CallBack=PointertoFunSPI;
}

void		__vector_12(void)
{
	SPI_ISR_CallBack();
}

/*****************************************************************************/
/******************************   DATA	  **************************************/
void 		SPI_voidSendu8Data(u8 SPI_Data)
{
	SPDR_REG= SPI_Data;
	while (!(SPSR_REG & (1<<SPIF)));
}

u8 			SPI_u8RecieveData(void)
{
	while (!(SPSR_REG & (1<<SPIF)));
	return SPDR_REG;
}
