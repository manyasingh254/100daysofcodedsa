/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree
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
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

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

    printf("Height of the tree: %d\n", findHeight(root));

    free(arr);
    free(queue);
    return 0;
}