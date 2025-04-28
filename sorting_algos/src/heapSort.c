#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void heapSort(unsigned int*, int);

int main()
{
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);
    heapSort(arr, size);
    printIntegerArray(arr, size);

    return 0;
}

