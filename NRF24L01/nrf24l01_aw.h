/*
nrf24l01 lib 0x02

copyright (c) Davide Gironi, 2012

References:
  -  This library is based upon nRF24L01 avr lib by Stefan Engelke
     http://www.tinkerer.eu/AVRLib/nRF24L01
  -  and arduino library 2011 by J. Coliz
     http://maniacbug.github.com/RF24

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/

#ifndef _NRF24L01_AW_H_
#define _NRF24L01_AW_H_

#include <avr/io.h>
#include "../config.h"
#include "nrf24l01registers.h"
#include "../spi/spi_aw.h"

class nrf24l01_aw : public spi_aw{


//dodalem
private:
uint8_t nrf24l01_readregister(uint8_t reg);
void nrf24l01_readregisters(uint8_t reg, uint8_t *value, uint8_t len);
void nrf24l01_writeregister(uint8_t reg, uint8_t value);
void nrf24l01_writeregisters(uint8_t reg, uint8_t *value, uint8_t len);
void nrf24l01_revaddress(uint8_t *addr, uint8_t *addrrev);
void nrf24l01_flushRXfifo();
void nrf24l01_flushTXfifo();
void nrf24l01_setRX();
void nrf24l01_setTX();
void nrf24l01_setpalevel();
void nrf24l01_setdatarate();
void nrf24l01_setcrclength();


//byly
public:
void nrf24l01_setrxaddr(uint8_t channel, uint8_t *addr);
void nrf24l01_settxaddr(uint8_t *addr);
#if NRF24L01_PRINTENABLE == 1
void nrf24l01_printinfo(void(*prints)(const char *), void(*printc)(unsigned char data));
#endif
uint8_t nrf24l01_getstatus();
uint8_t nrf24l01_readready(uint8_t* pipe);
void nrf24l01_read(uint8_t *data);
uint8_t nrf24l01_write(uint8_t *data);
void nrf24l01_init();









};

#endif
