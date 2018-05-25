#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int size;
    double *values;
    float *temperatures;
} DATASTRUCTURE;

int main(void)
{
    FILE *p;
    p = fopen("data.txt", "w");
    if(p == NULL)
    {
        puts("Error!\n");
        exit(1);
    }

    DATASTRUCTURE* data = (DATASTRUCTURE*)malloc(sizeof(DATASTRUCTURE) * 3);

    data[0].size = 6;
    data[0].values = (double*)malloc(sizeof(double) * data[0].size);
    data[0].temperatures = (float*)malloc(sizeof(float) * data[0].size);

    data[0].temperatures[0] = 0.0;
    data[0].temperatures[1] = 20.0;
    data[0].temperatures[2] = 40.0;
    data[0].temperatures[3] = 60.0;
    data[0].temperatures[4] = 80.0;
    data[0].temperatures[5] = 100.0;

    data[0].values[0] = 0.01797;
    data[0].values[1] = 0.01004;
    data[0].values[2] = 0.00655;
    data[0].values[3] = 0.00470;
    data[0].values[4] = 0.00357;
    data[0].values[5] = 0.00284;

    data[1].size = 7;
    data[1].values = (double*)malloc(sizeof(double) * data[1].size);
    data[1].temperatures = (float*)malloc(sizeof(float) * data[1].size);

    data[1].temperatures[0] = 0.0;
    data[1].temperatures[1] = 10.0;
    data[1].temperatures[2] = 20.0;
    data[1].temperatures[3] = 30.0;
    data[1].temperatures[4] = 50.0;
    data[1].temperatures[5] = 70.0;
    data[1].temperatures[6] = 100.0;

    data[1].values[0] = 12.10;
    data[1].values[1] = 3.95;
    data[1].values[2] = 1.48;
    data[1].values[3] = 6.00;
    data[1].values[4] = 1.80;
    data[1].values[5] = 0.59;
    data[1].values[6] = 0.13;

    data[2].size = 5;
    data[2].values = (double*)malloc(sizeof(double) * data[2].size);
    data[2].temperatures = (float*)malloc(sizeof(float) * data[2].size);

    data[2].temperatures[0] = 10.0;
    data[2].temperatures[1] = 20.0;
    data[2].temperatures[2] = 30.0;
    data[2].temperatures[3] = 50.0;
    data[2].temperatures[4] = 70.0;

    data[2].values[0] = 549000.0;
    data[2].values[1] = 9.87;
    data[2].values[2] = 2.02;
    data[2].values[3] = 29025.0;
    data[2].values[4] = 11025.0;

    printf("%f", data[2].temperatures[2]);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < data[i].size; j++)
        {
            fprintf(p, "%f ", data[i].temperatures[j]);
        }
        fprintf(p, "\n");
        for(int j = 0; j < data[i].size; j++)
        {
            fprintf(p, "%lf ", data[i].values[j]);
        }
        fprintf(p, "\n");
    }


    fclose(p);
    return 0;
}
