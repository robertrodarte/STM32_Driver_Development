#include "stm32f4_uart_driver.h"

void USART2_write(int ch);

int main()
{
	RCC->AHB1ENR |= 1; // Enable GPIOA clock
	RCC->APB1ENR |= 0x20000; // Enable USART2
	GPIOA->AFR[0] |= 0x0700; // Alternate function 7 for USART2
	GPIOA->MODER |= 0x0020; // Enable alternate function 
	
	USART2->BRR = 0x0683; // Set baud to 9600
	USART2->CR1 = 0x0008; // Enable TX, 8-bit data
	USART2->CR2 = 0x0000; // 1 stop bit
	USART2->CR3 = 0x0000; // No flow control
	USART2->CR1 |= 0x2000; // Enable USART
	
	while(1) {
		USART2_write('Y');
		USART2_write('E');
		USART2_write('S');
		USART2_write('\r');
		USART2_write('\n');
		
	}
		
}

void USART2_write(int ch){
	while(!(USART2->SR & 0x0080)) {} // Wait for transfer buffer to be empty
	USART2->DR = (ch & 0xFF);
		
}