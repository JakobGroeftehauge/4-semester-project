/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: emp.h
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
* 050128  KA    Module created.
*
*****************************************************************************/

#ifndef SPI_H_
#define SPI_H_
/***************************** Include files *******************************/
#include "tm4c123gh6pm.h"
#include "EMP_type.h"

/*****************************    Defines    *******************************/

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/

extern void SPI_init(void);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : SPI initation
******************************************************************************/

extern void SPI_task(INT8U, INT8U, INT8U, INT8U);


extern void data_transmit(INT8U data);
/*****************************************************************************
*   Input    :Byte that needs to be send
*   Output   :
*   Function :Sends the data given and waits until the transmission is complete.
******************************************************************************/

extern void send_byte_task(INT8U, INT8U);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : SPI initation
******************************************************************************/


#endif /* SPI_H_ */
