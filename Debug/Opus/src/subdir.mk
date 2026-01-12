################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/src/analysis.c \
../Opus/src/mlp.c \
../Opus/src/mlp_data.c \
../Opus/src/opus.c \
../Opus/src/opus_decoder.c \
../Opus/src/opus_encoder.c \
../Opus/src/opus_multistream.c \
../Opus/src/opus_multistream_decoder.c \
../Opus/src/opus_multistream_encoder.c \
../Opus/src/repacketizer.c 

OBJS += \
./Opus/src/analysis.o \
./Opus/src/mlp.o \
./Opus/src/mlp_data.o \
./Opus/src/opus.o \
./Opus/src/opus_decoder.o \
./Opus/src/opus_encoder.o \
./Opus/src/opus_multistream.o \
./Opus/src/opus_multistream_decoder.o \
./Opus/src/opus_multistream_encoder.o \
./Opus/src/repacketizer.o 

C_DEPS += \
./Opus/src/analysis.d \
./Opus/src/mlp.d \
./Opus/src/mlp_data.d \
./Opus/src/opus.d \
./Opus/src/opus_decoder.d \
./Opus/src/opus_encoder.d \
./Opus/src/opus_multistream.d \
./Opus/src/opus_multistream_decoder.d \
./Opus/src/opus_multistream_encoder.d \
./Opus/src/repacketizer.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/src/%.o Opus/src/%.su Opus/src/%.cyclo: ../Opus/src/%.c Opus/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-src

clean-Opus-2f-src:
	-$(RM) ./Opus/src/analysis.cyclo ./Opus/src/analysis.d ./Opus/src/analysis.o ./Opus/src/analysis.su ./Opus/src/mlp.cyclo ./Opus/src/mlp.d ./Opus/src/mlp.o ./Opus/src/mlp.su ./Opus/src/mlp_data.cyclo ./Opus/src/mlp_data.d ./Opus/src/mlp_data.o ./Opus/src/mlp_data.su ./Opus/src/opus.cyclo ./Opus/src/opus.d ./Opus/src/opus.o ./Opus/src/opus.su ./Opus/src/opus_decoder.cyclo ./Opus/src/opus_decoder.d ./Opus/src/opus_decoder.o ./Opus/src/opus_decoder.su ./Opus/src/opus_encoder.cyclo ./Opus/src/opus_encoder.d ./Opus/src/opus_encoder.o ./Opus/src/opus_encoder.su ./Opus/src/opus_multistream.cyclo ./Opus/src/opus_multistream.d ./Opus/src/opus_multistream.o ./Opus/src/opus_multistream.su ./Opus/src/opus_multistream_decoder.cyclo ./Opus/src/opus_multistream_decoder.d ./Opus/src/opus_multistream_decoder.o ./Opus/src/opus_multistream_decoder.su ./Opus/src/opus_multistream_encoder.cyclo ./Opus/src/opus_multistream_encoder.d ./Opus/src/opus_multistream_encoder.o ./Opus/src/opus_multistream_encoder.su ./Opus/src/repacketizer.cyclo ./Opus/src/repacketizer.d ./Opus/src/repacketizer.o ./Opus/src/repacketizer.su

.PHONY: clean-Opus-2f-src

