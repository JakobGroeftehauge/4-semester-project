#include "FPGA_comp.h"
#include "FreeRTOS.h"
#include "defines.h"
#include "PID_freeRTOS.h"

volatile int16_t control_1_pos;
volatile int16_t control_1_vel;
volatile int16_t control_1_cur;
volatile int16_t control_2_pos;
volatile int16_t control_2_vel;
volatile int16_t control_2_cur;

volatile int16_t control_1_pos_ref;
volatile int16_t control_1_vel_ref;
volatile int16_t control_1_cur_ref;
volatile int16_t control_2_pos_ref;
volatile int16_t control_2_vel_ref;
volatile int16_t control_2_cur_ref;

volatile int16_t glob_protocol;

extern void init_sem()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    POS_1_SEM = xSemaphoreCreateBinary();
    VEL_1_SEM = xSemaphoreCreateBinary();
    CUR_1_SEM = xSemaphoreCreateBinary();
    POS_2_SEM = xSemaphoreCreateBinary();
    VEL_2_SEM = xSemaphoreCreateBinary();
    CUR_2_SEM = xSemaphoreCreateBinary();

    POS_1_REF_SEM = xSemaphoreCreateBinary();
    VEL_1_REF_SEM = xSemaphoreCreateBinary();
    CUR_1_REF_SEM = xSemaphoreCreateBinary();
    POS_2_REF_SEM = xSemaphoreCreateBinary();
    VEL_2_REF_SEM = xSemaphoreCreateBinary();
    CUR_2_REF_SEM = xSemaphoreCreateBinary();

    QUEUE_SEM = xSemaphoreCreateBinary();

}

extern void init_queue()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    SPI_queue = xQueueCreate(100, //Number of elements in queue
                             sizeof( struct SPI_queue_element  ) ); //Number of bytes for each element

}

extern void init_parameters()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
     struct PID_parameter PC_1_parameter =
     {
     PC_CONTROLLER_1_ID,// id
     POS_1,// slave_id
     &control_1_vel_ref, // *place to store output
     &VEL_1_REF_SEM, // *output semaphore
     &control_1_pos_ref, // *reference_signal
     &POS_1_REF_SEM, // *reference_semaphore
     &control_1_pos, // *feedback_signal
     &POS_1_SEM, // *feedback_semaphore
     20, // delay time (ms)
     &QUEUE_SEM, // *queue_semaphore
     0// output id
    };


    struct PID_parameter VC_1_parameter =
    {
     VC_CONTROLLER_1_ID,// id
     VEL_1,// slave_id
     &control_1_vel_ref, // *place to store output (BRUGES IKKE)
     &VEL_1_REF_SEM, // *output semaphore (BRUGES IKKE)
     &control_1_vel_ref, // *reference_signal
     &VEL_1_REF_SEM, // *reference_semaphore
     &control_1_vel, // *feedback_signal
     &VEL_1_SEM, // *feedback_semaphore
     5, // delay time (ms)
     &QUEUE_SEM, // *queue_semaphore
     0// output id
    };

    struct PID_parameter PC_2_parameter =
    {
     PC_CONTROLLER_2_ID,// id
     POS_2,// slave_id
     &control_2_vel_ref, // *place to store output
     &VEL_2_REF_SEM, // *output semaphore
     &control_2_pos_ref, // *reference_signal
     &POS_2_REF_SEM, // *reference_semaphore
     &control_2_pos, // *feedback_signal
     &POS_2_SEM, // *feedback_semaphore
     20, // delay time (ms)
     &QUEUE_SEM, // *queue_semaphore
     0// output id
    };

    struct PID_parameter VC_2_parameter =
    {
     VC_CONTROLLER_2_ID,// id
     VEL_2,             // slave_id
     &control_2_vel_ref, // *place to store output (BRUGES IKKE)
     &VEL_2_REF_SEM, // *output semaphore (BRUGES IKKE)
     &control_2_vel_ref, // *reference_signal
     &VEL_2_REF_SEM, // *reference_semaphore
     &control_2_vel, // *feedback_signal
     &VEL_2_SEM, // *feedback_semaphore
     5, // delay time (ms)
     &QUEUE_SEM, // *queue_semaphore
     0// output id
    };

}




