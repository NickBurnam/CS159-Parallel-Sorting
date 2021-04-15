// *********************************************************
// CS159-Parallel-Sorting
// Author: Nicholas Burnam
// Date: 4/1/2021
// Description: This is the main method for testing several 
//              sequential vs parallel sorting algorithms.
// *********************************************************

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void printArray(int* array);

const int N = 16;

int main()
{
    std::cout << "Hello World!\n";
    // initialize array length N with random numbers
    //
    srand((unsigned int)time(NULL));
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    printArray(arr);

    return(0);
}

void printArray(int *array) {
    cout << "< ";
    for (int i = 0; i < N; i++) {
        if(i == N-1)
            cout << array[i] << " >";
        else
            cout << array[i] << ", ";
    }
}

