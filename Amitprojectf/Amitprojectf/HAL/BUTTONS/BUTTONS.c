/*
 * BUTTONS.c
 *
 * Created: 12/14/2021 10:55:42 AM
 *  Author: pc
 */ 
#include "BUTTONS.h"



void Buttons_init(void)
{
	// to Set the pins as INPUT pins
	clr_bit(B_PORT_DIR,ON_OFF_PIN);
	clr_bit(B_PORT_DIR,UP_PIN);
	clr_bit(B_PORT_DIR,DOWN_PIN);
	
	// to enable internal Pull-Up Resistor
	
	set_bit(B_PORT,ON_OFF_PIN);
	set_bit(B_PORT,UP_PIN);
	set_bit(B_PORT,DOWN_PIN);
	
	
	// to enable Global Interrupt bit
	sei();
	
	// to trigger with Rising Edge
	set_bit(MCUCSR,ISC2);
	
	// Enable External Interrupt (INT2)
	set_bit(GICR,INT2);
}



// To Check if UP button is pressed or not and return the result.


unsigned char UP_pressed(void)
{
	// To Check if the button is pressed for the first time
	if(!(read_bit(PINB,UP_PIN))){
		// wait for 100 ms to make sure it's pressed to solve debouncing
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check again
		if (!(read_bit(PINB,UP_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}

/*----------------------------------------------------------------------------*-
DOWN_pressed() : Checks if DOWN button is pressed or not and return the result.
-*----------------------------------------------------------------------------*/

unsigned char DOWN_pressed(void)
{
	// Check if the button is pressed for the first time 
	if(!(read_bit(PINB,DOWN_PIN))){
		// wait for 100 ms to make sure it's pressed to solve debouncing 
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check again
		if (!(read_bit(PINB,DOWN_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
