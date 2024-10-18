#include "stm32f4xx.h"                  // Device header
#include "power_led.h"

power_led::power_led(led_color_t _color, 
										 led_state_t _state, 
										 led_diameter_t _diameter, 
										 led_current_t _current, 
										 led_voltage_t _voltage)
										 :led(_color, _state)
{
	this->current = _current; 
	this->diameter = _diameter; 
	this->voltage = _voltage; 
}

void power_led::power_led_set_current(led_current_t _current)
{
	this->current = _current;
}

void power_led::power_led_set_diameter(led_diameter_t _diameter)
{
	this->diameter = _diameter; 
}

void power_led::power_led_set_voltage(led_voltage_t _voltage)
{
	this->voltage = _voltage; 
}

led_electrical_t power_led::power_led_compute_power()
{
	return ((this->current) * (this->voltage)); 
}	

led_current_t power_led::power_led_get_current()
{
	return this->current; 
}

led_diameter_t power_led::power_led_get_diameter()
{
	return this->diameter; 
}

led_voltage_t power_led::power_led_get_voltage()
{
	return this->voltage;
}	