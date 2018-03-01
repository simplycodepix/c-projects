#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_WORKERS 2
#define CURRENT_YEAR 2018

struct WORKER
{
    char name[10];
    char position[20];
    int year;

} person[AMOUNT_OF_WORKERS];

void addWorker(char name[], char position[], int year);
void printWorkerInfo(char name[], char position[], int year);

int main(void)
{    

    for( int i = 0; i < AMOUNT_OF_WORKERS; i++ )
    {
        printf("\n***************Worker [%d] info***************\n", i + 1);

        printf("Enter name: ");
        fflush(stdin);
        scanf("%s", &person[i].name);
        
        printf("Enter position: ");
        fflush(stdin);
        scanf("%s", &person[i].position);
        
        printf("Enter year: ");
        fflush(stdin);
        scanf("%d", &person[i].year);
    }

    short int experience, found = 0;
    printf("\nEnter Interesting Experience: ");
    fflush(stdin);
    scanf("%d", &experience);

    printf("\n\nList Of Workers that Match:\n");

    for( int i = 0; i < AMOUNT_OF_WORKERS; i++ )
    {
        if( ( CURRENT_YEAR - person[i].year ) > experience )
        {
            printf("\n***************Worker [%d] info***************\n", i + 1);
            printf("Name: %s\n", person[i].name);
            found = 1;
        }
    }

    if( found == 0 )
    {
        printf("Any worker that match this criteria is not found\n");
    }

    return 0;
}

void addWorker(char name[], char position[], int year)
{
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", &name);
    
    printf("Enter position: ");
    fflush(stdin);
    scanf("%s", &position);
    
    printf("Enter year: ");
    fflush(stdin);
    scanf("%d", &year);
}

/*
switch
{
    case "name":
        printf("name", name);
    case "position":
        printf("position", position);
    case "year":
        printf("position", year);
        printf("Name: %s\n", person[i].name);
        printf("Position: %s\n", person[i].position);
        printf("Year: %d\n", person[i].year);
}
*/