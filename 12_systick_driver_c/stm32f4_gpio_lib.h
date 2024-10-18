#ifndef __STM32F4_GPIO_LIB_H__
#define __STM32F4_GPIO_LIB_H__

#include "stm32f4_gpio_driver.h"

#define GPIO_PIN_0 		((uint16_t)0x0001)
#define GPIO_PIN_1 		((uint16_t)0x0002)
#define GPIO_PIN_2 		((uint16_t)0x0004)
#define GPIO_PIN_3 		((uint16_t)0x0008)
#define GPIO_PIN_4 		((uint16_t)0x0010)
#define GPIO_PIN_5 		((uint16_t)0x0020)
#define GPIO_PIN_6 		((uint16_t)0x0040)
#define GPIO_PIN_7 		((uint16_t)0x0080)
#define GPIO_PIN_8 		((uint16_t)0x0100)
#define GPIO_PIN_9 		((uint16_t)0x0200)
#define GPIO_PIN_10 	((uint16_t)0x0400)
#define GPIO_PIN_11 	((uint16_t)0x0800)
#define GPIO_PIN_12 	((uint16_t)0x1000)
#define GPIO_PIN_13 	((uint16_t)0x2000)
#define GPIO_PIN_14 	((uint16_t)0x4000)
#define GPIO_PIN_15 	((uint16_t)0x8000)
#define GPIO_PIN_ALL 	((uint16_t)0xFFFF)

#define GPIO_MODE_INPUT 			(0x00U)
#define GPIO_MODE_OUTPUT_PP 	(0x01U)
#define GPIO_MODE_OUTPUT_OD		(0x11U)
#define GPIO_MODE_AF_PP 			(0x02U)
#define GPIO_MODE_AF_OD				(0x12U)

#define GPIO_NO_PULL 		(0x00U)
#define GPIO_PULL_UP 		(0x01U)
#define GPIO_PULL_DOWN 	(0x02U)

typedef struct 
{
	uint32_t PIN; 
	uint32_t MODE;
	uint32_t PULL;
	uint32_t SPEED;
	uint32_t ALTERNATE;	
	
}GPIO_INIT_t; 

typedef enum 
{
	GPIO_PIN_RESET = 0, 
	GPIO_PIN_SET,
	
}GPIO_PIN_STATE_t; 


void lib_gpio_init(GPIO_t * GPIOx, GPIO_INIT_t *GPIO_init); 
GPIO_PIN_STATE_t lib_gpio_read_pin(GPIO_t * GPIOx, uint16_t GPIO_pin);
void lib_gpio_write_pin(GPIO_t *GPIOx, uint16_t GPIO_pin, GPIO_PIN_STATE_t pin_state); 
void lib_gpio_toggle_pin(GPIO_t *GPIOx, uint16_t GPIO_pin); 
void __lib_rcc_gpioa_clk_enable(void); 
void __lib_rcc_gpiob_clk_enable(void);
void __lib_rcc_gpioc_clk_enable(void);
void __lib_rcc_gpiod_clk_enable(void);
void __lib_rcc_gpioe_clk_enable(void);
void __lib_rcc_gpioh_clk_enable(void);
















#endif