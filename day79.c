/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Edge
{
    int to, weight;
    struct Edge *next;
};

struct HeapNode
{
    int v, dist;
};

struct MinHeap
{
    int size;
    int capacity;
    struct HeapNode **array;
};

struct HeapNode *newHeapNode(int v, int dist)
{
    struct HeapNode *node = malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapNodes(struct HeapNode **a, struct HeapNode **b)
{
    struct HeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx)
    {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

struct HeapNode *extractMin(struct MinHeap *heap)
{
    if (heap->size == 0)
        return NULL;
    struct HeapNode *root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

void insertHeap(struct MinHeap *heap, int v, int dist)
{
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = newHeapNode(v, dist);
    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist)
    {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    struct Edge **adj = calloc(n + 1, sizeof(struct Edge *));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Edge *e1 = malloc(sizeof(struct Edge));
        e1->to = v;
        e1->weight = w;
        e1->next = adj[u];
        adj[u] = e1;
        struct Edge *e2 = malloc(sizeof(struct Edge));
        e2->to = u;
        e2->weight = w;
        e2->next = adj[v];
        adj[v] = e2;
    }

    int src;
    scanf("%d", &src);

    int *dist = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    struct MinHeap *heap = malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = m + n;
    heap->array = malloc(heap->capacity * sizeof(struct HeapNode *));

    insertHeap(heap, src, 0);

    while (heap->size != 0)
    {
        struct HeapNode *node = extractMin(heap);
        int u = node->v;
        int d = node->dist;
        free(node);

        if (d > dist[u])
            continue;

        struct Edge *curr = adj[u];
        while (curr)
        {
            if (dist[u] != INT_MAX && dist[u] + curr->weight < dist[curr->to])
            {
                dist[curr->to] = dist[u] + curr->weight;
                insertHeap(heap, curr->to, dist[curr->to]);
            }
            curr = curr->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}