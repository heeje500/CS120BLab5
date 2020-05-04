/*	Author: Heeje Lee
 *
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	Demo video: https://youtu.be/QMfp4ShLY2o 
 */
#include <avr/io.h> 
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, init, inc, wait} state;
void Tick();

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0xFF; PORTB = 0x00; //outputs

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

	else {
		state = init;
	}
	break;

	case wait:
	if ((~PINA & 0x01) == 0x01) {
		state = wait;
	}

	else {
		state = init;
	}
	break;

	case inc:
	state = wait;
	break;

	default: 
	state = Start;
	break;

}
	switch(state) 
	{
	
	case Start: 
	PORTB = 0x00;
	break;

	case init: 
	break;

	case wait:
	break;

	case inc:
	if (PORTB == 0x00) {
		PORTB = 0x01;
	}

	else if (PORTB == 0x3F){ 
		PORTB = 0x00;
	}

	else {
	PORTB = (PORTB << 1);
	
	}
	break;

	default:
	break;
	}

}
