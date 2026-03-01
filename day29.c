/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (!n)
        exit(1);
    n->data = val;
    n->next = NULL;
    return n;
}
int main()
{
    int n, k, val;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Enter rotation k: ");
    scanf("%d", &k);
    k = k % n;
    if (k == 0)
        goto print;
    tail->next = head;
    struct Node *curr = head;
    for (int i = 0; i < n - k - 1; i++)
        curr = curr->next;
    head = curr->next;
    curr->next = NULL;
print:
    printf("Rotated List: ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return 0;
}