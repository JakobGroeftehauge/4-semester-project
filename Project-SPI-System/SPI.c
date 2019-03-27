/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: emp.c
*
* PROJECT....: EMP
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
 ****************************************************************************
 Date    Id    Change
* YYMMDD
* --------------------
* 050128  KA    Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include "SPI.h"
#include "EMP_type.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/
void SPI_init(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :Set up the SPI on the microcontroller.
*   Page     : 965
*   *   - Setups the microcontroller as Master.
*   - Uses Port A 5 as MOSI
*   - uses Port A 4 as MISO
*   - Uses Port A 3 as SS (slave select)
*   - Uses Port A 2 as SCK
*   - Uses SSIO0
*
*   Sends 8 bit data - with 250kHz
******************************************************************************/
{
    //To enable and initialize the SSI, the following steps are necessary:

    //Enable the SSI module using theRCGCSSIregister (see page 346)
    SYSCTL_RCGCSSI_R |= (1<<0);        //selecting SSI0 module

    //Enable the clock to the appropriate GPIO module via theRCGCGPIOregister
    //(see page 340).To find out which GPIO port to enable, refer to Table 23-5 on page 1351.
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; //Maybe the right register

    //Set the GPIOAFSELbits for the appropriate pins (see page 671).
    //To determine which GPIOs to configure, see Table 23-4 on page 1344

    GPIO_PORTA_AFSEL_R |= (1<<2)|(1<<3)|(1<<4)|(1<<5);

    // Configure thePMCnfields in theGPIOPCTLregister to assign the SSI
    // signals to the appropriate pins. See page 688 and Table 23-5 on page 135

    GPIO_PORTA_PCTL_R = 0x00222200;

    //Program theGPIODENregister to enable the pin's digital function.
    // In addition, the drive strength,drain select and pull-up/pull-down functions must be configured.
    //Refer to “General-PurposeInput/Outputs (GPIOs)” on page 649 for more information.

    GPIO_PORTA_DEN_R |=(1<<2)|(1<<3)|(1<<4)|(1<<5); //enabling digital mode for PORTA 2,3,4,5

    GPIO_PORTA_PUR_R |=(1<<2)|(1<<3)|(1<<4)|(1<<5); //selecting pull ups for 2,3,4,5


    //Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes.

    SSI0_CR1_R = 0 ;

    // Select whether the SSI is a master or slave
    // For master operations, set the SSICR1 register to 0x0000.0000.

    SSI0_CR1_R = 0 ;

    //Configure the SSI clock source by writing to the SSICC register.

    SSI0_CC_R = 0; //using main system clock

    // Configure the clock prescale divisor by writing the SSICPSR register.

    SSI0_CPSR_R = 64; //selecting divisor 64 for SSI clock
                      // SSInClk = SysClk / (CPSDVSR * (1 + SCR) SCR = 0;

    //Write theSSICR0register with the following configuration
    SSI0_CR0_R |= 0x7; //freescale mode, 8 bit data, steady clock low

    // Enable the SSI by setting theSSEbit in theSSICR1register.
    SSI0_CR1_R |= (1<<1);
}

void send_data(int data)
{
    SSI0_DR_R = data;               //putting the byte to send from SSI
    while (SSI0_SR_R &(1<<0) == 0)  //waiting for transmission to be done
    { ; }

}

void send_byte(int data, int slave_no)
/*****************************************************************************
*   Input    :byte that is being sent by SPI
*   Output   :
*   Function :Sends the data given and waits until the transmission is complete.
*
******************************************************************************/
{
    switch( slave_no )
    {
    case 0:
        GPIO_PORTC_DATA_R &= (0<<7)|(0<<6)|(0<<5)|(0<<4);
        send_data(data);
        break;
    case 1:
        GPIO_PORTC_DATA_R &= (0<<7)|(0<<6)|(0<<5)|(1<<4);
        send_data(data);
        break;
    case 2:
        GPIO_PORTC_DATA_R &= (0<<7)|(0<<6)|(1<<5)|(0<<4);
        send_data(data);
        break;
    case 3:
        GPIO_PORTC_DATA_R &= (0<<7)|(0<<6)|(1<<5)|(1<<4);
        send_data(data);
        break;
    case 4:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(0<<5)|(0<<4);
        send_data(data);
        break;
    case 5:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(0<<5)|(1<<4);
        send_data(data);
        break;
    case 6:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(1<<5)|(0<<4);
        send_data(data);
        break;
    case 7:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(1<<5)|(1<<4);
        send_data(data);
        break;
    case 8:
        GPIO_PORTC_DATA_R &= (1<<7)|(0<<6)|(0<<5)|(0<<4);
        send_data(data);
        break;

    }
}

int receive_byte()
/*****************************************************************************
*   Input    :
*   Output   : The function return the received data.
*   Function : receiving data with SPI
*   // test
*
******************************************************************************/
{
    int data=0;
    int j;
    send_byte(0xFF);
    for(j = 0; j<0xFF; j++)
    {
        ;
    }

    data = SSI0_DR_R;
    GPIO_PORTF_DATA_R = data;
    return data;
}
