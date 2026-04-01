/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
        {
            return false;
        }

        if (right < n && arr[i] > arr[right])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    printf("Nodes: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = malloc(n * sizeof(int));
    printf("Level-order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    free(arr);
    return 0;
}