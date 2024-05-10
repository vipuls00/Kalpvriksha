#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

void initialize(struct stack* s) {
    s->top = NULL;
}

void push(struct stack* s, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory overflow (heap full)\n");
        return;
    }
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}

void pop(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct node* temp = s->top;
        s->top = temp->next;
        printf("Popped: %d\n", temp->data);
        free(temp);
    }
}

int peek(struct stack* s) {
    if (s->top != NULL) {
        return s->top->data;
    } else {
        printf("Stack is empty\n");
        return -1; // Return an error code or handle it appropriately
    }
}

int isEmpty(struct stack* s) {
    return s->top == NULL;
}

void display(struct stack* s) {
    struct node* temp = s->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct stack s;
    initialize(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Current stack: \n");
    display(&s);

    printf("Top element: %d\n", peek(&s));
    pop(&s);
    display(&s);

    if (isEmpty(&s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

