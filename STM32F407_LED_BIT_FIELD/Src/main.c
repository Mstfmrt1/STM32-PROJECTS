

#include <stdint.h>
#include "main.h"

/*
    uint32_t *pclockcontrol_reg=(uint32_t*)0X40023830; // (
    uint32_t *pPortDmode_reg=(uint32_t*)0X40020C00;
    uint32_t *pDoutdata_reg=(uint32_t*)0X40020C14;
    */

int main(void)
{
	RCC_AHB1ENR_t volatile  *const pClkControlreg =(RCC_AHB1ENR_t *)0X40023830;
	GPIOx_MODE_t volatile *const pGpioxmode=(GPIOx_MODE_t*)0X40020C00;
	GPIOx_ODR_t   volatile *const pPortDOutReg  = (GPIOx_ODR_t*) 0x40020C14;

	pClkControlreg->gpiod_en=1;	pGpioxmode->pin_12=1;



	while(1)
	{
		pPortDOutReg->pin_12=1;
		for(uint32_t i =0;i<30000;i++);
		pPortDOutReg->pin_12=0;
		for(uint32_t i =0;i<30000;i++);
	}
}
