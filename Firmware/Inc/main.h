/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TEMP_PWM_Pin GPIO_PIN_0
#define TEMP_PWM_GPIO_Port GPIOA
#define TH_SENSOR_Pin GPIO_PIN_3
#define TH_SENSOR_GPIO_Port GPIOA
#define LED_C_Pin GPIO_PIN_10
#define LED_C_GPIO_Port GPIOB
#define LED_D_Pin GPIO_PIN_11
#define LED_D_GPIO_Port GPIOB
#define LED_E_Pin GPIO_PIN_12
#define LED_E_GPIO_Port GPIOB
#define LED_F_Pin GPIO_PIN_13
#define LED_F_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOB
#define LED_DP_Pin GPIO_PIN_15
#define LED_DP_GPIO_Port GPIOB
#define LED_3_Pin GPIO_PIN_11
#define LED_3_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_12
#define LED_2_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_15
#define LED_1_GPIO_Port GPIOA
#define LED_0_Pin GPIO_PIN_3
#define LED_0_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOB
#define ENC_SW_Pin GPIO_PIN_5
#define ENC_SW_GPIO_Port GPIOB
#define ENC_PB_Pin GPIO_PIN_6
#define ENC_PB_GPIO_Port GPIOB
#define ENC_PA_Pin GPIO_PIN_7
#define ENC_PA_GPIO_Port GPIOB
#define LED_A_Pin GPIO_PIN_8
#define LED_A_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_9
#define LED_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
