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

// Queues
QueueHandle_t SPI_queue;



#endif /* DEFINES_H_ */
