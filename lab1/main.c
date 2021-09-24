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
#define PINB *((u8*)0x39)

#define DDRD	*((u8*)0x31)
#define PORTD	*((u8*)0x32)
#define PIND	*((u8*)0x30)

u8 seg []= {	0x3f,0x06,0x5B,0x4F,0x66,
				0x6D,0x7D,0x07,0x7F,0x6F,0x77,
				0x7C,0x39,0x5E,0x79,0x71
		   };
int main()
{
	DDRC |=(1<<2);//led1
	DDRC |=(1<<7);//led2

	DDRD &=~(1<<6);//sw1
	DDRD &=~(1<<0);//sw2

	//PORTA |=(1<<6);//pull up sw1
	//PORTA |=(1<<7);//pull up sw2

	while(1) //for(;;)
	{
		if ( ((PIND>>6)&1) == 1)
		{
			PORTC |=(1<<2); //led1 on
			PORTC &=~(1<<7);//led2 off
		}
		else if ( ((PIND>>0)&1) == 1)
		{
			PORTC &=~(1<<2); //led1 off
			PORTC &=~(1<<7);//led2 off
		}

		if ( ((PIND>>6)&1) == 0 && ((PIND>>0)&1) == 0)
		{
			PORTC |=(1<<7); //led2 on
			PORTC &=~(1<<2);//led1 off
		}
	}
}
