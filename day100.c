/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int originalIdx;
} Element;

void merge(Element *arr, int *counts, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Element *L = (Element *)malloc(n1 * sizeof(Element));
    Element *R = (Element *)malloc(n2 * sizeof(Element));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightSmallerCount = 0;

    while (i < n1 && j < n2)
    {
        if (R[j].val < L[i].val)
        {
            rightSmallerCount++;
            arr[k++] = R[j++];
        }
        else
        {
            counts[L[i].originalIdx] += rightSmallerCount;
            arr[k++] = L[i++];
        }
    }

    while (i < n1)
    {
        counts[L[i].originalIdx] += rightSmallerCount;
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Element *arr, int *counts, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, counts, left, mid);
        mergeSort(arr, counts, mid + 1, right);
        merge(arr, counts, left, mid, right);
    }
}

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    if (numsSize == 0)
        return NULL;

    int *counts = (int *)calloc(numsSize, sizeof(int));
    Element *arr = (Element *)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++)
    {
        arr[i].val = nums[i];
        arr[i].originalIdx = i;
    }

    mergeSort(arr, counts, 0, numsSize - 1);

    free(arr);
    return counts;
}