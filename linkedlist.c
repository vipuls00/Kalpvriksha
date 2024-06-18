// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void insertAtPosition(struct Node** headRef, int data, int position) {
//     struct Node* newNode = createNode(data);
//     if (position == 0) {
//         newNode->next = *headRef;
//         *headRef = newNode;
//         return;
//     }
//     struct Node* current = *headRef;
//     for (int i = 0; i < position - 1 && current != NULL; i++) {
//         current = current->next;
//     }
//     if (current == NULL) {
//         printf("Position out of bounds\n");
//         return;
//     }
//     newNode->next = current->next;
//     current->next = newNode;
// }

// int detectLoop(struct Node* head) {
//     struct Node *slow = head, *fast = head;
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast) {
//             return 1;
//         }
//     }
//     return 0;
// // }
// void detectAndRemoveLoop(struct Node* head) {
//     if (head == NULL || head->next == NULL) {
//         return; // No loop if list is empty or has only one node
//     }

//     struct Node *slow = head, *fast = head;

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast) {
//             break;
//         }
//     }

//     if (slow == fast) {
//         slow = head;
//         while (slow->next != fast->next) {
//             slow = slow->next;
//             fast = fast->next;
//         }
//         fast->next = NULL;
//     }
// }
// int main() {
//     struct Node* head = NULL;
//     for (int i = 0; i < 5; i++) {
//         insertAtPosition(&head, i, i);
//     }

//     struct Node* temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = head;

//     if (detectLoop(head)) {
//         printf("Loop detected\n");
//     } else {
//         printf("No loop detected\n");
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertatend(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
int detectloop(struct node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
struct node *findsum(struct node *head1, struct node *head2)
{
    struct node *sum = NULL;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        int data = temp1->data + temp2->data;
        insertatend(&sum, data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return sum;
}
struct node* reverse(struct node* head){
    struct node* temp = head;
    int size = 0;
    while (temp->next != NULL)
    {
        size++;
        temp = temp->next;
    }
    temp = head;
    int cnt = 0;
    while (cnt < (size/2))
    {
        temp = temp->next;
    }
    return temp;
    
}
void print(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    insertatend(&head1, 5);
    insertatend(&head1, 4);
    insertatend(&head1, 3);
    insertatend(&head1, 2);
    insertatend(&head1, 1);
    insertatend(&head2, 10);
    insertatend(&head2, 9);
    insertatend(&head2, 8);
    insertatend(&head2, 7);
    insertatend(&head2, 6);
    struct node *sum = findsum(head1, head2);

    print(head1);
    print(head2);
    print(sum);
    struct node* rev = reverse(head1);
    printf(rev);
    return 0;
}