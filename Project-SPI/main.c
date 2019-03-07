

/**
 * main.c
 */
/**************************************************************************************************************************
 * Includes :
**************************************************************************************************************************/

#include "tm4c123gh6pm.h"
#include "SPI.h"
#include <stdint.h>

/**************************************************************************************************************************
 * Global varibels :
**************************************************************************************************************************/

/**************************************************************************************************************************
 * Definitions :
**************************************************************************************************************************/

/**************************************************************************************************************************
 * Function of program :
 *
 *
**************************************************************************************************************************/

void delay();
void led_init();

int main(void)
{

    led_init();

    SPI_init();
int i = 1;
uint16_t send_data;
uint16_t read_data;
    while (1)

    {

        if(!(GPIO_PORTF_DATA_R&0x10))
        {

           while (!(GPIO_PORTF_DATA_R&0x10))
           {
               ;
           }

           send_data = 0x1111;

           send_byte(send_data);

           delay();

           read_data = SSI0_DR_R;

           send_byte(send_data);

           delay();
           //GPIO_PORTF_DATA_R = 0x2;
           while (1)
           {

           read_data = SSI0_DR_R;

           send_byte(read_data);

           delay();

           }

          // send_byte(read_data);
//
//           send_data = 0x0D;
//
//           send_byte(send_data);
        }

    }
    return 0;
}

void delay()
{
    int i;
    int j;
    for(i = 0; i<0xF0; i++)
    {
//        for(j = 0; j<0xFF; j++)
//            {
//                ;
//            }
    }
}

void led_init()
{
    int dummy;
    //Enable the GPIO port that is used for the on-board LEDs and swithces.
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // Do a dummy read to insert a few cycles after enabling the peripheral.

    dummy = SYSCTL_RCGC2_R;
    // Set the direction as out - put (PF1-PF3)

    GPIO_PORTF_DIR_R = 0x0E;

    //Enable the GPIO pins for digital function (PF1 - PF4)
    GPIO_PORTF_DEN_R = 0x1E;

    //Enable internal pull-up (PF4)
    GPIO_PORTF_PUR_R = 0x10;
}
