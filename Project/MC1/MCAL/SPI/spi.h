/*
 * spi.h
 *
 *  Created on: Aug 21, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "spi_config.h"

void spi_master_init(void);
void spi_slave_init(void);
void spi_master_send(uint8);
uint8 spi_slave_receive(void);
void call_back_spi(void (*callback)(void));

#endif /* MCAL_SPI_SPI_H_ */
