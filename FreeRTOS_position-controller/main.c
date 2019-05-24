/***************************** Include files *******************************/

/* Standard includes. */
#include <setup.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/*  Mis. Includes */
#include "EMP_type.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "defines.h"

/* Hardware includes. */
#include "tm4c123gh6pm.h"
#include "gpio.h"

/* Task includes */
#include "SPI.h"
#include "PID_FreeRTOS.h"
#include "uart_protocol.h"

/* Tiva includes */
#include <driverlib/sysctl.h>



/*****************************    Defines    *******************************/

#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3

/*****************************   Constants   *******************************/


/*****************************   Variables   *******************************/

struct PID_parameter PC_1_parameter;
struct PID_parameter VC_1_parameter;
struct PID_parameter PC_2_parameter;
struct PID_parameter VC_2_parameter;



/*****************************   Functions   *******************************/

int main(void)
{
    // Init system

    uart0_init(9600, 8, 1, 0);
    init_gpio();
    SPI_init();
    init_sem();
    init_queue();
    init_PIDs();
    init_parameters();



    // Create tasks
    // -------------------

    // Controller tasks

    xTaskCreate(PID_PC_task, "Position controller 1", 100, &PC_1_parameter, 3, &PC_PID1_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 1", 100, &VC_1_parameter, 4, &VC_PID1_handle);
    xTaskCreate(PID_PC_task, "Position controller 2", 100, &PC_2_parameter, 3, &PC_PID2_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 2", 100, &VC_2_parameter, 5, &VC_PID2_handle);

    // Other tasks

    xTaskCreate(UARTDriverTask, "Get from UART queue", 100, NULL, 1, &UART_driver_task_handle);
    xTaskCreate(UITask, "UI", 100, NULL, 1, &UI_task_handle);
    xTaskCreate(SPI_task, "SPI module", 100, NULL, 8, &SPI_handle);


    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();


    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
