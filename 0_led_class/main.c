#include "led.h"
#include "power_led.h"

power_led_t pled1;
power_led_t pled2; 
	
led_electrical_t pled1_power; 
led_electrical_t pled2_power; 
	
int main() 
{
	USART2_Init();
	
	power_led_ctor(&pled1, RED, ON, DIAMETER_5MM, CURR_NORMAL, VOLTAGE_NORMAL); 
	power_led_ctor(&pled2, YELLOW, ON, DIAMETER_7MM, CURR_HIGH, VOLTAGE_NORMAL);  
	
	pled1_power = power_led_compute_power(&pled1);
	pled2_power = power_led_compute_power(&pled2); 
	
	while(1) {
		
	}
}