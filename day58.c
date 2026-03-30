/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree
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

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node *buildTree(int in[], int pre[], int inStart, int inEnd, int *preIdx)
{
    if (inStart > inEnd)
        return NULL;

    struct Node *node = newNode(pre[(*preIdx)++]);

    if (inStart == inEnd)
        return node;

    int inIdx = search(in, inStart, inEnd, node->data);

    node->left = buildTree(in, pre, inStart, inIdx - 1, preIdx);
    node->right = buildTree(in, pre, inIdx + 1, inEnd, preIdx);

    return node;
}

void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    printf("Nodes: ");
    scanf("%d", &n);

    int *pre = malloc(n * sizeof(int));
    int *in = malloc(n * sizeof(int));

    printf("Preorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    printf("Inorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    int preIdx = 0;
    struct Node *root = buildTree(in, pre, 0, n - 1, &preIdx);

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}