////////////////////////////////////
//  Name: Daniel Marzec
//  PSU ID: djm6267
//  Assignment #3
////////////////////////////////////

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <thread>
#include <omp.h>
// Function Declarations
////////////////////////////////////////////////////////////////////////////


//calculates walltime, from hw2
void get_walltime(double* wcTime) {
     struct timeval tp;
     gettimeofday(&tp, NULL);
     *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);

}
//prints contents of array
void printArray(float *array, int size)
{
        for (int i = 0; i < size; i++){
                printf("%f", array[i]);
                printf("\n");
        }
}

//fills in array with random float values
void fill_in_rand_array( float* rand_array, int size)
{
        srandom(1);
        for(int i = 0; i<size; i++){
                float random_number = random();
                rand_array[i] = random_number/1000;
        }

}

//find mean of array
void find_mean(float* array, int size, float* mean_val )
{
        float sum = 0;
        for(int i = 0; i < size; i++){
                sum = sum + array[i];
        }
        *mean_val = (sum/size);

}


//find differential
void calc_diff( float* array ,int start_index  , int size , float* diff_val , float mean_val )
{
        float sum = 0;
        float diff = 0;
        for(int i = 0; i < size; i++){
                sum = abs( array[start_index + i] - mean_val);           
                diff = diff + (sum*sum); }
        *diff_val = (sum/size);
}

void find_serial_standard_deviation( )
{
//variables for timing and calculation
float serial_sum ,serial_mean , serial_diff , total_serial_diff, std = 0;


//N : size of array 
int N = 1000000000;
//P : Amount of Threads
int P = 1;
//filling array with random values to calculate standard deviation with
float* randArray = new float[N] ;
fill_in_rand_array(randArray, N);
//timer variables
double d_S, d_E = 0;
//start timer, calculate std, end timer
get_walltime(&d_S);
//calculating sums for mean
for(int i = 0; i<N; i++){
        serial_sum = randArray[i];
}
serial_mean = serial_sum/N;
//calculating sum of differentials for standard deviation 
for(int i = 0; i<N;i++){
        serial_diff = abs(randArray[i] - serial_mean);
        total_serial_diff =total_serial_diff +( serial_diff * serial_diff);
}
std = sqrt(total_serial_diff/N);
//end timer
get_walltime(&d_E);
printf("serial with N = %d , P = 1 , Elapsed time: %f\n",N ,(d_E - d_S));
}

//serial implementation
int main(int argc, char *argv[])
{
//I tried to only do the std calculations in a function and
//put everything else in here but it kept adding time
find_serial_standard_deviation();
}

           