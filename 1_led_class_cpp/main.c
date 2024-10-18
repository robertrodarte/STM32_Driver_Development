#include "led.h"

led_t led1; 
led_t led2; 

int main() 
{
	USART2_Init();
	
	// LED 1 defaulted to red and Off
	led_ctor(&led1, RED, OFF); 
	led_ctor(&led2, BLUE, ON);
	
	led_get_state(&led1);
	led_get_state(&led2);
	
	led_set_state(&led1, ON); 
	led_set_state(&led2, OFF); 
	
	while(1) {
		
	}
}