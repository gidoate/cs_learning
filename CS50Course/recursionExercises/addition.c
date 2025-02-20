#include <stdio.h>

int addition(int n)
{
    if (n == 1)
    {
        printf("Returning 1\n");
        return 1;
    }
    else
    {
        int result = n + addition(n - 1);
        printf("Returning %d + addition(%d - 1) = %d\n", n, n, result);
        return result;
    }
}

int main(void)
{
    int n = 0;
    printf("Input the last number of the range starting from 1: ");
    scanf("%d", &n);
    int result = addition(n);
    printf("Addition result is: %d", result);
    return 0;
}