#include <stdio.h>
#include <math.h>

#define T0 100
#define ALPHA 0.05

double stocksFormula(double viscosity, float speed, float radius);
double calculateTemperature();
double calculateViscosity(double temperature);

struct DATASTRUCTURE
{

    int radius;
    int delta;
    

} data[3];

int main(void)
{

    printf("Works\n");

    return 0;
} 