################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/silk/float/LPC_analysis_filter_FLP.c \
../Opus/silk/float/LPC_inv_pred_gain_FLP.c \
../Opus/silk/float/LTP_analysis_filter_FLP.c \
../Opus/silk/float/LTP_scale_ctrl_FLP.c \
../Opus/silk/float/apply_sine_window_FLP.c \
../Opus/silk/float/autocorrelation_FLP.c \
../Opus/silk/float/burg_modified_FLP.c \
../Opus/silk/float/bwexpander_FLP.c \
../Opus/silk/float/corrMatrix_FLP.c \
../Opus/silk/float/encode_frame_FLP.c \
../Opus/silk/float/energy_FLP.c \
../Opus/silk/float/find_LPC_FLP.c \
../Opus/silk/float/find_LTP_FLP.c \
../Opus/silk/float/find_pitch_lags_FLP.c \
../Opus/silk/float/find_pred_coefs_FLP.c \
../Opus/silk/float/inner_product_FLP.c \
../Opus/silk/float/k2a_FLP.c \
../Opus/silk/float/noise_shape_analysis_FLP.c \
../Opus/silk/float/pitch_analysis_core_FLP.c \
../Opus/silk/float/process_gains_FLP.c \
../Opus/silk/float/regularize_correlations_FLP.c \
../Opus/silk/float/residual_energy_FLP.c \
../Opus/silk/float/scale_copy_vector_FLP.c \
../Opus/silk/float/scale_vector_FLP.c \
../Opus/silk/float/schur_FLP.c \
../Opus/silk/float/sort_FLP.c \
../Opus/silk/float/warped_autocorrelation_FLP.c \
../Opus/silk/float/wrappers_FLP.c 

OBJS += \
./Opus/silk/float/LPC_analysis_filter_FLP.o \
./Opus/silk/float/LPC_inv_pred_gain_FLP.o \
./Opus/silk/float/LTP_analysis_filter_FLP.o \
./Opus/silk/float/LTP_scale_ctrl_FLP.o \
./Opus/silk/float/apply_sine_window_FLP.o \
./Opus/silk/float/autocorrelation_FLP.o \
./Opus/silk/float/burg_modified_FLP.o \
./Opus/silk/float/bwexpander_FLP.o \
./Opus/silk/float/corrMatrix_FLP.o \
./Opus/silk/float/encode_frame_FLP.o \
./Opus/silk/float/energy_FLP.o \
./Opus/silk/float/find_LPC_FLP.o \
./Opus/silk/float/find_LTP_FLP.o \
./Opus/silk/float/find_pitch_lags_FLP.o \
./Opus/silk/float/find_pred_coefs_FLP.o \
./Opus/silk/float/inner_product_FLP.o \
./Opus/silk/float/k2a_FLP.o \
./Opus/silk/float/noise_shape_analysis_FLP.o \
./Opus/silk/float/pitch_analysis_core_FLP.o \
./Opus/silk/float/process_gains_FLP.o \
./Opus/silk/float/regularize_correlations_FLP.o \
./Opus/silk/float/residual_energy_FLP.o \
./Opus/silk/float/scale_copy_vector_FLP.o \
./Opus/silk/float/scale_vector_FLP.o \
./Opus/silk/float/schur_FLP.o \
./Opus/silk/float/sort_FLP.o \
./Opus/silk/float/warped_autocorrelation_FLP.o \
./Opus/silk/float/wrappers_FLP.o 

C_DEPS += \
./Opus/silk/float/LPC_analysis_filter_FLP.d \
./Opus/silk/float/LPC_inv_pred_gain_FLP.d \
./Opus/silk/float/LTP_analysis_filter_FLP.d \
./Opus/silk/float/LTP_scale_ctrl_FLP.d \
./Opus/silk/float/apply_sine_window_FLP.d \
./Opus/silk/float/autocorrelation_FLP.d \
./Opus/silk/float/burg_modified_FLP.d \
./Opus/silk/float/bwexpander_FLP.d \
./Opus/silk/float/corrMatrix_FLP.d \
./Opus/silk/float/encode_frame_FLP.d \
./Opus/silk/float/energy_FLP.d \
./Opus/silk/float/find_LPC_FLP.d \
./Opus/silk/float/find_LTP_FLP.d \
./Opus/silk/float/find_pitch_lags_FLP.d \
./Opus/silk/float/find_pred_coefs_FLP.d \
./Opus/silk/float/inner_product_FLP.d \
./Opus/silk/float/k2a_FLP.d \
./Opus/silk/float/noise_shape_analysis_FLP.d \
./Opus/silk/float/pitch_analysis_core_FLP.d \
./Opus/silk/float/process_gains_FLP.d \
./Opus/silk/float/regularize_correlations_FLP.d \
./Opus/silk/float/residual_energy_FLP.d \
./Opus/silk/float/scale_copy_vector_FLP.d \
./Opus/silk/float/scale_vector_FLP.d \
./Opus/silk/float/schur_FLP.d \
./Opus/silk/float/sort_FLP.d \
./Opus/silk/float/warped_autocorrelation_FLP.d \
./Opus/silk/float/wrappers_FLP.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/silk/float/%.o Opus/silk/float/%.su Opus/silk/float/%.cyclo: ../Opus/silk/float/%.c Opus/silk/float/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-silk-2f-float

clean-Opus-2f-silk-2f-float:
	-$(RM) ./Opus/silk/float/LPC_analysis_filter_FLP.cyclo ./Opus/silk/float/LPC_analysis_filter_FLP.d ./Opus/silk/float/LPC_analysis_filter_FLP.o ./Opus/silk/float/LPC_analysis_filter_FLP.su ./Opus/silk/float/LPC_inv_pred_gain_FLP.cyclo ./Opus/silk/float/LPC_inv_pred_gain_FLP.d ./Opus/silk/float/LPC_inv_pred_gain_FLP.o ./Opus/silk/float/LPC_inv_pred_gain_FLP.su ./Opus/silk/float/LTP_analysis_filter_FLP.cyclo ./Opus/silk/float/LTP_analysis_filter_FLP.d ./Opus/silk/float/LTP_analysis_filter_FLP.o ./Opus/silk/float/LTP_analysis_filter_FLP.su ./Opus/silk/float/LTP_scale_ctrl_FLP.cyclo ./Opus/silk/float/LTP_scale_ctrl_FLP.d ./Opus/silk/float/LTP_scale_ctrl_FLP.o ./Opus/silk/float/LTP_scale_ctrl_FLP.su ./Opus/silk/float/apply_sine_window_FLP.cyclo ./Opus/silk/float/apply_sine_window_FLP.d ./Opus/silk/float/apply_sine_window_FLP.o ./Opus/silk/float/apply_sine_window_FLP.su ./Opus/silk/float/autocorrelation_FLP.cyclo ./Opus/silk/float/autocorrelation_FLP.d ./Opus/silk/float/autocorrelation_FLP.o ./Opus/silk/float/autocorrelation_FLP.su ./Opus/silk/float/burg_modified_FLP.cyclo ./Opus/silk/float/burg_modified_FLP.d ./Opus/silk/float/burg_modified_FLP.o ./Opus/silk/float/burg_modified_FLP.su ./Opus/silk/float/bwexpander_FLP.cyclo ./Opus/silk/float/bwexpander_FLP.d ./Opus/silk/float/bwexpander_FLP.o ./Opus/silk/float/bwexpander_FLP.su ./Opus/silk/float/corrMatrix_FLP.cyclo ./Opus/silk/float/corrMatrix_FLP.d ./Opus/silk/float/corrMatrix_FLP.o ./Opus/silk/float/corrMatrix_FLP.su ./Opus/silk/float/encode_frame_FLP.cyclo ./Opus/silk/float/encode_frame_FLP.d ./Opus/silk/float/encode_frame_FLP.o ./Opus/silk/float/encode_frame_FLP.su ./Opus/silk/float/energy_FLP.cyclo ./Opus/silk/float/energy_FLP.d ./Opus/silk/float/energy_FLP.o ./Opus/silk/float/energy_FLP.su ./Opus/silk/float/find_LPC_FLP.cyclo ./Opus/silk/float/find_LPC_FLP.d ./Opus/silk/float/find_LPC_FLP.o ./Opus/silk/float/find_LPC_FLP.su ./Opus/silk/float/find_LTP_FLP.cyclo ./Opus/silk/float/find_LTP_FLP.d ./Opus/silk/float/find_LTP_FLP.o ./Opus/silk/float/find_LTP_FLP.su ./Opus/silk/float/find_pitch_lags_FLP.cyclo ./Opus/silk/float/find_pitch_lags_FLP.d ./Opus/silk/float/find_pitch_lags_FLP.o ./Opus/silk/float/find_pitch_lags_FLP.su ./Opus/silk/float/find_pred_coefs_FLP.cyclo ./Opus/silk/float/find_pred_coefs_FLP.d ./Opus/silk/float/find_pred_coefs_FLP.o ./Opus/silk/float/find_pred_coefs_FLP.su ./Opus/silk/float/inner_product_FLP.cyclo ./Opus/silk/float/inner_product_FLP.d ./Opus/silk/float/inner_product_FLP.o ./Opus/silk/float/inner_product_FLP.su ./Opus/silk/float/k2a_FLP.cyclo ./Opus/silk/float/k2a_FLP.d ./Opus/silk/float/k2a_FLP.o ./Opus/silk/float/k2a_FLP.su ./Opus/silk/float/noise_shape_analysis_FLP.cyclo ./Opus/silk/float/noise_shape_analysis_FLP.d ./Opus/silk/float/noise_shape_analysis_FLP.o ./Opus/silk/float/noise_shape_analysis_FLP.su ./Opus/silk/float/pitch_analysis_core_FLP.cyclo ./Opus/silk/float/pitch_analysis_core_FLP.d ./Opus/silk/float/pitch_analysis_core_FLP.o ./Opus/silk/float/pitch_analysis_core_FLP.su ./Opus/silk/float/process_gains_FLP.cyclo ./Opus/silk/float/process_gains_FLP.d ./Opus/silk/float/process_gains_FLP.o ./Opus/silk/float/process_gains_FLP.su ./Opus/silk/float/regularize_correlations_FLP.cyclo ./Opus/silk/float/regularize_correlations_FLP.d ./Opus/silk/float/regularize_correlations_FLP.o ./Opus/silk/float/regularize_correlations_FLP.su ./Opus/silk/float/residual_energy_FLP.cyclo ./Opus/silk/float/residual_energy_FLP.d ./Opus/silk/float/residual_energy_FLP.o ./Opus/silk/float/residual_energy_FLP.su ./Opus/silk/float/scale_copy_vector_FLP.cyclo ./Opus/silk/float/scale_copy_vector_FLP.d ./Opus/silk/float/scale_copy_vector_FLP.o ./Opus/silk/float/scale_copy_vector_FLP.su ./Opus/silk/float/scale_vector_FLP.cyclo ./Opus/silk/float/scale_vector_FLP.d ./Opus/silk/float/scale_vector_FLP.o ./Opus/silk/float/scale_vector_FLP.su ./Opus/silk/float/schur_FLP.cyclo ./Opus/silk/float/schur_FLP.d ./Opus/silk/float/schur_FLP.o ./Opus/silk/float/schur_FLP.su ./Opus/silk/float/sort_FLP.cyclo ./Opus/silk/float/sort_FLP.d ./Opus/silk/float/sort_FLP.o ./Opus/silk/float/sort_FLP.su ./Opus/silk/float/warped_autocorrelation_FLP.cyclo ./Opus/silk/float/warped_autocorrelation_FLP.d ./Opus/silk/float/warped_autocorrelation_FLP.o ./Opus/silk/float/warped_autocorrelation_FLP.su ./Opus/silk/float/wrappers_FLP.cyclo ./Opus/silk/float/wrappers_FLP.d ./Opus/silk/float/wrappers_FLP.o ./Opus/silk/float/wrappers_FLP.su

.PHONY: clean-Opus-2f-silk-2f-float

