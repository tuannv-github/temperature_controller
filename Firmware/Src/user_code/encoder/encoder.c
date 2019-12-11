/*
 * encoder.c
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */

#include "encoder.h"
#include "tim.h"
#include "Src/user_code/timer/timer.h"
#include "gpio.h"
#include <stdbool.h>

static on_encoder_change_t gon_encoder_change;
static timer_ID_t buzzer_timer_id = -1;
static void turn_off_buzzer_callback(uint8_t* cxt){
	buzzer_timer_id = -1;
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
}

static void encoder_callback(uint8_t *context){
	float changed;
	uint32_t enc = htim4.Instance->CNT;
	if(enc > 32768) {
		enc = 65536 - enc;
		changed = -((float)enc);
	}
	else{
		changed = enc;
	}
	htim4.Instance->CNT = 0;
	changed = (changed*changed*changed*0.001 + changed*0.001);
	if(gon_encoder_change != 0 && changed != 0){
		gon_encoder_change(changed);
	}
	if(buzzer_timer_id == -1 && changed !=0){
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
		buzzer_timer_id = timer_register_callback(turn_off_buzzer_callback, 5, 0, TIMER_MODE_ONE_SHOT);
	}
}

void encoder_init(){
	HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_ALL);
	htim4.Instance->CNT = 0;
	timer_register_callback(encoder_callback,10,0,TIMER_MODE_REPEAT);
	gon_encoder_change = 0;
}

void encoder_register_callback(on_encoder_change_t on_encoder_change){
	if(on_encoder_change!=0){
		gon_encoder_change = on_encoder_change;
	}
}
