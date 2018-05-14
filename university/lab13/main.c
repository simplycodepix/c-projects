/*
* Обчислити z= ( еs1+еs2 )/( k1k2 ), де s1 і k1 – сума і кількість позитивних елементів
* масиву x(100); s2 і k2 – сума і кількість позитивних елементів масиву y(80). Суми і кількість
* обчислювати в функції.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 2.71
#define FIRST_SIZE 5
#define SECOND_SIZE 8

void calculateSumAndAmountOfPositiveNumbers(int *arr, int size, int *sum, int *amount);
float calculateThatFormula(int s1, int k1, int s2, int k2);

int main(void)
{

    int arrX[FIRST_SIZE] = {-1, -2, 5, 3, -2};
    int arrY[SECOND_SIZE] = {1, 2, -5, 3, -2, 5, -1, 7};

    int firstAmount, firstSum;
    calculateSumAndAmountOfPositiveNumbers(arrX, FIRST_SIZE, &firstSum, &firstAmount);

    int secondAmount, secondSum;
    calculateSumAndAmountOfPositiveNumbers(arrY, SECOND_SIZE, &secondSum, &secondAmount);


    printf("First Sum = %d\n", firstSum);
    printf("First Amount = %d\n", firstAmount);
    printf("Second Sum = %d\n", secondSum);
    printf("Second Amount = %d\n", secondAmount);

    float result;

    result = calculateThatFormula(firstSum, firstAmount, secondSum, secondAmount);

    printf("Result = %f", result);

    return 0;
}

void calculateSumAndAmountOfPositiveNumbers(int *arr, int size, int *sum, int *amount)
{
    *sum = 0;
    *amount = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] >= 0)
        {
            *sum += arr[i];
            ++(*amount);
        }
    }
}

float calculateThatFormula(int s1, int k1, int s2, int k2)
{
    float numerator, denominator;
    float result;

    numerator = (pow(E, (double)s1) + pow(E, (double)s2));
    denominator = (k1 * k2);

    if(denominator > 0)
        result = (numerator / denominator);
    else {
        printf("ERROR -> division by zero\n");
        return 0;
    }

    return result;
}