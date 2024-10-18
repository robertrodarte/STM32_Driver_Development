#include "led.h"

static void run_diagnostics(led_t const * const me);
static uint32_t compute_efficiency(led_t const * const me);

void led_ctor(led_t * const me, led_color_t _color, led_state_t _state)
{
	// Initialize virtual table 
	static const struct LedVtable vtable = {
		&run_diagnostics, 
		&compute_efficiency, 
	}; 
	
	me->vptr = &vtable; 
	
	me->color = _color;
	me->state = _state; 
	
	// HARDWARE INIT
	RCC->AHB1ENR |= LED_PORT_CLOCK; // Enable the AHPB 
	
	switch(_color) {
		case RED: 
			LED_PORT->MODER |= LED_RED_MODE_BIT; // Make red pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_RED_PIN;
				printf("The red LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_RED_PIN;
				printf("The red LED is set off \n\r"); 				
			}
			break; 
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Make green pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_GREEN_PIN;
				printf("The red LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_GREEN_PIN;
				printf("The red LED is set off \n\r"); 				
			}
			break;  
		case BLUE: 
			LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Make blue pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_BLUE_PIN;
				printf("The red LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_BLUE_PIN;
				printf("The red LED is set off \n\r"); 				
			}
			break;
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Make yellow pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_YELLOW_PIN;
				printf("The red LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_YELLOW_PIN;
				printf("The red LED is set off \n\r"); 				
			}
			break; 
	}
	
}

void led_set_state(led_t * const me, led_state_t _state)
{
	me->state = _state; 
	
	switch(me->color) {
		case RED: 
			LED_PORT->MODER |= LED_RED_MODE_BIT; // Make red pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_RED_PIN;
				printf("The red LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_RED_PIN;
				printf("The red LED is set off \n\r"); 				
			}
			break; 
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Make green pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_GREEN_PIN;
				printf("The green LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_GREEN_PIN;
				printf("The green LED is set off \n\r"); 				
			}
			break;  
		case BLUE: 
			LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Make blue pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_BLUE_PIN;
				printf("The blue LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_BLUE_PIN;
				printf("The blue LED is set off \n\r"); 				
			}
			break;
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Make yellow pin a GPIO
			if(me->state == ON) {
				LED_PORT->MODER |= LED_YELLOW_PIN;
				printf("The yellow LED is set on \n\r"); 
			}
			else {
				LED_PORT->MODER &= ~LED_YELLOW_PIN;
				printf("The yellow LED is set off \n\r"); 				
			}
			break; 
	}
}

led_state_t led_get_state(led_t * const me)
{
		switch(me->color){
		case RED:
			printf("The red LED is currently %d \n\r", me->state);
			break;
		case GREEN:
			printf("The green LED is currently %d \n\r", me->state);
			break;
		case YELLOW:
			printf("The yellow LED is currently %d \n\r", me->state);
			break;
		case BLUE:
			printf("The blue LED is currently %d \n\r", me->state);
			break;
	}
		
	return me->state; 
}

static void run_diagnostics(led_t const * const me) // Neither the pointer me or the led_t struct can be modified in this fuction. 
{																									  
	(void)me; 
}

static uint32_t compute_efficiency(led_t const * const me)
{
	(void)me;
	return 0U; 
}

// Polymorphism at work 

void runSystemDiagnostics(led_t const * led_modules[])
{
	int i; 
	for(i = 0; led_modules[i] != (led_t *)0; i++) {
		led_runDiagnostics_vcall(led_modules[i]); 
	}
}
void computeLedEffs(led_t const * led_modules[])
{
	int i; 
	for(i = 0; led_modules[i] != (led_t *)0; i++) {
		led_computeEffi_vcall(led_modules[i]); 
	}
}
	







