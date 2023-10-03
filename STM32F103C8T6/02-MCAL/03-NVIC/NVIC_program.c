#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"




void MNVIC_voidInit(void)
{
				/*SCB Registers Definations*/
	#define	SCB_BASE   0xE000ED00
	#define SCB_AIRCR  *((volatile u32 *)(SCB_BASE+0x0C))	
	SCB_AIRCR=GROUP_SUB_PRI_PATTERN;
}

void MNVIC_voidEnableInterrupt(NVIC_Interrupt_t Copy_u8PeripheralInt)
{
	/*Check the interupt number to determine which regiser to type in 
	  and to Enable the corresponding interrupt  */
	if(Copy_u8PeripheralInt <= 31)
	{
		NVIC_ISER0 = ( 1 << Copy_u8PeripheralInt ) ;
	}
	else if(Copy_u8PeripheralInt <= 59)
	{
		  Copy_u8PeripheralInt =   Copy_u8PeripheralInt - 32 ;
		NVIC_ISER0 = ( 1 << Copy_u8PeripheralInt ) ;
	}
}


void MNVIC_voidDisableInterrupt(NVIC_Interrupt_t Copy_u8PeripheralInt)
{
	/*Check the interupt number to determine which regiser to type in 
	  and to Disable the corresponding interrupt  */
	if(Copy_u8PeripheralInt <= 31)
	{
		NVIC_ICER0 = ( 1 << Copy_u8PeripheralInt ) ;
	}
	else if(Copy_u8PeripheralInt <= 59)
	{
		  Copy_u8PeripheralInt =   Copy_u8PeripheralInt - 32 ;
		NVIC_ICER1 = ( 1 << Copy_u8PeripheralInt ) ;
	}
}


void MNVIC_voidSetPendingFlag(NVIC_Interrupt_t Copy_u8PeripheralInt)
{
	/*Check the interupt number to determine which regiser to type in 
	  and to Set the pending flag  */
	if(Copy_u8PeripheralInt <= 31)
	{
		NVIC_ISPR0 = ( 1 << Copy_u8PeripheralInt ) ;
	}
	else if(Copy_u8PeripheralInt <= 59)
	{
		  Copy_u8PeripheralInt =   Copy_u8PeripheralInt - 32 ;
		NVIC_ISPR1 = ( 1 << Copy_u8PeripheralInt ) ;
	}
}


void MNVIC_voidClearPendingFlag(NVIC_Interrupt_t Copy_u8PeripheralInt)
{
	/*Check the interupt number to determine which regiser to type in 
	  and to Clear the pending flag  */
	if(Copy_u8PeripheralInt <= 31)
	{
		NVIC_ICPR0 = ( 1 << Copy_u8PeripheralInt ) ;
	}
	else if(Copy_u8PeripheralInt <= 59)
	{
		Copy_u8PeripheralInt =Copy_u8PeripheralInt - 32 ;
		NVIC_ICPR1 = ( 1 << Copy_u8PeripheralInt ) ;
	}
}


u8 MNVIC_u8GetActiveFlag(NVIC_Interrupt_t Copy_u8PeripheralInt)
{
	u8 LOC_u8Result;

	/*Check the interupt number to determine which regiser to read from 
	  and to read the active flag  */
	if(Copy_u8PeripheralInt <= 31)
	{
		LOC_u8Result = GET_BIT(NVIC_IABR0,Copy_u8PeripheralInt);
	}
	else if(Copy_u8PeripheralInt <= 59)
	{
		Copy_u8PeripheralInt =   Copy_u8PeripheralInt - 32 ;
		LOC_u8Result = GET_BIT(NVIC_IABR0,Copy_u8PeripheralInt);
	}
	return LOC_u8Result;
}


void MNVIC_voidSetPriority(NVIC_Interrupt_t Copy_u8PeripheralInt,u8 Copy_u8IntGroupPriority,u8 Copy_u8IntSubPriority)
{

	/*( ( Copy_u32GroupPattern - 0x05FA0300 ) / 0x100 ) ) -> the difference between to successive pattern
	is 0x100 by dividng the result by0x100 then we have the number of bits that needed by sub priority
	so the group priority is shifted by this number*/
	u8 LOC_u8Poiority = Copy_u8IntSubPriority | (Copy_u8IntGroupPriority <<( ( GROUP_SUB_PRI_PATTERN - 0x05FA0300 ) / 0x100 ) );
	
	/*External Peripherals*/
	if(Copy_u8PeripheralInt >= 0)
	{
		NVIC_IPR[Copy_u8PeripheralInt] = LOC_u8Poiority << 4;
	}
	
	/*Set the group pattern*/
	//SCB_AIRCR = Copy_u32GroupPattern;
}


