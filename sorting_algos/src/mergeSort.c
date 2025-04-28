#include <stdio.h>
#include <stdlib.h>


void merge(unsigned int*, int, unsigned int*, int, unsigned int*);
void mergeSort(unsigned int*, int);

/*
Time complexity: O(NlogN)
Space complexity: O(N)

Write this code better
Learn and implement non-recursive mergesort
Learn and implement in-place mergesort
*/

int main()
{
    int size = 5;
    unsigned int arr[] = {3, 2, 7, 5, 4};
    
    mergeSort(arr, size);
    printIntegerArray(arr, size);
    findPairs(arr, size);

    return 0;
}

void merge(unsigned int* Larr, int LarrSize, unsigned int* Rarr, int RarrSize, unsigned int* arr)
{
    int i, j, k;
    i = j = k = 0;
    while (i < LarrSize && j < RarrSize)
    {
        arr[k++] = (Larr[i] <= Rarr[j]) ? Larr[i++] : Rarr[j++];
    }
    while (i < LarrSize)
    {
        arr[k++] = Larr[i++];
    }
    while (j < RarrSize)
    {
        arr[k++] = Rarr[j++];
    }
}

void mergeSort(unsigned int* arr, int size)
{
    if (size < 2)
    {
        return;
    }
    int LarrSize = size / 2;
    int RarrSize = size - LarrSize;
    unsigned int Larr[LarrSize], Rarr[RarrSize];
    for (int i = 0; i < LarrSize; i++)
    {
        Larr[i] = arr[i];
    }
    for (int i = LarrSize; i < size; i++)
    {
        Rarr[i - LarrSize] = arr[i];
    }
    
    mergeSort(Larr, LarrSize);
    mergeSort(Rarr, RarrSize);
    merge(Larr, LarrSize, Rarr, RarrSize, arr);
}

void findPairs(unsigned int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            for (int j = 0; j < size; j++) {
                if (arr[j] % 2 == 0) {
                    printf("(%u, %u)\n", arr[i], arr[j]);
                }
            }
        }
    }
}

void swap(unsigned int* i, unsigned int* j)
{
    unsigned int temp = *i;
    *i = *j;
    *j = temp;
}

void printIntegerArray(unsigned int* arr, int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf((i == size - 1 ? "%u" : "%u, "), arr[i]);
    }
    printf("}\n");
}