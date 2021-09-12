/*
 * uart_config.h
 *
 *  Created on: Aug 20, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

#define F_cpu 16000000UL
#define USART_BAUDRATE 9600
#define baud (((F_cpu / (USART_BAUDRATE * 16UL))) - 1)

#define normal_speed 	0
#define double_speed	1

#define uart_speed	normal_speed

#define Asynchronous 	0
#define Synchronous		1

#define uart_type 	Asynchronous

#define Disabled 		0
#define Reserved	 	1
#define Even_Parity 	2
#define Odd_Parity 		3

#define Parity_Mode		Disabled

#define one_bit 	0
#define two_bit 	1

#define Stop_Bit	one_bit

#define five_bit	0
#define six_bit		1
#define seven_bit	2
#define eight_bit	3
#define nine_bit	4

#define Character_Size	eight_bit

#define disabled 	0
#define enabled 	1

#define Receiver		enabled
#define Transmitter		enabled
#define TX_interrupt 	disabled
#define RX_interrupt 	disabled

#endif /* MCAL_UART_UART_CONFIG_H_ */
