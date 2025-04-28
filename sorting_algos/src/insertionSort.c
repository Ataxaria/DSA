#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void insertionSort(unsigned int*, int);

/*
Time complexity: O(n^2)
Space complexity: O(1)

Lower overhead for small N
*/

int main()
{
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);
    insertionSort(arr, size);
    printIntegerArray(arr, size);

    return 0;
}

void insertionSort(unsigned int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        unsigned int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole--] = arr[hole - 1];
        }
        arr[hole] = value;
    }
    
}