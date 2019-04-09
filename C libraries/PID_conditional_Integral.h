/*****************************************************************************
 * MODULENAME.: PID_controller_Integral.h
 *
 * PROJECT....: 4. semester project
 *
 * DESCRIPTION: implementation of PID controller
 *
 * Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190408  JGR    Module created.
* 190409  PC	 Revised, comments added
*
*****************************************************************************/


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
 
} PID_controller;

//extern void init_PID_filter(PID_controller);

extern float run_PID(float feedback, float setpoint, PID_controller* PID);
/*****************************************************************************
*   Input    : Sampled data, setpoint, specific controller
*   Output   : Regulated signal
*   Function : PID controller
******************************************************************************/


#endif /* PID_H_ */
