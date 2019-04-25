/***************************** Include files *******************************/

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "EMP_type.h"
#include "defines.h"

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


/*****************************   Variables   *******************************/
volatile INT16S pwm_var;
volatile INT16S pos_var;

volatile float control_signal_PC1;
volatile float control_signal_PC2;

volatile float feedback;
volatile int16_t output_PC1;
volatile int16_t output_PC2;

//PID_parameter PID1_PC = {CC_CONTROLLER_ID, &output_PC1, &control_signal_PC1};
//PID_parameter PID2_PC = {CC_CONTROLLER_ID, &output_PC2, &control_signal_PC2};

//uint32_t SystemCoreClock;

/*****************************   Functions   *******************************/

int main(void)
{
    //SystemCoreClock;
    //init_systick();
    init_gpio();


    // Create queues
    // -------------------
    SPI_queue = xQueueCreate(100, //Number of elements in queue
                             sizeof( struct SPI_queue_element  ) ); //Number of bytes for each element


    // Create tasks
    // -------------------
    //Debuggeren bliver stuck derinde pga semaphore
   // xTaskCreate(PID_PC_task, "Position controller 1", 100, &PID1_PC, 8, &PC_PID1_handle);

    xTaskCreate(SPI_task, "SPI module", 100, 4, 1, &SPI_handle);

    //Bruges til at teste passing a structs i queues.
    xTaskCreate(update_values_task, "Update values module", 100, &PID1_PC, 1, &adjust_values_handle);


    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();



    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
