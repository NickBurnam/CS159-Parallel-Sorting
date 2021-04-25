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

void sequentialBitonicSort(int* arr, int start, int N);
void parallelBitonicSort(int* arr, int start, int N, int numThreads);
