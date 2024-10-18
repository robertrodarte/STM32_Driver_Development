#ifndef __STM32F4_UART_LIB_H
#define __STM32F4_UART_LIB_H

#include "stm32f4_uart_driver.h"

typedef enum {
	RX_ONLY = 0, 
	TX_ONLY, 
	RX_AND_TX, 
	
}UART_Com_t; 

typedef enum {
	_115200 = 0, 
	_9600,
	// Add more baud here if needed
	
}UART_BaudRate_t;

class UARTComm{	
	private:
		UART_Com_t comType; 
		UART_BaudRate_t baudRate;
	
	public:
		UARTComm(UART_Com_t _comType, UART_BaudRate_t _baudRate);
		char LIB_UART_READ() const;
		void LIB_UART_WRITE(int ch);
		UART_Com_t getCommType() const; 
		UART_BaudRate_t getBaudRate() const;
};

#endif