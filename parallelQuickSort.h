// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: A parallel quick sort algorithm implemented 
//              using OpenMP.
// Source: Adapted from 
//		   https://github.com/
// *********************************************************
#pragma once
#include <omp.h>
#include <iostream>

void sequentialQuickSort(int* arr, int left, int right);
void parallelQuickSort(int* arr, int left, int right, int threads);
