/*
 * main.c
 *
 *  Created on: Sep 18, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include <util/delay.h>

#define DDRC *((u8*)0x34)
#define PORTC *((u8*)0x35)

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)

int main(){

	//PortC.7 DDR direction
	DDRC |= (1<<7);

	DDRA |= (0x0f<<4);//instead of making DDRA 4 times
	//0b00001111<<4 = 0b11110000 | 0b00001010 =0b11111010

	DDRB |= (1<<1);

	//will print 5 in the hexadecoder the 4 selection pins
	PORTA &=~(1<<7);
	PORTA |= (1<<6);
	PORTA &=~ (1<<5);
	PORTA |= (1<<4);
	//0b0101 = 5

	//7segment enable
	PORTB |=(1<<2);


	 while(1)
	 {
		 //PortC.7 output
		 PORTC |= (1<<7);
		 _delay_ms(1000);
		 PORTC &= ~(1<<7);
		 _delay_ms(1000);
	 }
}
