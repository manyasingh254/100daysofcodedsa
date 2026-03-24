/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value
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

struct Node *findLCA(struct Node *root, int p, int q)
{
    if (root == NULL || root->data == p || root->data == q)
        return root;

    struct Node *left = findLCA(root->left, p, q);
    struct Node *right = findLCA(root->right, p, q);

    if (left && right)
        return root; // LCA found
    return (left != NULL) ? left : right;
}

int main()
{
    int n, p, q;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter level-order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = newNode(arr[0]);
    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int f = 0, r = 0;
    queue[r++] = root;

    int i = 1;
    while (i < n && f < r)
    {
        struct Node *curr = queue[f++];
        if (curr)
        {
            curr->left = newNode(arr[i++]);
            if (curr->left)
                queue[r++] = curr->left;
            if (i < n)
            {
                curr->right = newNode(arr[i++]);
                if (curr->right)
                    queue[r++] = curr->right;
            }
        }
    }

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct Node *lca = findLCA(root, p, q);
    if (lca)
        printf("LCA: %d\n", lca->data);

    return 0;
}