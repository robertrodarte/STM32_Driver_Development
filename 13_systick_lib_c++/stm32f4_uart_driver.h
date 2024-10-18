#ifndef __STM32F4_UART_DRIVER_H
#define __STM32F4_UART_DRIVER_H

#include "stm32f4_gpio_driver.h"

#define __IO volatile
	 
#define APB1PERIPH_BASE 		(PERIPH_BASE)
#define USART2_BASE					(APB1PERIPH_BASE + 0x4400U)

typedef struct {
	__IO uint32_t SR; 	// Status register
	__IO uint32_t DR;		// Data register
	__IO uint32_t BRR;	// Baud Rate Register
	__IO uint32_t CR1;	// Control Register 1
	__IO uint32_t CR2;	// Control Register 2
	__IO uint32_t CR3;	// Control Register 3
	
}USART_t; 

#define USART2 ((USART_t *)USART2_BASE)

#endif