/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated
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
        exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct Node *buildSortedList(int size, int listNum)
{
    if (size <= 0)
        return NULL;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter %d sorted elements for list %d:\n", size, listNum);
    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i + 1);
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
    return head;
}
struct Node *mergeSortedLists(struct Node *h1, struct Node *h2)
{
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            tail->next = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    tail->next = (h1 != NULL) ? h1 : h2;
    return dummy.next;
}
void printList(struct Node *head)
{
    printf("Merged List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    int n, m;
    printf("Enter size of first list: ");
    if (scanf("%d", &n) != 1)
        return 0;
    struct Node *l1 = buildSortedList(n, 1);
    printf("Enter size of second list: ");
    if (scanf("%d", &m) != 1)
        return 0;
    struct Node *l2 = buildSortedList(m, 2);
    struct Node *result = mergeSortedLists(l1, l2);
    printList(result);
    return 0;
}