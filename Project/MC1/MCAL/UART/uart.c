/*
 * uart.c
 *
 *  Created on: Aug 20, 2021
 *      Author: M.Eltokhy
 */

#include "uart.h"

void (*ptftx)(void);
void (*ptfrx)(void);

void uart_init(void) {
#if uart_type == Asynchronous
	UCSRC |= ((1 << URSEL) & ~(1 << UMSEL));
#elif uart_type == Synchronous
	UCSRC|= ((1<<URSEL) | (1<<UMSEL));
#endif

#if Parity_Mode == Disabled
	UCSRC |= ((1 << URSEL) & ~(1 << UPM1) & ~(1 << UPM0));
#elif Parity_Mode == Reserved
	UCSRC |= ((1 << URSEL) & ~(1 << UPM1) | (1 << UPM0));
#elif Parity_Mode == Even_Parity
	UCSRC |= ((1 << URSEL) | (1 << UPM1) & ~(1 << UPM0));
#elif Parity_Mode == Odd_Parity
	UCSRC |= ((1 << URSEL) | (1 << UPM1) | (1 << UPM0));
#endif

#if Stop_Bit == one_bit
	UCSRC |= ((1 << URSEL) & ~(1 << USBS));
#elif Stop_Bit == two_bit
	UCSRC |= ((1 << URSEL) | (1 << USBS));
#endif

#if uart_speed == normal_speed && Baud_Rate == 9600
	CLEAR_BIT(UCSRA, U2X);
	UBRRL = 103;
#elif uart_speed == normal_speed && Baud_Rate == 115200
	CLEAR_BIT(UCSRA, U2X);
	UBRRL=8;
#elif uart_speed == double_speed && Baud_Rate == 9600
	SET_BIT(UCSRA,U2X);
	UBRRL=207;
#elif uart_speed == double_speed && Baud_Rate == 115200
	SET_BIT(UCSRA,U2X);
	UBRRL=16;
#endif

#if Stop_Bit == one_bit
	UCSRC |= ((1 << URSEL) & ~(1 << USBS));
#elif Stop_Bit == two_bit
	UCSRC |= ((1 << URSEL) | (1 << USBS));
#endif

#if Transmitter
	SET_BIT(UCSRB, TXEN);
#else
	CLEAR_BIT(UCSRB,TXEN);
#endif

#if Receiver
	SET_BIT(UCSRB, RXEN);
#else
	CLEAR_BIT(UCSRB,RXEN);
#endif

#if TX_interrupt
	SET_BIT(UCSRB, TXCIE);
#else
	CLEAR_BIT(UCSRB,TXCIE);
#endif

#if RX_interrupt
	SET_BIT(UCSRB, RXCIE);
#else
	CLEAR_BIT(UCSRB,RXCIE);
#endif

#if Character_Size == five_bit
	CLEAR_BIT(UCSRB,UCSZ2);
	UCSRC |= ((1 << URSEL) & ~(1 << UCSZ1) & ~(1 << UCSZ0));
#elif Character_Size == six_bit
	CLEAR_BIT(UCSRB,UCSZ2);
	UCSRC |= ((1 << URSEL) & ~(1 << UCSZ1) | (1 << UCSZ0));
#elif Character_Size == seven_bit
	CLEAR_BIT(UCSRB,UCSZ2);
	UCSRC |= ((1 << URSEL) & ~(1 << UCSZ1) & ~(1 << UCSZ0));
#elif Character_Size == eight_bit
	CLEAR_BIT(UCSRB, UCSZ2);
	UCSRC |= ((1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0));
#elif Character_Size == nine_bit
	SET_BIT(UCSRB,UCSZ2);
	UCSRC |= ((1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0));
#endif
}

void uart_transmit(uint8 data)
{
	while ( !( UCSRA & (1<<UDRE)) );
	UDR=data;
}

void uart_transmit_data(uint8 *data)
{
	uint8 i=0;
	while(data[i]!='\n'){
		while ( !( UCSRA & (1<<UDRE)) );
		UDR=data[i];
		i++;
	}

}

uint8 uart_receive(void)
{
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}

void call_back_tx(void (*callback)(void)) {
	ptftx = callback;
}

void call_back_rx(void (*callback)(void)) {
	ptfrx = callback;
}

ISR(USART_TXC_vect) {
	ptftx();
}

ISR(USART_RXC_vect) {
	ptfrx();
}
