#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "gpio.h"
#include "systick.h"
//#include "swtimers.h"
#include "tmodel.h"
#include "systick.h"


//INT16S alive_timer = MILLISEC(500);

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

  // Loop forever.
  while(1)
  {
	// System part of the super loop.
	// ------------------------------
	while( !ticks );

	// The following will be executed every 5mS
	ticks--;

//	if( ! --alive_timer )
//	{
//      alive_timer =	MILLISEC( 500 );
//	  GPIO_PORTD_DATA_R ^= 0x40;
//	}

    // Protected operating system mode
    swt_ctrl();



  }
  return( 0 );
}
