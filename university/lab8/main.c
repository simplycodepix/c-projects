#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillAnArrayWithNumbers(double *arrayOfNumbers, int size);
double calculateThatFormula(double *arrayOfNumbers, int size, double functionOne(double), double functionTwo(double));

int main(void)
{

    double *arrayOfNumbers, result;
    int amountOfElements;

    printf("Enter the amount of elements in array: ");
    fflush(stdin);
    scanf("%d", &amountOfElements);

    // FILLING AN ARRAY WITH NUMBERS
    arrayOfNumbers = (double*)malloc(amountOfElements*sizeof(double));
    fillAnArrayWithNumbers(arrayOfNumbers, amountOfElements);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, sin, cos);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, cos, sin);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, sin, sin);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, cos, cos);
    printf("\nYour Final Result = %lf \n", result);

    return 0;
}

void fillAnArrayWithNumbers(double *arrayOfNumbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("-> ");
        fflush(stdin);
        scanf("%lf", &arrayOfNumbers[i]);
    }
}

double calculateThatFormula(double *arrayOfNumbers, int size, double functionOne(double), double functionTwo(double))
{
    double firstSum = 0, secondSum = 0;
    for(int i = 0; i < size; i++)
    {
        firstSum += (arrayOfNumbers[i] * functionOne(arrayOfNumbers[i]));
        secondSum += (pow(arrayOfNumbers[i], 2.0) * functionTwo(arrayOfNumbers[i]));
    }
    return (firstSum + secondSum);
}