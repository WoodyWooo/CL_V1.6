################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AudioLibraries/scr/SDR.c \
../AudioLibraries/scr/audioBF.c 

OBJS += \
./AudioLibraries/scr/SDR.o \
./AudioLibraries/scr/audioBF.o 

C_DEPS += \
./AudioLibraries/scr/SDR.d \
./AudioLibraries/scr/audioBF.d 


# Each subdirectory must supply rules for building sources it contributes
AudioLibraries/scr/%.o AudioLibraries/scr/%.su AudioLibraries/scr/%.cyclo: ../AudioLibraries/scr/%.c AudioLibraries/scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AudioLibraries-2f-scr

clean-AudioLibraries-2f-scr:
	-$(RM) ./AudioLibraries/scr/SDR.cyclo ./AudioLibraries/scr/SDR.d ./AudioLibraries/scr/SDR.o ./AudioLibraries/scr/SDR.su ./AudioLibraries/scr/audioBF.cyclo ./AudioLibraries/scr/audioBF.d ./AudioLibraries/scr/audioBF.o ./AudioLibraries/scr/audioBF.su

.PHONY: clean-AudioLibraries-2f-scr

