#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 4
#define ARR_SIZE 3
#define FINAL_SIZE 6

typedef struct st { 
    int info; 
    struct st *next;
} QUOTE;

QUOTE *add(QUOTE *s, int item);
int shift(QUOTE **head, QUOTE **tail);
int sortArray(int *array, int size);

int main(void) {
    QUOTE *head = NULL, *tail = NULL;
    QUOTE *head_second = NULL, *tail_second = NULL;
    QUOTE *head_final = NULL, *tail_final = NULL;
    int i, value;

    int values_first[ARR_SIZE];
    int values_second[ARR_SIZE];
    int values_final[FINAL_SIZE], counter = 0;

    printf("Enter elements for the First Stack: \n");
    for (i = 0; i < ARR_SIZE; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &value);
        tail = add(tail, value);
        if (head == NULL) head = tail;
        values_final[counter] = value;
        counter++;
    }

    printf("Enter elements for the Second Stack: \n");
    for (i = 0; i < ARR_SIZE; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &value);
        tail_second = add(tail_second, value);
        if (head_second == NULL) head_second = tail_second;
        values_final[counter] = value;
        counter++;
    }

    sortArray(values_final, FINAL_SIZE);

    for (i = 0; i < FINAL_SIZE; i++) {
        tail_final = add(tail_final, values_final[i]);
        if (head_final == NULL) head_final = tail_final;
        printf("%d ", values_final[i]);
    }

    printf("\n");

    while (head_final) {
        printf("%d ", shift(&tail_final, &head_final));
    }

    return 0;
}

QUOTE *add(QUOTE *s, int item) { 
    QUOTE *new_item; 
    new_item = (QUOTE*)malloc(sizeof(QUOTE)); 
    new_item->info = item; 
    new_item->next = NULL;
    if (s != NULL)
        s->next = new_item;
    return new_item;
}

int shift(QUOTE **tail, QUOTE **head) {
    QUOTE * element = *head;
    int value = element->info;
    *head = (**head).next;
    free(element);
    if (*head == NULL) {
        *tail = NULL;
    }
    return value;
}

int sortArray(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return *array;
}