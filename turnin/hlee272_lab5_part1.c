/*	Author: Heeje Lee
 *
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1:
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *code, is my own original work.
 * Lab 5 part 1 demo video : https://youtu.be/OH29MZfuaT8
 */
#include <avr/io.h> 
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs

	unsigned char light = 0x00;
	unsigned char tmpA = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = ~PINA & 0xFF;

	if (tmpA == 0x00) {
		light = 0x40;
	}

	else if (tmpA < 3) {
		light = 0x20;
	}

	else if (tmpA < 5 ) {
		light = 0x30;
	}

	else if (tmpA < 7) {
		light = 0x38;
	}

	else if (tmpA < 10) {
		light = 0x3C;
	}

	else if (tmpA < 13) {
		light = 0x3E;
	}

	else {
		light = 0x3F;
	}
	
	//low fuel
	if (tmpA < 5) {
		light = light + 0x40;
	}

	PORTC = light;
    }
 
}
