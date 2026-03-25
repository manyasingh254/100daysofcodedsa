/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
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

void findMinMax(struct Node *node, int *min, int *max, int hd)
{
    if (!node)
        return;
    if (hd < *min)
        *min = hd;
    if (hd > *max)
        *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

void printVerticalLine(struct Node *root, int line_no)
{
    if (!root)
        return;
    struct Node **q = malloc(2000 * sizeof(struct Node *));
    int *hds = malloc(2000 * sizeof(int));
    int f = 0, r = 0;
    q[r] = root;
    hds[r++] = 0;
    while (f < r)
    {
        struct Node *curr = q[f];
        int curr_hd = hds[f++];
        if (curr_hd == line_no)
            printf("%d ", curr->data);
        if (curr->left)
        {
            q[r] = curr->left;
            hds[r++] = curr_hd - 1;
        }
        if (curr->right)
        {
            q[r] = curr->right;
            hds[r++] = curr_hd + 1;
        }
    }
    free(q);
    free(hds);
}

int main()
{
    int n, min = 0, max = 0;
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
    findMinMax(root, &min, &max, 0);
    for (int line = min; line <= max; line++)
    {
        printVerticalLine(root, line);
        printf("\n");
    }
    return 0;
}