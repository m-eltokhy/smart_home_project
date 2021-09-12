/*
 * DIO.h
 *
 *  Created on: Jul 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "DIO_types.h"

void DIO_Write(Dio_Pin, Dio_Status_Type);
void DIO_Port_Write(Dio_Port_Type,uint8);
Dio_Status_Type DIO_Read(Dio_Pin);
void DIO_Init(void);

#endif /* DIO_H_ */

