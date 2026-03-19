/*
Problem: Height of Binary Tree

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

int findHeight(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter level-order traversal (-1 for NULL): ");
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
    printf("Height of the tree: %d\n", findHeight(root));
    free(arr);
    free(q);
    return 0;
}