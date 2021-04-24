//
// Created by Abitha Thankaraj on 24/04/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdint.h>

//global variable for factorial
int *fact;

//void ithPermutation( int n, int i)
//{
//    int j, k = 0;
//    int *perm = (int *)calloc(n, sizeof(int));
//
//    // compute factorial code
//    for (k = 0; k < n; ++k)
//    {
//        perm[k] = i / fact[n - 1 - k];
//        i = i % fact[n - 1 - k];
//    }
//
//    // readjust values to obtain the permutation
//    // start from the end and check if preceding values are lower
//    for (k = n - 1; k > 0; --k)
//        for (j = k - 1; j >= 0; --j)
//            if (perm[j] <= perm[k])
//                perm[k]++;
//
//    // print permutation
//    for (k = 0; k < n; ++k) {
//        perm[k] += 1;
//        printf("%d ", perm[k]);
//    }
//    printf("\n");
//    printf("Bye\n");
//
//    free(perm);
//}

int main(int argc, char *argv[])
{
    int n,t;
    std::string inputfile;

    if(argc != 3 ){
        printf("usage: ./shp n filename\n");
        printf("n: number of cities\n");
        printf("filename: name of input file\n");
        exit(1);
    }

    n = atoi(argv[1]);
    inputfile = argv[2];

//Error handling for number of cities
    if (n <0 || n>12){
        std::cerr <<"Number of cities is"<<argv[1]<<"\n Number of cities should be 0<b<=12\n";
        exit(1);
    }

// Read input file

// Error if file is not readable.
    std::ifstream myFile;
    myFile.open(inputfile);
    if (!myFile.is_open()) {
        std::cerr << "Failed to open file"<<inputfile<<"\n";
        exit(1);
    }

    int data_size = n*n;

    int* data;

    try {
        data= new int[data_size];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << '\n';
        exit(1);
    }
//Read in row major form
    for (int i=0; i<data_size;i++){
        myFile>>data[i];
    }

    myFile.close();
    //Verify file is read as expected
    /*
     for (int i=0; i<n;i++){
         for (int j=0; j<n;j++){
             std::cout<<data[i*n+j]<<' ';
         }
         std::cout<<'\n';
     }
    */
/*******************************Factorial array*********************/
    // Compute factorial
    fact = new int[n]();
    int k=0;
    fact[k] = 1;
    while (++k < n)
        fact[k] = fact[k - 1] * k;

    int min_cost = 9999999;
    int* min_cost_path = new int[n]();
    for (int i=0; i<fact[n-1]; i++){
//        ithPermutation(n-1 , i );
/******************************* generate i-th permutation *********************/

        int p =n-1;
        int q =i;
        int j, k = 0;

        int *perm = new int[p]();

        // compute factorial code
        for (k = 0; k < p; ++k)
        {
            perm[k] = q / fact[p - 1 - k];
            q = q % fact[p - 1 - k];
        }

        // readjust values to obtain the permutation
        // start from the end and check if preceding values are lower
        for (k = p - 1; k > 0; --k)
            for (j = k - 1; j >= 0; --j)
                if (perm[j] <= perm[k])
                    perm[k]++;

        // print permutation
        for (k = 0; k < p; ++k) {
            perm[k] += 1;
            printf("%d ", perm[k]);
        }
        printf("\n");


/******************************* calculate cost of i-th permutation path*********************/
        int cost=data[0*n + perm[0]];

        for (k=0; k<p-1; k++){
            cost+=data[perm[k]*n + perm[k+1]];
        }
        if (cost < min_cost){
            min_cost = cost;
            for (k=0;k<p;k++){
                min_cost_path[k+1] = perm[k];
            }
        }

        delete[] perm;


    }
    printf("Min cost is %d:\n", min_cost);
    for (k = 0; k < n; ++k) {
        printf("%d ", min_cost_path[k]);
    }
    printf("\n");
}