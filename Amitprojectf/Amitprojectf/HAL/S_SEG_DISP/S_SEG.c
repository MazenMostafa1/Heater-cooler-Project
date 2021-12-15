/*
 * S_SEG.c
 *
 * Created: 12/14/2021 11:00:06 AM
 *  Author: pc
 */ 
#include "S_SEG.h"


// to initialize the Seven Segment display


// Array for Numbers' Values
uint8_t Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SSD_init(void)
{
	
	// setting Seven Segment Pins as output pins
	SSD_PORT_DIR = 0xFF;
	set_bit(SSD_ENABLE_PORT_DIR,SSD1_ENABLE_PIN);
	set_bit(SSD_ENABLE_PORT_DIR,SSD2_ENABLE_PIN);
	
	// because we want the Seven Segment to be initially OFF until the on/off button is pressed
	SSD_disable();
	
}


// to Upload data to the Seven Segment.


void SSD_ARR(uint16_t N)
{
	SSD_DATA = Nums[N];
}


// the 2 seven seg. are multiplexed and works with the same pins. This function is to enable one of them.

void SSD_enable(uint8_t disp)
{
	if(disp == 1){
		set_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		clr_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
	else if (disp == 2){
		set_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
		clr_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	}
}


//To disable the two seven segments for some special cases.


void SSD_disable(void)
{
	clr_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	clr_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}


// To turn off the Seven Segment 


void SSD_off(void)
{
	SSD_DATA = 0x00;
}


// To write on each of the two SSDs


void SSD_type(uint16_t N)
{
	uint8_t units;
	uint8_t tens;
	
	units = N % 10;
	tens = (int) N / 10;
	
	SSD_enable(DISP1);
	SSD_ARR(units);
	_delay_ms(5);
	
	SSD_enable(DISP2);
	SSD_ARR(tens);
	_delay_ms(5);
}