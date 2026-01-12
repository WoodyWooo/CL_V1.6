################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/celt/tests/test_unit_cwrs32.c \
../Opus/celt/tests/test_unit_dft.c \
../Opus/celt/tests/test_unit_entropy.c \
../Opus/celt/tests/test_unit_laplace.c \
../Opus/celt/tests/test_unit_mathops.c \
../Opus/celt/tests/test_unit_mdct.c \
../Opus/celt/tests/test_unit_rotation.c \
../Opus/celt/tests/test_unit_types.c 

OBJS += \
./Opus/celt/tests/test_unit_cwrs32.o \
./Opus/celt/tests/test_unit_dft.o \
./Opus/celt/tests/test_unit_entropy.o \
./Opus/celt/tests/test_unit_laplace.o \
./Opus/celt/tests/test_unit_mathops.o \
./Opus/celt/tests/test_unit_mdct.o \
./Opus/celt/tests/test_unit_rotation.o \
./Opus/celt/tests/test_unit_types.o 

C_DEPS += \
./Opus/celt/tests/test_unit_cwrs32.d \
./Opus/celt/tests/test_unit_dft.d \
./Opus/celt/tests/test_unit_entropy.d \
./Opus/celt/tests/test_unit_laplace.d \
./Opus/celt/tests/test_unit_mathops.d \
./Opus/celt/tests/test_unit_mdct.d \
./Opus/celt/tests/test_unit_rotation.d \
./Opus/celt/tests/test_unit_types.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/celt/tests/%.o Opus/celt/tests/%.su Opus/celt/tests/%.cyclo: ../Opus/celt/tests/%.c Opus/celt/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-celt-2f-tests

clean-Opus-2f-celt-2f-tests:
	-$(RM) ./Opus/celt/tests/test_unit_cwrs32.cyclo ./Opus/celt/tests/test_unit_cwrs32.d ./Opus/celt/tests/test_unit_cwrs32.o ./Opus/celt/tests/test_unit_cwrs32.su ./Opus/celt/tests/test_unit_dft.cyclo ./Opus/celt/tests/test_unit_dft.d ./Opus/celt/tests/test_unit_dft.o ./Opus/celt/tests/test_unit_dft.su ./Opus/celt/tests/test_unit_entropy.cyclo ./Opus/celt/tests/test_unit_entropy.d ./Opus/celt/tests/test_unit_entropy.o ./Opus/celt/tests/test_unit_entropy.su ./Opus/celt/tests/test_unit_laplace.cyclo ./Opus/celt/tests/test_unit_laplace.d ./Opus/celt/tests/test_unit_laplace.o ./Opus/celt/tests/test_unit_laplace.su ./Opus/celt/tests/test_unit_mathops.cyclo ./Opus/celt/tests/test_unit_mathops.d ./Opus/celt/tests/test_unit_mathops.o ./Opus/celt/tests/test_unit_mathops.su ./Opus/celt/tests/test_unit_mdct.cyclo ./Opus/celt/tests/test_unit_mdct.d ./Opus/celt/tests/test_unit_mdct.o ./Opus/celt/tests/test_unit_mdct.su ./Opus/celt/tests/test_unit_rotation.cyclo ./Opus/celt/tests/test_unit_rotation.d ./Opus/celt/tests/test_unit_rotation.o ./Opus/celt/tests/test_unit_rotation.su ./Opus/celt/tests/test_unit_types.cyclo ./Opus/celt/tests/test_unit_types.d ./Opus/celt/tests/test_unit_types.o ./Opus/celt/tests/test_unit_types.su

.PHONY: clean-Opus-2f-celt-2f-tests

