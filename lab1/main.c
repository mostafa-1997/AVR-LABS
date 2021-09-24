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
int main(){

	//PortC.7 DDR direction
	DDRC |= (1<<7);


	 while(1)
	 {
		 //PortC.7 output
		 PORTC |= (1<<7);
		 _delay_ms(1000);
		 PORTC &= ~(1<<7);
		 _delay_ms(1000);
	 }
}
