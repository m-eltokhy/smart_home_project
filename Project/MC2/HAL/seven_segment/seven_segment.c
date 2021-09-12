/*
 * seven_segment.c
 *
 *  Created on: Aug 1, 2021
 *      Author: M.Eltokhy
 */

#include "seven_segment.h"

void seven_display_number(uint8 n) {
	uint8 u = n % 10;
	DIO_Write(PORT_B1, High);
	DIO_Write(PORT_B2, Low);
	DIO_Write(PORT_A4,!GET_BIT(u,0));
	DIO_Write(PORT_A5,!GET_BIT(u,1));
	DIO_Write(PORT_A6,!GET_BIT(u,2));
	DIO_Write(PORT_A7,!GET_BIT(u,3));
	_delay_us(100);
	u = n / 10;
	DIO_Write(PORT_B1, Low);
	DIO_Write(PORT_B2, High);
	DIO_Write(PORT_A4,!GET_BIT(u,0));
	DIO_Write(PORT_A5,!GET_BIT(u,1));
	DIO_Write(PORT_A6,!GET_BIT(u,2));
	DIO_Write(PORT_A7,!GET_BIT(u,3));
	_delay_us(100);
}

