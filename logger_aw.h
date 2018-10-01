/*
 * logger.h
 *
 *  Created on: 30-04-2018
 *      Author: adam
 */


#ifndef LOGGER_H_
#define LOGGER_H_
#include <inttypes.h>
#include <avr/interrupt.h>
#include "uart/uart.h"


class logger_aw : public uart {
public:
	logger_aw();
	~logger_aw();

	void log(const char* x);
	void log_u8(uint8_t x);
};
#endif /* LOGGER_H_ */
