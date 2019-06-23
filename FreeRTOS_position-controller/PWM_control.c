/*
 * PWM_control.c
 *
 *  Created on: 19. jun. 2019
 *      Author: chris
 */

/***************************** Include files *******************************/
// Standard includes
#include <stdint.h>
#include <stdbool.h>

//Hardware includes
#include "tm4c123gh6pm.h"

//TivaWare includes
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void init_PWM(void)
{
    //Set the clock
    //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    //Configure PWM Clock to match system
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    // Enable the peripherals used by this program.
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins

    //Configure PF1,PF2,PF3 Pins as PWM
    GPIOPinConfigure(GPIO_PA7_M1PWM3);
    //GPIOPinConfigure(GPIO_PF2_M1PWM6);
    //GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);//GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);

    //Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    //PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    //Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 1600);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 1600);

    //Set PWM duty-50% (Period /2)
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3,300);
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
//    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,100);

    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_1);
    //PWMGenEnable(PWM1_BASE, PWM_GEN_3);

    // Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true); //PWM_OUT_5_BIT | PWM_OUT_6_BIT |

    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 1300);

    //Fade

}


