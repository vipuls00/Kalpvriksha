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

struct node *search(struct node *root, int key)
{
    if (root->data == key || root == NULL)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
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
    return 0;
}