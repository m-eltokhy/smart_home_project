/*
 * LCD.c
 *
 *  Created on: Jul 31, 2021
 *      Author: M.Eltokhy
 */

#include "LCD.h"


void lcd_init(void) {
	DDRA|=0xf0;
	DDRB|=0x0e;
	DIO_Write(PORT_B2, Low);
	_delay_ms(20);
	lcd_cmd(0x01);
	lcd_cmd(0x33);
	lcd_cmd(0x32);
	lcd_cmd(0x28);
	lcd_cmd(0x0f);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
//	lcd_cmd(0x80);
}

void lcd_cmd(uint8 cmd) {
	DIO_Write(PORT_B2, Low);
	DIO_Write(PORT_B1, Low);
	(GET_BIT(cmd, 4)) ? DIO_Write(PORT_A4, High) : DIO_Write(PORT_A4, Low);
	(GET_BIT(cmd, 5)) ? DIO_Write(PORT_A5, High) : DIO_Write(PORT_A5, Low);
	(GET_BIT(cmd, 6)) ? DIO_Write(PORT_A6, High) : DIO_Write(PORT_A6, Low);
	(GET_BIT(cmd, 7)) ? DIO_Write(PORT_A7, High) : DIO_Write(PORT_A7, Low);
	DIO_Write(PORT_B3, High);
	_delay_us(10);
	DIO_Write(PORT_B3, Low);
	_delay_us(200);
	(GET_BIT(cmd, 0)) ? DIO_Write(PORT_A4, High) : DIO_Write(PORT_A4, Low);
	(GET_BIT(cmd, 1)) ? DIO_Write(PORT_A5, High) : DIO_Write(PORT_A5, Low);
	(GET_BIT(cmd, 2)) ? DIO_Write(PORT_A6, High) : DIO_Write(PORT_A6, Low);
	(GET_BIT(cmd, 3)) ? DIO_Write(PORT_A7, High) : DIO_Write(PORT_A7, Low);
	DIO_Write(PORT_B3, High);
	_delay_us(10);
	DIO_Write(PORT_B3, Low);
	_delay_us(200);
}

void lcd_data(uint8 data) {
	DIO_Write(PORT_B2, Low);
	DIO_Write(PORT_B1, High);
	(GET_BIT(data, 0)) ? DIO_Write(PORT_A4, High) : DIO_Write(PORT_A4, Low);
	(GET_BIT(data, 1)) ? DIO_Write(PORT_A5, High) : DIO_Write(PORT_A5, Low);
	(GET_BIT(data, 2)) ? DIO_Write(PORT_A6, High) : DIO_Write(PORT_A6, Low);
	(GET_BIT(data, 3)) ? DIO_Write(PORT_A7, High) : DIO_Write(PORT_A7, Low);
	DIO_Write(PORT_B3, High);
	_delay_us(10);
	DIO_Write(PORT_B3, Low);
	_delay_us(200);
	(GET_BIT(data, 4)) ? DIO_Write(PORT_A4, High) : DIO_Write(PORT_A4, Low);
	(GET_BIT(data, 5)) ? DIO_Write(PORT_A5, High) : DIO_Write(PORT_A5, Low);
	(GET_BIT(data, 6)) ? DIO_Write(PORT_A6, High) : DIO_Write(PORT_A6, Low);
	(GET_BIT(data, 7)) ? DIO_Write(PORT_A7, High) : DIO_Write(PORT_A7, Low);
	DIO_Write(PORT_B3, High);
	_delay_us(10);
	DIO_Write(PORT_B3, Low);
	_delay_us(200);
}

void lcd_string(uint8 *str) {
	for (uint8 i = 0; str[i]; i++) {
		if (i == 16) {
			lcd_cmd(0xc0);
		}
		lcd_data(str[i]);
	}
}

void lcd_sent_num(uint32 num) {
	uint8 n[10];
	itoa(num, n, 10);
	lcd_string(n);
}

void lcd_proteus_init(void) {
	DDRD=0xff;
	CLEAR_BIT(PORTD,2);
	_delay_ms(20);
	lcd_proteus_cmd(0x01);
	lcd_proteus_cmd(0x33);
	lcd_proteus_cmd(0x32);
	lcd_proteus_cmd(0x28);
	lcd_proteus_cmd(0x0f);
	lcd_proteus_cmd(0x06);
	lcd_proteus_cmd(0x01);
//	lcd_proteus_cmd(0x80);
}

void lcd_proteus_cmd(uint8 cmd) {
	CLEAR_BIT(PORTD,2);
	CLEAR_BIT(PORTD,1);
	if(GET_BIT(cmd, 4)) { SET_BIT(PORTD,4) ;}else{ CLEAR_BIT(PORTD,4);}
	if(GET_BIT(cmd, 5)) { SET_BIT(PORTD,5) ;}else{ CLEAR_BIT(PORTD,5);}
	if(GET_BIT(cmd, 6)) { SET_BIT(PORTD,6) ;}else{ CLEAR_BIT(PORTD,6);}
	if(GET_BIT(cmd, 7)) { SET_BIT(PORTD,7) ;}else{ CLEAR_BIT(PORTD,7);}
	SET_BIT(PORTD,3);
	_delay_us(10);
	CLEAR_BIT(PORTD,3);
	_delay_us(200);
	if(GET_BIT(cmd, 0)) { SET_BIT(PORTD,4); }else{ CLEAR_BIT(PORTD,4);}
	if(GET_BIT(cmd, 1)) { SET_BIT(PORTD,5) ;}else{ CLEAR_BIT(PORTD,5);}
	if(GET_BIT(cmd, 2)) { SET_BIT(PORTD,6) ;}else{ CLEAR_BIT(PORTD,6);}
	if(GET_BIT(cmd, 3)) { SET_BIT(PORTD,7) ;}else{ CLEAR_BIT(PORTD,7);}
	SET_BIT(PORTD,3);
	_delay_us(10);
	CLEAR_BIT(PORTD,3);
	_delay_us(200);
}

void lcd_proteus_data(uint8 data) {
	CLEAR_BIT(PORTD,2);
	SET_BIT(PORTD,1);
	if(GET_BIT(data, 4)) { SET_BIT(PORTD,4) ;}else{ CLEAR_BIT(PORTD,4);}
	if(GET_BIT(data, 5)) { SET_BIT(PORTD,5) ;}else{ CLEAR_BIT(PORTD,5);}
	if(GET_BIT(data, 6)) { SET_BIT(PORTD,6) ;}else{ CLEAR_BIT(PORTD,6);}
	if(GET_BIT(data, 7)) { SET_BIT(PORTD,7) ;}else{ CLEAR_BIT(PORTD,7);}
	SET_BIT(PORTD,3);
	_delay_us(10);
	CLEAR_BIT(PORTD,3);
	_delay_us(200);
	if(GET_BIT(data, 0)) { SET_BIT(PORTD,4); }else{ CLEAR_BIT(PORTD,4);}
	if(GET_BIT(data, 1)) { SET_BIT(PORTD,5) ;}else{ CLEAR_BIT(PORTD,5);}
	if(GET_BIT(data, 2)) { SET_BIT(PORTD,6) ;}else{ CLEAR_BIT(PORTD,6);}
	if(GET_BIT(data, 3)) { SET_BIT(PORTD,7) ;}else{ CLEAR_BIT(PORTD,7);}
	SET_BIT(PORTD,3);
	_delay_us(10);
	CLEAR_BIT(PORTD,3);
	_delay_us(200);
}

void lcd_proteus_string(uint8 *str) {
	for (uint8 i = 0; str[i]; i++) {
		if (i == 16) {
			lcd_proteus_cmd(0xc0);
		}
		lcd_proteus_data(str[i]);
	}
}

void lcd_proteus_sent_num(uint32 num) {
	uint8 n[10];
	itoa(num, n, 10);
	lcd_proteus_string(n);
}
