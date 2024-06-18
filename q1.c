#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node* next;
};


struct node* createnode(char* data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newnode->data, data);
    newnode->next = NULL;
    return newnode;
}

void insertatend(struct node** head, char* data) {
    struct node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
}

void printlist(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%s ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct node* checkforsame(struct node* head1,struct node* head2){
    struct node* same = NULL;
    struct node* temp1 = head1;
    while (temp1 != NULL)
    {
        struct node* temp2 = head2;
        while (temp2 != NULL)
        {
            if (strcmp(temp1->data, temp2->data) == 0)
            {
                insertatend(&same,temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        
    }
    return same;
}
struct node* checkunique(struct node* head1, struct node* head2) {
    struct node* uniqueList = NULL;
    struct node* curr1 = head1;
    struct node* curr2 = head2;

    while (curr1 != NULL) {
        struct node* temp = head2;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(curr1->data, temp->data) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertatend(&uniqueList, curr1->data);
        }
        curr1 = curr1->next;
    }

    // Check elements of head2 that are not in head1
    while (curr2 != NULL) {
        struct node* temp = head1;
        int found = 0;
        while (temp != NULL) {
            if (strcmp(curr2->data, temp->data) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertatend(&uniqueList, curr2->data);
        }
        curr2 = curr2->next;
    }

    return uniqueList;
}
struct node* checkForSameNodes(struct node* head1, struct node* head2) {
    struct node* newlist = NULL;
    struct node* curr1 = head1;
    while (curr1 != NULL) {
        struct node* curr2 = head2;
        while (curr2 != NULL) {
            if (strcmp(curr1->data, curr2->data) == 0) {
                insertatend(&newlist, curr1->data);
                break;  
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return newlist;
}

// struct node* checkforunique(struct node* same, struct node* head1, struct node* head2){
//     struct node* newlist1 = NULL;
//     struct node* curr1 = same;
//     int found;
//     int found1;
//     while (curr1 != NULL)
//     {
//         struct node* first = head1;
//          found = 0;
//         while (first != NULL)
//         {
//             if(strcmp(curr1->data,first->data) == 0){
//                 found = 1;
//             }
//             break;
//         }
//         if(!found){
//             insertatend(&newlist1,curr1->data);
//         }
//         curr1 = curr1->next;
//     }
//     struct node* curr2 = same;
//     while (curr2 != NULL)
//     {
//         struct node* first = head2;
//          found1 = 0;
//         while (first != NULL)
//         {
//             if(strcmp(curr2->data,first->data) == 0){
//                 found1 = 1;
//             }
//             break;
//         }
//         if (!found && !found1) {
//             insertatend(&newlist1, curr1->data);
//         }
//         curr2 = curr2->next;
//     }
//     return newlist1;
// }
int main() {
    struct node* head1 = NULL;
    char str[100];
    printf("Enter elements for the first linked list: ");
    scanf("%[^\n]%*c", str);
    char* tokens = strtok(str, " ");
    while (tokens != NULL) {
        insertatend(&head1, tokens);
        tokens = strtok(NULL, " ");
    }

    struct node* head2 = NULL;
    char str2[100];
    printf("Enter elements for the second linked list: ");
    scanf("%[^\n]%*c", str2);
    char* token = strtok(str2, " ");
    while (token != NULL) {
        insertatend(&head2, token);
        token = strtok(NULL, " ");
    }

    struct node* intboth = checkforsame(head1, head2);
    printf("Common elements in the linked lists: ");
    printlist(intboth);
        struct node* unique = checkunique(head1, head2);
    printf("Common elements in the linked lists: ");
    printlist(unique);

    return 0;
}
