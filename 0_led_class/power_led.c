#include "stm32f4xx.h"                  // Device header
#include "power_led.h"

void power_led_ctor(power_led_t * const me, led_color_t _color, 
										led_state_t _state, led_diameter_t _diameter, led_current_t _current, led_voltage_t _voltage)
{
	// Initialize power LED
	led_ctor(&me->super, _color, _state); // (LED type is super)
	me->diameter = _diameter; 
	me->voltage = _voltage; 
	me->current = _current;
}

void power_led_set_current(power_led_t * const me, led_current_t _current)
{
	me->current = _current;
}

void power_led_set_diameter(power_led_t * const me, led_diameter_t _diameter)
{
	me->diameter = _diameter; 
}

void power_led_set_voltage(power_led_t * const me, led_voltage_t _voltage)
{
	me->voltage = _voltage; 
}

led_electrical_t power_led_compute_power(power_led_t * const me)
{
	return ((me->current) * (me->voltage)); 
}	

led_current_t power_led_get_current(power_led_t * const me)
{
	return me->current; 
}

led_diameter_t power_led_get_diameter(power_led_t * const me)
{
	return me->diameter; 
}

led_voltage_t power_led_get_voltage(power_led_t * const me)
{
	return me->voltage;
}	