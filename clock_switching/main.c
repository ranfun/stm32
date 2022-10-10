#include<stdint.h>
#include "stm32f401xe.h"

//RCC_HSI_ON by default 
//set HSE_ON as 1 in RCC's clock control reg.
//RCC_CFGR bits SW[1:0] system clock switch 01 HSE as sysclk.

int main(void){
	RCC_TypeDef *pRCC;
	pRCC->CR|=(1<<16);
	
	//wait until HSE becomes stable. HSE clock rdy on pin 17.
	
	while(!(pRCC->CR[17] & (1<<17)));
	
	//selecting HSE as sysclk.
	pRCC->CFGR&=~(0x3<<0);
	pRCC->CFGR!=(0x1<<0);
	return 0; 
}