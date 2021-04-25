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

void compAndSwap(int a[], int i, int j, int dir)
{
    if (dir == (a[i] > a[j]))
        swap(a[i], a[j]);
}

void bitonicMerge(int a[], int low, int cnt, int dir)
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

void bitonicSortRoutine(int a[], int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        // sort in ascending order since dir here is 1
        bitonicSortRoutine(a, low, k, 1);

        // sort in descending order since dir here is 0
        bitonicSortRoutine(a, low + k, k, 0);

        // Will merge wole sequence in ascending order
        // since dir=1.
        bitonicMerge(a, low, cnt, dir);
    }
}

void sequentialBitonicSort(int* arr, int start, int N) {
    int up = 1;
    bitonicSortRoutine(arr, start, N, up);
}

void parallelBitonicSort(int* arr, int start, int N, int numThreads) {

}