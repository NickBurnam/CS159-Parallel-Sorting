// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel quick sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from Eduard López
//		   https://github.com/eduardlopez/quicksort-parallel
// *********************************************************

#pragma once
#include <omp.h>
#include <iostream>

/**
 * Sequential single-threaded implementation of quick sort.
 *
 * @param arr The array to sort.
 * @param left The start index of the array.
 * @param right The end index of the array.
 */
void sequentialQuickSort(int* arr, int left, int right);

/**
 * Parallel multi-threaded implementation of quick sort.
 *
 * @param arr The array to sort.
 * @param left The start index of the array.
 * @param right The end index of the array.
 * @param threads The number of threads to utilize.
 */
void parallelQuickSort(int* arr, int left, int right, int threads);
