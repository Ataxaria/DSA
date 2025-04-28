#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int linearSearch(unsigned int*, int, unsigned int);

int main()
{
    int size = getArraySize();
    unsigned int arr[size];
    
    generateRandomArray(arr, size);
    printIntegerArray(arr, size);

    unsigned int query = 0;
    puts("Query: ");
    scanf("%u", &query);
    
    int result = linearSearch(arr, size, query);

    printf((result == -1) ? "\nElement is not located in array\n" : "\n%u is located at index %d\n", query, result);
    return 0;
}

int linearSearch(unsigned int* arr, int size, unsigned int query)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == query)
        {
            return i;
        }
    }

    return -1;
}
