/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: LEDMRX_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

/*The required delay is 2.5 ms*/
#define LEDMRX_DELAY 2500 

static void HLEDMRX_voidDisableColumns(void);
static void HLEDMRX_voidSetRowValues(u8 Copy_u8RowVal);

#endif