#include "led_cpp.h"

// Static allocation
led led1(RED, ON); 

led_state_t led1_state; 
led_state_t led2_state; 
led_state_t led3_state; 

int main() 
{
	USART2_Init();
	
	// Automatic allocation 
	led led2(BLUE, ON); 
	
	// Dynamic allocation
	led *led3 = new led(YELLOW, ON); 
	
	led1_state = led1.get_state(); 
	led2_state = led2.get_state(); 
	led3_state = led3->get_state(); // arrow because we initalized dynamically
	
	led1.set_state(OFF); 
	led2.set_state(OFF);
	led3->set_state(OFF); 
	
	delete led3; // free up memory(memory leak stuff?)
	
	while(1) {
		
	}
}