/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    struct Node *next;
};

void dfs(int v, bool visited[], struct Node **adj)
{
    visited[v] = true;
    struct Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex, visited, adj);
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

        struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
        n1->vertex = v;
        n1->next = adj[u];
        adj[u] = n1;

        struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
        n2->vertex = u;
        n2->next = adj[v];
        adj[v] = n2;
    }

    bool *visited = (bool *)calloc(n + 1, sizeof(bool));
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, visited, adj);
        }
    }

    printf("%d\n", count);

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