#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"
#include "song_tet.h"/* ->include array of the music after sampling and quantizing*/

static void DAC_voidHandler(void)
{
	static u16 SLOC_u16CurrentElment=0;
	u8 LOC_u8PinsValue[8]={0};
	for(u8 i = 0 ;i < 8 ; i++)
	{
		LOC_u8PinsValue[i]=GET_BIT(TrackArray[SLOC_u16CurrentElment],i);/*Track Array and it's size exists in song_test.h*/
	}

	MGPIO_voidSetPinValue(DAC_PIN0,LOC_u8PinsValue[0]);
	MGPIO_voidSetPinValue(DAC_PIN1,LOC_u8PinsValue[1]);
	MGPIO_voidSetPinValue(DAC_PIN2,LOC_u8PinsValue[2]);
	MGPIO_voidSetPinValue(DAC_PIN3,LOC_u8PinsValue[3]);
	MGPIO_voidSetPinValue(DAC_PIN4,LOC_u8PinsValue[4]);
	MGPIO_voidSetPinValue(DAC_PIN5,LOC_u8PinsValue[5]);
	MGPIO_voidSetPinValue(DAC_PIN6,LOC_u8PinsValue[6]);
	MGPIO_voidSetPinValue(DAC_PIN7,LOC_u8PinsValue[7]);

	if(SLOC_u16CurrentElment==TrackSize)
	{
		/*to replay the track*/
		SLOC_u16CurrentElment=0;
	}

}

void HDAC_voidInit(void)
{
	MGPIO_voidSetPinMode(DAC_PIN0 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN1 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN2 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN3 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN4 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN5 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN6 , GPIO_Output_PP_2MHz);
	MGPIO_voidSetPinMode(DAC_PIN7 , GPIO_Output_PP_2MHz);
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125 , DAC_voidHandler);/*8 mhz -> sample every 125us*/


}