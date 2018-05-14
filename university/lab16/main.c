#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_SPORTSMEN 2
#define CURRENT_YEAR 2018

enum criteries { NAME, SPORT, AGE, AGE_SPORT, ALL_INFO, NUM_OF_FIELDS };

struct SPORTSMEN
{
    int age;
    char name[10];
    char sport[10];
    int ageSport;

} sportsman[AMOUNT_OF_SPORTSMEN];

void addSportsman(struct SPORTSMEN* sportsman);
void printSportsmanInfo(struct SPORTSMEN* sportsman, int criteria);

int main(void)
{    
    short int found = 0;

    for( int i = 0; i < AMOUNT_OF_SPORTSMEN; i++ )
    {
        printf("\nsportsman [%d] info:\n", i + 1);
        addSportsman(&sportsman[i]);
    }

    printf("\nList Of SPORTSMEN that Match:\n\n");

    char sportSearch[10] = "Swimming";
    
    for( int i = 0; i < AMOUNT_OF_SPORTSMEN; i++ )
    {
        if( ( strcmp(sportsman[i].sport, sportSearch) == 0) )
        {
            printSportsmanInfo(&sportsman[i], ALL_INFO);
            printf("\n");
            found = 1;
        }
    }

    if( found == 0 )
    {
        printf("Any sportsman that match this criteria is not found\n");
    }

    return 0;
}

void addSportsman(struct SPORTSMEN*sportsman)
{
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", &sportsman -> name);
    
    printf("Enter age: ");
    fflush(stdin);
    scanf("%d", &sportsman -> age);
    
    printf("Enter sport: ");
    fflush(stdin);
    scanf("%s", &sportsman -> sport);

    printf("Enter how long this person trains: ");
    fflush(stdin);
    scanf("%d", &sportsman -> ageSport);
}

void printSportsmanInfo(struct SPORTSMEN* sportsman, int criteria)
{

    switch(criteria)
    {
        case NAME:
            printf("Name: %s\n", sportsman -> name);
            break;
        case ALL_INFO:
            printf("Name: %s\n", sportsman -> name);
            printf("Age: %d\n", sportsman -> age);
            printf("Sport: %s\n", sportsman -> sport);
            printf("Trains for %d years\n", sportsman -> ageSport);
            break;
        default:
            printf("Bad criteria\n");
            break;
    }    

}

// #include <stdio.h>
// #include <string.h>

// struct TRIANGLES
// {
//     int a, b, c;

// } triangle;

// int calculatePerimeter(struct TRIANGLES* triangle);

// int main(void)
// {    
//     short int experience, found = 0;

//     int perimeter;

//     triangle.a = 2;
//     triangle.b = 5;
//     triangle.c = 7;

//     perimeter = calculatePerimeter(&triangle);
//     printf("perimeter = %d\n", perimeter);

//     return 0;
// }

// int calculatePerimeter(struct TRIANGLES* triangle)
// {
//     return (triangle -> a + triangle -> b + triangle -> c);
// }
