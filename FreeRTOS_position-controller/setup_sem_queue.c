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

    POS_1_SET_SEM = xSemaphoreCreateBinary();
    VEL_1_SET_SEM = xSemaphoreCreateBinary();
    CUR_1_SET_SEM = xSemaphoreCreateBinary();
    POS_2_SET_SEM = xSemaphoreCreateBinary();
    VEL_2_SET_SEM = xSemaphoreCreateBinary();
    CUR_2_SET_SEM = xSemaphoreCreateBinary();

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






