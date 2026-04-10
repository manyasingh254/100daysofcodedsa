/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
struct Node
{
    int target, weight;
    struct Node *next;
};
struct Edge
{
    int vertex, dist;
};
struct MinHeap
{
    struct Edge *array;
    int size;
    int capacity;
};
struct MinHeap *createHeap(int capacity)
{
    struct MinHeap *heap = malloc(sizeof(struct MinHeap));
    heap->array = malloc(capacity * sizeof(struct Edge));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}
void swap(struct Edge *a, struct Edge *b)
{
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}
void push(struct MinHeap *heap, int vertex, int dist)
{
    heap->array[heap->size] = (struct Edge){vertex, dist};
    int i = heap->size++;
    while (i != 0 && heap->array[(i - 1) / 2].dist > heap->array[i].dist)
    {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
struct Edge pop(struct MinHeap *heap)
{
    struct Edge root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    int i = 0;
    while (2 * i + 1 < heap->size)
    {
        int smallest = 2 * i + 1;
        if (smallest + 1 < heap->size && heap->array[smallest + 1].dist < heap->array[smallest].dist)
            smallest++;
        if (heap->array[i].dist <= heap->array[smallest].dist)
            break;
        swap(&heap->array[i], &heap->array[smallest]);
        i = smallest;
    }
    return root;
}
void dijkstra(int V, struct Node **adj, int src)
{
    int *dist = malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    struct MinHeap *pq = createHeap(V * V); // Capacity for worst-case edges
    dist[src] = 0;
    push(pq, src, 0);
    while (pq->size > 0)
    {
        struct Edge current = pop(pq);
        int u = current.vertex;
        int d = current.dist;
        if (d > dist[u])
            continue;
        struct Node *temp = adj[u];
        while (temp)
        {
            int v = temp->target;
            int weight = temp->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                push(pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    free(dist);
    free(pq->array);
    free(pq);
}