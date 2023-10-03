#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTP_voidInit(void)
{
	/*Init pins*/
	MGPIO_voidSetPinMode(STP_SERIAL_DATA,GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(STP_SHIFT_CLK	,GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(STP_STORE_CLK	,GPIO_Output_PP_2MHz);
	MSTK_voidInit();
}

void HSTP_voidSendDataSynch(u8 Copy_u8Data)
{
	s8 LOC_s8Counter;
	u8 LOC_u8Bit;
	for(LOC_s8Counter = 7 ; LOC_s8Counter >= 0 ; LOC_s8Counter--)
	{
		/*send data from MSB*/
		LOC_u8Bit = GET_BIT(Copy_u8Data , LOC_s8Counter);
		MGPIO_voidSetPinValue(STP_SERIAL_DATA , LOC_u8Bit);

		/*Shift clk pulse for 100ns*/
		MGPIO_voidSetPinValue(STP_SHIFT_CLK , GPIO_High);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLK , GPIO_Low);
	}
	/*Store clk pulse for 100ns*/
	MGPIO_voidSetPinValue(STP_STORE_CLK , GPIO_High);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STP_STORE_CLK , GPIO_Low);
}