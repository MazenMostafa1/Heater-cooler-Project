/*
 * SYSTEM.c
 *
 * Created: 12/14/2021 10:58:16 AM
 *  Author: pc
 */ 
#include "SYSTEM.h"

void system_init(void)
{
	// initialization of all the used drivers
	ADC_init();
	Buttons_init();
	cool_init();
	heat_init();
	led_init();
	SSD_init();
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	
	// ON_OFF_flag is initially OFF
	Current_state = OFF;
	
	// to set initial temp. and fill array
	if(EEPROM_read(0x0000) != 0xFF){
		desired_temp = EEPROM_read(0x0000);
	}
	else{
		desired_temp = FIRST_DESIRED_TEMP;
	}
	
	temp_arr_init();
	
	// To Save desired temp in EEPROM
	EEPROM_write(0x0000,(uint8_t) desired_temp);	
	
}


// This function turns off all displays  and the Timers.


void OFF_state(void)
{
		SSD_off();
		led_off();
		heat_off();
		cool_off();
		sleep(); 
}


	//The On state function waits for the temp to be measured every 100 ms and then checks the up and down button to set the desired temp


void ON_state(void)
{
	// when the 100ms pass and flag is triggered, measure temperature from the sensor and add it to array and calculate the average
	if (temp_measure_flag == 1){
		actual_temp = (ADC_read()*0.5);
		add_temp(temp_arr , actual_temp);
		avg_temp = calc_avg(temp_arr);	
		temp_measure_flag = 0;
	}
	SSD_type(actual_temp);
	// turn cooler or heater ON and OFF depending on the average temperature measured from the array.
	//If It is more than the desired+margin turns on the cooler
	//If It is less than the desired+margin turns on the heater
	change_temp();
	 // Check if UP or DOWN buttons are pressed to switch to the SETTING_MODE
	if(UP_pressed()==PRESSED || DOWN_pressed()==PRESSED){
		SSD_disable();
		setting_counter = 0;
		Current_state = SETTING;
			
	}
}





void SET_state(void)
{
	heat_off();
	cool_off();
	led_off();
	
	// to toggle the seven segment while writing the desired temperature
	
	if(toggle_flag == 1){
		SSD_type(desired_temp);
	}
	else{
		SSD_off();
	}
	
	// if UP or DOWN pressed, change the desired temp as long as it's still in range
	
	if((UP_pressed() == PRESSED) && (desired_temp < MAXIMUM_TEMP)){
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		SSD_type(desired_temp);
	}
	else if ((DOWN_pressed() == PRESSED) && (desired_temp > MINIMUM_TEMP)){
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		SSD_type(desired_temp);
	}
	
	EEPROM_write(0x0000,desired_temp);
	
}


// This function turns on the Heater or the Cooler


void change_temp(void)
{
	if( (desired_temp < avg_temp + MARGIN) && (desired_temp > avg_temp - MARGIN) ){
		// Actual Temperature equals Desired Temperature
		// No need for Heating or Cooling
		heat_off();
		cool_off();
		led_off();
	}
	else if(desired_temp < avg_temp + MARGIN){
		// Actual Temperature is Larger
		// we need the Cooling element
		
		heat_off();
		cool_on();
		led_on();
	}
	else if (desired_temp > avg_temp - MARGIN){
		// Actual Temperature is Smaller
		// we need the Heating element
		
		heat_on();
		cool_off();
		if (toggle_flag == 1)
		{
			led_on();
		}
		else {
			led_off();
		}
	}
}


//This function is a part of the Sys_init. function that reads the first actual temperature and put it at all elements in the temperature array.


void temp_arr_init(void)
{
	uint16_t first_temp = ADC_read()*0.5;
	
	for (uint8_t i = 0; i<NUM_OF_MEASURES; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = calc_avg(temp_arr);
	arr_counter = 0;
}


// This function is used to add the new measured temperature to the temperature array that will have its average during the code.


void add_temp(uint16_t * arr , uint16_t new_val)
{
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}


// to calculate the last 10 measured temperatures.


uint16_t calc_avg(uint16_t * arr)
{
	uint16_t sum = 0;
	uint16_t avg;
	
	for(uint8_t i=0; i<NUM_OF_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg = (uint16_t) sum / NUM_OF_MEASURES;
	return avg;
}


// This function is to keep the CPU  idle  to save more power when it doesn't need to do anything


void sleep(void)
{
	
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);

}