#include "medical_led.h"
#include "uart.h"

void MedicalLed_ctor(MedicalLed_t * const me, 
										 LedWaveLength_t _wavelength, 
										 led_color_t _color, 
										 led_state_t _state)
{
	static const struct LedVtable vtable = {
		(void(*)(led_t const * const me))&MedicalLed_runDiagnostics,
		(uint32_t(*)(led_t const * const me))&MedicalLed_computeEfficiency,
	};
	
	led_ctor(&me->super, _color, _state); 
	
	me->super.vptr = &vtable; 
	
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

uint32_t MedicalLed_computeEfficiency(MedicalLed_t const * const me)
{
	// Dummy efficinecy computation
	// This stuff is made up and used for example
	const int8_t input = 120; 
	const int8_t output = 86; 
	const int8_t k1 = 4; 
	const int8_t k2 = 6; 
	
	int8_t K; 
	
	// If wavelength == IR K=4 else K=6
	K = me->wavelength == INFARED ? k1 : k2; 
	
	int8_t eff = ((input/output)*100) - K; 
	
	return eff; 
	
}

void MedicalLed_runDiagnostics(MedicalLed_t const * const me)
{
	// Dummy diagnostics
	for(int i=0; i<20; i++) {
		printf("Medical LED diagnostics stage: %d... \n\r", i);
		
		// Do something here... 
	}
}


