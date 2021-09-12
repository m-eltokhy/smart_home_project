/*
 * uart.h
 *
 *  Created on: Aug 20, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "uart_config.h"

void uart_init(void);
void uart_transmit(uint8);
void uart_transmit_data(uint8*);
uint8 uart_receive(void);
void call_back_tx(void (*callback)(void));
void call_back_rx(void (*callback)(void));

#endif /* MCAL_UART_UART_H_ */
