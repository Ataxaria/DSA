#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void selectionSort(unsigned int*, int);

/*
Time complexity: O(n^2)
Space complexity: O(1)
*/

int main()
{   
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);
    selectionSort(arr, size);
    printIntegerArray(arr, size);

    return 0;
}

void selectionSort(unsigned int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            // printf(" %d ", minIndex);
        }
        swap(arr, i, minIndex);
        // printIntegerArray(arr, size);
    }
    
}
