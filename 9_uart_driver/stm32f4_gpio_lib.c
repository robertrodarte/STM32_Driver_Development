#include "stm32f4_gpio_lib.h"

#define GPIO_NUM 					   (16U)
#define GPIO_MODER_MODE0 	   (0x3U << 0)
#define GPIO_MODE 				   (0x03U)
#define GPIO_PUPDR_PUPDR0    (0x3U << 0)
#define GPIO_OSPEEDR_OSPEED0 (0x3U << 0)
#define GPIO_OTYPER_OT0 		 (0x1U << 0)
#define GPIO_OUTPUT_TYPE		 (0x10U)

void lib_gpio_init(GPIO_t * GPIOx, GPIO_INIT_t *GPIO_init)
{
	uint32_t position; 
	uint32_t ioposition = 0x00U; 
	uint32_t iocurrent = 0x00U; 
	uint32_t temp = 0x00U; 
	
	// Configure the port pins
	for(position = 0U; position < GPIO_NUM; position++) {
		// Get IO position
		ioposition = 0x01U << position; 
		// Get the current IO position
		iocurrent = (uint32_t)(GPIO_init->PIN) & ioposition; 
		
		if(iocurrent == ioposition) {
			// Alternate function selection
			if((GPIO_init->MODE == GPIO_MODE_AF_PP) || (GPIO_init->MODE == GPIO_MODE_AF_OD)){
				temp = GPIOx->AFR[position >> 3U]; 
				temp &= ~(0xFU << ((uint32_t)position & 0x07U)* 4U);
				temp |= ((uint32_t)(GPIO_init->ALTERNATE) << (((uint32_t)position & 0x07U) * 4U)); 
				GPIOx->AFR[position >> 3U] = temp; 
			}
			
			// Configure IO direction mode (Input, Output)
			temp = GPIOx->MODER; 
			temp &= ~(GPIO_MODER_MODE0 << (position * 2U));
			temp |= ((GPIO_init->MODE & GPIO_MODE) << (position * 2U)); 
			GPIOx->MODER = temp;
			
			// Alternate function selection
			if((GPIO_init->MODE == GPIO_MODE_OUTPUT_PP) || (GPIO_init->MODE == GPIO_MODE_OUTPUT_OD)
					|| (GPIO_init->MODE == GPIO_MODE_AF_PP)|| (GPIO_init->MODE == GPIO_MODE_AF_OD)) {
							
			  temp = GPIOx->OSPEEDR; 
				temp &= ~(GPIO_OSPEEDR_OSPEED0 << (position *2U)); 
				temp |= (GPIO_init->SPEED << (position * 2U)); 
				GPIOx->OSPEEDR = temp; 
						
				// Configure output type
				temp = GPIOx->OTYPER; 
				temp &= ~(GPIO_OTYPER_OT0 << (position *2U));
				temp |= (((GPIO_init->MODE & GPIO_OUTPUT_TYPE) >> 4U ) << (position * 2U)); 
				GPIOx->OTYPER = temp; 
			}
				
			// Activate the Pull-up or Pull-down resistor for the current IO
			temp = GPIOx->PUPDR;
			temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
			temp |= ((GPIO_init->PULL) << (position * 2U));
			GPIOx->PUPDR = temp; 
		}	
	}
}

GPIO_PIN_STATE_t lib_gpio_read_pin(GPIO_t * GPIOx, uint16_t GPIO_pin)
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


void lib_gpio_write_pin(GPIO_t *GPIOx, uint16_t GPIO_pin, GPIO_PIN_STATE_t pin_state)
{
	if(pin_state != GPIO_PIN_RESET) {
		GPIOx->BSRR = GPIO_pin; 
	}
	else {
		GPIOx->BSRR = (uint32_t)GPIO_pin << 16; 
	}
}


void lib_gpio_toggle_pin(GPIO_t *GPIOx, uint16_t GPIO_pin)
{
	GPIOx->ODR ^= GPIO_pin; 
}

void __lib_rcc_gpioa_clk_enable(void) {RCC->AHB1ENR |= GPIOA_EN;}
void __lib_rcc_gpiob_clk_enable(void) {RCC->AHB1ENR |= GPIOB_EN;}
void __lib_rcc_gpioc_clk_enable(void) {RCC->AHB1ENR |= GPIOC_EN;}
void __lib_rcc_gpiod_clk_enable(void) {RCC->AHB1ENR |= GPIOD_EN;}
void __lib_rcc_gpioe_clk_enable(void) {RCC->AHB1ENR |= GPIOE_EN;}
void __lib_rcc_gpioh_clk_enable(void) {RCC->AHB1ENR |= GPIOH_EN;}














