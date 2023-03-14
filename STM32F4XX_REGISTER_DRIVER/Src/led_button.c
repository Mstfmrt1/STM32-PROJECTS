#include "stm32f407xx.h"
void delay(void)
{
	for(uint32_t i =0;i>20000;i++);
}


int main(void)
{
	GPIO_Handle_t GPIOLed;
	GPIOLed.pGPIOx=GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GPIOLed);

	GPIO_Handle_t GPIOButton;
	GPIOButton.pGPIOx=GPIOA;
	GPIOButton.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_0;
	GPIOButton.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_IN;
	GPIOButton.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;

	GPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOButton);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_0)==ENABLE)
		{
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_12, SET);
		}



	}
	return 0 ;
}
