/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: SPI_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

typedef enum 
{
	SPI_RX  	=  6 ,
	SPI_TX      =  7 
}SPI_Interrupts_t;

void MSPI_voidInit(void);

/*you need to select the slave before calling the function*/
void MSPI_voidSendSync(u8 Copy_u8DataToTransmit,u8* Copy_pu8DataToRecieve);
void MSPI_voidSendAsync(u8 Copy_u8DataToTransmit,void (*Fptr)(u8));
void MSPI_voidInerruptEnable(SPI_Interrupts_t Copy_u8IntSrc);
void MSPI_voidInerruptDisable(SPI_Interrupts_t Copy_u8IntSrc);


#endif