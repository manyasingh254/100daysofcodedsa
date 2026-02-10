/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    int low = 0;
    int high = strlen(s) - 1;
    while (high > low)
    {
        if (s[low++] != s[high--])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}