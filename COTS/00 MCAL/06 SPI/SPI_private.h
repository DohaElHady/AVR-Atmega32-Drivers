#ifndef		SPI_PRIVATE_H
#define		SPI_PRIVATE_H


#define     SPI_DORD_MSB      0
#define     SPI_DORD_LSB      1

#define     SPI_SLAVE         0
#define     SPI_MASTER        1

#define     SPI_CLK_POLARITY_RISING_LEAD    0
#define     SPI_CLK_POLARITY_FALLING_LEAD   1

#define     SPI_CLK_PHASE_SAMPLE_LEAD       0
#define     SPI_CLK_PHASE_SETUP_LEAD        1

#define     SPI_SCK_FOSC_DIV_4              4
#define     SPI_SCK_FOSC_DIV_16             16
#define     SPI_SCK_FOSC_DIV_64             64
#define     SPI_SCK_FOSC_DIV_128            128
#define     SPI_SCK_FOSC_DIV_2_SP2X         2
#define     SPI_SCK_FOSC_DIV_8_SP2X         8
#define     SPI_SCK_FOSC_DIV_32_SP2X        32
#define     SPI_SCK_FOSC_DIV_64_SP2X        66

#define     SPCR_REG       *((volatile u8 *)0x2D)
#define     SPSR_REG       *((volatile u8 *)0x2E)
#define     SPDR_REG       *((volatile u8 *)0x2F)



/*        SPCR_REG Pins    */
#define       SPR0          0
#define       SPR1          1
#define       CPHA          2
#define       CPOL          3
#define       MSTR          4
#define       DORD          5
#define       SPE           6
#define       SPIE          7

/*        SPSR_REG Pins    */
#define       SPI2X         0
#define       WCOL          6
#define       SPIF          7

/*        SPDR_REG Pins    */
#define       MSB         0
#define       LSB         7


/*        SPI Physical Pins */
#define       SPI_PORT         PORTB
#define       SPI_SS           PIN4
#define       SPI_MOSI         PIN5
#define       SPI_MISO         PIN6
#define       SPI_SCK          PIN7

#endif
