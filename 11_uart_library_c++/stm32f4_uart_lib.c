#include "stm32f4_uart_lib.h"

#define BRR_CNF1_9600   (0x0683) // Set baud to 9600 at 16 MHz 
#define BRR_CNF1_115200 (0x008b) // Set baud to 115200 at 16 MHz 
#define CR1_CNF1_TX 		(0x0008) // Enable TX, 8-bit data
#define CR1_CNF1_RX 		(0x0004) // Enable RX, 8-bit data
#define CR2_CNF1 				(0x0000) // 1 stop bit
#define CR3_CNF1 				(0x0000) // No flow control
#define UART2_CR1_EN 		(0x2000) // Enable USART
#define UART2_CR1_DIS 	(0x0000) // Disable USART

void LIB_UART_Init(UART_Com_t comType, UART_BaudRate_t baudRate)
{
	
	RCC->AHB1ENR |= 1; // Enable GPIO clk
  RCC->APB1ENR |= 0x20000; // Enable USART2 clk
	
	// Disable USART
	USART2->CR1 = UART2_CR1_DIS; 
	
	// Configure USART
	// Set communication type
	switch(comType) {
		case TX_ONLY:
			GPIOA->MODER |= 0x0020; // Enable alternate function at PA2
			GPIOA->AFR[0] |= 0x0700; // Alternate function 7 for USART2
			USART2->CR1 = CR1_CNF1_TX; // Enable TX, 8-bit data
			break;
		
		case RX_ONLY:
			GPIOA->MODER |= 0x0080; // Enable alternate function at PA3
			GPIOA->AFR[0] |= 0x7000; // Alternate function 7 for USART2
			USART2->CR1 = CR1_CNF1_RX; // Enable RX, 8-bit data
			break;
		
		case RX_AND_TX:
			GPIOA->MODER |= 0x0020 | 0x0080; // Enable alternate function at PA2 and PA3
			GPIOA->AFR[0] |= 0x0700 | 0x7000; // Alternate function 7 for USART2
			USART2->CR1 = CR1_CNF1_TX | CR1_CNF1_RX; // Enable TX and RX, 8-bit data
			break;

		default:
			break;
	}
	
	// Set Baud Rate
	switch(baudRate) {
		case _115200: 
			USART2->BRR = BRR_CNF1_115200; // Set baud to 115200 at 16 MHz
			break; 
		
		case _9600:
			USART2->BRR = BRR_CNF1_9600; // Set baud to 9600 at 16 MHz
			break;
		
		default:
			break;
	}
	
	// Universal settings
	USART2->CR2 = CR2_CNF1; // 1 stop bit
	USART2->CR3 = CR3_CNF1; // No flow control
	
	// Enable USART
	USART2->CR1 |= UART2_CR1_EN; // Enable USART
}

char LIB_UART_READ(void) {
	while(!(USART2->SR & 0x0020)) {} // Wait till char arrives
	return USART2->DR;
}

void LIB_UART_WRITE(int ch) {
	while(!(USART2->SR & 0x0080)) {} // Wait for transfer buffer to be empty
	USART2->DR = (ch & 0xFF); // Send character
}





