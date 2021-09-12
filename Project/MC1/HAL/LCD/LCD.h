/*
 * LCD.h
 *
 *  Created on: Jul 31, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../MCAL/DIO/DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

void lcd_init(void);
void lcd_cmd(uint8);
void lcd_data(uint8);
void lcd_string(uint8*);
void lcd_sent_num(uint32);
void lcd_proteus_init(void);
void lcd_proteus_cmd(uint8);
void lcd_proteus_data(uint8);
void lcd_proteus_string(uint8*);
void lcd_proteus_sent_num(uint32);

#endif /* HAL_LCD_LCD_H_ */
