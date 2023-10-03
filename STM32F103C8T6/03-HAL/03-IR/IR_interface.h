/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: IR_interface.h		                           	*/
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H
typedef enum
{
	IR_Btn_1  = 84 ,
	IR_Btn_2  = 22 ,
	IR_Btn_3  = 21 ,
	IR_Btn_4  = 80 ,
	IR_Btn_5  = 18 ,
	IR_Btn_6  = 17 ,
	IR_Btn_7  = 76 ,
	IR_Btn_8  = 14 ,
	IR_Btn_9  = 13 ,
	IR_Btn_0  = 12

}IR_Button;
void HIR_voidInit(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin,EXTI_Line_t Copy_u8Line);
u8 HIR_u8GetFrame(u8* Copy_pu8Data,u8* Copy_pu8Address);


#endif 
