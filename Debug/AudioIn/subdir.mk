################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AudioIn/stm32f4xx_hal_tim.c 

OBJS += \
./AudioIn/stm32f4xx_hal_tim.o 

C_DEPS += \
./AudioIn/stm32f4xx_hal_tim.d 


# Each subdirectory must supply rules for building sources it contributes
AudioIn/%.o AudioIn/%.su AudioIn/%.cyclo: ../AudioIn/%.c AudioIn/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../AudioIn/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AudioIn

clean-AudioIn:
	-$(RM) ./AudioIn/stm32f4xx_hal_tim.cyclo ./AudioIn/stm32f4xx_hal_tim.d ./AudioIn/stm32f4xx_hal_tim.o ./AudioIn/stm32f4xx_hal_tim.su

.PHONY: clean-AudioIn

