/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: IR_private.h		                           	*/
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

static void IR_voidGetFrame(void);
static void IR_voidAnalyzeFrame(void);
static u8 IR_u8GetBitStatus(void);

#define ZERO_BIT  	0
#define ONE_BIT   	1
#define START_BIT   2
#define ERROR_BIT   3

#endif 