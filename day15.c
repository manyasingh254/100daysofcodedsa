/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements
*/
#include <stdio.h>
int main()
{
    int m, n, i, j, sum = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int mat[m][n];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int limit = (m < n) ? m : n;
    for (i = 0; i < limit; i++)
    {
        sum += mat[i][i];
    }
    printf("Sum of the primary diagonal elements is %d\n", sum);
    return 0;
}