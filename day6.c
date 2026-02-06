/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated
*/
#include <stdio.h>
int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 1;
    int arr[n];
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int newSize = removeDuplicates(arr, n);
    printf("Unique elements: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}