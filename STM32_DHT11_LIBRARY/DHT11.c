#include "DHT11.h"
#include "stm32f4xx_hal.h"

#define timer htim1


extern TIM_HandleTypeDef timer;
extern void delay (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&timer, 0);
	while (__HAL_TIM_GET_COUNTER(&timer) < us);
}


void set_gpio_output (void)//DHT11 GPIO OUTPUT SETTING
{
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}


void set_gpio_input (void)//DHT11 GPIO INPUT SETTING
{
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void DHT11_start (void)
{
	    set_gpio_output ();  // set the pin as output
		HAL_GPIO_WritePin (GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
		delay(1000);
		HAL_GPIO_WritePin (GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);// pull the pin low
		delay(18000);   // wait for 18ms
		HAL_GPIO_WritePin (GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
		delay(20);
		set_gpio_input ();   // set as input
}


void DHT11_check_response (void)
{
    delay(40);
	if (!(HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1)))
	{
		delay(80);
		if ((HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1))) check = 1;
	}
	while ((HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1)));   // wait for the pin to go low
}

uint8_t DHT11_read_data (void)
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1)));   // wait for the pin to go high
		delay(40);   // wait for 40 us
		if ((HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1)) == 0)   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (GPIOC, GPIO_PIN_1)));  // wait for the pin to go low
	}
	return i;
}

void DHT11_Init(void)
{
	DHT11_start ();
		  DHT11_check_response ();
		  Rh_byte1 = DHT11_read_data ();
		  Rh_byte2 = DHT11_read_data ();
		  Temp_byte1 = DHT11_read_data ();
		  Temp_byte2 = DHT11_read_data ();
		  sum = DHT11_read_data();
		  /*if (sum == (Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2))    // if the data is correct
		  		{
		  			char text[50];
		  			sprintf(text, "S:%dC | NEM:%d%%", Temp_byte1, Rh_byte1);
		  			lcd_put_cur(1, 0);
		  			lcd_send_string(text);
		  			HAL_Delay (1000);
		  		}*/

}


