#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 4

typedef struct st { int info; struct st *next; } STACK;

void push(STACK **s, int item);
int pop(STACK **s);
int peek(STACK *s);

int main() {
    STACK *head = NULL;
    STACK *head_second = NULL;
    STACK *head_final = NULL;
    int i, value;
    
    printf("Enter elements for the First Stack: \n");
    for (i = 0; i < STACK_SIZE; i++) {
        printf("Enter element %d:", i);
        scanf("%d", &value);
        push(&head, value);
    }

    printf("Enter elements for the Second Stack: \n");
    for (i = 0; i < STACK_SIZE; i++) {
        printf("Enter element %d:", i);
        scanf_s("%d", &value);
        push(&head_second, value);
    }

    printf("Enter elements for the Second Stack: \n");
    for (i = 0; i < STACK_SIZE; i++) {
        push(&head_second, pop(&head) + pop(&head_second));
    }

    while (head_final) {
        printf("%d ", pop(&head_final));
    }

    return 0;
}
void push(STACK **s, int item) {
    STACK *new_item;
    new_item = (STACK*)malloc(sizeof(STACK));
    new_item -> info = item;
    new_item -> next = *s;
    *s = new_item;
}
int pop(STACK **s) {
    STACK * remove_it = *s;
    int value = peek(remove_it);
    *s = (**s).next;
    free(remove_it); 
    return value;
}
int peek(STACK *s) {
    return s->info;
}
