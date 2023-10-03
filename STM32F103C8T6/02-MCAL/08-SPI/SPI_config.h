/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: SPI_config.h		                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*Choose one of the following : -SPI_SLAVE
								-SPI_MASTER */
#define SPI_MODE   SPI_MASTER


/*Choose one of the following : -SPI_MSB_FIRST
								-SPI_LSB_FIRST */
#define SPI_FRAME_FORMAT	SPI_MSB_FIRST

/*Choose one of the following : -SPI_FRAME_8 
								-SPI_FRAME_16 */
#define SPI_FRAME_SIZE  	SPI_FRAME_8

/*Choose one of the following : -SPI_FIRST_EDGE_READ
								-SPI_SEC_EDGE_READ */
#define SPI_CLK_PHASE   SPI_SEC_EDGE_READ


/*Choose one of the following : -SPI_LOW_IDLE
								-SPI_HIGH_IDLE */
#define SPI_CLK_POLARITY   SPI_HIGH_IDLE

/*Choose one of the following : -SPI_CLK_DIV_2
								-SPI_CLK_DIV_4
								-SPI_CLK_DIV_8
								-SPI_CLK_DIV_16
								-SPI_CLK_DIV_32
								-SPI_CLK_DIV_64
								-SPI_CLK_DIV_128
								-SPI_CLK_DIV_256 */
#define SPI_BAUD_RATE   SPI_CLK_DIV_2

#endif