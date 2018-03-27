#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int calculateSomeStuffInString(char string[], int function(int));
void deleteVowelsFromString(char *destination, char string[]);

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

    int result = calculateSomeStuffInString(str, isupper);
    printf("\nYour string is: %s\n", str);
    printf("Amount of Uppercase Leters in the String = %d \n", result);

    result = calculateSomeStuffInString(str, isspace);
    printf("\nIf You Don't Remember Your string is: %s\n", str);
    printf("Amount of Spaces in the String = %d \n", result);

    char stringWithoutVowels[100];
    printf("\nJust Want to Remind You that Your String was: %s\n", str);
    deleteVowelsFromString(stringWithoutVowels, str);
    printf("But Now It is: %s \n", stringWithoutVowels);


    fclose(p);
    return 0;
}

int calculateSomeStuffInString(char string[], int function(int))
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

void deleteVowelsFromString(char *destination, char string[])
{
    const char *arr_lett = "AaEeIiOoUuYy";
    int i, j, d = 0;

    for(int i = 0; i < strlen(string); ++i)
    {
        if(arr_lett[j] != string[i])
        {
            destination[d++] = string[i];
        }
    }
    destination[d] = 0;
    printf("%s\n", destination);

    // for(i = 0; i < strlen(string); ++i)
    // {
        // for(j = 0; j < strlen(arr_lett); ++j)
            // arr_lett[j] == string[i] ? ++cnt : 0;
    // }
    // return cnt;
}