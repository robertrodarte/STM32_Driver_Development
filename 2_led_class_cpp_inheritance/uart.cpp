#include "uart.h"

void USART2_init()
{
	// 1. Enable clock access to uart (USART - Bit 17)
	RCC->APB1ENR |= 0x20000; 
	// 2. Enable clock access to portA
	RCC->AHB1ENR |= 0x01; 
	// 3. Enable pins for alternate functions
	// 		RX - PA2
	// 		TX - PA3
	GPIOA->MODER &= ~0x00F0;
	GPIOA->MODER |= 0x00A0; // Enable alt function for PA2/3
	// 4. Configure type of alternate function 
	GPIOA->AFR[0] &= ~0xFF00; 
	GPIOA->AFR[0] |= 0x7700; 

	// 5. Configure UART
	USART2->BRR = 0x0683;
	USART2->CR1 = 0x000c; 
	USART2->CR2 = 0x000; 
	USART2->CR3 = 0x000;
	USART2->CR1 |= 0x2000;
}

// Write data to console
int USART2_write(int ch)
{
	while(!(USART2->SR & 0x0080)){}
	USART2->DR = (ch & 0xff); 
	return ch;
}

// Read data from console
int USART2_read() 
{
	while(!(USART2->SR & 0x0020)){}
	return USART2->DR; 
}
