/*
 * BUTTONS.h
 *
 * Created: 12/14/2021 10:55:53 AM
 *  Author: pc
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_


#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "STD_MACROS.h"

#define PRESSED 1
#define NOT_PRESSED 0

#define DEBOUNCE_INTERVAL 100
#define B_PORT PORTB
#define B_PORT_DIR DDRB

#define ON_OFF_PIN 2
#define UP_PIN 1
#define DOWN_PIN 3

// Buttons Functions
void Buttons_init(void);
void ON_OFF_EXTI(void);

unsigned char UP_pressed(void);
unsigned char DOWN_pressed(void);



#endif /* BUTTONS_H_ */