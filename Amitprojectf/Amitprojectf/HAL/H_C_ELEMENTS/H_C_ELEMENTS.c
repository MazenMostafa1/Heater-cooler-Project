/*
 * H_C_ELEMENTS.c
 *
 * Created: 12/14/2021 10:56:31 AM
 *  Author: pc
 */ 
#include "STD_MACROS.h"
#include "H_C_ELEMENTS.h"

void heat_init(void)
{
	set_bit(HEAT_PORT_DIR,HEAT_PIN);
}

void cool_init(void)
{
	set_bit(COOL_PORT_DIR,COOL_PIN);
}



 
//to start the Heater 


void heat_on(void)
{
	set_bit(HEAT_PORT,HEAT_PIN);
}

//to start the Cooler.

void cool_on(void)
{
	set_bit(COOL_PORT,COOL_PIN);
}



// to stop Heater 


void heat_off(void)
{
	clr_bit(HEAT_PORT,HEAT_PIN);
}


// to stop cooler


void cool_off(void)
{
	clr_bit(COOL_PORT,COOL_PIN);
}