/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list
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
    if (!newNode)
        exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int countKey(struct Node *head, int key)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}
int main()
{
    int n, key, val;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Type the element of node %d: ", i + 1);
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
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
    printf("Enter the key to count: ");
    scanf("%d", &key);
    printf("%d\n", countKey(head, key));
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}