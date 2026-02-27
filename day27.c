/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int getLength(struct Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}
struct Node *findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    while (len1 > len2)
    {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1)
    {
        head2 = head2->next;
        len2--;
    }
    while (head1 && head2)
    {
        if (head1->data == head2->data)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}
struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    int n, m, val;
    struct Node *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    printf("Enter size of list 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if (!h1)
            h1 = t1 = newNode;
        else
        {
            t1->next = newNode;
            t1 = newNode;
        }
    }
    printf("Enter size of list 2: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if (!h2)
            h2 = t2 = newNode;
        else
        {
            t2->next = newNode;
            t2 = newNode;
        }
    }
    struct Node *intersect = findIntersection(h1, h2);
    if (intersect)
        printf("%d\n", intersect->data);
    else
        printf("No Intersection\n");
    return 0;
}