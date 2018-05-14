#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 4

typedef struct st { 
    int info; 
    struct st *next;
} QUOTE;

QUOTE *add(QUOTE *s, int item);
int shift(QUOTE **head, QUOTE **tail);

int main(void) {
    QUOTE *head = NULL, *tail = NULL;
    int i, value;
    for (i = 0; i < STACK_SIZE; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &value);
        tail = add(tail, value);
        if (head == NULL) head = tail;
    }

    while (head) {
        printf("%d ", shift(&tail, &head));
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