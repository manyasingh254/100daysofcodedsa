/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void findWinner(int n, char **votes)
{
    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int maxVotes = 0;

    char *currentCandidate = votes[0];
    int currentVotes = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(votes[i], currentCandidate) == 0)
        {
            currentVotes++;
        }
        else
        {
            if (currentVotes > maxVotes)
            {
                maxVotes = currentVotes;
                winner = currentCandidate;
            }
            currentCandidate = votes[i];
            currentVotes = 1;
        }
    }

    if (currentVotes > maxVotes)
    {
        maxVotes = currentVotes;
        winner = currentCandidate;
    }

    printf("%s %d\n", winner, maxVotes);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        votes[i] = (char *)malloc(101 * sizeof(char)); // Max name length 100
        scanf("%s", votes[i]);
    }

    findWinner(n, votes);

    for (int i = 0; i < n; i++)
        free(votes[i]);
    free(votes);

    return 0;
}