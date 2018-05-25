#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALFA 0.05
#define MATH_PI 3.14
#define MATH_E 2.71

typedef struct
{
    int TIME;
    int Temp_zero;
    int delta_TIME;
    int radius;
    int speed;
    int size;
} CONSTANTS;

typedef struct
{
    int size;
    double *values;
    float *temperatures;
} DATASTRUCTURE;

void allocateMemory(DATASTRUCTURE* data, int sizeOfDatastructures);
void readData(DATASTRUCTURE* data, FILE*p, int sizeOfDatastructures);

double stocksFormula(double viscosity, float speed, float radius);
double calculateTemperature(int delta_T, int t_zero, float alfa);
double calculateViscosity(double temperature, DATASTRUCTURE* data, int i);

int main(void)
{
    FILE *p, *p1;
    p = fopen("data.txt", "r");
    p1 = fopen("water_result.txt", "w");
    if(p == NULL)
    {
        puts("Error!\n");
        exit(1);
    }
    CONSTANTS * constant = (CONSTANTS*)malloc(sizeof(CONSTANTS));

    constant -> TIME = 200;
    constant -> delta_TIME = 10;
    constant -> Temp_zero = 100;
    constant -> radius = 2;
    constant -> speed = 25;
    constant -> size = 3;

    DATASTRUCTURE * data = (DATASTRUCTURE*)malloc(sizeof(DATASTRUCTURE) * constant -> size);

    allocateMemory(data, constant->size);
    readData(data, p, constant->size);

    double temperature;
    double stocksFormulaResult;
    double viscosity;

    for(int j = 0; j < data[0].size - 1; j++)
    {
        fprintf(p1, "Stocks Formula Results for [%i] viscosity data\n", j + 1);
        for(int i = (constant->delta_TIME); i <= constant->TIME; i += constant->delta_TIME)
        {
            temperature = calculateTemperature(i, constant->Temp_zero, ALFA);
            viscosity = calculateViscosity(temperature, &data[0], j);
            stocksFormulaResult = stocksFormula(viscosity,constant->speed,constant->radius);
            fprintf(p1, "%lf\n", stocksFormulaResult);
        }
        fprintf(p1, "\n");
    }

    fclose(p);
    fclose(p1);
    return 0;
}

void allocateMemory(DATASTRUCTURE* data, int sizeOfDatastructures)
{
    data[0].size = 6;
    data[1].size = 7;
    data[2].size = 5;

    for(int i = 0; i < sizeOfDatastructures; i++)
    {
        data[i].values = (double*)malloc(sizeof(double) * data[i].size);
        data[i].temperatures = (float*)malloc(sizeof(float) * data[i].size);
    }
}

void readData(DATASTRUCTURE* data, FILE*p, int sizeOfDatastructures)
{
    for(int i = 0; i < sizeOfDatastructures; i++)
    {
        for(int j = 0; j < data[i].size; j++)
        {
            fflush(stdin);
            fscanf(p, "%f", &data[i].temperatures[j]);
        }
        for(int j = 0; j < data[i].size; j++)
        {
            fflush(stdin);
            fscanf(p, "%lf", &data[i].values[j]);
        }
    }
}

double stocksFormula(double viscosity, float speed, float radius)
{
    return (double)(6.0 * MATH_PI * viscosity * speed * radius);
}

double calculateTemperature(int delta_T, int t_zero, float alfa)
{
    double temperature;
    temperature = (double)t_zero * pow((double)MATH_E, (double)(-alfa * delta_T));
    return temperature;
}

double calculateViscosity(double temperature, DATASTRUCTURE* data, int i)
{
    double viscosity;
    viscosity = data->values[i] + ((data->values[i+1] - data->values[i]) / (data->temperatures[i+1] - data->temperatures[i])) * (temperature - data->temperatures[i]);
    return viscosity;
}