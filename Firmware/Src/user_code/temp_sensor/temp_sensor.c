/*
 * temp_sensor.c
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */
#include "adc.h"
#include <stdbool.h>

static uint32_t adc_value = 0;
static uint32_t is_first_read = true;

void temp_sensor_init(){
	HAL_ADC_Start(&hadc1);
}

float temp_sensor_read(){
	if(is_first_read == true){
		adc_value = HAL_ADC_GetValue(&hadc1);
		is_first_read = false;
	}
	else{
		adc_value = 0.99*adc_value + 0.01*HAL_ADC_GetValue(&hadc1);
	}
	float temp = (float)adc_value/100.;
	return temp;
}
