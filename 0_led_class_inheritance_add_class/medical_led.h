#ifndef _MEDICAL_LED_H
#define _MEDICAL_LED_H

#include "led.h"

typedef enum {
	
	INFARED = 910, 
	NEAR_INFARED = 880, 
	
}LedWaveLength_t; 

typedef struct {

	led_t super; 
	LedWaveLength_t wavelength; 
	
}MedicalLed_t; 

void MedicalLed_ctor(MedicalLed_t * const me, 
										 LedWaveLength_t _wavelength, 
										 led_color_t _color, 
										 led_state_t _state); 

LedWaveLength_t MedicalLed_getWavelength(MedicalLed_t * const me);
void MedicalLed_setWavelength(MedicalLed_t * const me, LedWaveLength_t wavelength);

#endif