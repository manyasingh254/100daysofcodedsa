/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated
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
void deleteKey(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
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
    printf("Enter key to delete: ");
    scanf("%d", &key);
    printf("The updated linked list is: ");
    deleteKey(&head, key);
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}