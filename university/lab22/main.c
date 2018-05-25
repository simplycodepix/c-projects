#include <stdlib.h>
#include <stdio.h>

typedef struct st { // елемент черги
    int info; // інформаційне поле
    struct st *next; // вказівник на наступний елемент черги
} QUOTE;

QUOTE *add(QUOTE *s, int item); // помістити item в чергу
int shift(QUOTE **head, QUOTE **tail);

int main() {
    QUOTE *head = NULL, *tail = NULL;
    int i, value;

    for (i = 0; i< 10; i++) {
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

QUOTE *add(QUOTE *s, int item) { // помістити item в чергу
    QUOTE *new_item; // створюємо елемент

    new_item = (QUOTE*)malloc(sizeof(QUOTE)); // виділяємо пам’ять під новий елемент
    new_item->info = item; // задаємо значення новому елементу
    new_item->next = NULL; // встановлюємо зв’язки

    if (s != NULL)
        s->next = new_item; // додаємо новий елемент

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