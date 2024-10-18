#ifndef __STM32F4_SYSTICK_DRIVER_H
#define __STM32F4_SYSTICK_DRIVER_H

#include "stdint.h"

#define __IOM volatile // Read/Write structure member permission
#define __OM volatile // Write only structure member permission
#define __IM volatile // Read only structure member permission
	
#define SCB_BASE 				(0xE000E000UL) // System control base address
#define SysTick_Offset 	(0x010UL)
#define SysTick_BASE 		(SCB_BASE + SysTick_Offset)

typedef struct {
	
	__IOM uint32_t CTRL;
	__IOM uint32_t LOAD; 
	__IOM uint32_t VAL;
	__IM  uint32_t CALIB;
	
}SysTick_t; 

#define SysTick ((SysTick_t *)(SysTick_BASE)) // SysTick config structure
	
#endif