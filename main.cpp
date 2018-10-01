/*
 * main.cpp
 *
 *  Created on: 30-03-2018
 *      Author: adam
 */

#include <inttypes.h>
//#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include "NRF24L01/nrf24l01_aw.h"
#include "NRF24L01/nrf24l01registers.h"
#include <util/delay.h>
#include "lcd_aw.h"
#include "logger_aw.h"



int main(void){
uint8_t led = 0;
uint8_t pipe = 0;
uint8_t odb=1;
uint8_t bufferout[6];
uint8_t bufferin[6];
char znak[3];
uint8_t addrtx0[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP0;


//lcd_aw lcd1;
lcd_aw lcd1;
//logger_aw log1;
nrf24l01_aw radio1;
//sei();
//transc1.log("po sei \r\n");

   //init lcd
   lcd1.lcd_init(LCD_DISP_ON);

   //lcd go home
   lcd1.lcd_home();

//init lcd - inicjalizacja LCD

   lcd1.lcd_led(led); //set led
   lcd1.lcd_clrscr();
   lcd1.lcd_gotoxy(0, 0);
   lcd1.lcd_puts("NRF24L01 - odb");
   lcd1.lcd_gotoxy(0, 1);
   lcd1.lcd_puts("na objektowo");

   _delay_ms(2000);
   //lcd1.lcd_clrscr();
   //transc1.log("przed nrf init\r\n");

   radio1.nrf24l01_init();
   radio1.nrf24l01_settxaddr(addrtx0);
   _delay_ms(100);
   //transc1.log("po nrf init\r\n");

   bufferout[0]=0;//0
   bufferout[1]=0;//1
   bufferout[2]=0;//bajt 1
   bufferout[3]=4;//bajt 2
   bufferout[4]=2;//bit0-NEW=1 bit1-ACK=1 bit2-OK
   bufferout[5]=4;//crc

if (odb==0)
	{
		lcd1.lcd_gotoxy(0, 0);
		lcd1.lcd_puts("wysylam:");
		while(1)
			{
				bufferout[2]++;
				if (bufferout[2]>9) {
					bufferout[2]=0;
					bufferout[1]++;
				}
				if (bufferout[1]>9) {
					bufferout[1]=0;
					bufferout[0]++;
				}
				if (bufferout[0]>9) {
					bufferout[0]=0;
					bufferout[1]=0;
					bufferout[2]=0;

				}
				lcd1.lcd_gotoxy(0, 1);
				itoa(bufferout[0],znak,10);
				lcd1.lcd_puts(znak);
				itoa(bufferout[1],znak,10);
				lcd1.lcd_puts(znak);
				itoa(bufferout[2],znak,10);
				lcd1.lcd_puts(znak);
				itoa(bufferout[3],znak,10);
				lcd1.lcd_puts(znak);
				itoa(bufferout[4],znak,10);
				lcd1.lcd_puts(znak);
				//itoa(bufferout[5],znak,10);
				//lcd1.lcd_puts(znak);
				//lcd1.lcd_puts("          ");

				//radio1.nrf24l01_write(bufferout);
				//_delay_ms(1000);
			}
	}else
	{
		while(1)
			{
				//log1.log("czekam na odb - ");
				lcd1.lcd_gotoxy(0, 0);
				lcd1.lcd_puts("czekam:");
				while(!radio1.nrf24l01_readready(&pipe))
				{
					lcd1.lcd_puts(".");
					//wait for bufforin
					_delay_ms(250);
				}
		radio1.nrf24l01_read(bufferin);
		lcd1.lcd_gotoxy(0, 0);
		lcd1.lcd_puts("odebrano        ");
		lcd1.lcd_gotoxy(0, 1);
		lcd1.lcd_puts("{");
		itoa(bufferin[0],znak,10);
		lcd1.lcd_puts(znak);
		itoa(bufferin[1],znak,10);
		lcd1.lcd_puts(znak);
		itoa(bufferin[2],znak,10);
		lcd1.lcd_puts(znak);
		itoa(bufferin[3],znak,10);
		lcd1.lcd_puts(znak);
		itoa(bufferin[4],znak,10);
		lcd1.lcd_puts(znak);
		itoa(bufferin[5],znak,10);
		lcd1.lcd_puts(znak);
		lcd1.lcd_puts("}            ");
			}//end while
	}//end elseif
return 0;
}//end main

