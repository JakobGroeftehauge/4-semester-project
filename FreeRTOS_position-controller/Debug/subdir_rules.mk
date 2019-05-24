################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Filter.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/Filter.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOS_position-controller" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/TivaWare_C_Series-2.1.4.178" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/jmkaa/git/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/jmkaa/git/4-semester-project/TivaWare_C_Series-2.1.4.178" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"Filter.d" -MT"Filter.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PID_FreeRTOS.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/PID_FreeRTOS.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOS_position-controller" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/TivaWare_C_Series-2.1.4.178" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/jmkaa/git/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/jmkaa/git/4-semester-project/TivaWare_C_Series-2.1.4.178" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"PID_FreeRTOS.d" -MT"PID_FreeRTOS.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SPI.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/SPI.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOS_position-controller" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/TivaWare_C_Series-2.1.4.178" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/jmkaa/git/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/jmkaa/git/4-semester-project/TivaWare_C_Series-2.1.4.178" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"SPI.d" -MT"SPI.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

circular_buffer.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/circular_buffer.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOS_position-controller" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/TivaWare_C_Series-2.1.4.178" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/jmkaa/git/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/jmkaa/git/4-semester-project/TivaWare_C_Series-2.1.4.178" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"circular_buffer.d" -MT"circular_buffer.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOS_position-controller" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/TivaWare_C_Series-2.1.4.178" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/jmkaa/git/4-semester-project/FreeRTOSv10.2.0/FreeRTOS/Source/include" -I"C:/Users/jmkaa/git/4-semester-project/TivaWare_C_Series-2.1.4.178" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


