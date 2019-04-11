/*
 * Filter.c
 *
 *  Created on: 21. mar. 2019
 *      Author: Peter
 */
#include "Filter.h"

float raw_input_buffer(float in)
{

    static uint8_t i=0;

    input_buffer[i]=in;


    data_updated = 1;

    if(i==BufferSize)
    {
        i=0;
    }
    if(buffer_Size<BufferSize)
    {
        buffer_Size++;
    }

    i++;

    return input_buffer[i-1];

}

/*extern uint8_t size_of_buf()
{
    uint8_t i;
    uint8_t size=0;

    for(i=0;i<BufferSize;i++)
    {
        if(input_buffer[i]!=0)
        {
            size++;
        }
    }
    return size;
}*/

float calculate_filter(float in)
{
    uint8_t j;


    float input = in;
    float result = 0;
    float filter_buffer[FilterSize]={0};
    uint8_t buffer_len = buffer_Size;

    if(data_updated > 0)
        {
            if(buffer_len > FILTER_INIT_SIZE)
                {
                    for(j=0;j<buffer_len;j++)
                        {
                             result = result + (input*filter_coeff[j]);
                        }
                }
                else
                {
                    result = 0;
                }
            data_updated=0;
        }

    return result;

}

