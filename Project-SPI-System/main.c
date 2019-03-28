#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "gpio.h"
#include "systick.h"
#include "swtimers.h"
#include "tmodel.h"
#include "systick.h"
#include "rtcs.h"
#include "SPI.h"




int main(void)
/*****************************************************************************
*   Input    : NONE
*   Output   : Returns 0
*   Function : Init hardware and then loop forever
******************************************************************************/
{
  INT8U event;
  INT8U counter_value;

  disable_global_int();
  init_systick();
  init_gpio();
  enable_global_int();

  SPI_init();


  start_task(TASK_SPI, SPI_task);

  return( 0 );
}
