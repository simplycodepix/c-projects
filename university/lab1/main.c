// lab1_mod1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EX1_SIZE 15
#define EX2_SIZE 10
#define EX3_SIZE 5

void ex1() {
	int MAS[EX1_SIZE], i, summ = 0, max = 0, max_index;
	double product = 1, average2, average;

    printf("Enter %d numbers: \n", EX1_SIZE);

	for (i = 0;i < EX1_SIZE;i++) {
        fflush(stdin);
        scanf("%d", &MAS[i]);
	}

	for (i = 0;i < EX1_SIZE;i++) {
		
		if( MAS[i] % 2 == 0 ) {
			summ += MAS[i];
		}

		if( MAS[i] % 2 != 0 ) {
			product *= MAS[i];	
		}

		if( MAS[i] > max ) {
			max = MAS[i];
			max_index = i;
		}
	}
	
	average = summ / EX1_SIZE;
	average2 = pow(product, (1/EX1_SIZE));

    printf("Summ = %d \n", summ);
    printf("Average = %.2f \n", average);
    printf("Product = %.2f \n", product);
    printf("Average 2 = %.2f \n", average2);
    printf("Max numer = %d, with index = %d \n", max, max_index);

}

void ex2() {
	int MAS[EX2_SIZE], i, summ = 0, min, max = 0, max_index, min_index;
	double product = 1;

    printf("Enter %d numbers: \n", EX2_SIZE);

    for (i = 0;i < EX2_SIZE;i++) {
        fflush(stdin);
        scanf("%d", &MAS[i]);
	}

	min = MAS[0];

	for (i = 0;i < EX2_SIZE;i++) {

		if( MAS[i] < 0 ) {
			summ += MAS[i];
		}

		if( abs(MAS[i]) > max ) {
			max = MAS[i];
			max_index = i;
		}
		if( abs(MAS[i]) < min ) {
			min = MAS[i];
			min_index = i;
		}

	}
	if (min_index < max_index ) {
		for (i = min_index;i <= max_index; i++) {
			product *= MAS[i];	
		}
	} else {
		for (i = min_index;i >= max_index; i--) {
			product *= MAS[i];	
		}
	}

    printf("Min index: %d \n", min_index);
    printf("Max index: %d \n", max_index);

    printf("Summ = %d \n", summ);
    printf("Product = %.2f \n", product);

}


void ex3() {
	int X[EX3_SIZE] = { 1, 2, 3, 4, 2 }, Z[EX3_SIZE], i, j, max;

	j = EX3_SIZE - 1;

	for (i = 0; i < EX3_SIZE; i++) {
		Z[j--] = X[i];
	}

    printf("Z-array: ");
	max = Z[0];
	for (i = 0; i < EX3_SIZE; i++) {
		printf("%d ", Z[i]);
		if (Z[i] > max) {
			max = Z[i];
		}
	}
    printf("Max element = %d \n", max);
}

int main()
{
	// ex1();
	// ex2();
	ex3();

}