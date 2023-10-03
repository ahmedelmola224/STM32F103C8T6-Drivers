#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

void HSSD_voidInit(SSD_t Copy_u8Ssd)
{
	switch(Copy_u8Ssd)
	{
	case SSD_1:
		MGPIO_voidSetByteMode(SSD1_DATA_PORT,SSD1_BYTE,GPIO_Output_PP_2MHz);
		break;
	case SSD_2:
		MGPIO_voidSetByteMode(SSD2_DATA_PORT,SSD2_BYTE,GPIO_Output_PP_2MHz);
		break;
	default: break;		
	}

}

void HSSD_voidSetSymbol(SSD_t Copy_u8Ssd,SSD_Symbol_t Copy_u8Symbol)
{
	u8 LOC_u8Symbol=Copy_u8Symbol;
	switch(Copy_u8Ssd)
	{
	case SSD_1:
		if(SSD1_TYPE == SSD_COMMON_CATHODE)
		{
			LOC_u8Symbol=~LOC_u8Symbol;
		}
		MGPIO_voidSetByteValue(SSD1_DATA_PORT,SSD1_BYTE,LOC_u8Symbol);
		break;
	case SSD_2:
		if(SSD2_TYPE == SSD_COMMON_CATHODE)
		{
			LOC_u8Symbol=~LOC_u8Symbol;
		}
		MGPIO_voidSetByteValue(SSD2_DATA_PORT,SSD2_BYTE,LOC_u8Symbol);
		break;
	default: break;		
	}

}
