#include "Rcc.h"

void rngUnresetEnableClock(){
	RCC_reg->RCC_AHB2RSTR &= ~(1 << 6);
	RCC_reg->RCC_AHB2ENR  |= (1 << 6);

//	RCC_reg->RCC_PLLCFGR &= ~(15 << 24);	//CLEAR PLLQ
//	RCC_reg->RCC_PLLCFGR |= (3 << 24);		//set PLLQ to 0011
}
