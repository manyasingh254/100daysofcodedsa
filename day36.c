/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, val;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 0;
    int *q = (int *)malloc(n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        q[i] = val;
    }
    printf("Enter number of dequeues: ");
    scanf("%d", &m);
    int front = m % n;
    printf("Result: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", q[(front + i) % n], (i < n - 1 ? " " : ""));
    }
    printf("\n");
    free(q);
    return 0;
}