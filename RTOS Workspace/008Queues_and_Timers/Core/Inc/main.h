/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef struct {
	uint8_t payload[10]; 	//data bytes of the command
	uint32_t len; 			//command length
} command_t;

/* Application States */
typedef enum {
	sMainMenu = 0,
	sLedEffect,
	sRtcMenu,
	sRtcTimeConfig,
	sRtcDateConfig,
	sRtcReport,
} state_t;

extern xTaskHandle handle_menu_task;
extern xTaskHandle handle_cmd_task;
extern xTaskHandle handle_print_task;
extern xTaskHandle handle_led_task;
extern xTaskHandle handle_rtc_task;

extern QueueHandle_t q_data; //10 data bytes length
extern QueueHandle_t q_print;

extern TimerHandle_t handle_led_timer[4];
extern TimerHandle_t rtc_timer;

//initial state variable
extern state_t curr_state;

extern UART_HandleTypeDef huart2;
extern RTC_HandleTypeDef hrtc;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define HH_CONFIG 			0
#define MM_CONFIG 			1
#define SS_CONFIG 			2

#define DATE_CONFIG 		0
#define MONTH_CONFIG 		1
#define DAYOFWEEK_CONFIG 	2
#define YEAR_CONFIG 		3

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void menu_task(void *param);
void cmd_handler_task(void *param);
void print_task(void *param);
void led_task(void *param);
void rtc_task(void *param);

void led_effect(int n);
void turn_off_all_leds(void);
void turn_on_all_leds(void);
void led_effect_stop(void);
void LED_effect1(void);
void LED_effect2(void);
void LED_effect3(void);
void LED_effect4(void);

void show_time_date(void);
void show_time_date_itm(void);
void rtc_configure_date(RTC_DateTypeDef *date);
void rtc_configure_time(RTC_TimeTypeDef *time);
int validate_rtc_information(RTC_TimeTypeDef *time, RTC_DateTypeDef *date);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PUSH_BUTTON_Pin GPIO_PIN_13
#define PUSH_BUTTON_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_10
#define LED_GREEN_GPIO_Port GPIOB
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define LED_RED_Pin GPIO_PIN_7
#define LED_RED_GPIO_Port GPIOB
#define LED_YELLOW_Pin GPIO_PIN_8
#define LED_YELLOW_GPIO_Port GPIOB
#define LED_BLUE_Pin GPIO_PIN_9
#define LED_BLUE_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define LED1		LED_RED_Pin
#define LED1_PORT	LED_RED_GPIO_Port
#define LED2		LED_YELLOW_Pin
#define LED2_PORT	LED_YELLOW_GPIO_Port
#define LED3		LED_BLUE_Pin
#define LED3_PORT	LED_BLUE_GPIO_Port
#define LED4		LED_GREEN_Pin
#define LED4_PORT	LED_GREEN_GPIO_Port
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
