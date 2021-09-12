/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: M.Eltokhy
 */

#include "MCAL/SPI/spi.h"
#include "MCAL/UART/uart.h"

int main()
{
	spi_master_init();
	uart_init();
	uint8 data=0;
	uart_transmit_data("Mohamed Eltokhy Project\r\n");
	while(1){
		_delay_ms(10);
		data=uart_receive();
		spi_master_send(data);
		_delay_ms(10);
	}
	return 0;
}
