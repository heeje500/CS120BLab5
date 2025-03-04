/*	Author: Heeje Lee
 *
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	Demo video: https://youtu.be/mCIWNHDvIYQ
 */
#include <avr/io.h> 
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, init, wait, inc, dec, zero} state;
void Tick();

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs

	state = Start;
    /* Insert your solution below */
    while (1) {
	Tick();
    }
 
}

void Tick() {

	switch(state) {
	
	case Start:
	state = init;
	break;

	case init: 
	if ((~PINA & 0x01) == 0x01) {
		state = inc;
	}

	else if ((~PINA & 0x02) == 0x02) {
		state = dec;
	}

	else if ((~PINA & 0x03) == 0x03) {
		state = zero;
	} 

	else {
		state = init;
	}

	break;

	case wait:

	if (((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
		state = wait;
	}

	else if ((~PINA & 0x03) == 0x03) {
		state = zero;
	}

	else {
		state = init;
	}
	break;

	case inc: 
	state = wait;
	break;

	case dec:
	state = wait;
	break;

	case zero: 
	if (((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
		state = zero;
	}

	else {
		state = init;
	}

	break;

	default: 
	state = Start;
	break;

}
	switch(state) 
	{
	
	case Start: 
	PORTC = 0x00;
	break;

	case init: 
	break;

	case wait:
	break;

	case inc:
	if (PORTC < 0x09) {
	PORTC = PORTC + 0x01;
	}

	else {
	PORTC = PORTC;
	}
	break;

	case dec: 
	if (PORTC > 0x00) {
	PORTC = PORTC - 0x01;
	}

	else {
	PORTC = PORTC;
	}
	break;

	case zero:
	PORTC = 0x00;
	break;

	default:
	break;
	}

}
