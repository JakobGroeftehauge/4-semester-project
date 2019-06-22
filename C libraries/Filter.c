/*****************************************************************************
 * MODULENAME.: filter.c
 *
 * PROJECT....: 4. semester project
 *
 * Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 190408  JGR    Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include "filter.h"
#include "circular_buffer.h"
#include <stdint.h>
/*****************************    Defines    *******************************/
#define NOF_FILTERS     8

/*****************************   Variables   *******************************/
filter_descriptor filter_pool[NOF_FILTERS]; //Pool of filters

/*****************************   Functions   *******************************/

extern void init_filter(uint8_t id, float coefArray_A[MAX_NUMBER_OF_TABS], float coefArray_B[MAX_NUMBER_OF_TABS], uint8_t tabs)
/*****************************************************************************
*   Input    : filter id, Array with filter coefficient, number of tabs in the filter.
*   Output   :
*   Function : Initialize filter
******************************************************************************/
{
    filter_pool[id].id = id; // Filter must have same ID, as the used circular_buffer.
    filter_pool[id].tabs = tabs;

    for(uint8_t i = 0; i < tabs; i++)
        {
        if( coefArray_A != 0 )
            filter_pool[id].coefList_A[i] = coefArray_A[i]; //For a coefficients

            filter_pool[id].coefList_B[i] = coefArray_B[i];  // For b coefficients
        }

        //initializes buffer to filter with same ID as filter
        initialize_buffer(id); //Buffer A
        initialize_buffer(id+8); //Buffer B
}

float run_filter(uint8_t id, float data)
/*****************************************************************************
*   Input    : filter id, sampled data
*   Output   : filtered data
*   Function : filter data
******************************************************************************/
{
    float result = 0;
    float total = 0;
    float intermediateResult_A = 0; //Used as intermediate step in calculations
    float intermediateResult_B = 0; //Used as intermediate step in calculations

    uint8_t id_A = id;
    uint8_t id_B = id+1;

    update_buffer(id_B, data); //Puts newly sampled data into buffer and shifts data

    for(uint8_t i = 0; i < filter_pool[id].tabs; i++)
    {
        //Numerator (B coefficients)
        intermediateResult_B = filter_pool[id].coefList_B[i] * peek_buffer(id_B, i+1);

        total += intermediateResult_B;
    }

    for(uint8_t i = 1; i < filter_pool[id].tabs; i++)
    {
        //Denominator (A coefficients)
        intermediateResult_A = filter_pool[id].coefList_A[i] * peek_buffer(id_A, i+1);//Calculates the n'th step of the FIR filter
        total += intermediateResult_A;
    }

    result =  total;

    update_buffer(id_A, result); //Puts output data into buffer

    return result;
}

/****************************** End Of Module *******************************/
