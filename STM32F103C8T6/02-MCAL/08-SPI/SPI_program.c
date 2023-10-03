#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


static void (*SPI_Fptr_Rx)(u8) = NULL;
void MSPI_voidInit(void)
{
	/*clock phase*/
	WRITE_BIT(SPI->SPI_CR1,0,SPI_CLK_PHASE);

	/* Clock polarity*/
	WRITE_BIT(SPI->SPI_CR1,1,SPI_CLK_POLARITY);

	/* Mode selection*/
	WRITE_BIT(SPI->SPI_CR1,2,SPI_MODE);

	/*Baud rate control*/
	SPI->SPI_CR1 |= SPI_BAUD_RATE << 3;

	/* Frame format*/
	WRITE_BIT(SPI->SPI_CR1,7,SPI_FRAME_FORMAT);

	/*ٍsw management*/
	SET_BIT(SPI->SPI_CR1,9);

	/*slave not selected*/
	SET_BIT(SPI->SPI_CR1,8);

	/*Frame Size*/
	WRITE_BIT(SPI->SPI_CR1,11,SPI_FRAME_SIZE);

	/*SPI ENABLE*/
	SET_BIT(SPI->SPI_CR1,6);

}


void MSPI_voidSendSync(u8 Copy_u8DataToTransmit,u8* Copy_pu8DataToRecieve)
{
	/*who call this function need to select the slave using gpio low and at the end high*/
	/*Put the data in the register to transmit*/
	SPI->SPI_DR = Copy_u8DataToTransmit;

	/*Wait until transmit and recieve*/
	while((GET_BIT(SPI->SPI_SR, 7)));

	*Copy_pu8DataToRecieve = SPI->SPI_DR;
}


void MSPI_voidSendAsync(u8 Copy_u8DataToTransmit,void (*Fptr)(u8))
{
	/*who call this function need to select the slave by making gpio selection pin low*/
	/*for safety & if you need to use the same funcion */
	if(Fptr != NULL)
		SPI_Fptr_Rx = Fptr;

	SPI->SPI_DR = Copy_u8DataToTransmit;



}

void MSPI_voidInerruptEnable(SPI_Interrupts_t Copy_u8IntSrc)
{
	SET_BIT(SPI->SPI_CR2,Copy_u8IntSrc);

}
void MSPI_voidInerruptDisable(SPI_Interrupts_t Copy_u8IntSrc)
{
	CLR_BIT(SPI->SPI_CR2,Copy_u8IntSrc);
}

void SPI1_IRQHandler(void)
{
	if(SPI_Fptr_Rx!=NULL)
		SPI_Fptr_Rx(SPI->SPI_DR);
	/*in SPI_Fptr_Rx need to make GPIO Selectin Pin High   */

}

