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

void find_openMP_std(){
//N : size of array 
int N = 1000000000;
//P : Amount of Threads
int P = 10;
//filling array with random values to calculate standard deviation with
float* randArray = new float[N] ;
fill_in_rand_array(randArray, N);
//variables for timing and calculation
double d_S, d_E = 0;
float sum, mean, diff , std = 0;
//Attempt to ensure P threads 
omp_set_dynamic(0);
omp_set_num_threads(P);
#pragma omp parallel 
{
get_walltime(&d_S);
int i;
#pragma omp for reduction(+:sum) reduction(+:diff)
for (i=0; i<N; i++)
{
// Using modifed standard deviation formula found online std = ((Sum(Xi^2))/N) - (mean)^2
//sum for purpose of mean calculation
sum += randArray[i];
//diff to sum up squared Xi values
diff += (randArray[i] * randArray[i]);
}
}
//plug into std = ((Sum(Xi^2))/N) - (mean)^2
mean = (sum/N);
std =sqrt( (diff/N) - (mean*mean));
get_walltime(&d_E);

}



//openMP implementation
int main(int argc, char *argv[])
{
find_openMP_std();
}




               