################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FPGA_comp.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/FPGA_comp.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"FPGA_comp.d" -MT"FPGA_comp.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Filter.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/Filter.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"Filter.d" -MT"Filter.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PID_MA.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/PID_MA.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"PID_MA.d" -MT"PID_MA.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SPI.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/SPI.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"SPI.d" -MT"SPI.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

circular_buffer.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/circular_buffer.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"circular_buffer.d" -MT"circular_buffer.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

gpio.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/EMP\ libraries/gpio.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"gpio.d" -MT"gpio.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

rtcs.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/rtcs.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"rtcs.d" -MT"rtcs.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

systick.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/EMP\ libraries/systick.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"systick.d" -MT"systick.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

test.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/test.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"test.d" -MT"test.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

uart.o: C:/Users/Jakob/Google\ Drive/01\ SDU/04\ 4.\ Semester/05\ 4.\ semesterprojekt/4-semester-project/C\ libraries/uart.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/PositionController_MA" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/C libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/EMP libraries" -I"C:/Users/Jakob/Google Drive/01 SDU/04 4. Semester/05 4. semesterprojekt/4-semester-project/Project_SPI_System" -I"C:/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"uart.d" -MT"uart.d"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


