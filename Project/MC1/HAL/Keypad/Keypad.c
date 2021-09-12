/*
 * Keypad.c
 *
 *  Created on: Aug 1, 2021
 *      Author: M.Eltokhy
 */

#include "Keypad.h"

uint8 key[4][4] = { { '1', '4', '7', 'C' },
					{ '2', '5', '8', '0' },
					{ '3', '6', '9', '#' },
					{ '+', '-', '*', '/' } };

void keypad_Init(void) {
	DDRC = 0xf0;
}

uint8 get_key(void) {
	uint8 i,j,ch;
	for (i=0; i < 4; i++) {
		PORTC &= 0x0f;
		DIO_Write(20 + i, High);
		_delay_ms(250);
		for (j=0; j < 4; j++) {
			_delay_ms(250);
			if (DIO_Read(16+j)) {
				ch=key[i][j];
			}
		}
	}
	return ch;
}
