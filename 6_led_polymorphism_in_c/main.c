#include "led.h"
#include "power_led.h"
#include "medical_led.h"
	
int main() 
{
	USART2_Init();
	
	MedicalLed_t mled1;
  power_led_t pled1;	
	led_t led1; 
	
	led_t const * sys_leds[] = {&led1, (led_t*)&pled1, (led_t*)&mled1, (led_t*)0}; 
	
	led_ctor(&led1, RED, ON); 
	power_led_ctor(&pled1, RED, ON, DIAMETER_5MM, CURR_NORMAL, VOLTAGE_NORMAL); 
	MedicalLed_ctor(&mled1, INFARED, (led_color_t)INFARED, ON); 
	
	while(1) {
		runSystemDiagnostics(sys_leds); 
		// Can put delay
		computeLedEffs(sys_leds); 
	}
}