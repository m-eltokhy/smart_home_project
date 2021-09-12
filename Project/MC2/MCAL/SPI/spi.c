/*
 * spi.c
 *
 *  Created on: Aug 21, 2021
 *      Author: M.Eltokhy
 */

#include "spi.h"

void (*ptfspi)(void);

void spi_master_init(void) {
	SET_BIT(DDRB, 5);
	SET_BIT(DDRB, 7);
	SET_BIT(DDRB, 4);
	CLEAR_BIT(DDRB, 6);
	CLEAR_BIT(PORTB, 4);
	SET_BIT(SPCR, MSTR);
	SPCR |= SPI_Clock_Rate;

#if spi_interrupt == enable
	SET_BIT(SPCR,SPIE);
#else
	CLEAR_BIT(SPCR, SPIE);
#endif

#if spi_enable == enable
	SET_BIT(SPCR, SPE);
#elif spi_enable == disable
	SET_BIT(SPCR,SPE);
#endif

#if Data_Order == MSB
	SET_BIT(SPCR, DORD);
#elif Data_Order == LSB
	SET_BIT(SPCR,DORD);
#endif

#if Clock_Phase == leading
	CLEAR_BIT(SPCR, CPHA);
#elif Clock_Phase == trailing
	SET_BIT(SPCR,CPHA);
#endif

#if SPI_Speed == normal_speed
	CLEAR_BIT(SPSR, SPI2X);
#elif SPI_Speed == double_speed
	SET_BIT(SPSR,SPI2X);
#endif

}

void spi_slave_init(void) {
	CLEAR_BIT(DDRB, 5);
	CLEAR_BIT(DDRB, 7);
	CLEAR_BIT(DDRB, 4);
	SET_BIT(DDRB, 6);
	CLEAR_BIT(SPCR, MSTR);
	SPCR |= SPI_Clock_Rate;

#if spi_interrupt == enable
	SET_BIT(SPCR,SPIE);
#else
	CLEAR_BIT(SPCR, SPIE);
#endif

#if spi_enable == enable
	SET_BIT(SPCR, SPE);
#elif spi_enable == disable
	SET_BIT(SPCR,SPE);
#endif

#if Data_Order == MSB
	SET_BIT(SPCR, DORD);
#elif Data_Order == LSB
	SET_BIT(SPCR,DORD);
#endif

#if Clock_Phase == leading
	CLEAR_BIT(SPCR, CPHA);
#elif Clock_Phase == trailing
	SET_BIT(SPCR,CPHA);
#endif

#if SPI_Speed == normal_speed
	CLEAR_BIT(SPSR, SPI2X);
#elif SPI_Speed == double_speed
	SET_BIT(SPSR,SPI2X);
#endif

}

void spi_master_send(uint8 data) {
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
}

uint8 spi_slave_receive(void) {
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void call_back_spi(void (*callback)(void)) {
	ptfspi = callback;
}

ISR(SPI_STC_vect) {
	ptfspi();
}
