#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    char location[30];
    float price;
} entrepreneurships;

void fillInfo(entrepreneurships* entrepreneurship);
void printInfo(entrepreneurships* entrepreneurship);
void updatePrice(entrepreneurships* entrepreneurship);

int main(void)
{
    FILE *p;
    p = fopen("text.txt", "w");
    if(p == NULL)
    {
        puts("Error!\n");
        exit(1);
    }

    int amountOfEntrepreneurships = 2;
    entrepreneurships* entrepreneurship = (entrepreneurships*)malloc(sizeof(entrepreneurships) * amountOfEntrepreneurships);

    for(int i = 0; i < amountOfEntrepreneurships; i++)
    {
        fillInfo(&entrepreneurship[i]);
        printf("\n");
        fwrite(&entrepreneurship[i], sizeof(entrepreneurships), 1, p);
    }

    rewind(p);

    printf("Change Price of Entrepreneurshups\n");
    for (int i = 0; i < amountOfEntrepreneurships; i++)
    {
        fread(&entrepreneurship[i], sizeof(entrepreneurships), 1, p);
        printInfo(&entrepreneurship[i]);
        
        printf("\nEnter new price for %s: ", entrepreneurship[i].name);
        scanf("%f", &entrepreneurship[i].price);

        fseek(p, -(long)sizeof(entrepreneurships), 1);
        fwrite(&entrepreneurship[i], sizeof(entrepreneurships), 1, p);
        
        fseek(p, -(long)sizeof(entrepreneurships), 1);
        fread(&entrepreneurship[i], sizeof(entrepreneurships), 1, p);
        
        printf("\nNew price of %s: %.2f $\n",
        entrepreneurship[i].name, entrepreneurship[i].price);
        printf("\n_______________________\n\n");
    }

    free(entrepreneurship);
    fclose(p);
    return 0;
}

void fillInfo(entrepreneurships* entrepreneurship)
{
    printf("Enter Name: ");
    fflush(stdin);
    scanf("%s", &entrepreneurship -> name);
    printf("Enter Location: ");
    fflush(stdin);
    scanf("%s", &entrepreneurship -> location);
    printf("Enter Price: ");
    fflush(stdin);
    scanf("%f", &entrepreneurship -> price);
}

void updatePrice(entrepreneurships* entrepreneurship)
{
    printf("Enter New Price: ");
    fflush(stdin);
    scanf("%f", &entrepreneurship -> price);
}

void printInfo(entrepreneurships* entrepreneurship)
{
    printf("Name: %s \n", entrepreneurship -> name);
    printf("Location: %s \n", entrepreneurship -> location);
    printf("Price: %.2f $ \n", entrepreneurship -> price);
}