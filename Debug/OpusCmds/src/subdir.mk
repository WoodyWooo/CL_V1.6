################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OpusCmds/src/opus_func.c \
../OpusCmds/src/opus_init.c 

OBJS += \
./OpusCmds/src/opus_func.o \
./OpusCmds/src/opus_init.o 

C_DEPS += \
./OpusCmds/src/opus_func.d \
./OpusCmds/src/opus_init.d 


# Each subdirectory must supply rules for building sources it contributes
OpusCmds/src/%.o OpusCmds/src/%.su OpusCmds/src/%.cyclo: ../OpusCmds/src/%.c OpusCmds/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OpusCmds-2f-src

clean-OpusCmds-2f-src:
	-$(RM) ./OpusCmds/src/opus_func.cyclo ./OpusCmds/src/opus_func.d ./OpusCmds/src/opus_func.o ./OpusCmds/src/opus_func.su ./OpusCmds/src/opus_init.cyclo ./OpusCmds/src/opus_init.d ./OpusCmds/src/opus_init.o ./OpusCmds/src/opus_init.su

.PHONY: clean-OpusCmds-2f-src

