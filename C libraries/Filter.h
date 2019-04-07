/*
 * Filter.h
 *
 *  Created on: 21. mar. 2019
 *      Author: Peter
 */

#ifndef FILTER_H_
#define FILTER_H_
#include <stdint.h>

#define BufferSize 10
#define FilterSize 10
#define FILTER_INIT_SIZE 0

static float input_buffer[BufferSize]={0};
static float filter_coeff[]={
0,
-0.000000000000000000785328944467812029521,
-0.021344384465231652781014304309792350978,
0.000000000000000009955784571983863898562,
0.270851356685877842078724597740801982582,
0.500986055558707676915730644395807757974,
0.270851356685877842078724597740801982582,
0.000000000000000009955784571983863898562,
-0.021344384465231652781014304309792350978,
-0.000000000000000000785328944467812029521,
0};
static uint8_t data_updated = 0;
static uint8_t buffer_Size = 0;

float raw_input_buffer(float in);

//extern uint8_t size_of_buf();

float calculate_filter(float in);


#endif /* FILTER_H_ */
