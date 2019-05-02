
/***************************** Include files *******************************/
#include "tm4c123gh6pm.h"
#include "EMP_type.h"
#include "SPI.h"
#include "PID_freeRTOS.h"
#include "defines.h"
#include "uart_protocol.h"
#include "uart0.h"
#include "setup.h"

/*****************************    Defines    *******************************/

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

volatile uint8_t UITaskCommandReady         = UI_COMMAND_READY;
volatile uint8_t *first_byte_from_queue_ptr = 0;
volatile uint8_t *receive_character         = 0;
volatile uint8_t *byte_from_UART_queue      = 0;
volatile uint8_t first_byte_from_queue      = 0;

/****************************    Semaphores    ***************************/
SemaphoreHandle_t POS_1_SEM;
SemaphoreHandle_t VEL_1_SEM;
SemaphoreHandle_t CUR_1_SEM;
SemaphoreHandle_t POS_2_SEM;
SemaphoreHandle_t VEL_2_SEM;
SemaphoreHandle_t CUR_2_SEM;

SemaphoreHandle_t POS_1_REF_SEM;
SemaphoreHandle_t VEL_1_REF_SEM;
SemaphoreHandle_t CUR_1_REF_SEM;
SemaphoreHandle_t POS_2_REF_SEM;
SemaphoreHandle_t VEL_2_REF_SEM;
SemaphoreHandle_t CUR_2_REF_SEM;

SemaphoreHandle_t SPI_EOT_SEM;

SemaphoreHandle_t QUEUE_SEM;
/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/

void UARTDriverTask (void * pvParameters)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        if (uart0_rx_rdy())
        {
            receive_character = uart0_getc();
            xQueueSend(xUARTReceive_queue,  &receive_character, (TickType_t) 0); //(void *)
        }
        while( !uart0_tx_rdy() ){       ;       }
            uart0_putc( 'k' );

        vTaskDelayUntil (&xLastWakeTime, pdMS_TO_TICKS( 50 ) );
        //vTaskDelay(pdMS_TO_TICKS( 50 ));
    }
}

void UITask( void * pvParameters)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{

//    TickType_t xLastWakeTime;
//    xLastWakeTime = xTaskGetTickCount();
    struct SPI_queue_element SPI_protocol_struct;
    for (;;)
    {
        if (UITaskCommandReady)
        {
            xQueueReceive( xUARTReceive_queue, &first_byte_from_queue_ptr , ( TickType_t ) portMAX_DELAY );
            first_byte_from_queue = first_byte_from_queue_ptr;
        }

        UBaseType_t UARTMessagesWaiting = uxQueueMessagesWaiting(xUARTReceive_queue);
        switch ( first_byte_from_queue - 48 )
        {
            case (RESET_COMMAND):
                UITaskCommandReady = UI_COMMAND_READY;
                //GPIO_PORTF_DATA_R ^= 0x02; // Debug

                reset_all();

                SPI_protocol_struct.id = PROTOCOL_SLAVE;
                SPI_protocol_struct.data = 0x00CC;
                xQueueSend( SPI_queue, (void *) &SPI_protocol_struct, 0);

                break;

            case (HOME_MOTOR_COMMAND):
                if (UARTMessagesWaiting >= 1)
                {
                    UITaskCommandReady = UI_COMMAND_READY;
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    //GPIO_PORTF_DATA_R ^= 0x04; // Debug
                    if( byte_from_UART_queue == 0 )
                    {
                        if( xSemaphoreTake( POS_1_REF_SEM, portMAX_DELAY ) == pdTRUE )
                        {
                            control_1_pos_ref = 0;
                            xSemaphoreGive(POS_1_REF_SEM);
                        }
                    }
                    else if( byte_from_UART_queue == 1 )
                    {
                        if( xSemaphoreTake( POS_2_REF_SEM, portMAX_DELAY ) == pdTRUE )
                        {
                            control_2_pos_ref = 0;
                            xSemaphoreGive(POS_2_REF_SEM);
                        }
                    }
                } else {
                    UITaskCommandReady = UI_WAITING_FOR_COMMAND;
                    vTaskDelay( pdMS_TO_TICKS( 3000 ) );
                }


                break;

            case (INCREMENT_MOTOR_COMMAND): //Vent til sidst
                if (UARTMessagesWaiting >= 2)
                {
                   UITaskCommandReady = UI_COMMAND_READY;
                   xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                   xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                   // GPIO_PORTF_DATA_R ^= 0x08; // Debug
                   // DO stuff
                } else {
                    UITaskCommandReady = UI_WAITING_FOR_COMMAND;
                    vTaskDelay( pdMS_TO_TICKS( 3000 ) );
                }
                break;

            case (GO_TO_POSITION_COMMAND):
                if (UARTMessagesWaiting >= 5)
                {
                    UITaskCommandReady = UI_COMMAND_READY;
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    xQueueReceive( xUARTReceive_queue, &byte_from_UART_queue , ( TickType_t ) 0 );
                    GPIO_PORTF_DATA_R ^= 0x02;
                } else {
                    UITaskCommandReady = UI_WAITING_FOR_COMMAND;
                    vTaskDelay( pdMS_TO_TICKS( 3000 ) );
                }
                break;

            case (ABORT_COMMAND):
                UITaskCommandReady = UI_COMMAND_READY;
                break;

            default:

                break;
        }








        //vTaskDelayUntil (&xLastWakeTime, pdMS_TO_TICKS( 1000 ) );
//        vTaskDelay( pdMS_TO_TICKS( 3000 ) );
    }
}




