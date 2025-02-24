#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(void)
{
    int n = 0;
    printf("Enter the index of Fibonacci's sequence of which you'd like to know the value: ");
    scanf("%i", &n);
    int x = fibonacci(n);
    printf("The value of Fibonacci's sequence at position %i is number %i", n, x);
}