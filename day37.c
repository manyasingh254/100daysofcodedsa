/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, val;
    char op[20];
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *pq = (int *)malloc(n * sizeof(int));
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter operation (insert <val>, delete, peek): ");
        scanf("%s", op);
        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &val);
            pq[size++] = val;
        }
        else if (strcmp(op, "delete") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                int minIdx = 0;
                for (int j = 1; j < size; j++)
                {
                    if (pq[j] < pq[minIdx])
                        minIdx = j;
                }
                printf("Deleted: %d\n", pq[minIdx]);
                for (int j = minIdx; j < size - 1; j++)
                {
                    pq[j] = pq[j + 1];
                }
                size--;
            }
        }
        else if (strcmp(op, "peek") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                int minVal = pq[0];
                for (int j = 1; j < size; j++)
                {
                    if (pq[j] < minVal)
                        minVal = pq[j];
                }
                printf("Peek: %d\n", minVal);
            }
        }
    }
    free(pq);
    return 0;
}