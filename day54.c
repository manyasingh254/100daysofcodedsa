/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order
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

void zigzagTraversal(struct Node *root, int n)
{
    if (!root)
        return;

    struct Node **s1 = malloc(n * sizeof(struct Node *));
    struct Node **s2 = malloc(n * sizeof(struct Node *));
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 >= 0 || top2 >= 0)
    {
        while (top1 >= 0)
        {
            struct Node *curr = s1[top1--];
            printf("%d ", curr->data);
            if (curr->left)
                s2[++top2] = curr->left;
            if (curr->right)
                s2[++top2] = curr->right;
        }
        while (top2 >= 0)
        {
            struct Node *curr = s2[top2--];
            printf("%d ", curr->data);
            if (curr->right)
                s1[++top1] = curr->right;
            if (curr->left)
                s1[++top1] = curr->left;
        }
    }
    free(s1);
    free(s2);
}

int main()
{
    int n;
    printf("Nodes: ");
    scanf("%d", &n);
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

    zigzagTraversal(root, n);
    return 0;
}