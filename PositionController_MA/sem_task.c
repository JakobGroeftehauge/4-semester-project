/*
 * sem_task.c
 *
 *  Created on: 15 Apr 2019
 *      Author: Mads
 */
#include "emp_type.h"
#include "rtcs.h"
#include "tm4c123gh6pm.h"
#include "tmodel.h"
#include "sem_task.h"

static uint8_t send_data = 65;

extern void signaling_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{


    wait(100);

    //GPIO_PORTF_DATA_R ^=0x02;
    if (event == EVENT_TIMEOUT)
    {
    //put_queue( Q_SPI_POS, send_data, WAIT_FOREVER );
    signal(SEM_MAK);
    send_data ++;
    }
    return;
}


extern void waiting_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
//    if(wait_sem(SEM_MAK,WAIT_FOREVER))
//    {
//        uart0_putc('K');
//        GPIO_PORTF_DATA_R ^=0x04;
//    }
    if (event == EVENT_SIGNAL)
    {
//        if (get_queue( Q_SPI_POS, &send_data, WAIT_FOREVER )) // ser ud til at denne wait'er på en semaphor
        {
            uart0_putc(send_data);
        }
    }
    //GPIO_PORTF_DATA_R ^=0x04;
    wait_sem(SEM_MAK,WAIT_FOREVER);
}




