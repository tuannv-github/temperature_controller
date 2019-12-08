/*
 * encoder.h
 *
 *  Created on: Dec 8, 2019
 *      Author: 16138
 */

#ifndef USER_CODE_ENCODER_ENCODER_H_
#define USER_CODE_ENCODER_ENCODER_H_

#include <stdint.h>

typedef void (*on_encoder_change_t)(float value);

void encoder_init();
void encoder_register_callback(on_encoder_change_t on_encoder_change);

#endif /* USER_CODE_ENCODER_ENCODER_H_ */
