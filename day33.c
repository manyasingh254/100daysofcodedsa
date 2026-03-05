/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
int main()
{
    char s[1000], st[1000];
    int top = -1;
    printf("Enter infix expression: ");
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
    {
        if (isalnum(s[i]))
            printf("%c", s[i]);
        else if (s[i] == '(')
            st[++top] = '(';
        else if (s[i] == ')')
        {
            while (top != -1 && st[top] != '(')
                printf("%c", st[top--]);
            top--;
        }
        else
        {
            while (top != -1 && prec(s[i]) <= prec(st[top]))
                printf("%c", st[top--]);
            st[++top] = s[i];
        }
    }
    while (top != -1)
        printf("%c", st[top--]);
    printf("\n");
    return 0;
}