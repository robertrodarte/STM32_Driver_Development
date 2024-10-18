#ifndef __STM32F4_SYSTICK_LIB_H
#define __STM32F4_SYSTICK_LIB_H

#include "stm32f4_systick_driver.h"

void LIB_SYSTICK_Delay(uint32_t seconds);
void LIB_SYSTICK_DelayMS(uint32_t millis);

#endif