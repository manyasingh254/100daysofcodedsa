/*
Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n
*/
#include <stdio.h>

int main()
{
    long long n;
    if (scanf("%lld", &n) != 1)
        return 0;

    if (n < 2)
    {
        printf("%lld\n", n);
        return 0;
    }

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid == 0)
        {
            low = mid + 1;
            continue;
        }

        if (mid <= n / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}