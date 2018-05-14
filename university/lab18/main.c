#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 4

int main(void)
{

    FILE *p, *p1;
    p = fopen("text.txt", "w");
    p1 = fopen("dan.txt", "r");
    if(p == NULL && p1 == NULL)
    {
        puts("Error!\n");
        exit(1);
    }

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int matrix2[MATRIX_SIZE][MATRIX_SIZE];

    for(int i = 0;i < MATRIX_SIZE; i++)
    {
        for(int j = 0;j < MATRIX_SIZE; j++)
        {
            fscanf(p1, "%d", &matrix[i][j]);
        }
    }

    for(int i = 0;i < MATRIX_SIZE; i++)
    {
        for(int j = 0;j < MATRIX_SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int temp;
    for(int i = 0;i < MATRIX_SIZE; i++)
    {
        for(int j = 0;j < MATRIX_SIZE; j++)
        {
            matrix2[j][i]= matrix[i][j];
        }
    }

    for(int i = 0;i < MATRIX_SIZE; i++)
    {
        for(int j = 0;j < MATRIX_SIZE; j++)
        {
            fprintf(p, "%d ", matrix2[i][j]);
        }
        fprintf(p, "\n");
    }

    fclose(p);
    fclose(p1);
    
    return 0;
}