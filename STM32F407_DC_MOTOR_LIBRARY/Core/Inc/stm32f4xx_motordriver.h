

#ifndef STM32F4XX_MOTORDRIVER_H_
#define STM32F4XX_MOTORDRIVER_H_

#define HAL_TIM_MODULE_ENABLED

#include "stm32f4xx_hal.h"


// DC Motor Rotation Directions
#define DIR_ClockWıse        0
#define DIR_CClockWıse       1
// MOTOR INSTANCE
#define DC_MOTOR1    0
#define DC_MOTOR2    1
// DC Motor PWM Properties
#define DC_MOTOR_PWM_RES  10
#define DC_MOTOR_F_PWM    19000

// The Number OF DC MOTORs To Be Used
#define DC_MOTOR_UNITS  1

typedef struct
{
	GPIO_TypeDef * DIR1_GPIO;
	GPIO_TypeDef * DIR2_GPIO;
	uint16_t       DIR1_PIN;
	uint16_t       DIR2_PIN;
	TIM_TypeDef*   TIM_Instance;
	uint32_t       PWM_TIM_CH;
	uint16_t       TIM_CLK_MHz;
	uint32_t       PWM_FREQ_Hz;
	uint8_t        PWM_RES_BITS;
}DC_MOTOR_CfgType;

extern const DC_MOTOR_CfgType DC_MOTOR_CfgParam[DC_MOTOR_UNITS];


void DC_MOTOR_Init(uint8_t MOTOR_Instance);
void DC_MOTOR_Start(uint8_t MOTOR_Instance, uint8_t DIR, uint16_t SPEED);
void DC_MOTOR_Set_Speed(uint8_t MOTOR_Instance, uint16_t SPEED);
void DC_MOTOR_Set_Dir(uint8_t MOTOR_Instance, uint8_t DIR);
void DC_MOTOR_Stop(uint8_t MOTOR_Instance);
uint32_t DC_MOTOR_Get_MaxFreq(uint8_t MOTOR_Instance);


#endif
