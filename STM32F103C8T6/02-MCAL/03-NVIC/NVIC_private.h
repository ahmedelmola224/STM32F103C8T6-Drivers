/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: NVIC_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

			/*NVIC Registers Definations*/
#define NVIC_BASE   0xE000E100

#define NVIC_ISER0  *((volatile u32 *)(NVIC_BASE+0x00)) /*Enable External Interrupts 0->31*/
#define NVIC_ISER1  *((volatile u32 *)(NVIC_BASE+0x04)) /*Enable External Interrupts 31->59*/

#define NVIC_ICER0  *((volatile u32 *)(NVIC_BASE+0x080)) /*Disable External Interrupts 0->31*/
#define NVIC_ICER1  *((volatile u32 *)(NVIC_BASE+0x084)) /*Disable External Interrupts 31->59*/

#define NVIC_ISPR0  *((volatile u32 *)(NVIC_BASE+0x100)) /*Set Pending flag 0->31*/
#define NVIC_ISPR1  *((volatile u32 *)(NVIC_BASE+0x104)) /*Set Pending flag 32->59*/

#define NVIC_ICPR0  *((volatile u32 *)(NVIC_BASE+0x180)) /*Clear Pending flag 0->31*/
#define NVIC_ICPR1  *((volatile u32 *)(NVIC_BASE+0x184)) /*Clear Pending flag 32->59*/

#define NVIC_IABR0  *((volatile u32 *)(NVIC_BASE+0x200)) /*Clear Pending flag 0->31*/
#define NVIC_IABR1  *((volatile u32 *)(NVIC_BASE+0x204)) /*Clear Pending flag 32->59*/

#define NVIC_IPR      ((volatile u8 *)(NVIC_BASE+0x300)) /*priority*/




		/*Group Field*/
#define NVIC_GROUP4_SUB0	0x05FA0300
#define NVIC_GROUP3_SUB1	0x05FA0400
#define NVIC_GROUP2_SUB2	0x05FA0500
#define NVIC_GROUP1_SUB3	0x05FA0600
#define NVIC_GROUP0_SUB4	0x05FA0700


#endif