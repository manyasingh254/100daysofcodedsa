/*
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return -1;
    struct Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

int main()
{
    int n, val;
    char op[20];
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1)
        return 0;

    struct Queue *q = createQueue();

    for (int i = 0; i < n; i++)
    {
        printf("Enter operation (enqueue <val>, dequeue): ");
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &val);
            enqueue(q, val);
        }
        else if (strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue(q));
        }
    }
    return 0;
}