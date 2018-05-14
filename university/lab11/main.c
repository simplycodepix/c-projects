#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 3

float fillArray(float* array, int size);
float calculateAverage(float* array, int size);
void printArray(float* array, int size);
void findMaxElementAndItsPosition(float* array, int size, float* max, int* position);
void isMatrixSymmetrical(float array[ARRAY_SIZE][ARRAY_SIZE], int size);

int main(void)
{

    float *arrayOfNumbers, average, matrix[ARRAY_SIZE][ARRAY_SIZE] = {2, -2, 5, -2, 5, 4, 5, 4, 3};
    // = {1, -2, 5, -2, 2, 4, 5, 4, 3}
    int sizeOfArray;

    printf("This is your Matrix\n");
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ARRAY_SIZE; j++)
            printf("%4.2f ", matrix[i][j]);
        printf("\n");
    }

    isMatrixSymmetrical(matrix, ARRAY_SIZE);

    printf("Enter size of an Array: ");
    fflush(stdin);
    scanf("%d", &sizeOfArray);

    arrayOfNumbers = (float*)malloc(sizeOfArray*sizeof(float));

    printf("Please Fill an Array: \n");
    fillArray(arrayOfNumbers, sizeOfArray);

    printf("Your array is: ");
    printArray(arrayOfNumbers, sizeOfArray);

    average = calculateAverage(arrayOfNumbers, sizeOfArray);
    printf("Average = %4.2f\n", average);

    float maxElement;
    int positionOfMaxElement;
    findMaxElementAndItsPosition(arrayOfNumbers, sizeOfArray, &maxElement, &positionOfMaxElement);
    
    printf("Max number = %4.2f\n", maxElement);
    printf("Max number position = %i\n", positionOfMaxElement);
    
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
        printf("%4.2f ", array[i]);     
    printf("\n");
}

float calculateAverage(float* array, int size)
{
    float sum = 0;
    for(int i = 0; i < size; i++)
        sum += *array++;
    return (sum / size);
}

void findMaxElementAndItsPosition(float* array, int size, float* max, int* position)
{
    *max = array[0];
    *position = 0;

    for(int i = 0; i < size; i++)
    {
        if(*max < array[i])
        {
            *max = array[i];
            *position = i;
        }
    }
}

void isMatrixSymmetrical(float array[ARRAY_SIZE][ARRAY_SIZE], int size)
{
    int counter = 0;

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(array[i][j] == array[j][i])
                counter++;
    
    
    if(counter == (size * size))
        printf("Your Matrix is Symmetrical\n");
    else 
        printf("Your Matrix isn't Symmetrical\n");
}