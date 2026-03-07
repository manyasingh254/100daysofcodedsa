/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, val;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        queue[rear++] = val;
    }
    printf("Queue elements: ");
    for (int i = front; i < rear; i++)
    {
        printf("%d%s", queue[i], (i < rear - 1 ? " " : ""));
    }
    printf("\n");
    free(queue);
    return 0;
}