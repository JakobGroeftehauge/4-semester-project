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

#ifndef _EMP_H
  #define _EMP_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/
extern volatile INT16S ticks;

/*****************************   Constants   *******************************/


/*****************************   Functions   *******************************/
void enable_global_int();
void disable_global_int();
void init_systick();
void systick_handler();
extern void test2(void);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/


/****************************** End Of Module *******************************/
#endif

