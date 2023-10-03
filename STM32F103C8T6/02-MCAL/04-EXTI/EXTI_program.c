#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void(*EXTI_ptrFunc[16])(void) = NULL;

/*........till EXTI15_ptrFunc........ */

void MEXTI_voidEnableExti(EXTI_Line_t Copy_u8Line)
{
	SET_BIT(EXTI->EXTI_IMR,Copy_u8Line);
}


void MEXTI_voidDisableExti(EXTI_Line_t Copy_u8Line)
{
	CLR_BIT(EXTI->EXTI_IMR,Copy_u8Line);
}


void MEXTI_voidSetSensingEdge(EXTI_Line_t Copy_u8Line,EXTI_Mode_t Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_Rising_Edge:
			SET_BIT(EXTI->EXTI_RTSR,Copy_u8Line);
			break;
		case EXTI_Falling_Edge:
			SET_BIT(EXTI->EXTI_FTSR,Copy_u8Line);
			break;
		case EXTI_On_Change:
			SET_BIT(EXTI->EXTI_RTSR,Copy_u8Line);
			SET_BIT(EXTI->EXTI_FTSR,Copy_u8Line);
			break;		
	}
}


void MEXTI_voidTriggerSwInt(EXTI_Line_t Copy_u8Line)
{
	SET_BIT(EXTI->EXTI_SWIER,Copy_u8Line);
}

void MEXTI_voidSetCallBack(EXTI_Line_t Copy_u8Line,void(*Copy_ptrFunc)(void))
{
	EXTI_ptrFunc[Copy_u8Line] = Copy_ptrFunc;

}


void EXTI0_IRQHandler(void)
{
	if(EXTI0_ptrFunc != NULL)
		EXTI_ptrFunc[0]();

	SET_BIT(EXTI->EXTI_PR,0);
}

void EXTI1_IRQHandler(void)
{
	if(EXTI1_ptrFunc != NULL)
		EXTI_ptrFunc[1]();

	SET_BIT(EXTI->EXTI_PR,1);
}

void EXTI2_IRQHandler(void)
{
	if(EXTI2_ptrFunc != NULL)
		EXTI_ptrFunc[2]();

	SET_BIT(EXTI->EXTI_PR,2);
}

void EXTI3_IRQHandler(void)
{
	if(EXTI3_ptrFunc != NULL)
		EXTI_ptrFunc[3]();

	SET_BIT(EXTI->EXTI_PR,3);
}

void EXTI4_IRQHandler(void)
{
	if(EXTI4_ptrFunc != NULL)
		EXTI_ptrFunc[4]();

	SET_BIT(EXTI->EXTI_PR,4);
}
