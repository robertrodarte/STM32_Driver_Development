#ifndef _POWER_LED_H
#define _POWER_LED_H

#include "led_cpp.h"

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

class power_led:public led{
	
		private:	
			led_current_t current; 
			led_diameter_t diameter;
			led_voltage_t voltage; 
		
		public: 
			power_led(led_color_t _color, led_state_t _state, led_diameter_t _diameter, led_current_t _current, led_voltage_t _voltage); // Constructor doesn't need return type
			void power_led_set_current(led_current_t _current);
			void power_led_set_diameter(led_diameter_t _diameter);
			void power_led_set_voltage(led_voltage_t _voltage); 
			led_electrical_t power_led_compute_power(); 
			led_current_t power_led_get_current(); 
			led_diameter_t power_led_get_diameter(); 
			led_voltage_t power_led_get_voltage(); 
};
#endif