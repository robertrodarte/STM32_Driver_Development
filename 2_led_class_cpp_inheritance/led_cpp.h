#ifndef LED_H
#define LED_H

#include "stm32f4xx.h"                  // Device header
#include "uart_cpp.h"
#include <stdint.h>

#define LED_PORT (GPIOB)

#define LED_PORT_CLOCK (1U<<1)

#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<13)

#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_BLUE_MODE_BIT (1U<<30)
#define LED_YELLOW_MODE_BIT (1U<<26)

typedef enum {
	RED = 0,
	GREEN = 1, 
	YELLOW = 2, 
	BLUE = 3
}led_color_t; 

typedef enum {
	OFF = 0, 
	ON = 1
}led_state_t;

class led{
	// LED's attritbutes
	private:
		led_color_t color; // Color of LED
		led_state_t state; // State of LED
	
	// LED constructor
	public:
		led(led_color_t _color, led_state_t _state);
	  void set_state(led_state_t _state);
		led_state_t get_state()const; 
};

#endif