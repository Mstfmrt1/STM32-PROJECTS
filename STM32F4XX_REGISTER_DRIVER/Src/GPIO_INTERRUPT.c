#include "stm32f407xx.h"
#include <string.h>
void delay(void)
{
	for(uint32_t i =0;i>20000;i++);
}


int main(void)
{
	GPIO_Handle_t GPIOLed,GPIOButton;;
	memset(&GPIOLed,0,sizeof(GPIOLed));//yapının her üyesini 0 yaparak başlatır.
	memset(&GPIOButton,0,sizeof(GPIOButton));
	GPIOLed.pGPIOx=GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GPIOLed);


	GPIOButton.pGPIOx=GPIOA;
	GPIOButton.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_0;
	GPIOButton.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_IT_FT;
	GPIOButton.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOButton);

	//IRQ CONFIGURATION
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0, 15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0, ENABLE);
	while(1);
}
	void EXTI0_IRQHandler(void)
	{
		delay();
		GPIO_IRQHandling(GPIO_PIN_0);//clear the pending event from extı line
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);
	}



