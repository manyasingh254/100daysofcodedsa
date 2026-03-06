/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **top, int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (!n)
        exit(1);
    n->data = val;
    n->next = *top;
    *top = n;
}
int pop(struct Node **top)
{
    if (!*top)
        exit(1);
    struct Node *t = *top;
    int v = t->data;
    *top = (*top)->next;
    free(t);
    return v;
}
int main()
{
    char s[100];
    struct Node *top = NULL;
    printf("Enter postfix expression (space-separated, e.g., 2 3 1 * + 9 -):\n");
    while (scanf("%s", s) != EOF)
    {
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1])))
        {
            push(&top, atoi(s));
        }
        else
        {
            int b = pop(&top);
            int a = pop(&top);
            if (s[0] == '+')
                push(&top, a + b);
            else if (s[0] == '-')
                push(&top, a - b);
            else if (s[0] == '*')
                push(&top, a * b);
            else if (s[0] == '/')
                push(&top, a / b);
        }
        if (getchar() == '\n')
            break;
    }
    if (top)
        printf("Result: %d\n", pop(&top));
    return 0;
}