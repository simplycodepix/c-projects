#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define ARR_SIZE 5

void enterArray(int arr[], int size);
void printArray(int arr[], int size);

int countArithmeticAverage(int arr[], int size);
double countGeometricAverage(int arr[], int size);


int main(void)
{
	int arr[ARR_SIZE], arr2[ARR_SIZE], arr3[ARR_SIZE];
    float arithmeticAverage, geometricAverage;
	
	enterArray(arr, ARR_SIZE);
	//printArray(arr, ARR_SIZE);
	arithmeticAverage = countArithmeticAverage(arr, ARR_SIZE);
    geometricAverage = countGeometricAverage(arr, ARR_SIZE);
	printf("Aritmetic Average = %.2f\n", arithmeticAverage);
    printf("Geometric Average = %.2f\n", geometricAverage);

	enterArray(arr2, ARR_SIZE);
	//printArray(arr2, ARR_SIZE);
	arithmeticAverage = countArithmeticAverage(arr2, ARR_SIZE);
    geometricAverage = countGeometricAverage(arr2, ARR_SIZE);
	printf("Aritmetic Average = %.2f\n", arithmeticAverage);
    printf("Geometric Average = %.2f\n", geometricAverage);

	enterArray(arr3, ARR_SIZE);
	//printArray(arr3, ARR_SIZE);
	arithmeticAverage = countArithmeticAverage(arr3, ARR_SIZE);
    geometricAverage = countGeometricAverage(arr3, ARR_SIZE);
	printf("Aritmetic Average = %.2f\n", arithmeticAverage);
    printf("Geometric Average = %.2f\n", geometricAverage);

	return 0;
}

void enterArray(int* arr, int size)
{
	printf("Enter %d numbers\n", ARR_SIZE);
	for(int i = 0;i < size; i++)
	{
		printf("-> ");
		fflush(stdin);
		scanf("%d", &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0;i < size; i++)
	{
		printf("Arr[%d] = %d\n", i, arr[i]);
	}
}


int countArithmeticAverage(int arr[], int size)
{
	int summ = 0, counter = 0;
	int result = 0;

	for(int i = 0;i < size; i++)
	{
		if( arr[i] < 0 )
		{
			summ += arr[i];
			counter++;
		}
	}

    if (counter == 0)
    {
        return 0;
    } else
    {
        return result = (summ / counter);
    }
}

double countGeometricAverage(int arr[], int size)
{
	int product = 1, counter = 0;
	double result;

	for(int i = 0;i < size; i++)
	{
		if( arr[i] > 0 )
		{
			product *= arr[i];
			counter++;
		}
	}

	return result = ( pow((double)product, (double)(1.0 / counter)) );
}