#pragma once
#include <omp.h>
#include <string.h>
#include <iostream>

void parallelMergeSort(int* array, int low, int high);
void sequentialMergeSort(int* array, int low, int high);
void merge(int* array, int low, int mid, int high);