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
* 190409  PC     Revised.
*
*****************************************************************************/
#include "PID_MA.h"
#include "filter.h"
#include "rtcs.h"
#include "tmodel.h"
#include "FPGA_comp.h"
#include "SPI.h"



/*****************************    Defines    *******************************/
#define NOF_PIDS     1


/*****************************   Variables   *******************************/
PID_controller PID_pool[NOF_PIDS];
volatile INT16S pwm_var;
volatile INT16S pos_var;


extern void PID_task(uint8_t id, uint8_t state, uint8_t event, uint8_t data)
/*****************************************************************************
*   Function : PID controller task
******************************************************************************/
{
   float referencePoint = 10;
   float feedback;

   int16_t result_to_send;


        feedback = pos_var;
        feedback = 9.9;
        float result_PID = run_PID(feedback, referencePoint, CC_CONTROLLER_ID);
        result_PID *= 100;
        result_to_send = (int16_t) voltage_to_duty_cycle(result_PID);
        //result_to_send *= 85;

//       INT8U data_LOW = pos_var & 0xFF;
//       INT8U data_HIGH = (pos_var >> 8);
//       while( !uart0_tx_rdy() )
//       {}
//       uart0_putc(data_LOW);
        pwm_var = result_PID;


        signal( SEM_PWM_UPDATE );
   }

}


extern void init_PIDs()
/*****************************************************************************
*   Function : Initialize all the PID controllers
******************************************************************************/
{
    //Setup of the Current Controller
    PID_pool[CC_CONTROLLER_ID].Kp = 1;
    PID_pool[CC_CONTROLLER_ID].Kd = 1;
    PID_pool[CC_CONTROLLER_ID].Ki = 1;
    PID_pool[CC_CONTROLLER_ID].dt = 0.1;
    PID_pool[CC_CONTROLLER_ID].integral = 0;
    PID_pool[CC_CONTROLLER_ID].previous_error = 0;
    PID_pool[CC_CONTROLLER_ID].upper_sat = 10;
    PID_pool[CC_CONTROLLER_ID].lower_sat = -10;
    PID_pool[CC_CONTROLLER_ID].filter_id = CC_CONTROLLER_ID;
    PID_pool[CC_CONTROLLER_ID].pastError = 0;
    PID_pool[CC_CONTROLLER_ID].Ud = 0;
    PID_pool[CC_CONTROLLER_ID].sat_flag = 0;
    float CC_Filter_Coef[MAX_NUMBER_OF_TABS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    init_filter(CC_CONTROLLER_ID, CC_Filter_Coef, 3);
    

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
   float integral_term;

    error = setpoint - feedback;

    // calculate the proportional and derivative terms
    float proportional_term  = PID_pool[id].Kp*error;
    float derivative_term = PID_pool[id].Kd*2/T*(error - PID_pool[id].previous_error)-PID_pool[id].Ud;

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
