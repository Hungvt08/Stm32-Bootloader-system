#include <stdio.h>
#include <stdint.h>
#include "main.h"

void button_init()
{
	//input button PA0
	__HAL_RCC_GPIOA_CLK_ENABLE();
	uint32_t* gpioa_moder = (uint32_t*)0x40020000;
	*gpioa_moder &= ~(0b11 << 0);
}
int button_get_state()
{
	uint32_t* gpioa_idr = (uint32_t*)0x40020010;
	if(((*gpioa_idr >> 0) &1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	HAL_Init();
	button_init();
	while(1)
	{
		uint32_t* temp;
		uint32_t func_add;
		void(*fp)();
		if(button_get_state() == 1)
		{
			temp = (uint32_t*) 0x08004004;
		}
		else
		{
			temp = (uint32_t*) 0x08008004;
		}
		func_add = *temp;
		fp = func_add;
		fp();
	}
	return 0;
}
