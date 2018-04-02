#include <stdio.h>

double expression(int p);
double calculateThatSum(int n);

int main(void)
{
    int n;
    double result;

    printf("Enter your number: ");
    fflush(stdin);
    scanf("%d", &n);

    result = calculateThatSum(n);
    printf("Result = %lf\n", result);

    return 0;
}

double expression(int p)
{
    return (((double)p + 2) / (3 * (double)p));
}

double calculateThatSum(int n)
{
    if ( n <= 0 )
        return 0.0;
    else if ( n == 1 )
        return expression(n);
    else
        return (expression(n) + calculateThatSum(n - 1));
}