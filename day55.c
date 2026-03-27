/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes
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

void printRightView(struct Node *root, int n)
{
    if (!root)
        return;

    struct Node **queue = malloc(n * sizeof(struct Node *));
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail)
    {
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++)
        {
            struct Node *curr = queue[head++];

            if (i == levelSize - 1)
            {
                printf("%d ", curr->data);
            }

            if (curr->left)
                queue[tail++] = curr->left;
            if (curr->right)
                queue[tail++] = curr->right;
        }
    }
    free(queue);
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = malloc(n * sizeof(int));
    printf("Enter level-order traversal: ");
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

    printf("Right View: ");
    printRightView(root, n);
    printf("\n");

    free(arr);
    free(q);
    return 0;
}