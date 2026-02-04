/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated
*/
#include <stdio.h>
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1)
        return 1;
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverseArray(arr, n);
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}