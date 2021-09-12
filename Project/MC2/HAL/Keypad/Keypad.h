/*
 * Keypad.h
 *
 *  Created on: Aug 1, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"

void keypad_Init(void);
uint8 get_key(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
