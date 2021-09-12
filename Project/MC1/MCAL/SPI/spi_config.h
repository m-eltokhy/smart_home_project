/*
 * spi_config.h
 *
 *  Created on: Aug 21, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#define disable	0
#define enable 	1

#define spi_enable		enable
#define spi_interrupt	disable

#define MSB		0
#define LSB		1

#define Data_Order	MSB

#define leading		0
#define trailing	1

#define Clock_Phase leading

#define normal_speed	0
#define double_speed	1

#define SPI_Speed	normal_speed

#define f_4		0
#define f_16	1
#define f_64	2
#define f_128	3

#define SPI_Clock_Rate f_16


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
