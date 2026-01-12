################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/silk/fixed/LTP_analysis_filter_FIX.c \
../Opus/silk/fixed/LTP_scale_ctrl_FIX.c \
../Opus/silk/fixed/apply_sine_window_FIX.c \
../Opus/silk/fixed/autocorr_FIX.c \
../Opus/silk/fixed/burg_modified_FIX.c \
../Opus/silk/fixed/corrMatrix_FIX.c \
../Opus/silk/fixed/encode_frame_FIX.c \
../Opus/silk/fixed/find_LPC_FIX.c \
../Opus/silk/fixed/find_LTP_FIX.c \
../Opus/silk/fixed/find_pitch_lags_FIX.c \
../Opus/silk/fixed/find_pred_coefs_FIX.c \
../Opus/silk/fixed/k2a_FIX.c \
../Opus/silk/fixed/k2a_Q16_FIX.c \
../Opus/silk/fixed/noise_shape_analysis_FIX.c \
../Opus/silk/fixed/pitch_analysis_core_FIX.c \
../Opus/silk/fixed/process_gains_FIX.c \
../Opus/silk/fixed/regularize_correlations_FIX.c \
../Opus/silk/fixed/residual_energy16_FIX.c \
../Opus/silk/fixed/residual_energy_FIX.c \
../Opus/silk/fixed/schur64_FIX.c \
../Opus/silk/fixed/schur_FIX.c \
../Opus/silk/fixed/vector_ops_FIX.c \
../Opus/silk/fixed/warped_autocorrelation_FIX.c 

OBJS += \
./Opus/silk/fixed/LTP_analysis_filter_FIX.o \
./Opus/silk/fixed/LTP_scale_ctrl_FIX.o \
./Opus/silk/fixed/apply_sine_window_FIX.o \
./Opus/silk/fixed/autocorr_FIX.o \
./Opus/silk/fixed/burg_modified_FIX.o \
./Opus/silk/fixed/corrMatrix_FIX.o \
./Opus/silk/fixed/encode_frame_FIX.o \
./Opus/silk/fixed/find_LPC_FIX.o \
./Opus/silk/fixed/find_LTP_FIX.o \
./Opus/silk/fixed/find_pitch_lags_FIX.o \
./Opus/silk/fixed/find_pred_coefs_FIX.o \
./Opus/silk/fixed/k2a_FIX.o \
./Opus/silk/fixed/k2a_Q16_FIX.o \
./Opus/silk/fixed/noise_shape_analysis_FIX.o \
./Opus/silk/fixed/pitch_analysis_core_FIX.o \
./Opus/silk/fixed/process_gains_FIX.o \
./Opus/silk/fixed/regularize_correlations_FIX.o \
./Opus/silk/fixed/residual_energy16_FIX.o \
./Opus/silk/fixed/residual_energy_FIX.o \
./Opus/silk/fixed/schur64_FIX.o \
./Opus/silk/fixed/schur_FIX.o \
./Opus/silk/fixed/vector_ops_FIX.o \
./Opus/silk/fixed/warped_autocorrelation_FIX.o 

C_DEPS += \
./Opus/silk/fixed/LTP_analysis_filter_FIX.d \
./Opus/silk/fixed/LTP_scale_ctrl_FIX.d \
./Opus/silk/fixed/apply_sine_window_FIX.d \
./Opus/silk/fixed/autocorr_FIX.d \
./Opus/silk/fixed/burg_modified_FIX.d \
./Opus/silk/fixed/corrMatrix_FIX.d \
./Opus/silk/fixed/encode_frame_FIX.d \
./Opus/silk/fixed/find_LPC_FIX.d \
./Opus/silk/fixed/find_LTP_FIX.d \
./Opus/silk/fixed/find_pitch_lags_FIX.d \
./Opus/silk/fixed/find_pred_coefs_FIX.d \
./Opus/silk/fixed/k2a_FIX.d \
./Opus/silk/fixed/k2a_Q16_FIX.d \
./Opus/silk/fixed/noise_shape_analysis_FIX.d \
./Opus/silk/fixed/pitch_analysis_core_FIX.d \
./Opus/silk/fixed/process_gains_FIX.d \
./Opus/silk/fixed/regularize_correlations_FIX.d \
./Opus/silk/fixed/residual_energy16_FIX.d \
./Opus/silk/fixed/residual_energy_FIX.d \
./Opus/silk/fixed/schur64_FIX.d \
./Opus/silk/fixed/schur_FIX.d \
./Opus/silk/fixed/vector_ops_FIX.d \
./Opus/silk/fixed/warped_autocorrelation_FIX.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/silk/fixed/%.o Opus/silk/fixed/%.su Opus/silk/fixed/%.cyclo: ../Opus/silk/fixed/%.c Opus/silk/fixed/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-silk-2f-fixed

clean-Opus-2f-silk-2f-fixed:
	-$(RM) ./Opus/silk/fixed/LTP_analysis_filter_FIX.cyclo ./Opus/silk/fixed/LTP_analysis_filter_FIX.d ./Opus/silk/fixed/LTP_analysis_filter_FIX.o ./Opus/silk/fixed/LTP_analysis_filter_FIX.su ./Opus/silk/fixed/LTP_scale_ctrl_FIX.cyclo ./Opus/silk/fixed/LTP_scale_ctrl_FIX.d ./Opus/silk/fixed/LTP_scale_ctrl_FIX.o ./Opus/silk/fixed/LTP_scale_ctrl_FIX.su ./Opus/silk/fixed/apply_sine_window_FIX.cyclo ./Opus/silk/fixed/apply_sine_window_FIX.d ./Opus/silk/fixed/apply_sine_window_FIX.o ./Opus/silk/fixed/apply_sine_window_FIX.su ./Opus/silk/fixed/autocorr_FIX.cyclo ./Opus/silk/fixed/autocorr_FIX.d ./Opus/silk/fixed/autocorr_FIX.o ./Opus/silk/fixed/autocorr_FIX.su ./Opus/silk/fixed/burg_modified_FIX.cyclo ./Opus/silk/fixed/burg_modified_FIX.d ./Opus/silk/fixed/burg_modified_FIX.o ./Opus/silk/fixed/burg_modified_FIX.su ./Opus/silk/fixed/corrMatrix_FIX.cyclo ./Opus/silk/fixed/corrMatrix_FIX.d ./Opus/silk/fixed/corrMatrix_FIX.o ./Opus/silk/fixed/corrMatrix_FIX.su ./Opus/silk/fixed/encode_frame_FIX.cyclo ./Opus/silk/fixed/encode_frame_FIX.d ./Opus/silk/fixed/encode_frame_FIX.o ./Opus/silk/fixed/encode_frame_FIX.su ./Opus/silk/fixed/find_LPC_FIX.cyclo ./Opus/silk/fixed/find_LPC_FIX.d ./Opus/silk/fixed/find_LPC_FIX.o ./Opus/silk/fixed/find_LPC_FIX.su ./Opus/silk/fixed/find_LTP_FIX.cyclo ./Opus/silk/fixed/find_LTP_FIX.d ./Opus/silk/fixed/find_LTP_FIX.o ./Opus/silk/fixed/find_LTP_FIX.su ./Opus/silk/fixed/find_pitch_lags_FIX.cyclo ./Opus/silk/fixed/find_pitch_lags_FIX.d ./Opus/silk/fixed/find_pitch_lags_FIX.o ./Opus/silk/fixed/find_pitch_lags_FIX.su ./Opus/silk/fixed/find_pred_coefs_FIX.cyclo ./Opus/silk/fixed/find_pred_coefs_FIX.d ./Opus/silk/fixed/find_pred_coefs_FIX.o ./Opus/silk/fixed/find_pred_coefs_FIX.su ./Opus/silk/fixed/k2a_FIX.cyclo ./Opus/silk/fixed/k2a_FIX.d ./Opus/silk/fixed/k2a_FIX.o ./Opus/silk/fixed/k2a_FIX.su ./Opus/silk/fixed/k2a_Q16_FIX.cyclo ./Opus/silk/fixed/k2a_Q16_FIX.d ./Opus/silk/fixed/k2a_Q16_FIX.o ./Opus/silk/fixed/k2a_Q16_FIX.su ./Opus/silk/fixed/noise_shape_analysis_FIX.cyclo ./Opus/silk/fixed/noise_shape_analysis_FIX.d ./Opus/silk/fixed/noise_shape_analysis_FIX.o ./Opus/silk/fixed/noise_shape_analysis_FIX.su ./Opus/silk/fixed/pitch_analysis_core_FIX.cyclo ./Opus/silk/fixed/pitch_analysis_core_FIX.d ./Opus/silk/fixed/pitch_analysis_core_FIX.o ./Opus/silk/fixed/pitch_analysis_core_FIX.su ./Opus/silk/fixed/process_gains_FIX.cyclo ./Opus/silk/fixed/process_gains_FIX.d ./Opus/silk/fixed/process_gains_FIX.o ./Opus/silk/fixed/process_gains_FIX.su ./Opus/silk/fixed/regularize_correlations_FIX.cyclo ./Opus/silk/fixed/regularize_correlations_FIX.d ./Opus/silk/fixed/regularize_correlations_FIX.o ./Opus/silk/fixed/regularize_correlations_FIX.su ./Opus/silk/fixed/residual_energy16_FIX.cyclo ./Opus/silk/fixed/residual_energy16_FIX.d ./Opus/silk/fixed/residual_energy16_FIX.o ./Opus/silk/fixed/residual_energy16_FIX.su ./Opus/silk/fixed/residual_energy_FIX.cyclo ./Opus/silk/fixed/residual_energy_FIX.d ./Opus/silk/fixed/residual_energy_FIX.o ./Opus/silk/fixed/residual_energy_FIX.su ./Opus/silk/fixed/schur64_FIX.cyclo ./Opus/silk/fixed/schur64_FIX.d ./Opus/silk/fixed/schur64_FIX.o ./Opus/silk/fixed/schur64_FIX.su ./Opus/silk/fixed/schur_FIX.cyclo ./Opus/silk/fixed/schur_FIX.d ./Opus/silk/fixed/schur_FIX.o ./Opus/silk/fixed/schur_FIX.su ./Opus/silk/fixed/vector_ops_FIX.cyclo ./Opus/silk/fixed/vector_ops_FIX.d ./Opus/silk/fixed/vector_ops_FIX.o ./Opus/silk/fixed/vector_ops_FIX.su ./Opus/silk/fixed/warped_autocorrelation_FIX.cyclo ./Opus/silk/fixed/warped_autocorrelation_FIX.d ./Opus/silk/fixed/warped_autocorrelation_FIX.o ./Opus/silk/fixed/warped_autocorrelation_FIX.su

.PHONY: clean-Opus-2f-silk-2f-fixed

