/*
 * ADC.c
 *
 * Created: 12/14/2021 11:00:40 AM
 *  Author: pc
 */ 
#include "ADC.h"


// to initialize the ADC 


void ADC_init()
{
	
	// Choosing reference voltage option.
	set_bit(ADMUX,REFS0);
	
	// Choosing Channel One (Single Ended In.) at A0 pin.
	clr_bit(ADMUX,MUX0);
	clr_bit(ADMUX,MUX1);
	clr_bit(ADMUX,MUX2);
	clr_bit(ADMUX,MUX3);
	clr_bit(ADMUX,MUX4);
	
	// to Choose the Data to be Right Adjusted in the Data Reg.
	clr_bit(ADMUX,ADLAR);
	
	// To Choose Prescaler for the ADC
	
	set_bit(ADCSRA,ADPS0);
	clr_bit(ADCSRA,ADPS1);
	clr_bit(ADCSRA,ADPS2);
	
	// Enable the ADC
	set_bit(ADCSRA,ADEN);
	
}

// to read data from the temperature sensor


uint16_t ADC_read()
{
	
	uint16_t data;
	
	// Start Conversion
	set_bit(ADCSRA,ADSC);
	
	while(is_bit_clr(ADCSRA,ADIF));
	
	// Read Data from the ADC Data Register
	// Read the Low register first
	data = ADCL;
	data |= (ADCH<<8);
	
	// Clear Flag 
	set_bit(ADCSRA,ADIF);
	
	return data;
}