#include <stdio.h>
#include <stdlib.h>

void enterDimensions(int *Rows, int *Cols);
void fillArray(int **array, int Rows, int Cols);
void printArray(int **array, int Rows, int Cols);
void changeNumberInArray(int **array, int Rows, int Cols);

int main(void)
{
    int **array;
    int amountOfRows, amountOfCols;

    enterDimensions(&amountOfRows, &amountOfCols);

    array = (int**)malloc(amountOfRows*sizeof(int*));
    for(size_t i = 0; i < amountOfRows; i++)
    {
        array[i] = (int*)malloc(amountOfCols*sizeof(int));
    }
    
    fillArray(array, amountOfRows, amountOfCols);
    printArray(array, amountOfRows, amountOfCols);
    changeNumberInArray(array, amountOfRows, amountOfCols);
    printArray(array, amountOfRows, amountOfCols);
    free(array);

    return 0;
}

void enterDimensions(int *Rows, int *Cols)
{
    printf("Enter amount of Rows: ");
    scanf("%d", Rows);
    printf("Enter amount of Cols: ");
    scanf("%d", Cols);
}

void fillArray(int **array, int Rows, int Cols)
{
    int i, j;
    printf("Please, fill an array with some numbers: \n");
    for (i = 0; i < Rows; i++)
    { for (j = 0; j < Cols; j++)
        { printf("-> ");
            scanf("%d", &array[i][j]); } }
}

void printArray(int **array, int Rows, int Cols)
{
    int i, j;
    printf("This is your array: \n");
    for (i = 0; i < Rows; i++)
    { for (j = 0; j < Cols; j++)
        { printf("%d ", array[i][j]); }
        printf("\n"); }
}

void changeNumberInArray(int **array, int Rows, int Cols)
{
    int i, j;
    
    for (i = 0; i < Rows; i++)
        for (j = 0; j < Cols; j++)
        { if(array[i][j] < 0)
                array[i][j] = 0;
            else
                array[i][j] = 1; }
}