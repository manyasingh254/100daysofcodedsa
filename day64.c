/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
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

void BFS(struct Graph *graph, int startVertex)
{
    bool *visited = calloc(graph->numVertices, sizeof(bool));
    int *queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

int main()
{
    int n, m, start;
    printf("Vertices and Edges: ");
    scanf("%d %d", &n, &m);

    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node *));
    for (int i = 0; i < n; i++)
        graph->adjLists[i] = NULL;

    printf("Edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Start vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(graph, start);
    printf("\n");

    return 0;
}