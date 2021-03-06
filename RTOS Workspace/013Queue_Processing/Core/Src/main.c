/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f4xx.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

//command structure
typedef struct APP_CMD {
	uint8_t COMMAND_NUM;
	uint8_t COMMAND_ARGS[10];
} APP_CMD_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define DWT_CTRL    (*(volatile uint32_t*)0xE0001000)

/* Dimensions the buffer into which messages destined for stdout are placed. */
#define mainMAX_MSG_LEN	( 80 )

#define LED_ON_COMMAND 					1
#define LED_OFF_COMMAND 				2
#define LED_TOGGLE_COMMAND 				3
#define LED_TOGGLE_STOP_COMMAND 		4
#define LED_READ_STATUS_COMMAND 		5
#define RTC_READ_DATE_TIME_COMMAND		6

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
volatile uint8_t user_data;
uint8_t command_buffer[20];
uint8_t command_len = 0;

//This is the menu
char menu[] = { "\
\r\nLED_ON             ----> 1 \
\r\nLED_OFF            ----> 2 \
\r\nLED_TOGGLE         ----> 3 \
\r\nLED_TOGGLE_OFF     ----> 4 \
\r\nLED_READ_STATUS    ----> 5 \
\r\nRTC_PRINT_DATETIME ----> 6 \
\r\nEXIT_APP           ----> 0 \
\r\nType your option here : " };

char usr_msg[250] = {0};

//Task handles
TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;
TaskHandle_t xTaskHandle3 = NULL;
TaskHandle_t xTaskHandle4 = NULL;

//Queue handles
QueueHandle_t command_queue=NULL;
QueueHandle_t uart_write_queue = NULL;

//Software timer handle
TimerHandle_t led_timer_handle = NULL;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void printmsg(char *msg);
void rtos_delay(uint32_t delay_in_ms);
void getArguments(uint8_t *buffer);
uint8_t getCommandCode(uint8_t *buffer);

//prototypes command helper functions
void make_led_on(void);
void make_led_off(void);
void led_toggle_start(uint32_t duration);
void led_toggle_stop(void);
void read_led_status(char *task_msg);
void read_rtc_info(char *task_msg);
void print_error_message(char *task_msg);

//tasks prototypes
void vTask1_menu_display(void *pvParameters);
void vTask2_cmd_handling(void *pvParameters);
void vTask3_cmd_processing(void *pvParameters);
void vTask4_uart_write(void *pvParameters);

//Software timer callback function prototype
void led_toggle(TimerHandle_t xTimer);

//extern void SEGGER_UART_init(uint32_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	//SEGGER_UART_init(500000);
	// Used to collect SEGGER Event time-stamps
	DWT->CTRL |= (1 << 0); //Enable CYCCNT in DWT_CTRL
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  //Start Recording with Segger SystemView
  	//SEGGER_SYSVIEW_Conf();
  	//SEGGER_SYSVIEW_Start();

	sprintf(usr_msg, "\r\nThis is Queue Command Processing Demo\r\n");
	printmsg(usr_msg);

	//Queue creations
	command_queue = xQueueCreate(10, sizeof(APP_CMD_t*));
	uart_write_queue = xQueueCreate(10, sizeof(char*));

	if((command_queue != NULL) && (uart_write_queue != NULL)) {

		xTaskCreate(vTask1_menu_display, "TASK1-MENU", 500, NULL, 1, &xTaskHandle1);
		xTaskCreate(vTask2_cmd_handling, "TASK2-CMD-HANDLING", 500, NULL, 2, &xTaskHandle2);
		xTaskCreate(vTask3_cmd_processing, "TASK3-CMD-PROCESS", 500, NULL, 2, &xTaskHandle3);
		xTaskCreate(vTask4_uart_write, "TASK4-UART-WRITE", 500, NULL, 2, &xTaskHandle4);

		/* Start the scheduler so the created tasks start executing. */
		vTaskStartScheduler();
	}

	sprintf(usr_msg, "Queue creation failed... \r\n");
	printmsg(usr_msg);

	//Code will never reach here if creation of Queue/Semaphore was successful because the scheduler will be running the tasks indefinitely.
	//If it does reach here, then it is likely due to insufficient heap memory available for a resource to be created.

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while(1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_12;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PUSH_BUTTON_Pin */
  GPIO_InitStruct.Pin = PUSH_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PUSH_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void vTask1_menu_display(void *pvParameters) {

	char *pData = menu;

	for(;;) {
		xQueueSend(uart_write_queue, &pData, portMAX_DELAY);

		//wait until notification
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
	}
}

void vTask2_cmd_handling(void *pvParameters) {

	uint8_t command_code = 0;

	APP_CMD_t *new_cmd;

	for(;;) {
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);

		//1. send command to queue
		new_cmd = (APP_CMD_t*) pvPortMalloc(sizeof(APP_CMD_t));

		taskENTER_CRITICAL();
		command_code = getCommandCode(command_buffer);
		new_cmd->COMMAND_NUM = command_code;
		getArguments(new_cmd->COMMAND_ARGS);
		taskEXIT_CRITICAL();

		//send the command to the command queue
		xQueueSend(command_queue,&new_cmd,portMAX_DELAY);
	}
}


void vTask3_cmd_processing(void *pvParameters) {

	APP_CMD_t *new_cmd;
	char task_msg[50];

	uint32_t toggle_duration = pdMS_TO_TICKS(500);

	for(;;) {
		xQueueReceive(command_queue, (void*)&new_cmd, portMAX_DELAY);

		if(new_cmd->COMMAND_NUM == LED_ON_COMMAND) {
			make_led_on();

		} else if(new_cmd->COMMAND_NUM == LED_OFF_COMMAND) {
			make_led_off();

		} else if(new_cmd->COMMAND_NUM == LED_TOGGLE_COMMAND) {
			led_toggle_start(toggle_duration);

		} else if(new_cmd->COMMAND_NUM == LED_TOGGLE_STOP_COMMAND) {
			led_toggle_stop();

		} else if(new_cmd->COMMAND_NUM == LED_READ_STATUS_COMMAND) {
			read_led_status(task_msg);

		} else if(new_cmd->COMMAND_NUM == RTC_READ_DATE_TIME_COMMAND) {
			read_rtc_info(task_msg);

		} else {
			print_error_message(task_msg);
		}
		vPortFree(new_cmd);
	}
}


void vTask4_uart_write(void *pvParameters) {

	char *pData = NULL;

	for(;;) {
		xQueueReceive(uart_write_queue, &pData, portMAX_DELAY);
		printmsg(pData);
	}
}


void printmsg(char *msg) {

	for(uint32_t i = 0; i < strlen(msg); i++) {
		HAL_UART_Transmit(&huart2, (uint8_t*)&msg[i], sizeof(msg[i]), HAL_MAX_DELAY);
	}
}

void rtos_delay(uint32_t delay_in_ms) {

	uint32_t tick_count_local = 0;

	//convert ms to ticks
	uint32_t delay_in_ticks = ((delay_in_ms * configTICK_RATE_HZ) / 1000);

	tick_count_local = xTaskGetTickCount();

	while(xTaskGetTickCount() < (tick_count_local + delay_in_ticks));
}

void USART2_IRQHandler(void) {

	uint8_t data_byte;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	if(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE)) {
		//a data byte is received from the user
		HAL_UART_Receive(&huart2, (uint8_t*)&data_byte, 1, HAL_MAX_DELAY);
		command_buffer[command_len++] = data_byte;

		if(data_byte == '\r') {
			//then user is finished entering the data
			//reset the command_len variable
			command_len = 0;

			//lets notify the command handling task
			xTaskNotifyFromISR(xTaskHandle2, 0, eNoAction, &xHigherPriorityTaskWoken);
			xTaskNotifyFromISR(xTaskHandle1, 0, eNoAction, &xHigherPriorityTaskWoken);
		}
	}

	// if the above freertos apis wake up any higher priority task, then yield the processor to the
	//higher priority task which is just woken up.

	if(xHigherPriorityTaskWoken) {
		taskYIELD();
	}
}

uint8_t getCommandCode(uint8_t *buffer) {

	return buffer[0] - 48;
}

void getArguments(uint8_t *buffer) {

}

void make_led_on(void) {

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

void make_led_off(void) {

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void led_toggle(TimerHandle_t xTimer) {

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void led_toggle_start(uint32_t duration) {

	if(led_timer_handle == NULL) {
		//1. lets create the software timer
		led_timer_handle = xTimerCreate("LED-TIMER", duration, pdTRUE, NULL, led_toggle);

		//2. start the software timer
		xTimerStart(led_timer_handle, portMAX_DELAY);
	} else {
		//start the software timer
		xTimerStart(led_timer_handle, portMAX_DELAY);
	}
}

void led_toggle_stop(void) {

	 xTimerStop(led_timer_handle, portMAX_DELAY);
}

void read_led_status(char *task_msg) {

	sprintf(task_msg, "\r\nLED status is : %d\r\n", HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5));
	xQueueSend(uart_write_queue, &task_msg, portMAX_DELAY);
}

void read_rtc_info(char *task_msg)
{
	RTC_TimeTypeDef RTC_time;
	RTC_DateTypeDef RTC_date;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &RTC_time, RTC_FORMAT_BIN);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &RTC_date, RTC_FORMAT_BIN);

	sprintf(task_msg,"\r\nTime: %02d:%02d:%02d \r\n Date : %02d-%2d-%2d \r\n", RTC_time.Hours, RTC_time.Minutes, RTC_time.Seconds, \
									RTC_date.Date, RTC_date.Month, RTC_date.Year);
	xQueueSend(uart_write_queue, &task_msg, portMAX_DELAY);
}

void print_error_message(char *task_msg) {

	sprintf(task_msg, "\r\nInvalid command received\r\n");
	xQueueSend(uart_write_queue, &task_msg, portMAX_DELAY);
}

/* USER CODE END 4 */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
