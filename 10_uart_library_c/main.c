#include "stm32f4_uart_lib.h"

int main()
{
	LIB_UART_Init(TX_ONLY, _115200);
	
	while(1) {
		LIB_UART_WRITE('Y'); 
	}
}
