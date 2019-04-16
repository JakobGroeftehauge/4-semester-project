

/**
 * main.c
 */

/***************************** Include files *******************************/

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Hardware includes. */
//#include "hardware_tm4c123g.h" // Requires TivaWare library
//#include "systick_frt.h"    // From Mortens Lessons
#include "tm4c123gh6pm.h"
#include "gpio.h"


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

//uint32_t SystemCoreClock;

/*****************************   Functions   *******************************/

void ledTaskFlash( void *pvParameters)
{
    TickType_t xLastWakeTime;
    //uint32_t xLastWakeTime;
    //parameter = (uint8_t *) pvParameters;
    xLastWakeTime = xTaskGetTickCount();
    //uint16_t *parameter = (uint16_t * ) pvParameters;

    uint16_t time = 200;
    for (;;)
    {
        if (pvParameters == GREEN_LED_TASK)
        {
            GPIO_PORTF_DATA_R ^= 0x04;
            time = 2000;

        }
        if (pvParameters == YELLOW_LED_TASK)
        {
            GPIO_PORTF_DATA_R ^= 0x02;
            time = 3000;
        }


        vTaskDelayUntil (&xLastWakeTime, pdMS_TO_TICKS( time ) );
        //vTaskDelay(time);
    }
}

void semTask

int main(void)
{
    //SystemCoreClock;
    //init_systick();
    init_gpio();

    //Create semaphores
    SemaphoreHandle_t taskSignalSem;
    taskSignalSem = xSemaphoreCreateCounting( UBaseType_t 10,
                                                UBaseType_t 0);

    xSemaphoreTake();
    // Start the tasks.
    // ----------------
    xTaskCreate(ledTaskFlash, "Yellow LED task", 100, 2, 1, NULL );
    xTaskCreate(ledTaskFlash, "Green LED task", 100, 3, 1, NULL );
    xTaskCreate(semTask, "semTask", 100, 4, 1, Null);

    //GPIO_PORTF_DATA_R = 0x02;

    // Start the scheduler.
    // --------------------
    vTaskStartScheduler();

    GPIO_PORTF_DATA_R = 0x02;

    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
