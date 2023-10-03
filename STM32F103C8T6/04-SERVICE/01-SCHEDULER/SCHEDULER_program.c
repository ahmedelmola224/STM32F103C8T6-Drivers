#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "SCHEDULER_interrface.h"
#include "SCHEDULER_private.h"
#include "SCHEDULER_config.h"

static SCHEDULER_Task_t Tasks[NUMBER_OF_TASKS];


void SSCHEDULER_voidCreateTask(u8 Copy_u8TaskId,u16 Copy_u16Periodicity,u8 Copy_u8FirstDelay,void(*Copy_Fptr)(void));

{
	Tasks[Copy_u8TaskId].SCHEDULER_Periodicity = Copy_u16Periodicity;
	Tasks[Copy_u8TaskId].SCHEDULER_Fptr = Copy_Fptr;
	Tasks[Copy_u8TaskId].SCHEDULER_FirstDelay = Copy_u8FirstDelay;
	Tasks[Copy_u8TaskId].SCHEDULER_TaskState = SCHEDULER_TASK_Ready;
}

void SSCHEDULER_voidStart(void)
{
	MSTK_voidInit();
	/*tick time =1ms=1000us*/
	MSTK_voidSetIntervalPeriodic(1000,SSCHEDULER_voidScheduleTasks);
}

static void SSCHEDULER_voidScheduleTasks(void)
{
	for(u8 i = 0; i < NUMBER_OF_TASKS; i++)
	{
		if(Tasks[i].SCHEDULER_Fptr!=NULL &&(Tasks[i].SCHEDULER_TaskState) == SCHEDULER_TASK_Ready)
		{
			if((Tasks[i].SCHEDULER_FirstDelay) == 0)
			{
				Tasks[i].SCHEDULER_Fptr();
				Tasks[i].SCHEDULER_FirstDelay = Tasks[i].SCHEDULER_Periodicity-1;
			}
			else
			{
				Tasks[i].SCHEDULER_FirstDelay--;
			}
		}
		
	}
}


void SSCHEDULER_voidSusupendTask(u8 Copy_u8TaskId)
{
	Tasks[Copy_u8TaskId].SCHEDULER_TaskState = SCHEDULER_Task_Suspended;
}

void SSCHEDULER_voidResumeTask(u8 Copy_u8TaskId)
{
	Tasks[Copy_u8TaskId].SCHEDULER_TaskState = SCHEDULER_TASK_Ready;
}

void SSCHEDULER_voidDeleteTask(u8 Copy_u8TaskId)
{
	Tasks[Copy_u8TaskId].SCHEDULER_Fptr = NULL;
}