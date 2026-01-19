################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AudioOut/src/Audio_out_control.c \
../AudioOut/src/PCM1774_CODEC_Driver.c 

OBJS += \
./AudioOut/src/Audio_out_control.o \
./AudioOut/src/PCM1774_CODEC_Driver.o 

C_DEPS += \
./AudioOut/src/Audio_out_control.d \
./AudioOut/src/PCM1774_CODEC_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
AudioOut/src/%.o AudioOut/src/%.su AudioOut/src/%.cyclo: ../AudioOut/src/%.c AudioOut/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AudioOut-2f-src

clean-AudioOut-2f-src:
	-$(RM) ./AudioOut/src/Audio_out_control.cyclo ./AudioOut/src/Audio_out_control.d ./AudioOut/src/Audio_out_control.o ./AudioOut/src/Audio_out_control.su ./AudioOut/src/PCM1774_CODEC_Driver.cyclo ./AudioOut/src/PCM1774_CODEC_Driver.d ./AudioOut/src/PCM1774_CODEC_Driver.o ./AudioOut/src/PCM1774_CODEC_Driver.su

.PHONY: clean-AudioOut-2f-src

