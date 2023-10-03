#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h" 

static u8 GLO_u8FrameReady	= 0;
static u8 GLO_u8Error 		= 0;
static u8 GLO_u8Address 	= 0;
static u8 GLO_u8Date 		= 0;
static u8 GLO_u8StartBit	= 0;
static u32 GLO_u32IrFrame[35]={0};
void HIR_voidInit(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin,EXTI_Line_t Copy_u8Line)
{
	/*All the requied intializations*/
	GLO_u8FrameReady=0,GLO_u8Error=0,GLO_u8Address=0,GLO_u8Date=0,GLO_u8StartBit = 0; 
	MGPIO_voidSetPinMode(Copy_u8Port , Copy_u8Pin , GPIO_INPUT_FL);
	MAFIO_voidSetExtiConfig(Copy_u8Line , Copy_u8Port);
	MSTK_voidInit();
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(NVIC_EXTI0 + Copy_u8Line);
	MEXTI_voidSetCallBack(IR_voidGetFrame);
	MEXTI_voidSetSensingEdge(Copy_u8Line , EXTI_Falling_Edge);
	MEXTI_voidEnableExti(Copy_u8Line);
}

u8 HIR_u8GetFrame(u8* Copy_pu8Data,u8* Copy_pu8Address)
{
	/*variable indicates that there's error if the frame has already error or the frame is still being processed
	 0->error   
	 1->correect data & address */
	u8 LOC_u8Error = 1;
	if(GLO_u8FrameReady == 1)
	{
		/*frame ready so move the data , address and error*/
		*Copy_pu8Data    = GLO_u8Date;
		*Copy_pu8Address = GLO_u8Address;
		 LOC_u8Error	 = GLO_u8Error;
		 GLO_u8FrameReady= 0;
	}
	return LOC_u8Error;

}

static void IR_voidGetFrame(void)
{
	if(GLO_u8StartBit==0)
	{
		/*first falling edge*/
		MSTK_voidSetIntervalSingle(1000000,IR_voidAnalyzeFrame);
	}
	else if(GLO_u8StartBit<=33)
	{
		/*save stk reading to process later*/
		GLO_u32IrFrame[GLO_u8StartBit-1] = MSTK_u32GetElapsedTicks();

		/*reset stk*/
		MSTK_voidSetIntervalSingle(1000000,IR_voidAnalyzeFrame);
	}
	GLO_u8StartBit++;
}

static void IR_voidAnalyzeFrame(void)
{
	u8 i;
	u8 LOC_BitState;
	GLO_u8FrameReady = 0;

	/*check start bit*/
	if(IR_u8GetBitStatus(GLO_u32IrFrame[0])!=START_BIT)
	{
		GLO_u8Error=1;
	}

	GLO_u8Address = 0 ;
	/*get address*/
	for(i = 1 ; i <= 8 ; i++)
	{
		LOC_BitState = IR_u8GetBitStatus(GLO_u32IrFrame[i]);

		/*check the correctness of the bit*/
		if(LOC_BitState == ERROR_BIT || LOC_BitState == START_BIT)
		{
			GLO_u8Error = 1 ;
		}
		else
		{
			/*write the bit in the address variable*/
			WRITE_BIT(GLO_u8Address , LOC_BitState);
		}
	}

	GLO_u8Date = 0;
	/*get data*/
	for(i = 17 ; i <= 24 ; i++)
	{
		/*check the correctness of the bit*/
		LOC_BitState = IR_u8GetBitStatus(GLO_u32IrFrame[i]);
		if(LOC_BitState == ERROR_BIT || LOC_BitState == START_BIT)
		{
			GLO_u8Error = 1 ;
		}
		else
		{
			/*write the bit in the data variable*/
			WRITE_BIT(GLO_u8Date , LOC_BitState);
		}
	}

	/*reset variables to be ready to recieve new signal */
	GLO_u8StartBit=0;
	GLO_u32IrFrame[0]=0;
	GLO_u8FrameReady=1;

}

static u8 IR_u8GetBitStatus(u32 Copy_u32Ticks)
{
	u8 LOC_u8BitState = ERROR_BIT;
	/*Start bit range*/
	if(Copy_u32Ticks > 10500 && Copy_u32Ticks < 14000)
	{
		LOC_u8BitState = START_BIT;
	}
	/*Zero bit range*/
	else if(Copy_u32Ticks > 950 && Copy_u32Ticks < 1350)
	{
		LOC_u8BitState = ZERO_BIT;
	}
	/*one bit range*/
	else if(Copy_u32Ticks > 1950 && Copy_u32Ticks < 2450)
	{
		LOC_u8BitState = ONE_BIT;
	}
}