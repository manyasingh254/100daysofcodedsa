/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.
*/
#include <stdio.h>
#include <stdlib.h>

int canAllocate(int *pages, int n, int m, long long mid)
{
    int students = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages[i] > mid)
            return 0;
        if (currentSum + pages[i] > mid)
        {
            students++;
            currentSum = pages[i];
            if (students > m)
                return 0;
        }
        else
        {
            currentSum += pages[i];
        }
    }
    return 1;
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    int *pages = (int *)malloc(n * sizeof(int));
    long long sum = 0;
    int maxPage = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
        sum += pages[i];
        if (pages[i] > maxPage)
            maxPage = pages[i];
    }

    if (m > n)
    {
        printf("-1\n");
        free(pages);
        return 0;
    }

    long long low = maxPage;
    long long high = sum;
    long long ans = sum;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (canAllocate(pages, n, m, mid))
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
    free(pages);
    return 0;
}