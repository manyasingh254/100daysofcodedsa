/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.
*/
#include <stdio.h>
#include <stdlib.h>

// Simple hash map entry
struct Entry
{
    int sum;
    int index;
};

// Function to find the longest subarray with 0 sum
int maxLen(int arr[], int n)
{
    // In the worst case, we might have n distinct prefix sums
    struct Entry *map = (struct Entry *)malloc(n * sizeof(struct Entry));
    int mapSize = 0;

    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        if (curr_sum == 0)
        {
            max_len = i + 1;
        }
        else
        {
            // Check if this sum has been seen before
            int foundIdx = -1;
            for (int j = 0; j < mapSize; j++)
            {
                if (map[j].sum == curr_sum)
                {
                    foundIdx = map[j].index;
                    break;
                }
            }

            if (foundIdx != -1)
            {
                // If sum is seen before, update max_len if current subarray is longer
                if (i - foundIdx > max_len)
                {
                    max_len = i - foundIdx;
                }
            }
            else
            {
                // If sum is not seen, add it to the map with current index
                map[mapSize].sum = curr_sum;
                map[mapSize].index = i;
                mapSize++;
            }
        }
    }

    free(map);
    return max_len;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}