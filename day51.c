/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
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
    else
        root->right = insert(root->right, val);
    return root;
}
struct Node *findLCA(struct Node *root, int p, int q)
{
    while (root)
    {
        if (p < root->data && q < root->data)
            root = root->left;
        else if (p > root->data && q > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
int main()
{
    int n, val, p, q;
    struct Node *root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter the two nodes to find LCA: ");
    scanf("%d %d", &p, &q);
    struct Node *lca = findLCA(root, p, q);
    if (lca)
        printf("LCA of %d and %d is: %d\n", p, q, lca->data);
    return 0;
}