

/**
 * main.c
 */

/***************************** Include files *******************************/

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "EMP_type.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

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
TaskHandle_t PC_PID1_handle = NULL;

/*****************************   Variables   *******************************/
volatile INT16S pwm_var;
volatile INT16S pos_var;

volatile float controlSignal;
volatile float feedback;
volatile int16_t output_PC1;

//uint32_t SystemCoreClock;

/*****************************   Functions   *******************************/

int main(void)
{
    //SystemCoreClock;
    //init_systick();
    init_gpio();

    xTaskCreate(PID_task, "Position controller 1", 100, 4, 8, &PC_PID1_handle);



    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();



    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
