// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel quick sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from 
//		   https://github.com/
// *********************************************************
#include "parallelQuickSort.h"
#include <omp.h>

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
		omp_set_nested(1);
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