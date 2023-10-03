#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

typedef enum 
{
	SSD_1=0,
	SSD_2
}SSD_t;

typedef enum 
{
	SSD_Number_0=0b1000000	,
	SSD_Number_1=0b1111001	,
	SSD_Number_2=0b0100100	,
	SSD_Number_3=0b0110000	,
	SSD_Number_4=0b0011001	,
	SSD_Number_5=0b0010010	,
	SSD_Number_6=0b0000010	,
	SSD_Number_7=0b1111000	,
	SSD_Number_8=0b0000000	,
	SSD_Number_9=00010000 	,
}SSD_Symbol_t;

void HSSD_voidInit(SSD_t Copy_u8Ssd);
void HSSD_voidSetSymbol(SSD_t Copy_u8Ssd,SSD_Symbol_t Copy_u8Symbol);

#endif