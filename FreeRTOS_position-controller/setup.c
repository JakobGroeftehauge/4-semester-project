#include "FPGA_comp.h"
#include "FreeRTOS.h"
#include "defines.h"

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
    static const PID_parameter PC_1_parameter =
    {
     // id
     // slave_id
     // *place to store output
     // *output semaphore
     // *reference_signal
     // *reference_semaphore
     // *feedback_semaphore
     // delay time
     // *queue_semaphore
     // output id
    };


    static const PID_parameter VC_1_parameter =
    {
         // id
         // slave_id
         // *place to store output
         // *output semaphore
         // *reference_signal
         // *reference_semaphore
         // *feedback_semaphore
         // delay time
         // *queue_semaphore
         // output id
    };

    static const PID_parameter PC_2_parameter =
    {
         // id
         // slave_id
         // *place to store output
         // *output semaphore
         // *reference_signal
         // *reference_semaphore
         // *feedback_semaphore
         // delay time
         // *queue_semaphore
         // output id
    };

    static const PID_parameter VC_2_parameter =
    {
         // id
         // slave_id
         // *place to store output
         // *output semaphore
         // *reference_signal
         // *reference_semaphore
         // *feedback_semaphore
         // delay time
         // *queue_semaphore
         // output id
    };

}




