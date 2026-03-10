/*
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;
} Deque;

Deque *createDeque(int k)
{
    Deque *obj = (Deque *)malloc(sizeof(Deque));
    obj->arr = (int *)malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = k - 1;
    obj->count = 0;
    obj->capacity = k;
    return obj;
}

bool push_front(Deque *obj, int value)
{
    if (obj->count == obj->capacity)
        return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->count++;
    return true;
}

bool push_back(Deque *obj, int value)
{
    if (obj->count == obj->capacity)
        return false;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->count++;
    return true;
}

int pop_front(Deque *obj)
{
    if (obj->count == 0)
        return -1;
    int val = obj->arr[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->count--;
    return val;
}

int pop_back(Deque *obj)
{
    if (obj->count == 0)
        return -1;
    int val = obj->arr[obj->rear];
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->count--;
    return val;
}

int front(Deque *obj)
{
    return (obj->count == 0) ? -1 : obj->arr[obj->front];
}

int back(Deque *obj)
{
    return (obj->count == 0) ? -1 : obj->arr[obj->rear];
}

int main()
{
    int n, k, val;
    char op[20];
    printf("Enter max capacity: ");
    scanf("%d", &k);
    Deque *dq = createDeque(k);
    printf("Enter number of operations: ");
    scanf("%d", &n);
    while (n--)
    {
        printf("Op (push_f, push_b, pop_f, pop_b, front, back): ");
        scanf("%s", op);
        if (strcmp(op, "push_f") == 0)
        {
            scanf("%d", &val);
            push_front(dq, val);
        }
        else if (strcmp(op, "push_b") == 0)
        {
            scanf("%d", &val);
            push_back(dq, val);
        }
        else if (strcmp(op, "pop_f") == 0)
            printf("%d\n", pop_front(dq));
        else if (strcmp(op, "pop_b") == 0)
            printf("%d\n", pop_back(dq));
        else if (strcmp(op, "front") == 0)
            printf("%d\n", front(dq));
        else if (strcmp(op, "back") == 0)
            printf("%d\n", back(dq));
    }
    return 0;
}