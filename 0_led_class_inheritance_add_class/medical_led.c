#include "medical_led.h"

void MedicalLed_ctor(MedicalLed_t * const me, 
										 LedWaveLength_t _wavelength, 
										 led_color_t _color, 
										 led_state_t _state)
{
	
	led_ctor(&me->super, _color, _state); 
	me->wavelength = _wavelength; 
	
}

LedWaveLength_t MedicalLed_getWavelength(MedicalLed_t * const me)
{
	
	return me->wavelength; 
	
}

void MedicalLed_setWavelength(MedicalLed_t * const me, LedWaveLength_t wavelength)
{
	
	me->wavelength = wavelength; 
	
}