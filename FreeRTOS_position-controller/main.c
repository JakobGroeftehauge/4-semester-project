/***************************** Include files *******************************/

/* Standard includes. */
#include <setup.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
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

//uint32_t SystemCoreClock;

/*****************************   Functions   *******************************/

int main(void)
{
    //SystemCoreClock;
    //init_systick();
    init_gpio();
    SPI_init();
    init_sem();
    init_queue();
    init_PIDs();
    init_parameters();

    pos_var = 32;

    // Create tasks
    // -------------------
    xTaskCreate(PID_PC_task, "Position controller 1", 100, &PC_1_parameter, 8, &PC_PID1_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 1", 100, &VC_1_parameter, 8, &VC_PID1_handle);
    xTaskCreate(PID_PC_task, "Position controller 2", 100, &PC_2_parameter, 8, &PC_PID2_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 2", 100, &VC_2_parameter, 8, &VC_PID2_handle);

    uint8_t empty = 4;
    xTaskCreate(SPI_task, "SPI module", 100, &empty, 1, &SPI_handle);

    control_1_pos_ref = 500;
    control_2_pos_ref = 500;
    control_2_pos = 200;


    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();


    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
