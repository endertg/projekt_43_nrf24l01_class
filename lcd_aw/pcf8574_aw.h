/*
 * pcf8574_aw.h
 *
 *  Created on: 30-03-2018
 *      Author: adam
 */

#ifndef PCF8574_AW_H_
#define PCF8574_AW_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "i2c_aw.h"

class pcf8574_aw : public i2c_aw{
private:
public:
int PCF8574_ADDRBASE;

//#define PCF8574_ADDRBASE (39) //device base address

#define PCF8574_I2CINIT 1 //init i2c

#define PCF8574_MAXDEVICES 8 //max devices, depends on address (3 bit)
#define PCF8574_MAXPINS 8 //max pin per device

//settings
#define PCF8574_I2CFLEURYPATH "../i2chw/i2cmaster.h" //define the path to i2c fleury lib

//pin status
volatile uint8_t pcf8574_pinstatus[PCF8574_MAXDEVICES];

//prototypes
pcf8574_aw();
~pcf8574_aw();

//methods prototypes
void pcf8574_init();
int8_t pcf8574_getoutput(uint8_t deviceid);
int8_t pcf8574_getoutputpin(uint8_t deviceid, uint8_t pin);
int8_t pcf8574_setoutput(uint8_t deviceid, uint8_t data);
int8_t pcf8574_setoutputpins(uint8_t deviceid, uint8_t pinstart, uint8_t pinlength, int8_t data);
int8_t pcf8574_setoutputpin(uint8_t deviceid, uint8_t pin, uint8_t data);
int8_t pcf8574_setoutputpinhigh(uint8_t deviceid, uint8_t pin);
int8_t pcf8574_setoutputpinlow(uint8_t deviceid, uint8_t pin);
int8_t pcf8574_getinput(uint8_t deviceid);
int8_t pcf8574_getinputpin(uint8_t deviceid, uint8_t pin);
void pcf8574_setaddress(uint8_t address);
};//class pcf8574_aw ends


#endif /* PCF8574_AW_H_ */
