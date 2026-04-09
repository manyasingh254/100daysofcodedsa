/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int V;
    struct Node **adj;
};

void addEdge(struct Graph *g, int u, int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void kahnTopologicalSort(struct Graph *g)
{
    int *inDegree = (int *)calloc(g->V, sizeof(int));

    for (int i = 0; i < g->V; i++)
    {
        struct Node *temp = g->adj[i];
        while (temp)
        {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    int *queue = (int *)malloc(g->V * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < g->V; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[tail++] = i;
        }
    }

    int count = 0;
    int *topOrder = (int *)malloc(g->V * sizeof(int));

    while (head < tail)
    {
        int u = queue[head++];
        topOrder[count++] = u;

        struct Node *temp = g->adj[u];
        while (temp)
        {
            int v = temp->vertex;
            // Reduce in-degree of neighbors
            if (--inDegree[v] == 0)
            {
                queue[tail++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != g->V)
    {
        printf("The graph contains a cycle! Topological sort not possible.\n");
    }
    else
    {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", topOrder[i]);
        }
        printf("\n");
    }

    free(inDegree);
    free(queue);
    free(topOrder);
}