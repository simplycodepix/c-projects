/*
* Складіть програму обчислення суми додатних елементів
* одновимірного масиву A[N], наявних в цьому масиві більше двох
* разів.
*/

#include <stdio.h>

#define ARR_SIZE 5

int CalculatePositiveNumbers(int[], int);

int main(void)
{

    int arrOfNumbers[ARR_SIZE] = {-2, -2, 4, 4, 5};

    int result = CalculatePositiveNumbers(arrOfNumbers, ARR_SIZE);
    printf("Result = %d", result);

    return 0;
}

int CalculatePositiveNumbers(int arr[], int size)
{
    int result = 0, count;
    
    for(int i = 0;i < size;i++)
    {
        count = 0;
        
        for(int j = 0;j < size;j++)
        {
            if(arr[j] == arr[i] && arr[j] > 0)
            {
                count++;
            }
        }

        if(count >= 2)
        {
            result += arr[i];
        }
    }
    return result;
}
