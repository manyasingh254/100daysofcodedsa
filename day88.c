/*
Problem Statement: Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.
*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlace(int *stalls, int n, int k, int dist)
{
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPos >= dist)
        {
            count++;
            lastPos = stalls[i];
            if (count >= k)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2)
        return 0;

    int *stalls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);
    free(stalls);
    return 0;
}