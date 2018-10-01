/*
spi lib 0x01

copyright (c) Davide Gironi, 2012

References:
  -  This library is based upon SPI avr lib by Stefan Engelke
     http://www.tinkerer.eu/AVRLib/SPI

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/


#ifndef _SPI_AW_H_
#define _SPI_AW_H_
#include <avr/io.h>
#include "../config.h"

class spi_aw {


public:

void spi_init();
uint8_t spi_writereadbyte(uint8_t data);

};

#endif
