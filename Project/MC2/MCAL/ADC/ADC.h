/*
 * ADC.h
 *
 *  Created on: Aug 8, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include <avr/interrupt.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "ADC_Config.h"

void adc_init(void);
uint16 adc_read(uint8);


#endif /* MCAL_ADC_ADC_H_ */
