################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ExtraDrivers/src/gp_timer.c \
../ExtraDrivers/src/stm32f4xx_hal_i2c.c \
../ExtraDrivers/src/stm32f4xx_hal_i2c_ex.c \
../ExtraDrivers/src/stm32f4xx_hal_i2s.c \
../ExtraDrivers/src/stm32f4xx_hal_i2s_ex.c \
../ExtraDrivers/src/stm32f4xx_hal_sai.c \
../ExtraDrivers/src/stm32f4xx_hal_sai_ex.c \
../ExtraDrivers/src/stm32f4xx_hal_spi.c 

OBJS += \
./ExtraDrivers/src/gp_timer.o \
./ExtraDrivers/src/stm32f4xx_hal_i2c.o \
./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.o \
./ExtraDrivers/src/stm32f4xx_hal_i2s.o \
./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.o \
./ExtraDrivers/src/stm32f4xx_hal_sai.o \
./ExtraDrivers/src/stm32f4xx_hal_sai_ex.o \
./ExtraDrivers/src/stm32f4xx_hal_spi.o 

C_DEPS += \
./ExtraDrivers/src/gp_timer.d \
./ExtraDrivers/src/stm32f4xx_hal_i2c.d \
./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.d \
./ExtraDrivers/src/stm32f4xx_hal_i2s.d \
./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.d \
./ExtraDrivers/src/stm32f4xx_hal_sai.d \
./ExtraDrivers/src/stm32f4xx_hal_sai_ex.d \
./ExtraDrivers/src/stm32f4xx_hal_spi.d 


# Each subdirectory must supply rules for building sources it contributes
ExtraDrivers/src/%.o ExtraDrivers/src/%.su ExtraDrivers/src/%.cyclo: ../ExtraDrivers/src/%.c ExtraDrivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ExtraDrivers-2f-src

clean-ExtraDrivers-2f-src:
	-$(RM) ./ExtraDrivers/src/gp_timer.cyclo ./ExtraDrivers/src/gp_timer.d ./ExtraDrivers/src/gp_timer.o ./ExtraDrivers/src/gp_timer.su ./ExtraDrivers/src/stm32f4xx_hal_i2c.cyclo ./ExtraDrivers/src/stm32f4xx_hal_i2c.d ./ExtraDrivers/src/stm32f4xx_hal_i2c.o ./ExtraDrivers/src/stm32f4xx_hal_i2c.su ./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.cyclo ./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.d ./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.o ./ExtraDrivers/src/stm32f4xx_hal_i2c_ex.su ./ExtraDrivers/src/stm32f4xx_hal_i2s.cyclo ./ExtraDrivers/src/stm32f4xx_hal_i2s.d ./ExtraDrivers/src/stm32f4xx_hal_i2s.o ./ExtraDrivers/src/stm32f4xx_hal_i2s.su ./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.cyclo ./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.d ./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.o ./ExtraDrivers/src/stm32f4xx_hal_i2s_ex.su ./ExtraDrivers/src/stm32f4xx_hal_sai.cyclo ./ExtraDrivers/src/stm32f4xx_hal_sai.d ./ExtraDrivers/src/stm32f4xx_hal_sai.o ./ExtraDrivers/src/stm32f4xx_hal_sai.su ./ExtraDrivers/src/stm32f4xx_hal_sai_ex.cyclo ./ExtraDrivers/src/stm32f4xx_hal_sai_ex.d ./ExtraDrivers/src/stm32f4xx_hal_sai_ex.o ./ExtraDrivers/src/stm32f4xx_hal_sai_ex.su ./ExtraDrivers/src/stm32f4xx_hal_spi.cyclo ./ExtraDrivers/src/stm32f4xx_hal_spi.d ./ExtraDrivers/src/stm32f4xx_hal_spi.o ./ExtraDrivers/src/stm32f4xx_hal_spi.su

.PHONY: clean-ExtraDrivers-2f-src

