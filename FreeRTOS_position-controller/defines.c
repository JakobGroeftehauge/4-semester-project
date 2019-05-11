
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "defines.h"

#include "EMP_type.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "PID_FreeRTOS.h"

// Slaves


//Task handles
TaskHandle_t PC_PID1_handle = NULL;
TaskHandle_t PC_PID2_handle = NULL;
TaskHandle_t VC_PID1_handle = NULL;
TaskHandle_t VC_PID2_handle = NULL;


TaskHandle_t SPI_handle = NULL;
TaskHandle_t adjust_values_handle = NULL;
TaskHandle_t SPI_test_handle = NULL;

TaskHandle_t UI_task_handle = NULL;
TaskHandle_t UART_driver_task_handle = NULL;


