/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main()
{
    struct Node *root = NULL;
    int n, val, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter value to search: ");
    scanf("%d", &key);
    struct Node *result = search(root, key);
    if (result)
        printf("Value %d found in the BST.\n", result->data);
    else
        printf("Value %d not found.\n", key);
    return 0;
}