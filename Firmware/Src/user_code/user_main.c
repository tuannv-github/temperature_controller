/*
 * user.c
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */

#include "stdint.h"

#include "user_main.h"
#include "led/led.h"
#include "encoder/encoder.h"
#include "temp_sensor/temp_sensor.h"
#include "gpio.h"
#include "tim.h"

static float desired_temp = 0;
static float current_temp = 0;
static timer_ID_t show_current_temp_callback_timer_id = -1;
static timer_ID_t show_desired_temp_callback_timer_id = -1;


static void show_curr_temp_callback(uint8_t *context){
	float current_temp = temp_sensor_read();
	led_show(current_temp);
}

static void show_desired_temp_timeout_callback(uint8_t *context){
	timer_unregister_callback(show_desired_temp_callback_timer_id);
	show_desired_temp_callback_timer_id = -1;
	show_current_temp_callback_timer_id = timer_register_callback(show_curr_temp_callback, 100, 0, TIMER_MODE_REPEAT);
}

void cmd_callback(float changed){
	if(show_current_temp_callback_timer_id != -1){
		timer_unregister_callback(show_current_temp_callback_timer_id);
	}
	show_current_temp_callback_timer_id = -1;

	desired_temp -= changed;
	if(desired_temp <= 0) desired_temp = 0;
	if (desired_temp >= 99.99) desired_temp = 99.99;

	led_show(desired_temp);
	if(show_desired_temp_callback_timer_id != -1){
		timer_unregister_callback(show_desired_temp_callback_timer_id);
	}
	show_desired_temp_callback_timer_id = timer_register_callback(show_desired_temp_timeout_callback, 1000, 0, TIMER_MODE_ONE_SHOT);
}

static void enc_sw_callback(uint8_t *context){
	if(HAL_GPIO_ReadPin(ENC_SW_GPIO_Port,ENC_SW_Pin) == GPIO_PIN_RESET){
		if(show_current_temp_callback_timer_id != -1){
			timer_unregister_callback(show_current_temp_callback_timer_id);
		}
		show_current_temp_callback_timer_id = -1;

		led_show(desired_temp);
		if(show_desired_temp_callback_timer_id != -1){
			timer_unregister_callback(show_desired_temp_callback_timer_id);
		}
		show_desired_temp_callback_timer_id = timer_register_callback(show_desired_temp_timeout_callback, 1000, 0, TIMER_MODE_ONE_SHOT);
	}
}

void user_main(){
	led_init();
	led_show(current_temp);
	encoder_init();
	encoder_register_callback(cmd_callback);
	temp_sensor_init();

	show_current_temp_callback_timer_id = timer_register_callback(show_curr_temp_callback, 100, 0, TIMER_MODE_REPEAT);
	timer_register_callback(enc_sw_callback, 100, 0, TIMER_MODE_REPEAT);

	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 900);
}
