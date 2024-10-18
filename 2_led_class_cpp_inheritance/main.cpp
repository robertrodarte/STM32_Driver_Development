#include "led_cpp.h"
#include "power_led.h"

power_led pled1(RED, ON, DIAMETER_5MM, CURR_NORMAL, VOLTAGE_NORMAL);
	
led_electrical_t pled1_power; 
led_electrical_t pled2_power; 
led_electrical_t pled3_power; 
	
int main() 
{
	USART2_Init();
	
	power_led pled2(BLUE, ON, DIAMETER_7MM, CURR_HIGH, VOLTAGE_NORMAL);
	
	power_led *pled3 = new power_led(YELLOW, ON, DIAMETER_2MM, CURR_VERY_HIGH, VOLTAGE_HIGH); 
	
	pled1_power = pled1.power_led_compute_power(); 
	pled2_power = pled2.power_led_compute_power(); 
	pled3_power = pled3->power_led_compute_power(); 
	
	pled1.set_state(OFF); 
	pled2.set_state(OFF);
	pled3->set_state(OFF);
	
	delete pled3; // Dynamically allocated, make sure to clean up 
	
	while(1) {
		
	}
}