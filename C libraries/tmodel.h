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


// Interrupt Service Routines.
// ---------------------------
#define ISR_TIMER 21

// Shared State Memory.
// --------------------


//#define SSM_RTC_SEC            31


// Shared Event Buffers.
// ---------------------
//#define SEB_BUTTON_EVENT 41


// Semaphores
// ----------
#define SEM_OUTPINS       USER_SEM


// QUEUEs.
// -------
#define Q_SPI_REQUEST     USER_QUEUE
#define Q_SPI_OUT         USER_QUEUE+1

// Traffic Light Modes.
// --------------------
//#define MM_TLIGHT   1


// Software Timers.
// ----------------
//#define ST_BUTTON   1


#endif /* _TMODEL_H_ */
