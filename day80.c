/*
Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

Input:
- First line: integer n representing the number of vertices
- Next n lines: n space-separated integers representing the adjacency matrix of the graph
  (use -1 to indicate no direct edge between two vertices)

Output:
- Print the shortest distance matrix where the value at row i and column j represents the shortest distance from vertex i to vertex j
*/
#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    long long dist[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = val;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] >= INF)
            {
                printf("-1 ");
            }
            else
            {
                printf("%lld ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}