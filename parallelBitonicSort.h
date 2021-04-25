// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel bitonic sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from 
//		   https://www.geeksforgeeks.org/bitonic-sort/
// *********************************************************

#pragma once
#include <algorithm>
#include <omp.h>
using namespace std;

/**
 * Sequential single-threaded implementation of Bitonic Sort.
 *
 * @param arr The array to sort.
 * @param start The start index of the array.
 * @param N The size of the array.
 */
void sequentialBitonicSort(int* arr, int start, int N);

/**
 * Parallel multi-threaded implementation of Bitonic Sort.
 *
 * @param arr The array to sort.
 * @param start The start index of the array.
 * @param N The size of the array.
 * @param numThreads The number of threads to utilize.
 */
void parallelBitonicSort(int* arr, int start, int N, int numThreads);
