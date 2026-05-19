#include <stdio.h>
#include <stdint.h>
#include "main.h"

void led_init()
{
	// output chan PD
	__HAL_RCC_GPIOD_CLK_ENABLE();
	uint32_t* gpiod_moder = (uint32_t*)0x40020C00;
	*gpiod_moder &= ~(0b11 << 24);
	*gpiod_moder |= (0b01 << 24);
	*gpiod_moder &= ~(0b11 << 26);
	*gpiod_moder |= (0b01 << 26);
	*gpiod_moder &= ~(0b11 << 28);
	*gpiod_moder |= (0b01 << 28);
	*gpiod_moder &= ~(0b11 << 30);
	*gpiod_moder |= (0b01 << 30);
}
enum{
	LED_GREEN =12,
	LED_ORANGE,
	LED_RED,
	LED_BLUE
};
void led_ctrl_init(int led_num, int led_state)
{
	uint32_t* gpiod_odr = (uint32_t*)0x40020C14;
	if(led_state == 1)
	{
		*gpiod_odr |= (1 << led_num);
	}
	else
	{
		*gpiod_odr &= ~(1 << led_num);
	}
}
int main()
{
	HAL_Init();
	led_init();
	while(1)
		{
			led_ctrl_init(LED_BLUE, 1);
			led_ctrl_init(LED_GREEN, 1);
			HAL_Delay(1000);
			led_ctrl_init(LED_BLUE, 0);
			led_ctrl_init(LED_GREEN, 0);
			HAL_Delay(1000);
		}
	return 0;
	}
