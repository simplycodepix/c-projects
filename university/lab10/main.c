#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int calculateHowMuchInString(char string[], int function(int));
char deleteVowelsFromString(char *destination, char string[]);
int isVowelInString(char character);

int main(void)
{
    FILE *p;
    p = fopen("text.txt", "r");
    if(p == NULL)
    {
        puts("Error!\n");
        exit(1);
    }

    char str[100];

    fflush(stdin);
    printf("Type something nice: ");
    gets(str);

    int result = calculateHowMuchInString(str, isupper);
    printf("\nYour string is: %s\n", str);
    printf("Amount of Uppercase Leters in the String = %d \n", result);

    result = calculateHowMuchInString(str, isspace);
    printf("\nIf You Don't Remember Your string is: %s\n", str);
    printf("Amount of Spaces in the String = %d \n", result);

    char stringWithoutVowels[100];
    printf("\nJust Want to Remind You that Your String was: %s\n", str);
    deleteVowelsFromString(stringWithoutVowels, str);
    printf("But Now It is: %s \n", stringWithoutVowels);


    fclose(p);
    return 0;
}

int calculateHowMuchInString(char string[], int function(int))
{
    int result = 0;
    for(int i = 0; i < strlen(string); i++)
    {
        if(function(string[i]))
        {
            result++;
        }
    }
    return result;
}

int isVowelInString(char character)
{
    const char *arr_lett = "AaEeIiOoUuYy";

    for(int i = 0; i < strlen(arr_lett); i++)
    {
        if(arr_lett[i] == character)
            return 1;
    }

    return 0;
}


char deleteVowelsFromString(char *destination, char string[])
{
    int j = 0;

    for(int i = 0; string[i] != '\0'; i++)
    {
        if(isVowelInString(string[i]) == 0)
        {
            destination[j++] = string[i];
        }
    }
    destination[j] = '\0';
}