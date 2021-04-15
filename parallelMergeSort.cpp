#include "parallelMergeSort.h"

void parallelMergeSort(int list[], int size, int temp[], int threads)
{
	#pragma omp parallel sections num_threads(2)
	{
		#pragma omp section
		{
			parallelMergeSort(list, size / 2, temp, threads / 2);
		}
		#pragma omp section
		{
			parallelMergeSort(list + size / 2, size - size / 2, temp + size / 2, threads - threads / 2);
		}
	}
	merge(list, size, temp);
	std::cout << "here\n";
}

void merge_sort_serial(int list[], int size, int temp[])
{
	merge_sort_serial(list, size / 2, temp);
	merge_sort_serial(list + size / 2, size - size / 2, temp);

	merge(list, size, temp);
}

void merge(int list[], int size, int temp[])
{
	int i1 = 0;
	int i2 = size / 2;
	int tempi = 0;
	while (i1 < size / 2 && i2 < size)
	{
		if (list[i1] < list[i2])
		{
			temp[tempi] = list[i1];
			i1++;
		}
		else
		{
			temp[tempi] = list[i2];
			i2++;
		}
		tempi++;
	}
	while (i1 < size / 2)
	{
		temp[tempi] = list[i1];
		i1++;
		tempi++;
	}
	while (i2 < size)
	{
		temp[tempi] = list[i2];
		i2++;
		tempi++;
	}

	memcpy(list, temp, size * sizeof(int));
}