/*
 * state_feedback.h
 *
 *  Created on: 19 Jun 2019
 *      Author: Mads
 */

#ifndef STATE_FEEDBACK_H_
#define STATE_FEEDBACK_H_

extern uint8_t multiply(uint8_t m1, uint8_t m2, float mat1[][m2],
                        uint8_t n1, uint8_t n2, float mat2[][n2],
                        float res[][n2] );

extern uint8_t addition(uint8_t m, uint8_t n, float mat1[][n], float mat2[][n],
              float res[][n] );

extern void State_Feeback_TASK(void* pvParameters);

extern void scalarMultiplication(float k, uint8_t m, uint8_t n, float mat1[][n], float res[][n]);

typedef struct
{
  uint8_t ID;
  float A[3][3];
  float B[3][1];
  float C[2][3];
  float xhat[3][1];
  float F[1][3];
  float L[2][3];         //stepsize for integral
} State_Controller;


#endif /* STATE_FEEDBACK_H_ */
