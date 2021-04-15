// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: This is the main method for testing several 
//              sequential vs parallel sorting algorithms.
// *********************************************************

#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;

void initArray(int* array, int n);
void printArray(int* array, int n);

const int N = 16;

int main()
{
    // start timer
    // 
    auto begin = std::chrono::high_resolution_clock::now();

    // initialize array length N with random numbers
    //
    int arr[N];
    initArray(arr, N);

    // End timer
    //
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Time to initialize Array: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;
    
    // Print array
    //
    printArray(arr, N);

    // start timer
    // 
    begin = std::chrono::high_resolution_clock::now();

    // std::sort array O(N·log(N))
    sort(arr, arr + N);
    
    // End timer
    //
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "std::sort elapsed time: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;




    return(0);
}

void initArray(int* array, int n) {
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
}

void printArray(int *array, int n) {
    cout << "< ";
    for (int i = 0; i < n; i++) {
        if(i == N-1)
            cout << array[i] << " >" << endl;
        else
            cout << array[i] << ", ";
    }
}

