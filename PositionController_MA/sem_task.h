/*
 * sem_task.h
 *
 *  Created on: 15 Apr 2019
 *      Author: Mads
 */

#ifndef SEM_TASK_H_
#define SEM_TASK_H_

extern void signaling_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data);
extern void waiting_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data);


#endif /* SEM_TASK_H_ */
