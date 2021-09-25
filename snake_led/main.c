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

	u8 bit = 0;
	while(1)//super loop system
	{
		for(int i =0;i<8;i++)
		{
			PORTA |= (1<<i);//led ON
			_delay_ms(250);
		}

		for(int i =0;i<8;i++)
		{
			PORTA &= ~(1<<i);//led OFF
			_delay_ms(250);
		}
	}

}
