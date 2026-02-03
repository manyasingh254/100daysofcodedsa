/*
Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"
*/
#include <stdio.h>
int main()
{
    int n, k, i, comparisons = 0, found = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    return 0;
}