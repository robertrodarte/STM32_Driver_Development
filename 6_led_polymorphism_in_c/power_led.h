#ifndef _POWER_LED_H
#define _POWER_LED_H

#include "led.h"

typedef uint8_t led_electrical_t; 
typedef uint8_t led_dim_t; 

typedef enum {
	
	CURR_LOW = 10, // 10mA
	CURR_NORMAL = 20, 
	CURR_HIGH = 35, 
	CURR_VERY_HIGH = 60,
	
}led_current_t; 

typedef enum {
	
	DIAMETER_2MM = 2, // 2mm 
	DIAMETER_5MM = 5, 
	DIAMETER_7MM = 7, 

}led_diameter_t; 

typedef enum {
	
	VOLTAGE_LOW = 3, // 3V
	VOLTAGE_NORMAL = 5,
	VOLTAGE_HIGH = 9, 
	
}led_voltage_t; 

typedef struct{
	
	led_t super;
	led_current_t current; 
	led_diameter_t diameter;
	led_voltage_t voltage; 
	
}power_led_t; 

void power_led_ctor(power_led_t * const me, led_color_t _color, 
										led_state_t _state, led_diameter_t _diameter, 
										led_current_t _current, led_voltage_t _voltage); 

void power_led_set_current(power_led_t * const me, led_current_t _current);
void power_led_set_diameter(power_led_t * const me, led_diameter_t _diameter);
void power_led_set_voltage(power_led_t * const me, led_voltage_t _voltage); 

led_electrical_t power_led_compute_power(power_led_t * const me); 
led_current_t power_led_get_current(power_led_t * const me); 
led_diameter_t power_led_get_diameter(power_led_t * const me); 
led_voltage_t power_led_get_voltage(power_led_t * const me); 

uint32_t PowerLed_computeEfficiency(power_led_t const * const me);
void PowerLed_runDiagnostics(power_led_t const * const me); 


#endif