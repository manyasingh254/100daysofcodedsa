/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Edge
{
    int to;
    int weight;
    struct Edge *next;
};

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    struct Edge **adj = (struct Edge **)calloc(n + 1, sizeof(struct Edge *));
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

    int *min_weight = (int *)malloc((n + 1) * sizeof(int));
    bool *in_mst = (bool *)calloc(n + 1, sizeof(bool));
    for (int i = 1; i <= n; i++)
        min_weight[i] = INT_MAX;

    int total_weight = 0;
    min_weight[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int min_val = INT_MAX;

        for (int v = 1; v <= n; v++)
        {
            if (!in_mst[v] && min_weight[v] < min_val)
            {
                min_val = min_weight[v];
                u = v;
            }
        }

        if (u == -1)
            break;

        in_mst[u] = true;
        total_weight += min_val;

        struct Edge *curr = adj[u];
        while (curr)
        {
            if (!in_mst[curr->to] && curr->weight < min_weight[curr->to])
            {
                min_weight[curr->to] = curr->weight;
            }
            curr = curr->next;
        }
    }

    printf("%d\n", total_weight);

    for (int i = 1; i <= n; i++)
    {
        struct Edge *curr = adj[i];
        while (curr)
        {
            struct Edge *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(adj);
    free(min_weight);
    free(in_mst);

    return 0;
}