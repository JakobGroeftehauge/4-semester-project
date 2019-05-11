#ifndef DEFINES_H_
#define DEFINES_H_

/***************************** Include files *******************************/
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "EMP_type.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "PID_FreeRTOS.h"
#include "uart_protocol.h"

/*****************************    Defines    *******************************/
// Slaves
#define POS_1                   0
#define VEL_1                   1
#define CUR_1                   2
#define PWM_1                   3
#define POS_2                   4
#define VEL_2                   5
#define CUR_2                   6
#define PWM_2                   7
#define PROTOCOL_SLAVE          8

// UART
#define UI_WAITING_FOR_COMMAND  0
#define UI_COMMAND_READY        1

#define RESET_COMMAND           0
#define HOME_MOTOR_COMMAND      1
#define INCREMENT_MOTOR_COMMAND 2
#define GO_TO_POSITION_COMMAND  3
#define ABORT_COMMAND           4
#define MAX_PWM_TILT            5


/********************** External declaration of Variables ******************/
extern float control_1_pos;
extern float control_1_vel;
extern float control_1_cur;
extern float control_2_pos;
extern float control_2_vel;
extern float control_2_cur;

extern float control_1_pos_ref;
extern float control_1_vel_ref;
extern float control_1_cur_ref;
extern float control_2_pos_ref;
extern float control_2_vel_ref;
extern float control_2_cur_ref;

extern int16_t glob_protocol;
extern int16_t global_test;

/*****************************     Structs     ****************************/
typedef struct PID_parameter {
    uint8_t             id;
    uint8_t             slave_id;
    float               *place_to_store_output;
    SemaphoreHandle_t   *output_semaphore;
    float               *reference_signal;
    SemaphoreHandle_t   *reference_semaphore;
    float               *feedback_signal;
    SemaphoreHandle_t   *feedback_semaphore;
    uint16_t            delayTime;
    SemaphoreHandle_t   *queue_semaphore;
    uint8_t             output_id;
};

typedef volatile struct SPI_queue_element {
    uint8_t id;
    int16_t data;
};

/***************************** Struct init  ****************************/
extern struct PID_parameter PC_1_parameter;
extern struct PID_parameter VC_1_parameter;
extern struct PID_parameter PC_2_parameter;
extern struct PID_parameter VC_2_parameter;

/*****************************     Queues     ****************************/
QueueHandle_t SPI_queue;
QueueHandle_t xUARTReceive_queue;

/****************************    Semaphores    ***************************/
extern SemaphoreHandle_t POS_1_SEM;
extern SemaphoreHandle_t VEL_1_SEM;
extern SemaphoreHandle_t POS_2_SEM;
extern SemaphoreHandle_t VEL_2_SEM;


extern SemaphoreHandle_t POS_1_REF_SEM;
extern SemaphoreHandle_t VEL_1_REF_SEM;
extern SemaphoreHandle_t POS_2_REF_SEM;
extern SemaphoreHandle_t VEL_2_REF_SEM;


extern SemaphoreHandle_t SPI_EOT_SEM;
extern SemaphoreHandle_t QUEUE_SEM;
extern SemaphoreHandle_t UART_RECEIVE_SEM;


/*****************************     Tasks     ****************************/
// Controllers
extern TaskHandle_t PC_PID1_handle;
extern TaskHandle_t PC_PID2_handle;
extern TaskHandle_t VC_PID1_handle;
extern TaskHandle_t VC_PID2_handle;

// SPI
extern TaskHandle_t SPI_handle;
extern TaskHandle_t adjust_values_handle;
extern TaskHandle_t SPI_test_handle;

// UART
extern TaskHandle_t UI_task_handle;
extern TaskHandle_t UART_driver_task_handle;
#endif /* DEFINES_H_ */
