/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: SPI_private.h		                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define  SPI_BASE   0x40013000 
typedef struct 
{
	u32 SPI_CR1;
	u32 SPI_CR2;
	u32 SPI_SR;
	u32 SPI_DR;
	u32 SPI_CRCPR;
	u32 SPI_RXCRCR;
	u32 SPI_TXCRCR;
}SPI_Registers_t;

#define SPI  ((volatile SPI_Registers_t *)SPI_BASE)

/*Clock phase*/
#define SPI_FIRST_EDGE_READ   	0
#define SPI_SEC_EDGE_READ   	1


/* Clock polarity*/
#define SPI_LOW_IDLE			0
#define SPI_HIGH_IDLE			1


/* Mode selection */
#define SPI_SLAVE				0
#define SPI_MASTER 				1


/* Baud rate control*/
#define SPI_CLK_DIV_2  				0
#define SPI_CLK_DIV_4  				1
#define SPI_CLK_DIV_8  				2
#define SPI_CLK_DIV_16  			3
#define SPI_CLK_DIV_32  			4
#define SPI_CLK_DIV_64  			5
#define SPI_CLK_DIV_128  			6
#define SPI_CLK_DIV_256 			7


/* Frame format*/
#define SPI_MSB_FIRST 			0
#define SPI_LSB_FIRST 			1

/*Frame size*/
#define SPI_FRAME_8   			0
#define SPI_FRAME_16			1







#endif