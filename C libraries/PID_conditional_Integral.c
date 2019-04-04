/*
 * PID.c
 *
 *  Created on: Mar 21, 2019
 *      Author: Jakob
 */
#include "PID.h"

extern float run_PID(float feedback, float setpoint, PID_controller* PID)
{
    // see powerpoint, Control engineering course: lesson 8, for implementation of discrete PID.

   float error;
   float output;
   float TempIntegral = 0;
   static float integral = 0;
   static float pastError = 0;
   static float Ud = 0;



   error = setpoint - feedback;
   TempIntegral = integral + (error + pastError)*((PID->Ti/PID->Kp*PID->dt)/2);

   output = PID->Kp * error + TempIntegral + (PID->Kp*PID->Td*2)/PID->dt * (pastError-error) - Ud;

   // Implementation of conditional integration (Maybe change to back-calculation)
   if ((PID->lower_sat > output) || (output > PID->upper_sat)) //forkert
   {
       output = PID->Kp * error + (PID->Kp*PID->Td*2)/PID->dt * (pastError-error) - Ud;
   }
   else
   {
       integral = TempIntegral;
   }

   Ud = (PID->Td*PID->Kp*2)/PID->dt * (pastError-error) - Ud;
   pastError = error;

   return output;
}



