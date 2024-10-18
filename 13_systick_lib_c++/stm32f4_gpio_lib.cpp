#include "stm32f4_gpio_lib.h"

#define GPIO_NUM 					   (16U)
#define GPIO_MODER_MODE0 	   (0x3U << 0)
#define GPIO_MODE 				   (0x03U)
#define GPIO_PUPDR_PUPDR0    (0x3U << 0)
#define GPIO_OSPEEDR_OSPEED0 (0x3U << 0)
#define GPIO_OTYPER_OT0 		 (0x1U << 0)
#define GPIO_OUTPUT_TYPE		 (0x10U)

Gpio::Gpio(PORT_Name_t GPIO_PortName, GPIO_t * GPIOx, GPIO_Init_t *GPIO_init)
{
	// Enable clock of specified port
	switch(GPIO_PortName) {
		case PORTA: 
			__lib_rcc_gpioa_clk_enable(); 
			break; 
		case PORTB: 
			__lib_rcc_gpiob_clk_enable(); 
			break; 
		case PORTC: 
			__lib_rcc_gpioc_clk_enable(); 
			break; 		
		case PORTD: 
			__lib_rcc_gpiod_clk_enable(); 
			break;
		case PORTE: 
			__lib_rcc_gpioe_clk_enable(); 
			break;
		case PORTH: 
			__lib_rcc_gpioh_clk_enable(); 
			break;
		default:
			break; 
	}
	
	uint32_t position; 
	uint32_t temp = 0x00U;
	uint32_t ioposition = 0x00U; 
	uint32_t iocurrent = 0x00U;  
	
	// Configure the port pins
	for(position = 0U; position < GPIO_NUM; position++) {
		// Get IO position
		ioposition = 0x01U << position; 
		// Get the current IO position
		iocurrent = (uint32_t)(GPIO_init->PIN) & ioposition; 
		
		if(iocurrent == ioposition) {
			
			// Configure IO direction mode (Input, Output)
			temp = GPIOx->MODER; 
			temp &= ~(GPIO_MODER_MODE0 << (position * 2U));
			temp |= ((GPIO_init->MODE & GPIO_MODE) << (position * 2U)); 
			GPIOx->MODER = temp;
				
			// Activate the Pull-up or Pull-down resistor for the current IO
			temp = GPIOx->PUPDR;
			temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
			temp |= ((GPIO_init->PULL) << (position * 2U));
			GPIOx->PUPDR = temp; 
		}	
	}
}

GPIO_PIN_STATE_t Gpio::lib_gpio_read_pin(GPIO_t * GPIOx, uint16_t GPIO_pin)
{
	GPIO_PIN_STATE_t bitstatus; 
	
	if((GPIOx->IDR & GPIO_pin) != (uint32_t)(GPIO_PIN_RESET)) {
		bitstatus = GPIO_PIN_SET; 
	}
	else {
		bitstatus = GPIO_PIN_RESET; 
	}
	
	return bitstatus;
}


void Gpio::lib_gpio_write_pin(GPIO_t *GPIOx, uint16_t GPIO_pin, GPIO_PIN_STATE_t pin_state)
{
	if(pin_state != GPIO_PIN_RESET) {
		GPIOx->BSRR = GPIO_pin; 
	}
	else {
		GPIOx->BSRR = (uint32_t)GPIO_pin << 16; 
	}
}


void Gpio::lib_gpio_toggle_pin(GPIO_t *GPIOx, uint16_t GPIO_pin)
{
	GPIOx->ODR ^= GPIO_pin; 
}

void Gpio::__lib_rcc_gpioa_clk_enable()const {RCC->AHB1ENR |= GPIOA_EN;}
void Gpio::__lib_rcc_gpiob_clk_enable()const {RCC->AHB1ENR |= GPIOB_EN;}
void Gpio::__lib_rcc_gpioc_clk_enable()const {RCC->AHB1ENR |= GPIOC_EN;}
void Gpio::__lib_rcc_gpiod_clk_enable()const {RCC->AHB1ENR |= GPIOD_EN;}
void Gpio::__lib_rcc_gpioe_clk_enable()const {RCC->AHB1ENR |= GPIOE_EN;}
void Gpio::__lib_rcc_gpioh_clk_enable()const {RCC->AHB1ENR |= GPIOH_EN;}

GPIO_Init_t __gpio_pin_params(pinData_t _Mode, pinData_t _Pin, pinData_t _Pull)
{
	GPIO_Init_t pinGPIO_InitStruct;
	
	pinGPIO_InitStruct.MODE = _Mode; 
	pinGPIO_InitStruct.PIN = _Pin; 
	pinGPIO_InitStruct.PULL = _Pull; 

	return pinGPIO_InitStruct;
}














