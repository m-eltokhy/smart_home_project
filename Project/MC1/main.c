/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: M.Eltokhy
 */


#include "MCAL/DIO/DIO.h"
#include "MCAL/SPI/spi.h"

int main()
{
	DIO_Init();
	spi_slave_init();
	while(1){
		_delay_ms(10);
		uint8 data=spi_slave_receive();
		if(data=='1'){
			TOGGLE_BIT(PORTA,0);
		}else if(data=='2'){
			TOGGLE_BIT(PORTA,1);
		}else if(data=='3'){
			DIO_Write(PORT_A0, High);
			DIO_Write(PORT_A1, High);
		}else if(data=='4'){
			DIO_Write(PORT_A0, Low);
			DIO_Write(PORT_A1, Low);
		}
	}
	return 0;
}
