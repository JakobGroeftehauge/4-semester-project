/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: tmodel.h
*
* PROJECT....: ECP
*
* DESCRIPTION: Defines the elemtn of the task model..
*
* Change Log:
******************************************************************************

* TMODEL: Defines of tasks, software timers, queues and semaphore all in
*         regard to SPI
*****************************************************************************/

#ifndef _TMODEL_H_
#define _TMODEL_H_

#include "rtcs.h"

// Tasks.
// ------
#define TASK_SW_TIMERS   USER_TASK
#define TASK_MAIN        USER_TASK+1
#define TASK_SPI         USER_TASK+2
#define TASK_TEST        USER_TASK+3
#define TASK_PID_PC      USER_TASK+4
#define TASK_SIGNAL      USER_TASK+5
#define TASK_WAIT        USER_TASK+6


// Interrupt Service Routines.
// ---------------------------
#define ISR_TIMER 21

// Shared State Memory.
// --------------------
//#define SSM_POS      31


// Shared Event Buffers.
// ---------------------
//#define SEB_POS      41


// Semaphores
// ----------
#define SEM_OUTPINS       USER_SEM
#define SEM_POS_UPDATE    USER_SEM+1
#define SEM_PWM_UPDATE    USER_SEM+2
#define SEM_MAK           USER_SEM+3

// QUEUEs.
// -------
#define Q_SPI_REQUEST     USER_QUEUE
#define Q_SPI_OUT         USER_QUEUE+1
#define Q_SPI_POS         USER_QUEUE+2
#define Q_SPI_PWM         USER_QUEUE+3



#endif /* _TMODEL_H_ */
