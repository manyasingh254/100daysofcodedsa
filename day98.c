/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    if (i1->start != i2->start)
    {
        return i1->start - i2->start;
    }
    return i1->end - i2->end;
}

Interval *merge(Interval *intervals, int intervalsSize, int *returnSize)
{
    if (intervalsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(Interval), compare);

    Interval *result = (Interval *)malloc(intervalsSize * sizeof(Interval));
    int count = 0;

    result[count++] = intervals[0];

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i].start <= result[count - 1].end)
        {
            if (intervals[i].end > result[count - 1].end)
            {
                result[count - 1].end = intervals[i].end;
            }
        }
        else
        {
            result[count++] = intervals[i];
        }
    }

    *returnSize = count;
    return result;
}