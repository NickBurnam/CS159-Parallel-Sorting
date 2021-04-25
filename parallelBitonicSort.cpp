// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel bitonic sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from 
//		   https://www.geeksforgeeks.org/bitonic-sort/
// *********************************************************

#include "parallelBitonicSort.h"

/**
 * Swap two elements in the array to adhere to ascending or descending order.
 *
 * @param a The array to sort.
 * @param i The start index of the array.
 * @param j The end index of the array.
 * @param dir Value for ascending (1) or descending (0).
 */
void compAndSwap(int* a, int i, int j, int dir)
{
    if (dir == (a[i] > a[j]))
        swap(a[i], a[j]);
}

/**
 * Merge a bitonic sequence in ascending or descending order.
 *
 * @param a The array to sort.
 * @param low The start index of the array.
 * @param cnt The number of elements to be sorted.
 * @param dir Value for ascending (1) or descending (0).
 */
void bitonicMerge(int* a, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compAndSwap(a, i, i + k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low + k, k, dir);
    }
}

/**
 * Recursively split array into bitonic sequence and then merge.
 *
 * @param a The array to sort.
 * @param low The start index of the array.
 * @param cnt The number of elements to be sorted.
 * @param dir Value for ascending (1) or descending (0).
 */
void sequentialBitonicSortRoutine(int* a, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        // sort in ascending order since dir here is 1
        sequentialBitonicSortRoutine(a, low, k, 1);

        // sort in descending order since dir here is 0
        sequentialBitonicSortRoutine(a, low + k, k, 0);

        // Will merge wole sequence in ascending order
        // since dir=1.
        bitonicMerge(a, low, cnt, dir);
    }
}

/**
 * Split array into bitonic sequence with parallel recursion and then merge.
 *
 * @param a The array to sort.
 * @param low The start index of the array.
 * @param cnt The number of elements to be sorted.
 * @param dir Value for ascending (1) or descending (0).
 * @param threads The number of threads to utilize.
 */
void parallelBitonicSortRoutine(int* a, int low, int cnt, int dir, int threads)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        if (threads > 1) {
            omp_set_nested(1); //no performance gain
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    // sort in ascending order since dir here is 1
                    parallelBitonicSortRoutine(a, low, k, 1, threads / 2);
                }
                #pragma omp section 
                {
                    // sort in descending order since dir here is 0
                    parallelBitonicSortRoutine(a, low + k, k, 0, threads / 2);
                }
            }
        }
        else {
            // sort in ascending order since dir here is 1
            parallelBitonicSortRoutine(a, low, k, 1, threads);

            // sort in descending order since dir here is 0
            parallelBitonicSortRoutine(a, low + k, k, 0, threads);
        }

        // Will merge wole sequence in ascending order
        // since dir=1.
        bitonicMerge(a, low, cnt, dir);
    }
}

/**
 * Sequential single-threaded implementation of Bitonic Sort.
 *
 * @param arr The array to sort.
 * @param start The start index of the array.
 * @param N The size of the array.
 */
void sequentialBitonicSort(int* arr, int start, int N) {
    int up = 1;
    sequentialBitonicSortRoutine(arr, start, N, up);
}

/**
 * Parallel multi-threaded implementation of Bitonic Sort.
 *
 * @param arr The array to sort.
 * @param start The start index of the array.
 * @param N The size of the array.
 * @param numThreads The number of threads to utilize.
 */
void parallelBitonicSort(int* arr, int start, int N, int numThreads) {
    int up = 1;
    parallelBitonicSortRoutine(arr, start, N, up, numThreads);
}