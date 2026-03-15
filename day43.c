/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree
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

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter level-order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = newNode(arr[0]);
    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear)
    {
        struct Node *current = queue[front++];

        if (current != NULL)
        {
            current->left = newNode(arr[i++]);
            if (current->left)
                queue[rear++] = current->left;

            if (i < n)
            {
                current->right = newNode(arr[i++]);
                if (current->right)
                    queue[rear++] = current->right;
            }
        }
    }

    printf("Inorder Traversal: ");
    printInorder(root);
    printf("\n");

    free(arr);
    free(queue);
    return 0;
}