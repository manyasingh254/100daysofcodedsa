/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    struct Node *next;
};

void dfs(int v, bool visited[], struct Node **adj, int *count)
{
    visited[v] = true;
    (*count)++;
    struct Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex, visited, adj, count);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    struct Node **adj = (struct Node **)calloc(n + 1, sizeof(struct Node *));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node *n1 = malloc(sizeof(struct Node));
        n1->vertex = v;
        n1->next = adj[u];
        adj[u] = n1;
        struct Node *n2 = malloc(sizeof(struct Node));
        n2->vertex = u;
        n2->next = adj[v];
        adj[v] = n2;
    }

    if (n == 0)
    {
        printf("CONNECTED\n");
        return 0;
    }

    bool *visited = (bool *)calloc(n + 1, sizeof(bool));
    int visitedCount = 0;

    dfs(1, visited, adj, &visitedCount);

    if (visitedCount == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    for (int i = 1; i <= n; i++)
    {
        struct Node *temp = adj[i];
        while (temp)
        {
            struct Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(adj);
    free(visited);

    return 0;
}