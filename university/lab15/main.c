#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_MOTORCYCLES 4
#define AMOUNT_OF_STUDENTS 3

struct MOTORCYCLES
{
    char model[10];
    char factory[10];
    unsigned int price;
    char engineNumber[10];
} motorcycle[AMOUNT_OF_MOTORCYCLES];

struct STUDENTS
{
    char name[10];
    char group[10];
    int yearOfBirth;
} student[AMOUNT_OF_STUDENTS];

void addMotorcylce(struct MOTORCYCLES* motorcycle);
void printMotorcycleInfo(struct MOTORCYCLES* motorcycle);

void addStudent(struct STUDENTS* student);
void printStudentInfo(struct STUDENTS* student);

int main(void)
{
    short int found = 0;

    for( int i = 0; i < AMOUNT_OF_MOTORCYCLES; i++ )
    {
        printf("\nmotorcycle [%d] info:\n", i + 1);
        addMotorcylce(&motorcycle[i]);
    }

    char factory[10];
    char engineNumber[10];

    printf("Enter interesting you factory: ");
    fflush(stdin);
    scanf("%s", factory);

    printf("Enter number: ");
    fflush(stdin);
    scanf("%s", engineNumber);

    printf("\nList Of Motorcycles that Match:\n\n");

    for( int i = 0; i < AMOUNT_OF_MOTORCYCLES; i++ )
    {
        if( ( strcmp(motorcycle[i].factory, factory) == 0) || (motorcycle[i].engineNumber[0] == engineNumber[0]) )
        {
            printMotorcycleInfo(&motorcycle[i]);
            printf("\n");
            found = 1;
        }
    }

    if( found == 0 )
    {
        printf("Any sportsman that match this criteria is not found\n");
    }



    printf("\n\n**** Part 2 **** \n\n");

    found = 0;

    for( int i = 0; i < AMOUNT_OF_STUDENTS; i++ )
    {
        printf("\nStudent [%d] info:\n", i + 1);
        addStudent(&student[i]);
    }

    printf("\nList Of Students that Match:\n\n");

    for( int i = 0; i < AMOUNT_OF_STUDENTS; i++ )
    {
        if( student[i].yearOfBirth == 1986 )
        {
            printStudentInfo(&student[i]);
            printf("\n");
            found = 1;
        }
    }

    if( found == 0 )
    {
        printf("Any student that match this criteria is not found\n");
    }

    return 0;
}

void addMotorcylce(struct MOTORCYCLES* motorcycle)
{

    printf("Enter model: ");
    fflush(stdin);
    scanf("%s", &motorcycle -> model);

    printf("Enter factory: ");
    fflush(stdin);
    scanf("%s", &motorcycle -> factory);

    printf("Enter price: ");
    fflush(stdin);
    scanf("%d", &motorcycle -> price);

    printf("Enter engine number: ");
    fflush(stdin);
    scanf("%s", &motorcycle -> engineNumber);

}

void printMotorcycleInfo(struct MOTORCYCLES* motorcycle)
{
    printf("Model: %s\n", motorcycle -> model);
    printf("Factory: %s\n", motorcycle -> factory);
    printf("Price: %d\n", motorcycle -> price);
    printf("Engine Number: %s\n", motorcycle -> engineNumber);
}

void addStudent(struct STUDENTS* student)
{

    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", &student -> name);

    printf("Enter group: ");
    fflush(stdin);
    scanf("%s", &student -> group);

    printf("Enter year of Birth: ");
    fflush(stdin);
    scanf("%i", &student -> yearOfBirth);

}

void printStudentInfo(struct STUDENTS* student)
{
    printf("Name: %s\n", student -> name);
    printf("Group: %s\n", student -> group);
    printf("Year of Birth: %i\n", student -> yearOfBirth);
}