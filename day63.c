/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
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

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

void DFS(struct Graph *graph, bool *visited, int vertex)
{
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node *temp = graph->adjLists[vertex];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
        {
            DFS(graph, visited, neighbor);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, m, startNode;
    printf("Vertices and Edges: ");
    scanf("%d %d", &n, &m);

    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node *));
    bool *visited = malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        graph->adjLists[i] = NULL;
        visited[i] = false;
    }

    printf("Edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Starting vertex: ");
    scanf("%d", &startNode);

    printf("DFS Traversal: ");
    DFS(graph, visited, startNode);
    printf("\n");

    return 0;
}