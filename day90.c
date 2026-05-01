/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.
*/
#include <stdio.h>
#include <stdlib.h>
int canPaint(int *boards, int n, int k, long long mid)
{
    int paintersCount = 1;
    long long currentBoardSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (boards[i] > mid)
            return 0;

        if (currentBoardSum + boards[i] > mid)
        {
            paintersCount++;
            currentBoardSum = boards[i];
            if (paintersCount > k)
                return 0;
        }
        else
        {
            currentBoardSum += boards[i];
        }
    }
    return 1;
}

int main()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2)
        return 0;

    int *boards = (int *)malloc(n * sizeof(int));
    long long totalLength = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &boards[i]);
        totalLength += boards[i];
        if (boards[i] > maxLength)
            maxLength = boards[i];
    }

    long long low = maxLength;
    long long high = totalLength;
    long long ans = totalLength;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (canPaint(boards, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);
    free(boards);
    return 0;
}