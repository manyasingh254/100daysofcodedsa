/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int left = 0, right = n - 1;
    int min_l = left, min_r = n - 1;
    int min_sum = arr[left] + arr[right];
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            min_l = left;
            min_r = right;
        }
        if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    printf("%d %d\n", arr[min_l], arr[min_r]);
    return 0;
}