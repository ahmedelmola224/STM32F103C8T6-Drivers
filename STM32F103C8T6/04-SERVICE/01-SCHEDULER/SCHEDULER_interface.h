/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: SCHEDULER_interface.h		                        */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H


/*Copy_u8TaskId-> represents the task priority*/
void SSCHEDULER_voidCreateTask(u8 Copy_u8TaskId,u16 Copy_u16Periodicity,u8 Copy_u8FirstDelay,void(*Copy_Fptr)(void));
void SSCHEDULER_voidSusupendTask(u8 Copy_u8TaskId);
void SSCHEDULER_voidResumeTask(u8 Copy_u8TaskId);
void SSCHEDULER_voidDeleteTask(u8 Copy_u8TaskId);
void SSCHEDULER_voidStart(void);

#endif
