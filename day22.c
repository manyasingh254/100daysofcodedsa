/*
Problem: Count the number of nodes in a singly linked list. Implement the solution using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers representing the linked list elements

Output:
- Print a single integer representing the total number of nodes in the linked list
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNewNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    int n, value;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Type the element of the node %d: ", i + 1);
        scanf("%d", &value);
        struct Node *newNode = createNewNode(value);

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
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("%d\n", count);
    current = head;
    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return 0;
}