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

void parallelMergeSort(int* array, int low, int high, int threads);
void sequentialMergeSort(int* array, int low, int high);
void merge(int* array, int low, int mid, int high);