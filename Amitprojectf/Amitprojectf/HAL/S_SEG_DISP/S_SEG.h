/*
 * S_SEG.h
 *
 * Created: 12/14/2021 11:00:17 AM
 *  Author: pc
 */ 


#ifndef S_SEG_H_
#define S_SEG_H_


#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_MACROS.h"



#define DISP1 1
#define DISP2 2

#define SSD_ENABLE_PORT_DIR DDRB
#define SSD_ENABLE_PORT PORTB
#define SSD1_ENABLE_PIN 6
#define SSD2_ENABLE_PIN 7
#define SSD_DATA PORTD
#define SSD_PORT_DIR DDRD


void SSD_init(void);
void SSD_ARR(uint16_t N);
void SSD_enable(uint8_t disp);
void SSD_disable(void);
void SSD_off(void);
void SSD_type(uint16_t N);


#endif /* S_SEG_H_ */