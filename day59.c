/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree
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

struct Node *buildTree(int in[], int post[], int inStart, int inEnd, int *postIdx)
{
    if (inStart > inEnd)
        return NULL;

    struct Node *node = newNode(post[(*postIdx)--]);

    if (inStart == inEnd)
        return node;

    int inIdx = search(in, inStart, inEnd, node->data);

    // Important: Build Right subtree before Left for Postorder
    node->right = buildTree(in, post, inIdx + 1, inEnd, postIdx);
    node->left = buildTree(in, post, inStart, inIdx - 1, postIdx);

    return node;
}

void preorder(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    printf("Nodes: ");
    scanf("%d", &n);

    int *in = malloc(n * sizeof(int));
    int *post = malloc(n * sizeof(int));

    printf("Inorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("Postorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    int postIdx = n - 1;
    struct Node *root = buildTree(in, post, 0, n - 1, &postIdx);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}