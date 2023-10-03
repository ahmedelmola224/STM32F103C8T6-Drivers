/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: AFIO_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

#define AFIO_BASE  0x40010000

typedef struct
{
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
	u32 AFIO_MAPR2;
}AFIO_Registers_t;

#define AFIO  ((volatile AFIO_Registers_t *)AFIO_BASE)

#endif