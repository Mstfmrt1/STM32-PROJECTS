
#include "main.h"

extern UART_HandleTypeDef huart2;
void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}


void EXTI0_IRQHandler(void)
{

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart2);
}
