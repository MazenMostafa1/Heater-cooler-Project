/*
 * TIMER.c
 *
 * Created: 12/14/2021 11:02:20 AM
 *  Author: pc
 */ 
#include "Timer.h"



// to initialize timer(1) to measure time between tasks every 1ms.


void timer1_init()
{

	// Select CTC Mode
	set_bit(TCCR1B,WGM12);
	
	
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	
	// Select Clock Prescaler (1024)
	set_bit(TCCR1B,CS10);
	clr_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
	
	// Enable Global Interrupt bit
	sei();

}


// to initialize timer(0) to trigger INT every 100ms to get Temp.


void timer0_init()
{
	
	// choose mode
	set_bit(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose Prescaler
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	
	// Enable Timer INT
	sei();
	set_bit(TIMSK,OCIE0);
	
}


// to stop timer(1) from triggering INTERRUPTS.


void timer1_INT_disable()
{
	
	// Disable Interrupts when Comparing with values A and B
	clr_bit(TIMSK,OCIE1A);
	
}


// to start timer(1) 


void timer1_INT_enable()
{
	
	// Enable Interrupts when Comparing with values A and B
	set_bit(TIMSK,OCIE1A);
	
}