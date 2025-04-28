#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int lomuto_partition(unsigned int*, int, int);
int hoare_partition(unsigned int*, int, int);
void quickSort(unsigned int*, int, int);

/*
Time complexity: O(NlogN) average | O(n^2) worst
Space complexity: O(logN) average | O(n) worst

i don't think you have any idea how fast i really am

hoare_partition: fast but doesn't fix the position of pivot
lomuto_partiton: slower but fixes position of pivot
*/

int main()
{
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);
    quickSort(arr, 0, size - 1);
    printIntegerArray(arr, size);

    return 0;
}

int lomuto_partition(unsigned int* arr, int low_index, int high_index) {
    unsigned int pivot = arr[high_index];
    int i = low_index - 1;

    for (int j = low_index; j < high_index; j++)
    {
        if (arr[j] < pivot) 
        {
            swap(&arr[++i], &arr[j]);
        }
        
    }
    
    swap(&arr[i + 1], &arr[high_index]);
    return i + 1;
}

int hoare_partition(unsigned int* arr, int low_index, int high_index) {
    unsigned int pivot = arr[low_index];
    int i = low_index - 1, j = high_index + 1;

    while (true)
    {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) { return j; }
        swap(&arr[i], &arr[j]);
    }
    
}

void quickSort(unsigned int* arr, int low_index, int high_index) {
    if (low_index < high_index)
    {
        int partition_index = hoare_partition(arr, low_index, high_index);
        quickSort(arr, low_index, partition_index /*+ 1 for lomuto_partition*/);
        quickSort(arr, partition_index + 1, high_index);
    }
    
}