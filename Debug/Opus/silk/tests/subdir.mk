################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/silk/tests/test_unit_LPC_inv_pred_gain.c 

OBJS += \
./Opus/silk/tests/test_unit_LPC_inv_pred_gain.o 

C_DEPS += \
./Opus/silk/tests/test_unit_LPC_inv_pred_gain.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/silk/tests/%.o Opus/silk/tests/%.su Opus/silk/tests/%.cyclo: ../Opus/silk/tests/%.c Opus/silk/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-silk-2f-tests

clean-Opus-2f-silk-2f-tests:
	-$(RM) ./Opus/silk/tests/test_unit_LPC_inv_pred_gain.cyclo ./Opus/silk/tests/test_unit_LPC_inv_pred_gain.d ./Opus/silk/tests/test_unit_LPC_inv_pred_gain.o ./Opus/silk/tests/test_unit_LPC_inv_pred_gain.su

.PHONY: clean-Opus-2f-silk-2f-tests

