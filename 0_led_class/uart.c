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

/* The code below is the interface to the C standard I/O library.
 * All the I/O are directed to the console.
 */
struct __FILE { int handle; };
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};


int fgetc(FILE *f) {
    int c;

    c = USART2_read();      /* read the character from console */

    if (c == '\r') {        /* if '\r', after it is echoed, a '\n' is appended*/
        USART2_write(c);    /* echo */
        c = '\n';
    }

    USART2_write(c);        /* echo */

    return c;
}


/* Called by C library console/file output */
int fputc(int c, FILE *f) {
    return USART2_write(c);  /* write the character to console */
}


int n;
char str[80];
		
void test_setup(void){
	
	printf("please enter a number: ");
	scanf("%d", &n);
	printf("the number entered is: %d\r\n", n);
	printf("please type a character string: ");
	gets(str);
	printf("the character string entered is: ");
	puts(str);
	printf("\r\n");
	
}