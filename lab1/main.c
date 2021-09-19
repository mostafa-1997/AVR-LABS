/*
 * main.c
 *
 *  Created on: Sep 18, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"

int main(){

	//PortC.7 DDR direction
	*((u8*)0x34) |= (1<<7);

	//PortC.7 output
	*((u8*)0x35) |= (1<<7);
}
