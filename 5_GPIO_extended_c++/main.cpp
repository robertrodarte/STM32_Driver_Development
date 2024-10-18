#include "stm32f4_gpio_lib.h"

uint8_t btnState; 

int main()
{
	GPIO_Init_t myGPIO_InitStruct;
	
	myGPIO_InitStruct = __gpio_pin_params(GPIO_MODE_OUTPUT_PP, GPIO_PIN_5, GPIO_NO_PULL);
	Gpio myOutput1(PORTA, GPIOA, &myGPIO_InitStruct);
	
	// Test 2 - add another port with same pin
	Gpio myOutput2(PORTC, GPIOC, &myGPIO_InitStruct);

	// Test 3 - another port another pin 
	myGPIO_InitStruct = __gpio_pin_params(GPIO_MODE_OUTPUT_PP, GPIO_PIN_13, GPIO_NO_PULL);
	Gpio myOutput3(PORTD, GPIOD, &myGPIO_InitStruct);
	
	// Test 4 - another port, different mode
	myGPIO_InitStruct = __gpio_pin_params(GPIO_MODE_INPUT, GPIO_PIN_13, GPIO_NO_PULL);
  Gpio myInput1(PORTC, GPIOC, &myGPIO_InitStruct);
	
	while(1) {
		for(int i = 0; i < 900000; i++) {}
		myOutput1.lib_gpio_toggle_pin(GPIOA, GPIO_PIN_5); 
	  myOutput2.lib_gpio_toggle_pin(GPIOC, GPIO_PIN_5);
		myOutput3.lib_gpio_toggle_pin(GPIOD, GPIO_PIN_13);
			
		// Button is active low on nucleo	
		btnState = myInput1.lib_gpio_read_pin(GPIOC, GPIO_PIN_13); 
	}
}
