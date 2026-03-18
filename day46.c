/*
Problem: Level Order Traversal

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
    if (val == -1)
        return NULL;
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
void levelOrder(struct Node *root, int n)
{
    if (!root)
        return;
    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int f = 0, r = 0;
    queue[r++] = root;
    while (f < r)
    {
        struct Node *curr = queue[f++];
        printf("%d ", curr->data);
        if (curr->left)
            queue[r++] = curr->left;
        if (curr->right)
            queue[r++] = curr->right;
    }
    free(queue);
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter level-order integers (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node *root = newNode(arr[0]);
    struct Node **q = (struct Node **)malloc(n * sizeof(struct Node *));
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
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
    printf("Level Order Traversal: ");
    levelOrder(root, n);
    printf("\n");
    return 0;
}