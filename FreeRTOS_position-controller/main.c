/***************************** Include files *******************************/

/* Standard includes. */
#include <setup.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "EMP_type.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "defines.h"
/* Hardware includes. */
//#include "hardware_tm4c123g.h" // Requires TivaWare library
//#include "systick_frt.h"    // From Mortens Lessons
#include "tm4c123gh6pm.h"
#include "gpio.h"

/* Task includes */
#include "SPI.h"
#include "PID_FreeRTOS.h"
#include "uart_protocol.h"

/* Tiva includes */
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"



/*****************************    Defines    *******************************/
//#define USERTASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3

/*****************************   Constants   *******************************/


/*****************************   Variables   *******************************/
//volatile INT16S pwm_var;
//volatile INT16S pos_var;
//
struct PID_parameter PC_1_parameter;
struct PID_parameter VC_1_parameter;
struct PID_parameter PC_2_parameter;
struct PID_parameter VC_2_parameter;

float globalPIDref;
//
//volatile float control_signal_PC1;
//volatile float control_signal_PC2;
//
//volatile float feedback;
//volatile int16_t output_PC1;
//volatile int16_t output_PC2;
//float control_1_pos_ref;


/*****************************   Functions   *******************************/

void delayMS(int ms) {
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}


void QEI_init()
{
    SYSCTL_RCGCQEI_R |= 0x01;       // QEI run mode clock gating control on
       SYSCTL_RCGCGPIO_R |= 0x08;      //Enable clock for PORTD

       GPIO_PORTD_LOCK_R = 0x4C4F434B; //Unlock port D for changes
       GPIO_PORTD_CR_R |= 0xC8;        // Allow changes to PD3,6,7
     GPIO_PORTD_AMSEL_R &= 0x00;           // Disable analog function
       GPIO_PORTD_DEN_R |= 0xC8;       // Enable Digital Pins
       GPIO_PORTD_DIR_R &= ~0xC8;  // Configure direction of pins as Input
       GPIO_PORTD_AFSEL_R |= 0xC8;     // QEI alternate function on PD3,6,7
     GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FF0FFF)+0x66006000;
       // Set PCTL Register PMC7, PMC6, PMC3 to 0x06

       //NVIC_PRI3_R = (NVIC_PRI3_R&0xFFFF1FFF)|0xA000; //QEI 0 Interrupt priority set to 5
       //NVIC_EN0_R |= 0x2000;                          //Enable QEI 0 Interrupt

       QEI0_CTL_R |= 0x38;
       //Velocity Capture on, Reset on index pulse, both edges of A and B signals are counted -> pulses/rev = 4096
       QEI0_INTEN_R |= 0x08;             //Enable the Phase error interrupt
       QEI0_LOAD_R = 500000; //0x00001387;         //Velocity timer value 5000 - 1 (Speed is determined by counting the number of pulses in this amount of time.
       QEI0_MAXPOS_R = 65536-1; //((1024 * 4) - 1); //Maximum Position Value
       QEI0_CTL_R |= 0x01;
}


int main(void)
{
//    uart0_init(9600, 8, 1, 0);
    init_gpio();
    //SPI_init();
    init_sem();
    init_queue();
    init_PIDs();
    init_parameters();
    init_PWM();
    QEI_init();

    bool fadeUp = true;
    unsigned long increment = 10;
    unsigned long pwmNow = 100;
//    while(1)
//    {
//        delayMS(20);
//        if (fadeUp) {
//            pwmNow += increment;
//            if (pwmNow >= 1599) { fadeUp = false; }
//        }
//        else {
//            pwmNow -= increment;
//            if (pwmNow <= 10) { fadeUp = true; }
//        }
//        //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pwmNow);
//        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);
//        //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,pwmNow);
//    }

//    GPIO_PORTC_DATA_R |= (1 << 6);
//    GPIO_PORTC_DATA_R &= ~(1 << 5);
//    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3,1300);
//
//    delayMS(2000);
//
//    GPIO_PORTC_DATA_R &= ~(1 << 6);
//    GPIO_PORTC_DATA_R |= (1 << 5);
//
//    delayMS(2000);
//
//    GPIO_PORTC_DATA_R &= ~(1 << 5);
//    GPIO_PORTC_DATA_R |= (1 << 6);
//    while(1){};

    xUARTReceive_queue = xQueueCreate(15, 8);


    // Create tasks
    // -------------------
    //xTaskCreate(PID_PC_task, "Position controller 1", 100, &PC_1_parameter, 3, &PC_PID1_handle);
    //xTaskCreate(PID_VC_task, "Velocity controller 1", 100, &VC_1_parameter, 4, &VC_PID1_handle);
    //xTaskCreate(PID_PC_task, "Position controller 2", 100, &PC_2_parameter, 3, &PC_PID2_handle);
    //xTaskCreate(PID_VC_task, "Velocity controller 2", 100, &VC_2_parameter, 5, &VC_PID2_handle);
    xTaskCreate(PID_task, "Demo PID task", 100, NULL, 3, NULL);

    //send_data( 0x00CC, 8);

    //xTaskCreate(UARTDriverTask, "Get from UART queue", 100, NULL, 1, &UART_driver_task_handle);
    //xTaskCreate(UITask, "UI", 100, NULL, 1, &UI_task_handle);
    //xTaskCreate(SPI_task, "SPI module", 100, NULL, 8, &SPI_handle);

    //control_1_pos_ref = 0;//2*3*3.14;
    //control_2_pos_ref = 0;
    //control_2_pos_ref = 30;
    //control_1_vel_ref = 20.5;
    globalPIDref = 0;

    //control_1_vel_ref = 30;

    // Start the scheduler.
    // --------------------
    GPIO_PORTF_DATA_R = 0x02;
    vTaskStartScheduler();


    // Will only get here, if there was insufficient memory.
    // -----------------------------------------------------
    return 0;
}
