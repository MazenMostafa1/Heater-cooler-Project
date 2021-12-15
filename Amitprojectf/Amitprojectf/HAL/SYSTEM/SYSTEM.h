/*
 * SYSTEM.h
 *
 * Created: 12/14/2021 10:57:53 AM
 *  Author: pc
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_



#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SYSTEM_CFG.h"
#include "STD_MACROS.h"
#include "ADC.h"
#include "BUTTONS.h"
#include "H_C_ELEMENTS.h"
#include "LED.h"
#include "S_SEG.h"
#include "TIMER.h"
#include "EEPROM.h"

#define OFF 0
#define ON 1
#define SETTING 2


void system_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_temp(uint16_t * arr , uint16_t new_val);
uint16_t calc_avg(uint16_t * arr);
void temp_arr_init(void);
void sleep(void);



uint8_t Current_state;

uint16_t temp_arr[NUM_OF_MEASURES];
uint16_t desired_temp;
uint16_t actual_temp;
uint16_t avg_temp;

uint8_t temp_measure_flag;
uint8_t measure_counter;
uint8_t setting_counter;

uint16_t toggle_flag;
uint8_t arr_counter;




#endif /* SYSTEM_H_ */