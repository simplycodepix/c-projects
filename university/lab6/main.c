#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_WORKERS 4
#define CURRENT_YEAR 2018

enum criteries { NAME, POSITION, YEAR, NAME_AND_POSITION, ALL_INFO, NUM_OF_FIELDS };

struct WORKERS
{
    char name[10];
    char position[20];
    int year;

} worker[AMOUNT_OF_WORKERS];

void addWorker(struct WORKERS* worker);
void printWorkerInfo(struct WORKERS* worker, int criteria);
void sortWorkersList(struct WORKERS* worker, int amount);

int main(void)
{    
    short int experience, found = 0;

    for( int i = 0; i < AMOUNT_OF_WORKERS; i++ )
    {
        printf("\nWorker [%d] info:\n", i + 1);
        addWorker(&worker[i]);
    }

    printf("\nEnter Interesting you Experience: ");
    fflush(stdin);
    scanf("%d", &experience);

    printf("\nList Of Workers that Match:\n\n");

    for( int i = 0; i < AMOUNT_OF_WORKERS; i++ )
    {
        if( (CURRENT_YEAR - worker[i].year) >= experience )
        {
            printWorkerInfo(&worker[i], NAME_AND_POSITION);
            printf("\n");
            found = 1;
        }
    }

    if( found == 0 )
    {
        printf("Any worker that match this criteria is not found\n");
    }

    return 0;
}

void addWorker(struct WORKERS*worker)
{
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", &worker -> name);
    
    printf("Enter position: ");
    fflush(stdin);
    scanf("%s", &worker -> position);
    
    printf("Enter year: ");
    fflush(stdin);
    scanf("%d", &worker -> year);
}

void printWorkerInfo(struct WORKERS* worker, int criteria)
{

    switch(criteria)
    {
        case NAME:
            printf("Name: %s\n", worker -> name);
            break;
        case POSITION:
            printf("Position: %s\n", worker -> position);
            break;
        case YEAR:
            printf("Year: %d\n", worker -> year);
            break;
        case NAME_AND_POSITION:
            printf("Name: %s\n", worker -> name);
            printf("Position: %s\n", worker -> position);
            break;
        case ALL_INFO:
            printf("Name: %s\n", worker -> name);
            printf("Position: %s\n", worker -> position);
            printf("Year: %d\n", worker -> year);
            break;
        default:
            printf("Bad criteria\n");
            break;
    }    

}

void sortWorkersList(struct WORKERS* worker, int amount)
{
    char placeholder[10];

    for(int i = 0; i < amount; i++)
    {
        for(int j = 0; j < amount; j++)
        {
            if(strcmp(worker[i].name, worker[j].name) > 0)
            {
                strcpy(placeholder, worker[i].name);
                strcpy(worker[i].name, worker[j].name);
                strcpy(worker[j].name, placeholder);
            }
        }    
    }

}