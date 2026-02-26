/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printForward(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d%s", current->data, (current->next ? " <-> " : ""));
        current = current->next;
    }
    printf("\n");
}
void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
int main()
{
    int n, value;
    Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Type the element of node %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    printf("\nDoubly Linked List (Forward): ");
    printForward(head);
    freeList(head);
    return 0;
}