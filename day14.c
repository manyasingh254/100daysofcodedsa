/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"
*/
#include <stdio.h>
int main()
{
    int n, i, j, flag = 1;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j && mat[i][j] != 1)
            {
                flag = 0;
                break;
            }
            else if (i != j && mat[i][j] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    if (flag == 1)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");
    return 0;
}