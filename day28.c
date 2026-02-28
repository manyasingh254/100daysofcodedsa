/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated
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
    int n, val;
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
        {
            head = newNode;
            head->next = head;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    printf("Circular List: ");
    struct Node *temp = head;
    if (temp)
    {
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(head)\n");
    }
    return 0;
}