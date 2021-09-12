/*
 * Keypad.h
 *
 *  Created on: Aug 1, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

void keypad_Init(void);
uint8 get_key(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
