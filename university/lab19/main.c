#include <stdio.h>
#include <stdlib.h>

void addNumber(int number, int* arr, int size);

int main(void)
{

    int *arr, arrSize = 5;
    arr = (int*)malloc(sizeof(int) * arrSize);

    for(int i = 0; i < arrSize; i++)
    {
        arr[i] = (rand() % 10) + 1;
    }

    int minNumber = arr[0];
    for(int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
        if(minNumber > arr[i])
            minNumber = arr[i];
    }

    printf("\nminNumber: %d\n", minNumber);
    addNumber(minNumber, arr, arrSize);

    return 0;
}

void addNumber(int number, int* arr, int size)
{
    for(int i = 0;i < size; i++)
    {
        arr[i] += number;
        printf("%d ", arr[i]);
    }
}