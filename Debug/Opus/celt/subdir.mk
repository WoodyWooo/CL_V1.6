################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/celt/bands.c \
../Opus/celt/celt.c \
../Opus/celt/celt_decoder.c \
../Opus/celt/celt_encoder.c \
../Opus/celt/celt_lpc.c \
../Opus/celt/cwrs.c \
../Opus/celt/entcode.c \
../Opus/celt/entdec.c \
../Opus/celt/entenc.c \
../Opus/celt/kiss_fft.c \
../Opus/celt/laplace.c \
../Opus/celt/mathops.c \
../Opus/celt/mdct.c \
../Opus/celt/modes.c \
../Opus/celt/pitch.c \
../Opus/celt/quant_bands.c \
../Opus/celt/rate.c \
../Opus/celt/vq.c 

OBJS += \
./Opus/celt/bands.o \
./Opus/celt/celt.o \
./Opus/celt/celt_decoder.o \
./Opus/celt/celt_encoder.o \
./Opus/celt/celt_lpc.o \
./Opus/celt/cwrs.o \
./Opus/celt/entcode.o \
./Opus/celt/entdec.o \
./Opus/celt/entenc.o \
./Opus/celt/kiss_fft.o \
./Opus/celt/laplace.o \
./Opus/celt/mathops.o \
./Opus/celt/mdct.o \
./Opus/celt/modes.o \
./Opus/celt/pitch.o \
./Opus/celt/quant_bands.o \
./Opus/celt/rate.o \
./Opus/celt/vq.o 

C_DEPS += \
./Opus/celt/bands.d \
./Opus/celt/celt.d \
./Opus/celt/celt_decoder.d \
./Opus/celt/celt_encoder.d \
./Opus/celt/celt_lpc.d \
./Opus/celt/cwrs.d \
./Opus/celt/entcode.d \
./Opus/celt/entdec.d \
./Opus/celt/entenc.d \
./Opus/celt/kiss_fft.d \
./Opus/celt/laplace.d \
./Opus/celt/mathops.d \
./Opus/celt/mdct.d \
./Opus/celt/modes.d \
./Opus/celt/pitch.d \
./Opus/celt/quant_bands.d \
./Opus/celt/rate.d \
./Opus/celt/vq.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/celt/%.o Opus/celt/%.su Opus/celt/%.cyclo: ../Opus/celt/%.c Opus/celt/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-celt

clean-Opus-2f-celt:
	-$(RM) ./Opus/celt/bands.cyclo ./Opus/celt/bands.d ./Opus/celt/bands.o ./Opus/celt/bands.su ./Opus/celt/celt.cyclo ./Opus/celt/celt.d ./Opus/celt/celt.o ./Opus/celt/celt.su ./Opus/celt/celt_decoder.cyclo ./Opus/celt/celt_decoder.d ./Opus/celt/celt_decoder.o ./Opus/celt/celt_decoder.su ./Opus/celt/celt_encoder.cyclo ./Opus/celt/celt_encoder.d ./Opus/celt/celt_encoder.o ./Opus/celt/celt_encoder.su ./Opus/celt/celt_lpc.cyclo ./Opus/celt/celt_lpc.d ./Opus/celt/celt_lpc.o ./Opus/celt/celt_lpc.su ./Opus/celt/cwrs.cyclo ./Opus/celt/cwrs.d ./Opus/celt/cwrs.o ./Opus/celt/cwrs.su ./Opus/celt/entcode.cyclo ./Opus/celt/entcode.d ./Opus/celt/entcode.o ./Opus/celt/entcode.su ./Opus/celt/entdec.cyclo ./Opus/celt/entdec.d ./Opus/celt/entdec.o ./Opus/celt/entdec.su ./Opus/celt/entenc.cyclo ./Opus/celt/entenc.d ./Opus/celt/entenc.o ./Opus/celt/entenc.su ./Opus/celt/kiss_fft.cyclo ./Opus/celt/kiss_fft.d ./Opus/celt/kiss_fft.o ./Opus/celt/kiss_fft.su ./Opus/celt/laplace.cyclo ./Opus/celt/laplace.d ./Opus/celt/laplace.o ./Opus/celt/laplace.su ./Opus/celt/mathops.cyclo ./Opus/celt/mathops.d ./Opus/celt/mathops.o ./Opus/celt/mathops.su ./Opus/celt/mdct.cyclo ./Opus/celt/mdct.d ./Opus/celt/mdct.o ./Opus/celt/mdct.su ./Opus/celt/modes.cyclo ./Opus/celt/modes.d ./Opus/celt/modes.o ./Opus/celt/modes.su ./Opus/celt/pitch.cyclo ./Opus/celt/pitch.d ./Opus/celt/pitch.o ./Opus/celt/pitch.su ./Opus/celt/quant_bands.cyclo ./Opus/celt/quant_bands.d ./Opus/celt/quant_bands.o ./Opus/celt/quant_bands.su ./Opus/celt/rate.cyclo ./Opus/celt/rate.d ./Opus/celt/rate.o ./Opus/celt/rate.su ./Opus/celt/vq.cyclo ./Opus/celt/vq.d ./Opus/celt/vq.o ./Opus/celt/vq.su

.PHONY: clean-Opus-2f-celt

