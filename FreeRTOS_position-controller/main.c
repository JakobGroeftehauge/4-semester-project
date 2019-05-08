/***************************** Include files *******************************/

/* Standard includes. */
#include <setup.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "EMP_type.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "defines.h"
/* Hardware includes. */
//#include "hardware_tm4c123g.h" // Requires TivaWare library
//#include "systick_frt.h"    // From Mortens Lessons
#include "tm4c123gh6pm.h"
#include "gpio.h"

/* Task includes */
#include "SPI.h"
#include "PID_FreeRTOS.h"
#include "uart_protocol.h"

/* Tiva includes */
#include <driverlib/sysctl.h>



/*****************************    Defines    *******************************/
//#define USERTASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3

#define GREEN_LED_TASK 2
#define YELLOW_LED_TASK 3


/*****************************   Constants   *******************************/


/*****************************   Variables   *******************************/
volatile INT16S pwm_var;
volatile INT16S pos_var;

struct PID_parameter PC_1_parameter;
struct PID_parameter VC_1_parameter;
struct PID_parameter PC_2_parameter;
struct PID_parameter VC_2_parameter;

volatile float control_signal_PC1;
volatile float control_signal_PC2;

volatile float feedback;
volatile int16_t output_PC1;
volatile int16_t output_PC2;
float control_1_pos_ref;


/*****************************   Functions   *******************************/

int main(void)
    {

    uart0_init(9600, 8, 1, 0);
    init_gpio();
    SPI_init();
    init_sem();
    init_queue();
    init_PIDs();
    init_parameters();

    xUARTReceive_queue = xQueueCreate(15, 8);


    // Create tasks
    // -------------------
    //xTaskCreate(PID_PC_task, "Position controller 1", 100, &PC_1_parameter, 8, &PC_PID1_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 1", 100, &VC_1_parameter, 8, &VC_PID1_handle);
    //xTaskCreate(PID_PC_task, "Position controller 2", 100, &PC_2_parameter, 8, &PC_PID2_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 2", 100, &VC_2_parameter, 8, &VC_PID2_handle);

    //send_data( 0x00CC, 8);

    xTaskCreate(UARTDriverTask, "Get from UART queue", 150, NULL, 1, &UART_driver_task_handle);
    xTaskCreate(UITask, "UI", 100, NULL, 1, &UI_task_handle);
    xTaskCreate(SPI_task, "SPI module", 100, NULL, 1, &SPI_handle);

    control_1_pos_ref = 0;
    control_2_pos_ref = 0;
    //control_2_pos_ref = 30;
    //control_1_vel_ref = 20.5;


    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();


    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
