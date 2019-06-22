/*
 * state_feedback.c
 *
 *  Created on: 19 Jun 2019
 *      Author: Mads
 */
#include <stdint.h>
#include "state_feedback.h"

#define mInputs  1
#define nStates  3
#define pOutputs  1

State_Controller Controller_Pool[2];

uint8_t multiply(uint8_t m1, uint8_t m2, float mat1[][m2],
              uint8_t n1, uint8_t n2, float mat2[][n2],
              float res[][n2] )
{
    if(m2 == n1)
    {
        int x, i, j; ;
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                res[i][j] = 0;
                for (x = 0; x < m2; x++)
                {
                    *(*(res + i) + j) += *(*(mat1 + i) + x) *
                                        *(*(mat2 + x) + j);
                }
            }
        }
        return 1;
    }
    else
    {
        return 0; //signals that the operation was illegal
    }

}


uint8_t addition(uint8_t m, uint8_t n, float mat1[][n], float mat2[][n],
              float res[][n] )
{
    uint8_t j,i;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}

uint8_t subtraction(uint8_t m, uint8_t n, float mat1[][n], float mat2[][n],
              float res[][n] )
{
    uint8_t j,i;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j]-mat2[i][j];
        }
    }
}

void scalarMultiplication(float k, uint8_t m, uint8_t n, float mat1[][n], float res[][n])
{
    uint8_t j,i;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j]*k;
        }
    }
}

extern void init_state_feedback()
{

}

uint8_t ID = 0;
float A[nStates][nStates] = {{0,1,0},{0,-0.1318,87.5},{0,-178181.18,-1690909.1}};
float B[nStates][mInputs] = {{0},{0},{363636.4}};
float C[pOutputs][nStates] = {{57.2958,0,0}};   //{{1,0,0}};  //{{1,0,0},{0,1,0}};
float F[mInputs][nStates] = {{-0.1886,0.337,1.9}};
float L[nStates][pOutputs] = {{-30.6477},{-13.37},{-98.6}};   //{{-40,-0.9932},{0.0055,-13309115.8},{-90.4171,257190236269.2}};
float xhat[nStates][1] = {{0},{0},{0}};
float h = 0.1;

extern void State_Feeback_TASK(void* pvParameters)
{
    float y[pOutputs][1];
    //float xhat[3][1];
    float u[mInputs][1];
    //float A_xhat[nStates][1];
    //float B_u[nStates][1];
    float C_xhat[pOutputs][1];
    float C_xhat_y[pOutputs][1];
    //float L_C_xhat_y[nStates][1];
    float running_sum[nStates][1];
    float tempMat[nStates][1];
    float r = 2;
    //y[0][0] = QEI0_POS_R;
    y[0][0] = 0.5;
    //y[1][0] = 0.0;

    multiply(mInputs,nStates,F,nStates,1,xhat,u); // u calculated

    if (u[1][1] > 12)
        u[1][1] = 12;
    if (u[1][1] < -12)
        u[1][1] = -12;


    // -------------- Calculate new xhat ---------------------------------
    //xhat+A*xhat+B*u+L*(C*xhat-y)
    multiply(nStates,nStates,A,nStates,1,xhat,running_sum); // calculate A*xhat and add to sum

    multiply(nStates,mInputs,B,mInputs,1,u,tempMat);    // Calculate B*u
    addition(nStates,1,running_sum,tempMat,running_sum);    // add B*u to running sum

    multiply(pOutputs,nStates,C,nStates,1,xhat,C_xhat); // Calculate C*xhat
    subtraction(pOutputs,1,C_xhat,y,C_xhat_y);  // Calculate C*xhat-y
    multiply(nStates,pOutputs,L,pOutputs,1,C_xhat_y,tempMat); //Calculate L*(C*xhat-y)
    addition(nStates,1,running_sum,tempMat,running_sum);  // add L*(C*xhat-y) to running sum

    scalarMultiplication(h, nStates, 1, running_sum, running_sum); // multiplying the sampling time scalar

    addition(nStates,1,xhat,running_sum,xhat); // adding the terms to yield next xhat.

    // output
    // out = u[1][1]/12*1023


}




