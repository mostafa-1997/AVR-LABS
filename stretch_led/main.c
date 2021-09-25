/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include <util/delay.h>

#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((u8*)0x39)

int main()
{
	//DDRA direction output
	DDRA |= (1<<0);//led1
	DDRA |= (1<<1);//led2
	DDRA |= (1<<2);//led3
	DDRA |= (1<<3);//led4
	DDRA |= (1<<4);//led5
	DDRA |= (1<<5);//led6
	DDRA |= (1<<6);//led7
	DDRA |= (1<<7);//led8


	PORTA |= (1<<3);//led4 ON
	PORTA |= (1<<4);//led5 ON
	_delay_ms(250);

	while(1)//super loop system
	{
		PORTA |= (1<<2);//led3 ON
		PORTA |= (1<<5);//led6 ON
		_delay_ms(250);

		PORTA |= (1<<1);//led2 ON
		PORTA |= (1<<6);//led7 ON
		_delay_ms(250);

		PORTA |= (1<<0);//led1 ON
		PORTA |= (1<<7);//led8 ON
		_delay_ms(250);


		PORTA &= ~(1<<0);//led1 OFF
		PORTA &= ~(1<<7);//led8 OFF
		_delay_ms(250);

		PORTA &= ~(1<<1);//led2 OFF
		PORTA &= ~(1<<6);//led7 OFF
		_delay_ms(250);

		PORTA &= ~(1<<2);//led3 OFF
		PORTA &= ~(1<<5);//led6 OFF
		_delay_ms(250);
	}

}
