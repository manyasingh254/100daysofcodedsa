/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
struct Node *createNode(int c, int e)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (!n)
        exit(1);
    n->coeff = c;
    n->exp = e;
    n->next = NULL;
    return n;
}
int main()
{
    int n, c, e;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        struct Node *newNode = createNode(c, e);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    struct Node *temp = head;
    while (temp)
    {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
    return 0;
}