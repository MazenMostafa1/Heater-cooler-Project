/*
 * ADC.h
 *
 * Created: 12/14/2021 11:00:54 AM
 *  Author: pc
 */ 


#ifndef ADC_H_
#define ADC_H_


#include <avr/io.h>
#include "STD_MACROS.h"

void ADC_init(void);
uint16_t ADC_read(void);



#endif /* ADC_H_ */