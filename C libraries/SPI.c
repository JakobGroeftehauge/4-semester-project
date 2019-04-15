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
#include "tmodel.h"
#include "rtcs.h"
#include "events.h"
#include "uart.h"
/*****************************    Defines    *******************************/

#define POSITION_SLAVE      2
#define PWM_SLAVE           8
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
    SYSCTL_RCGCSSI_R |= (1<<1);        //selecting SSI1 module

    //Enable the clock to the appropriate GPIO module via theRCGCGPIOregister
    //(see page 340).To find out which GPIO port to enable, refer to Table 23-5 on page 1351.
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; //Maybe the right register
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; //Maybe the right register

    //Set the GPIOAFSELbits for the appropriate pins (see page 671).
    //To determine which GPIOs to configure, see Table 23-4 on page 1344

    GPIO_PORTD_AFSEL_R |= (1<<0)|(1<<1)|(1<<2)|(1<<3);
    GPIO_PORTF_AFSEL_R |= (1<<0)|(1<<1)|(1<<2)|(1<<3);

    // Configure thePMCnfields in theGPIOPCTLregister to assign the SSI
    // signals to the appropriate pins. See page 688 and Table 23-5 on page 135

    GPIO_PORTD_PCTL_R |= (2<<0)|(2<<4)|(2<<8)|(2<12);
    GPIO_PORTF_PCTL_R |= (2<<0)|(2<<4)|(2<<8)|(2<12);

    //Program theGPIODENregister to enable the pin's digital function.
    // In addition, the drive strength,drain select and pull-up/pull-down functions must be configured.
    //Refer to “General-PurposeInput/Outputs (GPIOs)” on page 649 for more information.

    GPIO_PORTD_DEN_R |=(1<<1)|(1<<2); //enabling digital mode for PORTD 0,1,2,3

    GPIO_PORTD_PUR_R |=(1<<1)|(1<<2); //selecting pull ups for 0,1,2,3

    GPIO_PORTF_DEN_R |=(1<<0)|(1<<1)|(1<<2); //enabling digital mode for PORTD 0,1,2,3

    GPIO_PORTF_PUR_R |=(1<<0)|(1<<1)|(1<<2); //selecting pull ups for 0,1,2,3

    //Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes.

    SSI1_CR1_R = 0 ;

    // Select whether the SSI is a master or slave
    // For master operations, set the SSICR1 register to 0x0000.0000.

    SSI1_CR1_R = 0 ;

    //Configure the SSI clock source by writing to the SSICC register.

    SSI1_CC_R = 0; //using main system clock

    // Configure the clock prescale divisor by writing the SSICPSR register.

    SSI1_CPSR_R = 64; //selecting divisor 64 for SSI clock
                      // SSInClk = SysClk / (CPSDVSR * (1 + SCR) SCR = 0;

    //Write theSSICR0register with the following configuration
    SSI1_CR0_R |= 0xF|(1<<7); //freescale mode, 16 bit data, steady clock low

    // Enable the SSI by setting theSSEbit in theSSICR1register.
    SSI1_CR1_R |= (1<<1);
}

extern void SPI_task(INT8U my_id, INT8U my_state, INT8U event, INT8U data)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
{
    INT16U PWM_data;
    INT8U static TIMER_PWM = 0;
    INT8U static TIMER_SLAVE = 0;

    //Receive data
        send_byte( 0xFFFF, 3 ); //CHANGE WHICH SLAVE HERE
        receive_byte();

        //Send data
    if( TIMER_PWM >= 15 )
    {
        if( wait_sem( SEM_PWM_UPDATE,1 ) )//Check Semaphore if PWM data is ready
        {
            if( get_queue( Q_SPI_PWM, &PWM_data,1 ) )//Get from queue
            {
                TIMER_PWM = 0;
                send_byte( PWM_data,PWM_SLAVE );
            }
        }
     }
    TIMER_PWM++;




//For test
//------------------------------------
//INT8U static counter = 0;
//    counter++;
//
//    if( counter > 10 ) //Adjust timer here
//    {
//        send_byte( 0xFFFF, 2);
//        receive_byte();
//        counter = 0;
//    }

}

void data_transmit(INT16U data)
/*****************************************************************************
*   Input    :Byte that
*   Output   :
*   Function :Sends the data given and waits until the transmission is complete.
******************************************************************************/
{
    SSI1_DR_R = data;          //putting the byte to send from SSI

    for(int i=0; i<20; i++){}; //Burn few cycles to make sure SS is LOW
    while ( !(GPIO_PORTD_DATA_R & 0b0000010) ) //While SS HIGH make sure slave is also HIGH
    {       ;      }

}

void send_byte(INT16U data, INT8U slave_no)
/*****************************************************************************
*   Input    :byte that is being sent by SPI
*             slave select
*   Output   :
*   Function :Sets up slave select for desired slave, and then sends data given.
******************************************************************************/
{
    switch( slave_no )
    {
    case 0:
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 1:
        GPIO_PORTC_DATA_R &= (1<<7)|(1<<6)|(1<<5)|(0<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 2:
        GPIO_PORTC_DATA_R &= (1<<7)|(1<<6)|(0<<5)|(1<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 3:
        GPIO_PORTC_DATA_R &= (1<<7)|(1<<6)|(0<<5)|(0<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 4:
        GPIO_PORTC_DATA_R &= (1<<7)|(0<<6)|(1<<5)|(1<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 5:
        GPIO_PORTC_DATA_R &= (1<<7)|(0<<6)|(1<<5)|(0<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 6:
        GPIO_PORTC_DATA_R &= (1<<7)|(0<<6)|(0<<5)|(1<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 7:
        GPIO_PORTC_DATA_R &= (1<<7)|(0<<6)|(0<<5)|(0<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 8:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(1<<5)|(1<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    case 9:
        GPIO_PORTC_DATA_R &= (0<<7)|(1<<6)|(1<<5)|(0<<4);
        data_transmit(data);
        GPIO_PORTC_DATA_R |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
        break;
    }
}

void receive_byte()
/*****************************************************************************
*   Input    :
*   Output   : The function return the received data.
*   Function : receiving data with SPI
******************************************************************************/
{
    INT16U data;

    while( SSI1_SR_R & (0<<2) ) //Check if receive FIFO emtpy
    {}
    data = SSI1_DR_R;

    if ( put_queue( Q_SPI_POS, data, WAIT_FOREVER ) )
        signal( SEM_POS_UPDATE );



//For test
//-------------------------
//    INT16U data;
//    while( SSI1_SR_R & (0<<2) ) //Check if receive FIFO emtpy
//    {}
//    data = SSI1_DR_R;
//
//    INT8U data_LOW = data & 0xFF;
//    INT8U data_HIGH = (data >> 8);
//
//    while( !uart0_tx_rdy() )
//    {}
//    uart0_putc(data_LOW);
//    while( !uart0_tx_rdy() )
//    {}
//    uart0_putc(data_HIGH);
}

/****************************** End Of Module *******************************/
