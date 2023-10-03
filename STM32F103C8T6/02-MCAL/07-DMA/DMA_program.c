#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


static void (*DMA_Fptr[7])(void)={NULL};

void MDMA_voidSetConfiguration(u8 Copy_u8Channel ,DMA_Dir_t Copy_u8DataSrc ,DMA_MEM2MEM_t Copy_u8M2m , DMA_Ch_Priority_t Copy_u8Priority , DMA_Mem_Size_t Copy_u8MemSize ,DMA_Per_Size_t Cpoy_u8PerSize ,DMA_Minc_t Copy_u8Minc,DMA_Pinc_t Copy_u8Pinc,DMA_Circ_t Copy_u8Cir )
{
	/*Set the source of the data */
	WRITE_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 4 , Copy_u8DataSrc);

	/*determine if it is Mem to Mem */
	WRITE_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 14 , Copy_u8M2m);

	/*Set priority of the channel*/
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR|=(Copy_u8Priority << 12);

	/*Set Memory Size*/
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR|=(Copy_u8MemSize << 10);


	/*Set Peripheral Size*/
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR|=(Cpoy_u8PerSize << 8);


	/*Determine Mem and Peripheral increment mode or not*/
	WRITE_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 7 , Copy_u8Minc);
	WRITE_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 6 , Copy_u8Pinc);

	/*Determine circular mode or not*/
	WRITE_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 5 , Copy_u8Cir);
}


void MDMA_voidEnableChannel(u8 Copy_u8Channel)
{
	/*Clear all flags of the specified channel*/
	u8 LOC_u8StartBit = ((Copy_u8Channel * 4) -4);
	SET_NIBBLE(DMA->DMA_IFCR,LOC_u8StartBit);

	/*Enable Channel*/
	SET_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 0);
}

void MDMA_voidDisableChannel(u8 Copy_u8Channel)
{
	CLR_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR , 0);

}

void MDMA_voidEnableInterrupt(u8 Copy_u8Channel , DMA_Interrupts_t Copy_u8IntSrc)
{
	SET_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR ,Copy_u8IntSrc ) ;
}

void MDMA_voidDisableInterrupt(u8 Copy_u8Channel , DMA_Interrupts_t Copy_u8IntSrc)
{
	CLR_BIT(DMA->DMA_CH[Copy_u8Channel-1].DMA_CCR ,Copy_u8IntSrc ) ;
}

void MDMA_voidSetAddress(u8 Copy_u8Channel ,u32 Copy_u32MemAddress,u32 Copy_u32PeripheralAddress , u16 Copy_u16BlockSize)
{
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CNDTR = Copy_u16BlockSize;
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CMAR  = Copy_u32MemAddress;
	DMA->DMA_CH[Copy_u8Channel-1].DMA_CPAR  = Copy_u32PeripheralAddress;
}

void MDMA_voidSetCallBack(u8 Copy_u8Channel,void(*Copy_Fptr)(void))
{
	DMA_Fptr[Copy_u8Channel-1] = Copy_Fptr;
}



void DMA1_Channel1_IRQHandler(void)
{
	if(DMA_Fptr[0]!= NULL)
	{
		DMA_Fptr[0]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,0);
}

void DMA1_Channel2_IRQHandler(void)
{
	if(DMA_Fptr[1]!= NULL)
	{
		DMA_Fptr[1]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,4);
}


void DMA1_Channel3_IRQHandler(void)
{
	if(DMA_Fptr[2]!= NULL)
	{
		DMA_Fptr[2]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,8);
}

void DMA1_Channel4_IRQHandler(void)
{
	if(DMA_Fptr[3]!= NULL)
	{
		DMA_Fptr[3]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,12);
}

void DMA1_Channel5_IRQHandler(void)
{
	if(DMA_Fptr[4]!= NULL)
	{
		DMA_Fptr[4]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,16);
}


void DMA1_Channel6_IRQHandler(void)
{
	if(DMA_Fptr[5]!= NULL)
	{
		DMA_Fptr[5]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,20);
}


void DMA1_Channel7_IRQHandler(void)
{
	if(DMA_Fptr[6]!= NULL)
	{
		DMA_Fptr[6]();
	}

	SET_NIBBLE(DMA->DMA_IFCR,24);
}