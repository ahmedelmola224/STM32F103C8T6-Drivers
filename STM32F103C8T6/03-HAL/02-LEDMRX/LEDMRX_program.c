#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_inteface.h"
#include "STK_inteface.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_pivate.h"
#include "LEDMRX_config.h"


void HLEDMRX_voidInit(void)
{
	/*Init Rows Pins Direction*/
	MGPIO_voidSetPinMode(LEDMRX_ROW0_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW1_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW2_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW3_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW4_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW5_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW6_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_ROW7_PIN , GPIO_Output_PP_2MHz);

	/*Init Columns Pins Direction*/
	MGPIO_voidSetPinMode(LEDMRX_COL0_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL1_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL2_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL3_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL4_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL5_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL6_PIN , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(LEDMRX_COL7_PIN , GPIO_Output_PP_2MHz);
}


void HLEDMRX_voidDisplay(u8* Copy_pu8Data)
{
	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[0]);
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[1]);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[2]);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[3]);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[4]);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[5]);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[6]);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);
	
	HLEDMRX_voidDisableColumns();
	HLEDMRX_voidSetRowValues(Copy_pu8Data[7]);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN , GPIO_Low);
	MSTK_voidSetBusyWait(LEDMRX_DELAY);

}


static void HLEDMRX_voidDisableColumns(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN , GPIO_High);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN , GPIO_High);
}	


static void HLEDMRX_voidSetRowValues(u8 Copy_u8RowVal)
{
	u8 LOC_u8BitVal = 0;
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN , LOC_u8BitVal);
	LOC_u8BitVal = GET_BIT(Copy_u8RowVal , 7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN , LOC_u8BitVal);
}	

