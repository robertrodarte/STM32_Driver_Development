#include "stm32f4_gpio_lib.h"
#include "stm32f4_systick_driver.h"

GPIO_INIT_t myGPIO_InitStruct;

int main()
{
	__lib_rcc_gpioa_clk_enable();
	myGPIO_InitStruct.MODE = GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.PIN = GPIO_PIN_5;
	myGPIO_InitStruct.PULL = GPIO_NO_PULL;
	lib_gpio_init(GPIOA, &myGPIO_InitStruct);
	
	// Configure SysTick
	SysTick->LOAD = 16000000 - 1; 
	SysTick->VAL = 0; 
	SysTick->CTRL = 5; 
	
	while(1) {
		if(SysTick->CTRL & 0x10000) {
			lib_gpio_toggle_pin(GPIOA, GPIO_PIN_5);
		}
	}
}
