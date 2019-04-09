/*****************************************************************************
 * MODULENAME.: PID_conditional_Integral.c
 *
 * PROJECT....: 4. semester project
 *
 * Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190408  JGR    Module created.
* 190409  PC	 Revised.
*
*****************************************************************************/
#include "PID.h"

extern float run_PID(float feedback, float setpoint, PID_controller* PID)
{
    // see powerpoint, Control engineering course: lesson 8, for implementation of discrete PID.

   float error;
   float output;
   float TempIntegral = 0;	// Most recent integral
   static float integral = 0; //Previous integral
   static float pastError = 0;
   static float Ud = 0; //Previous control signal for the derivative term



   error = setpoint - feedback;
   TempIntegral = integral + (error + pastError)*((PID->Ti/PID->Kp*PID->dt)/2); //Calculates the integral 

   output = PID->Kp * error + TempIntegral + (PID->Kp*PID->Td*2)/PID->dt * (pastError-error) - Ud;
   //		P controller	--	I controller --	D controller

   // Implementation of conditional integration (Maybe change to back-calculation)
   if ((PID->lower_sat > output) || (output > PID->upper_sat)) //Anti-windub
   {
       output = PID->Kp * error + (PID->Kp*PID->Td*2)/PID->dt * (pastError-error) - Ud;
	   //Integral term is excluded
   }
   else
   {
       integral = TempIntegral;
   }

   Ud = (PID->Td*PID->Kp*2)/PID->dt * (pastError-error) - Ud; //Calculates the new derivative term
   pastError = error;

   return output;
}



