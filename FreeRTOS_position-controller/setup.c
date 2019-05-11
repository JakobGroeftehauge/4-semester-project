#include <setup.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "EMP_type.h"

#include "setup.h"
#include "FPGA_comp.h"
#include "FreeRTOS.h"
#include "defines.h"
#include "PID_freeRTOS.h"
#include "SPI.h"



#include "task.h"
#include "semphr.h"
#include "tm4c123gh6pm.h"
#include "gpio.h"


/********************** External declaration of Variables ******************/
float control_1_pos;
float control_1_vel;
float control_1_cur;
float control_2_pos;
float control_2_vel;
float control_2_cur;

float control_1_pos_ref;
float control_1_vel_ref;
float control_1_cur_ref;
float control_2_pos_ref;
float control_2_vel_ref;
float control_2_cur_ref;

int16_t glob_protocol;

/****************************    Semaphores    ***************************/
SemaphoreHandle_t POS_1_SEM;
SemaphoreHandle_t VEL_1_SEM;
SemaphoreHandle_t POS_2_SEM;
SemaphoreHandle_t VEL_2_SEM;

SemaphoreHandle_t POS_1_REF_SEM;
SemaphoreHandle_t VEL_1_REF_SEM;
SemaphoreHandle_t POS_2_REF_SEM;
SemaphoreHandle_t VEL_2_REF_SEM;


SemaphoreHandle_t SPI_EOT_SEM;
SemaphoreHandle_t QUEUE_SEM;
SemaphoreHandle_t UART_RECEIVE_SEM;


extern void init_sem()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    POS_1_SEM = xSemaphoreCreateCounting(1, 0);
    VEL_1_SEM = xSemaphoreCreateCounting(1, 0);
    POS_2_SEM = xSemaphoreCreateCounting(1, 0);
    VEL_2_SEM = xSemaphoreCreateCounting(1, 0);

    POS_1_REF_SEM = xSemaphoreCreateCounting(1, 1);
    VEL_1_REF_SEM = xSemaphoreCreateCounting(1, 1);
    POS_2_REF_SEM = xSemaphoreCreateCounting(1, 1);
    VEL_2_REF_SEM = xSemaphoreCreateCounting(1, 1);

    SPI_EOT_SEM = xSemaphoreCreateCounting(1, 0);
    QUEUE_SEM = xSemaphoreCreateCounting(1, 1);
    UART_RECEIVE_SEM = xSemaphoreCreateCounting(1, 0);
}

extern void init_queue()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    SPI_queue = xQueueCreate(10, //Number of elements in queue
                             sizeof( struct SPI_queue_element  ) ); //Number of bytes for each element
}

extern void init_parameters()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
//    PC_1_parameter.id =                     PC_CONTROLLER_1_ID;
//    PC_1_parameter.slave_id =               POS_1;
//    PC_1_parameter.place_to_store_output =  &control_1_vel_ref;
//    PC_1_parameter.output_semaphore =       &VEL_1_REF_SEM;
//    PC_1_parameter.reference_signal =       &control_1_pos_ref;
//    PC_1_parameter.reference_semaphore =    &POS_1_REF_SEM;
//    PC_1_parameter.feedback_signal =        &control_1_pos;
//    PC_1_parameter.feedback_semaphore =     &POS_1_SEM;
//    PC_1_parameter.delayTime =              5;
//    PC_1_parameter.queue_semaphore =        &QUEUE_SEM;
//    PC_1_parameter.output_id =              0;
//    PC_1_parameter.test_led =               0x10;
//
//    VC_1_parameter.id =                     VC_CONTROLLER_1_ID;
//    VC_1_parameter.slave_id =               VEL_1;
//    VC_1_parameter.place_to_store_output =  &control_1_vel_ref;
//    VC_1_parameter.output_semaphore =       &VEL_1_REF_SEM;
//    VC_1_parameter.reference_signal =       &control_1_vel_ref;
//    VC_1_parameter.reference_semaphore =    &VEL_1_REF_SEM;
//    VC_1_parameter.feedback_signal =        &control_1_vel;
//    VC_1_parameter.feedback_semaphore =     &VEL_1_SEM;
//    VC_1_parameter.delayTime =              1;
//    VC_1_parameter.queue_semaphore =        &QUEUE_SEM;
//    VC_1_parameter.output_id =              PWM_1;
//    VC_1_parameter.test_led =               0x40;

    VC_1_parameter.id =                     VC_CONTROLLER_1_ID;
    VC_1_parameter.slave_id =               POS_1;
    VC_1_parameter.place_to_store_output =  &control_1_vel_ref; // not used for this controller
    VC_1_parameter.output_semaphore =       &VEL_1_REF_SEM;
    VC_1_parameter.reference_signal =       &control_1_pos_ref;
    VC_1_parameter.reference_semaphore =    &POS_1_REF_SEM;
    VC_1_parameter.feedback_signal =        &control_1_pos;
    VC_1_parameter.feedback_semaphore =     &POS_1_SEM;
    VC_1_parameter.delayTime =              1;
    VC_1_parameter.queue_semaphore =        &QUEUE_SEM;
    VC_1_parameter.output_id =              PWM_1;


//    PC_2_parameter.id =                     PC_CONTROLLER_2_ID;
//    PC_2_parameter.slave_id =               POS_2;
//    PC_2_parameter.place_to_store_output =  &control_2_vel_ref;
//    PC_2_parameter.output_semaphore =       &VEL_2_REF_SEM;
//    PC_2_parameter.reference_signal =       &control_2_pos_ref;
//    PC_2_parameter.reference_semaphore =    &POS_2_REF_SEM;
//    PC_2_parameter.feedback_signal =        &control_2_pos;
//    PC_2_parameter.feedback_semaphore =     &POS_2_SEM;
//    PC_2_parameter.delayTime =              5;
//    PC_2_parameter.queue_semaphore =        &QUEUE_SEM;
//    PC_2_parameter.output_id =              0;
//    PC_2_parameter.test_led =               0x10;

//    VC_2_parameter.id =                     VC_CONTROLLER_2_ID;
//    VC_2_parameter.slave_id =               VEL_2;
//    VC_2_parameter.place_to_store_output =  &control_2_vel_ref;
//    VC_2_parameter.output_semaphore =       &VEL_2_REF_SEM;
//    VC_2_parameter.reference_signal =       &control_2_vel_ref;
//    VC_2_parameter.reference_semaphore =    &VEL_2_REF_SEM;
//    VC_2_parameter.feedback_signal =        &control_2_vel;
//    VC_2_parameter.feedback_semaphore =     &VEL_2_SEM;
//    VC_2_parameter.delayTime =              1;
//    VC_2_parameter.queue_semaphore =        &QUEUE_SEM;
//    VC_2_parameter.output_id =              PWM_2;
//    VC_2_parameter.test_led =               0x40;


//    VC_2_parameter.id =                     VC_CONTROLLER_2_ID;
//    VC_2_parameter.slave_id =               POS_2;//VEL_1;
//    VC_2_parameter.place_to_store_output =  &control_2_vel_ref;
//    VC_2_parameter.output_semaphore =       &VEL_2_REF_SEM;
//    VC_2_parameter.reference_signal =       &control_2_pos_ref;//&control_1_vel_ref;
//    VC_2_parameter.reference_semaphore =    &POS_2_REF_SEM;//&VEL_1_REF_SEM;
//    VC_2_parameter.feedback_signal =        &control_2_pos;//&control_1_vel;
//    VC_2_parameter.feedback_semaphore =     &POS_2_SEM;//&VEL_1_SEM;
//    VC_2_parameter.delayTime =              1;
//    VC_2_parameter.queue_semaphore =        &QUEUE_SEM;
//    VC_2_parameter.output_id =              PWM_2;
}


extern void reset_all()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    // Reset tasks
    vTaskDelete(&PC_PID1_handle);
    vTaskDelete(&VC_PID1_handle);
    vTaskDelete(&PC_PID2_handle);
    vTaskDelete(&VC_PID2_handle);

    // Reset queues
    xQueueReset(SPI_queue);

    // Reset buffers
    control_1_pos = 0;
    control_1_vel = 0;
    control_1_cur = 0;
    control_2_pos = 0;
    control_2_vel = 0;
    control_2_cur = 0;

    control_1_pos_ref = 0;
    control_1_vel_ref = 0;
    control_1_cur_ref = 0;
    control_2_pos_ref = 0;
    control_2_vel_ref = 0;
    control_2_cur_ref = 0;

    // Reset semaphores
    vSemaphoreDelete(POS_1_SEM);
    vSemaphoreDelete(VEL_1_SEM);
    vSemaphoreDelete(POS_2_SEM);
    vSemaphoreDelete(VEL_2_SEM);

    vSemaphoreDelete(POS_1_REF_SEM);
    vSemaphoreDelete(VEL_1_REF_SEM);
    vSemaphoreDelete(POS_2_REF_SEM);
    vSemaphoreDelete(VEL_2_REF_SEM);

    vSemaphoreDelete(SPI_EOT_SEM);
    vSemaphoreDelete(QUEUE_SEM);
    vSemaphoreDelete(UART_RECEIVE_SEM);

    // Initialize again
    init_sem();
    init_queue();

    xTaskCreate(PID_PC_task, "Position controller 1", 100, &PC_1_parameter, 8, &PC_PID1_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 1", 100, &VC_1_parameter, 8, &VC_PID1_handle);
    xTaskCreate(PID_PC_task, "Position controller 2", 100, &PC_2_parameter, 8, &PC_PID2_handle);
    xTaskCreate(PID_VC_task, "Velocity controller 2", 100, &VC_2_parameter, 8, &VC_PID2_handle);

    uint8_t empty = 4;
    xTaskCreate(SPI_task, "SPI module", 100, &empty, 1, &SPI_handle);

    while( !uart0_tx_rdy() )
    {
        ;
    }
    uart0_putc( 'p' );
}

