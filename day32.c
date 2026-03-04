/*
Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, val, stack[1000], top = -1;
    printf("Enter number of elements to push: ");
    if (scanf("%d", &n) != 1)
        return 0;
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        stack[++top] = val;
    }
    printf("Enter number of elements to pop: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        if (top >= 0)
            top--;
    }
    printf("Remaining stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d%s", stack[i], (i > 0 ? " " : ""));
    }
    printf("\n");
    return 0;
}