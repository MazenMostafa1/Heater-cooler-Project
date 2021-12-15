/*
 * LED.c
 *
 * Created: 12/14/2021 10:57:20 AM
 *  Author: pc
 */ 
#include "LED.h"


// init. heating element led by making it an output pin.


void led_init(void)
{
	
	// PIN 0 in the port is an output pin
	// the LED pin is initially off
	
	set_bit(LED_PORT_DIR,LED_PIN);
	clr_bit(LED_PORT,LED_PIN);

}


// to turn on the LED.


void led_on(void)
{
	set_bit(LED_PORT,LED_PIN);
}

// to turn off the LED.

void led_off(void)
{
	clr_bit(LED_PORT,LED_PIN);
}
