#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(void)
{
    int n = 4;
    // printf("Input number of terms for the Series (< 20) : ");
    // scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int result = fibonacci(i);
        printf("%d ", result);
    }
}