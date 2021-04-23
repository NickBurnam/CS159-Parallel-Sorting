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
#include <omp.h>
#include "parallelMergeSort.h"
using namespace std;

void initArray(int* array, int n);
void printArray(int* array, int n);
void copyArray(int* source, int* dest, int size);

const int N = 1000000;
const bool printArrays = false;

int main()
{
    // start timer
    // 
    auto begin = std::chrono::high_resolution_clock::now();

    // initialize array length N with random numbers
    //
    int* arr = new int[N];
    int* arr2 = new int[N];
    int* arr3 = new int[N];

    initArray(arr, N);
    copyArray(arr, arr2, N);
    copyArray(arr, arr3, N);

    // End timer
    //
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Time to initialize Arrays: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;
    
    cout << endl << "/*****************************************************************************/" << endl;

    // Print array before sort
    //
    printArray(arr, N);

    // start timer
    // 
    begin = std::chrono::high_resolution_clock::now();

    // std::sort array O(N·log(N))
    //
    sort(arr, arr + N);
    
    // End timer
    //
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "std::sort elapsed time: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;

    // Print array after sort
    //
    printArray(arr, N);

    cout << endl << "/*****************************************************************************/" << endl;

    // Print array before sort
    //
    printArray(arr2, N);

    // start timer
    // 
    begin = std::chrono::high_resolution_clock::now();

    // Sequential Merge Sort
    //
    sequentialMergeSort(arr2, 0, N - 1);

    // End timer
    //
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Sequential Merge Sort elapsed time: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;

    // Print array after sort
    //
    printArray(arr2, N);

    cout << endl << "/*****************************************************************************/" << endl;

    // Print array before sort
    //
    printArray(arr3, N);

    // start timer
    // 
    begin = std::chrono::high_resolution_clock::now();

    // Parallel Merge Sort
    //
    omp_set_num_threads(16);
    parallelMergeSort(arr3, 0, N-1);

    // End timer
    //
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Parallel Merge Sort elapsed time: " << std::fixed << std::setprecision(9) << elapsed.count() * 1e-9 << " seconds." << endl;
    
    // Print array after sort
    //
    printArray(arr3, N);

    cout << endl << "/*****************************************************************************/" << endl;

    return(0);
}

void initArray(int* array, int n) {
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
}

void printArray(int *array, int n) {
    if (printArrays) {
        cout << "< ";
        for (int i = 0; i < n; i++) {
            if (i == N - 1)
                cout << array[i] << " >" << endl;
            else
                cout << array[i] << ", ";
        }
    }
}

void copyArray(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++)
        dest[i] = source[i];
}

