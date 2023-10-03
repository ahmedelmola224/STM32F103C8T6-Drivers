/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: DMA_private.h	     	                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define  DMA_BASE   0x40020000

typedef struct 
{
	u32 DMA_CCR      ; 
	u32 DMA_CNDTR    ;
	u32 DMA_CPAR     ;
	u32 DMA_CMAR  	 ; 
	u32 DMA_RESERVED ;
}DMA_Channel_Reg_t;

typedef struct
{
	u32 DMA_ISR	    			 ;
	u32 DMA_IFCR				 ;
	DMA_Channel_Reg_t DMA_CH [7] ;
}DMA_Registers_t;


#define DMA  ((volatile DMA_Registers_t *)DMA_BASE)


#endif