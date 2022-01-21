#ifndef		SPI_CONFIG_H
#define		SPI_CONFIG_H

#ifndef     F_CPU
#define     F_CPU             16000000UL
#endif

/*
SPI_MSTR_MODE can be: (Master/Slave)
              SPI_SLAVE
              SPI_MASTER
*/
#define     SPI_MSTR_MODE         SPI_MASTER
/*
SPI_DORD_MODE can be: (Data Order Mode)
              SPI_DORD_MSB
              SPI_DORD_LSB
*/
#define     SPI_DORD_MODE         SPI_DORD_MSB
/*
SPI_CLK_POLARITY can be:
              SPI_CLK_POLARITY_RISING_LEAD  (Start at Rising Edge)
              SPI_CLK_POLARITY_FALLING_LEAD (Start at Falling Edge)
*/
#define     SPI_CLK_POLARITY    SPI_CLK_POLARITY_RISING_LEAD
/*
SPI_CLK_PHASE can be:
              SPI_CLK_PHASE_SAMPLE_LEAD (Read First)
              SPI_CLK_PHASE_SETUP_LEAD  (Write First)
*/
#define     SPI_CLK_PHASE        SPI_CLK_PHASE_SETUP_LEAD
/*
SPI_SCK_MODE can be:
              SPI_SCK_FOSC_DIV_4
              SPI_SCK_FOSC_DIV_16
              SPI_SCK_FOSC_DIV_64
              SPI_SCK_FOSC_DIV_128

              SPI_SCK_FOSC_DIV_2_SP2X
              SPI_SCK_FOSC_DIV_8_SP2X
              SPI_SCK_FOSC_DIV_32_SP2X
              SPI_SCK_FOSC_DIV_64_SP2X

*/
#define     SPI_SCK_MODE        SPI_SCK_FOSC_DIV_16

#endif
