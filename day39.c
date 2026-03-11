/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *heap, int size, int i)
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
        heapify(heap, size, smallest);
    }
}

int main()
{
    int n, val;
    char op[20];

    printf("Enter total number of operations: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nOperation %d - Enter command (insert, extractMin, peek): ", i + 1);
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            heap[size] = val;
            int curr = size++;
            while (curr > 0 && heap[curr] < heap[(curr - 1) / 2])
            {
                swap(&heap[curr], &heap[(curr - 1) / 2]);
                curr = (curr - 1) / 2;
            }
        }
        else if (strcmp(op, "extractMin") == 0)
        {
            if (size == 0)
                printf("Result: -1\n");
            else
            {
                printf("Result (Min Extracted): %d\n", heap[0]);
                heap[0] = heap[--size];
                heapify(heap, size, 0);
            }
        }
        else if (strcmp(op, "peek") == 0)
        {
            if (size == 0)
                printf("Result: -1\n");
            else
                printf("Result (Min Peek): %d\n", heap[0]);
        }
        else
        {
            printf("Invalid command. Use 'insert', 'extractMin', or 'peek'.\n");
        }
    }

    free(heap);
    return 0;
}