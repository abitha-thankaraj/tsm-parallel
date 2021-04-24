//
// Created by Abitha Thankaraj on 24/04/21.
//

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
#include <omp.h>
//global variable for factorial
int *fact;
void ithPermutation( int n, int i)
{
    //Ref: https://en.wikipedia.org/wiki/Factorial_number_system
    /* https://stackoverflow.com/questions/7918806/finding-n-th-permutation-without-computing-others
     *  when considering the lexicographical order of permutations, you should use the factorial decomposition at your advantage.

From a practical point of view, this is how I see it:

-   Perform a sort of Euclidian division, except you do it with factorial numbers, starting with (n-1)!, (n-2)!, and so on.
-   Keep the quotients in an array. The i-th quotient should be a number between 0 and n-i-1 inclusive, where i goes from 0 to n-1.
    This array is your permutation. The problem is that each quotient does not care for previous values, so you need to adjust them. More explicitly, you need to increment every value as many times as there are previous values that are lower or equal.
     * */
    int j, k = 0;
    int *perm = new int[n]();

    // compute factorial code
    for (k = 0; k < n; ++k)
    {
        perm[k] = i / fact[n - 1 - k];
        i = i % fact[n - 1 - k];
    }

    // readjust values to obtain the permutation
    // start from the end and check if preceding values are lower
    for (k = n - 1; k > 0; --k)
        for (j = k - 1; j >= 0; --j)
            if (perm[j] <= perm[k])
                perm[k]++;

    // print permutation
    printf("%d ", 0);
    for (k = 0; k < n; ++k) {
        perm[k] += 1;
        printf("%d ", perm[k]);
    }

    delete[] perm;
}

int main(int argc, char *argv[])
{
    int n,t;
    std::string inputfile;

    if(argc != 4 ){
        printf("usage: ./ptsm n t filename\n");
        printf("n: number of cities\n");
        printf("t: number of threads\n");
        printf("filename: name of input file\n");
        exit(1);
    }

    n = atoi(argv[1]);
    t = atoi(argv[2]);
    inputfile = argv[3];

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
    int shortest_path_permutation =0;

#pragma omp parallel for num_threads(t)  default(none) shared(min_cost, fact, data, n, shortest_path_permutation) schedule(static)

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
        }

/******************************* calculate cost of i-th permutation path*********************/
        int cost=data[0*n + perm[0]];

        for (k=0; k<p-1; k++){
            cost+=data[perm[k]*n + perm[k+1]];
        }


        if (cost < min_cost) {
#pragma omp critical

            {
                if (cost < min_cost) {
                    min_cost=cost;
                    shortest_path_permutation= i;
                }
            }
        }
        delete[] perm;
    }
    printf("Min cost is: %d\nMin cost path is: ", min_cost);
    ithPermutation (n-1 , shortest_path_permutation );
    printf("\n");
}