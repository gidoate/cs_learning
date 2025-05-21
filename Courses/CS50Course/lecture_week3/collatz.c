#include <stdio.h>

int collatz(int n)
{
    int count=0;
    if (n <= 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        if (n%2 == 0)
        {
            return 1 + collatz(n/2);
        }
        else
        {
            return 1 + collatz(3*n+1);
        }
        count = 1 + collatz(n);
    }
    return count;
}

int main()
{
    int n = 7;
    int steps = collatz(n);
    printf("Number of steps: %d\n", steps);
    return 0;
}
