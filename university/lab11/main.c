#include <stdio.h>
#include <stdlib.h>

float fillArray(float* array, int size);
float calculateAverage(float* array, int size);
void printArray(float* array, int size);

int main(void)
{

    float *arrayOfNumbers, average;
    int sizeOfArray;

    printf("Enter size of an Array: ");
    fflush(stdin);
    scanf("%d", &sizeOfArray);

    arrayOfNumbers = (float*)malloc(sizeOfArray*sizeof(float));

    printf("Please Fill an Array: \n");
    fillArray(arrayOfNumbers, sizeOfArray);

    printf("Your array is: ");
    printArray(arrayOfNumbers, sizeOfArray);

    average = calculateAverage(arrayOfNumbers, sizeOfArray);
    printf("Average = %4.2f", average);
    
    return 0;
}

float fillArray(float* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("-> ");
        fflush(stdin);
        scanf("%f", &array[i]);     
    }
    return *array;
}

void printArray(float* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%4.2f ", array[i]);     
    }
    printf("\n");
}

float calculateAverage(float* array, int size)
{
    float sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *array++;
    }
    return (sum / size);
}