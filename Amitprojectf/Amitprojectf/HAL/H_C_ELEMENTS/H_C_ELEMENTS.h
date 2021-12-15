/*
 * H_C_ELEMENTS.h
 *
 * Created: 12/14/2021 10:56:18 AM
 *  Author: pc
 */ 


#ifndef H_C_ELEMENTS_H_
#define H_C_ELEMENTS_H_


#include <avr/io.h>

#define HEAT_PORT_DIR DDRB
#define HEAT_PORT PORTB
#define HEAT_PIN 4

#define COOL_PORT_DIR DDRB
#define COOL_PORT PORTB
#define COOL_PIN 5

void heat_init(void);
void heat_on(void);
void heat_off(void);

void cool_init(void);
void cool_on(void);
void cool_off(void);


#endif /* H_C_ELEMENTS_H_ */