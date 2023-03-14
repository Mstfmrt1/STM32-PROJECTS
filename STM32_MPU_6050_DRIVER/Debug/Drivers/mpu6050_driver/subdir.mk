################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/mpu6050_driver/mpu6050.c \
../Drivers/mpu6050_driver/sensordriver.c \
../Drivers/mpu6050_driver/sensortest.c 

OBJS += \
./Drivers/mpu6050_driver/mpu6050.o \
./Drivers/mpu6050_driver/sensordriver.o \
./Drivers/mpu6050_driver/sensortest.o 

C_DEPS += \
./Drivers/mpu6050_driver/mpu6050.d \
./Drivers/mpu6050_driver/sensordriver.d \
./Drivers/mpu6050_driver/sensortest.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/mpu6050_driver/%.o Drivers/mpu6050_driver/%.su: ../Drivers/mpu6050_driver/%.c Drivers/mpu6050_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/MERT FILE/STM32 PROJECTS GİTHUB/MPU_6050/Drivers/mpu6050_driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-mpu6050_driver

clean-Drivers-2f-mpu6050_driver:
	-$(RM) ./Drivers/mpu6050_driver/mpu6050.d ./Drivers/mpu6050_driver/mpu6050.o ./Drivers/mpu6050_driver/mpu6050.su ./Drivers/mpu6050_driver/sensordriver.d ./Drivers/mpu6050_driver/sensordriver.o ./Drivers/mpu6050_driver/sensordriver.su ./Drivers/mpu6050_driver/sensortest.d ./Drivers/mpu6050_driver/sensortest.o ./Drivers/mpu6050_driver/sensortest.su

.PHONY: clean-Drivers-2f-mpu6050_driver

