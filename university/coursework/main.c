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
    float radius;
    float speed;
    int size;
    int variant;
} CONSTANTS;

typedef struct
{
    int size;
    double *values;
    float *temperatures;
} DATASTRUCTURE;

void enterConstants(CONSTANTS* constant);

void allocateMemory(DATASTRUCTURE* data, int sizeOfDatastructures);
void readData(DATASTRUCTURE* data, FILE*p, int sizeOfDatastructures);

double stocksFormula(double viscosity, float speed, float radius);
double calculateTemperature(int delta_T, int t_zero, float alfa);
double calculateViscosity(double temperature, DATASTRUCTURE* data, int i);

int main(void)
{
    FILE *p, *p1;
    p = fopen("data.txt", "r");
    p1 = fopen("program_result.txt", "w");

    if(p == NULL || p1 == NULL)
    {
        puts("File is not open!\n");
        exit(1);
    } else {
        puts("All Files are opened! Now we can calculate something.\n");
    }

    CONSTANTS * constant = (CONSTANTS*)malloc(sizeof(CONSTANTS));
    constant -> size = 3;

    DATASTRUCTURE * data = (DATASTRUCTURE*)malloc(sizeof(DATASTRUCTURE) * constant -> size);

    enterConstants(constant);
    allocateMemory(data, constant->size);
    readData(data, p, constant->size);

    double temperature;
    double stocksFormulaResult;
    double viscosity;

    for(int j = 0; j < data[constant->variant - 1].size - 1; j++)
    {
        fprintf(p1, "Stocks Formula Results for [%i] viscosity data\n", j + 1);
        for(int i = (constant->delta_TIME); i <= constant->TIME; i += constant->delta_TIME)
        {
            temperature = calculateTemperature(i, constant->Temp_zero, ALFA);
            viscosity = calculateViscosity(temperature, &data[constant->variant - 1], j);
            stocksFormulaResult = stocksFormula(viscosity,constant->speed,constant->radius);
            fprintf(p1, "%lf\n", stocksFormulaResult);
        }
        fprintf(p1, "\n");
    }

    fclose(p);
    fclose(p1);

    printf("Data was calculated! Check program_result.txt for the results\n");
    return 0;
}

void enterConstants(CONSTANTS* constant)
{
    printf("Please Enter some Constants below: \n");
    printf("Enter Time: ");
    fflush(stdin);
    scanf("%d", &constant->TIME);

    printf("Enter Delta Time: ");
    fflush(stdin);
    scanf("%d", &constant->delta_TIME);

    printf("Enter Temperature 0: ");
    fflush(stdin);
    scanf("%d", &constant->Temp_zero);

    printf("Enter Radius: ");
    fflush(stdin);
    scanf("%f", &constant->radius);

    printf("Enter speed: ");
    fflush(stdin);
    scanf("%f", &constant->speed);

    printf("Choose environment 1, 2 or 3: ");
    fflush(stdin);
    scanf("%d", &constant->variant);

    int wrong_environment = 1;
    while(constant->variant != 1 && constant->variant != 2 && constant->variant != 3)
    {
        puts("Something went wrong, but don't worry just try again.\n");
        printf("Choose environment 1, 2 or 3: ");
        fflush(stdin);
        scanf("%d", &constant->variant);
    }
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