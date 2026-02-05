/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int p;
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);
    int *log1 = (int *)malloc(p * sizeof(int));
    if (log1 == NULL)
        return 1;
    printf("Enter %d sorted arrival times from server 1: ", p);
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &log1[i]);
    }
    int q;
    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);
    int *log2 = (int *)malloc(q * sizeof(int));
    if (log2 == NULL)
        return 1;
    printf("Enter %d sorted arrival times from server 2: ", q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &log2[i]);
    }
    int *merged = (int *)malloc((p + q) * sizeof(int));
    if (merged == NULL)
        return 1;
    int i = 0, j = 0, k = 0;
    while (i < p && j < q)
    {
        if (log1[i] <= log2[j])
        {
            merged[k++] = log1[i++];
        }
        else
        {
            merged[k++] = log2[j++];
        }
    }
    while (i < p)
    {
        merged[k++] = log1[i++];
    }
    while (j < q)
    {
        merged[k++] = log2[j++];
    }
    printf("Merged Chronological Log:\n");
    for (int idx = 0; idx < p + q; idx++)
    {
        printf("%d", merged[idx]);
        if (idx < p + q - 1)
            printf(" ");
    }
    printf("\n");
    free(log1);
    free(log2);
    free(merged);
    return 0;
}