#include "stm32f4_gpio_lib.h"
#include "stm32f4_systick_lib.h"


SYSTICK sysTickTimer;
GPIO_Init_t myGPIO_InitStruct;

int main()
{
	myGPIO_InitStruct = __gpio_pin_params(GPIO_MODE_OUTPUT_PP, GPIO_PIN_5, GPIO_NO_PULL);
	Gpio myOutput1(PORTA, GPIOA, &myGPIO_InitStruct);
	
	while(1) {
		sysTickTimer.LIB_SYSTICK_DelayMS(250);
		myOutput1.lib_gpio_toggle_pin(GPIOA, GPIO_PIN_5); 
	}
}
