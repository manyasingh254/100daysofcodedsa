/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjLists;
};

struct Node *createNode(int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph *graph, int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

void topologicalSortUtil(int v, bool visited[], int stack[], int *stackIndex, struct Graph *graph)
{
    visited[v] = true;

    struct Node *temp = graph->adjLists[v];
    while (temp)
    {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
        {
            topologicalSortUtil(connectedVertex, visited, stack, stackIndex, graph);
        }
        temp = temp->next;
    }

    // Push current vertex to stack which stores the result
    stack[(*stackIndex)++] = v;
}

void topologicalSort(struct Graph *graph)
{
    int stack[graph->numVertices];
    int stackIndex = 0;
    bool *visited = calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, stack, &stackIndex, graph);
        }
    }

    // Print contents of stack in reverse order
    printf("Topological Ordering: ");
    for (int i = stackIndex - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
}

int main()
{
    int V = 6;
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = V;
    graph->adjLists = malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}