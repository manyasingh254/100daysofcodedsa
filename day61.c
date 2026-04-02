/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, isUndirected;
    printf("Vertices and Edges: ");
    scanf("%d %d", &n, &m);
    printf("Undirected? (1 for Yes, 0 for No): ");
    scanf("%d", &isUndirected);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
        {
            matrix[u][v] = 1;
            if (isUndirected)
            {
                matrix[v][u] = 1;
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    printMatrix(matrix, n);

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}