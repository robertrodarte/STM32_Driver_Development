#include "stm32f4_gpio_lib.h"

int main()
{
	GPIO_INIT_t myGPIO_InitStruct;
	
	while(1) {
		
		myGPIO_InitStruct.MODE = GPIO_MODE_OUTPUT_PP; 
		myGPIO_InitStruct.PIN = GPIO_PIN_5; 
		myGPIO_InitStruct.PULL = GPIO_NO_PULL; 
		
		__lib_rcc_gpioa_clk_enable(); 
		
		lib_gpio_init(GPIOA, &myGPIO_InitStruct); 
		
		for(int i = 0; i < 900000; i++) {
			lib_gpio_toggle_pin(GPIOA, GPIO_PIN_5); 
		}
	}
}
