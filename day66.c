/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
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

bool isCyclicUtil(struct Graph *graph, int v, bool visited[], bool recStack[])
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        struct Node *temp = graph->adjLists[v];
        while (temp)
        {
            int neighbor = temp->vertex;
            if (!visited[neighbor] && isCyclicUtil(graph, neighbor, visited, recStack))
            {
                return true;
            }
            else if (recStack[neighbor])
            {
                return true;
            }
            temp = temp->next;
        }
    }
    recStack[v] = false; // Backtrack: remove node from recursion stack
    return false;
}

bool isCyclic(struct Graph *graph)
{
    bool *visited = calloc(graph->numVertices, sizeof(bool));
    bool *recStack = calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(graph, i, visited, recStack))
            {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }
    free(visited);
    free(recStack);
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