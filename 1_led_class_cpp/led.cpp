#include "led_cpp.h"

led::led(led_color_t _color, led_state_t _state)
// Option 2
:color(_color),
state(_state)
{
	// Option 1 (common)
	this->color = _color;
	this->state = _state; 
	
	// HARDWARE INIT
	RCC->AHB1ENR |= LED_PORT_CLOCK; // Enable the AHPB 
	
	switch(_color) {
		case RED: 
			LED_PORT->MODER |= LED_RED_MODE_BIT; // Make red pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_RED_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_RED_PIN;
			}
			break; 
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Make green pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_GREEN_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_GREEN_PIN;		
			}
			break;  
		case BLUE: 
			LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Make blue pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_BLUE_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_BLUE_PIN;				
			}
			break;
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Make yellow pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_YELLOW_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_YELLOW_PIN;			
			}
			break; 
	}
	
}

void led::set_state(led_state_t _state)
{
	this->state = _state; 
	
	switch(this->color) {
		case RED: 
			LED_PORT->MODER |= LED_RED_MODE_BIT; // Make red pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_RED_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_RED_PIN;				
			}
			break; 
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Make green pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_GREEN_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_GREEN_PIN;	
			}
			break;  
		case BLUE: 
			LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Make blue pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_BLUE_PIN;
			}
			else {
				LED_PORT->MODER &= ~LED_BLUE_PIN;			
			}
			break;
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Make yellow pin a GPIO
			if(this->state == ON) {
				LED_PORT->MODER |= LED_YELLOW_PIN; 
			}
			else {
				LED_PORT->MODER &= ~LED_YELLOW_PIN;				
			}
			break; 
	}
}

led_state_t led::get_state(void)const
{
		switch(this->color){
		case RED:
			break;
		case GREEN:
			break;
		case YELLOW:
			break;
		case BLUE:
			break;
	}
		
	return this->state; 
}