/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: uart.h
*
* PROJECT....: EMP
*
* DESCRIPTION: Test.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 150228  MoH   Module created.
*
*****************************************************************************/

#ifndef _UART_H
  #define _UART_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/

void uart_tx_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data);
void uart_rx_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data);
BOOLEAN uart0_rx_rdy();
INT8U uart0_getc();
BOOLEAN uart0_tx_rdy();
void uart0_putc( INT8U ch );
INT32U lcrh_databits( INT8U antal_databits );
INT32U lcrh_stopbits( INT8U antal_stopbits );
INT32U lcrh_parity( INT8U parity );
void uart0_fifos_enable();
void uart0_fifos_disable();

extern void uart0_init( INT32U, INT8U, INT8U, INT8U );
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize uart 0
******************************************************************************/


/****************************** End Of Module *******************************/
#endif

