/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: EXTI_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define  EXTI_BASE   0x40010400
typedef struct 
{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;
}EXTI_Registers_t;

#define EXTI  ((volatile EXTI_Registers_t *)EXTI_BASE)

#endif