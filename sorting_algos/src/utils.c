#include <stdio.h>
#include "utils.h"

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

void generateRandomArray(unsigned int* arr, int size)
{
    FILE* urand = fopen("/dev/urandom", "r");
    unsigned int randint;
    for (int i = 0; i < size; i++)
    {
        fread(&randint, sizeof(randint), 1, urand);
        arr[i] = (randint %= 10000);
    }
    fclose(urand);
}


int getArraySize(void)
{
    int size = 0;
    printf("Enter size of array: ");
    scanf("%d", &size);
    return size;
}