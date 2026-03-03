/*
Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stack[MAX], top = -1;
void push(int val)
{
    if (top >= MAX - 1)
        return;
    stack[++top] = val;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}
void display()
{
    if (top == -1)
        return;
    for (int i = top; i >= 0; i--)
        printf("%d%s", stack[i], (i > 0 ? " " : ""));
    printf("\n");
}
int main()
{
    int n, op, val;
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        printf("Op (1:push, 2:pop, 3:display): ");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("Value: ");
            scanf("%d", &val);
            push(val);
        }
        else if (op == 2)
        {
            pop();
        }
        else if (op == 3)
        {
            display();
        }
    }
    return 0;
}