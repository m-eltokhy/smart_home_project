/*
 * ADC.c
 *
 *  Created on: Aug 8, 2021
 *      Author: M.Eltokhy
 */

#include "ADC.h"

void adc_init(void) {
	//Enable ADC
#if ADC_Enable == ENABLE
	SET_BIT(ADCSRA, ADEN);
	//set vref
	ADMUX |= (ADC_Source << 6);
	//set prescaler
	ADCSRA |= ADC_prescaler;
#endif

}

uint16 adc_read(uint8 ch) {
	//choose channel
	ADMUX = (ADMUX & 0xe0) | (ch & 0x1f);
	//start conversion
	SET_BIT(ADCSRA, ADSC);
	//wait for conversion
	while (!GET_BIT(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}
