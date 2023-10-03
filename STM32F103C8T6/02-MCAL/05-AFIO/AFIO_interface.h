/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: AFIO_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/


#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

		/*AFIO PORTS*/
#define AFIO_PORT_A	0b0000
#define AFIO_PORT_B	0b0001
#define AFIO_PORT_C	0b0010

void MAFIO_voidSetExtiConfig(u8 Copy_u8Line,u8 Copy_u8Port);

#endif