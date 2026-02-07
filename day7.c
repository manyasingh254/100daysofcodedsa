/*
Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number
*/
#include <stdio.h>
long fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The Fibonacci number at index %d is %ld\n", n, fib(n));
}
