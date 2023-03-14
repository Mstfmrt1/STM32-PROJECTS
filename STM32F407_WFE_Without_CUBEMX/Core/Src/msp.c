
#include "main.h"
#include "stm32f4xx_hal_tim.h"

void HAL_MspInit(void)
{
    //LOW LEVEL INIT
	//Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions ARM CORTEX MX
	SCB->SHCSR |= 0x7 << 16; //usage fault, memory fault and bus fault system exceptions

	//3. configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{

	//ENABLE CLOCK
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2.ENABLE IRQ
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//SET PRIORITY
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn,1,0);

}

 void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	 GPIO_InitTypeDef gpio_uart;
	 //USART 2 LOW LEVEL INIT

	 //ENABLE CLOCK USART2 PERIPHERAL
	 __HAL_RCC_USART2_CLK_SLEEP_DISABLE();
	 __HAL_RCC_USART2_CLK_ENABLE();

	 __HAL_RCC_GPIOA_CLK_ENABLE();

	 //PINMUXING
	 gpio_uart.Pin = GPIO_PIN_2;
	 gpio_uart.Mode =GPIO_MODE_AF_PP;
	 gpio_uart.Pull = GPIO_PULLUP;
	 gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	 gpio_uart.Alternate =  GPIO_AF7_USART2; //UART2_TX
	 HAL_GPIO_Init(GPIOA,&gpio_uart);

	 gpio_uart.Pin = GPIO_PIN_3; //UART2_RX
	 HAL_GPIO_Init(GPIOA,&gpio_uart);
	 //NVIC SETTINGS
	 HAL_NVIC_EnableIRQ(USART2_IRQn);
	 HAL_NVIC_SetPriority(USART2_IRQn,0,0);

}

