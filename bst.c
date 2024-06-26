#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    return newnode;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
        return root;
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;  
}
// struct node* findMin(struct node* node) {
//     struct node* current = node;
//     while (current && current->left != NULL)
//         current = current->left;
//     return current;
// }

// struct node* deleteNode(struct node* root, int key) {
//     if (root == NULL) return root;

//     if (key < root->data)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);
//     else {
//         if (root->left == NULL) {
//             struct node* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             struct node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         struct node* temp = findMin(root->right);

//         root->data = temp->data;

//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }
struct node* deleteNode(struct node* head, int key){
    if (head == NULL)
    {
        return head;
    }
    struct node* temp = head;
    if (key > temp->data)
    {
        return deleteNode(temp->left,key);
    }else if(key < temp->data){
        return deleteNode(temp->right,key);
    }else{
        if (temp->left == NULL)
        {
            struct node* r = temp->right;
            free(temp);
            return r;
        }else if (temp->right == NULL)
        {
            struct node* l = temp->left;
            free(temp);
            return l;
        }
        else{
            struct node* min = findmin(temp->right);
            temp->data = min->data;
            temp->right = deleteNode(temp->right,min->data);

        }
        
        return temp;
    }
    
    
    
}
struct node *search(struct node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key > root->data) {
        return search(root->right, key);
    }

    return search(root->left, key);
}
void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    inorderTraversal(root);
   struct node* se =  search(root,20);
    if (se != NULL)
    {
           printf("Element is present ");
    }
    
    return 0;
}