/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pos;
    double time;
} Car;

int compare(const void *a, const void *b)
{
    return ((Car *)b)->pos - ((Car *)a)->pos;
}

int carFleet(int target, int *position, int positionSize, int *speed, int speedSize)
{
    if (positionSize == 0)
        return 0;

    Car *cars = (Car *)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++)
    {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++)
    {
        if (cars[i].time > maxTime)
        {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}