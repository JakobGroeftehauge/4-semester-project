################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FPGA_comp.o: C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C\ libraries/FPGA_comp.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/Position_controller_FreeRTOS" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C libraries" -I"C:/Users/Mads/Documents/GitHub/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Filter.o: C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C\ libraries/Filter.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/Position_controller_FreeRTOS" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C libraries" -I"C:/Users/Mads/Documents/GitHub/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PID_MA.o: C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C\ libraries/PID_MA.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/Position_controller_FreeRTOS" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C libraries" -I"C:/Users/Mads/Documents/GitHub/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

circular_buffer.o: C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C\ libraries/circular_buffer.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/Position_controller_FreeRTOS" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C libraries" -I"C:/Users/Mads/Documents/GitHub/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/Position_controller_FreeRTOS" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/chris/Documents/4_sem_code_git_before_exam/4-semester-project/C libraries" -I"C:/Users/Mads/Documents/GitHub/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


