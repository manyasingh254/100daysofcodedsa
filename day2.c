/*
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated
*/
#include <stdio.h>
int main()
{
    int n, pos, i;
    int arr[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("Invalid position! Please enter a value between 1 and %d\n", n);
    }
    else
    {
        for (i = pos - 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Updated array: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}