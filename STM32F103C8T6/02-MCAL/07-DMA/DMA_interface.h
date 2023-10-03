/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: DMA_interface.h	                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/*Memory to memory mode*/
typedef enum 
{
	DMA_M2m_Disabled = 0  ,
	DMA_M2m_Enabled  = 1
}DMA_MEM2MEM_t;

/*Channel priority level*/
typedef enum 
{
	DMA_Pl_Low 		= 0 ,
	DMA_Pl_Medium   = 1 ,
	DMA_Pl_High     = 2 ,
	DMA_Pl_VeryHigh = 3 
}DMA_Ch_Priority_t;

/*Memory size*/
typedef enum 
{
	DMA_Msize_8   = 0  ,
	DMA_Msize_16  = 1  ,
	DMA_Msize_32  = 2
}DMA_Mem_Size_t;

/* Peripheral size*/
typedef enum 
{
	DMA_Psize_8   = 0  ,
	DMA_Psize_16  = 1  ,
	DMA_Psize_32  = 2
}DMA_Per_Size_t;

 /*Memory increment mode*/
typedef enum 
{
	DMA_Minc_Disabled   =  0  ,
	DMA_Minc_Enabled    =  1
}DMA_Minc_t;

 /*Peripheral increment mode*/
typedef enum 
{
	DMA_Pinc_Disabled   =  0  ,
	DMA_Pinc_Enabled    =  1
}DMA_Pinc_t;

/*Circular mode*/
typedef enum 
{
	DMA_Circ_Disabled   =  0  ,
	DMA_Circ_Enabled 	=  1
}DMA_Circ_t;

/*Data transfer direction*/
typedef enum 
{
	DMA_Src_Peripheral 	=  0  ,
	DMA_Src_Memory  	=  1
}DMA_Dir_t;


typedef enum 
{
	DMA_TCI     =  1 ,
	DMA_HTI  	=  2 ,
	DMA_TEI 	=  3 
}DMA_Interrupts_t;


void MDMA_voidSetConfiguration(u8 Copy_u8Channel ,DMA_Dir_t Copy_u8DataSrc ,DMA_MEM2MEM_t Copy_u8M2m , DMA_Ch_Priority_t Copy_u8Priority , DMA_Mem_Size_t Copy_u8MemSize ,DMA_Per_Size_t Cpoy_u8PerSize ,DMA_Minc_t Copy_u8Minc,DMA_Pinc_t Copy_u8Pinc,DMA_Circ_t Copy_u8Cir );
void MDMA_voidEnableChannel(u8 Copy_u8Channel);
void MDMA_voidDisableChannel(u8 Copy_u8Channel);
void MDMA_voidEnableInterrupt(u8 Copy_u8Channel , DMA_Interrupts_t Copy_u8IntSrc);
void MDMA_voidDisableInterrupt(u8 Copy_u8Channel , DMA_Interrupts_t Copy_u8IntSrc);
void MDMA_voidSetAddress(u8 Copy_u8Channel ,u32 Copy_u32MemAddress,u32 Copy_u32PeripheralAddress , u16 Copy_u16BlockSize);
void MDMA_voidSetCallBack(u8 Copy_u8Channel,void(*Copy_Fptr)(void));
















#endif