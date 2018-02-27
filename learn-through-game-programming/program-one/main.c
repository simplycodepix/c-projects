/*
* Rewrite the Menu Chooser program from this chapter using an enumeration
* to represent difficulty levels. The variable choice will still be of type int.
*/

#include <stdio.h>

enum difficultyLevels { EASY = 1, NORMAL, HARD };

int main(void)
{

    int choice;

    printf("Difficulty Levels\n");
    printf("%d - Easy\n", EASY);
    printf("%d - Normal\n", NORMAL);
    printf("%d - Hard\n", HARD);

    printf("Choice: ");
    fflush(stdin);
    scanf("%d", &choice);

    switch(choice)
    {
        case EASY:
            printf("You picked Easy\n");
            break;
        case NORMAL:
            printf("You picked Normal\n");
            break;
        case HARD:
            printf("You picked Hard\n");
            break;
        default:
            break;
    }

    return 0;
}