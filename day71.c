/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY -1
#define DELETED -2

void insert(int table[], int m, int key)
{
    int h_k = key % m;
    for (int i = 0; i < m; i++)
    {
        int idx = (h_k + i * i) % m;
        if (table[idx] == EMPTY || table[idx] == DELETED)
        {
            table[idx] = key;
            return;
        }
    }
}

bool search(int table[], int m, int key)
{
    int h_k = key % m;
    for (int i = 0; i < m; i++)
    {
        int idx = (h_k + i * i) % m;
        if (table[idx] == EMPTY)
        {
            return false;
        }
        if (table[idx] == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int m, q;
    if (scanf("%d %d", &m, &q) != 2)
        return 0;

    int *table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;
    while (q--)
    {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0)
        {
            insert(table, m, key);
        }
        else if (strcmp(op, "SEARCH") == 0)
        {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}