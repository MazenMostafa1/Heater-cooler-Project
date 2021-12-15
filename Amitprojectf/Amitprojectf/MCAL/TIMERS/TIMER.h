/*
 * TIMER.h
 *
 * Created: 12/14/2021 11:02:35 AM
 *  Author: pc
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_MACROS.h"

void timer1_init();
void timer0_init();
void timer1_INT_disable();
void timer1_INT_enable();



#endif /* TIMER_H_ */