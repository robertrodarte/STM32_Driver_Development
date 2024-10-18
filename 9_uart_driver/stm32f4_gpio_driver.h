#ifndef __STM32F4_GPIO_DRIVER_H__
#define __STM32F4_GPIO_DRIVER_H__

#include <stdint.h>

// Bare Metal Programming
#define PERIPH_BASE 			(0x40000000U)
#define AHB1_PERIPH_BASE 	(PERIPH_BASE + 0x00020000U)

#define RCC_BASE 					(AHB1_PERIPH_BASE + 0x00003800U)

#define GPIOA_BASE 				(AHB1_PERIPH_BASE)
#define GPIOB_BASE 				(AHB1_PERIPH_BASE + 0x00000400U)
#define GPIOC_BASE 				(AHB1_PERIPH_BASE + 0x00000800U)
#define GPIOD_BASE 				(AHB1_PERIPH_BASE + 0x00000C00U)
#define GPIOE_BASE 				(AHB1_PERIPH_BASE + 0x0001000U)
#define GPIOH_BASE 				(AHB1_PERIPH_BASE + 0x0001C00U)

#define __IO volatile 
	
typedef struct 
{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER; 
	__IO uint32_t OSPEEDR; 
	__IO uint32_t PUPDR; 
	__IO uint32_t IDR; 
	__IO uint32_t ODR; 
	__IO uint32_t BSRR; 
	__IO uint32_t LCKR; 
	__IO uint32_t AFR[2]; // AFR Low = 0, AFR High = 1 
	
}GPIO_t; 

typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR; 
	__IO uint32_t CFGR; 
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
			 uint32_t PAD1[2]; // Memory Padding 
	__IO uint32_t APB1RSTR; 
	__IO uint32_t APB2RSTR;
			 uint32_t PAD2[2]; // Memory Padding
	__IO uint32_t AHB1ENR; 
	__IO uint32_t AHB2ENR; 
			 uint32_t PAD3[2]; // Memory Padding
	__IO uint32_t APB1ENR; 
	__IO uint32_t APB2ENR; 
		   uint32_t PAD4[2]; // Memory Padding
	__IO uint32_t AHB1LPENR; 
	__IO uint32_t AHB2LPENR; 
			 uint32_t PAD5[2]; // Memory Padding
	__IO uint32_t APB1LPENR; 
	__IO uint32_t APB2LPENR; 
			 uint32_t PAD6[2]; // Memory Padding
	__IO uint32_t BDCR; 
	__IO uint32_t CSR;
			 uint32_t PAD7[2]; // Memory Padding
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR; 
	     uint32_t PAD8;  // Memory Padding
	__IO uint32_t DCKCFGR; 
	
}RCC_t; 

#define RCC	((RCC_t*)RCC_BASE) // RCC is defined as a pointer, to the RCC_BASE memory address, that holds a RCC_t structure
#define GPIOA ((GPIO_t*)GPIOA_BASE) // GPIOA is defined as pointer, to the GPIOA_BASE memory address, that holds a GPIO_t structure
#define GPIOB ((GPIO_t*)GPIOB_BASE)
#define GPIOC ((GPIO_t*)GPIOC_BASE)
#define GPIOD ((GPIO_t*)GPIOD_BASE)
#define GPIOE ((GPIO_t*)GPIOE_BASE)
#define GPIOH ((GPIO_t*)GPIOH_BASE)

#define MODER_5_OUT (1<<10)
#define LED_PIN (1<<5)

#define GPIOA_EN (1<<0)
#define GPIOB_EN (1<<1)
#define GPIOC_EN (1<<2)
#define GPIOD_EN (1<<3)
#define GPIOE_EN (1<<4)
#define GPIOH_EN (1<<7)

#endif