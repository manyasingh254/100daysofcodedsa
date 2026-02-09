/*
Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    printf("Enter code name: ");
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
    printf("%s\n", s);
    return 0;
}