/*
 * ADC_Config.h
 *
 *  Created on: Aug 8, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#define DISABLE 	0
#define ENABLE		1

#define ADC_Enable ENABLE

#define ADC_SOURCE_INTERNAL		0
#define ADC_SOURCE_AVC			1
#define ADC_SOURCE_RESERVED		2
#define ADC_SOURCE_VREF			3	//2.56v

#define ADC_Source	ADC_SOURCE_VREF

#define ADC_PRESCALER_2		0
#define ADC_PRESCALER_4		2
#define ADC_PRESCALER_8		3
#define ADC_PRESCALER_16	4
#define ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define ADC_PRESCALER_128	7

#define ADC_prescaler	ADC_PRESCALER_128

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
