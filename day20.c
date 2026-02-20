/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1)
        return 0;
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int current_sum = 0;
        for (int j = i; j < n; j++)
        {
            current_sum += arr[j];
            if (current_sum == 0)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}