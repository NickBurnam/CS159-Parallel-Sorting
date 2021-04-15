#pragma once
#include <omp.h>
#include <string.h>
#include <iostream>

void parallelMergeSort(int list[], int size, int temp[], int threads);
void merge_sort_serial(int list[], int size, int temp[]);
void merge(int list[], int size, int temp[]);