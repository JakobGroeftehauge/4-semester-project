#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "EMP_type.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "PID_FreeRTOS.h"

// Slaves
#define POS_1           0
#define VEL_1           1
#define CUR_1           2
#define PWM_1           3
#define POS_2           4
#define VEL_2           5
#define CUR_2           6
#define PWM_2           7
#define PROTOCOL_SLAVE  8

extern volatile int16_t output_PC1;

typedef volatile struct {
    uint8_t id;
    int16_t *place_to_store_output;
    float  *reference_signal;
    float  *feedback_signal;
    uint16_t delayTime;
} PID_parameter;



PID_parameter PID1_PC;
PID_parameter PID2_PC;
//PID1_PC.id = CC_CONTROLLER_ID;
//PID_PC1.place_to_store_output = &output_PC1;


// Queues
QueueHandle_t SPI_queue;

//Task handles
extern TaskHandle_t PC_PID1_handle;
extern TaskHandle_t PC_PID2_handle;

extern TaskHandle_t SPI_handle;
extern TaskHandle_t adjust_values_handle;



#endif /* DEFINES_H_ */
