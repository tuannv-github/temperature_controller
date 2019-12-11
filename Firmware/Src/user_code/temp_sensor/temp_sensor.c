/*
 * temp_sensor.c
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */
#include "adc.h"
#include <stdbool.h>
#include <math.h>
#include "Src/user_code/timer/timer.h"

#define BETA 	4066.0
#define T0		(25+273.15)
#define R0		(100000.0)
#define VCC		5.0

static uint32_t adc_value = 0;
static uint32_t is_first_read = true;
static float temperator = 0;
static float k;

static void read_temp_cb(uint8_t *ctx){
	if(is_first_read == true){
		adc_value = HAL_ADC_GetValue(&hadc1);
		is_first_read = false;
	}
	else{
		adc_value = 0.99*adc_value + 0.01*HAL_ADC_GetValue(&hadc1);
	}
	float voltage = adc_value*3.3/4096.;
	float resistance = voltage/((VCC-voltage)/56000.0);
	temperator = BETA/log(resistance/k)-273.15;
}

void temp_sensor_init(){
	HAL_ADC_Start(&hadc1);
	k = R0 * exp(-BETA/T0);
	timer_register_callback(read_temp_cb, 10, 0, TIMER_MODE_REPEAT);
}

float temp_sensor_read(){
	return temperator;
}
