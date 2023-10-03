#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetExtiConfig(u8 Copy_u8Line,u8 Copy_u8Port)
{
	u8 LOC_u8RegIndex   = Copy_u8Line / 4;
	u8 LOC_u8LineOffset = Copy_u8Line % 4;
	CLR_NIBBLE(AFIO->AFIO_EXTICR[LOC_u8RegIndex] , LOC_u8LineOffset * 4);
	WRITE_NIBBLE(AFIO->AFIO_EXTICR[LOC_u8RegIndex] , LOC_u8LineOffset * 4 , Copy_u8Port);
}