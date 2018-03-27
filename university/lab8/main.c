#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillAnArrayWithNumbers(double *arrayOfNumbers, int size);
double calculateThatFormula(double *arrayOfNumbers, int size, double functionOne(double), double functionTwo(double));

int main(void)
{

    FILE *p;
    p = fopen("file.txt", "w");

    if(p == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

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
    fprintf(p, "%lf", result);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, cos, sin);
    fprintf(p, "%lf", result);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, sin, sin);
    fprintf(p, "%lf", result);
    printf("\nYour Final Result = %lf \n", result);

    // PRINTING THE RESULT
    result = calculateThatFormula(arrayOfNumbers, amountOfElements, cos, cos);
    fprintf(p, "%lf", result);
    printf("\nYour Final Result = %lf \n", result);

    fclose(p);
    

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