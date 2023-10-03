#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInit(void)
{
	/*Reset Pulse sequence*/
	MGPIO_voidSetPinValue(TFT_RST,GPIO_High);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST,GPIO_Low);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST,GPIO_High);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST,GPIO_Low);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST,GPIO_High);
	MSTK_voidSetBusyWait(120000);

	/*sleep ou command*/
	HTFT_voidWriteCommand(0x11);
	MSTK_voidSetBusyWait(150000);

	/*color mode command*/
	HTFT_voidWriteCommand(0x3A);
	/*passing color mode parameter ->rgb565*/
	HTFT_voidWriteData(0x05);

	/*Display on command*/
	HTFT_voidWriteCommand(0x29);
}


void HTFT_voidDisplayImage(const u16* Copy_pu16Image)
{
	/*Set x address*/
	HTFT_voidWriteCommand(0x2A);
	/*start*/
	HTFT_voidWriteData(0x00);
	HTFT_voidWriteData(0x00);
	/*end*/
	HTFT_voidWriteData(0x00);
	HTFT_voidWriteData(0x7F);

	/*Set y address*/
	HTFT_voidWriteCommand(0x2B);
	/*start*/
	HTFT_voidWriteData(0x00);
	HTFT_voidWriteData(0x00);
	/*end*/
	HTFT_voidWriteData(0x00);
	HTFT_voidWriteData(0x9F);

	/*Ram Write to show on tft*/
	HTFT_voidWriteCommand(0x2C);
	for(u16 i = 0 ; i < 20480 ; i++)
	{
		/*wrtie high byte*/
		HTFT_voidWriteData(Copy_pu8Image[i]>>8);
		/*wrtie Low byte*/
		HTFT_voidWriteData(Copy_pu8Image[i]&0x00FF);
	}

}

static void HTFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8 LOC_u8RecData;
	/*Set pin A0 Low to send command */
	MGPIO_voidSetPinValue(TFT_A0,GPIO_Low);
	/*Send command*/
	MSPI_voidSendSync(Copy_Command,&LOC_u8RecData);

}

static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	u8 LOC_u8RecData;
	/*Set pin A0 high to send data */
	MGPIO_voidSetPinValue(TFT_A0,GPIO_High);
	/*send command*/
	MSPI_voidSendSync(Copy_Data,&LOC_u8RecData);
	
}