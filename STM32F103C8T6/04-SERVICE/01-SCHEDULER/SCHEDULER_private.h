/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: SCHEDULER_private.h		                        */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

static void SSCHEDULER_voidScheduleTasks(void);

typedef enum 
{
	SCHEDULER_TASK_Ready,
	SCHEDULER_Task_Running,
	SCHEDULER_Task_Suspended
}SCHEDULER_Task_State_t;

typedef struct 
{
	u16 SCHEDULER_Periodicity;
	SCHEDULER_Task_State_t SCHEDULER_TaskState;
	u8 SCHEDULER_FirstDelay;
	void (*SCHEDULER_Fptr)(void);
}SCHEDULER_Task_t;

#endif
