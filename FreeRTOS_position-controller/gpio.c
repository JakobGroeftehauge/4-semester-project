/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "gpio.h"

#include <stdbool.h>
#include <driverlib/sysctl.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void init_gpio(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
  uint8_t dummy;
//
//  // Enable the GPIO port that is used for the on-board LED.
//  SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOD | SYSCTL_RCGC2_GPIOF | SYSCTL_RCGC2_GPIOA;
//
//  // Do a dummy read to insert a few cycles after enabling the peripheral.
//  dummy = SYSCTL_RCGC2_R;
//
//  /*PORT F setup*/
//  GPIO_PORTF_LOCK_R = 0x4C4F434B;  // Unlock the CR register
//  GPIO_PORTF_CR_R   = 0xFF;        // Enable overwrite of PUR to FP0
//
//  // Set the direction as output (PF1, PF2 and PF3).
//  GPIO_PORTF_DIR_R = 0x0E;
//
//  // Enable the GPIO pins for digital function (PF0, PF1, PF2, PF3, PF4).
//  GPIO_PORTF_DEN_R = 0x1F;
//
//  // Enable internal pull-up (PF0 and PF4).
//  GPIO_PORTF_PUR_R = 0x11;
//
//

  // Enable the GPIO port that is used for the on-board LED.
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF | SYSCTL_RCGC2_GPIOD | SYSCTL_RCGC2_GPIOC | SYSCTL_RCGC2_GPIOA;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    dummy = SYSCTL_RCGC2_R;

    // Set the direction as output (PF1, PF2 and PF3).
    GPIO_PORTC_DIR_R = 0xF0;
    GPIO_PORTD_DIR_R = 0x4C;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTA_DIR_R |= 0xD4; //PA2, PA4, PA6 and PA7

    // Enable the GPIO pins for digital function (PF0, PF1, PF2, PF3, PF4).
    GPIO_PORTC_DEN_R = 0xF0;
    GPIO_PORTD_DEN_R = 0x4C;
    GPIO_PORTF_DEN_R = 0x1F;
    GPIO_PORTA_DEN_R |= 0xD4;

    // Enable internal pull-up (PF0 and PF4).
    GPIO_PORTF_PUR_R = 0x11;
//  /*PORT D setup*/
//  // Set the direction as output (PD6).
//  GPIO_PORTD_DIR_R = 0x40;
//
//  // Enable the GPIO pins for digital function (PD6).
//  GPIO_PORTD_DEN_R = 0x40;
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //TivaWare API calls for running the system at 80 Mhz from PLL

}

/****************************** End Of Module *******************************/


