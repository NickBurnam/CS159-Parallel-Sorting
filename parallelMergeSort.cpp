// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel merge sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from Daniel Palomino
//		   https://github.com/dpalominop/ParallelMergeSort
// *********************************************************

#include "parallelMergeSort.h"

/**
 * Merge elements to sort.
 *
 * @param array The array to sort.
 * @param low The start index of the array.
 * @param mid The middle index of the array.
 * @param high The end index of the array.
 */
void merge(int* array, int low, int mid, int high) {

    // n1 is size of left part and n2 is size of right part
    int n1 = mid - low + 1, n2 = high - mid, i, j;
    int* left = new int[n1];
    int* right = new int[n2];

    // storing values in left part
    for (i = 0; i < n1; i++) {
        left[i] = array[i + low];
    }

    // storing values in right part
    for (i = 0; i < n2; i++) {
        right[i] = array[i + mid + 1];
    }

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        }
        else {
            array[k++] = right[j++];
        }
    }

    while (i < n1) {
        array[k++] = left[i++];
    }

    while (j < n2) {
        array[k++] = right[j++];
    }
    delete[] left;
    delete[] right;
}

/**
 * Parallel multi-threaded implementation of merge sort.
 *
 * @param array The array to sort.
 * @param low The start index of the array.
 * @param high The end index of the array.
 * @param threads The number of threads to utilize.
 */
void parallelMergeSort(int* array, int low, int high, int threads) {
	// calculating mid point of array
	int mid = low + (high - low) / 2;
	if (low < high) {
        if (threads > 1) {
            omp_set_nested(1);
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    parallelMergeSort(array, low, mid, threads / 2);
                }
                #pragma omp section
                {
                    parallelMergeSort(array, mid + 1, high, threads - threads / 2);
                }
            }
        }
        else {
            parallelMergeSort(array, low, mid, threads / 2);
            parallelMergeSort(array, mid + 1, high, threads / 2);
        }
		merge(array, low, mid, high);
	}
}

/**
 * Sequential single-threaded implementation of merge sort.
 *
 * @param array The array to sort.
 * @param low The start index of the array.
 * @param high The end index of the array.
 */
void sequentialMergeSort(int* array, int low, int high) {
    int mid = low + (high - low) / 2;
    if (low < high) {
        sequentialMergeSort(array, low, mid);
        sequentialMergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
