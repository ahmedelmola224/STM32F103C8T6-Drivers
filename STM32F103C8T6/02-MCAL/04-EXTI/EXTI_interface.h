/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: EXTI_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

		/*EXTI MODES*/
typedef enum 
{
	EXTI_Rising_Edge	,
	EXTI_Falling_Edge	,
	EXTI_On_Change
}EXTI_Mode_t;
		
		/*EXTI LINES*/
typedef enum
{
	EXTI_Line0  = 0 	,
	EXTI_Line1  = 1 	,
	EXTI_Line2  = 2 	,
	EXTI_Line3  = 3 	,
	EXTI_Line4  = 4 	,
	EXTI_Line5  = 5 	,
	EXTI_Line6  = 6 	,
	EXTI_Line7  = 7 	,
	EXTI_Line8  = 8 	,
	EXTI_Line9  = 9 	,
	EXTI_Line10 = 10 	,
	EXTI_Line11 = 11 	,
	EXTI_Line12 = 12 	,
	EXTI_Line13 = 13 	,
	EXTI_Line14 = 14 	,
	EXTI_Line15 = 15 	
	
}EXTI_Line_t;
		
void MEXTI_voidEnableExti(EXTI_Line_t Copy_u8Line);
void MEXTI_voidDisableExti(EXTI_Line_t Copy_u8Line);
void MEXTI_voidSetSensingEdge(EXTI_Line_t Copy_u8Line,EXTI_Mode_t Copy_u8Mode);
void MEXTI_voidTriggerSwInt(EXTI_Line_t Copy_u8Line);
void MEXTI_voidSetCallBack(EXTI_Line_t Copy_u8Line,void(*Copy_ptrFunc)(void));




#endif