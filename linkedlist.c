#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(struct Node** headRef, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    struct Node* current = *headRef;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    for (int i = 0; i < 5; i++) {
        insertAtPosition(&head, i, i);
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    if (detectLoop(head)) {
        printf("Loop detected\n");
    } else {
        printf("No loop detected\n");
    }

    return 0;
}
