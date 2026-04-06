/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
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

bool isCyclicUtil(struct Graph *graph, int v, bool visited[], int parent)
{
    visited[v] = true;

    struct Node *temp = graph->adjLists[v];
    while (temp)
    {
        int neighbor = temp->vertex;

        if (!visited[neighbor])
        {
            if (isCyclicUtil(graph, neighbor, visited, v))
                return true;
        }
        // If neighbor is visited and not the parent, a cycle is found
        else if (neighbor != parent)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool isCyclic(struct Graph *graph)
{
    bool *visited = calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(graph, i, visited, -1))
            {
                free(visited);
                return true;
            }
        }
    }
    free(visited);
    return false;
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node *));
    for (int i = 0; i < n; i++)
        graph->adjLists[i] = NULL;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isCyclic(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}