/*
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree
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
    if (val == -1)
        return NULL;
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void mirror(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    printf("Nodes: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = malloc(n * sizeof(int));
    printf("Level-order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = newNode(arr[0]);
    struct Node **q = malloc(n * sizeof(struct Node *));
    int f = 0, r = 0, i = 1;
    q[r++] = root;

    while (i < n && f < r)
    {
        struct Node *curr = q[f++];
        if (curr)
        {
            curr->left = newNode(arr[i++]);
            if (curr->left)
                q[r++] = curr->left;
            if (i < n)
            {
                curr->right = newNode(arr[i++]);
                if (curr->right)
                    q[r++] = curr->right;
            }
        }
    }

    mirror(root);
    printf("Inorder of Mirrored Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}