#include "stm32f4_systick_lib.h"

#include "stm32f4_systick_lib.h"

SYSTICK::SYSTICK() 
{
	// Constructor
}

void SYSTICK::LIB_SYSTICK_Delay(uint32_t seconds)
{
	uint32_t i; 
	
	// Configure SysTick (1 second delay)
	SysTick->LOAD = 16000000 - 1; 
	SysTick->VAL = 0; // Clears current value register
	SysTick->CTRL = 5; // Enables timer with no interrupt
	
	for(i = 0; i < seconds; i++) {
		// Wait until COUNTFLAG is set
		while((SysTick->CTRL & 0x10000) == 0) {}
	}
	
	// Stop the timer
	SysTick->CTRL = 0;
}

void SYSTICK::LIB_SYSTICK_DelayMS(uint32_t millis)
{
	uint32_t i; 
	
	// Configure SysTick (1 second delay)
	SysTick->LOAD = 16000 - 1; 
	SysTick->VAL = 0; // Clears current value register
	SysTick->CTRL = 5; // Enables timer with no interrupt
	
	for(i = 0; i < millis; i++) {
		// Wait until COUNTFLAG is set
		while((SysTick->CTRL & 0x10000) == 0) {}
	}
	
	// Stop the timer
	SysTick->CTRL = 0;
}