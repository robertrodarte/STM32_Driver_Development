#include "led.h"
#include "power_led.h"
#include "medical_led.h"

	
int main() 
{
	USART2_Init();
	
	MedicalLed_t mled1; 
	
	MedicalLed_ctor(&mled1, INFARED, (led_color_t)INFARED, ON); 
	
	while(1) {
		
	}
}