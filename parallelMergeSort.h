// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel merge sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from Daniel Palomino
//		   https://github.com/dpalominop/ParallelMergeSort
// *********************************************************

#pragma once
#include <omp.h>
#include <string.h>
#include <iostream>

/**
 * Parallel multi-threaded implementation of merge sort.
 *
 * @param array The array to sort.
 * @param low The start index of the array.
 * @param high The end index of the array.
 * @param threads The number of threads to utilize.
 */
void parallelMergeSort(int* array, int low, int high, int threads);

/**
 * Sequential single-threaded implementation of merge sort.
 *
 * @param array The array to sort.
 * @param low The start index of the array.
 * @param high The end index of the array.
 */
void sequentialMergeSort(int* array, int low, int high);