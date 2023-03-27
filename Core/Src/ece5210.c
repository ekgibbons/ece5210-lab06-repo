#include "ece5210.h"

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288f

#define W_C (PI/3)
#define NUM_TAPS 30

float h_float[NUM_TAPS] = {0.f};


/**
Generates a windowed sinc lowpass filter with cutoff
frequency defined as a constant W_C with the number of
taps also defined as a constant (NUM_TAPS).  This filter
uses a Hamming window.

   * @param void
   * @return void
*/
void init_firwin(void)
{
    uint16_t M = NUM_TAPS - 1;
    float sum = 0.f;

    for (uint16_t n = 0; n < NUM_TAPS; n++)
    {
        if ((n == M/2) && (NUM_TAPS % 2))
        {
            h_float[n] = W_C / PI;
        }
        else
        {
            h_float[n] = sinf(W_C*(n - (float)M/2)) /
                (PI*(n - (float)M/2));
        }

        h_float[n] *= 0.54f - 0.46f*cosf(2*PI*n/M);
        
        sum += h_float[n];
    }

    for (int n = 0; n < NUM_TAPS; n++)
    {
        h_float[n] /= sum;
    }
}




/**
Function that processes a single sample

   * @param sample_in Input sample in int16_t format
   * @return Output sample in int16_t format
*/
int16_t process_sample(int16_t sample_in)
{

    int16_t sample_out = sample_in;
    return sample_out;
}

