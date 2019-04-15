
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "gpio.h"
#include "systick.h"
#include "swtimers.h"
#include "tmodel.h"
#include "rtcs.h"
#include "SPI.h"
#include "uart.h"
#include "test.h"
#include "PID_MA.h"
#include "sem_task.h"


int main(void)
/*****************************************************************************
*   Input    : NONE
*   Output   : Returns 0
*   Function : Init hardware and then loop forever
******************************************************************************/
{

  //INT8U event;
  //INT8U counter_value;

  disable_global_int();

  init_systick();
  init_gpio();
  init_PIDs();
  uart0_init( 9600, 8, 1, 0 );
  SPI_init();


  enable_global_int();

  init_rtcs();

  open_queue(Q_SPI_POS);

  start_task(TASK_SIGNAL, signaling_task);
  start_task(TASK_WAIT, waiting_task);



  schedule();


  return( 0 );
}
