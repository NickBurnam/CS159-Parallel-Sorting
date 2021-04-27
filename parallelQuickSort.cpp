/*
The MIT License (MIT)

Copyright (c) 2016 Eduard López

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel quick sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from Eduard López
//		   https://github.com/eduardlopez/quicksort-parallel
// *********************************************************

#include "parallelQuickSort.h"

/**
 * Sequential single-threaded implementation of quick sort.
 *
 * @param arr The array to sort.
 * @param left The start index of the array.
 * @param right The end index of the array.
 */
void sequentialQuickSort(int* arr, int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* PARTITION PART */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	/* RECURSION PART */
	if (left < j) { sequentialQuickSort(arr, left, j); }
	if (i < right) { sequentialQuickSort(arr, i, right); }
}

/**
 * Parallel multi-threaded implementation of quick sort.
 *
 * @param arr The array to sort.
 * @param left The start index of the array.
 * @param right The end index of the array.
 * @param threads The number of threads to utilize.
 */
void parallelQuickSort(int* arr, int left, int right, int threads)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* PARTITION PART */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	/* RECURSION PART */
	if (threads > 1) {
		omp_set_nested(1); //big performance gain
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				if (left < j)
				{
					parallelQuickSort(arr, left, j, threads / 2);
				}
			}
			#pragma omp section 
			{
				if (i < right)
				{
					parallelQuickSort(arr, i, right, threads / 2);
				}
			}
		}
	}
	else {
		if (left < j) {
			parallelQuickSort(arr, left, j, threads / 2);
		}
		if (i < right)
		{
			parallelQuickSort(arr, i, right, threads / 2);
		}
	}
}