#ifndef LED_H
#define LED_H

#include "stm32f4xx.h"                  // Device header
#include "uart.h"
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

// LED's attritbutes
typedef struct {
	struct LedVtable const *vptr; // Virtual pointer
	led_color_t color; // Color of LED
	led_state_t state; // State of LED
	
}led_t;

// LED virtual table
struct LedVtable{
	void (*run_diagnostics)(led_t const * const me);
	uint32_t (*compute_efficiency)(led_t const * const me);
	
};

// LED constructor
void led_ctor(led_t * const me, led_color_t _color, led_state_t _state);
void led_set_state(led_t * const me, led_state_t _state);
led_state_t led_get_state(led_t * const me); 

// Method 1
static inline void led_runDiagnostics_vcall(led_t const * const me)
{
	(*me->vptr->run_diagnostics)(me); 
}

static inline uint32_t led_computeEffi_vcall(led_t const * const me)
{
	return (*me->vptr->compute_efficiency)(me); 
}

// Method 2 
#define LED_RUN_DIAG_VCALL(me) (*(me)->vptr->run_diagnostics)(me)
#define LED_GET_EFFICIENCY(me) (*(me)->vptr->compute_efficiency)(me)

void runSystemDiagnostics(led_t const * led_modules[]); 
void computeLedEffs(led_t const * led_modules[]); 

#endif