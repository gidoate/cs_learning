#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int main(void)
{
    int n;
    printf("introduce a number to calculate the factorial: ");
    scanf("%i", &n);
    int x = factorial(n);
    printf("the factorial of %i is %i\n", n, x);
    
}