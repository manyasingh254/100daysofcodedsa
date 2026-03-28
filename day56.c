/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirror(struct Node *t1, struct Node *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->data == t2->data) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct Node *root)
{
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
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

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}