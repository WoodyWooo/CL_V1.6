################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Opus/silk/A2NLSF.c \
../Opus/silk/CNG.c \
../Opus/silk/HP_variable_cutoff.c \
../Opus/silk/LPC_analysis_filter.c \
../Opus/silk/LPC_fit.c \
../Opus/silk/LPC_inv_pred_gain.c \
../Opus/silk/LP_variable_cutoff.c \
../Opus/silk/NLSF2A.c \
../Opus/silk/NLSF_VQ.c \
../Opus/silk/NLSF_VQ_weights_laroia.c \
../Opus/silk/NLSF_decode.c \
../Opus/silk/NLSF_del_dec_quant.c \
../Opus/silk/NLSF_encode.c \
../Opus/silk/NLSF_stabilize.c \
../Opus/silk/NLSF_unpack.c \
../Opus/silk/NSQ.c \
../Opus/silk/NSQ_del_dec.c \
../Opus/silk/PLC.c \
../Opus/silk/VAD.c \
../Opus/silk/VQ_WMat_EC.c \
../Opus/silk/ana_filt_bank_1.c \
../Opus/silk/biquad_alt.c \
../Opus/silk/bwexpander.c \
../Opus/silk/bwexpander_32.c \
../Opus/silk/check_control_input.c \
../Opus/silk/code_signs.c \
../Opus/silk/control_SNR.c \
../Opus/silk/control_audio_bandwidth.c \
../Opus/silk/control_codec.c \
../Opus/silk/debug.c \
../Opus/silk/dec_API.c \
../Opus/silk/decode_core.c \
../Opus/silk/decode_frame.c \
../Opus/silk/decode_indices.c \
../Opus/silk/decode_parameters.c \
../Opus/silk/decode_pitch.c \
../Opus/silk/decode_pulses.c \
../Opus/silk/decoder_set_fs.c \
../Opus/silk/enc_API.c \
../Opus/silk/encode_indices.c \
../Opus/silk/encode_pulses.c \
../Opus/silk/gain_quant.c \
../Opus/silk/init_decoder.c \
../Opus/silk/init_encoder.c \
../Opus/silk/inner_prod_aligned.c \
../Opus/silk/interpolate.c \
../Opus/silk/lin2log.c \
../Opus/silk/log2lin.c \
../Opus/silk/pitch_est_tables.c \
../Opus/silk/process_NLSFs.c \
../Opus/silk/quant_LTP_gains.c \
../Opus/silk/resampler.c \
../Opus/silk/resampler_down2.c \
../Opus/silk/resampler_down2_3.c \
../Opus/silk/resampler_private_AR2.c \
../Opus/silk/resampler_private_IIR_FIR.c \
../Opus/silk/resampler_private_down_FIR.c \
../Opus/silk/resampler_private_up2_HQ.c \
../Opus/silk/resampler_rom.c \
../Opus/silk/shell_coder.c \
../Opus/silk/sigm_Q15.c \
../Opus/silk/sort.c \
../Opus/silk/stereo_LR_to_MS.c \
../Opus/silk/stereo_MS_to_LR.c \
../Opus/silk/stereo_decode_pred.c \
../Opus/silk/stereo_encode_pred.c \
../Opus/silk/stereo_find_predictor.c \
../Opus/silk/stereo_quant_pred.c \
../Opus/silk/sum_sqr_shift.c \
../Opus/silk/table_LSF_cos.c \
../Opus/silk/tables_LTP.c \
../Opus/silk/tables_NLSF_CB_NB_MB.c \
../Opus/silk/tables_NLSF_CB_WB.c \
../Opus/silk/tables_gain.c \
../Opus/silk/tables_other.c \
../Opus/silk/tables_pitch_lag.c \
../Opus/silk/tables_pulses_per_block.c 

OBJS += \
./Opus/silk/A2NLSF.o \
./Opus/silk/CNG.o \
./Opus/silk/HP_variable_cutoff.o \
./Opus/silk/LPC_analysis_filter.o \
./Opus/silk/LPC_fit.o \
./Opus/silk/LPC_inv_pred_gain.o \
./Opus/silk/LP_variable_cutoff.o \
./Opus/silk/NLSF2A.o \
./Opus/silk/NLSF_VQ.o \
./Opus/silk/NLSF_VQ_weights_laroia.o \
./Opus/silk/NLSF_decode.o \
./Opus/silk/NLSF_del_dec_quant.o \
./Opus/silk/NLSF_encode.o \
./Opus/silk/NLSF_stabilize.o \
./Opus/silk/NLSF_unpack.o \
./Opus/silk/NSQ.o \
./Opus/silk/NSQ_del_dec.o \
./Opus/silk/PLC.o \
./Opus/silk/VAD.o \
./Opus/silk/VQ_WMat_EC.o \
./Opus/silk/ana_filt_bank_1.o \
./Opus/silk/biquad_alt.o \
./Opus/silk/bwexpander.o \
./Opus/silk/bwexpander_32.o \
./Opus/silk/check_control_input.o \
./Opus/silk/code_signs.o \
./Opus/silk/control_SNR.o \
./Opus/silk/control_audio_bandwidth.o \
./Opus/silk/control_codec.o \
./Opus/silk/debug.o \
./Opus/silk/dec_API.o \
./Opus/silk/decode_core.o \
./Opus/silk/decode_frame.o \
./Opus/silk/decode_indices.o \
./Opus/silk/decode_parameters.o \
./Opus/silk/decode_pitch.o \
./Opus/silk/decode_pulses.o \
./Opus/silk/decoder_set_fs.o \
./Opus/silk/enc_API.o \
./Opus/silk/encode_indices.o \
./Opus/silk/encode_pulses.o \
./Opus/silk/gain_quant.o \
./Opus/silk/init_decoder.o \
./Opus/silk/init_encoder.o \
./Opus/silk/inner_prod_aligned.o \
./Opus/silk/interpolate.o \
./Opus/silk/lin2log.o \
./Opus/silk/log2lin.o \
./Opus/silk/pitch_est_tables.o \
./Opus/silk/process_NLSFs.o \
./Opus/silk/quant_LTP_gains.o \
./Opus/silk/resampler.o \
./Opus/silk/resampler_down2.o \
./Opus/silk/resampler_down2_3.o \
./Opus/silk/resampler_private_AR2.o \
./Opus/silk/resampler_private_IIR_FIR.o \
./Opus/silk/resampler_private_down_FIR.o \
./Opus/silk/resampler_private_up2_HQ.o \
./Opus/silk/resampler_rom.o \
./Opus/silk/shell_coder.o \
./Opus/silk/sigm_Q15.o \
./Opus/silk/sort.o \
./Opus/silk/stereo_LR_to_MS.o \
./Opus/silk/stereo_MS_to_LR.o \
./Opus/silk/stereo_decode_pred.o \
./Opus/silk/stereo_encode_pred.o \
./Opus/silk/stereo_find_predictor.o \
./Opus/silk/stereo_quant_pred.o \
./Opus/silk/sum_sqr_shift.o \
./Opus/silk/table_LSF_cos.o \
./Opus/silk/tables_LTP.o \
./Opus/silk/tables_NLSF_CB_NB_MB.o \
./Opus/silk/tables_NLSF_CB_WB.o \
./Opus/silk/tables_gain.o \
./Opus/silk/tables_other.o \
./Opus/silk/tables_pitch_lag.o \
./Opus/silk/tables_pulses_per_block.o 

C_DEPS += \
./Opus/silk/A2NLSF.d \
./Opus/silk/CNG.d \
./Opus/silk/HP_variable_cutoff.d \
./Opus/silk/LPC_analysis_filter.d \
./Opus/silk/LPC_fit.d \
./Opus/silk/LPC_inv_pred_gain.d \
./Opus/silk/LP_variable_cutoff.d \
./Opus/silk/NLSF2A.d \
./Opus/silk/NLSF_VQ.d \
./Opus/silk/NLSF_VQ_weights_laroia.d \
./Opus/silk/NLSF_decode.d \
./Opus/silk/NLSF_del_dec_quant.d \
./Opus/silk/NLSF_encode.d \
./Opus/silk/NLSF_stabilize.d \
./Opus/silk/NLSF_unpack.d \
./Opus/silk/NSQ.d \
./Opus/silk/NSQ_del_dec.d \
./Opus/silk/PLC.d \
./Opus/silk/VAD.d \
./Opus/silk/VQ_WMat_EC.d \
./Opus/silk/ana_filt_bank_1.d \
./Opus/silk/biquad_alt.d \
./Opus/silk/bwexpander.d \
./Opus/silk/bwexpander_32.d \
./Opus/silk/check_control_input.d \
./Opus/silk/code_signs.d \
./Opus/silk/control_SNR.d \
./Opus/silk/control_audio_bandwidth.d \
./Opus/silk/control_codec.d \
./Opus/silk/debug.d \
./Opus/silk/dec_API.d \
./Opus/silk/decode_core.d \
./Opus/silk/decode_frame.d \
./Opus/silk/decode_indices.d \
./Opus/silk/decode_parameters.d \
./Opus/silk/decode_pitch.d \
./Opus/silk/decode_pulses.d \
./Opus/silk/decoder_set_fs.d \
./Opus/silk/enc_API.d \
./Opus/silk/encode_indices.d \
./Opus/silk/encode_pulses.d \
./Opus/silk/gain_quant.d \
./Opus/silk/init_decoder.d \
./Opus/silk/init_encoder.d \
./Opus/silk/inner_prod_aligned.d \
./Opus/silk/interpolate.d \
./Opus/silk/lin2log.d \
./Opus/silk/log2lin.d \
./Opus/silk/pitch_est_tables.d \
./Opus/silk/process_NLSFs.d \
./Opus/silk/quant_LTP_gains.d \
./Opus/silk/resampler.d \
./Opus/silk/resampler_down2.d \
./Opus/silk/resampler_down2_3.d \
./Opus/silk/resampler_private_AR2.d \
./Opus/silk/resampler_private_IIR_FIR.d \
./Opus/silk/resampler_private_down_FIR.d \
./Opus/silk/resampler_private_up2_HQ.d \
./Opus/silk/resampler_rom.d \
./Opus/silk/shell_coder.d \
./Opus/silk/sigm_Q15.d \
./Opus/silk/sort.d \
./Opus/silk/stereo_LR_to_MS.d \
./Opus/silk/stereo_MS_to_LR.d \
./Opus/silk/stereo_decode_pred.d \
./Opus/silk/stereo_encode_pred.d \
./Opus/silk/stereo_find_predictor.d \
./Opus/silk/stereo_quant_pred.d \
./Opus/silk/sum_sqr_shift.d \
./Opus/silk/table_LSF_cos.d \
./Opus/silk/tables_LTP.d \
./Opus/silk/tables_NLSF_CB_NB_MB.d \
./Opus/silk/tables_NLSF_CB_WB.d \
./Opus/silk/tables_gain.d \
./Opus/silk/tables_other.d \
./Opus/silk/tables_pitch_lag.d \
./Opus/silk/tables_pulses_per_block.d 


# Each subdirectory must supply rules for building sources it contributes
Opus/silk/%.o Opus/silk/%.su Opus/silk/%.cyclo: ../Opus/silk/%.c Opus/silk/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DHAL_I2S_MODULE_ENABLED -DHAVE_CONFIG_H -DHAL_SAI_MODULE_ENABLED -DOPUS_ARM_INLINE_ASM -DOPUS_ARM_ASM -DHAL_SPI_MODULE_ENABLED -DDEBUG -DHAL_I2C_MODULE_ENABLED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../ESP32/inc -I../ExtraDrivers/inc -I../AudioIn/inc -I../AudioLibraries/inc -I../AudioLibraries/libs/STM32_AcousticBF_Library/Inc -I../AudioOut/inc -I../AudioLibraries/libs/SDR/Inc -I../OpusCmds/inc -I../Opus/src -I../Opus/include -I../Opus/celt -I../Opus/celt/arm -I../Opus/silk -I../Opus/silk/arm -I../Opus/silk/fixed -I../Opus/win32 -I../Opus/win32/VS2015 -I../BatteryMgmt -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Opus-2f-silk

clean-Opus-2f-silk:
	-$(RM) ./Opus/silk/A2NLSF.cyclo ./Opus/silk/A2NLSF.d ./Opus/silk/A2NLSF.o ./Opus/silk/A2NLSF.su ./Opus/silk/CNG.cyclo ./Opus/silk/CNG.d ./Opus/silk/CNG.o ./Opus/silk/CNG.su ./Opus/silk/HP_variable_cutoff.cyclo ./Opus/silk/HP_variable_cutoff.d ./Opus/silk/HP_variable_cutoff.o ./Opus/silk/HP_variable_cutoff.su ./Opus/silk/LPC_analysis_filter.cyclo ./Opus/silk/LPC_analysis_filter.d ./Opus/silk/LPC_analysis_filter.o ./Opus/silk/LPC_analysis_filter.su ./Opus/silk/LPC_fit.cyclo ./Opus/silk/LPC_fit.d ./Opus/silk/LPC_fit.o ./Opus/silk/LPC_fit.su ./Opus/silk/LPC_inv_pred_gain.cyclo ./Opus/silk/LPC_inv_pred_gain.d ./Opus/silk/LPC_inv_pred_gain.o ./Opus/silk/LPC_inv_pred_gain.su ./Opus/silk/LP_variable_cutoff.cyclo ./Opus/silk/LP_variable_cutoff.d ./Opus/silk/LP_variable_cutoff.o ./Opus/silk/LP_variable_cutoff.su ./Opus/silk/NLSF2A.cyclo ./Opus/silk/NLSF2A.d ./Opus/silk/NLSF2A.o ./Opus/silk/NLSF2A.su ./Opus/silk/NLSF_VQ.cyclo ./Opus/silk/NLSF_VQ.d ./Opus/silk/NLSF_VQ.o ./Opus/silk/NLSF_VQ.su ./Opus/silk/NLSF_VQ_weights_laroia.cyclo ./Opus/silk/NLSF_VQ_weights_laroia.d ./Opus/silk/NLSF_VQ_weights_laroia.o ./Opus/silk/NLSF_VQ_weights_laroia.su ./Opus/silk/NLSF_decode.cyclo ./Opus/silk/NLSF_decode.d ./Opus/silk/NLSF_decode.o ./Opus/silk/NLSF_decode.su ./Opus/silk/NLSF_del_dec_quant.cyclo ./Opus/silk/NLSF_del_dec_quant.d ./Opus/silk/NLSF_del_dec_quant.o ./Opus/silk/NLSF_del_dec_quant.su ./Opus/silk/NLSF_encode.cyclo ./Opus/silk/NLSF_encode.d ./Opus/silk/NLSF_encode.o ./Opus/silk/NLSF_encode.su ./Opus/silk/NLSF_stabilize.cyclo ./Opus/silk/NLSF_stabilize.d ./Opus/silk/NLSF_stabilize.o ./Opus/silk/NLSF_stabilize.su ./Opus/silk/NLSF_unpack.cyclo ./Opus/silk/NLSF_unpack.d ./Opus/silk/NLSF_unpack.o ./Opus/silk/NLSF_unpack.su ./Opus/silk/NSQ.cyclo ./Opus/silk/NSQ.d ./Opus/silk/NSQ.o ./Opus/silk/NSQ.su ./Opus/silk/NSQ_del_dec.cyclo ./Opus/silk/NSQ_del_dec.d ./Opus/silk/NSQ_del_dec.o ./Opus/silk/NSQ_del_dec.su ./Opus/silk/PLC.cyclo ./Opus/silk/PLC.d ./Opus/silk/PLC.o ./Opus/silk/PLC.su ./Opus/silk/VAD.cyclo ./Opus/silk/VAD.d ./Opus/silk/VAD.o ./Opus/silk/VAD.su ./Opus/silk/VQ_WMat_EC.cyclo ./Opus/silk/VQ_WMat_EC.d ./Opus/silk/VQ_WMat_EC.o ./Opus/silk/VQ_WMat_EC.su ./Opus/silk/ana_filt_bank_1.cyclo ./Opus/silk/ana_filt_bank_1.d ./Opus/silk/ana_filt_bank_1.o ./Opus/silk/ana_filt_bank_1.su ./Opus/silk/biquad_alt.cyclo ./Opus/silk/biquad_alt.d ./Opus/silk/biquad_alt.o ./Opus/silk/biquad_alt.su ./Opus/silk/bwexpander.cyclo ./Opus/silk/bwexpander.d ./Opus/silk/bwexpander.o ./Opus/silk/bwexpander.su ./Opus/silk/bwexpander_32.cyclo ./Opus/silk/bwexpander_32.d ./Opus/silk/bwexpander_32.o ./Opus/silk/bwexpander_32.su ./Opus/silk/check_control_input.cyclo ./Opus/silk/check_control_input.d ./Opus/silk/check_control_input.o ./Opus/silk/check_control_input.su ./Opus/silk/code_signs.cyclo ./Opus/silk/code_signs.d ./Opus/silk/code_signs.o ./Opus/silk/code_signs.su ./Opus/silk/control_SNR.cyclo ./Opus/silk/control_SNR.d ./Opus/silk/control_SNR.o ./Opus/silk/control_SNR.su ./Opus/silk/control_audio_bandwidth.cyclo ./Opus/silk/control_audio_bandwidth.d ./Opus/silk/control_audio_bandwidth.o ./Opus/silk/control_audio_bandwidth.su ./Opus/silk/control_codec.cyclo ./Opus/silk/control_codec.d ./Opus/silk/control_codec.o ./Opus/silk/control_codec.su ./Opus/silk/debug.cyclo ./Opus/silk/debug.d ./Opus/silk/debug.o ./Opus/silk/debug.su ./Opus/silk/dec_API.cyclo ./Opus/silk/dec_API.d ./Opus/silk/dec_API.o ./Opus/silk/dec_API.su ./Opus/silk/decode_core.cyclo ./Opus/silk/decode_core.d ./Opus/silk/decode_core.o ./Opus/silk/decode_core.su ./Opus/silk/decode_frame.cyclo ./Opus/silk/decode_frame.d ./Opus/silk/decode_frame.o ./Opus/silk/decode_frame.su ./Opus/silk/decode_indices.cyclo ./Opus/silk/decode_indices.d ./Opus/silk/decode_indices.o ./Opus/silk/decode_indices.su ./Opus/silk/decode_parameters.cyclo ./Opus/silk/decode_parameters.d ./Opus/silk/decode_parameters.o ./Opus/silk/decode_parameters.su ./Opus/silk/decode_pitch.cyclo ./Opus/silk/decode_pitch.d ./Opus/silk/decode_pitch.o ./Opus/silk/decode_pitch.su ./Opus/silk/decode_pulses.cyclo ./Opus/silk/decode_pulses.d ./Opus/silk/decode_pulses.o ./Opus/silk/decode_pulses.su ./Opus/silk/decoder_set_fs.cyclo ./Opus/silk/decoder_set_fs.d ./Opus/silk/decoder_set_fs.o ./Opus/silk/decoder_set_fs.su ./Opus/silk/enc_API.cyclo ./Opus/silk/enc_API.d ./Opus/silk/enc_API.o ./Opus/silk/enc_API.su ./Opus/silk/encode_indices.cyclo ./Opus/silk/encode_indices.d ./Opus/silk/encode_indices.o ./Opus/silk/encode_indices.su ./Opus/silk/encode_pulses.cyclo ./Opus/silk/encode_pulses.d ./Opus/silk/encode_pulses.o ./Opus/silk/encode_pulses.su ./Opus/silk/gain_quant.cyclo ./Opus/silk/gain_quant.d ./Opus/silk/gain_quant.o ./Opus/silk/gain_quant.su ./Opus/silk/init_decoder.cyclo ./Opus/silk/init_decoder.d ./Opus/silk/init_decoder.o ./Opus/silk/init_decoder.su ./Opus/silk/init_encoder.cyclo ./Opus/silk/init_encoder.d ./Opus/silk/init_encoder.o ./Opus/silk/init_encoder.su ./Opus/silk/inner_prod_aligned.cyclo ./Opus/silk/inner_prod_aligned.d ./Opus/silk/inner_prod_aligned.o ./Opus/silk/inner_prod_aligned.su ./Opus/silk/interpolate.cyclo ./Opus/silk/interpolate.d ./Opus/silk/interpolate.o ./Opus/silk/interpolate.su ./Opus/silk/lin2log.cyclo ./Opus/silk/lin2log.d ./Opus/silk/lin2log.o ./Opus/silk/lin2log.su ./Opus/silk/log2lin.cyclo ./Opus/silk/log2lin.d ./Opus/silk/log2lin.o ./Opus/silk/log2lin.su ./Opus/silk/pitch_est_tables.cyclo ./Opus/silk/pitch_est_tables.d ./Opus/silk/pitch_est_tables.o ./Opus/silk/pitch_est_tables.su ./Opus/silk/process_NLSFs.cyclo ./Opus/silk/process_NLSFs.d ./Opus/silk/process_NLSFs.o ./Opus/silk/process_NLSFs.su ./Opus/silk/quant_LTP_gains.cyclo ./Opus/silk/quant_LTP_gains.d ./Opus/silk/quant_LTP_gains.o ./Opus/silk/quant_LTP_gains.su ./Opus/silk/resampler.cyclo ./Opus/silk/resampler.d ./Opus/silk/resampler.o ./Opus/silk/resampler.su ./Opus/silk/resampler_down2.cyclo ./Opus/silk/resampler_down2.d ./Opus/silk/resampler_down2.o ./Opus/silk/resampler_down2.su ./Opus/silk/resampler_down2_3.cyclo
	-$(RM) ./Opus/silk/resampler_down2_3.d ./Opus/silk/resampler_down2_3.o ./Opus/silk/resampler_down2_3.su ./Opus/silk/resampler_private_AR2.cyclo ./Opus/silk/resampler_private_AR2.d ./Opus/silk/resampler_private_AR2.o ./Opus/silk/resampler_private_AR2.su ./Opus/silk/resampler_private_IIR_FIR.cyclo ./Opus/silk/resampler_private_IIR_FIR.d ./Opus/silk/resampler_private_IIR_FIR.o ./Opus/silk/resampler_private_IIR_FIR.su ./Opus/silk/resampler_private_down_FIR.cyclo ./Opus/silk/resampler_private_down_FIR.d ./Opus/silk/resampler_private_down_FIR.o ./Opus/silk/resampler_private_down_FIR.su ./Opus/silk/resampler_private_up2_HQ.cyclo ./Opus/silk/resampler_private_up2_HQ.d ./Opus/silk/resampler_private_up2_HQ.o ./Opus/silk/resampler_private_up2_HQ.su ./Opus/silk/resampler_rom.cyclo ./Opus/silk/resampler_rom.d ./Opus/silk/resampler_rom.o ./Opus/silk/resampler_rom.su ./Opus/silk/shell_coder.cyclo ./Opus/silk/shell_coder.d ./Opus/silk/shell_coder.o ./Opus/silk/shell_coder.su ./Opus/silk/sigm_Q15.cyclo ./Opus/silk/sigm_Q15.d ./Opus/silk/sigm_Q15.o ./Opus/silk/sigm_Q15.su ./Opus/silk/sort.cyclo ./Opus/silk/sort.d ./Opus/silk/sort.o ./Opus/silk/sort.su ./Opus/silk/stereo_LR_to_MS.cyclo ./Opus/silk/stereo_LR_to_MS.d ./Opus/silk/stereo_LR_to_MS.o ./Opus/silk/stereo_LR_to_MS.su ./Opus/silk/stereo_MS_to_LR.cyclo ./Opus/silk/stereo_MS_to_LR.d ./Opus/silk/stereo_MS_to_LR.o ./Opus/silk/stereo_MS_to_LR.su ./Opus/silk/stereo_decode_pred.cyclo ./Opus/silk/stereo_decode_pred.d ./Opus/silk/stereo_decode_pred.o ./Opus/silk/stereo_decode_pred.su ./Opus/silk/stereo_encode_pred.cyclo ./Opus/silk/stereo_encode_pred.d ./Opus/silk/stereo_encode_pred.o ./Opus/silk/stereo_encode_pred.su ./Opus/silk/stereo_find_predictor.cyclo ./Opus/silk/stereo_find_predictor.d ./Opus/silk/stereo_find_predictor.o ./Opus/silk/stereo_find_predictor.su ./Opus/silk/stereo_quant_pred.cyclo ./Opus/silk/stereo_quant_pred.d ./Opus/silk/stereo_quant_pred.o ./Opus/silk/stereo_quant_pred.su ./Opus/silk/sum_sqr_shift.cyclo ./Opus/silk/sum_sqr_shift.d ./Opus/silk/sum_sqr_shift.o ./Opus/silk/sum_sqr_shift.su ./Opus/silk/table_LSF_cos.cyclo ./Opus/silk/table_LSF_cos.d ./Opus/silk/table_LSF_cos.o ./Opus/silk/table_LSF_cos.su ./Opus/silk/tables_LTP.cyclo ./Opus/silk/tables_LTP.d ./Opus/silk/tables_LTP.o ./Opus/silk/tables_LTP.su ./Opus/silk/tables_NLSF_CB_NB_MB.cyclo ./Opus/silk/tables_NLSF_CB_NB_MB.d ./Opus/silk/tables_NLSF_CB_NB_MB.o ./Opus/silk/tables_NLSF_CB_NB_MB.su ./Opus/silk/tables_NLSF_CB_WB.cyclo ./Opus/silk/tables_NLSF_CB_WB.d ./Opus/silk/tables_NLSF_CB_WB.o ./Opus/silk/tables_NLSF_CB_WB.su ./Opus/silk/tables_gain.cyclo ./Opus/silk/tables_gain.d ./Opus/silk/tables_gain.o ./Opus/silk/tables_gain.su ./Opus/silk/tables_other.cyclo ./Opus/silk/tables_other.d ./Opus/silk/tables_other.o ./Opus/silk/tables_other.su ./Opus/silk/tables_pitch_lag.cyclo ./Opus/silk/tables_pitch_lag.d ./Opus/silk/tables_pitch_lag.o ./Opus/silk/tables_pitch_lag.su ./Opus/silk/tables_pulses_per_block.cyclo ./Opus/silk/tables_pulses_per_block.d ./Opus/silk/tables_pulses_per_block.o ./Opus/silk/tables_pulses_per_block.su

.PHONY: clean-Opus-2f-silk

