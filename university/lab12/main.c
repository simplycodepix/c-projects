#include <stdio.h>
#include <stdlib.h>

int fillArray(int *array, int size);
int sortArray(int *array, int size);
void printArray(int *array, int size);

int main(void)
{
    int *arr, sizeOfArray;

    printf("Enter size of Array: ");
    fflush(stdin);
    scanf("%i", &sizeOfArray);
    arr = (int*)malloc(sizeOfArray * sizeof(int));

    printf("Now Fill an Array: \n");
    fillArray(arr, sizeOfArray);

    printf("Your Array: ");
    printArray(arr, sizeOfArray);

    sortArray(arr, sizeOfArray);
    printf("Array after sorting: ");
    printArray(arr, sizeOfArray);

    return 0;
}

int fillArray(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("-> ");
        fflush(stdin);
        scanf("%d", &array[i]);     
    }
    return *array;
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);     
    printf("\n");
}

int sortArray(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return *array;
}