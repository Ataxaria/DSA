#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void bubbleSort(unsigned int*, int);

/*
Time complexity: O(n^2)
Space complexity: O(1)

Never use this
*/

int main()
{
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);
    bubbleSort(arr, size);
    printIntegerArray(arr, size);

    return 0;
}

void bubbleSort(unsigned int* arr, int size)
{
    for (int k = 1; k < size; k++)
    {
        bool swapped = false;
        for (int i = 0; i < size - k; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                swapped = true;
            }
            
        }
        if (!swapped)
        {
            break;
        }
        
    }
    
}