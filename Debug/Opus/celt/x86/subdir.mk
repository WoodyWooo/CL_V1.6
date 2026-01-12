################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/celt/x86/celt_lpc_sse.c \
../Opus/celt/x86/pitch_sse.c \
../Opus/celt/x86/pitch_sse2.c \
../Opus/celt/x86/pitch_sse4_1.c \
../Opus/celt/x86/vq_sse2.c \
../Opus/celt/x86/x86_celt_map.c \
../Opus/celt/x86/x86cpu.c 

OBJS += \
./Opus/celt/x86/celt_lpc_sse.o \
./Opus/celt/x86/pitch_sse.o \
./Opus/celt/x86/pitch_sse2.o \
./Opus/celt/x86/pitch_sse4_1.o \
./Opus/celt/x86/vq_sse2.o \
./Opus/celt/x86/x86_celt_map.o \
./Opus/celt/x86/x86cpu.o 

C_DEPS += \
./Opus/celt/x86/celt_lpc_sse.d \
./Opus/celt/x86/pitch_sse.d \
./Opus/celt/x86/pitch_sse2.d \
./Opus/celt/x86/pitch_sse4_1.d \
./Opus/celt/x86/vq_sse2.d \
./Opus/celt/x86/x86_celt_map.d \
./Opus/celt/x86/x86cpu.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/celt/x86/%.o Opus/celt/x86/%.su Opus/celt/x86/%.cyclo: ../Opus/celt/x86/%.c Opus/celt/x86/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-celt-2f-x86

clean-Opus-2f-celt-2f-x86:
	-$(RM) ./Opus/celt/x86/celt_lpc_sse.cyclo ./Opus/celt/x86/celt_lpc_sse.d ./Opus/celt/x86/celt_lpc_sse.o ./Opus/celt/x86/celt_lpc_sse.su ./Opus/celt/x86/pitch_sse.cyclo ./Opus/celt/x86/pitch_sse.d ./Opus/celt/x86/pitch_sse.o ./Opus/celt/x86/pitch_sse.su ./Opus/celt/x86/pitch_sse2.cyclo ./Opus/celt/x86/pitch_sse2.d ./Opus/celt/x86/pitch_sse2.o ./Opus/celt/x86/pitch_sse2.su ./Opus/celt/x86/pitch_sse4_1.cyclo ./Opus/celt/x86/pitch_sse4_1.d ./Opus/celt/x86/pitch_sse4_1.o ./Opus/celt/x86/pitch_sse4_1.su ./Opus/celt/x86/vq_sse2.cyclo ./Opus/celt/x86/vq_sse2.d ./Opus/celt/x86/vq_sse2.o ./Opus/celt/x86/vq_sse2.su ./Opus/celt/x86/x86_celt_map.cyclo ./Opus/celt/x86/x86_celt_map.d ./Opus/celt/x86/x86_celt_map.o ./Opus/celt/x86/x86_celt_map.su ./Opus/celt/x86/x86cpu.cyclo ./Opus/celt/x86/x86cpu.d ./Opus/celt/x86/x86cpu.o ./Opus/celt/x86/x86cpu.su

.PHONY: clean-Opus-2f-celt-2f-x86

