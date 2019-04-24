/*****************************************************************************
 * MODULENAME.: PID_FreeRTOS.c
 *
 * PROJECT....: 4. semester project
 *
 * Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190423  JGR    Module created.
*
*****************************************************************************/
#include "PID_FreeRTOS.h"
#include "filter.h"
#include "tmodel.h"
#include "FPGA_comp.h"
#include "SPI.h"
#include "FreeRTOS.h"
#include "defines.h"



/*****************************    Defines    *******************************/
#define NOF_PIDS     2


/*****************************   Variables   *******************************/
PID_controller PID_pool[NOF_PIDS];
//volatile INT16S pwm_var;
//volatile INT16S pos_var;
//extern volatile float controlSignal;
//extern volatile float feedback;
//extern volatile int16_t output_PC1;

extern void PID_task( void * pvParameters)
/*****************************************************************************
*   Function : PID controller task
******************************************************************************/
{
	for(;;)
	{
		float result_PID; 
		uint32_t passedValue;
		float    passedValue_float = *((float*) passedValue);
		PID_parameter controller_parameter = *((PID_parameter *) pvParameters);

		xTaskNotifyWait(0x00, 0xffffffff, &passedValue, portMAX_DELAY);


		//if(ulTaskNotifyTake(pdTRUE, portMAX_DELAY) == pdTRUE)
		//{
			result_PID = run_PID(passedValue_float, *controller_parameter.control_signal, controller_parameter.id);
			*controller_parameter.place_to_store_output = voltage_to_duty_cycle(result_PID);
		//}
	}
	

}


extern void init_PIDs()
/*****************************************************************************
*   Function : Initialize all the PID controllers
******************************************************************************/
{
    //Setup of the Current Controller
    PID_pool[CC_CONTROLLER_ID].Kp = 1;
    PID_pool[CC_CONTROLLER_ID].Kd = 0.01;
    PID_pool[CC_CONTROLLER_ID].Ki = 5;
    PID_pool[CC_CONTROLLER_ID].dt = 0.005;
    PID_pool[CC_CONTROLLER_ID].integral = 0;
    PID_pool[CC_CONTROLLER_ID].previous_error = 0;
    PID_pool[CC_CONTROLLER_ID].upper_sat = 12;
    PID_pool[CC_CONTROLLER_ID].lower_sat = -12;
    PID_pool[CC_CONTROLLER_ID].filter_id = CC_CONTROLLER_ID;
    PID_pool[CC_CONTROLLER_ID].pastError = 0;
    PID_pool[CC_CONTROLLER_ID].Ud = 0;
    PID_pool[CC_CONTROLLER_ID].sat_flag = 0;
    float CC_Filter_Coef[MAX_NUMBER_OF_TABS] = {0.0249, 0.9502, 0.0249, 1, 1, 1, 1, 1, 1, 1};
    init_filter(CC_CONTROLLER_ID, CC_Filter_Coef, 2);
    

    //SETUP FILTER

    //Setup of the Velocity Controller


    //Setup of the Position controller

}

extern float run_PID(float feedback, float setpoint, uint8_t id) // CHANGE TO PID_ID instead of PID_controller
/*****************************************************************************
*   Input    : Sampled data, setpoint, controller id
*   Output   : Regulated signal
*   Function : PID controller
******************************************************************************/
{
    // see powerpoint, Control engineering course: lesson 8, for implementation of discrete PID.

   float error;
   float output;
   float T = PID_pool[id].dt;
   float static integral_term;

   error = setpoint - feedback;

   error = run_filter(PID_pool[id].filter_id, error);

    // calculate the proportional and derivative terms
   float proportional_term  = PID_pool[id].Kp*error;
   float derivative_term = PID_pool[id].Kd*2/T*(error - PID_pool[id].previous_error);// - PID_pool[id].Ud;


// integral is only given a value if the controller is not in saturation
   if (PID_pool[id].sat_flag)
   {
       integral_term = 0;
   }
   else
   {
       integral_term = PID_pool[id].integral + PID_pool[id].Ki*T/2*(error + PID_pool[id].previous_error);
   }


   output = proportional_term + integral_term + derivative_term;

   PID_pool[id].integral = integral_term;
   PID_pool[id].Ud = derivative_term;
   PID_pool[id].previous_error = error;

    // check for saturation for next run through and set flag
   if (output > PID_pool[id].upper_sat)
   {
       output = PID_pool[id].upper_sat;
       PID_pool[id].sat_flag = 1;
   }
   else if (output < PID_pool[id].lower_sat)
   {
       output = PID_pool[id].lower_sat;
       PID_pool[id].sat_flag = 1;
   }
   else
   {
       PID_pool[id].sat_flag = 0;
   }

   return output;

}
