/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float data;
    struct Node *next;
};

void insertionSort(struct Node **headRef)
{
    if (*headRef == NULL || (*headRef)->next == NULL)
        return;
    struct Node *sorted = NULL;
    struct Node *curr = *headRef;
    while (curr != NULL)
    {
        struct Node *next = curr->next;
        if (sorted == NULL || sorted->data >= curr->data)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    *headRef = sorted;
}

void bucketSort(float arr[], int n)
{
    struct Node **buckets = (struct Node **)malloc(n * sizeof(struct Node *));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bi];
        buckets[bi] = newNode;
    }

    for (int i = 0; i < n; i++)
    {
        insertionSort(&buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        struct Node *curr = buckets[i];
        while (curr)
        {
            arr[index++] = curr->data;
            struct Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}