/*
 * PID.h
 *
 *  Created on: Mar 21, 2019
 *      Author: Jakob
 */


#ifndef PID_H_
#define PID_H_

typedef struct
{
  float Td;
  float Kp;
  float Ti;
  float integral;
  float previous_error;
  float dt;         //stepsize for integral
  float upper_sat;
  float lower_sat;
  //filter
} PID_controller;

//extern void init_PID_filter(PID_controller);

extern float run_PID(float feedback, float setpoint, PID_controller* PID);

extern float run_PLANT(float setpoint, PID_controller* PID);


#endif /* PID_H_ */
