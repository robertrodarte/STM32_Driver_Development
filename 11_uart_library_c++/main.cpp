#include "stm32f4_uart_lib.h"

int main()
{
	UARTComm USARTtest(TX_ONLY, _115200);
	
	while(1) {
		USARTtest.LIB_UART_WRITE('H');
		USARTtest.LIB_UART_WRITE('E');
		USARTtest.LIB_UART_WRITE('L');
		USARTtest.LIB_UART_WRITE('L');
		USARTtest.LIB_UART_WRITE('O');
		USARTtest.LIB_UART_WRITE('\r');
		USARTtest.LIB_UART_WRITE('\n');
	}
}
