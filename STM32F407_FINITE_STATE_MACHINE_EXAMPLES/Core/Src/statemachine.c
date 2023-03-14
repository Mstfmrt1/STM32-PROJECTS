
#include "main.h"


UART_HandleTypeDef huart3;
static int clock;

uint32_t A_Prev_time;
uint32_t A_Now;
int A_Delta;

uint32_t B_Prev_time;
uint32_t B_Now;
int B_Delta;

uint32_t C_Prev_time;
uint32_t C_Now;
int C_Delta;




void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM3_Init(void);

void STATE_A_FUNCTION(void);
void STATE_B_FUNCTION(void);
void STATE_C_FUNCTION(void);
void STATE_MACHINE_INIT(void);
void printmsg(char *format,...);

typedef enum states{
	STATE_A=0,
	STATE_B,
	STATE_C
}state_type;

static state_type current_state;
TIM_HandleTypeDef htim3;

/************ prints formatted string to console over UART *********** */
void printmsg(char *format,...)
{

	char str[80];

	/*Extract the the argument list using VA apis */
	va_list args;
	va_start(args, format);
	vsprintf(str, format,args);
	HAL_UART_Transmit(&huart3,(uint8_t *)str, strlen(str),HAL_MAX_DELAY);
	va_end(args);

 }

void Systick_Handler(void)
{
	HAL_IncTick();

}


static void (*state_table[])(void)={
		STATE_A_FUNCTION,
		STATE_B_FUNCTION,
		STATE_C_FUNCTION
	};




void STATE_MACHINE_INIT(void)
	{
	current_state=STATE_A;
	clock=0;

	}

void STATE_A_FUNCTION(void)
	{
		if(clock==2)
		{
				current_state=STATE_B;

				A_Now=HAL_GetTick();
				A_Delta=A_Now-A_Prev_time;
				// MS TO SECONDS//
				A_Delta/=1000;
				A_Prev_time=A_Now;

				printmsg("THIS IS THE OUTPUT OF STATE A :\n");
				HAL_UART_Transmit(&huart3, (uint8_t*)A_Delta, sizeof(A_Delta), HAL_MAX_DELAY);
				printmsg("SECONDS AGO");

				current_state=STATE_B;
				printmsg("EXECUTION OF STATE A\r\n");
		}
	}
void STATE_B_FUNCTION(void)
	{
		if(clock==5)
		{
			current_state=STATE_C;

			B_Now=HAL_GetTick();
			B_Delta=B_Now-B_Prev_time;
			// MS TO SECONDS//
			B_Delta/=1000;
			B_Prev_time=B_Now;

			printmsg("THIS IS THE OUTPUT OF STATE B :\n");
			HAL_UART_Transmit(&huart3, (uint8_t*)B_Delta, sizeof(B_Delta), HAL_MAX_DELAY);
			printmsg("SECONDS AGO");

			current_state=STATE_C;
			printmsg("EXECUTION OF STATE B\r\n");
		}
	}
void STATE_C_FUNCTION(void)
	{
		if(clock==9)
		{
			clock=0;

			C_Now=HAL_GetTick();
			C_Delta=C_Now-C_Prev_time;
			// MS TO SECONDS//
			C_Delta/=1000;
			C_Prev_time=C_Now;

			printmsg("THIS IS THE OUTPUT OF STATE C :\n");
			HAL_UART_Transmit(&huart3, (uint8_t*)C_Delta, sizeof(C_Delta), HAL_MAX_DELAY);
			printmsg("SECONDS AGO");


			current_state=STATE_A;
			printmsg("EXECUTION OF STATE C\r\n");
		}
	}


int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART3_UART_Init();

  while (1)
  {
	  state_table[current_state]();
	  HAL_Delay(1000);
	  clock++;
  }

}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_USART3_UART_Init(void)
{


  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

static void MX_TIM3_Init(void)
{


  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 15999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 500;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }


}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }

}

