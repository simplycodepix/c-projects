#include <stdio.h>

#define FIRST_ARRAY_SIZE 10
#define SECOND_ARRAY_SIZE 5
#define THIRD_ARRAY_SIZE 5

#define FIRST_NUMBER_VALUE_LIMIT 60
#define SECOND_NUMBER_VALUE_LIMIT 70

void printArray(int arr[], int size);
int calculateSumOfPositiveNumbers(int arr[], int size, int limit);

int main(void)
{
    int firstArray[FIRST_ARRAY_SIZE] = { 65, -4, -5, -2, 61, -5, -2, -5, 2, 5 }, 
		secondArray[SECOND_ARRAY_SIZE] = { 62, -4, -5, -2, 1 }, 
		thirdArray[THIRD_ARRAY_SIZE] = { -2, 4, -5, 2, 71 },
		firstArrayResult, secondArrayResult, thirdArrayResult;

	printf("Arrays: \n\n");

	printArray(firstArray, FIRST_ARRAY_SIZE);
	printArray(secondArray, SECOND_ARRAY_SIZE);
	printArray(thirdArray, THIRD_ARRAY_SIZE);

	printf("\nSumms of Positive Numbers: \n\n");

	firstArrayResult = calculateSumOfPositiveNumbers(firstArray, FIRST_ARRAY_SIZE, FIRST_NUMBER_VALUE_LIMIT);
	printf("Sum of positive numbers in first array = %d\n", firstArrayResult);

	secondArrayResult = calculateSumOfPositiveNumbers(secondArray, SECOND_ARRAY_SIZE, FIRST_NUMBER_VALUE_LIMIT);
	printf("Sum of positive numbers in second array = %d\n", secondArrayResult);

	thirdArrayResult = calculateSumOfPositiveNumbers(thirdArray, THIRD_ARRAY_SIZE, SECOND_NUMBER_VALUE_LIMIT);
	printf("Sum of positive numbers in third array = %d\n\n", thirdArrayResult);

	return 0;
}

void printArray(int arr[], int size)
{
	printf("Row of Numbers: ");
	for(int i = 0; i < size; i++)
		printf("%3d ", arr[i]);
	printf("\n");
}

int calculateSumOfPositiveNumbers(int arr[], int size, int limit)
{
	int sumOfPositiveNumbers = 0;

	for(int i = 0; i < size; i++)
	{
		if(arr[i] > 0 && arr[i] < limit)
		{
			sumOfPositiveNumbers += arr[i];	
		}
	}
	
	return sumOfPositiveNumbers;
}