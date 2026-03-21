/*
Problem: BST Insert

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
    if (root == NULL)
        return newNode(val);
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    int n, val, insertVal;
    struct Node *root = NULL;
    printf("Enter number of initial nodes: ");
    scanf("%d", &n);
    printf("Enter nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter value to insert: ");
    scanf("%d", &insertVal);
    root = insert(root, insertVal);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}