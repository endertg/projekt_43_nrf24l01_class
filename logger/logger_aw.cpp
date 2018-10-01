/*
 * logger.cpp
 *
 *  Created on: 30-04-2018
 *      Author: adam
 */

#include "../logger_aw.h"
#include <stdlib.h>

#define UART_BAUD_RATE      9600

logger_aw::logger_aw(){
logger_aw::uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );//- odchaczyc jak biblioteki uart beda podpiete
//init interrupt
sei();// zezwol na przerwania UART
logger_aw::uart_puts("LOGGER_AW RUNNING...\r\n");
}

logger_aw::~logger_aw(){

}

void logger_aw::log(const char* x){
	logger_aw::uart_puts(x);
}

void logger_aw::log_u8(uint8_t x){
	char str[16];
	itoa(x, str, 10);

	logger_aw::uart_puts(str);
}
