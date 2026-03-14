/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, val;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *queue = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    for (int i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }

    for (int i = 0; i < n; i++)
    {
        queue[i] = stack[top--];
    }

    printf("Reversed Queue: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", queue[i], (i < n - 1 ? " " : ""));
    }
    printf("\n");

    free(queue);
    free(stack);
    return 0;
}