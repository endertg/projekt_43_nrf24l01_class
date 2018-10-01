
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define debug 			1

//magistrala I2C sprzętowa
//LCD na I2C
//1-GND
//2-VCC
//3-SDA-A4
//4-SCL-A5
//mozliwosc podlaczenia wiecej urzadzen - kazde ma adres
//#define PCF8574_ADDRBASE (39) //device base address - w pcf8574.h
//#define LCD_PCF8574_DEVICEID 0 //kolejne urzadzenie - w w lcdpcf8574.h

//magistrala SPI
//NRF24L01
//spi ports
#define SPI_DDR DDRB
#define SPI_PORT PORTB
#define SPI_MISO PB4
#define SPI_MOSI PB3
#define SPI_SCK PB5
#define SPI_SS PB2
//CE and CSN port definitions
#define NRF24L01_DDR DDRB
#define NRF24L01_PORT PORTB
#define NRF24L01_CE PB0
#define NRF24L01_CSN PB2

