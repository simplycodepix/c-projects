/*
* Simple Calculator
*/

#include <stdio.h>

float Calculator(float, char, float);

int main(void)
{
    float final, a, b;
    char o;

    while(1)
    {
        printf("What do you want to calculate? \n");
        scanf("%f %c %f", &a, &o, &b);

        final = Calculator(a, o, b);

        printf("Result = %f \n", final);
    }
    
    return 0;
}

float Calculator(float firstNumber, char operator, float secondNumber)
{
    float result;

    switch(operator){
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '/':
            result = firstNumber / secondNumber;
            break;
        default:
            printf("Ooops! Something went Wrong! Try Again\n");
    }

    return result;

}