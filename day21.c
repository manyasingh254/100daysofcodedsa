/*
Problem: Create and Traverse Singly Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements, space-separated
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    int n, value;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Type the element of node %d: ", i + 1);
        scanf("%d", &value);
        struct Node *newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("\nLinked List Traversal: ");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d%s", current->data, (current->next ? " -> " : ""));
        current = current->next;
    }
    printf("\n");
    current = head;
    while (current != NULL)
    {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}