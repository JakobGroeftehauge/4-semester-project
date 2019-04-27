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

/*****************************    Defines    *******************************/
#define POS_1           0
#define VEL_1           1
#define CUR_1           2
#define PWM_1           3
#define POS_2           4
#define VEL_2           5
#define CUR_2           6
#define PWM_2           7
#define PROTOCOL_SLAVE  8


/********************** External declaration of Variables ******************/
extern int16_t control_1_pos;
extern int16_t control_1_vel;
extern int16_t control_1_cur;
extern int16_t control_2_pos;
extern int16_t control_2_vel;
extern int16_t control_2_cur;

extern int16_t control_1_pos_ref;
extern int16_t control_1_vel_ref;
extern int16_t control_1_cur_ref;
extern int16_t control_2_pos_ref;
extern int16_t control_2_vel_ref;
extern int16_t control_2_cur_ref;

extern int16_t glob_protocol;

/*****************************     Structs     ****************************/
typedef struct PID_parameter {
    uint8_t id;
    uint8_t slave_id;
    int16_t *place_to_store_output;
    SemaphoreHandle_t *output_semaphore;
    float  *reference_signal;
    SemaphoreHandle_t *reference_semaphore;
    float  *feedback_signal;
    SemaphoreHandle_t *feedback_semaphore;
    uint16_t delayTime;
    SemaphoreHandle_t *queue_semaphore;
    uint8_t output_id;
} ;

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

SemaphoreHandle_t QUEUE_SEM;

/*****************************     Tasks     ****************************/
extern TaskHandle_t PC_PID1_handle;
extern TaskHandle_t PC_PID2_handle;
extern TaskHandle_t VC_PID1_handle;
extern TaskHandle_t VC_PID2_handle;

extern TaskHandle_t SPI_handle;
extern TaskHandle_t adjust_values_handle;

#endif /* DEFINES_H_ */
