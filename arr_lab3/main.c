/*
* За допомогою дійсної матриці X[7x2] на площині задано n точок так,
* що X1j, X2j - координати точки j. Точки попарно з'єднані відрізками.
* Знайти довжину найбільшого відрізка.
*/

#include <stdio.h>
#include <math.h>

#define FIRST_SIZE 7
#define SECOND_SIZE 2

double countMaxLengthBetweenPoints(int arr[FIRST_SIZE][SECOND_SIZE], int firstSize);
void printArray(int arr[FIRST_SIZE][SECOND_SIZE], int firstSize, int secondSize);

int main(void)
{
    int arr[FIRST_SIZE][SECOND_SIZE] = { {2, 4}, {5, 6}, {2, 3}, {1, 6}, {2,5}, {1, 4}, {4, 1} };
    double result;
    
    printArray(arr, FIRST_SIZE, SECOND_SIZE); // Printing An Array

    result = countMaxLengthBetweenPoints(arr, FIRST_SIZE);
    printf("Max Length Between Points = %3.2f", result);

    return 0;
}

double countMaxLengthBetweenPoints(int arr[FIRST_SIZE][SECOND_SIZE], int firstSize)
{
    double lengthBetweenPoints, maxLengthBetweenPoints = 0;
    int coordinateOfX;
    int coordinateOfY;

    for(int i = 0; i < firstSize - 1; i++)
    {
        coordinateOfX = arr[i + 1][0] - arr[i][0];
        coordinateOfY = arr[i + 1][1] - arr[i][1];

        #include "lengthBetweenPoints.txt"
        printf("Length Between A(%d, %d) and B(%d, %d): %f \n",
            arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1],
            lengthBetweenPoints);

        if(maxLengthBetweenPoints < lengthBetweenPoints)
        {
            maxLengthBetweenPoints = lengthBetweenPoints;
        }
    }

    return maxLengthBetweenPoints;
}

void printArray(int arr[FIRST_SIZE][SECOND_SIZE], int firstSize, int secondSize)
{
    for(int i = 0; i < firstSize; i++)
    {
        printf("M(x,y): ");
        for(int j = 0; j < secondSize; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// int k = 0;
// for(int i = 0; i < firstSize; i++)
// {
//     for(int j = 0; j < firstSize; j++)
//     {
//         coordinateOfX = arr[i][0] - arr[j][0];
//         coordinateOfY = arr[i][1] - arr[j][1];

//         #include "lengthBetweenPoints.txt"
//         printf("Length Between Points[%d] = %f\n", k++, lengthBetweenPoints);

//         if(maxLengthBetweenPoints < lengthBetweenPoints)
//         {
//             maxLengthBetweenPoints = lengthBetweenPoints;
//         }
//     }
// }