/*
 * LED.h
 *
 * Created: 12/14/2021 10:57:31 AM
 *  Author: pc
 */ 


#ifndef LED_H_
#define LED_H_


#include <avr/io.h>
#include "STD_MACROS.h"

#define LED_PORT_DIR DDRB
#define LED_PORT PORTB
#define LED_PIN 0

void led_init(void);
void led_on(void);
void led_off(void);


#endif /* LED_H_ */