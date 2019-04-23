
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
  init_rtcs();
  init_gpio();
  init_PIDs();
  uart0_init( 9600, 8, 1, 0 );
  SPI_init();

  enable_global_int();


  while( !uart0_tx_rdy() ){}
  uart0_putc('k');

  send_byte( 0x00AA, 8 );
  int data = receive_byte();
  send_byte( 0x00CC, 8 );
  data = receive_byte();

  open_queue(Q_SPI_POS);
  open_queue(Q_SPI_PWM);


  start_task(TASK_SPI_POS, SPI_POS_task);
  start_task(TASK_SPI_PWM, SPI_PWM_task);

  //start_task(TASK_TEST, test_task);
  start_task(TASK_PID_PC, PID_task);

  schedule();


  return( 0 );
}
