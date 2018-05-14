#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum criteries { FIRST_FUNCTION, SECOND_FUNCTION };

double maxValue(double *arr, int size, double (*function)(double), int criteria);

int main(void)
{
    double firstMaxNumber, secondMaxNumber, arr[3] = {3, 1, 5};

	firstMaxNumber = maxValue(arr, 3, sin, FIRST_FUNCTION);
	printf("First Max Number = %lf\n", firstMaxNumber);

	secondMaxNumber = maxValue(arr, 3, log, SECOND_FUNCTION);
	printf("Second Max Number = %lf\n", secondMaxNumber);

    return 0;
}

double maxValue(double *arr, int size, double (*function)(double), int criteria)
{
    double max, result;
	max = 0;
	for(int i = 0; i < size; i++)
	{
        switch(criteria)
        {
            case FIRST_FUNCTION:
                result = arr[i] * function(arr[i]);
            case SECOND_FUNCTION:
                result = function(arr[i]);
            default: break;
        }
		if(max < result)
			max = result;
	}
	return max;
}