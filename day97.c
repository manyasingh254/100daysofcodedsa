/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compareIntervals(const void *a, const void *b)
{
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int heap[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void heapPush(int heap[], int *size, int value)
{
    heap[*size] = value;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapPop(int heap[], int *size)
{
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
}

int minMeetingRooms(Interval *intervals, int intervalsSize)
{
    if (intervalsSize == 0)
        return 0;

    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    int *minHeap = (int *)malloc(intervalsSize * sizeof(int));
    int heapSize = 0;

    heapPush(minHeap, &heapSize, intervals[0].end);

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i].start >= minHeap[0])
        {
            heapPop(minHeap, &heapSize);
        }
        heapPush(minHeap, &heapSize, intervals[i].end);
    }

    int result = heapSize;
    free(minHeap);
    return result;
}