/*
 * led.c
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */

#include "gpio.h"
#include "led.h"

static uint8_t digits[4] = {0};
static uint8_t cur_digit = 0;

static void led_show_0(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_SET);
}

static void led_show_1(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_SET);
}

static void led_show_2(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_3(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_4(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_5(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_6(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_7(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_SET);
}

static void led_show_8(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

static void led_show_9(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_RESET);
}

void led_off(){
	HAL_GPIO_WritePin(LED_A_GPIO_Port,LED_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_C_GPIO_Port,LED_C_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_D_GPIO_Port,LED_D_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_E_GPIO_Port,LED_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_F_GPIO_Port,LED_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin, GPIO_PIN_SET);
}

void led_show_digit(uint8_t digit){
	switch(digit){
	case 0:
		led_show_0();
		break;
	case 1:
		led_show_1();
		break;
	case 2:
		led_show_2();
		break;
	case 3:
		led_show_3();
		break;
	case 4:
		led_show_4();
		break;
	case 5:
		led_show_5();
		break;
	case 6:
		led_show_6();
		break;
	case 7:
		led_show_7();
		break;
	case 8:
		led_show_8();
		break;
	case 9:
		led_show_9();
		break;
	default:
		break;

	}
}

static void led_show_callback(uint8_t *context){

	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_DP_GPIO_Port,LED_DP_Pin, GPIO_PIN_SET);


	switch(cur_digit){
	case 0:
		led_show_digit(digits[cur_digit]);
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_SET);
		break;
	case 1:
		led_show_digit(digits[cur_digit]);
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
		break;
	case 2:
		led_show_digit(digits[cur_digit]);
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_DP_GPIO_Port,LED_DP_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		if(digits[cur_digit] != 0){
			led_show_digit(digits[cur_digit]);
		}
		else{
			led_off();
		}
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
		break;
	}

	cur_digit++;
	if(cur_digit == 4) cur_digit = 0;
}

void led_init(){
	 HAL_GPIO_WritePin(LED_DP_GPIO_Port,LED_DP_Pin, GPIO_PIN_SET);
	 timer_register_callback(led_show_callback, 5, 0, TIMER_MODE_REPEAT);
}

// 00.00 -> 99.99
void led_show(float value){
	if(value < 0) value = 0;
	if(value > 99.99) value = 99.99;
	uint16_t int_value = (uint16_t)(value*100);
	digits[0] = (int_value)% 10;
	digits[1] = (int_value/10)% 10;
	digits[2] = (int_value/100)% 10;
	digits[3] = (int_value/1000)% 10;
}

